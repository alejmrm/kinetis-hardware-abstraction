/*****************************************************************************************************************************************************
*
*  MCU_IOPortDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU I/O port driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_IO_PORT_DRIVER_H
#define MCU_IO_PORT_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "MCU_PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
/*
 * This type defines the superset of available I/O ports. In general, for a specific MCU, only some of the ports are available.
 */
typedef enum  {
  IO_PORT_A = 0, IO_PORT_B, IO_PORT_C, IO_PORT_D, IO_PORT_E,
  NUM_IO_PORTS
} io_port;
/*
 * This type defines the superset of I/O pins that are available on I/O ports. In general, for a specific MCU and port, only some of the pins are
 * available.
 */
typedef enum  {
  IO_PORT_PIN_0 = 0, IO_PORT_PIN_1,  IO_PORT_PIN_2,  IO_PORT_PIN_3,  IO_PORT_PIN_4,  IO_PORT_PIN_5,  IO_PORT_PIN_6,  IO_PORT_PIN_7,
  IO_PORT_PIN_8,     IO_PORT_PIN_9,  IO_PORT_PIN_10, IO_PORT_PIN_11, IO_PORT_PIN_12, IO_PORT_PIN_13, IO_PORT_PIN_14, IO_PORT_PIN_15,
  IO_PORT_PIN_16,    IO_PORT_PIN_17, IO_PORT_PIN_18, IO_PORT_PIN_19, IO_PORT_PIN_20, IO_PORT_PIN_21, IO_PORT_PIN_22, IO_PORT_PIN_23,
  IO_PORT_PIN_24,    IO_PORT_PIN_25, IO_PORT_PIN_26, IO_PORT_PIN_27, IO_PORT_PIN_28, IO_PORT_PIN_29, IO_PORT_PIN_30, IO_PORT_PIN_31
} io_port_pin;

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the I/O port peripheral driver class. It is derived from the peripheral driver abstract base class.
 */
class IOPortDriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the I/O port peripheral driver class.
   */
  IOPortDriver(io_port port);
  ~IOPortDriver(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This data member is the I/O port managed by the class instance.
   */
  io_port port;
};

#endif
