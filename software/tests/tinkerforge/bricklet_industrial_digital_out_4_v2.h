/* ***********************************************************
 * This file was automatically generated on 2020-10-22.      *
 *                                                           *
 * C/C++ Bindings Version 2.1.29                             *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/

#ifndef BRICKLET_INDUSTRIAL_DIGITAL_OUT_4_V2_H
#define BRICKLET_INDUSTRIAL_DIGITAL_OUT_4_V2_H

#include "ip_connection.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BrickletIndustrialDigitalOut4V2 Industrial Digital Out 4 Bricklet 2.0
 */

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * 4 galvanically isolated digital outputs
 */
typedef Device IndustrialDigitalOut4V2;

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_VALUE 1

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_VALUE 2

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_SELECTED_VALUE 3

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_MONOFLOP 4

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_MONOFLOP 5

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_CHANNEL_LED_CONFIG 7

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_CHANNEL_LED_CONFIG 8

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_PWM_CONFIGURATION 9

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_PWM_CONFIGURATION 10

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_WRITE_WIEGAND_DATA_LOW_LEVEL 11

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_WIEGAND_STATE 12

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_SPITFP_ERROR_COUNT 234

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_BOOTLOADER_MODE 235

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_BOOTLOADER_MODE 236

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER 237

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_WRITE_FIRMWARE 238

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_STATUS_LED_CONFIG 239

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_STATUS_LED_CONFIG 240

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_CHIP_TEMPERATURE 242

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_RESET 243

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_WRITE_UID 248

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_READ_UID 249

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_IDENTITY 255

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Signature: \code void callback(uint8_t channel, bool value, void *user_data) \endcode
 * 
 * This callback is triggered whenever a monoflop timer reaches 0. The
 * parameters contain the channel and the current value of the channel
 * (the value after the monoflop).
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_CALLBACK_MONOFLOP_DONE 6

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Signature: \code void callback(void *user_data) \endcode
 * 
 * TBD
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_CALLBACK_WIEGAND_DONE 13


/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS 3

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_WIEGAND_STATE_IDLE 0

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_WIEGAND_STATE_BUSY 1

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_MODE_BOOTLOADER 0

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_MODE_FIRMWARE 1

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_STATUS_OK 0

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_STATUS_INVALID_MODE 1

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_STATUS_NO_CHANGE 2

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_STATUS_LED_CONFIG_OFF 0

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_STATUS_LED_CONFIG_ON 1

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * This constant is used to identify a Industrial Digital Out 4 Bricklet 2.0.
 *
 * The {@link industrial_digital_out_4_v2_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_DEVICE_IDENTIFIER 2124

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * This constant represents the display name of a Industrial Digital Out 4 Bricklet 2.0.
 */
#define INDUSTRIAL_DIGITAL_OUT_4_V2_DEVICE_DISPLAY_NAME "Industrial Digital Out 4 Bricklet 2.0"

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Creates the device object \c industrial_digital_out_4_v2 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
void industrial_digital_out_4_v2_create(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, const char *uid, IPConnection *ipcon);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Removes the device object \c industrial_digital_out_4_v2 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
void industrial_digital_out_4_v2_destroy(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the industrial_digital_out_4_v2_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is sent and errors are
 * silently ignored, because they cannot be detected.
 */
int industrial_digital_out_4_v2_get_response_expected(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Changes the response expected flag of the function specified by the
 * \c function_id parameter. This flag can only be changed for setter
 * (default value: *false*) and callback configuration functions
 * (default value: *true*). For getter functions it is always enabled.
 *
 * Enabling the response expected flag for a setter function allows to detect
 * timeouts and other error conditions calls of this setter as well. The device
 * will then send a response for this purpose. If this flag is disabled for a
 * setter function then no response is sent and errors are silently ignored,
 * because they cannot be detected.
 */
int industrial_digital_out_4_v2_set_response_expected(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
int industrial_digital_out_4_v2_set_response_expected_all(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, bool response_expected);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Registers the given \c function with the given \c callback_id. The
 * \c user_data will be passed as the last parameter to the \c function.
 */
void industrial_digital_out_4_v2_register_callback(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, int16_t callback_id, void (*function)(void), void *user_data);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the API version (major, minor, release) of the bindings for this
 * device.
 */
int industrial_digital_out_4_v2_get_api_version(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t ret_api_version[3]);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Sets the output value of all four channels. A value of *true* or *false* outputs
 * logic 1 or logic 0 respectively on the corresponding channel.
 * 
 * Use {@link industrial_digital_out_4_v2_set_selected_value} to change only one output channel state.
 * 
 * All running monoflop timers and PWMs will be aborted if this function is called.
 * 
 * For example: (True, True, False, False) will turn the channels 0-1 high and the
 * channels 2-3 low.
 */
int industrial_digital_out_4_v2_set_value(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, bool value[4]);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the logic levels that are currently output on the channels.
 */
int industrial_digital_out_4_v2_get_value(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, bool ret_value[4]);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Sets the output value of a specific channel without affecting the other channels.
 * 
 * A running monoflop timer or PWM for the specified channel will be aborted if this
 * function is called.
 */
int industrial_digital_out_4_v2_set_selected_value(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, bool value);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * The first parameter is the desired state of the channel (*true* means output *high*
 * and *false* means output *low*). The second parameter indicates the time that
 * the channel should hold the state.
 * 
 * If this function is called with the parameters (true, 1500):
 * The channel will turn on and in 1.5s it will turn off again.
 * 
 * A PWM for the selected channel will be aborted if this function is called.
 * 
 * A monoflop can be used as a failsafe mechanism. For example: Lets assume you
 * have a RS485 bus and a IO-4 Bricklet is connected to one of the slave
 * stacks. You can now call this function every second, with a time parameter
 * of two seconds. The channel will be *high* all the time. If now the RS485
 * connection is lost, the channel will turn *low* in at most two seconds.
 */
int industrial_digital_out_4_v2_set_monoflop(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, bool value, uint32_t time);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns (for the given channel) the current value and the time as set by
 * {@link industrial_digital_out_4_v2_set_monoflop} as well as the remaining time until the value flips.
 * 
 * If the timer is not running currently, the remaining time will be returned
 * as 0.
 */
int industrial_digital_out_4_v2_get_monoflop(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, bool *ret_value, uint32_t *ret_time, uint32_t *ret_time_remaining);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Each channel has a corresponding LED. You can turn the LED off, on or show a
 * heartbeat. You can also set the LED to "Channel Status". In this mode the
 * LED is on if the channel is high and off otherwise.
 * 
 * By default all channel LEDs are configured as "Channel Status".
 */
int industrial_digital_out_4_v2_set_channel_led_config(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, uint8_t config);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the channel LED configuration as set by {@link industrial_digital_out_4_v2_set_channel_led_config}
 */
int industrial_digital_out_4_v2_get_channel_led_config(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Activates a PWM for the given channel.
 * 
 * To turn the PWM off again, you can set the frequency to 0 or any other
 * function that changes a value of the channel (e.g. {@link industrial_digital_out_4_v2_set_selected_value}).
 * 
 * The optocoupler of the Industrial Digital
 * Out 4 Bricklet 2.0 has a rise time and fall time of 11.5us (each) at 24V. So the maximum
 * useful frequency value is about 400000 (40kHz).
 * 
 * A running monoflop timer for the given channel will be aborted if this function
 * is called.
 */
int industrial_digital_out_4_v2_set_pwm_configuration(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, uint32_t frequency, uint16_t duty_cycle);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the PWM configuration as set by {@link industrial_digital_out_4_v2_set_pwm_configuration}.
 */
int industrial_digital_out_4_v2_get_pwm_configuration(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, uint32_t *ret_frequency, uint16_t *ret_duty_cycle);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * TBD
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
int industrial_digital_out_4_v2_write_wiegand_data_low_level(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint16_t data_length, bool data_data[256]);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * TBD
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
int industrial_digital_out_4_v2_get_wiegand_state(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t *ret_wiegand_state);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the error count for the communication between Brick and Bricklet.
 * 
 * The errors are divided into
 * 
 * * ACK checksum errors,
 * * message checksum errors,
 * * framing errors and
 * * overflow errors.
 * 
 * The errors counts are for errors that occur on the Bricklet side. All
 * Bricks have a similar function that returns the errors on the Brick side.
 */
int industrial_digital_out_4_v2_get_spitfp_error_count(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Sets the bootloader mode and returns the status after the requested
 * mode change was instigated.
 * 
 * You can change from bootloader mode to firmware mode and vice versa. A change
 * from bootloader mode to firmware mode will only take place if the entry function,
 * device identifier and CRC are present and correct.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
int industrial_digital_out_4_v2_set_bootloader_mode(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t mode, uint8_t *ret_status);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the current bootloader mode, see {@link industrial_digital_out_4_v2_set_bootloader_mode}.
 */
int industrial_digital_out_4_v2_get_bootloader_mode(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t *ret_mode);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Sets the firmware pointer for {@link industrial_digital_out_4_v2_write_firmware}. The pointer has
 * to be increased by chunks of size 64. The data is written to flash
 * every 4 chunks (which equals to one page of size 256).
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
int industrial_digital_out_4_v2_set_write_firmware_pointer(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t pointer);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Writes 64 Bytes of firmware at the position as written by
 * {@link industrial_digital_out_4_v2_set_write_firmware_pointer} before. The firmware is written
 * to flash every 4 chunks.
 * 
 * You can only write firmware in bootloader mode.
 * 
 * This function is used by Brick Viewer during flashing. It should not be
 * necessary to call it in a normal user program.
 */
int industrial_digital_out_4_v2_write_firmware(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t data[64], uint8_t *ret_status);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Sets the status LED configuration. By default the LED shows
 * communication traffic between Brick and Bricklet, it flickers once
 * for every 10 received data packets.
 * 
 * You can also turn the LED permanently on/off or show a heartbeat.
 * 
 * If the Bricklet is in bootloader mode, the LED is will show heartbeat by default.
 */
int industrial_digital_out_4_v2_set_status_led_config(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t config);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the configuration as set by {@link industrial_digital_out_4_v2_set_status_led_config}
 */
int industrial_digital_out_4_v2_get_status_led_config(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t *ret_config);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the temperature as measured inside the microcontroller. The
 * value returned is not the ambient temperature!
 * 
 * The temperature is only proportional to the real temperature and it has bad
 * accuracy. Practically it is only useful as an indicator for
 * temperature changes.
 */
int industrial_digital_out_4_v2_get_chip_temperature(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, int16_t *ret_temperature);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Calling this function will reset the Bricklet. All configurations
 * will be lost.
 * 
 * After a reset you have to create new device objects,
 * calling functions on the existing ones will result in
 * undefined behavior!
 */
int industrial_digital_out_4_v2_reset(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Writes a new UID into flash. If you want to set a new UID
 * you have to decode the Base58 encoded UID string into an
 * integer first.
 * 
 * We recommend that you use Brick Viewer to change the UID.
 */
int industrial_digital_out_4_v2_write_uid(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t uid);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the current UID as an integer. Encode as
 * Base58 to get the usual string version.
 */
int industrial_digital_out_4_v2_read_uid(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t *ret_uid);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * Returns the UID, the UID where the Bricklet is connected to,
 * the position, the hardware and firmware version as well as the
 * device identifier.
 * 
 * The position can be 'a', 'b', 'c', 'd', 'e', 'f', 'g' or 'h' (Bricklet Port).
 * A Bricklet connected to an :ref:`Isolator Bricklet <isolator_bricklet>` is always as
 * position 'z'.
 * 
 * The device identifier numbers can be found :ref:`here <device_identifier>`.
 * |device_identifier_constant|
 */
int industrial_digital_out_4_v2_get_identity(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

/**
 * \ingroup BrickletIndustrialDigitalOut4V2
 *
 * TBD
 * 
 * .. versionadded:: 2.0.3$nbsp;(Plugin)
 */
int industrial_digital_out_4_v2_write_wiegand_data(IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, bool *data, uint16_t data_length);

#ifdef __cplusplus
}
#endif

#endif
