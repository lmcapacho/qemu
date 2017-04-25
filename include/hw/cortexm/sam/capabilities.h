/*
 * Atmel SAM capabilities definitions.
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

#ifndef SAM_CAPABILITIES_H_
#define SAM_CAPABILITIES_H_

#include <stdint.h>

/*
 * This file defines the members used in the structure used to describe
 * the capabilities of the Atmel SAM MCUs.
 *
 */

#define TYPE_SAM_PREFIX       "sam:"
#define TYPE_SAM3X_PREFIX     "sam3x:"
#define TYPE_SAM3X8E_PREFIX   "sam3x83:"

#define DEVICE_PATH_SAM "/machine/mcu/sam/"

typedef enum {
    SAM_FAMILY_UNKNOWN,
    SAM_FAMILY_SAM3X,
} sam_family_t;

#define SAM_MAX_PIO  (4)

typedef struct {

    sam_family_t family;

    // Properties common to all families
    uint32_t hsi_freq_hz;
    uint32_t lsi_freq_hz;

    // PIOs
    unsigned int has_pioa :1;
    unsigned int has_piob :1;
    unsigned int has_pioc :1;
    unsigned int has_piod :1;

    unsigned char num_pio; // Will be computed, no need to set it.

} SAMCapabilities;

#endif /* SAM_CAPABILITIES_H_ */
