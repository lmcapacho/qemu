/*
 * TIVA C Series Cortex-M devices emulation.
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

#ifndef TIVA_MCUS_H_
#define TIVA_MCUS_H_

#include "qemu/osdep.h"

#include <hw/cortexm/tiva/mcu.h>

/* ------------------------------------------------------------------------- */

// For compatibility with some development tools, it is
// strongly recommended to use the CMSIS names.
#define TYPE_TM4C123GH6PM "TM4C123GH6PM"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_TIVA_DEVICE_PARENT TYPE_TIVA_MCU
typedef TIVAMCUClass TIVADeviceParentClass;
typedef TIVAMCUState TIVADeviceParentState;

// ----------------------------------------------------------------------------

// Class definitions.
// Warning, this cast must not check the type!
#define TIVA_DEVICE_GET_CLASS(obj) \
    ((TIVADeviceClass *)object_get_class(OBJECT(obj)))

// Structure to define the specifics of each MCU. Capabilities are
// split between core & tiva; they care processed by parent class
// constructors.
typedef struct {

    const char *name; // CMSIS device name

    const CortexMCapabilities cortexm;
    const TIVACapabilities *tiva;

} TIVAPartInfo;

typedef struct {
    // private:
    TIVADeviceParentClass parent_class;
    // public:

    TIVAPartInfo *part_info;
} TIVADeviceClass;

// ----------------------------------------------------------------------------

// Instance definitions.
typedef struct {
    // private:
    TIVADeviceParentState parent_class;
// public:

} TIVADeviceState;

// ----------------------------------------------------------------------------

#endif /* TIVA_MCUS_H_ */
