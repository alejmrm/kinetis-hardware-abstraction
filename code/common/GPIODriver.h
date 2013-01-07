/*****************************************************************************************************************************************************
*
*  GPIODriver.h  -  Copyright 2012-2013, stokeware
*
*  This file contains the general purpose I/O driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "MCU_PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
/*
 * This type defines the superset of available GPIO ports. In general, for a specific MCU, only some of the ports are available.
 */
typedef enum  {
  GPIO_PORT_A = 0, GPIO_PORT_B, GPIO_PORT_C, GPIO_PORT_D, GPIO_PORT_E,
  NUM_GPIO_PORTS
} gpio_port;
/*
 * This type defines the superset of pins that are available on each GPIO port. In general, for a specific MCU and port, only some of the pins are
 * available.
 */
typedef enum  {
  GPIO_PORT_PIN_0 = 0, GPIO_PORT_PIN_1,  GPIO_PORT_PIN_2,  GPIO_PORT_PIN_3,  GPIO_PORT_PIN_4,  GPIO_PORT_PIN_5,  GPIO_PORT_PIN_6,  GPIO_PORT_PIN_7,
  GPIO_PORT_PIN_8,     GPIO_PORT_PIN_9,  GPIO_PORT_PIN_10, GPIO_PORT_PIN_11, GPIO_PORT_PIN_12, GPIO_PORT_PIN_13, GPIO_PORT_PIN_14, GPIO_PORT_PIN_15,
  GPIO_PORT_PIN_16,    GPIO_PORT_PIN_17, GPIO_PORT_PIN_18, GPIO_PORT_PIN_19, GPIO_PORT_PIN_20, GPIO_PORT_PIN_21, GPIO_PORT_PIN_22, GPIO_PORT_PIN_23,
  GPIO_PORT_PIN_24,    GPIO_PORT_PIN_25, GPIO_PORT_PIN_26, GPIO_PORT_PIN_27, GPIO_PORT_PIN_28, GPIO_PORT_PIN_29, GPIO_PORT_PIN_30, GPIO_PORT_PIN_31,
  NUM_GPIO_PORT_PINS
} gpio_port_pin;
/*
 * This type defines the superset of available GPIO pins. In general, for a specific MCU, only some of the pins are available.
 */
typedef enum  {
  /*
   * Port A.
   */
  GPIO_PIN_A0 = 0, GPIO_PIN_A1,  GPIO_PIN_A2,  GPIO_PIN_A3,  GPIO_PIN_A4,  GPIO_PIN_A5,  GPIO_PIN_A6,  GPIO_PIN_A7,
  GPIO_PIN_A8,     GPIO_PIN_A9,  GPIO_PIN_A10, GPIO_PIN_A11, GPIO_PIN_A12, GPIO_PIN_A13, GPIO_PIN_A14, GPIO_PIN_A15,
  GPIO_PIN_A16,    GPIO_PIN_A17, GPIO_PIN_A18, GPIO_PIN_A19, GPIO_PIN_A20, GPIO_PIN_A21, GPIO_PIN_A22, GPIO_PIN_A23,
  GPIO_PIN_A24,    GPIO_PIN_A25, GPIO_PIN_A26, GPIO_PIN_A27, GPIO_PIN_A28, GPIO_PIN_A29, GPIO_PIN_A30, GPIO_PIN_A31,
  /*
   * Port B.
   */
  GPIO_PIN_B0,     GPIO_PIN_B1,  GPIO_PIN_B2,  GPIO_PIN_B3,  GPIO_PIN_B4,  GPIO_PIN_B5,  GPIO_PIN_B6,  GPIO_PIN_B7,
  GPIO_PIN_B8,     GPIO_PIN_B9,  GPIO_PIN_B10, GPIO_PIN_B11, GPIO_PIN_B12, GPIO_PIN_B13, GPIO_PIN_B14, GPIO_PIN_B15,
  GPIO_PIN_B16,    GPIO_PIN_B17, GPIO_PIN_B18, GPIO_PIN_B19, GPIO_PIN_B20, GPIO_PIN_B21, GPIO_PIN_B22, GPIO_PIN_B23,
  GPIO_PIN_B24,    GPIO_PIN_B25, GPIO_PIN_B26, GPIO_PIN_B27, GPIO_PIN_B28, GPIO_PIN_B29, GPIO_PIN_B30, GPIO_PIN_B31,
  /*
   * Port C.
   */
  GPIO_PIN_C0,     GPIO_PIN_C1,  GPIO_PIN_C2,  GPIO_PIN_C3,  GPIO_PIN_C4,  GPIO_PIN_C5,  GPIO_PIN_C6,  GPIO_PIN_C7,
  GPIO_PIN_C8,     GPIO_PIN_C9,  GPIO_PIN_C10, GPIO_PIN_C11, GPIO_PIN_C12, GPIO_PIN_C13, GPIO_PIN_C14, GPIO_PIN_C15,
  GPIO_PIN_C16,    GPIO_PIN_C17, GPIO_PIN_C18, GPIO_PIN_C19, GPIO_PIN_C20, GPIO_PIN_C21, GPIO_PIN_C22, GPIO_PIN_C23,
  GPIO_PIN_C24,    GPIO_PIN_C25, GPIO_PIN_C26, GPIO_PIN_C27, GPIO_PIN_C28, GPIO_PIN_C29, GPIO_PIN_C30, GPIO_PIN_C31,
  /*
   * Port D.
   */
  GPIO_PIN_D0,     GPIO_PIN_D1,  GPIO_PIN_D2,  GPIO_PIN_D3,  GPIO_PIN_D4,  GPIO_PIN_D5,  GPIO_PIN_D6,  GPIO_PIN_D7,
  GPIO_PIN_D8,     GPIO_PIN_D9,  GPIO_PIN_D10, GPIO_PIN_D11, GPIO_PIN_D12, GPIO_PIN_D13, GPIO_PIN_D14, GPIO_PIN_D15,
  GPIO_PIN_D16,    GPIO_PIN_D17, GPIO_PIN_D18, GPIO_PIN_D19, GPIO_PIN_D20, GPIO_PIN_D21, GPIO_PIN_D22, GPIO_PIN_D23,
  GPIO_PIN_D24,    GPIO_PIN_D25, GPIO_PIN_D26, GPIO_PIN_D27, GPIO_PIN_D28, GPIO_PIN_D29, GPIO_PIN_D30, GPIO_PIN_D31,
  /*
   * Port E.
   */
  GPIO_PIN_E0,     GPIO_PIN_E1,  GPIO_PIN_E2,  GPIO_PIN_E3,  GPIO_PIN_E4,  GPIO_PIN_E5,  GPIO_PIN_E6,  GPIO_PIN_E7,
  GPIO_PIN_E8,     GPIO_PIN_E9,  GPIO_PIN_E10, GPIO_PIN_E11, GPIO_PIN_E12, GPIO_PIN_E13, GPIO_PIN_E14, GPIO_PIN_E15,
  GPIO_PIN_E16,    GPIO_PIN_E17, GPIO_PIN_E18, GPIO_PIN_E19, GPIO_PIN_E20, GPIO_PIN_E21, GPIO_PIN_E22, GPIO_PIN_E23,
  GPIO_PIN_E24,    GPIO_PIN_E25, GPIO_PIN_E26, GPIO_PIN_E27, GPIO_PIN_E28, GPIO_PIN_E29, GPIO_PIN_E30, GPIO_PIN_E31
} gpio_pin;
/*
 * This type defines the GPIO pin directions.
 */
typedef enum  {
  GPIO_PIN_DIR_IN = 0, GPIO_PIN_DIR_OUT
} gpio_pin_dir;
/*
 * This type defines the GPIO pin input and output levels.
 */
typedef enum  {
  GPIO_PIN_LVL_LO = 0, GPIO_PIN_LVL_HI
} gpio_pin_lvl;

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the GPIO driver class. It is derived from the MCU peripheral driver abstract base class.
 */
class GPIODriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the GPIO driver class.
   */
  GPIODriver(gpio_pin pin);
  ~GPIODriver(void);
  /*
   * This method sets the direction of the pin managed by the class instance.
   */
  void SetDir(gpio_pin_dir dir);
  /*
   * This method sets the level of the pin managed by the class instance.
   */
  void SetLvl(gpio_pin_lvl lvl);
  /*
   * This method provides the level of the pin managed by the class instance.
   */
  gpio_pin_lvl GetLvl(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This data member is the GPIO port corresponding to the pin managed by the class instance.
   */
  gpio_port port;
  /*
   * This data member is the GPIO port pin corresponding to the pin managed by the class instance.
   */
  gpio_port_pin portPin;
  /*
   * This static data member is an array containing pointers to the MCU register structures for each of the GPIO ports.
   */
  static GPIO_MemMapPtr gpioPortRegs[NUM_GPIO_PORTS];
  /*
   * This data member is a pointer to the GPIO port register structure for the port managed by the class instance.
   */
  GPIO_MemMapPtr portReg;
};

#endif
