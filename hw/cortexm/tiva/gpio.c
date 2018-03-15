/*
 * TIVA C Series - GPIO (Register map for GPIO peripheral) emulation.
 *
 * Copyright (c) 2017 lmcapacho.
 * Copyright (c) 2016 Liviu Ionescu.
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
 * You should have received a copy of the GNU General Public Licen
 se along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <hw/cortexm/tiva/gpio.h>
#include <hw/cortexm/tiva/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void tm4c123gh6pm_gpio_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    TMGPIOState *state = TM_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.tm4c.reg.data = cm_object_get_child_by_name(obj, "DATA");
    state->u.tm4c.reg.dir = cm_object_get_child_by_name(obj, "DIR");
    state->u.tm4c.reg.is = cm_object_get_child_by_name(obj, "IS");
    state->u.tm4c.reg.ibe = cm_object_get_child_by_name(obj, "IBE");
    state->u.tm4c.reg.iev = cm_object_get_child_by_name(obj, "IEV");
    state->u.tm4c.reg.im = cm_object_get_child_by_name(obj, "IM");
    state->u.tm4c.reg.ris = cm_object_get_child_by_name(obj, "RIS");
    state->u.tm4c.reg.mis = cm_object_get_child_by_name(obj, "MIS");
    state->u.tm4c.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->u.tm4c.reg.afsel = cm_object_get_child_by_name(obj, "AFSEL");
    state->u.tm4c.reg.dr2r = cm_object_get_child_by_name(obj, "DR2R");
    state->u.tm4c.reg.dr4r = cm_object_get_child_by_name(obj, "DR4R");
    state->u.tm4c.reg.dr8r = cm_object_get_child_by_name(obj, "DR8R");
    state->u.tm4c.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.tm4c.reg.pur = cm_object_get_child_by_name(obj, "PUR");
    state->u.tm4c.reg.pdr = cm_object_get_child_by_name(obj, "PDR");
    state->u.tm4c.reg.slr = cm_object_get_child_by_name(obj, "SLR");
    state->u.tm4c.reg.den = cm_object_get_child_by_name(obj, "DEN");
    state->u.tm4c.reg.lock = cm_object_get_child_by_name(obj, "LOCK");
    state->u.tm4c.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.tm4c.reg.amsel = cm_object_get_child_by_name(obj, "AMSEL");
    state->u.tm4c.reg.pctl = cm_object_get_child_by_name(obj, "PCTL");
    state->u.tm4c.reg.adcctl = cm_object_get_child_by_name(obj, "ADCCTL");
    state->u.tm4c.reg.dmactl = cm_object_get_child_by_name(obj, "DMACTL");

    // DATA bitfields.

    // DIR bitfields.

    // IS bitfields.

    // IBE bitfields.

    // IEV bitfields.

    // IM bitfields.
    state->u.tm4c.fld.im.gpio_im_gpio = cm_object_get_child_by_name(state->u.tm4c.reg.im, "GPIO_IM_GPIO");

    // RIS bitfields.
    state->u.tm4c.fld.ris.gpio_ris_gpio = cm_object_get_child_by_name(state->u.tm4c.reg.ris, "GPIO_RIS_GPIO");

    // MIS bitfields.
    state->u.tm4c.fld.mis.gpio_mis_gpio = cm_object_get_child_by_name(state->u.tm4c.reg.mis, "GPIO_MIS_GPIO");

    // ICR bitfields.
    state->u.tm4c.fld.icr.gpio_icr_gpio = cm_object_get_child_by_name(state->u.tm4c.reg.icr, "GPIO_ICR_GPIO");

    // AFSEL bitfields.

    // DR2R bitfields.

    // DR4R bitfields.

    // DR8R bitfields.

    // ODR bitfields.

    // PUR bitfields.

    // PDR bitfields.

    // SLR bitfields.

    // DEN bitfields.

    // LOCK bitfields.
    state->u.tm4c.fld.lock.gpio_lock = cm_object_get_child_by_name(state->u.tm4c.reg.lock, "GPIO_LOCK");

    // CR bitfields.

    // AMSEL bitfields.

    // PCTL bitfields.

    // ADCCTL bitfields.

    // DMACTL bitfields.
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Public ---------------------------------------------------------------

// Create PIO%c and return it.

Object* tm_gpio_create(Object *parent, tm_gpio_index_t index)
{
    if ((int) index >= TM_PORT_GPIO_UNDEFINED) {
        hw_error("Cannot assign GPIO%c: QEMU supports only %d ports\n",
                'A' + index, TM_PORT_GPIO_UNDEFINED);
    }

    char child_name[10];
    snprintf(child_name, sizeof(child_name) - 1, "GPIO%c",
            'A' + index - TM_PORT_GPIOA);
    // Passing a local string is ok.
    Object *gpio = cm_object_new(parent, child_name, TYPE_TM_GPIO);
    //int i;

    object_property_set_int(gpio, index, "port-index", NULL);

    cm_object_realize(gpio);

    return gpio;
}

// Return a pointer to the GPIO%c object, or null if not found.

Object* tm_gpio_get(int index)
{
    char gpio_name[40];
    snprintf(gpio_name, sizeof(gpio_name), DEVICE_PATH_TIVA "GPIO%c",
            'A' + index - TM_PORT_GPIOA);
    return object_resolve_path(gpio_name, NULL);
}


// ----- Private --------------------------------------------------------------

static void tm_gpio_update_output(TMGPIOState *state, uint32_t old_value, uint32_t new_value)
{
    // Compute pins that changed value.
    uint32_t changed = old_value ^ new_value;

	char gpio_name[3];
    snprintf(gpio_name, sizeof(gpio_name), "P%c",
            'A' + state->port_index - TM_PORT_GPIOA);

	int pin;
	uint32_t mask = 1;
	for (pin = 0; pin < TM_GPIO_PIN_COUNT; pin++, mask <<= 1) {
        if ((changed & mask) != 0) {
			fprintf(stderr, "%s", gpio_name);
			if( new_value & mask )
				fprintf(stderr, "%d:HIGH\n", pin);
			else
				fprintf(stderr, "%d:LOW\n", pin);
        }
    }
}


static void tm_gpio_data_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    TMGPIOState *state = TM_GPIO_STATE(periph);
	
	peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
			 
	tm_gpio_update_output(state, prev_value, full_value);
}

#if 0
static peripheral_register_t tm_gpio_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    TMGPIOState *state = TM_GPIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void tm_gpio_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    TMGPIOState *state = TM_GPIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t tm_gpio_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    TMGPIOState *state = TM_GPIO_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void tm_gpio_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    TMGPIOState *state = TM_GPIO_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

static void tm_gpio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    TMGPIOState *state = TM_GPIO_STATE(obj);

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = TM_PORT_GPIO_UNDEFINED;
    
    // Capabilities are not yet available.
}

static void tm_gpio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_TM_GPIO)) {
        return;
    }

    TIVAMCUState *mcu = tiva_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    TMGPIOState *state = TM_GPIO_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const TIVACapabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);
    
    char periph_name[10];
    snprintf(periph_name, sizeof(periph_name) - 1, "GPIO%c",
            'A' + state->port_index);

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    switch (capabilities->family) {
    case TIVA_FAMILY_TM4C:

        tm4c123gh6pm_gpio_create_objects(obj, cm_state->svd_json, periph_name);

		state->reg.data = state->u.tm4c.reg.data;
        // TODO: add actions.
        // cm_object_property_set_str(state->u.tm4c.fld.xxx.fff, "GGG", "follows");
        // cm_object_property_set_str(state->u.tm4c.fld.xxx.fff, "GGG", "cleared-by");

        // TODO: add callbacks.
        // peripheral_register_set_pre_read(state->tm4c.reg.xxx, &tm_gpio_xxx_pre_read_callback);
        // peripheral_register_set_post_read(state->tm4c.reg.xxx, &tm_gpio_xxx_post_read_callback);
        // peripheral_register_set_pre_read(state->tm4c.reg.xxx, &tm_gpio_xxx_pret_read_callback);
        // peripheral_register_set_post_write(state->tm4c.reg.xxx, &tm_gpio_xxx_post_write_callback);
        peripheral_register_set_post_write(state->reg.data, &tm_gpio_data_post_write_callback);

        // TODO: add interrupts.

        break;

    default:
        assert(false);
        break;
    }

    peripheral_prepare_registers(obj);
}

static void tm_gpio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_TM_GPIO);
}

static void tm_gpio_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = tm_gpio_reset_callback;
    dc->realize = tm_gpio_realize_callback;
}

static const TypeInfo tm_gpio_type_info = {
    .name = TYPE_TM_GPIO,
    .parent = TYPE_TM_GPIO_PARENT,
    .instance_init = tm_gpio_instance_init_callback,
    .instance_size = sizeof(TMGPIOState),
    .class_init = tm_gpio_class_init_callback,
    .class_size = sizeof(TMGPIOClass) };

static void tm_gpio_register_types(void)
{
    type_register_static(&tm_gpio_type_info);
}

type_init(tm_gpio_register_types);

// ----------------------------------------------------------------------------
