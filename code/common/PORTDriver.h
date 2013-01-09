/*****************************************************************************************************************************************************
*
*  PORTDriver.h  -  Copyright 2012-2013, stokeware
*
*  This file contains the port control and interrupt driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef PORT_DRIVER_H
#define PORT_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "MCU_PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
/*
 * This type defines the superset of available ports. In general, for a specific MCU, only some of the ports are available.
 */
typedef enum  {
  PORT_PORT_A = 0, PORT_PORT_B, PORT_PORT_C, PORT_PORT_D, PORT_PORT_E,
  NUM_PORT_PORTS
} port_port;
/*
 * This type defines the superset of pins that are available on each port. In general, for a specific MCU and port, only some of the pins are
 * available.
 */
typedef enum  {
  PORT_PORT_PIN_0 = 0, PORT_PORT_PIN_1,  PORT_PORT_PIN_2,  PORT_PORT_PIN_3,  PORT_PORT_PIN_4,  PORT_PORT_PIN_5,  PORT_PORT_PIN_6,  PORT_PORT_PIN_7,
  PORT_PORT_PIN_8,     PORT_PORT_PIN_9,  PORT_PORT_PIN_10, PORT_PORT_PIN_11, PORT_PORT_PIN_12, PORT_PORT_PIN_13, PORT_PORT_PIN_14, PORT_PORT_PIN_15,
  PORT_PORT_PIN_16,    PORT_PORT_PIN_17, PORT_PORT_PIN_18, PORT_PORT_PIN_19, PORT_PORT_PIN_20, PORT_PORT_PIN_21, PORT_PORT_PIN_22, PORT_PORT_PIN_23,
  PORT_PORT_PIN_24,    PORT_PORT_PIN_25, PORT_PORT_PIN_26, PORT_PORT_PIN_27, PORT_PORT_PIN_28, PORT_PORT_PIN_29, PORT_PORT_PIN_30, PORT_PORT_PIN_31,
  NUM_PORT_PORT_PINS
} port_port_pin;
/*
 * This type defines the superset of available port pins. In general, for a specific MCU, only some of the pins are available.
 */
typedef enum  {
  /*
   * Port A.
   */
  PORT_PIN_A0 = 0, PORT_PIN_A1,  PORT_PIN_A2,  PORT_PIN_A3,  PORT_PIN_A4,  PORT_PIN_A5,  PORT_PIN_A6,  PORT_PIN_A7,
  PORT_PIN_A8,     PORT_PIN_A9,  PORT_PIN_A10, PORT_PIN_A11, PORT_PIN_A12, PORT_PIN_A13, PORT_PIN_A14, PORT_PIN_A15,
  PORT_PIN_A16,    PORT_PIN_A17, PORT_PIN_A18, PORT_PIN_A19, PORT_PIN_A20, PORT_PIN_A21, PORT_PIN_A22, PORT_PIN_A23,
  PORT_PIN_A24,    PORT_PIN_A25, PORT_PIN_A26, PORT_PIN_A27, PORT_PIN_A28, PORT_PIN_A29, PORT_PIN_A30, PORT_PIN_A31,
  /*
   * Port B.
   */
  PORT_PIN_B0,     PORT_PIN_B1,  PORT_PIN_B2,  PORT_PIN_B3,  PORT_PIN_B4,  PORT_PIN_B5,  PORT_PIN_B6,  PORT_PIN_B7,
  PORT_PIN_B8,     PORT_PIN_B9,  PORT_PIN_B10, PORT_PIN_B11, PORT_PIN_B12, PORT_PIN_B13, PORT_PIN_B14, PORT_PIN_B15,
  PORT_PIN_B16,    PORT_PIN_B17, PORT_PIN_B18, PORT_PIN_B19, PORT_PIN_B20, PORT_PIN_B21, PORT_PIN_B22, PORT_PIN_B23,
  PORT_PIN_B24,    PORT_PIN_B25, PORT_PIN_B26, PORT_PIN_B27, PORT_PIN_B28, PORT_PIN_B29, PORT_PIN_B30, PORT_PIN_B31,
  /*
   * Port C.
   */
  PORT_PIN_C0,     PORT_PIN_C1,  PORT_PIN_C2,  PORT_PIN_C3,  PORT_PIN_C4,  PORT_PIN_C5,  PORT_PIN_C6,  PORT_PIN_C7,
  PORT_PIN_C8,     PORT_PIN_C9,  PORT_PIN_C10, PORT_PIN_C11, PORT_PIN_C12, PORT_PIN_C13, PORT_PIN_C14, PORT_PIN_C15,
  PORT_PIN_C16,    PORT_PIN_C17, PORT_PIN_C18, PORT_PIN_C19, PORT_PIN_C20, PORT_PIN_C21, PORT_PIN_C22, PORT_PIN_C23,
  PORT_PIN_C24,    PORT_PIN_C25, PORT_PIN_C26, PORT_PIN_C27, PORT_PIN_C28, PORT_PIN_C29, PORT_PIN_C30, PORT_PIN_C31,
  /*
   * Port D.
   */
  PORT_PIN_D0,     PORT_PIN_D1,  PORT_PIN_D2,  PORT_PIN_D3,  PORT_PIN_D4,  PORT_PIN_D5,  PORT_PIN_D6,  PORT_PIN_D7,
  PORT_PIN_D8,     PORT_PIN_D9,  PORT_PIN_D10, PORT_PIN_D11, PORT_PIN_D12, PORT_PIN_D13, PORT_PIN_D14, PORT_PIN_D15,
  PORT_PIN_D16,    PORT_PIN_D17, PORT_PIN_D18, PORT_PIN_D19, PORT_PIN_D20, PORT_PIN_D21, PORT_PIN_D22, PORT_PIN_D23,
  PORT_PIN_D24,    PORT_PIN_D25, PORT_PIN_D26, PORT_PIN_D27, PORT_PIN_D28, PORT_PIN_D29, PORT_PIN_D30, PORT_PIN_D31,
  /*
   * Port E.
   */
  PORT_PIN_E0,     PORT_PIN_E1,  PORT_PIN_E2,  PORT_PIN_E3,  PORT_PIN_E4,  PORT_PIN_E5,  PORT_PIN_E6,  PORT_PIN_E7,
  PORT_PIN_E8,     PORT_PIN_E9,  PORT_PIN_E10, PORT_PIN_E11, PORT_PIN_E12, PORT_PIN_E13, PORT_PIN_E14, PORT_PIN_E15,
  PORT_PIN_E16,    PORT_PIN_E17, PORT_PIN_E18, PORT_PIN_E19, PORT_PIN_E20, PORT_PIN_E21, PORT_PIN_E22, PORT_PIN_E23,
  PORT_PIN_E24,    PORT_PIN_E25, PORT_PIN_E26, PORT_PIN_E27, PORT_PIN_E28, PORT_PIN_E29, PORT_PIN_E30, PORT_PIN_E31
} port_pin;
/*
 * This type defines the port multiplexing modes for which the pins can be configured.
 */
typedef enum  {
  PORT_PIN_MUX_MODE_DISABLED_ANALOG = 0,
  PORT_PIN_MUX_MODE_ALT_1_GPIO      = 1,
  PORT_PIN_MUX_MODE_ALT_2           = 2,
  PORT_PIN_MUX_MODE_ALT_3           = 3,
  PORT_PIN_MUX_MODE_ALT_4           = 4,
  PORT_PIN_MUX_MODE_ALT_5           = 5,
  PORT_PIN_MUX_MODE_ALT_6           = 6,
  PORT_PIN_MUX_MODE_ALT_7           = 7
} port_pin_mux_mode;
/*
 * This type defines the port interrupt and DMA modes for which the pins can be configured.
 */
typedef enum  {
  PORT_PIN_INT_DMA_MODE_DISABLED         = 0,
  PORT_PIN_INT_DMA_MODE_DMA_RISING_EDGE  = 1,
  PORT_PIN_INT_DMA_MODE_DMA_FALLING_EDGE = 2,
  PORT_PIN_INT_DMA_MODE_DMA_EITHER_EDGE  = 3,
  PORT_PIN_INT_DMA_MODE_INT_LVL_LO       = 8,
  PORT_PIN_INT_DMA_MODE_INT_RISING_EDGE  = 9,
  PORT_PIN_INT_DMA_MODE_INT_FALLING_EDGE = 10,
  PORT_PIN_INT_DMA_MODE_INT_EITHER_EDGE  = 11,
  PORT_PIN_INT_DMA_MODE_INT_LVL_HI       = 12
} port_pin_int_dma_mode;

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the PORT driver class. It is derived from the peripheral driver abstract base class.
 */
class PORTDriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the PORT driver class.
   */
  PORTDriver(port_pin pin);
  ~PORTDriver(void);
  /*
   * This method clears the interrupt status for the pin managed by the class instance.
   */
  void ClearIntStatus(void);
  /*
   * This method configures the multiplexing mode for the pin managed by the class instance.
   */
  void SetMuxMode(port_pin_mux_mode mode);
  /*
   * This method configures the interrupt and DMA mode for the pin managed by the class instance.
   */
  void SetIntDmaMode(port_pin_int_dma_mode mode);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This data member is the port corresponding to the pin managed by the class instance.
   */
  port_port port;
  /*
   * This data member is the port pin corresponding to the pin managed by the class instance.
   */
  port_port_pin portPin;
  /*
   * This static data member is an array containing pointers to the PORT register structures for each of the ports.
   */
  static PORT_MemMapPtr portRegs[NUM_PORT_PORTS];
  /*
   * This data member is a pointer to the PORT register structure for the port managed by the class instance.
   */
  PORT_MemMapPtr portReg;
};

#endif
