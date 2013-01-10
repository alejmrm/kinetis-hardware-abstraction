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
#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
namespace GPIOType  {
  /*
   * This type defines the superset of available GPIO ports. In general, for a specific MCU, only some of the ports are available.
   */
  typedef enum  {
    PORT_A = 0, PORT_B, PORT_C, PORT_D, PORT_E,
    NUM_PORTS
  } port;
  /*
   * This type defines the superset of pins that are available on each GPIO port. In general, for a specific MCU and port, only some of the pins are
   * available.
   */
  typedef enum  {
    PORT_PIN_0 = 0, PORT_PIN_1,  PORT_PIN_2,  PORT_PIN_3,  PORT_PIN_4,  PORT_PIN_5,  PORT_PIN_6,  PORT_PIN_7,
    PORT_PIN_8,     PORT_PIN_9,  PORT_PIN_10, PORT_PIN_11, PORT_PIN_12, PORT_PIN_13, PORT_PIN_14, PORT_PIN_15,
    PORT_PIN_16,    PORT_PIN_17, PORT_PIN_18, PORT_PIN_19, PORT_PIN_20, PORT_PIN_21, PORT_PIN_22, PORT_PIN_23,
    PORT_PIN_24,    PORT_PIN_25, PORT_PIN_26, PORT_PIN_27, PORT_PIN_28, PORT_PIN_29, PORT_PIN_30, PORT_PIN_31,
    NUM_PORT_PINS
  } port_pin;
  /*
   * This type defines the superset of available GPIO pins. In general, for a specific MCU, only some of the pins are available.
   */
  typedef enum  {
    /*
     * Port A.
     */
    PIN_A0 = 0, PIN_A1,  PIN_A2,  PIN_A3,  PIN_A4,  PIN_A5,  PIN_A6,  PIN_A7,
    PIN_A8,     PIN_A9,  PIN_A10, PIN_A11, PIN_A12, PIN_A13, PIN_A14, PIN_A15,
    PIN_A16,    PIN_A17, PIN_A18, PIN_A19, PIN_A20, PIN_A21, PIN_A22, PIN_A23,
    PIN_A24,    PIN_A25, PIN_A26, PIN_A27, PIN_A28, PIN_A29, PIN_A30, PIN_A31,
    /*
     * Port B.
     */
    PIN_B0,     PIN_B1,  PIN_B2,  PIN_B3,  PIN_B4,  PIN_B5,  PIN_B6,  PIN_B7,
    PIN_B8,     PIN_B9,  PIN_B10, PIN_B11, PIN_B12, PIN_B13, PIN_B14, PIN_B15,
    PIN_B16,    PIN_B17, PIN_B18, PIN_B19, PIN_B20, PIN_B21, PIN_B22, PIN_B23,
    PIN_B24,    PIN_B25, PIN_B26, PIN_B27, PIN_B28, PIN_B29, PIN_B30, PIN_B31,
    /*
     * Port C.
     */
    PIN_C0,     PIN_C1,  PIN_C2,  PIN_C3,  PIN_C4,  PIN_C5,  PIN_C6,  PIN_C7,
    PIN_C8,     PIN_C9,  PIN_C10, PIN_C11, PIN_C12, PIN_C13, PIN_C14, PIN_C15,
    PIN_C16,    PIN_C17, PIN_C18, PIN_C19, PIN_C20, PIN_C21, PIN_C22, PIN_C23,
    PIN_C24,    PIN_C25, PIN_C26, PIN_C27, PIN_C28, PIN_C29, PIN_C30, PIN_C31,
    /*
     * Port D.
     */
    PIN_D0,     PIN_D1,  PIN_D2,  PIN_D3,  PIN_D4,  PIN_D5,  PIN_D6,  PIN_D7,
    PIN_D8,     PIN_D9,  PIN_D10, PIN_D11, PIN_D12, PIN_D13, PIN_D14, PIN_D15,
    PIN_D16,    PIN_D17, PIN_D18, PIN_D19, PIN_D20, PIN_D21, PIN_D22, PIN_D23,
    PIN_D24,    PIN_D25, PIN_D26, PIN_D27, PIN_D28, PIN_D29, PIN_D30, PIN_D31,
    /*
     * Port E.
     */
    PIN_E0,     PIN_E1,  PIN_E2,  PIN_E3,  PIN_E4,  PIN_E5,  PIN_E6,  PIN_E7,
    PIN_E8,     PIN_E9,  PIN_E10, PIN_E11, PIN_E12, PIN_E13, PIN_E14, PIN_E15,
    PIN_E16,    PIN_E17, PIN_E18, PIN_E19, PIN_E20, PIN_E21, PIN_E22, PIN_E23,
    PIN_E24,    PIN_E25, PIN_E26, PIN_E27, PIN_E28, PIN_E29, PIN_E30, PIN_E31
  } pin;
  /*
   * This type defines the GPIO pin directions.
   */
  typedef enum  {
    PIN_DIR_IN = 0, PIN_DIR_OUT
  } pin_dir;
  /*
   * This type defines the GPIO pin input and output levels.
   */
  typedef enum  {
    PIN_LVL_LO = 0, PIN_LVL_HI
  } pin_lvl;
}

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the GPIO driver class. It is derived from the MCU peripheral driver abstract base class.
 */
class GPIODriver : public PeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the GPIO driver class.
   */
  GPIODriver(GPIOType::pin pin);
  ~GPIODriver(void);
  /*
   * This method sets the direction of the pin managed by the class instance.
   */
  void SetDir(GPIOType::pin_dir dir);
  /*
   * This method sets the level of the pin managed by the class instance.
   */
  void SetLvl(GPIOType::pin_lvl lvl);
  /*
   * This method provides the level of the pin managed by the class instance.
   */
  GPIOType::pin_lvl GetLvl(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This data member is the GPIO port corresponding to the pin managed by the class instance.
   */
  GPIOType::port port;
  /*
   * This data member is the GPIO port pin corresponding to the pin managed by the class instance.
   */
  GPIOType::port_pin portPin;
  /*
   * This static data member is an array containing pointers to the MCU register structures for each of the GPIO ports.
   */
  static GPIO_MemMapPtr moduleReg[GPIOType::NUM_PORTS];
  /*
   * This data member is a pointer to the GPIO port register structure for the port managed by the class instance.
   */
  GPIO_MemMapPtr portReg;
};

#endif
