/*
 * SAM Cortex-M devices emulation.
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

#ifndef SAM_MCUS_H_
#define SAM_MCUS_H_

#include "qemu/osdep.h"

#include <hw/cortexm/sam/mcu.h>

/* ------------------------------------------------------------------------- */

// For compatibility with some development tools, it is
// strongly recommended to use the CMSIS names.
#define TYPE_SAM3X8E "SAM3X8E"
//#define TYPE_SAMF072RB "SAMF072RB"
//#define TYPE_SAMF100RB "SAMF100RB"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_SAM_DEVICE_PARENT TYPE_SAM_MCU
typedef SAMMCUClass SAMDeviceParentClass;
typedef SAMMCUState SAMDeviceParentState;

// ----------------------------------------------------------------------------

// Class definitions.
// Warning, this cast must not check the type!
#define SAM_DEVICE_GET_CLASS(obj) \
    ((SAMDeviceClass *)object_get_class(OBJECT(obj)))

// Structure to define the specifics of each MCU. Capabilities are
// split between core & sam; they care processed by parent class
// constructors.
typedef struct {

    const char *name; // CMSIS device name

    const CortexMCapabilities cortexm;
    const SAMCapabilities *sam;

} SAMPartInfo;

typedef struct {
    // private:
    SAMDeviceParentClass parent_class;
    // public:

    SAMPartInfo *part_info;
} SAMDeviceClass;

// ----------------------------------------------------------------------------

// Instance definitions.
typedef struct {
    // private:
    SAMDeviceParentState parent_class;
// public:

} SAMDeviceState;

// ----------------------------------------------------------------------------

#endif /* SAM_MCUS_H_ */
