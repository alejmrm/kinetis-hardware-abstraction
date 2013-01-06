/*****************************************************************************************************************************************************
*
*  MCU_NVICDriver.h  -  Copyright 2012-2013, stokeware
*
*  This file contains the MCU nested vectored interrupt controller driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_NVIC_DRIVER_H
#define MCU_NVIC_DRIVER_H

#include "MCU_PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
/*
 * This type defines the interrupts managed by the NVIC.
 */
typedef enum  {
  NVIC_INTRPT_PIT_0 = 68,
  NVIC_INTRPT_PIT_1 = 69,
  NVIC_INTRPT_PIT_2 = 70,
  NVIC_INTRPT_PIT_3 = 71
} nvic_intrpt;

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
   * This static method enables the specified interrupt.
   */
  static void EnableIntrpt(nvic_intrpt intrpt);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the NVIC register structure.
   */
  static NVIC_MemMapPtr nvicReg;
};

#endif
