/*****************************************************************************************************************************************************
*
*  MCU_SysIntegDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU system integration module driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_SYS_INTEG_DRIVER_H
#define MCU_SYS_INTEG_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "MCU_PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the system integration module peripheral driver class. It is derived from the peripheral driver abstract base class.
 */
class SysIntegDriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the system integration module peripheral driver class.
   */
  SysIntegDriver(void);
  ~SysIntegDriver(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the MCU system integration module register structure.
   */
  static SIM_MemMapPtr sysIntegModuleReg;
};

#endif
