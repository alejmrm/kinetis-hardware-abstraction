/*****************************************************************************************************************************************************
*
*  MCU_NVICDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU nested vectored interrupt controller driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_NVIC_DRIVER_H
#define MCU_NVIC_DRIVER_H

#include "MCU_PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the NVIC driver class. It is derived from the peripheral driver abstract base class.
 */
class NVICDriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the NVIC driver class.
   */
  NVICDriver(void);
  ~NVICDriver(void);
  /*
   * This static method initializes the NVIC module.
   */
  static void InitModule(void);
};

#endif
