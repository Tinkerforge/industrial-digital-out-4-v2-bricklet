/* industrial-digital-out-4-v2-bricklet
 * Copyright (C) 2018 Ishraq Ibne Ashraf <ishraq@tinkerforge.com>
 * Copyright (C) 2018 Olaf Lüke <olaf@tinkerforge.com>
 *
 * ido4.h: Implementation of Industrial Digital Out 4 V2 Bricklet
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "ido4.h"

#include <stdint.h>
#include <stdbool.h>

#include "bricklib2/logging/logging.h"
#include "bricklib2/hal/system_timer/system_timer.h"
#include "bricklib2/utility/util_definitions.h"

#include "communication.h"

#include "xmc_ccu4.h"

IDO4_t ido4;

XMC_CCU4_SLICE_t *const ido4_slice[NUMBER_OF_CHANNELS] = {
	CCU40_CC43,
	CCU40_CC42,
	CCU40_CC41,
	CCU40_CC40,
};

void ido4_pwm_stop(const uint8_t channel) {
	if(ido4.channels[channel].pwm.frequency != 0) {
		ido4.channels[channel].pwm.duty_cycle = 0;
		ido4.channels[channel].pwm.frequency  = 0;
		XMC_CCU4_SLICE_StopTimer(ido4_slice[channel]);

		const XMC_GPIO_CONFIG_t pwm_stop_config	= {
			.mode                = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
			.input_hysteresis    = XMC_GPIO_INPUT_HYSTERESIS_STANDARD,
			.output_level        = XMC_GPIO_OUTPUT_LEVEL_LOW,
		};

		XMC_GPIO_Init(ido4.channels[channel].port, ido4.channels[channel].pin, &pwm_stop_config);
	}
}

void ido4_pwm_init(const uint8_t channel) {
	const XMC_CCU4_SLICE_COMPARE_CONFIG_t compare_config = {
		.timer_mode          = XMC_CCU4_SLICE_TIMER_COUNT_MODE_EA,
		.monoshot            = false,
		.shadow_xfer_clear   = 0,
		.dither_timer_period = 0,
		.dither_duty_cycle   = 0,
		.prescaler_mode      = XMC_CCU4_SLICE_PRESCALER_MODE_NORMAL,
		.mcm_enable          = 0,
		.prescaler_initval   = 0,
		.float_limit         = 0,
		.dither_limit        = 0,
		.passive_level       = XMC_CCU4_SLICE_OUTPUT_PASSIVE_LEVEL_LOW,
		.timer_concatenation = 0
	};

	const XMC_GPIO_CONFIG_t pwm_config	= {
		.mode                = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT2,
		.input_hysteresis    = XMC_GPIO_INPUT_HYSTERESIS_STANDARD,
		.output_level        = XMC_GPIO_OUTPUT_LEVEL_LOW,
	};

	XMC_CCU4_Init(CCU40, XMC_CCU4_SLICE_MCMS_ACTION_TRANSFER_PR_CR);
	XMC_CCU4_StartPrescaler(CCU40);
	XMC_CCU4_SLICE_CompareInit(ido4_slice[channel], &compare_config);

	// Set the period and compare register values
	XMC_CCU4_SLICE_SetTimerPeriodMatch(ido4_slice[channel], 32000);
	XMC_CCU4_SLICE_SetTimerCompareMatch(ido4_slice[channel], 0);

	XMC_CCU4_EnableShadowTransfer(CCU40, (XMC_CCU4_SHADOW_TRANSFER_SLICE_0 << (ido4.channels[channel].pin*4)) |
	                                     (XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_0 << (ido4.channels[channel].pin*4)));

	XMC_GPIO_Init(ido4.channels[channel].port, ido4.channels[channel].pin, &pwm_config);

	XMC_CCU4_EnableClock(CCU40, ido4.channels[channel].pin);
}

void ido4_pwm_update(const uint8_t channel, const uint32_t frequency, const uint16_t duty_cycle) {
	if(frequency == 0) {
		ido4_pwm_stop(channel);
		return;
	}

	const bool new_start = ido4.channels[channel].pwm.frequency == 0;

	if(new_start) {
		ido4_pwm_init(channel);
	}

	ido4.channels[channel].pwm.duty_cycle = MIN(10000, duty_cycle);
	ido4.channels[channel].pwm.frequency  = MIN(320000000, frequency);

	uint32_t prescaler = 0;
	uint32_t divisor = 1;
	uint32_t period_value = (640000000/ido4.channels[channel].pwm.frequency) - 1;
	while(period_value > 0xFFFF) {
		prescaler++;
		divisor *= 2;
		period_value = (640000000/(ido4.channels[channel].pwm.frequency*divisor)) - 1;
	}

	uint32_t compare_value = (period_value*duty_cycle + 10000/2)/10000;

	XMC_CCU4_SLICE_SetPrescaler(ido4_slice[channel], prescaler);
	XMC_CCU4_SLICE_SetTimerPeriodMatch(ido4_slice[channel], period_value);
	XMC_CCU4_SLICE_SetTimerCompareMatch(ido4_slice[channel], compare_value);
	XMC_CCU4_EnableShadowTransfer(CCU40, (XMC_CCU4_SHADOW_TRANSFER_SLICE_0 << (ido4.channels[channel].pin*4)) |
    		                             (XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_0 << (ido4.channels[channel].pin*4)));

	if(new_start) {
    	XMC_CCU4_SLICE_StartTimer(ido4_slice[channel]);
	}
}

void ido4_init(void) {
	logd("[+] IDO4-V2: ido4_init()\n\r");

	// Channel out config
	XMC_GPIO_CONFIG_t ch_pin_out_config = {
		.mode         = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
		.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH,
	};

	// Initialise all the channels
	for(uint8_t i = 0; i < NUMBER_OF_CHANNELS; i++) {
		// Generic channel config
		ido4.channels[i].pin = 3-i;
		ido4.channels[i].port = (XMC_GPIO_PORT_t *)PORT1_BASE;
		ido4.channels[i].value = false;

		XMC_GPIO_Init(ido4.channels[i].port, ido4.channels[i].pin, &ch_pin_out_config);
		XMC_GPIO_SetOutputHigh(ido4.channels[i].port, ido4.channels[i].pin);

		// Channel monoflop config
		ido4.channels[i].monoflop.time = 0;
		ido4.channels[i].monoflop.time_start = 0;
		ido4.channels[i].monoflop.time_remaining = 0;
		ido4.channels[i].monoflop.running = false;

		// Channel LED config
		ido4.channels[i].status_led.port = (XMC_GPIO_PORT_t *)PORT0_BASE;

		if(i == 0) {
			ido4.channels[i].status_led.pin = 12;
		}
		else if(i == 1) {
			ido4.channels[i].status_led.pin = 9;
		}
		else if(i == 2) {
			ido4.channels[i].status_led.pin = 8;
		}
		else if(i == 3) {
			ido4.channels[i].status_led.pin = 7;
		}

		XMC_GPIO_Init(ido4.channels[i].status_led.port, ido4.channels[i].status_led.pin, &ch_pin_out_config);
	
		ido4.channels[i].status_led.config = \
			(uint8_t)INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS;
		ido4.channels[i].status_led.channel_led_flicker_state.config = \
			(uint8_t)LED_FLICKER_CONFIG_OFF;
	}

	// Monopflop callback ringbuffer init
	ringbuffer_init(&ido4.monoflop_cb_rb,
	                MONOFLOP_CB_BUFFER_SIZE,
	                &ido4.monoflop_cb_buffer[0]);
}

void ido4_tick(void) {
	// Iterate all channels
	for(uint8_t i = 0; i < NUMBER_OF_CHANNELS; i++) {
		// Manage monoflop
		if(ido4.channels[i].monoflop.running) {
			if(system_timer_is_time_elapsed_ms(ido4.channels[i].monoflop.time_start,
			                                   ido4.channels[i].monoflop.time)) {
				// Monoflop time expired
				ido4.channels[i].monoflop.time_start = 0;
				ido4.channels[i].monoflop.time_remaining = 0;
				ido4.channels[i].monoflop.running = false;

				ido4.channels[i].value = !ido4.channels[i].value;

				if(ido4.channels[i].value) {
					XMC_GPIO_SetOutputLow(ido4.channels[i].port, ido4.channels[i].pin);
				}
				else {
					XMC_GPIO_SetOutputHigh(ido4.channels[i].port, ido4.channels[i].pin);
				}

				// Enqueue monoflop callback for the channel
				if(ringbuffer_get_used(&ido4.monoflop_cb_rb) < MONOFLOP_CB_BUFFER_SIZE) {
					// Channel
					ringbuffer_add(&ido4.monoflop_cb_rb, i);
					// Value
					ringbuffer_add(&ido4.monoflop_cb_rb, (uint8_t)ido4.channels[i].value);
				}
			}
			else {
				ido4.channels[i].monoflop.time_remaining = \
					ido4.channels[i].monoflop.time - (system_timer_get_ms() - ido4.channels[i].monoflop.time_start);
			}
		}

		// Manage channel LEDs
		switch (ido4.channels[i].status_led.config) {
			case INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_OFF:
				ido4.channels[i].status_led.channel_led_flicker_state.config = LED_FLICKER_CONFIG_OFF;
				XMC_GPIO_SetOutputHigh(ido4.channels[i].status_led.port, ido4.channels[i].status_led.pin);

				break;

			case INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_ON:
				ido4.channels[i].status_led.channel_led_flicker_state.config = LED_FLICKER_CONFIG_ON;
				XMC_GPIO_SetOutputLow(ido4.channels[i].status_led.port, ido4.channels[i].status_led.pin);

				break;

			case INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_SHOW_HEARTBEAT:
				ido4.channels[i].status_led.channel_led_flicker_state.config = LED_FLICKER_CONFIG_HEARTBEAT;

				led_flicker_tick(&ido4.channels[i].status_led.channel_led_flicker_state,
				                 system_timer_get_ms(),
				                 ido4.channels[i].status_led.port,
				                 ido4.channels[i].status_led.pin);

				break;

			case INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS:
				ido4.channels[i].status_led.channel_led_flicker_state.config = LED_FLICKER_CONFIG_OFF;

				if(XMC_GPIO_GetInput(ido4.channels[i].port, ido4.channels[i].pin)) {
					XMC_GPIO_SetOutputHigh(ido4.channels[i].status_led.port,
					                       ido4.channels[i].status_led.pin);
				}
				else {
					XMC_GPIO_SetOutputLow(ido4.channels[i].status_led.port,
					                      ido4.channels[i].status_led.pin);
				}

				break;

			default:
				break;
		}
	}
}
