/*
 * TIVA C Series capabilities definitions.
 *
 * Copyright (c) 2017 lmcapacho
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TIVA_CAPABILITIES_H_
#define TIVA_CAPABILITIES_H_

#include <stdint.h>

/*
 * This file defines the members used in the structure used to describe
 * the capabilities of the Atmel TIVA MCUs.
 *
 */

#define TYPE_TM_PREFIX				"tm:"
#define TYPE_TM4C_PREFIX			"tm4c:"
#define TYPE_TM4C123GH6PM_PREFIX	"tm4c123gh6pm:"

#define DEVICE_PATH_TIVA "/machine/mcu/tiva/"

typedef enum {
    TIVA_FAMILY_UNKNOWN,
    TIVA_FAMILY_TM4C,
} tiva_family_t;

#define TM_MAX_PIO  (6)

typedef struct {

    tiva_family_t family;

    // Properties common to all families

    // GPIOs
    unsigned int has_porta :1;
    unsigned int has_portb :1;
    unsigned int has_portc :1;
    unsigned int has_portd :1;
    unsigned int has_porte :1;
    unsigned int has_portf :1;

    unsigned char num_port; // Will be computed, no need to set it.

} TIVACapabilities;

#endif /* TIVA_CAPABILITIES_H_ */
