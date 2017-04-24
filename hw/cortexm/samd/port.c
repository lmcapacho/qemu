/*
 * SAMD - PORT (Port Module) emulation.
 *
 * Copyright (c) 2017 lmcapacho
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <hw/cortexm/samd/port.h>
#include <hw/cortexm/samd/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void atsamd21g18a_port_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    SAMDPORTState *state = SAMD_PORT_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.samd21.reg.dir = cm_object_get_child_by_name(obj, "DIR");
    state->u.samd21.reg.dirclr = cm_object_get_child_by_name(obj, "DIRCLR");
    state->u.samd21.reg.dirset = cm_object_get_child_by_name(obj, "DIRSET");
    state->u.samd21.reg.dirtgl = cm_object_get_child_by_name(obj, "DIRTGL");
    state->u.samd21.reg.out = cm_object_get_child_by_name(obj, "OUT");
    state->u.samd21.reg.outclr = cm_object_get_child_by_name(obj, "OUTCLR");
    state->u.samd21.reg.outset = cm_object_get_child_by_name(obj, "OUTSET");
    state->u.samd21.reg.outtgl = cm_object_get_child_by_name(obj, "OUTTGL");
    state->u.samd21.reg.in = cm_object_get_child_by_name(obj, "IN");
    state->u.samd21.reg.ctrl = cm_object_get_child_by_name(obj, "CTRL");
    state->u.samd21.reg.wrconfig = cm_object_get_child_by_name(obj, "WRCONFIG");
    state->u.samd21.reg.pmux0_ = cm_object_get_child_by_name(obj, "PMUX0_");
    state->u.samd21.reg.pmux1_ = cm_object_get_child_by_name(obj, "PMUX1_");
    state->u.samd21.reg.pincfg0_ = cm_object_get_child_by_name(obj, "PINCFG0_");
    state->u.samd21.reg.pincfg1_ = cm_object_get_child_by_name(obj, "PINCFG1_");

    // DIR bitfields.
    state->u.samd21.fld.dir.dir = cm_object_get_child_by_name(state->u.samd21.reg.dir, "DIR");

    // DIRCLR bitfields.
    state->u.samd21.fld.dirclr.dirclr = cm_object_get_child_by_name(state->u.samd21.reg.dirclr, "DIRCLR");

    // DIRSET bitfields.
    state->u.samd21.fld.dirset.dirset = cm_object_get_child_by_name(state->u.samd21.reg.dirset, "DIRSET");

    // DIRTGL bitfields.
    state->u.samd21.fld.dirtgl.dirtgl = cm_object_get_child_by_name(state->u.samd21.reg.dirtgl, "DIRTGL");

    // OUT bitfields.
    state->u.samd21.fld.out.out = cm_object_get_child_by_name(state->u.samd21.reg.out, "OUT");

    // OUTCLR bitfields.
    state->u.samd21.fld.outclr.outclr = cm_object_get_child_by_name(state->u.samd21.reg.outclr, "OUTCLR");

    // OUTSET bitfields.
    state->u.samd21.fld.outset.outset = cm_object_get_child_by_name(state->u.samd21.reg.outset, "OUTSET");

    // OUTTGL bitfields.
    state->u.samd21.fld.outtgl.outtgl = cm_object_get_child_by_name(state->u.samd21.reg.outtgl, "OUTTGL");

    // IN bitfields.
    state->u.samd21.fld.in.in = cm_object_get_child_by_name(state->u.samd21.reg.in, "IN");

    // CTRL bitfields.
    state->u.samd21.fld.ctrl.sampling = cm_object_get_child_by_name(state->u.samd21.reg.ctrl, "SAMPLING");

    // WRCONFIG bitfields.
    state->u.samd21.fld.wrconfig.pinmask = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "PINMASK");
    state->u.samd21.fld.wrconfig.pmuxen = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "PMUXEN");
    state->u.samd21.fld.wrconfig.inen = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "INEN");
    state->u.samd21.fld.wrconfig.pullen = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "PULLEN");
    state->u.samd21.fld.wrconfig.drvstr = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "DRVSTR");
    state->u.samd21.fld.wrconfig.pmux = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "PMUX");
    state->u.samd21.fld.wrconfig.wrpmux = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "WRPMUX");
    state->u.samd21.fld.wrconfig.wrpincfg = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "WRPINCFG");
    state->u.samd21.fld.wrconfig.hwsel = cm_object_get_child_by_name(state->u.samd21.reg.wrconfig, "HWSEL");

    // PMUX0_ bitfields.
    state->u.samd21.fld.pmux0_.pmuxe = cm_object_get_child_by_name(state->u.samd21.reg.pmux0_, "PMUXE");
    state->u.samd21.fld.pmux0_.pmuxo = cm_object_get_child_by_name(state->u.samd21.reg.pmux0_, "PMUXO");

    // PMUX1_ bitfields.

    // PINCFG0_ bitfields.
    state->u.samd21.fld.pincfg0_.pmuxen = cm_object_get_child_by_name(state->u.samd21.reg.pincfg0_, "PMUXEN");
    state->u.samd21.fld.pincfg0_.inen = cm_object_get_child_by_name(state->u.samd21.reg.pincfg0_, "INEN");
    state->u.samd21.fld.pincfg0_.pullen = cm_object_get_child_by_name(state->u.samd21.reg.pincfg0_, "PULLEN");
    state->u.samd21.fld.pincfg0_.drvstr = cm_object_get_child_by_name(state->u.samd21.reg.pincfg0_, "DRVSTR");

    // PINCFG1_ bitfields.
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

static void samd_port_update_output(SAMDPORTState *state, uint32_t old_value, uint32_t new_value)
{
    // Compute pins that changed value.
    uint32_t changed = old_value ^ new_value;

	int pin;
	uint32_t mask = 1;
	for (pin = 0; pin < SAMD_MAX_PINS; pin++, mask <<= 1) {
        if ((changed & mask) != 0) {
			fprintf(stderr, "PORT");
			if( new_value & mask )
				fprintf(stderr, "%d:HIGH\n", pin);
			else
				fprintf(stderr, "%d:LOW\n", pin);
        }
    }
}

static void samd_port_outset_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    SAMDPORTState *state = SAMD_PORT_STATE(periph);

    uint32_t old_value = peripheral_register_read_value(state->reg.out);

	uint32_t set_pins = old_value | full_value;
	peripheral_register_write_value(state->reg.out, set_pins);
	 
	samd_port_update_output(state, old_value, set_pins);
}

static void samd_port_outclr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    SAMDPORTState *state = SAMD_PORT_STATE(periph);

    uint32_t old_value = peripheral_register_read_value(state->reg.out);

	uint32_t clear_pins = old_value & (~full_value);
	peripheral_register_write_value(state->reg.out, clear_pins);

	samd_port_update_output(state, old_value, clear_pins);
}

#if 0
static peripheral_register_t samd_port_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    SAMDPORTState *state = SAMD_PORT_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void samd_port_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    SAMDPORTState *state = SAMD_PORT_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t samd_port_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    SAMDPORTState *state = SAMD_PORT_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void samd_port_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    SAMDPORTState *state = SAMD_PORT_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

static void samd_port_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    //SAMDPORTState *state = SAMD_PORT_STATE(obj);

    // Capabilities are not yet available.
    
    // TODO: Add code to initialise all members.
}

static void samd_port_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_SAMD_PORT)) {
        return;
    }

    SAMDMCUState *mcu = samd_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    SAMDPORTState *state = SAMD_PORT_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const SAMDCapabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "PORT";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    switch (capabilities->family) {
    case SAMD_FAMILY_SAMD21:

        atsamd21g18a_port_create_objects(obj, cm_state->svd_json, periph_name);

        state->reg.out		= state->u.samd21.reg.out;        
        state->reg.outset  	= state->u.samd21.reg.outset;
        state->reg.outclr  	= state->u.samd21.reg.outclr;	

        // TODO: add actions.
        // cm_object_property_set_str(state->u.samd21.fld.xxx.fff, "GGG", "follows");
        // cm_object_property_set_str(state->u.samd21.fld.xxx.fff, "GGG", "cleared-by");

        // TODO: add callbacks.
        // peripheral_register_set_pre_read(state->samd21.reg.xxx, &samd_port_xxx_pre_read_callback);
        // peripheral_register_set_post_read(state->samd21.reg.xxx, &samd_port_xxx_post_read_callback);
        // peripheral_register_set_pre_read(state->samd21.reg.xxx, &samd_port_xxx_pret_read_callback);
        // peripheral_register_set_post_write(state->samd21.reg.xxx, &samd_port_xxx_post_write_callback);
		peripheral_register_set_post_write(state->reg.outset, &samd_port_outset_post_write_callback);
		peripheral_register_set_post_write(state->reg.outclr, &samd_port_outclr_post_write_callback);
		
        // TODO: add interrupts.

        break;

    default:
        assert(false);
        break;
    }

    peripheral_prepare_registers(obj);
}

static void samd_port_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

	SAMDPORTState *state = SAMD_PORT_STATE(dev);
	
    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_SAMD_PORT);
    
	peripheral_register_set_raw_value(state->reg.out, 0);
}

static void samd_port_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = samd_port_reset_callback;
    dc->realize = samd_port_realize_callback;
}

static const TypeInfo samd_port_type_info = {
    .name = TYPE_SAMD_PORT,
    .parent = TYPE_SAMD_PORT_PARENT,
    .instance_init = samd_port_instance_init_callback,
    .instance_size = sizeof(SAMDPORTState),
    .class_init = samd_port_class_init_callback,
    .class_size = sizeof(SAMDPORTClass) };

static void samd_port_register_types(void)
{
    type_register_static(&samd_port_type_info);
}

type_init(samd_port_register_types);

// ----------------------------------------------------------------------------
