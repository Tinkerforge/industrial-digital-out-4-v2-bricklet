/* industrial-digital-out-4-v2-bricklet
 * Copyright (C) 2020 Olaf Lüke <olaf@tinkerforge.com>
 *
 * wiegand.h: Simple bit banging wiegand sender
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

#ifndef WIEGAND_H
#define WIEGAND_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint16_t data_length;
	uint8_t data[32];

	uint16_t data_index;
	uint32_t last_time;

	bool done;
} Wiegand;

extern Wiegand wiegand;

void wiegand_tick(void);
void wiegand_init(void);

#endif