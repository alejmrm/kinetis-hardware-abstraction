/*****************************************************************************************************************************************************
*
*  CoreDriver.h  -  Copyright 2013, stokeware
*
*  This file contains the MCU core driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef CORE_DRIVER_H
#define CORE_DRIVER_H

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the core driver abstract base class.
 */
class CoreDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * This method is the pure virtual destructor for the core driver abstract base class.
   */
  virtual ~CoreDriver(void) = 0;
};

#endif
