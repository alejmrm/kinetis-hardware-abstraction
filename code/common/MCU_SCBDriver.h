/*****************************************************************************************************************************************************
*
*  MCU_SCBDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU system control block driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_SCB_DRIVER_H
#define MCU_SCB_DRIVER_H

#include "MCU_PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the SCB driver class. It is derived from the peripheral driver abstract base class.
 */
class SCBDriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the SCB driver class.
   */
  SCBDriver(void);
  ~SCBDriver(void);
  /*
   * This static method initializes the SCB module.
   */
  static void InitModule(void);
};

#endif
