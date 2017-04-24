/*
 * SAM - PIO (Parallel Input/Output Controller) emulation.
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

#ifndef SAM_PIO_H_
#define SAM_PIO_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/sam/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_SAM_PIO_A DEVICE_PATH_SAM "PIOA"
#define DEVICE_PATH_SAM_PIO_B DEVICE_PATH_SAM "PIOB"
#define DEVICE_PATH_SAM_PIO_C DEVICE_PATH_SAM "PIOC"
#define DEVICE_PATH_SAM_PIO_D DEVICE_PATH_SAM "PIOD"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    SAM_PORT_PIOA,
	SAM_PORT_PIOB,
    SAM_PORT_PIOC,
    SAM_PORT_PIOD,
    SAM_PORT_PIO_UNDEFINED = 0xFF,
} sam_pio_index_t;

#define SAM_PIO_PIN_COUNT    (32)

// ----------------------------------------------------------------------------

#define TYPE_SAM_PIO TYPE_SAM_PREFIX "pio" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_SAM_PIO_PARENT TYPE_PERIPHERAL
typedef PeripheralClass SAMPIOParentClass;
typedef PeripheralState SAMPIOParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define SAM_PIO_GET_CLASS(obj) \
    OBJECT_GET_CLASS(SAMPIOClass, (obj), TYPE_SAM_PIO)
#define SAM_PIO_CLASS(klass) \
    OBJECT_CLASS_CHECK(SAMPIOClass, (klass), TYPE_SAM_PIO)

typedef struct {
    // private: 
    SAMPIOParentClass parent_class;
    // public: 

    // None, so far.
} SAMPIOClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define SAM_PIO_STATE(obj) \
    OBJECT_CHECK(SAMPIOState, (obj), TYPE_SAM_PIO)

typedef struct {
    // private:
    SAMPIOParentState parent_obj;
    // public:

    const SAMCapabilities *capabilities;

    sam_pio_index_t port_index;

	 struct { 
       Object *per; // 0x00000000 (PIO Enable Register) 
       Object *pdr; // 0x00000004 (PIO Disable Register) 
       Object *psr; // 0x00000008 (PIO Status Register) 
       Object *oer; // 0x00000010 (Output Enable Register) 
       Object *odr; // 0x00000014 (Output Disable Register) 
       Object *osr; // 0x00000018 (Output Status Register) 
       Object *ifer; // 0x00000020 (Glitch Input Filter Enable Register) 
       Object *ifdr; // 0x00000024 (Glitch Input Filter Disable Register) 
       Object *ifsr; // 0x00000028 (Glitch Input Filter Status Register) 
       Object *sodr; // 0x00000030 (Set Output Data Register) 
       Object *codr; // 0x00000034 (Clear Output Data Register) 
       Object *odsr; // 0x00000038 (Output Data Status Register) 
       Object *pdsr; // 0x0000003C (Pin Data Status Register) 
       Object *ier; // 0x00000040 (Interrupt Enable Register) 
       Object *idr; // 0x00000044 (Interrupt Disable Register) 
       Object *imr; // 0x00000048 (Interrupt Mask Register) 
       Object *isr; // 0x0000004C (Interrupt Status Register) 
       Object *mder; // 0x00000050 (Multi-driver Enable Register) 
       Object *mddr; // 0x00000054 (Multi-driver Disable Register) 
       Object *mdsr; // 0x00000058 (Multi-driver Status Register) 
       Object *pudr; // 0x00000060 (Pull-up Disable Register) 
       Object *puer; // 0x00000064 (Pull-up Enable Register) 
       Object *pusr; // 0x00000068 (Pad Pull-up Status Register) 
       Object *absr; // 0x00000070 (Peripheral AB Select Register) 
       Object *scifsr; // 0x00000080 (System Clock Glitch Input Filter Select Register) 
       Object *difsr; // 0x00000084 (Debouncing Input Filter Select Register) 
       Object *ifdgsr; // 0x00000088 (Glitch or Debouncing Input Filter Clock Selection Status Register) 
       Object *scdr; // 0x0000008C (Slow Clock Divider Debouncing Register) 
       Object *ower; // 0x000000A0 (Output Write Enable) 
       Object *owdr; // 0x000000A4 (Output Write Disable) 
       Object *owsr; // 0x000000A8 (Output Write Status Register) 
       Object *aimer; // 0x000000B0 (Additional Interrupt Modes Enable Register) 
       Object *aimdr; // 0x000000B4 (Additional Interrupt Modes Disables Register) 
       Object *aimmr; // 0x000000B8 (Additional Interrupt Modes Mask Register) 
       Object *esr; // 0x000000C0 (Edge Select Register) 
       Object *lsr; // 0x000000C4 (Level Select Register) 
       Object *elsr; // 0x000000C8 (Edge/Level Status Register) 
       Object *fellsr; // 0x000000D0 (Falling Edge/Low Level Select Register) 
       Object *rehlsr; // 0x000000D4 (Rising Edge/ High Level Select Register) 
       Object *frlhsr; // 0x000000D8 (Fall/Rise - Low/High Status Register) 
       Object *locksr; // 0x000000E0 (Lock Status) 
       Object *wpmr; // 0x000000E4 (Write Protect Mode Register) 
       Object *wpsr; // 0x000000E8 (Write Protect Status Register) 
	 } reg;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // SAM3X PIO (Parallel Input/Output Controller A) registers.
        struct { 
          Object *per; // 0x00000000 (PIO Enable Register) 
          Object *pdr; // 0x00000004 (PIO Disable Register) 
          Object *psr; // 0x00000008 (PIO Status Register) 
          Object *oer; // 0x00000010 (Output Enable Register) 
          Object *odr; // 0x00000014 (Output Disable Register) 
          Object *osr; // 0x00000018 (Output Status Register) 
          Object *ifer; // 0x00000020 (Glitch Input Filter Enable Register) 
          Object *ifdr; // 0x00000024 (Glitch Input Filter Disable Register) 
          Object *ifsr; // 0x00000028 (Glitch Input Filter Status Register) 
          Object *sodr; // 0x00000030 (Set Output Data Register) 
          Object *codr; // 0x00000034 (Clear Output Data Register) 
          Object *odsr; // 0x00000038 (Output Data Status Register) 
          Object *pdsr; // 0x0000003C (Pin Data Status Register) 
          Object *ier; // 0x00000040 (Interrupt Enable Register) 
          Object *idr; // 0x00000044 (Interrupt Disable Register) 
          Object *imr; // 0x00000048 (Interrupt Mask Register) 
          Object *isr; // 0x0000004C (Interrupt Status Register) 
          Object *mder; // 0x00000050 (Multi-driver Enable Register) 
          Object *mddr; // 0x00000054 (Multi-driver Disable Register) 
          Object *mdsr; // 0x00000058 (Multi-driver Status Register) 
          Object *pudr; // 0x00000060 (Pull-up Disable Register) 
          Object *puer; // 0x00000064 (Pull-up Enable Register) 
          Object *pusr; // 0x00000068 (Pad Pull-up Status Register) 
          Object *absr; // 0x00000070 (Peripheral AB Select Register) 
          Object *scifsr; // 0x00000080 (System Clock Glitch Input Filter Select Register) 
          Object *difsr; // 0x00000084 (Debouncing Input Filter Select Register) 
          Object *ifdgsr; // 0x00000088 (Glitch or Debouncing Input Filter Clock Selection Status Register) 
          Object *scdr; // 0x0000008C (Slow Clock Divider Debouncing Register) 
          Object *ower; // 0x000000A0 (Output Write Enable) 
          Object *owdr; // 0x000000A4 (Output Write Disable) 
          Object *owsr; // 0x000000A8 (Output Write Status Register) 
          Object *aimer; // 0x000000B0 (Additional Interrupt Modes Enable Register) 
          Object *aimdr; // 0x000000B4 (Additional Interrupt Modes Disables Register) 
          Object *aimmr; // 0x000000B8 (Additional Interrupt Modes Mask Register) 
          Object *esr; // 0x000000C0 (Edge Select Register) 
          Object *lsr; // 0x000000C4 (Level Select Register) 
          Object *elsr; // 0x000000C8 (Edge/Level Status Register) 
          Object *fellsr; // 0x000000D0 (Falling Edge/Low Level Select Register) 
          Object *rehlsr; // 0x000000D4 (Rising Edge/ High Level Select Register) 
          Object *frlhsr; // 0x000000D8 (Fall/Rise - Low/High Status Register) 
          Object *locksr; // 0x000000E0 (Lock Status) 
          Object *wpmr; // 0x000000E4 (Write Protect Mode Register) 
          Object *wpsr; // 0x000000E8 (Write Protect Status Register) 
        } reg;

        struct { 

          // PER (PIO Enable Register) bitfields.
          struct { 
            Object *p0; // [0:0] PIO Enable
            Object *p1; // [1:1] PIO Enable
            Object *p2; // [2:2] PIO Enable
            Object *p3; // [3:3] PIO Enable
            Object *p4; // [4:4] PIO Enable
            Object *p5; // [5:5] PIO Enable
            Object *p6; // [6:6] PIO Enable
            Object *p7; // [7:7] PIO Enable
            Object *p8; // [8:8] PIO Enable
            Object *p9; // [9:9] PIO Enable
            Object *p10; // [10:10] PIO Enable
            Object *p11; // [11:11] PIO Enable
            Object *p12; // [12:12] PIO Enable
            Object *p13; // [13:13] PIO Enable
            Object *p14; // [14:14] PIO Enable
            Object *p15; // [15:15] PIO Enable
            Object *p16; // [16:16] PIO Enable
            Object *p17; // [17:17] PIO Enable
            Object *p18; // [18:18] PIO Enable
            Object *p19; // [19:19] PIO Enable
            Object *p20; // [20:20] PIO Enable
            Object *p21; // [21:21] PIO Enable
            Object *p22; // [22:22] PIO Enable
            Object *p23; // [23:23] PIO Enable
            Object *p24; // [24:24] PIO Enable
            Object *p25; // [25:25] PIO Enable
            Object *p26; // [26:26] PIO Enable
            Object *p27; // [27:27] PIO Enable
            Object *p28; // [28:28] PIO Enable
            Object *p29; // [29:29] PIO Enable
            Object *p30; // [30:30] PIO Enable
            Object *p31; // [31:31] PIO Enable
          } per; 

          // PDR (PIO Disable Register) bitfields.
          struct { 
            Object *p0; // [0:0] PIO Disable
            Object *p1; // [1:1] PIO Disable
            Object *p2; // [2:2] PIO Disable
            Object *p3; // [3:3] PIO Disable
            Object *p4; // [4:4] PIO Disable
            Object *p5; // [5:5] PIO Disable
            Object *p6; // [6:6] PIO Disable
            Object *p7; // [7:7] PIO Disable
            Object *p8; // [8:8] PIO Disable
            Object *p9; // [9:9] PIO Disable
            Object *p10; // [10:10] PIO Disable
            Object *p11; // [11:11] PIO Disable
            Object *p12; // [12:12] PIO Disable
            Object *p13; // [13:13] PIO Disable
            Object *p14; // [14:14] PIO Disable
            Object *p15; // [15:15] PIO Disable
            Object *p16; // [16:16] PIO Disable
            Object *p17; // [17:17] PIO Disable
            Object *p18; // [18:18] PIO Disable
            Object *p19; // [19:19] PIO Disable
            Object *p20; // [20:20] PIO Disable
            Object *p21; // [21:21] PIO Disable
            Object *p22; // [22:22] PIO Disable
            Object *p23; // [23:23] PIO Disable
            Object *p24; // [24:24] PIO Disable
            Object *p25; // [25:25] PIO Disable
            Object *p26; // [26:26] PIO Disable
            Object *p27; // [27:27] PIO Disable
            Object *p28; // [28:28] PIO Disable
            Object *p29; // [29:29] PIO Disable
            Object *p30; // [30:30] PIO Disable
            Object *p31; // [31:31] PIO Disable
          } pdr; 

          // PSR (PIO Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] PIO Status
            Object *p1; // [1:1] PIO Status
            Object *p2; // [2:2] PIO Status
            Object *p3; // [3:3] PIO Status
            Object *p4; // [4:4] PIO Status
            Object *p5; // [5:5] PIO Status
            Object *p6; // [6:6] PIO Status
            Object *p7; // [7:7] PIO Status
            Object *p8; // [8:8] PIO Status
            Object *p9; // [9:9] PIO Status
            Object *p10; // [10:10] PIO Status
            Object *p11; // [11:11] PIO Status
            Object *p12; // [12:12] PIO Status
            Object *p13; // [13:13] PIO Status
            Object *p14; // [14:14] PIO Status
            Object *p15; // [15:15] PIO Status
            Object *p16; // [16:16] PIO Status
            Object *p17; // [17:17] PIO Status
            Object *p18; // [18:18] PIO Status
            Object *p19; // [19:19] PIO Status
            Object *p20; // [20:20] PIO Status
            Object *p21; // [21:21] PIO Status
            Object *p22; // [22:22] PIO Status
            Object *p23; // [23:23] PIO Status
            Object *p24; // [24:24] PIO Status
            Object *p25; // [25:25] PIO Status
            Object *p26; // [26:26] PIO Status
            Object *p27; // [27:27] PIO Status
            Object *p28; // [28:28] PIO Status
            Object *p29; // [29:29] PIO Status
            Object *p30; // [30:30] PIO Status
            Object *p31; // [31:31] PIO Status
          } psr; 

          // OER (Output Enable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Output Enable
            Object *p1; // [1:1] Output Enable
            Object *p2; // [2:2] Output Enable
            Object *p3; // [3:3] Output Enable
            Object *p4; // [4:4] Output Enable
            Object *p5; // [5:5] Output Enable
            Object *p6; // [6:6] Output Enable
            Object *p7; // [7:7] Output Enable
            Object *p8; // [8:8] Output Enable
            Object *p9; // [9:9] Output Enable
            Object *p10; // [10:10] Output Enable
            Object *p11; // [11:11] Output Enable
            Object *p12; // [12:12] Output Enable
            Object *p13; // [13:13] Output Enable
            Object *p14; // [14:14] Output Enable
            Object *p15; // [15:15] Output Enable
            Object *p16; // [16:16] Output Enable
            Object *p17; // [17:17] Output Enable
            Object *p18; // [18:18] Output Enable
            Object *p19; // [19:19] Output Enable
            Object *p20; // [20:20] Output Enable
            Object *p21; // [21:21] Output Enable
            Object *p22; // [22:22] Output Enable
            Object *p23; // [23:23] Output Enable
            Object *p24; // [24:24] Output Enable
            Object *p25; // [25:25] Output Enable
            Object *p26; // [26:26] Output Enable
            Object *p27; // [27:27] Output Enable
            Object *p28; // [28:28] Output Enable
            Object *p29; // [29:29] Output Enable
            Object *p30; // [30:30] Output Enable
            Object *p31; // [31:31] Output Enable
          } oer; 

          // ODR (Output Disable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Output Disable
            Object *p1; // [1:1] Output Disable
            Object *p2; // [2:2] Output Disable
            Object *p3; // [3:3] Output Disable
            Object *p4; // [4:4] Output Disable
            Object *p5; // [5:5] Output Disable
            Object *p6; // [6:6] Output Disable
            Object *p7; // [7:7] Output Disable
            Object *p8; // [8:8] Output Disable
            Object *p9; // [9:9] Output Disable
            Object *p10; // [10:10] Output Disable
            Object *p11; // [11:11] Output Disable
            Object *p12; // [12:12] Output Disable
            Object *p13; // [13:13] Output Disable
            Object *p14; // [14:14] Output Disable
            Object *p15; // [15:15] Output Disable
            Object *p16; // [16:16] Output Disable
            Object *p17; // [17:17] Output Disable
            Object *p18; // [18:18] Output Disable
            Object *p19; // [19:19] Output Disable
            Object *p20; // [20:20] Output Disable
            Object *p21; // [21:21] Output Disable
            Object *p22; // [22:22] Output Disable
            Object *p23; // [23:23] Output Disable
            Object *p24; // [24:24] Output Disable
            Object *p25; // [25:25] Output Disable
            Object *p26; // [26:26] Output Disable
            Object *p27; // [27:27] Output Disable
            Object *p28; // [28:28] Output Disable
            Object *p29; // [29:29] Output Disable
            Object *p30; // [30:30] Output Disable
            Object *p31; // [31:31] Output Disable
          } odr; 

          // OSR (Output Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Output Status
            Object *p1; // [1:1] Output Status
            Object *p2; // [2:2] Output Status
            Object *p3; // [3:3] Output Status
            Object *p4; // [4:4] Output Status
            Object *p5; // [5:5] Output Status
            Object *p6; // [6:6] Output Status
            Object *p7; // [7:7] Output Status
            Object *p8; // [8:8] Output Status
            Object *p9; // [9:9] Output Status
            Object *p10; // [10:10] Output Status
            Object *p11; // [11:11] Output Status
            Object *p12; // [12:12] Output Status
            Object *p13; // [13:13] Output Status
            Object *p14; // [14:14] Output Status
            Object *p15; // [15:15] Output Status
            Object *p16; // [16:16] Output Status
            Object *p17; // [17:17] Output Status
            Object *p18; // [18:18] Output Status
            Object *p19; // [19:19] Output Status
            Object *p20; // [20:20] Output Status
            Object *p21; // [21:21] Output Status
            Object *p22; // [22:22] Output Status
            Object *p23; // [23:23] Output Status
            Object *p24; // [24:24] Output Status
            Object *p25; // [25:25] Output Status
            Object *p26; // [26:26] Output Status
            Object *p27; // [27:27] Output Status
            Object *p28; // [28:28] Output Status
            Object *p29; // [29:29] Output Status
            Object *p30; // [30:30] Output Status
            Object *p31; // [31:31] Output Status
          } osr; 

          // IFER (Glitch Input Filter Enable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Input Filter Enable
            Object *p1; // [1:1] Input Filter Enable
            Object *p2; // [2:2] Input Filter Enable
            Object *p3; // [3:3] Input Filter Enable
            Object *p4; // [4:4] Input Filter Enable
            Object *p5; // [5:5] Input Filter Enable
            Object *p6; // [6:6] Input Filter Enable
            Object *p7; // [7:7] Input Filter Enable
            Object *p8; // [8:8] Input Filter Enable
            Object *p9; // [9:9] Input Filter Enable
            Object *p10; // [10:10] Input Filter Enable
            Object *p11; // [11:11] Input Filter Enable
            Object *p12; // [12:12] Input Filter Enable
            Object *p13; // [13:13] Input Filter Enable
            Object *p14; // [14:14] Input Filter Enable
            Object *p15; // [15:15] Input Filter Enable
            Object *p16; // [16:16] Input Filter Enable
            Object *p17; // [17:17] Input Filter Enable
            Object *p18; // [18:18] Input Filter Enable
            Object *p19; // [19:19] Input Filter Enable
            Object *p20; // [20:20] Input Filter Enable
            Object *p21; // [21:21] Input Filter Enable
            Object *p22; // [22:22] Input Filter Enable
            Object *p23; // [23:23] Input Filter Enable
            Object *p24; // [24:24] Input Filter Enable
            Object *p25; // [25:25] Input Filter Enable
            Object *p26; // [26:26] Input Filter Enable
            Object *p27; // [27:27] Input Filter Enable
            Object *p28; // [28:28] Input Filter Enable
            Object *p29; // [29:29] Input Filter Enable
            Object *p30; // [30:30] Input Filter Enable
            Object *p31; // [31:31] Input Filter Enable
          } ifer; 

          // IFDR (Glitch Input Filter Disable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Input Filter Disable
            Object *p1; // [1:1] Input Filter Disable
            Object *p2; // [2:2] Input Filter Disable
            Object *p3; // [3:3] Input Filter Disable
            Object *p4; // [4:4] Input Filter Disable
            Object *p5; // [5:5] Input Filter Disable
            Object *p6; // [6:6] Input Filter Disable
            Object *p7; // [7:7] Input Filter Disable
            Object *p8; // [8:8] Input Filter Disable
            Object *p9; // [9:9] Input Filter Disable
            Object *p10; // [10:10] Input Filter Disable
            Object *p11; // [11:11] Input Filter Disable
            Object *p12; // [12:12] Input Filter Disable
            Object *p13; // [13:13] Input Filter Disable
            Object *p14; // [14:14] Input Filter Disable
            Object *p15; // [15:15] Input Filter Disable
            Object *p16; // [16:16] Input Filter Disable
            Object *p17; // [17:17] Input Filter Disable
            Object *p18; // [18:18] Input Filter Disable
            Object *p19; // [19:19] Input Filter Disable
            Object *p20; // [20:20] Input Filter Disable
            Object *p21; // [21:21] Input Filter Disable
            Object *p22; // [22:22] Input Filter Disable
            Object *p23; // [23:23] Input Filter Disable
            Object *p24; // [24:24] Input Filter Disable
            Object *p25; // [25:25] Input Filter Disable
            Object *p26; // [26:26] Input Filter Disable
            Object *p27; // [27:27] Input Filter Disable
            Object *p28; // [28:28] Input Filter Disable
            Object *p29; // [29:29] Input Filter Disable
            Object *p30; // [30:30] Input Filter Disable
            Object *p31; // [31:31] Input Filter Disable
          } ifdr; 

          // IFSR (Glitch Input Filter Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Input Filer Status
            Object *p1; // [1:1] Input Filer Status
            Object *p2; // [2:2] Input Filer Status
            Object *p3; // [3:3] Input Filer Status
            Object *p4; // [4:4] Input Filer Status
            Object *p5; // [5:5] Input Filer Status
            Object *p6; // [6:6] Input Filer Status
            Object *p7; // [7:7] Input Filer Status
            Object *p8; // [8:8] Input Filer Status
            Object *p9; // [9:9] Input Filer Status
            Object *p10; // [10:10] Input Filer Status
            Object *p11; // [11:11] Input Filer Status
            Object *p12; // [12:12] Input Filer Status
            Object *p13; // [13:13] Input Filer Status
            Object *p14; // [14:14] Input Filer Status
            Object *p15; // [15:15] Input Filer Status
            Object *p16; // [16:16] Input Filer Status
            Object *p17; // [17:17] Input Filer Status
            Object *p18; // [18:18] Input Filer Status
            Object *p19; // [19:19] Input Filer Status
            Object *p20; // [20:20] Input Filer Status
            Object *p21; // [21:21] Input Filer Status
            Object *p22; // [22:22] Input Filer Status
            Object *p23; // [23:23] Input Filer Status
            Object *p24; // [24:24] Input Filer Status
            Object *p25; // [25:25] Input Filer Status
            Object *p26; // [26:26] Input Filer Status
            Object *p27; // [27:27] Input Filer Status
            Object *p28; // [28:28] Input Filer Status
            Object *p29; // [29:29] Input Filer Status
            Object *p30; // [30:30] Input Filer Status
            Object *p31; // [31:31] Input Filer Status
          } ifsr; 

          // SODR (Set Output Data Register) bitfields.
          struct { 
            Object *p0; // [0:0] Set Output Data
            Object *p1; // [1:1] Set Output Data
            Object *p2; // [2:2] Set Output Data
            Object *p3; // [3:3] Set Output Data
            Object *p4; // [4:4] Set Output Data
            Object *p5; // [5:5] Set Output Data
            Object *p6; // [6:6] Set Output Data
            Object *p7; // [7:7] Set Output Data
            Object *p8; // [8:8] Set Output Data
            Object *p9; // [9:9] Set Output Data
            Object *p10; // [10:10] Set Output Data
            Object *p11; // [11:11] Set Output Data
            Object *p12; // [12:12] Set Output Data
            Object *p13; // [13:13] Set Output Data
            Object *p14; // [14:14] Set Output Data
            Object *p15; // [15:15] Set Output Data
            Object *p16; // [16:16] Set Output Data
            Object *p17; // [17:17] Set Output Data
            Object *p18; // [18:18] Set Output Data
            Object *p19; // [19:19] Set Output Data
            Object *p20; // [20:20] Set Output Data
            Object *p21; // [21:21] Set Output Data
            Object *p22; // [22:22] Set Output Data
            Object *p23; // [23:23] Set Output Data
            Object *p24; // [24:24] Set Output Data
            Object *p25; // [25:25] Set Output Data
            Object *p26; // [26:26] Set Output Data
            Object *p27; // [27:27] Set Output Data
            Object *p28; // [28:28] Set Output Data
            Object *p29; // [29:29] Set Output Data
            Object *p30; // [30:30] Set Output Data
            Object *p31; // [31:31] Set Output Data
          } sodr; 

          // CODR (Clear Output Data Register) bitfields.
          struct { 
            Object *p0; // [0:0] Clear Output Data
            Object *p1; // [1:1] Clear Output Data
            Object *p2; // [2:2] Clear Output Data
            Object *p3; // [3:3] Clear Output Data
            Object *p4; // [4:4] Clear Output Data
            Object *p5; // [5:5] Clear Output Data
            Object *p6; // [6:6] Clear Output Data
            Object *p7; // [7:7] Clear Output Data
            Object *p8; // [8:8] Clear Output Data
            Object *p9; // [9:9] Clear Output Data
            Object *p10; // [10:10] Clear Output Data
            Object *p11; // [11:11] Clear Output Data
            Object *p12; // [12:12] Clear Output Data
            Object *p13; // [13:13] Clear Output Data
            Object *p14; // [14:14] Clear Output Data
            Object *p15; // [15:15] Clear Output Data
            Object *p16; // [16:16] Clear Output Data
            Object *p17; // [17:17] Clear Output Data
            Object *p18; // [18:18] Clear Output Data
            Object *p19; // [19:19] Clear Output Data
            Object *p20; // [20:20] Clear Output Data
            Object *p21; // [21:21] Clear Output Data
            Object *p22; // [22:22] Clear Output Data
            Object *p23; // [23:23] Clear Output Data
            Object *p24; // [24:24] Clear Output Data
            Object *p25; // [25:25] Clear Output Data
            Object *p26; // [26:26] Clear Output Data
            Object *p27; // [27:27] Clear Output Data
            Object *p28; // [28:28] Clear Output Data
            Object *p29; // [29:29] Clear Output Data
            Object *p30; // [30:30] Clear Output Data
            Object *p31; // [31:31] Clear Output Data
          } codr; 

          // ODSR (Output Data Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Output Data Status
            Object *p1; // [1:1] Output Data Status
            Object *p2; // [2:2] Output Data Status
            Object *p3; // [3:3] Output Data Status
            Object *p4; // [4:4] Output Data Status
            Object *p5; // [5:5] Output Data Status
            Object *p6; // [6:6] Output Data Status
            Object *p7; // [7:7] Output Data Status
            Object *p8; // [8:8] Output Data Status
            Object *p9; // [9:9] Output Data Status
            Object *p10; // [10:10] Output Data Status
            Object *p11; // [11:11] Output Data Status
            Object *p12; // [12:12] Output Data Status
            Object *p13; // [13:13] Output Data Status
            Object *p14; // [14:14] Output Data Status
            Object *p15; // [15:15] Output Data Status
            Object *p16; // [16:16] Output Data Status
            Object *p17; // [17:17] Output Data Status
            Object *p18; // [18:18] Output Data Status
            Object *p19; // [19:19] Output Data Status
            Object *p20; // [20:20] Output Data Status
            Object *p21; // [21:21] Output Data Status
            Object *p22; // [22:22] Output Data Status
            Object *p23; // [23:23] Output Data Status
            Object *p24; // [24:24] Output Data Status
            Object *p25; // [25:25] Output Data Status
            Object *p26; // [26:26] Output Data Status
            Object *p27; // [27:27] Output Data Status
            Object *p28; // [28:28] Output Data Status
            Object *p29; // [29:29] Output Data Status
            Object *p30; // [30:30] Output Data Status
            Object *p31; // [31:31] Output Data Status
          } odsr; 

          // PDSR (Pin Data Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Output Data Status
            Object *p1; // [1:1] Output Data Status
            Object *p2; // [2:2] Output Data Status
            Object *p3; // [3:3] Output Data Status
            Object *p4; // [4:4] Output Data Status
            Object *p5; // [5:5] Output Data Status
            Object *p6; // [6:6] Output Data Status
            Object *p7; // [7:7] Output Data Status
            Object *p8; // [8:8] Output Data Status
            Object *p9; // [9:9] Output Data Status
            Object *p10; // [10:10] Output Data Status
            Object *p11; // [11:11] Output Data Status
            Object *p12; // [12:12] Output Data Status
            Object *p13; // [13:13] Output Data Status
            Object *p14; // [14:14] Output Data Status
            Object *p15; // [15:15] Output Data Status
            Object *p16; // [16:16] Output Data Status
            Object *p17; // [17:17] Output Data Status
            Object *p18; // [18:18] Output Data Status
            Object *p19; // [19:19] Output Data Status
            Object *p20; // [20:20] Output Data Status
            Object *p21; // [21:21] Output Data Status
            Object *p22; // [22:22] Output Data Status
            Object *p23; // [23:23] Output Data Status
            Object *p24; // [24:24] Output Data Status
            Object *p25; // [25:25] Output Data Status
            Object *p26; // [26:26] Output Data Status
            Object *p27; // [27:27] Output Data Status
            Object *p28; // [28:28] Output Data Status
            Object *p29; // [29:29] Output Data Status
            Object *p30; // [30:30] Output Data Status
            Object *p31; // [31:31] Output Data Status
          } pdsr; 

          // IER (Interrupt Enable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Input Change Interrupt Enable
            Object *p1; // [1:1] Input Change Interrupt Enable
            Object *p2; // [2:2] Input Change Interrupt Enable
            Object *p3; // [3:3] Input Change Interrupt Enable
            Object *p4; // [4:4] Input Change Interrupt Enable
            Object *p5; // [5:5] Input Change Interrupt Enable
            Object *p6; // [6:6] Input Change Interrupt Enable
            Object *p7; // [7:7] Input Change Interrupt Enable
            Object *p8; // [8:8] Input Change Interrupt Enable
            Object *p9; // [9:9] Input Change Interrupt Enable
            Object *p10; // [10:10] Input Change Interrupt Enable
            Object *p11; // [11:11] Input Change Interrupt Enable
            Object *p12; // [12:12] Input Change Interrupt Enable
            Object *p13; // [13:13] Input Change Interrupt Enable
            Object *p14; // [14:14] Input Change Interrupt Enable
            Object *p15; // [15:15] Input Change Interrupt Enable
            Object *p16; // [16:16] Input Change Interrupt Enable
            Object *p17; // [17:17] Input Change Interrupt Enable
            Object *p18; // [18:18] Input Change Interrupt Enable
            Object *p19; // [19:19] Input Change Interrupt Enable
            Object *p20; // [20:20] Input Change Interrupt Enable
            Object *p21; // [21:21] Input Change Interrupt Enable
            Object *p22; // [22:22] Input Change Interrupt Enable
            Object *p23; // [23:23] Input Change Interrupt Enable
            Object *p24; // [24:24] Input Change Interrupt Enable
            Object *p25; // [25:25] Input Change Interrupt Enable
            Object *p26; // [26:26] Input Change Interrupt Enable
            Object *p27; // [27:27] Input Change Interrupt Enable
            Object *p28; // [28:28] Input Change Interrupt Enable
            Object *p29; // [29:29] Input Change Interrupt Enable
            Object *p30; // [30:30] Input Change Interrupt Enable
            Object *p31; // [31:31] Input Change Interrupt Enable
          } ier; 

          // IDR (Interrupt Disable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Input Change Interrupt Disable
            Object *p1; // [1:1] Input Change Interrupt Disable
            Object *p2; // [2:2] Input Change Interrupt Disable
            Object *p3; // [3:3] Input Change Interrupt Disable
            Object *p4; // [4:4] Input Change Interrupt Disable
            Object *p5; // [5:5] Input Change Interrupt Disable
            Object *p6; // [6:6] Input Change Interrupt Disable
            Object *p7; // [7:7] Input Change Interrupt Disable
            Object *p8; // [8:8] Input Change Interrupt Disable
            Object *p9; // [9:9] Input Change Interrupt Disable
            Object *p10; // [10:10] Input Change Interrupt Disable
            Object *p11; // [11:11] Input Change Interrupt Disable
            Object *p12; // [12:12] Input Change Interrupt Disable
            Object *p13; // [13:13] Input Change Interrupt Disable
            Object *p14; // [14:14] Input Change Interrupt Disable
            Object *p15; // [15:15] Input Change Interrupt Disable
            Object *p16; // [16:16] Input Change Interrupt Disable
            Object *p17; // [17:17] Input Change Interrupt Disable
            Object *p18; // [18:18] Input Change Interrupt Disable
            Object *p19; // [19:19] Input Change Interrupt Disable
            Object *p20; // [20:20] Input Change Interrupt Disable
            Object *p21; // [21:21] Input Change Interrupt Disable
            Object *p22; // [22:22] Input Change Interrupt Disable
            Object *p23; // [23:23] Input Change Interrupt Disable
            Object *p24; // [24:24] Input Change Interrupt Disable
            Object *p25; // [25:25] Input Change Interrupt Disable
            Object *p26; // [26:26] Input Change Interrupt Disable
            Object *p27; // [27:27] Input Change Interrupt Disable
            Object *p28; // [28:28] Input Change Interrupt Disable
            Object *p29; // [29:29] Input Change Interrupt Disable
            Object *p30; // [30:30] Input Change Interrupt Disable
            Object *p31; // [31:31] Input Change Interrupt Disable
          } idr; 

          // IMR (Interrupt Mask Register) bitfields.
          struct { 
            Object *p0; // [0:0] Input Change Interrupt Mask
            Object *p1; // [1:1] Input Change Interrupt Mask
            Object *p2; // [2:2] Input Change Interrupt Mask
            Object *p3; // [3:3] Input Change Interrupt Mask
            Object *p4; // [4:4] Input Change Interrupt Mask
            Object *p5; // [5:5] Input Change Interrupt Mask
            Object *p6; // [6:6] Input Change Interrupt Mask
            Object *p7; // [7:7] Input Change Interrupt Mask
            Object *p8; // [8:8] Input Change Interrupt Mask
            Object *p9; // [9:9] Input Change Interrupt Mask
            Object *p10; // [10:10] Input Change Interrupt Mask
            Object *p11; // [11:11] Input Change Interrupt Mask
            Object *p12; // [12:12] Input Change Interrupt Mask
            Object *p13; // [13:13] Input Change Interrupt Mask
            Object *p14; // [14:14] Input Change Interrupt Mask
            Object *p15; // [15:15] Input Change Interrupt Mask
            Object *p16; // [16:16] Input Change Interrupt Mask
            Object *p17; // [17:17] Input Change Interrupt Mask
            Object *p18; // [18:18] Input Change Interrupt Mask
            Object *p19; // [19:19] Input Change Interrupt Mask
            Object *p20; // [20:20] Input Change Interrupt Mask
            Object *p21; // [21:21] Input Change Interrupt Mask
            Object *p22; // [22:22] Input Change Interrupt Mask
            Object *p23; // [23:23] Input Change Interrupt Mask
            Object *p24; // [24:24] Input Change Interrupt Mask
            Object *p25; // [25:25] Input Change Interrupt Mask
            Object *p26; // [26:26] Input Change Interrupt Mask
            Object *p27; // [27:27] Input Change Interrupt Mask
            Object *p28; // [28:28] Input Change Interrupt Mask
            Object *p29; // [29:29] Input Change Interrupt Mask
            Object *p30; // [30:30] Input Change Interrupt Mask
            Object *p31; // [31:31] Input Change Interrupt Mask
          } imr; 

          // ISR (Interrupt Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Input Change Interrupt Status
            Object *p1; // [1:1] Input Change Interrupt Status
            Object *p2; // [2:2] Input Change Interrupt Status
            Object *p3; // [3:3] Input Change Interrupt Status
            Object *p4; // [4:4] Input Change Interrupt Status
            Object *p5; // [5:5] Input Change Interrupt Status
            Object *p6; // [6:6] Input Change Interrupt Status
            Object *p7; // [7:7] Input Change Interrupt Status
            Object *p8; // [8:8] Input Change Interrupt Status
            Object *p9; // [9:9] Input Change Interrupt Status
            Object *p10; // [10:10] Input Change Interrupt Status
            Object *p11; // [11:11] Input Change Interrupt Status
            Object *p12; // [12:12] Input Change Interrupt Status
            Object *p13; // [13:13] Input Change Interrupt Status
            Object *p14; // [14:14] Input Change Interrupt Status
            Object *p15; // [15:15] Input Change Interrupt Status
            Object *p16; // [16:16] Input Change Interrupt Status
            Object *p17; // [17:17] Input Change Interrupt Status
            Object *p18; // [18:18] Input Change Interrupt Status
            Object *p19; // [19:19] Input Change Interrupt Status
            Object *p20; // [20:20] Input Change Interrupt Status
            Object *p21; // [21:21] Input Change Interrupt Status
            Object *p22; // [22:22] Input Change Interrupt Status
            Object *p23; // [23:23] Input Change Interrupt Status
            Object *p24; // [24:24] Input Change Interrupt Status
            Object *p25; // [25:25] Input Change Interrupt Status
            Object *p26; // [26:26] Input Change Interrupt Status
            Object *p27; // [27:27] Input Change Interrupt Status
            Object *p28; // [28:28] Input Change Interrupt Status
            Object *p29; // [29:29] Input Change Interrupt Status
            Object *p30; // [30:30] Input Change Interrupt Status
            Object *p31; // [31:31] Input Change Interrupt Status
          } isr; 

          // MDER (Multi-driver Enable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Multi Drive Enable.
            Object *p1; // [1:1] Multi Drive Enable.
            Object *p2; // [2:2] Multi Drive Enable.
            Object *p3; // [3:3] Multi Drive Enable.
            Object *p4; // [4:4] Multi Drive Enable.
            Object *p5; // [5:5] Multi Drive Enable.
            Object *p6; // [6:6] Multi Drive Enable.
            Object *p7; // [7:7] Multi Drive Enable.
            Object *p8; // [8:8] Multi Drive Enable.
            Object *p9; // [9:9] Multi Drive Enable.
            Object *p10; // [10:10] Multi Drive Enable.
            Object *p11; // [11:11] Multi Drive Enable.
            Object *p12; // [12:12] Multi Drive Enable.
            Object *p13; // [13:13] Multi Drive Enable.
            Object *p14; // [14:14] Multi Drive Enable.
            Object *p15; // [15:15] Multi Drive Enable.
            Object *p16; // [16:16] Multi Drive Enable.
            Object *p17; // [17:17] Multi Drive Enable.
            Object *p18; // [18:18] Multi Drive Enable.
            Object *p19; // [19:19] Multi Drive Enable.
            Object *p20; // [20:20] Multi Drive Enable.
            Object *p21; // [21:21] Multi Drive Enable.
            Object *p22; // [22:22] Multi Drive Enable.
            Object *p23; // [23:23] Multi Drive Enable.
            Object *p24; // [24:24] Multi Drive Enable.
            Object *p25; // [25:25] Multi Drive Enable.
            Object *p26; // [26:26] Multi Drive Enable.
            Object *p27; // [27:27] Multi Drive Enable.
            Object *p28; // [28:28] Multi Drive Enable.
            Object *p29; // [29:29] Multi Drive Enable.
            Object *p30; // [30:30] Multi Drive Enable.
            Object *p31; // [31:31] Multi Drive Enable.
          } mder; 

          // MDDR (Multi-driver Disable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Multi Drive Disable.
            Object *p1; // [1:1] Multi Drive Disable.
            Object *p2; // [2:2] Multi Drive Disable.
            Object *p3; // [3:3] Multi Drive Disable.
            Object *p4; // [4:4] Multi Drive Disable.
            Object *p5; // [5:5] Multi Drive Disable.
            Object *p6; // [6:6] Multi Drive Disable.
            Object *p7; // [7:7] Multi Drive Disable.
            Object *p8; // [8:8] Multi Drive Disable.
            Object *p9; // [9:9] Multi Drive Disable.
            Object *p10; // [10:10] Multi Drive Disable.
            Object *p11; // [11:11] Multi Drive Disable.
            Object *p12; // [12:12] Multi Drive Disable.
            Object *p13; // [13:13] Multi Drive Disable.
            Object *p14; // [14:14] Multi Drive Disable.
            Object *p15; // [15:15] Multi Drive Disable.
            Object *p16; // [16:16] Multi Drive Disable.
            Object *p17; // [17:17] Multi Drive Disable.
            Object *p18; // [18:18] Multi Drive Disable.
            Object *p19; // [19:19] Multi Drive Disable.
            Object *p20; // [20:20] Multi Drive Disable.
            Object *p21; // [21:21] Multi Drive Disable.
            Object *p22; // [22:22] Multi Drive Disable.
            Object *p23; // [23:23] Multi Drive Disable.
            Object *p24; // [24:24] Multi Drive Disable.
            Object *p25; // [25:25] Multi Drive Disable.
            Object *p26; // [26:26] Multi Drive Disable.
            Object *p27; // [27:27] Multi Drive Disable.
            Object *p28; // [28:28] Multi Drive Disable.
            Object *p29; // [29:29] Multi Drive Disable.
            Object *p30; // [30:30] Multi Drive Disable.
            Object *p31; // [31:31] Multi Drive Disable.
          } mddr; 

          // MDSR (Multi-driver Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Multi Drive Status.
            Object *p1; // [1:1] Multi Drive Status.
            Object *p2; // [2:2] Multi Drive Status.
            Object *p3; // [3:3] Multi Drive Status.
            Object *p4; // [4:4] Multi Drive Status.
            Object *p5; // [5:5] Multi Drive Status.
            Object *p6; // [6:6] Multi Drive Status.
            Object *p7; // [7:7] Multi Drive Status.
            Object *p8; // [8:8] Multi Drive Status.
            Object *p9; // [9:9] Multi Drive Status.
            Object *p10; // [10:10] Multi Drive Status.
            Object *p11; // [11:11] Multi Drive Status.
            Object *p12; // [12:12] Multi Drive Status.
            Object *p13; // [13:13] Multi Drive Status.
            Object *p14; // [14:14] Multi Drive Status.
            Object *p15; // [15:15] Multi Drive Status.
            Object *p16; // [16:16] Multi Drive Status.
            Object *p17; // [17:17] Multi Drive Status.
            Object *p18; // [18:18] Multi Drive Status.
            Object *p19; // [19:19] Multi Drive Status.
            Object *p20; // [20:20] Multi Drive Status.
            Object *p21; // [21:21] Multi Drive Status.
            Object *p22; // [22:22] Multi Drive Status.
            Object *p23; // [23:23] Multi Drive Status.
            Object *p24; // [24:24] Multi Drive Status.
            Object *p25; // [25:25] Multi Drive Status.
            Object *p26; // [26:26] Multi Drive Status.
            Object *p27; // [27:27] Multi Drive Status.
            Object *p28; // [28:28] Multi Drive Status.
            Object *p29; // [29:29] Multi Drive Status.
            Object *p30; // [30:30] Multi Drive Status.
            Object *p31; // [31:31] Multi Drive Status.
          } mdsr; 

          // PUDR (Pull-up Disable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Pull Up Disable.
            Object *p1; // [1:1] Pull Up Disable.
            Object *p2; // [2:2] Pull Up Disable.
            Object *p3; // [3:3] Pull Up Disable.
            Object *p4; // [4:4] Pull Up Disable.
            Object *p5; // [5:5] Pull Up Disable.
            Object *p6; // [6:6] Pull Up Disable.
            Object *p7; // [7:7] Pull Up Disable.
            Object *p8; // [8:8] Pull Up Disable.
            Object *p9; // [9:9] Pull Up Disable.
            Object *p10; // [10:10] Pull Up Disable.
            Object *p11; // [11:11] Pull Up Disable.
            Object *p12; // [12:12] Pull Up Disable.
            Object *p13; // [13:13] Pull Up Disable.
            Object *p14; // [14:14] Pull Up Disable.
            Object *p15; // [15:15] Pull Up Disable.
            Object *p16; // [16:16] Pull Up Disable.
            Object *p17; // [17:17] Pull Up Disable.
            Object *p18; // [18:18] Pull Up Disable.
            Object *p19; // [19:19] Pull Up Disable.
            Object *p20; // [20:20] Pull Up Disable.
            Object *p21; // [21:21] Pull Up Disable.
            Object *p22; // [22:22] Pull Up Disable.
            Object *p23; // [23:23] Pull Up Disable.
            Object *p24; // [24:24] Pull Up Disable.
            Object *p25; // [25:25] Pull Up Disable.
            Object *p26; // [26:26] Pull Up Disable.
            Object *p27; // [27:27] Pull Up Disable.
            Object *p28; // [28:28] Pull Up Disable.
            Object *p29; // [29:29] Pull Up Disable.
            Object *p30; // [30:30] Pull Up Disable.
            Object *p31; // [31:31] Pull Up Disable.
          } pudr; 

          // PUER (Pull-up Enable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Pull Up Enable.
            Object *p1; // [1:1] Pull Up Enable.
            Object *p2; // [2:2] Pull Up Enable.
            Object *p3; // [3:3] Pull Up Enable.
            Object *p4; // [4:4] Pull Up Enable.
            Object *p5; // [5:5] Pull Up Enable.
            Object *p6; // [6:6] Pull Up Enable.
            Object *p7; // [7:7] Pull Up Enable.
            Object *p8; // [8:8] Pull Up Enable.
            Object *p9; // [9:9] Pull Up Enable.
            Object *p10; // [10:10] Pull Up Enable.
            Object *p11; // [11:11] Pull Up Enable.
            Object *p12; // [12:12] Pull Up Enable.
            Object *p13; // [13:13] Pull Up Enable.
            Object *p14; // [14:14] Pull Up Enable.
            Object *p15; // [15:15] Pull Up Enable.
            Object *p16; // [16:16] Pull Up Enable.
            Object *p17; // [17:17] Pull Up Enable.
            Object *p18; // [18:18] Pull Up Enable.
            Object *p19; // [19:19] Pull Up Enable.
            Object *p20; // [20:20] Pull Up Enable.
            Object *p21; // [21:21] Pull Up Enable.
            Object *p22; // [22:22] Pull Up Enable.
            Object *p23; // [23:23] Pull Up Enable.
            Object *p24; // [24:24] Pull Up Enable.
            Object *p25; // [25:25] Pull Up Enable.
            Object *p26; // [26:26] Pull Up Enable.
            Object *p27; // [27:27] Pull Up Enable.
            Object *p28; // [28:28] Pull Up Enable.
            Object *p29; // [29:29] Pull Up Enable.
            Object *p30; // [30:30] Pull Up Enable.
            Object *p31; // [31:31] Pull Up Enable.
          } puer; 

          // PUSR (Pad Pull-up Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Pull Up Status.
            Object *p1; // [1:1] Pull Up Status.
            Object *p2; // [2:2] Pull Up Status.
            Object *p3; // [3:3] Pull Up Status.
            Object *p4; // [4:4] Pull Up Status.
            Object *p5; // [5:5] Pull Up Status.
            Object *p6; // [6:6] Pull Up Status.
            Object *p7; // [7:7] Pull Up Status.
            Object *p8; // [8:8] Pull Up Status.
            Object *p9; // [9:9] Pull Up Status.
            Object *p10; // [10:10] Pull Up Status.
            Object *p11; // [11:11] Pull Up Status.
            Object *p12; // [12:12] Pull Up Status.
            Object *p13; // [13:13] Pull Up Status.
            Object *p14; // [14:14] Pull Up Status.
            Object *p15; // [15:15] Pull Up Status.
            Object *p16; // [16:16] Pull Up Status.
            Object *p17; // [17:17] Pull Up Status.
            Object *p18; // [18:18] Pull Up Status.
            Object *p19; // [19:19] Pull Up Status.
            Object *p20; // [20:20] Pull Up Status.
            Object *p21; // [21:21] Pull Up Status.
            Object *p22; // [22:22] Pull Up Status.
            Object *p23; // [23:23] Pull Up Status.
            Object *p24; // [24:24] Pull Up Status.
            Object *p25; // [25:25] Pull Up Status.
            Object *p26; // [26:26] Pull Up Status.
            Object *p27; // [27:27] Pull Up Status.
            Object *p28; // [28:28] Pull Up Status.
            Object *p29; // [29:29] Pull Up Status.
            Object *p30; // [30:30] Pull Up Status.
            Object *p31; // [31:31] Pull Up Status.
          } pusr; 

          // ABSR (Peripheral AB Select Register) bitfields.
          struct { 
            Object *p0; // [0:0] Peripheral A Select.
            Object *p1; // [1:1] Peripheral A Select.
            Object *p2; // [2:2] Peripheral A Select.
            Object *p3; // [3:3] Peripheral A Select.
            Object *p4; // [4:4] Peripheral A Select.
            Object *p5; // [5:5] Peripheral A Select.
            Object *p6; // [6:6] Peripheral A Select.
            Object *p7; // [7:7] Peripheral A Select.
            Object *p8; // [8:8] Peripheral A Select.
            Object *p9; // [9:9] Peripheral A Select.
            Object *p10; // [10:10] Peripheral A Select.
            Object *p11; // [11:11] Peripheral A Select.
            Object *p12; // [12:12] Peripheral A Select.
            Object *p13; // [13:13] Peripheral A Select.
            Object *p14; // [14:14] Peripheral A Select.
            Object *p15; // [15:15] Peripheral A Select.
            Object *p16; // [16:16] Peripheral A Select.
            Object *p17; // [17:17] Peripheral A Select.
            Object *p18; // [18:18] Peripheral A Select.
            Object *p19; // [19:19] Peripheral A Select.
            Object *p20; // [20:20] Peripheral A Select.
            Object *p21; // [21:21] Peripheral A Select.
            Object *p22; // [22:22] Peripheral A Select.
            Object *p23; // [23:23] Peripheral A Select.
            Object *p24; // [24:24] Peripheral A Select.
            Object *p25; // [25:25] Peripheral A Select.
            Object *p26; // [26:26] Peripheral A Select.
            Object *p27; // [27:27] Peripheral A Select.
            Object *p28; // [28:28] Peripheral A Select.
            Object *p29; // [29:29] Peripheral A Select.
            Object *p30; // [30:30] Peripheral A Select.
            Object *p31; // [31:31] Peripheral A Select.
          } absr; 

          // SCIFSR (System Clock Glitch Input Filter Select Register) bitfields.
          struct { 
            Object *p0; // [0:0] System Clock Glitch Filtering Select.
            Object *p1; // [1:1] System Clock Glitch Filtering Select.
            Object *p2; // [2:2] System Clock Glitch Filtering Select.
            Object *p3; // [3:3] System Clock Glitch Filtering Select.
            Object *p4; // [4:4] System Clock Glitch Filtering Select.
            Object *p5; // [5:5] System Clock Glitch Filtering Select.
            Object *p6; // [6:6] System Clock Glitch Filtering Select.
            Object *p7; // [7:7] System Clock Glitch Filtering Select.
            Object *p8; // [8:8] System Clock Glitch Filtering Select.
            Object *p9; // [9:9] System Clock Glitch Filtering Select.
            Object *p10; // [10:10] System Clock Glitch Filtering Select.
            Object *p11; // [11:11] System Clock Glitch Filtering Select.
            Object *p12; // [12:12] System Clock Glitch Filtering Select.
            Object *p13; // [13:13] System Clock Glitch Filtering Select.
            Object *p14; // [14:14] System Clock Glitch Filtering Select.
            Object *p15; // [15:15] System Clock Glitch Filtering Select.
            Object *p16; // [16:16] System Clock Glitch Filtering Select.
            Object *p17; // [17:17] System Clock Glitch Filtering Select.
            Object *p18; // [18:18] System Clock Glitch Filtering Select.
            Object *p19; // [19:19] System Clock Glitch Filtering Select.
            Object *p20; // [20:20] System Clock Glitch Filtering Select.
            Object *p21; // [21:21] System Clock Glitch Filtering Select.
            Object *p22; // [22:22] System Clock Glitch Filtering Select.
            Object *p23; // [23:23] System Clock Glitch Filtering Select.
            Object *p24; // [24:24] System Clock Glitch Filtering Select.
            Object *p25; // [25:25] System Clock Glitch Filtering Select.
            Object *p26; // [26:26] System Clock Glitch Filtering Select.
            Object *p27; // [27:27] System Clock Glitch Filtering Select.
            Object *p28; // [28:28] System Clock Glitch Filtering Select.
            Object *p29; // [29:29] System Clock Glitch Filtering Select.
            Object *p30; // [30:30] System Clock Glitch Filtering Select.
            Object *p31; // [31:31] System Clock Glitch Filtering Select.
          } scifsr; 

          // DIFSR (Debouncing Input Filter Select Register) bitfields.
          struct { 
            Object *p0; // [0:0] Debouncing Filtering Select.
            Object *p1; // [1:1] Debouncing Filtering Select.
            Object *p2; // [2:2] Debouncing Filtering Select.
            Object *p3; // [3:3] Debouncing Filtering Select.
            Object *p4; // [4:4] Debouncing Filtering Select.
            Object *p5; // [5:5] Debouncing Filtering Select.
            Object *p6; // [6:6] Debouncing Filtering Select.
            Object *p7; // [7:7] Debouncing Filtering Select.
            Object *p8; // [8:8] Debouncing Filtering Select.
            Object *p9; // [9:9] Debouncing Filtering Select.
            Object *p10; // [10:10] Debouncing Filtering Select.
            Object *p11; // [11:11] Debouncing Filtering Select.
            Object *p12; // [12:12] Debouncing Filtering Select.
            Object *p13; // [13:13] Debouncing Filtering Select.
            Object *p14; // [14:14] Debouncing Filtering Select.
            Object *p15; // [15:15] Debouncing Filtering Select.
            Object *p16; // [16:16] Debouncing Filtering Select.
            Object *p17; // [17:17] Debouncing Filtering Select.
            Object *p18; // [18:18] Debouncing Filtering Select.
            Object *p19; // [19:19] Debouncing Filtering Select.
            Object *p20; // [20:20] Debouncing Filtering Select.
            Object *p21; // [21:21] Debouncing Filtering Select.
            Object *p22; // [22:22] Debouncing Filtering Select.
            Object *p23; // [23:23] Debouncing Filtering Select.
            Object *p24; // [24:24] Debouncing Filtering Select.
            Object *p25; // [25:25] Debouncing Filtering Select.
            Object *p26; // [26:26] Debouncing Filtering Select.
            Object *p27; // [27:27] Debouncing Filtering Select.
            Object *p28; // [28:28] Debouncing Filtering Select.
            Object *p29; // [29:29] Debouncing Filtering Select.
            Object *p30; // [30:30] Debouncing Filtering Select.
            Object *p31; // [31:31] Debouncing Filtering Select.
          } difsr; 

          // IFDGSR (Glitch or Debouncing Input Filter Clock Selection Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Glitch or Debouncing Filter Selection Status
            Object *p1; // [1:1] Glitch or Debouncing Filter Selection Status
            Object *p2; // [2:2] Glitch or Debouncing Filter Selection Status
            Object *p3; // [3:3] Glitch or Debouncing Filter Selection Status
            Object *p4; // [4:4] Glitch or Debouncing Filter Selection Status
            Object *p5; // [5:5] Glitch or Debouncing Filter Selection Status
            Object *p6; // [6:6] Glitch or Debouncing Filter Selection Status
            Object *p7; // [7:7] Glitch or Debouncing Filter Selection Status
            Object *p8; // [8:8] Glitch or Debouncing Filter Selection Status
            Object *p9; // [9:9] Glitch or Debouncing Filter Selection Status
            Object *p10; // [10:10] Glitch or Debouncing Filter Selection Status
            Object *p11; // [11:11] Glitch or Debouncing Filter Selection Status
            Object *p12; // [12:12] Glitch or Debouncing Filter Selection Status
            Object *p13; // [13:13] Glitch or Debouncing Filter Selection Status
            Object *p14; // [14:14] Glitch or Debouncing Filter Selection Status
            Object *p15; // [15:15] Glitch or Debouncing Filter Selection Status
            Object *p16; // [16:16] Glitch or Debouncing Filter Selection Status
            Object *p17; // [17:17] Glitch or Debouncing Filter Selection Status
            Object *p18; // [18:18] Glitch or Debouncing Filter Selection Status
            Object *p19; // [19:19] Glitch or Debouncing Filter Selection Status
            Object *p20; // [20:20] Glitch or Debouncing Filter Selection Status
            Object *p21; // [21:21] Glitch or Debouncing Filter Selection Status
            Object *p22; // [22:22] Glitch or Debouncing Filter Selection Status
            Object *p23; // [23:23] Glitch or Debouncing Filter Selection Status
            Object *p24; // [24:24] Glitch or Debouncing Filter Selection Status
            Object *p25; // [25:25] Glitch or Debouncing Filter Selection Status
            Object *p26; // [26:26] Glitch or Debouncing Filter Selection Status
            Object *p27; // [27:27] Glitch or Debouncing Filter Selection Status
            Object *p28; // [28:28] Glitch or Debouncing Filter Selection Status
            Object *p29; // [29:29] Glitch or Debouncing Filter Selection Status
            Object *p30; // [30:30] Glitch or Debouncing Filter Selection Status
            Object *p31; // [31:31] Glitch or Debouncing Filter Selection Status
          } ifdgsr; 

          // SCDR (Slow Clock Divider Debouncing Register) bitfields.
          struct { 
            Object *div; // [0:13] Slow Clock Divider Selection for Debouncing
          } scdr; 

          // OWER (Output Write Enable) bitfields.
          struct { 
            Object *p0; // [0:0] Output Write Enable.
            Object *p1; // [1:1] Output Write Enable.
            Object *p2; // [2:2] Output Write Enable.
            Object *p3; // [3:3] Output Write Enable.
            Object *p4; // [4:4] Output Write Enable.
            Object *p5; // [5:5] Output Write Enable.
            Object *p6; // [6:6] Output Write Enable.
            Object *p7; // [7:7] Output Write Enable.
            Object *p8; // [8:8] Output Write Enable.
            Object *p9; // [9:9] Output Write Enable.
            Object *p10; // [10:10] Output Write Enable.
            Object *p11; // [11:11] Output Write Enable.
            Object *p12; // [12:12] Output Write Enable.
            Object *p13; // [13:13] Output Write Enable.
            Object *p14; // [14:14] Output Write Enable.
            Object *p15; // [15:15] Output Write Enable.
            Object *p16; // [16:16] Output Write Enable.
            Object *p17; // [17:17] Output Write Enable.
            Object *p18; // [18:18] Output Write Enable.
            Object *p19; // [19:19] Output Write Enable.
            Object *p20; // [20:20] Output Write Enable.
            Object *p21; // [21:21] Output Write Enable.
            Object *p22; // [22:22] Output Write Enable.
            Object *p23; // [23:23] Output Write Enable.
            Object *p24; // [24:24] Output Write Enable.
            Object *p25; // [25:25] Output Write Enable.
            Object *p26; // [26:26] Output Write Enable.
            Object *p27; // [27:27] Output Write Enable.
            Object *p28; // [28:28] Output Write Enable.
            Object *p29; // [29:29] Output Write Enable.
            Object *p30; // [30:30] Output Write Enable.
            Object *p31; // [31:31] Output Write Enable.
          } ower; 

          // OWDR (Output Write Disable) bitfields.
          struct { 
            Object *p0; // [0:0] Output Write Disable.
            Object *p1; // [1:1] Output Write Disable.
            Object *p2; // [2:2] Output Write Disable.
            Object *p3; // [3:3] Output Write Disable.
            Object *p4; // [4:4] Output Write Disable.
            Object *p5; // [5:5] Output Write Disable.
            Object *p6; // [6:6] Output Write Disable.
            Object *p7; // [7:7] Output Write Disable.
            Object *p8; // [8:8] Output Write Disable.
            Object *p9; // [9:9] Output Write Disable.
            Object *p10; // [10:10] Output Write Disable.
            Object *p11; // [11:11] Output Write Disable.
            Object *p12; // [12:12] Output Write Disable.
            Object *p13; // [13:13] Output Write Disable.
            Object *p14; // [14:14] Output Write Disable.
            Object *p15; // [15:15] Output Write Disable.
            Object *p16; // [16:16] Output Write Disable.
            Object *p17; // [17:17] Output Write Disable.
            Object *p18; // [18:18] Output Write Disable.
            Object *p19; // [19:19] Output Write Disable.
            Object *p20; // [20:20] Output Write Disable.
            Object *p21; // [21:21] Output Write Disable.
            Object *p22; // [22:22] Output Write Disable.
            Object *p23; // [23:23] Output Write Disable.
            Object *p24; // [24:24] Output Write Disable.
            Object *p25; // [25:25] Output Write Disable.
            Object *p26; // [26:26] Output Write Disable.
            Object *p27; // [27:27] Output Write Disable.
            Object *p28; // [28:28] Output Write Disable.
            Object *p29; // [29:29] Output Write Disable.
            Object *p30; // [30:30] Output Write Disable.
            Object *p31; // [31:31] Output Write Disable.
          } owdr; 

          // OWSR (Output Write Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Output Write Status.
            Object *p1; // [1:1] Output Write Status.
            Object *p2; // [2:2] Output Write Status.
            Object *p3; // [3:3] Output Write Status.
            Object *p4; // [4:4] Output Write Status.
            Object *p5; // [5:5] Output Write Status.
            Object *p6; // [6:6] Output Write Status.
            Object *p7; // [7:7] Output Write Status.
            Object *p8; // [8:8] Output Write Status.
            Object *p9; // [9:9] Output Write Status.
            Object *p10; // [10:10] Output Write Status.
            Object *p11; // [11:11] Output Write Status.
            Object *p12; // [12:12] Output Write Status.
            Object *p13; // [13:13] Output Write Status.
            Object *p14; // [14:14] Output Write Status.
            Object *p15; // [15:15] Output Write Status.
            Object *p16; // [16:16] Output Write Status.
            Object *p17; // [17:17] Output Write Status.
            Object *p18; // [18:18] Output Write Status.
            Object *p19; // [19:19] Output Write Status.
            Object *p20; // [20:20] Output Write Status.
            Object *p21; // [21:21] Output Write Status.
            Object *p22; // [22:22] Output Write Status.
            Object *p23; // [23:23] Output Write Status.
            Object *p24; // [24:24] Output Write Status.
            Object *p25; // [25:25] Output Write Status.
            Object *p26; // [26:26] Output Write Status.
            Object *p27; // [27:27] Output Write Status.
            Object *p28; // [28:28] Output Write Status.
            Object *p29; // [29:29] Output Write Status.
            Object *p30; // [30:30] Output Write Status.
            Object *p31; // [31:31] Output Write Status.
          } owsr; 

          // AIMER (Additional Interrupt Modes Enable Register) bitfields.
          struct { 
            Object *p0; // [0:0] Additional Interrupt Modes Enable.
            Object *p1; // [1:1] Additional Interrupt Modes Enable.
            Object *p2; // [2:2] Additional Interrupt Modes Enable.
            Object *p3; // [3:3] Additional Interrupt Modes Enable.
            Object *p4; // [4:4] Additional Interrupt Modes Enable.
            Object *p5; // [5:5] Additional Interrupt Modes Enable.
            Object *p6; // [6:6] Additional Interrupt Modes Enable.
            Object *p7; // [7:7] Additional Interrupt Modes Enable.
            Object *p8; // [8:8] Additional Interrupt Modes Enable.
            Object *p9; // [9:9] Additional Interrupt Modes Enable.
            Object *p10; // [10:10] Additional Interrupt Modes Enable.
            Object *p11; // [11:11] Additional Interrupt Modes Enable.
            Object *p12; // [12:12] Additional Interrupt Modes Enable.
            Object *p13; // [13:13] Additional Interrupt Modes Enable.
            Object *p14; // [14:14] Additional Interrupt Modes Enable.
            Object *p15; // [15:15] Additional Interrupt Modes Enable.
            Object *p16; // [16:16] Additional Interrupt Modes Enable.
            Object *p17; // [17:17] Additional Interrupt Modes Enable.
            Object *p18; // [18:18] Additional Interrupt Modes Enable.
            Object *p19; // [19:19] Additional Interrupt Modes Enable.
            Object *p20; // [20:20] Additional Interrupt Modes Enable.
            Object *p21; // [21:21] Additional Interrupt Modes Enable.
            Object *p22; // [22:22] Additional Interrupt Modes Enable.
            Object *p23; // [23:23] Additional Interrupt Modes Enable.
            Object *p24; // [24:24] Additional Interrupt Modes Enable.
            Object *p25; // [25:25] Additional Interrupt Modes Enable.
            Object *p26; // [26:26] Additional Interrupt Modes Enable.
            Object *p27; // [27:27] Additional Interrupt Modes Enable.
            Object *p28; // [28:28] Additional Interrupt Modes Enable.
            Object *p29; // [29:29] Additional Interrupt Modes Enable.
            Object *p30; // [30:30] Additional Interrupt Modes Enable.
            Object *p31; // [31:31] Additional Interrupt Modes Enable.
          } aimer; 

          // AIMDR (Additional Interrupt Modes Disables Register) bitfields.
          struct { 
            Object *p0; // [0:0] Additional Interrupt Modes Disable.
            Object *p1; // [1:1] Additional Interrupt Modes Disable.
            Object *p2; // [2:2] Additional Interrupt Modes Disable.
            Object *p3; // [3:3] Additional Interrupt Modes Disable.
            Object *p4; // [4:4] Additional Interrupt Modes Disable.
            Object *p5; // [5:5] Additional Interrupt Modes Disable.
            Object *p6; // [6:6] Additional Interrupt Modes Disable.
            Object *p7; // [7:7] Additional Interrupt Modes Disable.
            Object *p8; // [8:8] Additional Interrupt Modes Disable.
            Object *p9; // [9:9] Additional Interrupt Modes Disable.
            Object *p10; // [10:10] Additional Interrupt Modes Disable.
            Object *p11; // [11:11] Additional Interrupt Modes Disable.
            Object *p12; // [12:12] Additional Interrupt Modes Disable.
            Object *p13; // [13:13] Additional Interrupt Modes Disable.
            Object *p14; // [14:14] Additional Interrupt Modes Disable.
            Object *p15; // [15:15] Additional Interrupt Modes Disable.
            Object *p16; // [16:16] Additional Interrupt Modes Disable.
            Object *p17; // [17:17] Additional Interrupt Modes Disable.
            Object *p18; // [18:18] Additional Interrupt Modes Disable.
            Object *p19; // [19:19] Additional Interrupt Modes Disable.
            Object *p20; // [20:20] Additional Interrupt Modes Disable.
            Object *p21; // [21:21] Additional Interrupt Modes Disable.
            Object *p22; // [22:22] Additional Interrupt Modes Disable.
            Object *p23; // [23:23] Additional Interrupt Modes Disable.
            Object *p24; // [24:24] Additional Interrupt Modes Disable.
            Object *p25; // [25:25] Additional Interrupt Modes Disable.
            Object *p26; // [26:26] Additional Interrupt Modes Disable.
            Object *p27; // [27:27] Additional Interrupt Modes Disable.
            Object *p28; // [28:28] Additional Interrupt Modes Disable.
            Object *p29; // [29:29] Additional Interrupt Modes Disable.
            Object *p30; // [30:30] Additional Interrupt Modes Disable.
            Object *p31; // [31:31] Additional Interrupt Modes Disable.
          } aimdr; 

          // AIMMR (Additional Interrupt Modes Mask Register) bitfields.
          struct { 
            Object *p0; // [0:0] Peripheral CD Status.
            Object *p1; // [1:1] Peripheral CD Status.
            Object *p2; // [2:2] Peripheral CD Status.
            Object *p3; // [3:3] Peripheral CD Status.
            Object *p4; // [4:4] Peripheral CD Status.
            Object *p5; // [5:5] Peripheral CD Status.
            Object *p6; // [6:6] Peripheral CD Status.
            Object *p7; // [7:7] Peripheral CD Status.
            Object *p8; // [8:8] Peripheral CD Status.
            Object *p9; // [9:9] Peripheral CD Status.
            Object *p10; // [10:10] Peripheral CD Status.
            Object *p11; // [11:11] Peripheral CD Status.
            Object *p12; // [12:12] Peripheral CD Status.
            Object *p13; // [13:13] Peripheral CD Status.
            Object *p14; // [14:14] Peripheral CD Status.
            Object *p15; // [15:15] Peripheral CD Status.
            Object *p16; // [16:16] Peripheral CD Status.
            Object *p17; // [17:17] Peripheral CD Status.
            Object *p18; // [18:18] Peripheral CD Status.
            Object *p19; // [19:19] Peripheral CD Status.
            Object *p20; // [20:20] Peripheral CD Status.
            Object *p21; // [21:21] Peripheral CD Status.
            Object *p22; // [22:22] Peripheral CD Status.
            Object *p23; // [23:23] Peripheral CD Status.
            Object *p24; // [24:24] Peripheral CD Status.
            Object *p25; // [25:25] Peripheral CD Status.
            Object *p26; // [26:26] Peripheral CD Status.
            Object *p27; // [27:27] Peripheral CD Status.
            Object *p28; // [28:28] Peripheral CD Status.
            Object *p29; // [29:29] Peripheral CD Status.
            Object *p30; // [30:30] Peripheral CD Status.
            Object *p31; // [31:31] Peripheral CD Status.
          } aimmr; 

          // ESR (Edge Select Register) bitfields.
          struct { 
            Object *p0; // [0:0] Edge Interrupt Selection.
            Object *p1; // [1:1] Edge Interrupt Selection.
            Object *p2; // [2:2] Edge Interrupt Selection.
            Object *p3; // [3:3] Edge Interrupt Selection.
            Object *p4; // [4:4] Edge Interrupt Selection.
            Object *p5; // [5:5] Edge Interrupt Selection.
            Object *p6; // [6:6] Edge Interrupt Selection.
            Object *p7; // [7:7] Edge Interrupt Selection.
            Object *p8; // [8:8] Edge Interrupt Selection.
            Object *p9; // [9:9] Edge Interrupt Selection.
            Object *p10; // [10:10] Edge Interrupt Selection.
            Object *p11; // [11:11] Edge Interrupt Selection.
            Object *p12; // [12:12] Edge Interrupt Selection.
            Object *p13; // [13:13] Edge Interrupt Selection.
            Object *p14; // [14:14] Edge Interrupt Selection.
            Object *p15; // [15:15] Edge Interrupt Selection.
            Object *p16; // [16:16] Edge Interrupt Selection.
            Object *p17; // [17:17] Edge Interrupt Selection.
            Object *p18; // [18:18] Edge Interrupt Selection.
            Object *p19; // [19:19] Edge Interrupt Selection.
            Object *p20; // [20:20] Edge Interrupt Selection.
            Object *p21; // [21:21] Edge Interrupt Selection.
            Object *p22; // [22:22] Edge Interrupt Selection.
            Object *p23; // [23:23] Edge Interrupt Selection.
            Object *p24; // [24:24] Edge Interrupt Selection.
            Object *p25; // [25:25] Edge Interrupt Selection.
            Object *p26; // [26:26] Edge Interrupt Selection.
            Object *p27; // [27:27] Edge Interrupt Selection.
            Object *p28; // [28:28] Edge Interrupt Selection.
            Object *p29; // [29:29] Edge Interrupt Selection.
            Object *p30; // [30:30] Edge Interrupt Selection.
            Object *p31; // [31:31] Edge Interrupt Selection.
          } esr; 

          // LSR (Level Select Register) bitfields.
          struct { 
            Object *p0; // [0:0] Level Interrupt Selection.
            Object *p1; // [1:1] Level Interrupt Selection.
            Object *p2; // [2:2] Level Interrupt Selection.
            Object *p3; // [3:3] Level Interrupt Selection.
            Object *p4; // [4:4] Level Interrupt Selection.
            Object *p5; // [5:5] Level Interrupt Selection.
            Object *p6; // [6:6] Level Interrupt Selection.
            Object *p7; // [7:7] Level Interrupt Selection.
            Object *p8; // [8:8] Level Interrupt Selection.
            Object *p9; // [9:9] Level Interrupt Selection.
            Object *p10; // [10:10] Level Interrupt Selection.
            Object *p11; // [11:11] Level Interrupt Selection.
            Object *p12; // [12:12] Level Interrupt Selection.
            Object *p13; // [13:13] Level Interrupt Selection.
            Object *p14; // [14:14] Level Interrupt Selection.
            Object *p15; // [15:15] Level Interrupt Selection.
            Object *p16; // [16:16] Level Interrupt Selection.
            Object *p17; // [17:17] Level Interrupt Selection.
            Object *p18; // [18:18] Level Interrupt Selection.
            Object *p19; // [19:19] Level Interrupt Selection.
            Object *p20; // [20:20] Level Interrupt Selection.
            Object *p21; // [21:21] Level Interrupt Selection.
            Object *p22; // [22:22] Level Interrupt Selection.
            Object *p23; // [23:23] Level Interrupt Selection.
            Object *p24; // [24:24] Level Interrupt Selection.
            Object *p25; // [25:25] Level Interrupt Selection.
            Object *p26; // [26:26] Level Interrupt Selection.
            Object *p27; // [27:27] Level Interrupt Selection.
            Object *p28; // [28:28] Level Interrupt Selection.
            Object *p29; // [29:29] Level Interrupt Selection.
            Object *p30; // [30:30] Level Interrupt Selection.
            Object *p31; // [31:31] Level Interrupt Selection.
          } lsr; 

          // ELSR (Edge/Level Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Edge/Level Interrupt source selection.
            Object *p1; // [1:1] Edge/Level Interrupt source selection.
            Object *p2; // [2:2] Edge/Level Interrupt source selection.
            Object *p3; // [3:3] Edge/Level Interrupt source selection.
            Object *p4; // [4:4] Edge/Level Interrupt source selection.
            Object *p5; // [5:5] Edge/Level Interrupt source selection.
            Object *p6; // [6:6] Edge/Level Interrupt source selection.
            Object *p7; // [7:7] Edge/Level Interrupt source selection.
            Object *p8; // [8:8] Edge/Level Interrupt source selection.
            Object *p9; // [9:9] Edge/Level Interrupt source selection.
            Object *p10; // [10:10] Edge/Level Interrupt source selection.
            Object *p11; // [11:11] Edge/Level Interrupt source selection.
            Object *p12; // [12:12] Edge/Level Interrupt source selection.
            Object *p13; // [13:13] Edge/Level Interrupt source selection.
            Object *p14; // [14:14] Edge/Level Interrupt source selection.
            Object *p15; // [15:15] Edge/Level Interrupt source selection.
            Object *p16; // [16:16] Edge/Level Interrupt source selection.
            Object *p17; // [17:17] Edge/Level Interrupt source selection.
            Object *p18; // [18:18] Edge/Level Interrupt source selection.
            Object *p19; // [19:19] Edge/Level Interrupt source selection.
            Object *p20; // [20:20] Edge/Level Interrupt source selection.
            Object *p21; // [21:21] Edge/Level Interrupt source selection.
            Object *p22; // [22:22] Edge/Level Interrupt source selection.
            Object *p23; // [23:23] Edge/Level Interrupt source selection.
            Object *p24; // [24:24] Edge/Level Interrupt source selection.
            Object *p25; // [25:25] Edge/Level Interrupt source selection.
            Object *p26; // [26:26] Edge/Level Interrupt source selection.
            Object *p27; // [27:27] Edge/Level Interrupt source selection.
            Object *p28; // [28:28] Edge/Level Interrupt source selection.
            Object *p29; // [29:29] Edge/Level Interrupt source selection.
            Object *p30; // [30:30] Edge/Level Interrupt source selection.
            Object *p31; // [31:31] Edge/Level Interrupt source selection.
          } elsr; 

          // FELLSR (Falling Edge/Low Level Select Register) bitfields.
          struct { 
            Object *p0; // [0:0] Falling Edge/Low Level Interrupt Selection.
            Object *p1; // [1:1] Falling Edge/Low Level Interrupt Selection.
            Object *p2; // [2:2] Falling Edge/Low Level Interrupt Selection.
            Object *p3; // [3:3] Falling Edge/Low Level Interrupt Selection.
            Object *p4; // [4:4] Falling Edge/Low Level Interrupt Selection.
            Object *p5; // [5:5] Falling Edge/Low Level Interrupt Selection.
            Object *p6; // [6:6] Falling Edge/Low Level Interrupt Selection.
            Object *p7; // [7:7] Falling Edge/Low Level Interrupt Selection.
            Object *p8; // [8:8] Falling Edge/Low Level Interrupt Selection.
            Object *p9; // [9:9] Falling Edge/Low Level Interrupt Selection.
            Object *p10; // [10:10] Falling Edge/Low Level Interrupt Selection.
            Object *p11; // [11:11] Falling Edge/Low Level Interrupt Selection.
            Object *p12; // [12:12] Falling Edge/Low Level Interrupt Selection.
            Object *p13; // [13:13] Falling Edge/Low Level Interrupt Selection.
            Object *p14; // [14:14] Falling Edge/Low Level Interrupt Selection.
            Object *p15; // [15:15] Falling Edge/Low Level Interrupt Selection.
            Object *p16; // [16:16] Falling Edge/Low Level Interrupt Selection.
            Object *p17; // [17:17] Falling Edge/Low Level Interrupt Selection.
            Object *p18; // [18:18] Falling Edge/Low Level Interrupt Selection.
            Object *p19; // [19:19] Falling Edge/Low Level Interrupt Selection.
            Object *p20; // [20:20] Falling Edge/Low Level Interrupt Selection.
            Object *p21; // [21:21] Falling Edge/Low Level Interrupt Selection.
            Object *p22; // [22:22] Falling Edge/Low Level Interrupt Selection.
            Object *p23; // [23:23] Falling Edge/Low Level Interrupt Selection.
            Object *p24; // [24:24] Falling Edge/Low Level Interrupt Selection.
            Object *p25; // [25:25] Falling Edge/Low Level Interrupt Selection.
            Object *p26; // [26:26] Falling Edge/Low Level Interrupt Selection.
            Object *p27; // [27:27] Falling Edge/Low Level Interrupt Selection.
            Object *p28; // [28:28] Falling Edge/Low Level Interrupt Selection.
            Object *p29; // [29:29] Falling Edge/Low Level Interrupt Selection.
            Object *p30; // [30:30] Falling Edge/Low Level Interrupt Selection.
            Object *p31; // [31:31] Falling Edge/Low Level Interrupt Selection.
          } fellsr; 

          // REHLSR (Rising Edge/ High Level Select Register) bitfields.
          struct { 
            Object *p0; // [0:0] Rising Edge /High Level Interrupt Selection.
            Object *p1; // [1:1] Rising Edge /High Level Interrupt Selection.
            Object *p2; // [2:2] Rising Edge /High Level Interrupt Selection.
            Object *p3; // [3:3] Rising Edge /High Level Interrupt Selection.
            Object *p4; // [4:4] Rising Edge /High Level Interrupt Selection.
            Object *p5; // [5:5] Rising Edge /High Level Interrupt Selection.
            Object *p6; // [6:6] Rising Edge /High Level Interrupt Selection.
            Object *p7; // [7:7] Rising Edge /High Level Interrupt Selection.
            Object *p8; // [8:8] Rising Edge /High Level Interrupt Selection.
            Object *p9; // [9:9] Rising Edge /High Level Interrupt Selection.
            Object *p10; // [10:10] Rising Edge /High Level Interrupt Selection.
            Object *p11; // [11:11] Rising Edge /High Level Interrupt Selection.
            Object *p12; // [12:12] Rising Edge /High Level Interrupt Selection.
            Object *p13; // [13:13] Rising Edge /High Level Interrupt Selection.
            Object *p14; // [14:14] Rising Edge /High Level Interrupt Selection.
            Object *p15; // [15:15] Rising Edge /High Level Interrupt Selection.
            Object *p16; // [16:16] Rising Edge /High Level Interrupt Selection.
            Object *p17; // [17:17] Rising Edge /High Level Interrupt Selection.
            Object *p18; // [18:18] Rising Edge /High Level Interrupt Selection.
            Object *p19; // [19:19] Rising Edge /High Level Interrupt Selection.
            Object *p20; // [20:20] Rising Edge /High Level Interrupt Selection.
            Object *p21; // [21:21] Rising Edge /High Level Interrupt Selection.
            Object *p22; // [22:22] Rising Edge /High Level Interrupt Selection.
            Object *p23; // [23:23] Rising Edge /High Level Interrupt Selection.
            Object *p24; // [24:24] Rising Edge /High Level Interrupt Selection.
            Object *p25; // [25:25] Rising Edge /High Level Interrupt Selection.
            Object *p26; // [26:26] Rising Edge /High Level Interrupt Selection.
            Object *p27; // [27:27] Rising Edge /High Level Interrupt Selection.
            Object *p28; // [28:28] Rising Edge /High Level Interrupt Selection.
            Object *p29; // [29:29] Rising Edge /High Level Interrupt Selection.
            Object *p30; // [30:30] Rising Edge /High Level Interrupt Selection.
            Object *p31; // [31:31] Rising Edge /High Level Interrupt Selection.
          } rehlsr; 

          // FRLHSR (Fall/Rise - Low/High Status Register) bitfields.
          struct { 
            Object *p0; // [0:0] Edge /Level Interrupt Source Selection.
            Object *p1; // [1:1] Edge /Level Interrupt Source Selection.
            Object *p2; // [2:2] Edge /Level Interrupt Source Selection.
            Object *p3; // [3:3] Edge /Level Interrupt Source Selection.
            Object *p4; // [4:4] Edge /Level Interrupt Source Selection.
            Object *p5; // [5:5] Edge /Level Interrupt Source Selection.
            Object *p6; // [6:6] Edge /Level Interrupt Source Selection.
            Object *p7; // [7:7] Edge /Level Interrupt Source Selection.
            Object *p8; // [8:8] Edge /Level Interrupt Source Selection.
            Object *p9; // [9:9] Edge /Level Interrupt Source Selection.
            Object *p10; // [10:10] Edge /Level Interrupt Source Selection.
            Object *p11; // [11:11] Edge /Level Interrupt Source Selection.
            Object *p12; // [12:12] Edge /Level Interrupt Source Selection.
            Object *p13; // [13:13] Edge /Level Interrupt Source Selection.
            Object *p14; // [14:14] Edge /Level Interrupt Source Selection.
            Object *p15; // [15:15] Edge /Level Interrupt Source Selection.
            Object *p16; // [16:16] Edge /Level Interrupt Source Selection.
            Object *p17; // [17:17] Edge /Level Interrupt Source Selection.
            Object *p18; // [18:18] Edge /Level Interrupt Source Selection.
            Object *p19; // [19:19] Edge /Level Interrupt Source Selection.
            Object *p20; // [20:20] Edge /Level Interrupt Source Selection.
            Object *p21; // [21:21] Edge /Level Interrupt Source Selection.
            Object *p22; // [22:22] Edge /Level Interrupt Source Selection.
            Object *p23; // [23:23] Edge /Level Interrupt Source Selection.
            Object *p24; // [24:24] Edge /Level Interrupt Source Selection.
            Object *p25; // [25:25] Edge /Level Interrupt Source Selection.
            Object *p26; // [26:26] Edge /Level Interrupt Source Selection.
            Object *p27; // [27:27] Edge /Level Interrupt Source Selection.
            Object *p28; // [28:28] Edge /Level Interrupt Source Selection.
            Object *p29; // [29:29] Edge /Level Interrupt Source Selection.
            Object *p30; // [30:30] Edge /Level Interrupt Source Selection.
            Object *p31; // [31:31] Edge /Level Interrupt Source Selection.
          } frlhsr; 

          // LOCKSR (Lock Status) bitfields.
          struct { 
            Object *p0; // [0:0] Lock Status.
            Object *p1; // [1:1] Lock Status.
            Object *p2; // [2:2] Lock Status.
            Object *p3; // [3:3] Lock Status.
            Object *p4; // [4:4] Lock Status.
            Object *p5; // [5:5] Lock Status.
            Object *p6; // [6:6] Lock Status.
            Object *p7; // [7:7] Lock Status.
            Object *p8; // [8:8] Lock Status.
            Object *p9; // [9:9] Lock Status.
            Object *p10; // [10:10] Lock Status.
            Object *p11; // [11:11] Lock Status.
            Object *p12; // [12:12] Lock Status.
            Object *p13; // [13:13] Lock Status.
            Object *p14; // [14:14] Lock Status.
            Object *p15; // [15:15] Lock Status.
            Object *p16; // [16:16] Lock Status.
            Object *p17; // [17:17] Lock Status.
            Object *p18; // [18:18] Lock Status.
            Object *p19; // [19:19] Lock Status.
            Object *p20; // [20:20] Lock Status.
            Object *p21; // [21:21] Lock Status.
            Object *p22; // [22:22] Lock Status.
            Object *p23; // [23:23] Lock Status.
            Object *p24; // [24:24] Lock Status.
            Object *p25; // [25:25] Lock Status.
            Object *p26; // [26:26] Lock Status.
            Object *p27; // [27:27] Lock Status.
            Object *p28; // [28:28] Lock Status.
            Object *p29; // [29:29] Lock Status.
            Object *p30; // [30:30] Lock Status.
            Object *p31; // [31:31] Lock Status.
          } locksr; 

          // WPMR (Write Protect Mode Register) bitfields.
          struct { 
            Object *wpen; // [0:0] Write Protect Enable
            Object *wpkey; // [8:31] Write Protect KEY
          } wpmr; 

          // WPSR (Write Protect Status Register) bitfields.
          struct { 
            Object *wpvs; // [0:0] Write Protect Violation Status
            Object *wpvsrc; // [8:23] Write Protect Violation Source
          } wpsr; 
        } fld;
      } sam3x;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} SAMPIOState;

// ----- Public ---------------------------------------------------------------

Object* sam_pio_create(Object *parent, sam_pio_index_t index);

Object* sam_pio_get(int index);
// ----------------------------------------------------------------------------

#endif /* SAM_PIO_H_ */
