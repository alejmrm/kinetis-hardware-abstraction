/*****************************************************************************************************************************************************
*
*  MCU_SIMDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU system integration module driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_SIM_DRIVER_H
#define MCU_SIM_DRIVER_H

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
class SIMDriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the system integration module peripheral driver class.
   */
  SIMDriver(void);
  ~SIMDriver(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the MCU system integration module register structure.
   */
  static SIM_MemMapPtr simReg;
};

#endif
