/*
 * SAMD Cortex-M devices emulation.
 *
 * Copyright (c) 2017 lmcapacho.
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

#ifndef SAMD_MCUS_H_
#define SAMD_MCUS_H_

#include "qemu/osdep.h"

#include <hw/cortexm/samd/mcu.h>

/* ------------------------------------------------------------------------- */

// For compatibility with some development tools, it is
// strongly recommended to use the CMSIS names.
#define TYPE_SAMD21G18 "SAMD21G18"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_SAMD_DEVICE_PARENT TYPE_SAMD_MCU
typedef SAMDMCUClass SAMDDeviceParentClass;
typedef SAMDMCUState SAMDDeviceParentState;

// ----------------------------------------------------------------------------

// Class definitions.
// Warning, this cast must not check the type!
#define SAMD_DEVICE_GET_CLASS(obj) \
    ((SAMDDeviceClass *)object_get_class(OBJECT(obj)))

// Structure to define the specifics of each MCU. Capabilities are
// split between core & samd; they care processed by parent class
// constructors.
typedef struct {

    const char *name; // CMSIS device name

    const CortexMCapabilities cortexm;
    const SAMDCapabilities *samd;

} SAMDPartInfo;

typedef struct {
    // private:
    SAMDDeviceParentClass parent_class;
    // public:

    SAMDPartInfo *part_info;
} SAMDDeviceClass;

// ----------------------------------------------------------------------------

// Instance definitions.
typedef struct {
    // private:
    SAMDDeviceParentState parent_class;
// public:

} SAMDDeviceState;

// ----------------------------------------------------------------------------

#endif /* SAMD_MCUS_H_ */
