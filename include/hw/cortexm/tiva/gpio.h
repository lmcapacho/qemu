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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TIVA_GPIO_H_
#define TIVA_GPIO_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/tiva/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_TIVA_GPIO_A DEVICE_PATH_TIVA "GPIOA"
#define DEVICE_PATH_TIVA_GPIO_B DEVICE_PATH_TIVA "GPIOB"
#define DEVICE_PATH_TIVA_GPIO_C DEVICE_PATH_TIVA "GPIOC"
#define DEVICE_PATH_TIVA_GPIO_D DEVICE_PATH_TIVA "GPIOD"
#define DEVICE_PATH_TIVA_GPIO_E DEVICE_PATH_TIVA "GPIOE"
#define DEVICE_PATH_TIVA_GPIO_F DEVICE_PATH_TIVA "GPIOF"

// ----------------------------------------------------------------------------

typedef enum {
    // TODO: keep this list in ascending order.
    TM_PORT_GPIOA,
	TM_PORT_GPIOB,
    TM_PORT_GPIOC,
    TM_PORT_GPIOD,
    TM_PORT_GPIOE,
    TM_PORT_GPIOF,
    TM_PORT_GPIO_UNDEFINED = 0xFF,
} tm_gpio_index_t;

#define TM_GPIO_PIN_COUNT    (32)

// ----------------------------------------------------------------------------

#define TYPE_TM_GPIO TYPE_TM_PREFIX "gpio" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_TM_GPIO_PARENT TYPE_PERIPHERAL
typedef PeripheralClass TMGPIOParentClass;
typedef PeripheralState TMGPIOParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define TM_GPIO_GET_CLASS(obj) \
    OBJECT_GET_CLASS(TMGPIOClass, (obj), TYPE_TM_GPIO)
#define TM_GPIO_CLASS(klass) \
    OBJECT_CLASS_CHECK(TMGPIOClass, (klass), TYPE_TM_GPIO)

typedef struct {
    // private: 
    TMGPIOParentClass parent_class;
    // public: 

    // None, so far.
} TMGPIOClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define TM_GPIO_STATE(obj) \
    OBJECT_CHECK(TMGPIOState, (obj), TYPE_TM_GPIO)

typedef struct {
    // private:
    TMGPIOParentState parent_obj;
    // public:

    const TIVACapabilities *capabilities;
	
    tm_gpio_index_t port_index;
    
    // TM4C GPIO (Register map for GPIO peripheral) registers.
    struct { 
      Object *data; // 0x000003FC (GPIO Data) 
      Object *dir; // 0x00000400 (GPIO Direction) 
      Object *is; // 0x00000404 (GPIO Interrupt Sense) 
      Object *ibe; // 0x00000408 (GPIO Interrupt Both Edges) 
      Object *iev; // 0x0000040C (GPIO Interrupt Event) 
      Object *im; // 0x00000410 (GPIO Interrupt Mask) 
      Object *ris; // 0x00000414 (GPIO Raw Interrupt Status) 
      Object *mis; // 0x00000418 (GPIO Masked Interrupt Status) 
      Object *icr; // 0x0000041C (GPIO Interrupt Clear) 
      Object *afsel; // 0x00000420 (GPIO Alternate Function Select) 
      Object *dr2r; // 0x00000500 (GPIO 2-mA Drive Select) 
      Object *dr4r; // 0x00000504 (GPIO 4-mA Drive Select) 
      Object *dr8r; // 0x00000508 (GPIO 8-mA Drive Select) 
      Object *odr; // 0x0000050C (GPIO Open Drain Select) 
      Object *pur; // 0x00000510 (GPIO Pull-Up Select) 
      Object *pdr; // 0x00000514 (GPIO Pull-Down Select) 
      Object *slr; // 0x00000518 (GPIO Slew Rate Control Select) 
      Object *den; // 0x0000051C (GPIO Digital Enable) 
      Object *lock; // 0x00000520 (GPIO Lock) 
      Object *cr; // 0x00000524 (GPIO Commit) 
      Object *amsel; // 0x00000528 (GPIO Analog Mode Select) 
      Object *pctl; // 0x0000052C (GPIO Port Control) 
      Object *adcctl; // 0x00000530 (GPIO ADC Control) 
      Object *dmactl; // 0x00000534 (GPIO DMA Control) 
    } reg;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // TM4C GPIO (Register map for GPIO peripheral) registers.
        struct { 
          Object *data; // 0x000003FC (GPIO Data) 
          Object *dir; // 0x00000400 (GPIO Direction) 
          Object *is; // 0x00000404 (GPIO Interrupt Sense) 
          Object *ibe; // 0x00000408 (GPIO Interrupt Both Edges) 
          Object *iev; // 0x0000040C (GPIO Interrupt Event) 
          Object *im; // 0x00000410 (GPIO Interrupt Mask) 
          Object *ris; // 0x00000414 (GPIO Raw Interrupt Status) 
          Object *mis; // 0x00000418 (GPIO Masked Interrupt Status) 
          Object *icr; // 0x0000041C (GPIO Interrupt Clear) 
          Object *afsel; // 0x00000420 (GPIO Alternate Function Select) 
          Object *dr2r; // 0x00000500 (GPIO 2-mA Drive Select) 
          Object *dr4r; // 0x00000504 (GPIO 4-mA Drive Select) 
          Object *dr8r; // 0x00000508 (GPIO 8-mA Drive Select) 
          Object *odr; // 0x0000050C (GPIO Open Drain Select) 
          Object *pur; // 0x00000510 (GPIO Pull-Up Select) 
          Object *pdr; // 0x00000514 (GPIO Pull-Down Select) 
          Object *slr; // 0x00000518 (GPIO Slew Rate Control Select) 
          Object *den; // 0x0000051C (GPIO Digital Enable) 
          Object *lock; // 0x00000520 (GPIO Lock) 
          Object *cr; // 0x00000524 (GPIO Commit) 
          Object *amsel; // 0x00000528 (GPIO Analog Mode Select) 
          Object *pctl; // 0x0000052C (GPIO Port Control) 
          Object *adcctl; // 0x00000530 (GPIO ADC Control) 
          Object *dmactl; // 0x00000534 (GPIO DMA Control) 
        } reg;

        struct { 

          // DATA (GPIO Data) bitfields.
          struct { 
          } data; 

          // DIR (GPIO Direction) bitfields.
          struct { 
          } dir; 

          // IS (GPIO Interrupt Sense) bitfields.
          struct { 
          } is; 

          // IBE (GPIO Interrupt Both Edges) bitfields.
          struct { 
          } ibe; 

          // IEV (GPIO Interrupt Event) bitfields.
          struct { 
          } iev; 

          // IM (GPIO Interrupt Mask) bitfields.
          struct { 
            Object *gpio_im_gpio; // [:NaN] GPIO Interrupt Mask Enable
          } im; 

          // RIS (GPIO Raw Interrupt Status) bitfields.
          struct { 
            Object *gpio_ris_gpio; // [:NaN] GPIO Interrupt Raw Status
          } ris; 

          // MIS (GPIO Masked Interrupt Status) bitfields.
          struct { 
            Object *gpio_mis_gpio; // [:NaN] GPIO Masked Interrupt Status
          } mis; 

          // ICR (GPIO Interrupt Clear) bitfields.
          struct { 
            Object *gpio_icr_gpio; // [:NaN] GPIO Interrupt Clear
          } icr; 

          // AFSEL (GPIO Alternate Function Select) bitfields.
          struct { 
          } afsel; 

          // DR2R (GPIO 2-mA Drive Select) bitfields.
          struct { 
          } dr2r; 

          // DR4R (GPIO 4-mA Drive Select) bitfields.
          struct { 
          } dr4r; 

          // DR8R (GPIO 8-mA Drive Select) bitfields.
          struct { 
          } dr8r; 

          // ODR (GPIO Open Drain Select) bitfields.
          struct { 
          } odr; 

          // PUR (GPIO Pull-Up Select) bitfields.
          struct { 
          } pur; 

          // PDR (GPIO Pull-Down Select) bitfields.
          struct { 
          } pdr; 

          // SLR (GPIO Slew Rate Control Select) bitfields.
          struct { 
          } slr; 

          // DEN (GPIO Digital Enable) bitfields.
          struct { 
          } den; 

          // LOCK (GPIO Lock) bitfields.
          struct { 
            Object *gpio_lock; // [:NaN] GPIO Lock
          } lock; 

          // CR (GPIO Commit) bitfields.
          struct { 
          } cr; 

          // AMSEL (GPIO Analog Mode Select) bitfields.
          struct { 
          } amsel; 

          // PCTL (GPIO Port Control) bitfields.
          struct { 
          } pctl; 

          // ADCCTL (GPIO ADC Control) bitfields.
          struct { 
          } adcctl; 

          // DMACTL (GPIO DMA Control) bitfields.
          struct { 
          } dmactl; 
        } fld;
      } tm4c;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} TMGPIOState;

// ----- Public ---------------------------------------------------------------

Object* tm_gpio_create(Object *parent, tm_gpio_index_t index);

Object* tm_gpio_get(int index);

// ----------------------------------------------------------------------------

#endif /* TM_GPIO_H_ */
