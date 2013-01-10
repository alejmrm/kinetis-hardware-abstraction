/*****************************************************************************************************************************************************
*
*  PeriphDriver.h  -  Copyright 2012-2013, stokeware
*
*  This file contains the MCU peripheral driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef PERIPH_DRIVER_H
#define PERIPH_DRIVER_H

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the peripheral driver abstract base class.
 */
class PeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * This method is the pure virtual destructor for the peripheral driver abstract base class.
   */
  virtual ~PeriphDriver(void) = 0;
};

#endif
