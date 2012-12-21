/*****************************************************************************************************************************************************
*
*  MCUIOPortDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU I/O port driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_IO_PORT_DRIVER_H
#define MCU_IO_PORT_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "MCUPeriphDriver.h"

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
  IO_PIN_0 = 0, IO_PIN_1,  IO_PIN_2,  IO_PIN_3,  IO_PIN_4,  IO_PIN_5,  IO_PIN_6,  IO_PIN_7,
  IO_PIN_8,     IO_PIN_9,  IO_PIN_10, IO_PIN_11, IO_PIN_12, IO_PIN_13, IO_PIN_14, IO_PIN_15,
  IO_PIN_16,    IO_PIN_17, IO_PIN_18, IO_PIN_19, IO_PIN_20, IO_PIN_21, IO_PIN_22, IO_PIN_23,
  IO_PIN_24,    IO_PIN_25, IO_PIN_26, IO_PIN_27, IO_PIN_28, IO_PIN_29, IO_PIN_30, IO_PIN_31
} io_pin;
/*
 * This type defines the I/O pin directions.
 */
typedef enum  {
  IO_PIN_DIR_IN = 0, IO_PIN_DIR_OUT
} io_pin_dir;
/*
 * This type defines the I/O pin input and output levels.
 */
typedef enum  {
  IO_PIN_LVL_LO = 0, IO_PIN_LVL_HI
} io_pin_lvl;

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the I/O port peripheral driver class. It is derived from the peripheral driver abstract base class.
 */
class MCUIOPortDriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * This method is the constructor for the I/O port peripheral driver class.
   */
  MCUIOPortDriver(io_port port);
  /*
   * This method is the destructor for the I/O port peripheral driver class.
   */
  ~MCUIOPortDriver(void);
  /*
   * This method sets the direction of the specified I/O pin.
   */
  void SetPinDir(io_pin pin, io_pin_dir dir);
  /*
   * This method sets the specified I/O pin to the specified level.
   */
  void SetPinLvl(io_pin pin, io_pin_lvl lvl);
  /*
   * This method provides the level of the specified I/O pin.
   */
  io_pin_lvl GetPinLvl(io_pin pin);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This data member is the I/O port managed by the class instance.
   */
  io_port port;
  /*
   *
   */
  static GPIO_MemMapPtr ioPortRegs[NUM_IO_PORTS];
  /*
   * This data member is a pointer to the I/O port register structure for the port managed by the class instance.
   */
  GPIO_MemMapPtr reg;
};

#endif
