/*
 * Atmel SAM Cortex-M device emulation.
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

#include <hw/cortexm/sam/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>
#include <hw/cortexm/bitband.h>
#include <hw/cortexm/json-parser.h>

#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----- Public ---------------------------------------------------------------

// ----- Private --------------------------------------------------------------

// Create children PIO nodes.
// Public names are "/machine/sam/PIO%c".
static void create_pio(SAMMCUState *state, sam_pio_index_t index)
{
    state->pio[index] = DEVICE(sam_pio_create(state->container, index));
}

// Constructor for all SAM devices, based on capabilities.
//
// Alias the flash memory to 0x080000.
//
static void sam_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_SAM_MCU)) {
        return;
    }

    SAMMCUState *state = SAM_MCU_STATE(dev);
    SAMCapabilities *capabilities = g_new0(SAMCapabilities, 1);

    if (state->param_capabilities) {
        // Copy R/O structure to a local R/W copy, to update it.
        memcpy(capabilities, state->param_capabilities,
                sizeof(SAMCapabilities));
    }

    assert(capabilities != NULL);
    state->capabilities = capabilities;

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);
    // const char *svd_device_name = cm_state->capabilities->svd_device_name;

    const char *family;
    switch (capabilities->family) {
    case SAM_FAMILY_SAM3X:
        family = "SAM3X";
        break;
    default:
        family = "unknown";
    }
    qemu_log_mask(LOG_FUNC, "SAM Family: %s\n", family);

    // Devices will be addressed below "/machine/mcu/sam".
    state->container = container_get(OBJECT(dev), "/sam");

    // Memory alias
    {
        // The SAM family stores its Flash memory at some base address
        // in memory (0x080000 for medium density devices), and then
        // aliases it to the boot memory space, which starts at 0x00000000
        // (the "System Memory" can also be aliased to 0x00000000,
        // but this is not implemented here).
        // The processor executes the code in the aliased memory at 0x00000000.
        // We need to make a QEMU alias so that reads in the 0x080000 area
        // are passed through to the 0x00000000 area. Note that this is the
        // opposite of real hardware, where the memory at 0x00000000 passes
        // reads through the "real" flash memory at 0x080000, but it works
        // the same either way.
        int flash_size = cm_state->flash_size_kb * 1024;

        // Allocate a new region for the alias
        MemoryRegion *flash_alias_mem = g_malloc(sizeof(MemoryRegion));

        Object *mem_container = container_get(cm_state->container, "/memory");

        // Initialise the new region
        memory_region_init_alias(flash_alias_mem, mem_container,
                "mem-flash-alias", &cm_state->flash_mem, 0, flash_size);
        memory_region_set_readonly(flash_alias_mem, true);

        // Alias it as the SAM specific 0x080000	
        memory_region_add_subregion(get_system_memory(), 0x080000,
                flash_alias_mem);
    }

    // Peripheral bitband.
    /*{
        if (capabilities->has_periph_bitband) {
            cortexm_bitband_init(state->container, "periph-bitband",
                    0x40000000);
        }
    }*/

    state->num_pio = 0;

    // The presence in SVD is maximal, must be validated by capabilities.
    // PIOA
    if (capabilities->has_pioa
            && svd_has_named_peripheral(cm_state->svd_json, "PIOA")) {
        create_pio(state, SAM_PORT_PIOA);
        state->num_pio = 1;
    }
    // PIOB
    if (capabilities->has_piob
            && svd_has_named_peripheral(cm_state->svd_json, "PIOB")) {
        create_pio(state, SAM_PORT_PIOB);
        state->num_pio = 2;
    }

    // PIOC
    if (capabilities->has_pioc
            && svd_has_named_peripheral(cm_state->svd_json, "PIOC")) {
        create_pio(state, SAM_PORT_PIOC);
        state->num_pio = 3;
    }

    // PIOD
    if (capabilities->has_piod
            && svd_has_named_peripheral(cm_state->svd_json, "PIOD")) {
        create_pio(state, SAM_PORT_PIOD);
        state->num_pio = 4;
    }
}

static int sam_mcu_reset_object(Object *obj, void *opaque)
{
    if (cm_object_is_instance_of_typename(obj, TYPE_DEVICE)) {
        device_reset(DEVICE(obj));
    }
    return 0; // Non-0 will break the iterator.
}

static void sam_mcu_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_SAM_MCU);

    SAMMCUState *state = SAM_MCU_STATE(dev);

    object_child_foreach(state->container, sam_mcu_reset_object, NULL);
}

// Virtual function, overriding (in fact extending) the Cortex-M code.
static void sam_mcu_memory_regions_create_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Create the parent (Cortex-M) memory regions
    CortexMClass *parent_class = CORTEXM_MCU_CLASS(
            object_class_by_name(TYPE_CORTEXM_MCU));
    parent_class->memory_regions_create(dev);
}

// TODO: get rid of the pointer property.
#define DEFINE_PROP_SAMCAPABILITIES_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, const SAMCapabilities*)

static Property sam_mcu_properties[] = {
        DEFINE_PROP_SAMCAPABILITIES_PTR("sam-capabilities",
                SAMMCUState, param_capabilities),
    DEFINE_PROP_END_OF_LIST(), /**/
};

static void sam_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

	/*
    SAMMCUState *state = SAM_MCU_STATE(obj);

    cm_object_property_add_uint32(obj, "hse-freq-hz", &state->hse_freq_hz);
    state->hse_freq_hz = 0;

    cm_object_property_add_uint32(obj, "lse-freq-hz", &state->lse_freq_hz);
    state->lse_freq_hz = 0;
    */
}

static void sam_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->realize = sam_mcu_realize_callback;
    dc->reset = sam_mcu_reset_callback;

    dc->props = sam_mcu_properties;

    CortexMClass *cm_class = CORTEXM_MCU_CLASS(klass);
    cm_class->memory_regions_create = sam_mcu_memory_regions_create_callback;
}

static const TypeInfo sam_mcu_type_info = {
    .abstract = true,
    .name = TYPE_SAM_MCU,
    .parent = TYPE_SAM_MCU_PARENT,
    .instance_init = sam_mcu_instance_init_callback,
    .instance_size = sizeof(SAMMCUState),
    .class_init = sam_mcu_class_init_callback,
    .class_size = sizeof(SAMMCUClass)
/**/
};

// ----- Type inits. -----

static void sam_type_init(void)
{
    type_register_static(&sam_mcu_type_info);
}

type_init(sam_type_init);

// ----------------------------------------------------------------------------

