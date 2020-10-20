/* industrial-digital-out-4-v2-bricklet
 * Copyright (C) 2020 Olaf Lüke <olaf@tinkerforge.com>
 *
 * config_ido4.h: Configuration for IDO4 IO
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

#ifndef CONFIG_IDO4_H
#define CONFIG_IDO4_H

#include "xmc_gpio.h"

#define IDO4_CHANNEL_0_PIN      3
#define IDO4_CHANNEL_0_PORT     XMC_GPIO_PORT1
#define IDO4_CHANNEL_1_PIN      2
#define IDO4_CHANNEL_1_PORT     XMC_GPIO_PORT1
#define IDO4_CHANNEL_2_PIN      1
#define IDO4_CHANNEL_2_PORT     XMC_GPIO_PORT1
#define IDO4_CHANNEL_3_PIN      0
#define IDO4_CHANNEL_3_PORT     XMC_GPIO_PORT1

#define IDO4_CHANNEL_LED_0_PIN  12
#define IDO4_CHANNEL_LED_0_PORT XMC_GPIO_PORT0
#define IDO4_CHANNEL_LED_1_PIN  9
#define IDO4_CHANNEL_LED_1_PORT XMC_GPIO_PORT0
#define IDO4_CHANNEL_LED_2_PIN  8
#define IDO4_CHANNEL_LED_2_PORT XMC_GPIO_PORT0
#define IDO4_CHANNEL_LED_3_PIN  7
#define IDO4_CHANNEL_LED_3_PORT XMC_GPIO_PORT0

#endif