/*
 * SAM - PIO (Parallel Input/Output Controller A) emulation.
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <hw/cortexm/sam/pio.h>
#include <hw/cortexm/sam/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void sam3x8e_pio_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    SAMPIOState *state = SAM_PIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.sam3x.reg.per = cm_object_get_child_by_name(obj, "PER");
    state->u.sam3x.reg.pdr = cm_object_get_child_by_name(obj, "PDR");
    state->u.sam3x.reg.psr = cm_object_get_child_by_name(obj, "PSR");
    state->u.sam3x.reg.oer = cm_object_get_child_by_name(obj, "OER");
    state->u.sam3x.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.sam3x.reg.osr = cm_object_get_child_by_name(obj, "OSR");
    state->u.sam3x.reg.ifer = cm_object_get_child_by_name(obj, "IFER");
    state->u.sam3x.reg.ifdr = cm_object_get_child_by_name(obj, "IFDR");
    state->u.sam3x.reg.ifsr = cm_object_get_child_by_name(obj, "IFSR");
    state->u.sam3x.reg.sodr = cm_object_get_child_by_name(obj, "SODR");
    state->u.sam3x.reg.codr = cm_object_get_child_by_name(obj, "CODR");
    state->u.sam3x.reg.odsr = cm_object_get_child_by_name(obj, "ODSR");
    state->u.sam3x.reg.pdsr = cm_object_get_child_by_name(obj, "PDSR");
    state->u.sam3x.reg.ier = cm_object_get_child_by_name(obj, "IER");
    state->u.sam3x.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->u.sam3x.reg.imr = cm_object_get_child_by_name(obj, "IMR");
    state->u.sam3x.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.sam3x.reg.mder = cm_object_get_child_by_name(obj, "MDER");
    state->u.sam3x.reg.mddr = cm_object_get_child_by_name(obj, "MDDR");
    state->u.sam3x.reg.mdsr = cm_object_get_child_by_name(obj, "MDSR");
    state->u.sam3x.reg.pudr = cm_object_get_child_by_name(obj, "PUDR");
    state->u.sam3x.reg.puer = cm_object_get_child_by_name(obj, "PUER");
    state->u.sam3x.reg.pusr = cm_object_get_child_by_name(obj, "PUSR");
    state->u.sam3x.reg.absr = cm_object_get_child_by_name(obj, "ABSR");
    state->u.sam3x.reg.scifsr = cm_object_get_child_by_name(obj, "SCIFSR");
    state->u.sam3x.reg.difsr = cm_object_get_child_by_name(obj, "DIFSR");
    state->u.sam3x.reg.ifdgsr = cm_object_get_child_by_name(obj, "IFDGSR");
    state->u.sam3x.reg.scdr = cm_object_get_child_by_name(obj, "SCDR");
    state->u.sam3x.reg.ower = cm_object_get_child_by_name(obj, "OWER");
    state->u.sam3x.reg.owdr = cm_object_get_child_by_name(obj, "OWDR");
    state->u.sam3x.reg.owsr = cm_object_get_child_by_name(obj, "OWSR");
    state->u.sam3x.reg.aimer = cm_object_get_child_by_name(obj, "AIMER");
    state->u.sam3x.reg.aimdr = cm_object_get_child_by_name(obj, "AIMDR");
    state->u.sam3x.reg.aimmr = cm_object_get_child_by_name(obj, "AIMMR");
    state->u.sam3x.reg.esr = cm_object_get_child_by_name(obj, "ESR");
    state->u.sam3x.reg.lsr = cm_object_get_child_by_name(obj, "LSR");
    state->u.sam3x.reg.elsr = cm_object_get_child_by_name(obj, "ELSR");
    state->u.sam3x.reg.fellsr = cm_object_get_child_by_name(obj, "FELLSR");
    state->u.sam3x.reg.rehlsr = cm_object_get_child_by_name(obj, "REHLSR");
    state->u.sam3x.reg.frlhsr = cm_object_get_child_by_name(obj, "FRLHSR");
    state->u.sam3x.reg.locksr = cm_object_get_child_by_name(obj, "LOCKSR");
    state->u.sam3x.reg.wpmr = cm_object_get_child_by_name(obj, "WPMR");
    state->u.sam3x.reg.wpsr = cm_object_get_child_by_name(obj, "WPSR");

    // PER bitfields.
    state->u.sam3x.fld.per.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P0");
    state->u.sam3x.fld.per.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P1");
    state->u.sam3x.fld.per.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P2");
    state->u.sam3x.fld.per.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P3");
    state->u.sam3x.fld.per.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P4");
    state->u.sam3x.fld.per.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P5");
    state->u.sam3x.fld.per.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P6");
    state->u.sam3x.fld.per.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P7");
    state->u.sam3x.fld.per.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P8");
    state->u.sam3x.fld.per.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P9");
    state->u.sam3x.fld.per.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P10");
    state->u.sam3x.fld.per.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P11");
    state->u.sam3x.fld.per.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P12");
    state->u.sam3x.fld.per.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P13");
    state->u.sam3x.fld.per.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P14");
    state->u.sam3x.fld.per.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P15");
    state->u.sam3x.fld.per.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P16");
    state->u.sam3x.fld.per.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P17");
    state->u.sam3x.fld.per.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P18");
    state->u.sam3x.fld.per.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P19");
    state->u.sam3x.fld.per.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P20");
    state->u.sam3x.fld.per.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P21");
    state->u.sam3x.fld.per.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P22");
    state->u.sam3x.fld.per.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P23");
    state->u.sam3x.fld.per.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P24");
    state->u.sam3x.fld.per.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P25");
    state->u.sam3x.fld.per.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P26");
    state->u.sam3x.fld.per.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P27");
    state->u.sam3x.fld.per.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P28");
    state->u.sam3x.fld.per.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P29");
    state->u.sam3x.fld.per.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P30");
    state->u.sam3x.fld.per.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.per, "P31");

    // PDR bitfields.
    state->u.sam3x.fld.pdr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P0");
    state->u.sam3x.fld.pdr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P1");
    state->u.sam3x.fld.pdr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P2");
    state->u.sam3x.fld.pdr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P3");
    state->u.sam3x.fld.pdr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P4");
    state->u.sam3x.fld.pdr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P5");
    state->u.sam3x.fld.pdr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P6");
    state->u.sam3x.fld.pdr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P7");
    state->u.sam3x.fld.pdr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P8");
    state->u.sam3x.fld.pdr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P9");
    state->u.sam3x.fld.pdr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P10");
    state->u.sam3x.fld.pdr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P11");
    state->u.sam3x.fld.pdr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P12");
    state->u.sam3x.fld.pdr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P13");
    state->u.sam3x.fld.pdr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P14");
    state->u.sam3x.fld.pdr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P15");
    state->u.sam3x.fld.pdr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P16");
    state->u.sam3x.fld.pdr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P17");
    state->u.sam3x.fld.pdr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P18");
    state->u.sam3x.fld.pdr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P19");
    state->u.sam3x.fld.pdr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P20");
    state->u.sam3x.fld.pdr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P21");
    state->u.sam3x.fld.pdr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P22");
    state->u.sam3x.fld.pdr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P23");
    state->u.sam3x.fld.pdr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P24");
    state->u.sam3x.fld.pdr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P25");
    state->u.sam3x.fld.pdr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P26");
    state->u.sam3x.fld.pdr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P27");
    state->u.sam3x.fld.pdr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P28");
    state->u.sam3x.fld.pdr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P29");
    state->u.sam3x.fld.pdr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P30");
    state->u.sam3x.fld.pdr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.pdr, "P31");

    // PSR bitfields.
    state->u.sam3x.fld.psr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P0");
    state->u.sam3x.fld.psr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P1");
    state->u.sam3x.fld.psr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P2");
    state->u.sam3x.fld.psr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P3");
    state->u.sam3x.fld.psr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P4");
    state->u.sam3x.fld.psr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P5");
    state->u.sam3x.fld.psr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P6");
    state->u.sam3x.fld.psr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P7");
    state->u.sam3x.fld.psr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P8");
    state->u.sam3x.fld.psr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P9");
    state->u.sam3x.fld.psr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P10");
    state->u.sam3x.fld.psr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P11");
    state->u.sam3x.fld.psr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P12");
    state->u.sam3x.fld.psr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P13");
    state->u.sam3x.fld.psr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P14");
    state->u.sam3x.fld.psr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P15");
    state->u.sam3x.fld.psr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P16");
    state->u.sam3x.fld.psr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P17");
    state->u.sam3x.fld.psr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P18");
    state->u.sam3x.fld.psr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P19");
    state->u.sam3x.fld.psr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P20");
    state->u.sam3x.fld.psr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P21");
    state->u.sam3x.fld.psr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P22");
    state->u.sam3x.fld.psr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P23");
    state->u.sam3x.fld.psr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P24");
    state->u.sam3x.fld.psr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P25");
    state->u.sam3x.fld.psr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P26");
    state->u.sam3x.fld.psr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P27");
    state->u.sam3x.fld.psr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P28");
    state->u.sam3x.fld.psr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P29");
    state->u.sam3x.fld.psr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P30");
    state->u.sam3x.fld.psr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.psr, "P31");

    // OER bitfields.
    state->u.sam3x.fld.oer.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P0");
    state->u.sam3x.fld.oer.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P1");
    state->u.sam3x.fld.oer.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P2");
    state->u.sam3x.fld.oer.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P3");
    state->u.sam3x.fld.oer.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P4");
    state->u.sam3x.fld.oer.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P5");
    state->u.sam3x.fld.oer.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P6");
    state->u.sam3x.fld.oer.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P7");
    state->u.sam3x.fld.oer.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P8");
    state->u.sam3x.fld.oer.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P9");
    state->u.sam3x.fld.oer.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P10");
    state->u.sam3x.fld.oer.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P11");
    state->u.sam3x.fld.oer.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P12");
    state->u.sam3x.fld.oer.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P13");
    state->u.sam3x.fld.oer.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P14");
    state->u.sam3x.fld.oer.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P15");
    state->u.sam3x.fld.oer.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P16");
    state->u.sam3x.fld.oer.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P17");
    state->u.sam3x.fld.oer.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P18");
    state->u.sam3x.fld.oer.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P19");
    state->u.sam3x.fld.oer.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P20");
    state->u.sam3x.fld.oer.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P21");
    state->u.sam3x.fld.oer.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P22");
    state->u.sam3x.fld.oer.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P23");
    state->u.sam3x.fld.oer.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P24");
    state->u.sam3x.fld.oer.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P25");
    state->u.sam3x.fld.oer.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P26");
    state->u.sam3x.fld.oer.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P27");
    state->u.sam3x.fld.oer.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P28");
    state->u.sam3x.fld.oer.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P29");
    state->u.sam3x.fld.oer.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P30");
    state->u.sam3x.fld.oer.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.oer, "P31");

    // ODR bitfields.
    state->u.sam3x.fld.odr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P0");
    state->u.sam3x.fld.odr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P1");
    state->u.sam3x.fld.odr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P2");
    state->u.sam3x.fld.odr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P3");
    state->u.sam3x.fld.odr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P4");
    state->u.sam3x.fld.odr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P5");
    state->u.sam3x.fld.odr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P6");
    state->u.sam3x.fld.odr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P7");
    state->u.sam3x.fld.odr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P8");
    state->u.sam3x.fld.odr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P9");
    state->u.sam3x.fld.odr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P10");
    state->u.sam3x.fld.odr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P11");
    state->u.sam3x.fld.odr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P12");
    state->u.sam3x.fld.odr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P13");
    state->u.sam3x.fld.odr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P14");
    state->u.sam3x.fld.odr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P15");
    state->u.sam3x.fld.odr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P16");
    state->u.sam3x.fld.odr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P17");
    state->u.sam3x.fld.odr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P18");
    state->u.sam3x.fld.odr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P19");
    state->u.sam3x.fld.odr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P20");
    state->u.sam3x.fld.odr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P21");
    state->u.sam3x.fld.odr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P22");
    state->u.sam3x.fld.odr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P23");
    state->u.sam3x.fld.odr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P24");
    state->u.sam3x.fld.odr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P25");
    state->u.sam3x.fld.odr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P26");
    state->u.sam3x.fld.odr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P27");
    state->u.sam3x.fld.odr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P28");
    state->u.sam3x.fld.odr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P29");
    state->u.sam3x.fld.odr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P30");
    state->u.sam3x.fld.odr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.odr, "P31");

    // OSR bitfields.
    state->u.sam3x.fld.osr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P0");
    state->u.sam3x.fld.osr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P1");
    state->u.sam3x.fld.osr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P2");
    state->u.sam3x.fld.osr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P3");
    state->u.sam3x.fld.osr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P4");
    state->u.sam3x.fld.osr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P5");
    state->u.sam3x.fld.osr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P6");
    state->u.sam3x.fld.osr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P7");
    state->u.sam3x.fld.osr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P8");
    state->u.sam3x.fld.osr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P9");
    state->u.sam3x.fld.osr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P10");
    state->u.sam3x.fld.osr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P11");
    state->u.sam3x.fld.osr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P12");
    state->u.sam3x.fld.osr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P13");
    state->u.sam3x.fld.osr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P14");
    state->u.sam3x.fld.osr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P15");
    state->u.sam3x.fld.osr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P16");
    state->u.sam3x.fld.osr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P17");
    state->u.sam3x.fld.osr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P18");
    state->u.sam3x.fld.osr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P19");
    state->u.sam3x.fld.osr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P20");
    state->u.sam3x.fld.osr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P21");
    state->u.sam3x.fld.osr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P22");
    state->u.sam3x.fld.osr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P23");
    state->u.sam3x.fld.osr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P24");
    state->u.sam3x.fld.osr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P25");
    state->u.sam3x.fld.osr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P26");
    state->u.sam3x.fld.osr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P27");
    state->u.sam3x.fld.osr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P28");
    state->u.sam3x.fld.osr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P29");
    state->u.sam3x.fld.osr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P30");
    state->u.sam3x.fld.osr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.osr, "P31");

    // IFER bitfields.
    state->u.sam3x.fld.ifer.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P0");
    state->u.sam3x.fld.ifer.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P1");
    state->u.sam3x.fld.ifer.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P2");
    state->u.sam3x.fld.ifer.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P3");
    state->u.sam3x.fld.ifer.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P4");
    state->u.sam3x.fld.ifer.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P5");
    state->u.sam3x.fld.ifer.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P6");
    state->u.sam3x.fld.ifer.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P7");
    state->u.sam3x.fld.ifer.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P8");
    state->u.sam3x.fld.ifer.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P9");
    state->u.sam3x.fld.ifer.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P10");
    state->u.sam3x.fld.ifer.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P11");
    state->u.sam3x.fld.ifer.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P12");
    state->u.sam3x.fld.ifer.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P13");
    state->u.sam3x.fld.ifer.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P14");
    state->u.sam3x.fld.ifer.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P15");
    state->u.sam3x.fld.ifer.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P16");
    state->u.sam3x.fld.ifer.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P17");
    state->u.sam3x.fld.ifer.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P18");
    state->u.sam3x.fld.ifer.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P19");
    state->u.sam3x.fld.ifer.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P20");
    state->u.sam3x.fld.ifer.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P21");
    state->u.sam3x.fld.ifer.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P22");
    state->u.sam3x.fld.ifer.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P23");
    state->u.sam3x.fld.ifer.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P24");
    state->u.sam3x.fld.ifer.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P25");
    state->u.sam3x.fld.ifer.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P26");
    state->u.sam3x.fld.ifer.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P27");
    state->u.sam3x.fld.ifer.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P28");
    state->u.sam3x.fld.ifer.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P29");
    state->u.sam3x.fld.ifer.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P30");
    state->u.sam3x.fld.ifer.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.ifer, "P31");

    // IFDR bitfields.
    state->u.sam3x.fld.ifdr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P0");
    state->u.sam3x.fld.ifdr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P1");
    state->u.sam3x.fld.ifdr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P2");
    state->u.sam3x.fld.ifdr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P3");
    state->u.sam3x.fld.ifdr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P4");
    state->u.sam3x.fld.ifdr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P5");
    state->u.sam3x.fld.ifdr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P6");
    state->u.sam3x.fld.ifdr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P7");
    state->u.sam3x.fld.ifdr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P8");
    state->u.sam3x.fld.ifdr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P9");
    state->u.sam3x.fld.ifdr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P10");
    state->u.sam3x.fld.ifdr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P11");
    state->u.sam3x.fld.ifdr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P12");
    state->u.sam3x.fld.ifdr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P13");
    state->u.sam3x.fld.ifdr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P14");
    state->u.sam3x.fld.ifdr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P15");
    state->u.sam3x.fld.ifdr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P16");
    state->u.sam3x.fld.ifdr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P17");
    state->u.sam3x.fld.ifdr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P18");
    state->u.sam3x.fld.ifdr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P19");
    state->u.sam3x.fld.ifdr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P20");
    state->u.sam3x.fld.ifdr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P21");
    state->u.sam3x.fld.ifdr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P22");
    state->u.sam3x.fld.ifdr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P23");
    state->u.sam3x.fld.ifdr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P24");
    state->u.sam3x.fld.ifdr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P25");
    state->u.sam3x.fld.ifdr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P26");
    state->u.sam3x.fld.ifdr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P27");
    state->u.sam3x.fld.ifdr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P28");
    state->u.sam3x.fld.ifdr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P29");
    state->u.sam3x.fld.ifdr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P30");
    state->u.sam3x.fld.ifdr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdr, "P31");

    // IFSR bitfields.
    state->u.sam3x.fld.ifsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P0");
    state->u.sam3x.fld.ifsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P1");
    state->u.sam3x.fld.ifsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P2");
    state->u.sam3x.fld.ifsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P3");
    state->u.sam3x.fld.ifsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P4");
    state->u.sam3x.fld.ifsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P5");
    state->u.sam3x.fld.ifsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P6");
    state->u.sam3x.fld.ifsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P7");
    state->u.sam3x.fld.ifsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P8");
    state->u.sam3x.fld.ifsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P9");
    state->u.sam3x.fld.ifsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P10");
    state->u.sam3x.fld.ifsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P11");
    state->u.sam3x.fld.ifsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P12");
    state->u.sam3x.fld.ifsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P13");
    state->u.sam3x.fld.ifsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P14");
    state->u.sam3x.fld.ifsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P15");
    state->u.sam3x.fld.ifsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P16");
    state->u.sam3x.fld.ifsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P17");
    state->u.sam3x.fld.ifsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P18");
    state->u.sam3x.fld.ifsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P19");
    state->u.sam3x.fld.ifsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P20");
    state->u.sam3x.fld.ifsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P21");
    state->u.sam3x.fld.ifsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P22");
    state->u.sam3x.fld.ifsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P23");
    state->u.sam3x.fld.ifsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P24");
    state->u.sam3x.fld.ifsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P25");
    state->u.sam3x.fld.ifsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P26");
    state->u.sam3x.fld.ifsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P27");
    state->u.sam3x.fld.ifsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P28");
    state->u.sam3x.fld.ifsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P29");
    state->u.sam3x.fld.ifsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P30");
    state->u.sam3x.fld.ifsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.ifsr, "P31");

    // SODR bitfields.
    state->u.sam3x.fld.sodr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P0");
    state->u.sam3x.fld.sodr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P1");
    state->u.sam3x.fld.sodr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P2");
    state->u.sam3x.fld.sodr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P3");
    state->u.sam3x.fld.sodr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P4");
    state->u.sam3x.fld.sodr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P5");
    state->u.sam3x.fld.sodr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P6");
    state->u.sam3x.fld.sodr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P7");
    state->u.sam3x.fld.sodr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P8");
    state->u.sam3x.fld.sodr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P9");
    state->u.sam3x.fld.sodr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P10");
    state->u.sam3x.fld.sodr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P11");
    state->u.sam3x.fld.sodr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P12");
    state->u.sam3x.fld.sodr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P13");
    state->u.sam3x.fld.sodr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P14");
    state->u.sam3x.fld.sodr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P15");
    state->u.sam3x.fld.sodr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P16");
    state->u.sam3x.fld.sodr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P17");
    state->u.sam3x.fld.sodr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P18");
    state->u.sam3x.fld.sodr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P19");
    state->u.sam3x.fld.sodr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P20");
    state->u.sam3x.fld.sodr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P21");
    state->u.sam3x.fld.sodr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P22");
    state->u.sam3x.fld.sodr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P23");
    state->u.sam3x.fld.sodr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P24");
    state->u.sam3x.fld.sodr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P25");
    state->u.sam3x.fld.sodr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P26");
    state->u.sam3x.fld.sodr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P27");
    state->u.sam3x.fld.sodr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P28");
    state->u.sam3x.fld.sodr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P29");
    state->u.sam3x.fld.sodr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P30");
    state->u.sam3x.fld.sodr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.sodr, "P31");

    // CODR bitfields.
    state->u.sam3x.fld.codr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P0");
    state->u.sam3x.fld.codr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P1");
    state->u.sam3x.fld.codr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P2");
    state->u.sam3x.fld.codr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P3");
    state->u.sam3x.fld.codr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P4");
    state->u.sam3x.fld.codr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P5");
    state->u.sam3x.fld.codr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P6");
    state->u.sam3x.fld.codr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P7");
    state->u.sam3x.fld.codr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P8");
    state->u.sam3x.fld.codr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P9");
    state->u.sam3x.fld.codr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P10");
    state->u.sam3x.fld.codr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P11");
    state->u.sam3x.fld.codr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P12");
    state->u.sam3x.fld.codr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P13");
    state->u.sam3x.fld.codr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P14");
    state->u.sam3x.fld.codr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P15");
    state->u.sam3x.fld.codr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P16");
    state->u.sam3x.fld.codr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P17");
    state->u.sam3x.fld.codr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P18");
    state->u.sam3x.fld.codr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P19");
    state->u.sam3x.fld.codr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P20");
    state->u.sam3x.fld.codr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P21");
    state->u.sam3x.fld.codr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P22");
    state->u.sam3x.fld.codr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P23");
    state->u.sam3x.fld.codr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P24");
    state->u.sam3x.fld.codr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P25");
    state->u.sam3x.fld.codr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P26");
    state->u.sam3x.fld.codr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P27");
    state->u.sam3x.fld.codr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P28");
    state->u.sam3x.fld.codr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P29");
    state->u.sam3x.fld.codr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P30");
    state->u.sam3x.fld.codr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.codr, "P31");

    // ODSR bitfields.
    state->u.sam3x.fld.odsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P0");
    state->u.sam3x.fld.odsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P1");
    state->u.sam3x.fld.odsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P2");
    state->u.sam3x.fld.odsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P3");
    state->u.sam3x.fld.odsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P4");
    state->u.sam3x.fld.odsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P5");
    state->u.sam3x.fld.odsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P6");
    state->u.sam3x.fld.odsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P7");
    state->u.sam3x.fld.odsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P8");
    state->u.sam3x.fld.odsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P9");
    state->u.sam3x.fld.odsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P10");
    state->u.sam3x.fld.odsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P11");
    state->u.sam3x.fld.odsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P12");
    state->u.sam3x.fld.odsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P13");
    state->u.sam3x.fld.odsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P14");
    state->u.sam3x.fld.odsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P15");
    state->u.sam3x.fld.odsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P16");
    state->u.sam3x.fld.odsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P17");
    state->u.sam3x.fld.odsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P18");
    state->u.sam3x.fld.odsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P19");
    state->u.sam3x.fld.odsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P20");
    state->u.sam3x.fld.odsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P21");
    state->u.sam3x.fld.odsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P22");
    state->u.sam3x.fld.odsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P23");
    state->u.sam3x.fld.odsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P24");
    state->u.sam3x.fld.odsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P25");
    state->u.sam3x.fld.odsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P26");
    state->u.sam3x.fld.odsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P27");
    state->u.sam3x.fld.odsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P28");
    state->u.sam3x.fld.odsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P29");
    state->u.sam3x.fld.odsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P30");
    state->u.sam3x.fld.odsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.odsr, "P31");

    // PDSR bitfields.
    state->u.sam3x.fld.pdsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P0");
    state->u.sam3x.fld.pdsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P1");
    state->u.sam3x.fld.pdsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P2");
    state->u.sam3x.fld.pdsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P3");
    state->u.sam3x.fld.pdsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P4");
    state->u.sam3x.fld.pdsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P5");
    state->u.sam3x.fld.pdsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P6");
    state->u.sam3x.fld.pdsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P7");
    state->u.sam3x.fld.pdsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P8");
    state->u.sam3x.fld.pdsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P9");
    state->u.sam3x.fld.pdsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P10");
    state->u.sam3x.fld.pdsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P11");
    state->u.sam3x.fld.pdsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P12");
    state->u.sam3x.fld.pdsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P13");
    state->u.sam3x.fld.pdsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P14");
    state->u.sam3x.fld.pdsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P15");
    state->u.sam3x.fld.pdsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P16");
    state->u.sam3x.fld.pdsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P17");
    state->u.sam3x.fld.pdsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P18");
    state->u.sam3x.fld.pdsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P19");
    state->u.sam3x.fld.pdsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P20");
    state->u.sam3x.fld.pdsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P21");
    state->u.sam3x.fld.pdsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P22");
    state->u.sam3x.fld.pdsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P23");
    state->u.sam3x.fld.pdsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P24");
    state->u.sam3x.fld.pdsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P25");
    state->u.sam3x.fld.pdsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P26");
    state->u.sam3x.fld.pdsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P27");
    state->u.sam3x.fld.pdsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P28");
    state->u.sam3x.fld.pdsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P29");
    state->u.sam3x.fld.pdsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P30");
    state->u.sam3x.fld.pdsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.pdsr, "P31");

    // IER bitfields.
    state->u.sam3x.fld.ier.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P0");
    state->u.sam3x.fld.ier.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P1");
    state->u.sam3x.fld.ier.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P2");
    state->u.sam3x.fld.ier.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P3");
    state->u.sam3x.fld.ier.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P4");
    state->u.sam3x.fld.ier.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P5");
    state->u.sam3x.fld.ier.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P6");
    state->u.sam3x.fld.ier.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P7");
    state->u.sam3x.fld.ier.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P8");
    state->u.sam3x.fld.ier.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P9");
    state->u.sam3x.fld.ier.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P10");
    state->u.sam3x.fld.ier.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P11");
    state->u.sam3x.fld.ier.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P12");
    state->u.sam3x.fld.ier.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P13");
    state->u.sam3x.fld.ier.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P14");
    state->u.sam3x.fld.ier.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P15");
    state->u.sam3x.fld.ier.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P16");
    state->u.sam3x.fld.ier.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P17");
    state->u.sam3x.fld.ier.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P18");
    state->u.sam3x.fld.ier.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P19");
    state->u.sam3x.fld.ier.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P20");
    state->u.sam3x.fld.ier.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P21");
    state->u.sam3x.fld.ier.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P22");
    state->u.sam3x.fld.ier.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P23");
    state->u.sam3x.fld.ier.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P24");
    state->u.sam3x.fld.ier.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P25");
    state->u.sam3x.fld.ier.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P26");
    state->u.sam3x.fld.ier.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P27");
    state->u.sam3x.fld.ier.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P28");
    state->u.sam3x.fld.ier.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P29");
    state->u.sam3x.fld.ier.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P30");
    state->u.sam3x.fld.ier.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.ier, "P31");

    // IDR bitfields.
    state->u.sam3x.fld.idr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P0");
    state->u.sam3x.fld.idr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P1");
    state->u.sam3x.fld.idr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P2");
    state->u.sam3x.fld.idr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P3");
    state->u.sam3x.fld.idr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P4");
    state->u.sam3x.fld.idr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P5");
    state->u.sam3x.fld.idr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P6");
    state->u.sam3x.fld.idr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P7");
    state->u.sam3x.fld.idr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P8");
    state->u.sam3x.fld.idr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P9");
    state->u.sam3x.fld.idr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P10");
    state->u.sam3x.fld.idr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P11");
    state->u.sam3x.fld.idr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P12");
    state->u.sam3x.fld.idr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P13");
    state->u.sam3x.fld.idr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P14");
    state->u.sam3x.fld.idr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P15");
    state->u.sam3x.fld.idr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P16");
    state->u.sam3x.fld.idr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P17");
    state->u.sam3x.fld.idr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P18");
    state->u.sam3x.fld.idr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P19");
    state->u.sam3x.fld.idr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P20");
    state->u.sam3x.fld.idr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P21");
    state->u.sam3x.fld.idr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P22");
    state->u.sam3x.fld.idr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P23");
    state->u.sam3x.fld.idr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P24");
    state->u.sam3x.fld.idr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P25");
    state->u.sam3x.fld.idr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P26");
    state->u.sam3x.fld.idr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P27");
    state->u.sam3x.fld.idr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P28");
    state->u.sam3x.fld.idr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P29");
    state->u.sam3x.fld.idr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P30");
    state->u.sam3x.fld.idr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.idr, "P31");

    // IMR bitfields.
    state->u.sam3x.fld.imr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P0");
    state->u.sam3x.fld.imr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P1");
    state->u.sam3x.fld.imr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P2");
    state->u.sam3x.fld.imr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P3");
    state->u.sam3x.fld.imr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P4");
    state->u.sam3x.fld.imr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P5");
    state->u.sam3x.fld.imr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P6");
    state->u.sam3x.fld.imr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P7");
    state->u.sam3x.fld.imr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P8");
    state->u.sam3x.fld.imr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P9");
    state->u.sam3x.fld.imr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P10");
    state->u.sam3x.fld.imr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P11");
    state->u.sam3x.fld.imr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P12");
    state->u.sam3x.fld.imr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P13");
    state->u.sam3x.fld.imr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P14");
    state->u.sam3x.fld.imr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P15");
    state->u.sam3x.fld.imr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P16");
    state->u.sam3x.fld.imr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P17");
    state->u.sam3x.fld.imr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P18");
    state->u.sam3x.fld.imr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P19");
    state->u.sam3x.fld.imr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P20");
    state->u.sam3x.fld.imr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P21");
    state->u.sam3x.fld.imr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P22");
    state->u.sam3x.fld.imr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P23");
    state->u.sam3x.fld.imr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P24");
    state->u.sam3x.fld.imr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P25");
    state->u.sam3x.fld.imr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P26");
    state->u.sam3x.fld.imr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P27");
    state->u.sam3x.fld.imr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P28");
    state->u.sam3x.fld.imr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P29");
    state->u.sam3x.fld.imr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P30");
    state->u.sam3x.fld.imr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.imr, "P31");

    // ISR bitfields.
    state->u.sam3x.fld.isr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P0");
    state->u.sam3x.fld.isr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P1");
    state->u.sam3x.fld.isr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P2");
    state->u.sam3x.fld.isr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P3");
    state->u.sam3x.fld.isr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P4");
    state->u.sam3x.fld.isr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P5");
    state->u.sam3x.fld.isr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P6");
    state->u.sam3x.fld.isr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P7");
    state->u.sam3x.fld.isr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P8");
    state->u.sam3x.fld.isr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P9");
    state->u.sam3x.fld.isr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P10");
    state->u.sam3x.fld.isr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P11");
    state->u.sam3x.fld.isr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P12");
    state->u.sam3x.fld.isr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P13");
    state->u.sam3x.fld.isr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P14");
    state->u.sam3x.fld.isr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P15");
    state->u.sam3x.fld.isr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P16");
    state->u.sam3x.fld.isr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P17");
    state->u.sam3x.fld.isr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P18");
    state->u.sam3x.fld.isr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P19");
    state->u.sam3x.fld.isr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P20");
    state->u.sam3x.fld.isr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P21");
    state->u.sam3x.fld.isr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P22");
    state->u.sam3x.fld.isr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P23");
    state->u.sam3x.fld.isr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P24");
    state->u.sam3x.fld.isr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P25");
    state->u.sam3x.fld.isr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P26");
    state->u.sam3x.fld.isr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P27");
    state->u.sam3x.fld.isr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P28");
    state->u.sam3x.fld.isr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P29");
    state->u.sam3x.fld.isr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P30");
    state->u.sam3x.fld.isr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.isr, "P31");

    // MDER bitfields.
    state->u.sam3x.fld.mder.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P0");
    state->u.sam3x.fld.mder.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P1");
    state->u.sam3x.fld.mder.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P2");
    state->u.sam3x.fld.mder.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P3");
    state->u.sam3x.fld.mder.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P4");
    state->u.sam3x.fld.mder.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P5");
    state->u.sam3x.fld.mder.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P6");
    state->u.sam3x.fld.mder.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P7");
    state->u.sam3x.fld.mder.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P8");
    state->u.sam3x.fld.mder.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P9");
    state->u.sam3x.fld.mder.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P10");
    state->u.sam3x.fld.mder.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P11");
    state->u.sam3x.fld.mder.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P12");
    state->u.sam3x.fld.mder.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P13");
    state->u.sam3x.fld.mder.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P14");
    state->u.sam3x.fld.mder.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P15");
    state->u.sam3x.fld.mder.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P16");
    state->u.sam3x.fld.mder.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P17");
    state->u.sam3x.fld.mder.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P18");
    state->u.sam3x.fld.mder.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P19");
    state->u.sam3x.fld.mder.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P20");
    state->u.sam3x.fld.mder.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P21");
    state->u.sam3x.fld.mder.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P22");
    state->u.sam3x.fld.mder.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P23");
    state->u.sam3x.fld.mder.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P24");
    state->u.sam3x.fld.mder.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P25");
    state->u.sam3x.fld.mder.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P26");
    state->u.sam3x.fld.mder.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P27");
    state->u.sam3x.fld.mder.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P28");
    state->u.sam3x.fld.mder.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P29");
    state->u.sam3x.fld.mder.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P30");
    state->u.sam3x.fld.mder.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.mder, "P31");

    // MDDR bitfields.
    state->u.sam3x.fld.mddr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P0");
    state->u.sam3x.fld.mddr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P1");
    state->u.sam3x.fld.mddr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P2");
    state->u.sam3x.fld.mddr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P3");
    state->u.sam3x.fld.mddr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P4");
    state->u.sam3x.fld.mddr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P5");
    state->u.sam3x.fld.mddr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P6");
    state->u.sam3x.fld.mddr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P7");
    state->u.sam3x.fld.mddr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P8");
    state->u.sam3x.fld.mddr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P9");
    state->u.sam3x.fld.mddr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P10");
    state->u.sam3x.fld.mddr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P11");
    state->u.sam3x.fld.mddr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P12");
    state->u.sam3x.fld.mddr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P13");
    state->u.sam3x.fld.mddr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P14");
    state->u.sam3x.fld.mddr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P15");
    state->u.sam3x.fld.mddr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P16");
    state->u.sam3x.fld.mddr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P17");
    state->u.sam3x.fld.mddr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P18");
    state->u.sam3x.fld.mddr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P19");
    state->u.sam3x.fld.mddr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P20");
    state->u.sam3x.fld.mddr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P21");
    state->u.sam3x.fld.mddr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P22");
    state->u.sam3x.fld.mddr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P23");
    state->u.sam3x.fld.mddr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P24");
    state->u.sam3x.fld.mddr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P25");
    state->u.sam3x.fld.mddr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P26");
    state->u.sam3x.fld.mddr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P27");
    state->u.sam3x.fld.mddr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P28");
    state->u.sam3x.fld.mddr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P29");
    state->u.sam3x.fld.mddr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P30");
    state->u.sam3x.fld.mddr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.mddr, "P31");

    // MDSR bitfields.
    state->u.sam3x.fld.mdsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P0");
    state->u.sam3x.fld.mdsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P1");
    state->u.sam3x.fld.mdsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P2");
    state->u.sam3x.fld.mdsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P3");
    state->u.sam3x.fld.mdsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P4");
    state->u.sam3x.fld.mdsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P5");
    state->u.sam3x.fld.mdsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P6");
    state->u.sam3x.fld.mdsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P7");
    state->u.sam3x.fld.mdsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P8");
    state->u.sam3x.fld.mdsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P9");
    state->u.sam3x.fld.mdsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P10");
    state->u.sam3x.fld.mdsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P11");
    state->u.sam3x.fld.mdsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P12");
    state->u.sam3x.fld.mdsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P13");
    state->u.sam3x.fld.mdsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P14");
    state->u.sam3x.fld.mdsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P15");
    state->u.sam3x.fld.mdsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P16");
    state->u.sam3x.fld.mdsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P17");
    state->u.sam3x.fld.mdsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P18");
    state->u.sam3x.fld.mdsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P19");
    state->u.sam3x.fld.mdsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P20");
    state->u.sam3x.fld.mdsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P21");
    state->u.sam3x.fld.mdsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P22");
    state->u.sam3x.fld.mdsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P23");
    state->u.sam3x.fld.mdsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P24");
    state->u.sam3x.fld.mdsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P25");
    state->u.sam3x.fld.mdsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P26");
    state->u.sam3x.fld.mdsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P27");
    state->u.sam3x.fld.mdsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P28");
    state->u.sam3x.fld.mdsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P29");
    state->u.sam3x.fld.mdsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P30");
    state->u.sam3x.fld.mdsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.mdsr, "P31");

    // PUDR bitfields.
    state->u.sam3x.fld.pudr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P0");
    state->u.sam3x.fld.pudr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P1");
    state->u.sam3x.fld.pudr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P2");
    state->u.sam3x.fld.pudr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P3");
    state->u.sam3x.fld.pudr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P4");
    state->u.sam3x.fld.pudr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P5");
    state->u.sam3x.fld.pudr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P6");
    state->u.sam3x.fld.pudr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P7");
    state->u.sam3x.fld.pudr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P8");
    state->u.sam3x.fld.pudr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P9");
    state->u.sam3x.fld.pudr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P10");
    state->u.sam3x.fld.pudr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P11");
    state->u.sam3x.fld.pudr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P12");
    state->u.sam3x.fld.pudr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P13");
    state->u.sam3x.fld.pudr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P14");
    state->u.sam3x.fld.pudr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P15");
    state->u.sam3x.fld.pudr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P16");
    state->u.sam3x.fld.pudr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P17");
    state->u.sam3x.fld.pudr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P18");
    state->u.sam3x.fld.pudr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P19");
    state->u.sam3x.fld.pudr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P20");
    state->u.sam3x.fld.pudr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P21");
    state->u.sam3x.fld.pudr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P22");
    state->u.sam3x.fld.pudr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P23");
    state->u.sam3x.fld.pudr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P24");
    state->u.sam3x.fld.pudr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P25");
    state->u.sam3x.fld.pudr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P26");
    state->u.sam3x.fld.pudr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P27");
    state->u.sam3x.fld.pudr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P28");
    state->u.sam3x.fld.pudr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P29");
    state->u.sam3x.fld.pudr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P30");
    state->u.sam3x.fld.pudr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.pudr, "P31");

    // PUER bitfields.
    state->u.sam3x.fld.puer.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P0");
    state->u.sam3x.fld.puer.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P1");
    state->u.sam3x.fld.puer.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P2");
    state->u.sam3x.fld.puer.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P3");
    state->u.sam3x.fld.puer.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P4");
    state->u.sam3x.fld.puer.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P5");
    state->u.sam3x.fld.puer.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P6");
    state->u.sam3x.fld.puer.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P7");
    state->u.sam3x.fld.puer.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P8");
    state->u.sam3x.fld.puer.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P9");
    state->u.sam3x.fld.puer.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P10");
    state->u.sam3x.fld.puer.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P11");
    state->u.sam3x.fld.puer.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P12");
    state->u.sam3x.fld.puer.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P13");
    state->u.sam3x.fld.puer.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P14");
    state->u.sam3x.fld.puer.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P15");
    state->u.sam3x.fld.puer.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P16");
    state->u.sam3x.fld.puer.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P17");
    state->u.sam3x.fld.puer.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P18");
    state->u.sam3x.fld.puer.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P19");
    state->u.sam3x.fld.puer.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P20");
    state->u.sam3x.fld.puer.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P21");
    state->u.sam3x.fld.puer.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P22");
    state->u.sam3x.fld.puer.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P23");
    state->u.sam3x.fld.puer.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P24");
    state->u.sam3x.fld.puer.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P25");
    state->u.sam3x.fld.puer.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P26");
    state->u.sam3x.fld.puer.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P27");
    state->u.sam3x.fld.puer.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P28");
    state->u.sam3x.fld.puer.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P29");
    state->u.sam3x.fld.puer.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P30");
    state->u.sam3x.fld.puer.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.puer, "P31");

    // PUSR bitfields.
    state->u.sam3x.fld.pusr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P0");
    state->u.sam3x.fld.pusr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P1");
    state->u.sam3x.fld.pusr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P2");
    state->u.sam3x.fld.pusr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P3");
    state->u.sam3x.fld.pusr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P4");
    state->u.sam3x.fld.pusr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P5");
    state->u.sam3x.fld.pusr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P6");
    state->u.sam3x.fld.pusr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P7");
    state->u.sam3x.fld.pusr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P8");
    state->u.sam3x.fld.pusr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P9");
    state->u.sam3x.fld.pusr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P10");
    state->u.sam3x.fld.pusr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P11");
    state->u.sam3x.fld.pusr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P12");
    state->u.sam3x.fld.pusr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P13");
    state->u.sam3x.fld.pusr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P14");
    state->u.sam3x.fld.pusr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P15");
    state->u.sam3x.fld.pusr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P16");
    state->u.sam3x.fld.pusr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P17");
    state->u.sam3x.fld.pusr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P18");
    state->u.sam3x.fld.pusr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P19");
    state->u.sam3x.fld.pusr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P20");
    state->u.sam3x.fld.pusr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P21");
    state->u.sam3x.fld.pusr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P22");
    state->u.sam3x.fld.pusr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P23");
    state->u.sam3x.fld.pusr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P24");
    state->u.sam3x.fld.pusr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P25");
    state->u.sam3x.fld.pusr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P26");
    state->u.sam3x.fld.pusr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P27");
    state->u.sam3x.fld.pusr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P28");
    state->u.sam3x.fld.pusr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P29");
    state->u.sam3x.fld.pusr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P30");
    state->u.sam3x.fld.pusr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.pusr, "P31");

    // ABSR bitfields.
    state->u.sam3x.fld.absr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P0");
    state->u.sam3x.fld.absr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P1");
    state->u.sam3x.fld.absr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P2");
    state->u.sam3x.fld.absr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P3");
    state->u.sam3x.fld.absr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P4");
    state->u.sam3x.fld.absr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P5");
    state->u.sam3x.fld.absr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P6");
    state->u.sam3x.fld.absr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P7");
    state->u.sam3x.fld.absr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P8");
    state->u.sam3x.fld.absr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P9");
    state->u.sam3x.fld.absr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P10");
    state->u.sam3x.fld.absr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P11");
    state->u.sam3x.fld.absr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P12");
    state->u.sam3x.fld.absr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P13");
    state->u.sam3x.fld.absr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P14");
    state->u.sam3x.fld.absr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P15");
    state->u.sam3x.fld.absr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P16");
    state->u.sam3x.fld.absr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P17");
    state->u.sam3x.fld.absr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P18");
    state->u.sam3x.fld.absr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P19");
    state->u.sam3x.fld.absr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P20");
    state->u.sam3x.fld.absr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P21");
    state->u.sam3x.fld.absr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P22");
    state->u.sam3x.fld.absr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P23");
    state->u.sam3x.fld.absr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P24");
    state->u.sam3x.fld.absr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P25");
    state->u.sam3x.fld.absr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P26");
    state->u.sam3x.fld.absr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P27");
    state->u.sam3x.fld.absr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P28");
    state->u.sam3x.fld.absr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P29");
    state->u.sam3x.fld.absr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P30");
    state->u.sam3x.fld.absr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.absr, "P31");

    // SCIFSR bitfields.
    state->u.sam3x.fld.scifsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P0");
    state->u.sam3x.fld.scifsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P1");
    state->u.sam3x.fld.scifsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P2");
    state->u.sam3x.fld.scifsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P3");
    state->u.sam3x.fld.scifsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P4");
    state->u.sam3x.fld.scifsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P5");
    state->u.sam3x.fld.scifsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P6");
    state->u.sam3x.fld.scifsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P7");
    state->u.sam3x.fld.scifsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P8");
    state->u.sam3x.fld.scifsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P9");
    state->u.sam3x.fld.scifsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P10");
    state->u.sam3x.fld.scifsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P11");
    state->u.sam3x.fld.scifsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P12");
    state->u.sam3x.fld.scifsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P13");
    state->u.sam3x.fld.scifsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P14");
    state->u.sam3x.fld.scifsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P15");
    state->u.sam3x.fld.scifsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P16");
    state->u.sam3x.fld.scifsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P17");
    state->u.sam3x.fld.scifsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P18");
    state->u.sam3x.fld.scifsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P19");
    state->u.sam3x.fld.scifsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P20");
    state->u.sam3x.fld.scifsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P21");
    state->u.sam3x.fld.scifsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P22");
    state->u.sam3x.fld.scifsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P23");
    state->u.sam3x.fld.scifsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P24");
    state->u.sam3x.fld.scifsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P25");
    state->u.sam3x.fld.scifsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P26");
    state->u.sam3x.fld.scifsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P27");
    state->u.sam3x.fld.scifsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P28");
    state->u.sam3x.fld.scifsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P29");
    state->u.sam3x.fld.scifsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P30");
    state->u.sam3x.fld.scifsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.scifsr, "P31");

    // DIFSR bitfields.
    state->u.sam3x.fld.difsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P0");
    state->u.sam3x.fld.difsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P1");
    state->u.sam3x.fld.difsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P2");
    state->u.sam3x.fld.difsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P3");
    state->u.sam3x.fld.difsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P4");
    state->u.sam3x.fld.difsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P5");
    state->u.sam3x.fld.difsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P6");
    state->u.sam3x.fld.difsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P7");
    state->u.sam3x.fld.difsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P8");
    state->u.sam3x.fld.difsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P9");
    state->u.sam3x.fld.difsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P10");
    state->u.sam3x.fld.difsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P11");
    state->u.sam3x.fld.difsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P12");
    state->u.sam3x.fld.difsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P13");
    state->u.sam3x.fld.difsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P14");
    state->u.sam3x.fld.difsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P15");
    state->u.sam3x.fld.difsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P16");
    state->u.sam3x.fld.difsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P17");
    state->u.sam3x.fld.difsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P18");
    state->u.sam3x.fld.difsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P19");
    state->u.sam3x.fld.difsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P20");
    state->u.sam3x.fld.difsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P21");
    state->u.sam3x.fld.difsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P22");
    state->u.sam3x.fld.difsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P23");
    state->u.sam3x.fld.difsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P24");
    state->u.sam3x.fld.difsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P25");
    state->u.sam3x.fld.difsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P26");
    state->u.sam3x.fld.difsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P27");
    state->u.sam3x.fld.difsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P28");
    state->u.sam3x.fld.difsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P29");
    state->u.sam3x.fld.difsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P30");
    state->u.sam3x.fld.difsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.difsr, "P31");

    // IFDGSR bitfields.
    state->u.sam3x.fld.ifdgsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P0");
    state->u.sam3x.fld.ifdgsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P1");
    state->u.sam3x.fld.ifdgsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P2");
    state->u.sam3x.fld.ifdgsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P3");
    state->u.sam3x.fld.ifdgsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P4");
    state->u.sam3x.fld.ifdgsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P5");
    state->u.sam3x.fld.ifdgsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P6");
    state->u.sam3x.fld.ifdgsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P7");
    state->u.sam3x.fld.ifdgsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P8");
    state->u.sam3x.fld.ifdgsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P9");
    state->u.sam3x.fld.ifdgsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P10");
    state->u.sam3x.fld.ifdgsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P11");
    state->u.sam3x.fld.ifdgsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P12");
    state->u.sam3x.fld.ifdgsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P13");
    state->u.sam3x.fld.ifdgsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P14");
    state->u.sam3x.fld.ifdgsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P15");
    state->u.sam3x.fld.ifdgsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P16");
    state->u.sam3x.fld.ifdgsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P17");
    state->u.sam3x.fld.ifdgsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P18");
    state->u.sam3x.fld.ifdgsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P19");
    state->u.sam3x.fld.ifdgsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P20");
    state->u.sam3x.fld.ifdgsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P21");
    state->u.sam3x.fld.ifdgsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P22");
    state->u.sam3x.fld.ifdgsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P23");
    state->u.sam3x.fld.ifdgsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P24");
    state->u.sam3x.fld.ifdgsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P25");
    state->u.sam3x.fld.ifdgsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P26");
    state->u.sam3x.fld.ifdgsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P27");
    state->u.sam3x.fld.ifdgsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P28");
    state->u.sam3x.fld.ifdgsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P29");
    state->u.sam3x.fld.ifdgsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P30");
    state->u.sam3x.fld.ifdgsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.ifdgsr, "P31");

    // SCDR bitfields.
    state->u.sam3x.fld.scdr.div = cm_object_get_child_by_name(state->u.sam3x.reg.scdr, "DIV");

    // OWER bitfields.
    state->u.sam3x.fld.ower.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P0");
    state->u.sam3x.fld.ower.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P1");
    state->u.sam3x.fld.ower.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P2");
    state->u.sam3x.fld.ower.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P3");
    state->u.sam3x.fld.ower.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P4");
    state->u.sam3x.fld.ower.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P5");
    state->u.sam3x.fld.ower.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P6");
    state->u.sam3x.fld.ower.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P7");
    state->u.sam3x.fld.ower.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P8");
    state->u.sam3x.fld.ower.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P9");
    state->u.sam3x.fld.ower.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P10");
    state->u.sam3x.fld.ower.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P11");
    state->u.sam3x.fld.ower.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P12");
    state->u.sam3x.fld.ower.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P13");
    state->u.sam3x.fld.ower.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P14");
    state->u.sam3x.fld.ower.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P15");
    state->u.sam3x.fld.ower.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P16");
    state->u.sam3x.fld.ower.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P17");
    state->u.sam3x.fld.ower.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P18");
    state->u.sam3x.fld.ower.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P19");
    state->u.sam3x.fld.ower.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P20");
    state->u.sam3x.fld.ower.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P21");
    state->u.sam3x.fld.ower.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P22");
    state->u.sam3x.fld.ower.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P23");
    state->u.sam3x.fld.ower.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P24");
    state->u.sam3x.fld.ower.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P25");
    state->u.sam3x.fld.ower.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P26");
    state->u.sam3x.fld.ower.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P27");
    state->u.sam3x.fld.ower.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P28");
    state->u.sam3x.fld.ower.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P29");
    state->u.sam3x.fld.ower.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P30");
    state->u.sam3x.fld.ower.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.ower, "P31");

    // OWDR bitfields.
    state->u.sam3x.fld.owdr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P0");
    state->u.sam3x.fld.owdr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P1");
    state->u.sam3x.fld.owdr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P2");
    state->u.sam3x.fld.owdr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P3");
    state->u.sam3x.fld.owdr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P4");
    state->u.sam3x.fld.owdr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P5");
    state->u.sam3x.fld.owdr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P6");
    state->u.sam3x.fld.owdr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P7");
    state->u.sam3x.fld.owdr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P8");
    state->u.sam3x.fld.owdr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P9");
    state->u.sam3x.fld.owdr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P10");
    state->u.sam3x.fld.owdr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P11");
    state->u.sam3x.fld.owdr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P12");
    state->u.sam3x.fld.owdr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P13");
    state->u.sam3x.fld.owdr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P14");
    state->u.sam3x.fld.owdr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P15");
    state->u.sam3x.fld.owdr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P16");
    state->u.sam3x.fld.owdr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P17");
    state->u.sam3x.fld.owdr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P18");
    state->u.sam3x.fld.owdr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P19");
    state->u.sam3x.fld.owdr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P20");
    state->u.sam3x.fld.owdr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P21");
    state->u.sam3x.fld.owdr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P22");
    state->u.sam3x.fld.owdr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P23");
    state->u.sam3x.fld.owdr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P24");
    state->u.sam3x.fld.owdr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P25");
    state->u.sam3x.fld.owdr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P26");
    state->u.sam3x.fld.owdr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P27");
    state->u.sam3x.fld.owdr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P28");
    state->u.sam3x.fld.owdr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P29");
    state->u.sam3x.fld.owdr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P30");
    state->u.sam3x.fld.owdr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.owdr, "P31");

    // OWSR bitfields.
    state->u.sam3x.fld.owsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P0");
    state->u.sam3x.fld.owsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P1");
    state->u.sam3x.fld.owsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P2");
    state->u.sam3x.fld.owsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P3");
    state->u.sam3x.fld.owsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P4");
    state->u.sam3x.fld.owsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P5");
    state->u.sam3x.fld.owsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P6");
    state->u.sam3x.fld.owsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P7");
    state->u.sam3x.fld.owsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P8");
    state->u.sam3x.fld.owsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P9");
    state->u.sam3x.fld.owsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P10");
    state->u.sam3x.fld.owsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P11");
    state->u.sam3x.fld.owsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P12");
    state->u.sam3x.fld.owsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P13");
    state->u.sam3x.fld.owsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P14");
    state->u.sam3x.fld.owsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P15");
    state->u.sam3x.fld.owsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P16");
    state->u.sam3x.fld.owsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P17");
    state->u.sam3x.fld.owsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P18");
    state->u.sam3x.fld.owsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P19");
    state->u.sam3x.fld.owsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P20");
    state->u.sam3x.fld.owsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P21");
    state->u.sam3x.fld.owsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P22");
    state->u.sam3x.fld.owsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P23");
    state->u.sam3x.fld.owsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P24");
    state->u.sam3x.fld.owsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P25");
    state->u.sam3x.fld.owsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P26");
    state->u.sam3x.fld.owsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P27");
    state->u.sam3x.fld.owsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P28");
    state->u.sam3x.fld.owsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P29");
    state->u.sam3x.fld.owsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P30");
    state->u.sam3x.fld.owsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.owsr, "P31");

    // AIMER bitfields.
    state->u.sam3x.fld.aimer.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P0");
    state->u.sam3x.fld.aimer.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P1");
    state->u.sam3x.fld.aimer.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P2");
    state->u.sam3x.fld.aimer.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P3");
    state->u.sam3x.fld.aimer.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P4");
    state->u.sam3x.fld.aimer.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P5");
    state->u.sam3x.fld.aimer.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P6");
    state->u.sam3x.fld.aimer.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P7");
    state->u.sam3x.fld.aimer.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P8");
    state->u.sam3x.fld.aimer.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P9");
    state->u.sam3x.fld.aimer.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P10");
    state->u.sam3x.fld.aimer.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P11");
    state->u.sam3x.fld.aimer.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P12");
    state->u.sam3x.fld.aimer.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P13");
    state->u.sam3x.fld.aimer.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P14");
    state->u.sam3x.fld.aimer.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P15");
    state->u.sam3x.fld.aimer.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P16");
    state->u.sam3x.fld.aimer.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P17");
    state->u.sam3x.fld.aimer.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P18");
    state->u.sam3x.fld.aimer.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P19");
    state->u.sam3x.fld.aimer.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P20");
    state->u.sam3x.fld.aimer.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P21");
    state->u.sam3x.fld.aimer.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P22");
    state->u.sam3x.fld.aimer.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P23");
    state->u.sam3x.fld.aimer.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P24");
    state->u.sam3x.fld.aimer.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P25");
    state->u.sam3x.fld.aimer.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P26");
    state->u.sam3x.fld.aimer.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P27");
    state->u.sam3x.fld.aimer.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P28");
    state->u.sam3x.fld.aimer.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P29");
    state->u.sam3x.fld.aimer.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P30");
    state->u.sam3x.fld.aimer.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.aimer, "P31");

    // AIMDR bitfields.
    state->u.sam3x.fld.aimdr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P0");
    state->u.sam3x.fld.aimdr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P1");
    state->u.sam3x.fld.aimdr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P2");
    state->u.sam3x.fld.aimdr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P3");
    state->u.sam3x.fld.aimdr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P4");
    state->u.sam3x.fld.aimdr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P5");
    state->u.sam3x.fld.aimdr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P6");
    state->u.sam3x.fld.aimdr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P7");
    state->u.sam3x.fld.aimdr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P8");
    state->u.sam3x.fld.aimdr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P9");
    state->u.sam3x.fld.aimdr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P10");
    state->u.sam3x.fld.aimdr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P11");
    state->u.sam3x.fld.aimdr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P12");
    state->u.sam3x.fld.aimdr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P13");
    state->u.sam3x.fld.aimdr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P14");
    state->u.sam3x.fld.aimdr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P15");
    state->u.sam3x.fld.aimdr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P16");
    state->u.sam3x.fld.aimdr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P17");
    state->u.sam3x.fld.aimdr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P18");
    state->u.sam3x.fld.aimdr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P19");
    state->u.sam3x.fld.aimdr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P20");
    state->u.sam3x.fld.aimdr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P21");
    state->u.sam3x.fld.aimdr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P22");
    state->u.sam3x.fld.aimdr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P23");
    state->u.sam3x.fld.aimdr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P24");
    state->u.sam3x.fld.aimdr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P25");
    state->u.sam3x.fld.aimdr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P26");
    state->u.sam3x.fld.aimdr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P27");
    state->u.sam3x.fld.aimdr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P28");
    state->u.sam3x.fld.aimdr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P29");
    state->u.sam3x.fld.aimdr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P30");
    state->u.sam3x.fld.aimdr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.aimdr, "P31");

    // AIMMR bitfields.
    state->u.sam3x.fld.aimmr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P0");
    state->u.sam3x.fld.aimmr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P1");
    state->u.sam3x.fld.aimmr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P2");
    state->u.sam3x.fld.aimmr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P3");
    state->u.sam3x.fld.aimmr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P4");
    state->u.sam3x.fld.aimmr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P5");
    state->u.sam3x.fld.aimmr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P6");
    state->u.sam3x.fld.aimmr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P7");
    state->u.sam3x.fld.aimmr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P8");
    state->u.sam3x.fld.aimmr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P9");
    state->u.sam3x.fld.aimmr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P10");
    state->u.sam3x.fld.aimmr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P11");
    state->u.sam3x.fld.aimmr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P12");
    state->u.sam3x.fld.aimmr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P13");
    state->u.sam3x.fld.aimmr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P14");
    state->u.sam3x.fld.aimmr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P15");
    state->u.sam3x.fld.aimmr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P16");
    state->u.sam3x.fld.aimmr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P17");
    state->u.sam3x.fld.aimmr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P18");
    state->u.sam3x.fld.aimmr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P19");
    state->u.sam3x.fld.aimmr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P20");
    state->u.sam3x.fld.aimmr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P21");
    state->u.sam3x.fld.aimmr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P22");
    state->u.sam3x.fld.aimmr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P23");
    state->u.sam3x.fld.aimmr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P24");
    state->u.sam3x.fld.aimmr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P25");
    state->u.sam3x.fld.aimmr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P26");
    state->u.sam3x.fld.aimmr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P27");
    state->u.sam3x.fld.aimmr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P28");
    state->u.sam3x.fld.aimmr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P29");
    state->u.sam3x.fld.aimmr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P30");
    state->u.sam3x.fld.aimmr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.aimmr, "P31");

    // ESR bitfields.
    state->u.sam3x.fld.esr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P0");
    state->u.sam3x.fld.esr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P1");
    state->u.sam3x.fld.esr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P2");
    state->u.sam3x.fld.esr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P3");
    state->u.sam3x.fld.esr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P4");
    state->u.sam3x.fld.esr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P5");
    state->u.sam3x.fld.esr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P6");
    state->u.sam3x.fld.esr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P7");
    state->u.sam3x.fld.esr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P8");
    state->u.sam3x.fld.esr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P9");
    state->u.sam3x.fld.esr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P10");
    state->u.sam3x.fld.esr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P11");
    state->u.sam3x.fld.esr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P12");
    state->u.sam3x.fld.esr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P13");
    state->u.sam3x.fld.esr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P14");
    state->u.sam3x.fld.esr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P15");
    state->u.sam3x.fld.esr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P16");
    state->u.sam3x.fld.esr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P17");
    state->u.sam3x.fld.esr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P18");
    state->u.sam3x.fld.esr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P19");
    state->u.sam3x.fld.esr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P20");
    state->u.sam3x.fld.esr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P21");
    state->u.sam3x.fld.esr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P22");
    state->u.sam3x.fld.esr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P23");
    state->u.sam3x.fld.esr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P24");
    state->u.sam3x.fld.esr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P25");
    state->u.sam3x.fld.esr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P26");
    state->u.sam3x.fld.esr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P27");
    state->u.sam3x.fld.esr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P28");
    state->u.sam3x.fld.esr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P29");
    state->u.sam3x.fld.esr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P30");
    state->u.sam3x.fld.esr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.esr, "P31");

    // LSR bitfields.
    state->u.sam3x.fld.lsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P0");
    state->u.sam3x.fld.lsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P1");
    state->u.sam3x.fld.lsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P2");
    state->u.sam3x.fld.lsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P3");
    state->u.sam3x.fld.lsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P4");
    state->u.sam3x.fld.lsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P5");
    state->u.sam3x.fld.lsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P6");
    state->u.sam3x.fld.lsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P7");
    state->u.sam3x.fld.lsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P8");
    state->u.sam3x.fld.lsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P9");
    state->u.sam3x.fld.lsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P10");
    state->u.sam3x.fld.lsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P11");
    state->u.sam3x.fld.lsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P12");
    state->u.sam3x.fld.lsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P13");
    state->u.sam3x.fld.lsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P14");
    state->u.sam3x.fld.lsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P15");
    state->u.sam3x.fld.lsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P16");
    state->u.sam3x.fld.lsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P17");
    state->u.sam3x.fld.lsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P18");
    state->u.sam3x.fld.lsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P19");
    state->u.sam3x.fld.lsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P20");
    state->u.sam3x.fld.lsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P21");
    state->u.sam3x.fld.lsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P22");
    state->u.sam3x.fld.lsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P23");
    state->u.sam3x.fld.lsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P24");
    state->u.sam3x.fld.lsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P25");
    state->u.sam3x.fld.lsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P26");
    state->u.sam3x.fld.lsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P27");
    state->u.sam3x.fld.lsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P28");
    state->u.sam3x.fld.lsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P29");
    state->u.sam3x.fld.lsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P30");
    state->u.sam3x.fld.lsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.lsr, "P31");

    // ELSR bitfields.
    state->u.sam3x.fld.elsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P0");
    state->u.sam3x.fld.elsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P1");
    state->u.sam3x.fld.elsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P2");
    state->u.sam3x.fld.elsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P3");
    state->u.sam3x.fld.elsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P4");
    state->u.sam3x.fld.elsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P5");
    state->u.sam3x.fld.elsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P6");
    state->u.sam3x.fld.elsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P7");
    state->u.sam3x.fld.elsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P8");
    state->u.sam3x.fld.elsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P9");
    state->u.sam3x.fld.elsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P10");
    state->u.sam3x.fld.elsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P11");
    state->u.sam3x.fld.elsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P12");
    state->u.sam3x.fld.elsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P13");
    state->u.sam3x.fld.elsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P14");
    state->u.sam3x.fld.elsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P15");
    state->u.sam3x.fld.elsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P16");
    state->u.sam3x.fld.elsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P17");
    state->u.sam3x.fld.elsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P18");
    state->u.sam3x.fld.elsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P19");
    state->u.sam3x.fld.elsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P20");
    state->u.sam3x.fld.elsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P21");
    state->u.sam3x.fld.elsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P22");
    state->u.sam3x.fld.elsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P23");
    state->u.sam3x.fld.elsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P24");
    state->u.sam3x.fld.elsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P25");
    state->u.sam3x.fld.elsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P26");
    state->u.sam3x.fld.elsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P27");
    state->u.sam3x.fld.elsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P28");
    state->u.sam3x.fld.elsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P29");
    state->u.sam3x.fld.elsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P30");
    state->u.sam3x.fld.elsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.elsr, "P31");

    // FELLSR bitfields.
    state->u.sam3x.fld.fellsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P0");
    state->u.sam3x.fld.fellsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P1");
    state->u.sam3x.fld.fellsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P2");
    state->u.sam3x.fld.fellsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P3");
    state->u.sam3x.fld.fellsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P4");
    state->u.sam3x.fld.fellsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P5");
    state->u.sam3x.fld.fellsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P6");
    state->u.sam3x.fld.fellsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P7");
    state->u.sam3x.fld.fellsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P8");
    state->u.sam3x.fld.fellsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P9");
    state->u.sam3x.fld.fellsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P10");
    state->u.sam3x.fld.fellsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P11");
    state->u.sam3x.fld.fellsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P12");
    state->u.sam3x.fld.fellsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P13");
    state->u.sam3x.fld.fellsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P14");
    state->u.sam3x.fld.fellsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P15");
    state->u.sam3x.fld.fellsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P16");
    state->u.sam3x.fld.fellsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P17");
    state->u.sam3x.fld.fellsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P18");
    state->u.sam3x.fld.fellsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P19");
    state->u.sam3x.fld.fellsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P20");
    state->u.sam3x.fld.fellsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P21");
    state->u.sam3x.fld.fellsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P22");
    state->u.sam3x.fld.fellsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P23");
    state->u.sam3x.fld.fellsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P24");
    state->u.sam3x.fld.fellsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P25");
    state->u.sam3x.fld.fellsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P26");
    state->u.sam3x.fld.fellsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P27");
    state->u.sam3x.fld.fellsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P28");
    state->u.sam3x.fld.fellsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P29");
    state->u.sam3x.fld.fellsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P30");
    state->u.sam3x.fld.fellsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.fellsr, "P31");

    // REHLSR bitfields.
    state->u.sam3x.fld.rehlsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P0");
    state->u.sam3x.fld.rehlsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P1");
    state->u.sam3x.fld.rehlsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P2");
    state->u.sam3x.fld.rehlsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P3");
    state->u.sam3x.fld.rehlsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P4");
    state->u.sam3x.fld.rehlsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P5");
    state->u.sam3x.fld.rehlsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P6");
    state->u.sam3x.fld.rehlsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P7");
    state->u.sam3x.fld.rehlsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P8");
    state->u.sam3x.fld.rehlsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P9");
    state->u.sam3x.fld.rehlsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P10");
    state->u.sam3x.fld.rehlsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P11");
    state->u.sam3x.fld.rehlsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P12");
    state->u.sam3x.fld.rehlsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P13");
    state->u.sam3x.fld.rehlsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P14");
    state->u.sam3x.fld.rehlsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P15");
    state->u.sam3x.fld.rehlsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P16");
    state->u.sam3x.fld.rehlsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P17");
    state->u.sam3x.fld.rehlsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P18");
    state->u.sam3x.fld.rehlsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P19");
    state->u.sam3x.fld.rehlsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P20");
    state->u.sam3x.fld.rehlsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P21");
    state->u.sam3x.fld.rehlsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P22");
    state->u.sam3x.fld.rehlsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P23");
    state->u.sam3x.fld.rehlsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P24");
    state->u.sam3x.fld.rehlsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P25");
    state->u.sam3x.fld.rehlsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P26");
    state->u.sam3x.fld.rehlsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P27");
    state->u.sam3x.fld.rehlsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P28");
    state->u.sam3x.fld.rehlsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P29");
    state->u.sam3x.fld.rehlsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P30");
    state->u.sam3x.fld.rehlsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.rehlsr, "P31");

    // FRLHSR bitfields.
    state->u.sam3x.fld.frlhsr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P0");
    state->u.sam3x.fld.frlhsr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P1");
    state->u.sam3x.fld.frlhsr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P2");
    state->u.sam3x.fld.frlhsr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P3");
    state->u.sam3x.fld.frlhsr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P4");
    state->u.sam3x.fld.frlhsr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P5");
    state->u.sam3x.fld.frlhsr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P6");
    state->u.sam3x.fld.frlhsr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P7");
    state->u.sam3x.fld.frlhsr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P8");
    state->u.sam3x.fld.frlhsr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P9");
    state->u.sam3x.fld.frlhsr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P10");
    state->u.sam3x.fld.frlhsr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P11");
    state->u.sam3x.fld.frlhsr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P12");
    state->u.sam3x.fld.frlhsr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P13");
    state->u.sam3x.fld.frlhsr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P14");
    state->u.sam3x.fld.frlhsr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P15");
    state->u.sam3x.fld.frlhsr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P16");
    state->u.sam3x.fld.frlhsr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P17");
    state->u.sam3x.fld.frlhsr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P18");
    state->u.sam3x.fld.frlhsr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P19");
    state->u.sam3x.fld.frlhsr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P20");
    state->u.sam3x.fld.frlhsr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P21");
    state->u.sam3x.fld.frlhsr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P22");
    state->u.sam3x.fld.frlhsr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P23");
    state->u.sam3x.fld.frlhsr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P24");
    state->u.sam3x.fld.frlhsr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P25");
    state->u.sam3x.fld.frlhsr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P26");
    state->u.sam3x.fld.frlhsr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P27");
    state->u.sam3x.fld.frlhsr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P28");
    state->u.sam3x.fld.frlhsr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P29");
    state->u.sam3x.fld.frlhsr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P30");
    state->u.sam3x.fld.frlhsr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.frlhsr, "P31");

    // LOCKSR bitfields.
    state->u.sam3x.fld.locksr.p0 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P0");
    state->u.sam3x.fld.locksr.p1 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P1");
    state->u.sam3x.fld.locksr.p2 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P2");
    state->u.sam3x.fld.locksr.p3 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P3");
    state->u.sam3x.fld.locksr.p4 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P4");
    state->u.sam3x.fld.locksr.p5 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P5");
    state->u.sam3x.fld.locksr.p6 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P6");
    state->u.sam3x.fld.locksr.p7 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P7");
    state->u.sam3x.fld.locksr.p8 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P8");
    state->u.sam3x.fld.locksr.p9 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P9");
    state->u.sam3x.fld.locksr.p10 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P10");
    state->u.sam3x.fld.locksr.p11 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P11");
    state->u.sam3x.fld.locksr.p12 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P12");
    state->u.sam3x.fld.locksr.p13 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P13");
    state->u.sam3x.fld.locksr.p14 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P14");
    state->u.sam3x.fld.locksr.p15 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P15");
    state->u.sam3x.fld.locksr.p16 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P16");
    state->u.sam3x.fld.locksr.p17 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P17");
    state->u.sam3x.fld.locksr.p18 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P18");
    state->u.sam3x.fld.locksr.p19 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P19");
    state->u.sam3x.fld.locksr.p20 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P20");
    state->u.sam3x.fld.locksr.p21 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P21");
    state->u.sam3x.fld.locksr.p22 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P22");
    state->u.sam3x.fld.locksr.p23 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P23");
    state->u.sam3x.fld.locksr.p24 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P24");
    state->u.sam3x.fld.locksr.p25 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P25");
    state->u.sam3x.fld.locksr.p26 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P26");
    state->u.sam3x.fld.locksr.p27 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P27");
    state->u.sam3x.fld.locksr.p28 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P28");
    state->u.sam3x.fld.locksr.p29 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P29");
    state->u.sam3x.fld.locksr.p30 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P30");
    state->u.sam3x.fld.locksr.p31 = cm_object_get_child_by_name(state->u.sam3x.reg.locksr, "P31");

    // WPMR bitfields.
    state->u.sam3x.fld.wpmr.wpen = cm_object_get_child_by_name(state->u.sam3x.reg.wpmr, "WPEN");
    state->u.sam3x.fld.wpmr.wpkey = cm_object_get_child_by_name(state->u.sam3x.reg.wpmr, "WPKEY");

    // WPSR bitfields.
    state->u.sam3x.fld.wpsr.wpvs = cm_object_get_child_by_name(state->u.sam3x.reg.wpsr, "WPVS");
    state->u.sam3x.fld.wpsr.wpvsrc = cm_object_get_child_by_name(state->u.sam3x.reg.wpsr, "WPVSRC");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Public ---------------------------------------------------------------

// Create PIO%c and return it.

Object* sam_pio_create(Object *parent, sam_pio_index_t index)
{
    if ((int) index >= SAM_PORT_PIO_UNDEFINED) {
        hw_error("Cannot assign PIO%c: QEMU supports only %d ports\n",
                'A' + index, SAM_PORT_PIO_UNDEFINED);
    }

    char child_name[10];
    snprintf(child_name, sizeof(child_name) - 1, "PIO%c",
            'A' + index - SAM_PORT_PIOA);
    // Passing a local string is ok.
    Object *gpio = cm_object_new(parent, child_name, TYPE_SAM_PIO);
    //int i;

    object_property_set_int(gpio, index, "port-index", NULL);

    cm_object_realize(gpio);

    return gpio;
}

// Return a pointer to the PIO%c object, or null if not found.

Object* sam_pio_get(int index)
{
    char gpio_name[40];
    snprintf(gpio_name, sizeof(gpio_name), DEVICE_PATH_SAM "PIO%c",
            'A' + index - SAM_PORT_PIOA);
    return object_resolve_path(gpio_name, NULL);
}

// ----- Private --------------------------------------------------------------

static void sam_pio_update_output(SAMPIOState *state, uint32_t old_value, uint32_t new_value)
{
    // Compute pins that changed value.
    uint32_t changed = old_value ^ new_value;

	char gpio_name[3];
    snprintf(gpio_name, sizeof(gpio_name), "P%c",
            'A' + state->port_index - SAM_PORT_PIOA);

	int pin;
	uint32_t mask = 1;
	for (pin = 0; pin < SAM_PIO_PIN_COUNT; pin++, mask <<= 1) {
        if ((changed & mask) != 0) {
			fprintf(stderr, "%s", gpio_name);
			if( new_value & mask )
				fprintf(stderr, "%d:HIGH\n", pin);
			else
				fprintf(stderr, "%d:LOW\n", pin);
        }
    }
}


static void sam_pio_sodr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    SAMPIOState *state = SAM_PIO_STATE(periph);
	
    uint32_t old_value = peripheral_register_read_value(state->reg.odsr);

	uint32_t set_pins = old_value | full_value;
	peripheral_register_write_value(state->reg.odsr, set_pins);
	 
	sam_pio_update_output(state, old_value, set_pins);
}

static void sam_pio_codr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    SAMPIOState *state = SAM_PIO_STATE(periph);

    uint32_t old_value = peripheral_register_read_value(state->reg.odsr);

	uint32_t clear_pins = old_value & (~full_value);
	peripheral_register_write_value(state->reg.odsr, clear_pins);

	sam_pio_update_output(state, old_value, clear_pins);	 
}


static void sam_pio_oer_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    SAMPIOState *state = SAM_PIO_STATE(periph);
	
	peripheral_register_set_raw_value(state->reg.osr, value);
}

#if 0
static peripheral_register_t sam_pio_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    SAMPIOState *state = SAM_PIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static peripheral_register_t sam_pio_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    SAMPIOState *state = SAM_PIO_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void sam_pio_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    SAMPIOState *state = SAM_PIO_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

static void sam_pio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    SAMPIOState *state = SAM_PIO_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = SAM_PORT_PIO_UNDEFINED;
}

static void sam_pio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_SAM_PIO)) {
        return;
    }

    SAMMCUState *mcu = sam_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    SAMPIOState *state = SAM_PIO_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const SAMCapabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    char periph_name[10];
    snprintf(periph_name, sizeof(periph_name) - 1, "PIO%c",
            'A' + state->port_index);	

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    switch (capabilities->family) {
    case SAM_FAMILY_SAM3X:

        sam3x8e_pio_create_objects(obj, cm_state->svd_json, periph_name);

		state->reg.codr = state->u.sam3x.reg.codr;
		state->reg.sodr = state->u.sam3x.reg.sodr;
		state->reg.psr  = state->u.sam3x.reg.psr;
		state->reg.oer  = state->u.sam3x.reg.oer;
		state->reg.osr  = state->u.sam3x.reg.osr;	
		state->reg.odsr  = state->u.sam3x.reg.odsr;	

        // TODO: add actions.
        // cm_object_property_set_str(state->u.sam3x.fld.xxx.fff, "GGG", "follows");
        // cm_object_property_set_str(state->u.sam3x.fld.xxx.fff, "GGG", "cleared-by");

        // TODO: add callbacks.
        // peripheral_register_set_pre_read(state->sam3x.reg.xxx, &sam_pio_xxx_pre_read_callback);
        // peripheral_register_set_post_read(state->sam3x.reg.xxx, &sam_pio_xxx_post_read_callback);
        // peripheral_register_set_pre_read(state->sam3x.reg.xxx, &sam_pio_xxx_pret_read_callback);
        // peripheral_register_set_post_write(state->sam3x.reg.xxx, &sam_pio_xxx_post_write_callback);
		peripheral_register_set_post_write(state->reg.codr, &sam_pio_codr_post_write_callback);
		peripheral_register_set_post_write(state->reg.sodr, &sam_pio_sodr_post_write_callback);
		peripheral_register_set_post_write(state->reg.oer, &sam_pio_oer_post_write_callback);

        // TODO: add interrupts.

        break;

    default:
        assert(false);
        break;
    }

    peripheral_prepare_registers(obj);
}

static void sam_pio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();
	
    SAMPIOState *state = SAM_PIO_STATE(dev);
	
    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_SAM_PIO);
	
	peripheral_register_set_raw_value(state->reg.psr, 0xFFFFFFFF);
}

static void sam_pio_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = sam_pio_reset_callback;
    dc->realize = sam_pio_realize_callback;
}

static const TypeInfo sam_pio_type_info = {
    .name = TYPE_SAM_PIO,
    .parent = TYPE_SAM_PIO_PARENT,
    .instance_init = sam_pio_instance_init_callback,
    .instance_size = sizeof(SAMPIOState),
    .class_init = sam_pio_class_init_callback,
    .class_size = sizeof(SAMPIOClass) };

static void sam_pio_register_types(void)
{
    type_register_static(&sam_pio_type_info);
}

type_init(sam_pio_register_types);

// ----------------------------------------------------------------------------
