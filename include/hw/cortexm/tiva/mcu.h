/*
 * TIVA C Series Cortex-M devices emulation.
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

#ifndef TIVA_MCU_H_
#define TIVA_MCU_H_

#include "qemu/osdep.h"

#include "hw/boards.h"
#include <hw/cortexm/mcu.h>
#include <hw/cortexm/tiva/capabilities.h>
#include <hw/cortexm/tiva/gpio.h>
#include <hw/cortexm/parson.h>

// ----------------------------------------------------------------------------

#define TYPE_TIVA_MCU "tiva-mcu"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_TIVA_MCU_PARENT TYPE_CORTEXM_MCU
typedef CortexMClass TIVAMCUParentClass;
typedef CortexMState TIVAMCUParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define TIVA_MCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(TIVAMCUClass, (obj), TYPE_TIVA_MCU)
#define TIVA_MCU_CLASS(klass) \
    OBJECT_CLASS_CHECK(TIVAMCUClass, (klass), TYPE_TIVA_MCU)

typedef struct TIVAMCUClass {
    // private:
    TIVAMCUParentClass parent_class;
    // public:

} TIVAMCUClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define TIVA_MCU_STATE(obj) \
    OBJECT_CHECK(TIVAMCUState, (obj), TYPE_TIVA_MCU)

typedef struct TIVAMCUState {
    // private:
    TIVAMCUParentState parent_obj;
    // public:

    // Constructor parameters.
    const TIVACapabilities *param_capabilities;

    // Specific TIVA capabilities; Cortex-M capabilities are separate.
    const TIVACapabilities *capabilities;

    Object *container;

    DeviceState *gpio[TM_MAX_PIO];
    int num_port;

} TIVAMCUState;

// ------ Public --------------------------------------------------------------


G_INLINE_FUNC TIVAMCUState *tiva_mcu_get(void)
{
    return TIVA_MCU_STATE(object_resolve_path("/machine/mcu", NULL));
}

// ----------------------------------------------------------------------------

#endif /* TIVA_MCU_H_ */
