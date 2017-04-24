/*
 * TIVA C Series Cortex-M device emulation.
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

#include <hw/cortexm/tiva/mcu.h>
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


// Create children GPIO nodes.
// Public names are "/machine/tiva/GPIO%c".
static void create_gpio(TIVAMCUState *state, tm_gpio_index_t index)
{
    state->gpio[index] = DEVICE(tm_gpio_create(state->container, index));
}

// Constructor for all TIVA devices, based on capabilities.
//
// Alias the flash memory to 0x080000.
//
static void tiva_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_TIVA_MCU)) {
        return;
    }

    TIVAMCUState *state = TIVA_MCU_STATE(dev);
    TIVACapabilities *capabilities = g_new0(TIVACapabilities, 1);

    if (state->param_capabilities) {
        // Copy R/O structure to a local R/W copy, to update it.
        memcpy(capabilities, state->param_capabilities,
                sizeof(TIVACapabilities));
    }

    assert(capabilities != NULL);
    state->capabilities = capabilities;

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);
    // const char *svd_device_name = cm_state->capabilities->svd_device_name;

    const char *family;
    switch (capabilities->family) {
    case TIVA_FAMILY_TM4C:
        family = "TM4C";
        break;
    default:
        family = "unknown";
    }
    qemu_log_mask(LOG_FUNC, "TIVA Family: %s\n", family);

    // Devices will be addressed below "/machine/mcu/tiva".
    state->container = container_get(OBJECT(dev), "/tiva");

    // Memory alias
    {
        // The TIVA family stores its Flash memory at some base address
        // in memory (0x080000 for medium density devices), and then
        // aliases it to the boot memory space, which starts at 0x00000000
        // (the "System Memory" can also be aliased to 0x00000000,
        // but this is not implemented here).
        // The processor executes the code in the aliased memory at 0x00000000.
        // We need to make a QEMU alias so that reads in the 0x080000 area
        // are passed through to the 0x00000000 area. Note that this is the
        // opposite of real hardware, where the memory at 0x00000000 passes
        // reads through the "real" flash memory at 0x080000, but it works
        // the tivae either way.
        int flash_size = cm_state->flash_size_kb * 1024;

        // Allocate a new region for the alias
        MemoryRegion *flash_alias_mem = g_malloc(sizeof(MemoryRegion));

        Object *mem_container = container_get(cm_state->container, "/memory");

        // Initialise the new region
        memory_region_init_alias(flash_alias_mem, mem_container,
                "mem-flash-alias", &cm_state->flash_mem, 0, flash_size);
        memory_region_set_readonly(flash_alias_mem, true);

        // Alias it as the TIVA specific 0x080000	
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

    state->num_port = 0;

    // The presence in SVD is maximal, must be validated by capabilities.
    // GPIOA
    if (capabilities->has_porta
            && svd_has_named_peripheral(cm_state->svd_json, "GPIOA")) {
        create_gpio(state, TM_PORT_GPIOA);
        state->num_port = 1;
    }
    // GPIOB
    if (capabilities->has_portb
            && svd_has_named_peripheral(cm_state->svd_json, "GPIOB")) {
        create_gpio(state, TM_PORT_GPIOB);
        state->num_port = 2;
    }
    // GPIOC
    if (capabilities->has_portc
            && svd_has_named_peripheral(cm_state->svd_json, "GPIOC")) {
        create_gpio(state, TM_PORT_GPIOC);
        state->num_port = 3;
    }
    // GPIOD
    if (capabilities->has_portd
            && svd_has_named_peripheral(cm_state->svd_json, "GPIOD")) {
        create_gpio(state, TM_PORT_GPIOD);
        state->num_port = 4;
    }
    // GPIOE
    if (capabilities->has_porte
            && svd_has_named_peripheral(cm_state->svd_json, "GPIOE")) {
        create_gpio(state, TM_PORT_GPIOE);
        state->num_port = 5;
    }
    // GPIOF
    if (capabilities->has_portf
            && svd_has_named_peripheral(cm_state->svd_json, "GPIOF")) {
        create_gpio(state, TM_PORT_GPIOF);
        state->num_port = 6;
    }
}

static int tiva_mcu_reset_object(Object *obj, void *opaque)
{
    if (cm_object_is_instance_of_typename(obj, TYPE_DEVICE)) {
        device_reset(DEVICE(obj));
    }
    return 0; // Non-0 will break the iterator.
}

static void tiva_mcu_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_TIVA_MCU);

    TIVAMCUState *state = TIVA_MCU_STATE(dev);

    object_child_foreach(state->container, tiva_mcu_reset_object, NULL);
}

// Virtual function, overriding (in fact extending) the Cortex-M code.
static void tiva_mcu_memory_regions_create_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Create the parent (Cortex-M) memory regions
    CortexMClass *parent_class = CORTEXM_MCU_CLASS(
            object_class_by_name(TYPE_CORTEXM_MCU));
    parent_class->memory_regions_create(dev);
}

// TODO: get rid of the pointer property.
#define DEFINE_PROP_TIVACAPABILITIES_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, const TIVACapabilities*)

static Property tiva_mcu_properties[] = {
        DEFINE_PROP_TIVACAPABILITIES_PTR("tiva-capabilities",
                TIVAMCUState, param_capabilities),
    DEFINE_PROP_END_OF_LIST(), /**/
};

static void tiva_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();
}

static void tiva_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->realize = tiva_mcu_realize_callback;
    dc->reset = tiva_mcu_reset_callback;

    dc->props = tiva_mcu_properties;

    CortexMClass *cm_class = CORTEXM_MCU_CLASS(klass);
    cm_class->memory_regions_create = tiva_mcu_memory_regions_create_callback;
}

static const TypeInfo tiva_mcu_type_info = {
    .abstract = true,
    .name = TYPE_TIVA_MCU,
    .parent = TYPE_TIVA_MCU_PARENT,
    .instance_init = tiva_mcu_instance_init_callback,
    .instance_size = sizeof(TIVAMCUState),
    .class_init = tiva_mcu_class_init_callback,
    .class_size = sizeof(TIVAMCUClass)
/**/
};

// ----- Type inits. -----

static void tiva_type_init(void)
{
    type_register_static(&tiva_mcu_type_info);
}

type_init(tiva_type_init);

// ----------------------------------------------------------------------------

