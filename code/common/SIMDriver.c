/*****************************************************************************************************************************************************
*
*  SIMDriver.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the system integration module driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "CommonTypes.h"
#include "SIMDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static data member is a pointer to the SIM register structure.
 */
SIM_MemMapPtr SIMDriver::moduleReg = SIM_BASE_PTR;
/*
 * This static data member is an array of pointers to the system clock gating control registers.
 */
volatile uint32* SIMDriver::sysClkGateCtrlReg[SIMType::NUM_SYS_CLK_GATING_CTRL_REGS] = {&SIM_SCGC1, &SIM_SCGC2, &SIM_SCGC3, &SIM_SCGC4,
                                                                                        &SIM_SCGC5, &SIM_SCGC6, &SIM_SCGC7};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the SIM driver class.
 */
SIMDriver::SIMDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the SIM driver class.
 */
SIMDriver::~SIMDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables gating to the specified system clock.
 */
void SIMDriver::EnableSysClkGating(SIMType::sys_clk clk)
{
  /*
   * Set the bit in the system clock gating control register corresponding to the specified system clock.
   */
  *sysClkGateCtrlReg[(uint8)clk >> 5] |= ((uint32)1 << ((uint8)clk & 0x1F));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method disables gating to the specified system clock.
 */
void SIMDriver::DisableSysClkGating(SIMType::sys_clk clk)
{
  /*
   * Clear the bit in the system clock gating control register corresponding to the specified system clock.
   */
  *sysClkGateCtrlReg[(uint8)clk >> 5] &= ~((uint32)1 << ((uint8)clk & 0x1F));
}
