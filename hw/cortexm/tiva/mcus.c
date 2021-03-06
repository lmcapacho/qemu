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

#include <hw/cortexm/tiva/mcus.h>
#include <hw/cortexm/mcu.h>
#include <hw/cortexm/helper.h>

#include "exec/address-spaces.h"
#include "qemu/error-report.h"
#include "sysemu/sysemu.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----------------------------------------------------------------------------

/*
 * Define all Atmel TIVA MCUs, based on table capabilities.
 *
 * To easily reuse the definitions, each line includes a pointer
 * to the core capabilities and a pointer to the tiva capabilities.
 * This greatly simplify adding definition that differ only in memory size.
 */

static const TIVACapabilities tm4c123g = {
    .family = TIVA_FAMILY_TM4C,

    .has_porta = true,
    .has_portb = true,
    .has_portc = true,
    .has_portd = true,
    .has_porte = true,
    .has_portf = true,
};

// ----------------------------------------------------------------------------

static const TIVAPartInfo tiva_mcus[] = {
    {
        .name = TYPE_TM4C123GH6PM,
        .cortexm = {
            .flash_size_kb = 256,
            .sram_size_kb = 32,

            .svd_file_name = "TM4C123GH6PM-qemu.json",
            .svd_device_name = "TM4C123GH6PM",
        /**/
        },

        .tiva = &tm4c123g,
    /**/
    },
    { }
/**/
};

// ----------------------------------------------------------------------------

static void tiva_mcus_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    // Add properties here.
}

static void tiva_mcus_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    TIVADeviceClass *st_class = TIVA_DEVICE_GET_CLASS(dev);
    TIVAPartInfo *part_info = st_class->part_info;

    // Set additional constructor parameters, that were passed via
    // the .class_data and copied to custom class member.
    qdev_prop_set_ptr(dev, "cortexm-capabilities",
            (void *) &part_info->cortexm);
    qdev_prop_set_ptr(dev, "tiva-capabilities", (void *) part_info->tiva);

    // Call parent realize().
    // We do not know the current typename, since it was generated
    // with a table, so we use the parent typename.

    if (!cm_device_by_name_realize(dev, errp, TYPE_TIVA_DEVICE_PARENT)) {
        return;
    }
}

static void tiva_mcus_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_by_name_reset(dev, TYPE_TIVA_MCU);
}

static void tiva_mcus_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->realize = tiva_mcus_realize_callback;
    dc->reset = tiva_mcus_reset_callback;
    // dc->props = tiva_mcus_properties;

    TIVADeviceClass *st_class = (TIVADeviceClass *) (klass);
    // Copy the 'data' param, pointing to a ParamInfo, to the class
    // structure, to be retrieved by the constructor.
    st_class->part_info = data;
}

// Register all devices described in the table.
// Pass the pointer to the table element as .class_data
// to the .class_init.

static void tiva_mcus_types_init(void)
{
    int i;
    for (i = 0; tiva_mcus[i].name; ++i) {

        TypeInfo ti = {
            .name = tiva_mcus[i].name,
            .parent = TYPE_TIVA_DEVICE_PARENT,
            .instance_init = tiva_mcus_instance_init_callback,
            .instance_size = sizeof(TIVADeviceState),
            .class_init = tiva_mcus_class_init_callback,
            .class_size = sizeof(TIVADeviceClass),
            .class_data = (void *) &tiva_mcus[i] };
        type_register(&ti);
    }
}

type_init(tiva_mcus_types_init);

// ----------------------------------------------------------------------------
