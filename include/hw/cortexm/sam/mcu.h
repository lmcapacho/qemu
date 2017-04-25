/*
 * Atmel SAM Cortex-M devices emulation.
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

#ifndef SAM_MCU_H_
#define SAM_MCU_H_

#include "qemu/osdep.h"

#include "hw/boards.h"
#include <hw/cortexm/mcu.h>
#include <hw/cortexm/sam/capabilities.h>
#include <hw/cortexm/sam/pio.h>
#include <hw/cortexm/parson.h>

// ----------------------------------------------------------------------------

#define TYPE_SAM_MCU "sam-mcu"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_SAM_MCU_PARENT TYPE_CORTEXM_MCU
typedef CortexMClass SAMMCUParentClass;
typedef CortexMState SAMMCUParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define SAM_MCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(SAMMCUClass, (obj), TYPE_SAM_MCU)
#define SAM_MCU_CLASS(klass) \
    OBJECT_CLASS_CHECK(SAMMCUClass, (klass), TYPE_SAM_MCU)

typedef struct SAMMCUClass {
    // private:
    SAMMCUParentClass parent_class;
    // public:

} SAMMCUClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define SAM_MCU_STATE(obj) \
    OBJECT_CHECK(SAMMCUState, (obj), TYPE_SAM_MCU)

typedef struct SAMMCUState {
    // private:
    SAMMCUParentState parent_obj;
    // public:

    // Constructor parameters.
    const SAMCapabilities *param_capabilities;

    // Specific SAM capabilities; Cortex-M capabilities are separate.
    const SAMCapabilities *capabilities;

    Object *container;
    
    uint32_t hse_freq_hz;
    uint32_t lse_freq_hz;
    
    DeviceState *pio[SAM_MAX_PIO];
    int num_pio;

} SAMMCUState;

// ------ Public --------------------------------------------------------------

/*
 * Might be deprecated in the future; peripherals are named and can be
 * obtained by name.
 */

G_INLINE_FUNC DeviceState *sam_mcu_get_pio_dev(DeviceState *dev,
        int port_index)
{
    assert(port_index < SAM_MAX_PIO);
    return DEVICE((SAM_MCU_STATE(dev)->pio[port_index]));
}

G_INLINE_FUNC SAMMCUState *sam_mcu_get(void)
{
    return SAM_MCU_STATE(object_resolve_path("/machine/mcu", NULL));
}

// ----------------------------------------------------------------------------

#endif /* SAM_MCU_H_ */
