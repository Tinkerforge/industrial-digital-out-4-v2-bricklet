/* industrial-digital-out-4-v2-bricklet
 * Copyright (C) 2018 Ishraq Ibne Ashraf <ishraq@tinkerforge.com>
 *
 * io4.c: Implementation of IO4 V2 Bricklet
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

#include "communication.h"

IDO4_t ido4;

void ido4_init(void) {
	logd("[+] IDO4-V2: ido4_init()\n\r");

	// Channel out config
	XMC_GPIO_CONFIG_t ch_pin_out_config = {
		.mode         = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
		.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH,
	};

	// Initialise all the channels
	for(uint8_t i = 0; i < NUMBER_OF_CHANNELS; i++) {
		uint8_t _i;

		// Generic channel config
		if (i == 0) {
			_i = 3;
		}
		else if (i == 1) {
			_i = 2;
		}
		else if (i == 2) {
			_i = 1;
		}
		else if (i == 3) {
			_i = 0;
		}

		ido4.channels[i].pin = _i;
		ido4.channels[i].port = (XMC_GPIO_PORT_t *)PORT1_BASE;
		ido4.channels[i].value = false;

		XMC_GPIO_Init(ido4.channels[i].port, ido4.channels[i].pin, &ch_pin_out_config);
		XMC_GPIO_SetOutputHigh(ido4.channels[i].port, ido4.channels[i].pin);

		// Channel monoflop config
		ido4.channels[i].monoflop.time = 0;
		ido4.channels[i].monoflop.time_start = 0;
		ido4.channels[i].monoflop.time_remaining = 0;

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
		if(ido4.channels[i].monoflop.time > 0) {
			if(system_timer_is_time_elapsed_ms(ido4.channels[i].monoflop.time_start,
			                                   ido4.channels[i].monoflop.time)) {
				// Monoflop time expired

				ido4.channels[i].monoflop.time = 0;
				ido4.channels[i].monoflop.time_start = 0;
				ido4.channels[i].monoflop.time_remaining = 0;

				if(ido4.channels[i].value) {
					ido4.channels[i].value = false;
				}
				else {
					ido4.channels[i].value = true;
				}

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

				if(ido4.channels[i].value) {
					XMC_GPIO_SetOutputLow(ido4.channels[i].status_led.port,
					                      ido4.channels[i].status_led.pin);
				}
				else {
					XMC_GPIO_SetOutputHigh(ido4.channels[i].status_led.port,
					                       ido4.channels[i].status_led.pin);
				}

				break;

			default:
				break;
		}
	}
}
