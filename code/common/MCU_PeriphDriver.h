/*****************************************************************************************************************************************************
*
*  MCU_PeriphDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU peripheral driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_PERIPH_DRIVER_H
#define MCU_PERIPH_DRIVER_H

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the MCU peripheral driver abstract base class.
 */
class MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * This method is the pure virtual destructor for the peripheral driver abstract base class.
   */
  virtual ~MCUPeriphDriver(void) = 0;
};

#endif
