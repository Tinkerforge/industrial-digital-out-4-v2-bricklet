/* industrial-digital-out-4-v2-bricklet
 * Copyright (C) 2020 Olaf Lüke <olaf@tinkerforge.com>
 *
 * wiegand.c: Simple bit banging wiegand sender
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

#include "wiegand.h"

#include <string.h>

#include "bricklib2/hal/system_timer/system_timer.h"

#include "xmc_ccu4.h"
#include "ido4.h"

extern XMC_CCU4_SLICE_t *const ido4_slice[];
extern const uint8_t ido4_channel_pin[];
extern XMC_GPIO_PORT_t *const ido4_channel_port[];

Wiegand wiegand;

void wiegand_50us_monoshot(const uint8_t channel) {
	// Reuse PWM code, but put CCU4 in monoshot mode
	// to make the single 50us pulse that we need for Wiegand
	ido4_pwm_init(channel, XMC_CCU4_SLICE_TIMER_REPEAT_MODE_SINGLE);

	XMC_CCU4_SLICE_SetPrescaler(ido4_slice[channel], XMC_CCU4_SLICE_PRESCALER_1);
	XMC_CCU4_SLICE_SetTimerPeriodMatch(ido4_slice[channel], 9600);
	XMC_CCU4_SLICE_SetTimerCompareMatch(ido4_slice[channel], 3200);
	XMC_CCU4_EnableShadowTransfer(CCU40, (XMC_CCU4_SHADOW_TRANSFER_SLICE_0 << (ido4_channel_pin[channel]*4)) |
	                                     (XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_0 << (ido4_channel_pin[channel]*4)));

    XMC_CCU4_SLICE_StartTimer(ido4_slice[channel]);
}

void wiegand_init(void) {
	memset(&wiegand, 0, sizeof(Wiegand));
}

void wiegand_tick(void) {
	if(wiegand.data_length > 0) {
		if(wiegand.last_time == 0) {
			// First we set to the default high state
			XMC_GPIO_SetOutputLow(ido4_channel_port[0], ido4_channel_pin[0]);
			XMC_GPIO_SetOutputLow(ido4_channel_port[1], ido4_channel_pin[1]);
			wiegand.last_time = system_timer_get_ms();
			return;
		}

		if(system_timer_is_time_elapsed_ms(wiegand.last_time, 2)) {
			// Check for end of Wiegand data
			if(wiegand.data_index == wiegand.data_length) {
				wiegand.data_index  = 0;
				wiegand.data_length = 0;
				wiegand.last_time   = 0;
				wiegand.done        = true;

				const XMC_GPIO_CONFIG_t pwm_stop_config	= {
					.mode                = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
					.input_hysteresis    = XMC_GPIO_INPUT_HYSTERESIS_STANDARD,
					.output_level        = XMC_GPIO_OUTPUT_LEVEL_LOW,
				};

				XMC_GPIO_Init(ido4_channel_port[0], ido4_channel_pin[0], &pwm_stop_config);
				XMC_GPIO_Init(ido4_channel_port[1], ido4_channel_pin[1], &pwm_stop_config);

				return;
			}

			// Write 50us pulse to channel 1 or 0
			const uint8_t channel = (wiegand.data[wiegand.data_index/8] & (1 << (wiegand.data_index % 8))) ? 1 : 0;
			wiegand_50us_monoshot(channel);

			wiegand.data_index++;
			wiegand.last_time = system_timer_get_ms();
		}
	}
}
