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

#ifndef SAMD_PORT_H_
#define SAMD_PORT_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/samd/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_SAMD_PORT DEVICE_PATH_SAMD "PORT"

#define SAMD_IRQ_PORT_IN_IN         	"in-in"
#define SAMD_IRQ_GPIO_ARMEMUS_OUT       "armemus-out"

// ----------------------------------------------------------------------------

#define TYPE_SAMD_PORT TYPE_SAMD_PREFIX "port" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_SAMD_PORT_PARENT TYPE_PERIPHERAL
typedef PeripheralClass SAMDPORTParentClass;
typedef PeripheralState SAMDPORTParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define SAMD_PORT_GET_CLASS(obj) \
    OBJECT_GET_CLASS(SAMDPORTClass, (obj), TYPE_SAMD_PORT)
#define SAMD_PORT_CLASS(klass) \
    OBJECT_CLASS_CHECK(SAMDPORTClass, (klass), TYPE_SAMD_PORT)

typedef struct {
    // private: 
    SAMDPORTParentClass parent_class;
    // public: 

    // None, so far.
} SAMDPORTClass;

// ----------------------------------------------------------------------------

void samd_port_armemus_write_callback(const char *value);

// ----------------------------------------------------------------------------

// Instance definitions.
#define SAMD_PORT_STATE(obj) \
    OBJECT_CHECK(SAMDPORTState, (obj), TYPE_SAMD_PORT)

typedef struct {
    // private:
    SAMDPORTParentState parent_obj;
    // public:

    const SAMDCapabilities *capabilities;
    
    qemu_irq armemus_irq[SAMD_MAX_PINS];
    
    // SAMD21 PORT (Port Module) registers.
    struct { 
      Object *dir; // 0x00 (Data Direction) 
      Object *dirclr; // 0x04 (Data Direction Clear) 
      Object *dirset; // 0x08 (Data Direction Set) 
      Object *dirtgl; // 0x0C (Data Direction Toggle) 
      Object *out; // 0x10 (Data Output Value) 
      Object *outclr; // 0x14 (Data Output Value Clear) 
      Object *outset; // 0x18 (Data Output Value Set) 
      Object *outtgl; // 0x1C (Data Output Value Toggle) 
      Object *in; // 0x20 (Data Input Value) 
      Object *ctrl; // 0x24 (Control) 
      Object *wrconfig; // 0x28 (Write Configuration) 
      Object *pmux0_; // 0x30 (Peripheral Multiplexing n - Group 0) 
      Object *pmux1_; // 0xb0 (Peripheral Multiplexing n - Group 1) 
      Object *pincfg0_; // 0x40 (Pin Configuration n - Group 0) 
      Object *pincfg1_; // 0xc0 (Pin Configuration n - Group 1) 
    } reg;


    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // SAMD21 PORT (Port Module) registers.
        struct { 
          Object *dir; // 0x00 (Data Direction) 
          Object *dirclr; // 0x04 (Data Direction Clear) 
          Object *dirset; // 0x08 (Data Direction Set) 
          Object *dirtgl; // 0x0C (Data Direction Toggle) 
          Object *out; // 0x10 (Data Output Value) 
          Object *outclr; // 0x14 (Data Output Value Clear) 
          Object *outset; // 0x18 (Data Output Value Set) 
          Object *outtgl; // 0x1C (Data Output Value Toggle) 
          Object *in; // 0x20 (Data Input Value) 
          Object *ctrl; // 0x24 (Control) 
          Object *wrconfig; // 0x28 (Write Configuration) 
          Object *pmux0_; // 0x30 (Peripheral Multiplexing n - Group 0) 
          Object *pmux1_; // 0xb0 (Peripheral Multiplexing n - Group 1) 
          Object *pincfg0_; // 0x40 (Pin Configuration n - Group 0) 
          Object *pincfg1_; // 0xc0 (Pin Configuration n - Group 1) 
        } reg;

        struct { 

          // DIR (Data Direction) bitfields.
          struct { 
            Object *dir; // [0:31] Port Data Direction
          } dir; 

          // DIRCLR (Data Direction Clear) bitfields.
          struct { 
            Object *dirclr; // [0:31] Port Data Direction Clear
          } dirclr; 

          // DIRSET (Data Direction Set) bitfields.
          struct { 
            Object *dirset; // [0:31] Port Data Direction Set
          } dirset; 

          // DIRTGL (Data Direction Toggle) bitfields.
          struct { 
            Object *dirtgl; // [0:31] Port Data Direction Toggle
          } dirtgl; 

          // OUT (Data Output Value) bitfields.
          struct { 
            Object *out; // [0:31] Port Data Output Value
          } out; 

          // OUTCLR (Data Output Value Clear) bitfields.
          struct { 
            Object *outclr; // [0:31] Port Data Output Value Clear
          } outclr; 

          // OUTSET (Data Output Value Set) bitfields.
          struct { 
            Object *outset; // [0:31] Port Data Output Value Set
          } outset; 

          // OUTTGL (Data Output Value Toggle) bitfields.
          struct { 
            Object *outtgl; // [0:31] Port Data Output Value Toggle
          } outtgl; 

          // IN (Data Input Value) bitfields.
          struct { 
            Object *in; // [0:31] Port Data Input Value
          } in; 

          // CTRL (Control) bitfields.
          struct { 
            Object *sampling; // [0:31] Input Sampling Mode
          } ctrl; 

          // WRCONFIG (Write Configuration) bitfields.
          struct { 
            Object *pinmask; // [0:15] Pin Mask for Multiple Pin Configuration
            Object *pmuxen; // [16:16] Peripheral Multiplexer Enable
            Object *inen; // [17:17] Input Enable
            Object *pullen; // [18:18] Pull Enable
            Object *drvstr; // [22:22] Output Driver Strength Selection
            Object *pmux; // [24:27] Peripheral Multiplexing
            Object *wrpmux; // [28:28] Write PMUX
            Object *wrpincfg; // [30:30] Write PINCFG
            Object *hwsel; // [31:31] Half-Word Select
          } wrconfig; 

          // PMUX0_ (Peripheral Multiplexing n - Group 0) bitfields.
          struct { 
            Object *pmuxe; // [0:3] Peripheral Multiplexing Even
            Object *pmuxo; // [4:7] Peripheral Multiplexing Odd
          } pmux0_; 

          // PMUX1_ (Peripheral Multiplexing n - Group 1) bitfields.
          struct { 
          } pmux1_; 

          // PINCFG0_ (Pin Configuration n - Group 0) bitfields.
          struct { 
            Object *pmuxen; // [0:0] Peripheral Multiplexer Enable
            Object *inen; // [1:1] Input Enable
            Object *pullen; // [2:2] Pull Enable
            Object *drvstr; // [6:6] Output Driver Strength Selection
          } pincfg0_; 

          // PINCFG1_ (Pin Configuration n - Group 1) bitfields.
          struct { 
          } pincfg1_; 
        } fld;
      } samd21;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} SAMDPORTState;

// ----------------------------------------------------------------------------

#endif /* SAMD_PORT_H_ */
