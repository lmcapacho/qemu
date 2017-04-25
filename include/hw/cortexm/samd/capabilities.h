/*
 * Atmel SAMD capabilities definitions.
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

#ifndef SAMD_CAPABILITIES_H_
#define SAMD_CAPABILITIES_H_

#include <stdint.h>

/*
 * This file defines the members used in the structure used to describe
 * the capabilities of the Atmel SAMD MCUs.
 *
 */

#define TYPE_SAMD_PREFIX       	"samd:"
#define TYPE_SAMD21_PREFIX     	"samd21:"
#define TYPE_SAMD21G18_PREFIX   "samd21g18:"

#define DEVICE_PATH_SAMD "/machine/mcu/samd/"

typedef enum {
    SAMD_FAMILY_UNKNOWN,
    SAMD_FAMILY_SAMD21,
} samd_family_t;

#define SAMD_MAX_PINS  (32)

typedef struct {

    samd_family_t family;

    // Properties common to all families

    // PORT
    unsigned int has_port :1;

} SAMDCapabilities;

#endif /* SAMD_CAPABILITIES_H_ */
