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
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the SIM driver class. It is derived from the peripheral driver abstract base class.
 */
class SIMDriver : public PeriphDriver
{
  /*********************
   * Private Constants
   ********************/
  private:
  /*
   * This constant defines the number of system clock gating control registers managed by the SIM.
   */
  enum  {
    NUM_SYS_CLK_GATING_CTRL_REGS = 7
  };

  /****************
   * Public Types
   ***************/
  public:
  /*
   * This type defines the system clocks whose operations are gated by the SIM.
   */
  typedef enum  {
    SYS_CLK_SLCD  = (((3 - 1) * 32) + 30),
    SYS_CLK_PORTA = (((5 - 1) * 32) + 9),
    SYS_CLK_PORTB = (((5 - 1) * 32) + 10),
    SYS_CLK_PORTC = (((5 - 1) * 32) + 11),
    SYS_CLK_PORTD = (((5 - 1) * 32) + 12),
    SYS_CLK_PORTE = (((5 - 1) * 32) + 13),
    SYS_CLK_PIT   = (((6 - 1) * 32) + 23)
  } sys_clk;

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
  static void EnableSysClkGating(SIMDriver::sys_clk clk);
  static void DisableSysClkGating(SIMDriver::sys_clk clk);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the SIM register structure.
   */
  static SIM_MemMapPtr moduleReg;
  /*
   * This static data member is an array of pointers to the system clock gating control registers.
   */
  static volatile uint32* sysClkGateCtrlReg[SIMDriver::NUM_SYS_CLK_GATING_CTRL_REGS];
};

#endif
