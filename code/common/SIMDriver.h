/*****************************************************************************************************************************************************
*
*  SIMDriver.h  -  Copyright 2012-2013, stokeware
*
*  This file contains the system integration module driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef SIM_DRIVER_H
#define SIM_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "CommonTypes.h"
#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Constant Definitions
*
*****************************************************************************************************************************************************/
/*
 * This constant defines the number of system clock gating control registers managed by the SIM.
 */
#define NUM_SYS_CLK_GATING_CTRL_REGS  7

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
/*
 * This type defines the system clocks whose operations are gated by the SIM.
 */
typedef enum  {
  SIM_SYS_CLK_PIT = ((5 * 32) + 23)    // Periodic interrupt timer
} sim_sys_clk;

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the SIM driver class. It is derived from the peripheral driver abstract base class.
 */
class SIMDriver : public PeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the SIM driver class.
   */
  SIMDriver(void);
  ~SIMDriver(void);
  /*
   * These static methods enable and disable gating to the specified system clock.
   */
  static void EnableSysClkGating(sim_sys_clk clk);
  static void DisableSysClkGating(sim_sys_clk clk);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the SIM register structure.
   */
  static SIM_MemMapPtr simRegs;
  /*
   * This static data member is an array of pointers to the system clock gating control registers.
   */
  static volatile uint32* sysClkGateCtrlRegs[NUM_SYS_CLK_GATING_CTRL_REGS];
};

#endif
