/* industrial-digital-out-4-v2-bricklet
 * Copyright (C) 2018 Ishraq Ibne Ashraf <ishraq@tinkerforge.com>
 *
 * communication.c: TFP protocol message handling
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

#include "communication.h"

#include "bricklib2/utility/communication_callback.h"
#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/logging/logging.h"

#include "ido4.h"

BootloaderHandleMessageResponse handle_message(const void *message, void *response) {
	switch(tfp_get_fid_from_message(message)) {
		case FID_SET_VALUE: return set_value(message);
		case FID_GET_VALUE: return get_value(message, response);
		case FID_SET_SELECTED_VALUE: return set_selected_value(message);
		case FID_SET_MONOFLOP: return set_monoflop(message);
		case FID_GET_MONOFLOP: return get_monoflop(message, response);
		case FID_SET_CHANNEL_LED_CONFIG: return set_channel_led_config(message);
		case FID_GET_CHANNEL_LED_CONFIG: return get_channel_led_config(message, response);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
}

BootloaderHandleMessageResponse set_value(const SetValue *data) {
	logd("[+] IDO4-V2: set_value()\n\r");

	for(uint8_t i = 0; i < NUMBER_OF_CHANNELS; i++) {
		if(data->value & (1 << i)) {
			ido4.channels[i].value = true;
			XMC_GPIO_SetOutputLow(ido4.channels[i].port, ido4.channels[i].pin);
		}
		else {
			ido4.channels[i].value = false;
			XMC_GPIO_SetOutputHigh(ido4.channels[i].port, ido4.channels[i].pin);
		}
	}

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_value(const GetValue *data, GetValue_Response *response) {
	logd("[+] IDO4-V2: get_value()\n\r");

	uint8_t bit_encoded_values = 0;
	response->header.length = sizeof(GetValue_Response);

	for(uint8_t i = 0; i < NUMBER_OF_CHANNELS; i++) {
		if(ido4.channels[i].value) {
			bit_encoded_values |= (1 << i);
		}
		else {
			bit_encoded_values &= ~(1 << i);
		}
	}

	response->value = bit_encoded_values;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_selected_value(const SetSelectedValue *data) {
	logd("[+] IDO4-V2: set_selected_value()\n\r");

	if(data->channel > NUMBER_OF_CHANNELS - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	ido4.channels[data->channel].value = data->value;

	if(ido4.channels[data->channel].value) {
		XMC_GPIO_SetOutputLow(ido4.channels[data->channel].port,
		                      ido4.channels[data->channel].pin);
	}
	else {
		XMC_GPIO_SetOutputHigh(ido4.channels[data->channel].port,
		                       ido4.channels[data->channel].pin);
	}

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse set_monoflop(const SetMonoflop *data) {
	logd("[+] IDO4-V2: set_monoflop()\n\r");

	if(data->channel > NUMBER_OF_CHANNELS - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	ido4.channels[data->channel].value = data->value;
	ido4.channels[data->channel].monoflop.time = data->time;
	ido4.channels[data->channel].monoflop.time_remaining = data->time;

	if(ido4.channels[data->channel].value) {
		XMC_GPIO_SetOutputLow(ido4.channels[data->channel].port,
		                      ido4.channels[data->channel].pin);
	}
	else {
		XMC_GPIO_SetOutputHigh(ido4.channels[data->channel].port,
		                       ido4.channels[data->channel].pin);
	}

	ido4.channels[data->channel].monoflop.time_start = system_timer_get_ms();

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_monoflop(const GetMonoflop *data, GetMonoflop_Response *response) {
	logd("[+] IDO4-V2: get_monoflop()\n\r");

	response->header.length = sizeof(GetMonoflop_Response);

	if(data->channel > NUMBER_OF_CHANNELS - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->time = ido4.channels[data->channel].monoflop.time;
	response->value = ido4.channels[data->channel].value;
	response->time_remaining = ido4.channels[data->channel].monoflop.time_remaining;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_channel_led_config(const SetChannelLEDConfig *data) {
	if(data->led > NUMBER_OF_CHANNELS - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	ido4.channels[data->led].status_led.config = data->config;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_channel_led_config(const GetChannelLEDConfig *data, GetChannelLEDConfig_Response *response) {
	response->header.length = sizeof(GetChannelLEDConfig_Response);

	if(data->led > NUMBER_OF_CHANNELS - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->config = ido4.channels[data->led].status_led.config;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

bool handle_monoflop_done_callback(void) {
	static bool is_buffered = false;
	static MonoflopDone_Callback cb;

	if(!is_buffered) {
		if(ringbuffer_is_empty(&ido4.monoflop_cb_rb)) {
			// Nothing to send
			return false;
		}

		tfp_make_default_header(&cb.header,
		                        bootloader_get_uid(),
		                        sizeof(MonoflopDone_Callback),
		                        FID_CALLBACK_MONOFLOP_DONE);

		ringbuffer_get(&ido4.monoflop_cb_rb, &cb.channel);
		ringbuffer_get(&ido4.monoflop_cb_rb, (uint8_t *)&cb.value);
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status,
		                                       (uint8_t*)&cb,
		                                       sizeof(MonoflopDone_Callback));

		is_buffered = false;

		return true;
	}
	else {
		is_buffered = true;
	}

	return false;
}

void communication_tick(void) {
	communication_callback_tick();
}

void communication_init(void) {
	communication_callback_init();
}
