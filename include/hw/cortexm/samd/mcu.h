/*
 * Atmel SAMD Cortex-M devices emulation.
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

#ifndef SAMD_MCU_H_
#define SAMD_MCU_H_

#include "qemu/osdep.h"

#include "hw/boards.h"
#include <hw/cortexm/mcu.h>
#include <hw/cortexm/samd/capabilities.h>
#include <hw/cortexm/samd/port.h>
#include <hw/cortexm/parson.h>

#include <hw/cortexm/armemus.h>

// ----------------------------------------------------------------------------

#define TYPE_SAMD_MCU "samd-mcu"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_SAMD_MCU_PARENT TYPE_CORTEXM_MCU
typedef CortexMClass SAMDMCUParentClass;
typedef CortexMState SAMDMCUParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define SAMD_MCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(SAMDMCUClass, (obj), TYPE_SAMD_MCU)
#define SAMD_MCU_CLASS(klass) \
    OBJECT_CLASS_CHECK(SAMDMCUClass, (klass), TYPE_SAMD_MCU)

typedef struct SAMDMCUClass {
    // private:
    SAMDMCUParentClass parent_class;
    // public:

} SAMDMCUClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define SAMD_MCU_STATE(obj) \
    OBJECT_CHECK(SAMDMCUState, (obj), TYPE_SAMD_MCU)

typedef struct SAMDMCUState {
    // private:
    SAMDMCUParentState parent_obj;
    // public:

    // Constructor parameters.
    const SAMDCapabilities *param_capabilities;

    // Specific SAMD capabilities; Cortex-M capabilities are separate.
    const SAMDCapabilities *capabilities;

    Object *container;

    DeviceState *port;

} SAMDMCUState;

// ------ Public --------------------------------------------------------------

/*
 * Might be deprecated in the future; peripherals are named and can be
 * obtained by name.
 */

G_INLINE_FUNC DeviceState *samd_mcu_get_port_dev(DeviceState *dev)
{
    return DEVICE((SAMD_MCU_STATE(dev)->port));
}

G_INLINE_FUNC SAMDMCUState *samd_mcu_get(void)
{
    return SAMD_MCU_STATE(object_resolve_path("/machine/mcu", NULL));
}

// ----------------------------------------------------------------------------

#endif /* SAMD_MCU_H_ */
