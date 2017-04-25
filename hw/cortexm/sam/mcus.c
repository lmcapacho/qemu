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

#include <hw/cortexm/sam/mcus.h>
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
 * Define all Atmel SAM MCUs, based on table capabilities.
 *
 * To easily reuse the definitions, each line includes a pointer
 * to the core capabilities and a pointer to the sam capabilities.
 * This greatly simplify adding definition that differ only in memory size.
 */

static const SAMCapabilities sam3x8e = {
    .family = SAM_FAMILY_SAM3X,

    .has_pioa = true,
    .has_piob = true,
    .has_pioc = true,
    .has_piod = true,
    
    .hsi_freq_hz = 83000000,
    .lsi_freq_hz = 4000000,
};

// ----------------------------------------------------------------------------

static const SAMPartInfo sam_mcus[] = {
    {
        .name = TYPE_SAM3X8E,
        .cortexm = {
            .flash_size_kb = 512,
            .sram_size_kb = 96,

            .svd_file_name = "SAM3X8E-qemu.json",
            .svd_device_name = "SAM3X8E",
        /**/
        },
        
        .sam = &sam3x8e,
    /**/
    },
    { }
/**/
};

// ----------------------------------------------------------------------------

static void sam_mcus_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    // Add properties here.
}

static void sam_mcus_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    SAMDeviceClass *st_class = SAM_DEVICE_GET_CLASS(dev);
    SAMPartInfo *part_info = st_class->part_info;

    // Set additional constructor parameters, that were passed via
    // the .class_data and copied to custom class member.
    qdev_prop_set_ptr(dev, "cortexm-capabilities",
            (void *) &part_info->cortexm);
    qdev_prop_set_ptr(dev, "sam-capabilities", (void *) part_info->sam);

    // Call parent realize().
    // We do not know the current typename, since it was generated
    // with a table, so we use the parent typename.

    if (!cm_device_by_name_realize(dev, errp, TYPE_SAM_DEVICE_PARENT)) {
        return;
    }
}

static void sam_mcus_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_by_name_reset(dev, TYPE_SAM_MCU);
}

static void sam_mcus_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->realize = sam_mcus_realize_callback;
    dc->reset = sam_mcus_reset_callback;
    // dc->props = sam_mcus_properties;

    SAMDeviceClass *st_class = (SAMDeviceClass *) (klass);
    // Copy the 'data' param, pointing to a ParamInfo, to the class
    // structure, to be retrieved by the constructor.
    st_class->part_info = data;
}

// Register all devices described in the table.
// Pass the pointer to the table element as .class_data
// to the .class_init.

static void sam_mcus_types_init(void)
{
    int i;
    for (i = 0; sam_mcus[i].name; ++i) {

        TypeInfo ti = {
            .name = sam_mcus[i].name,
            .parent = TYPE_SAM_DEVICE_PARENT,
            .instance_init = sam_mcus_instance_init_callback,
            .instance_size = sizeof(SAMDeviceState),
            .class_init = sam_mcus_class_init_callback,
            .class_size = sizeof(SAMDeviceClass),
            .class_data = (void *) &sam_mcus[i] };
        type_register(&ti);
    }
}

type_init(sam_mcus_types_init);

// ----------------------------------------------------------------------------
