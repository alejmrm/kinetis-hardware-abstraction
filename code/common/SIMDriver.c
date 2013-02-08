/*****************************************************************************************************************************************************
*
*  SIMDriver.c  -  This file contains the system integration module driver class implementation.
*
*  Copyright (c) 2012-2013, stokeware
*
*  Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above
*  copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
*  IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*****************************************************************************************************************************************************/
#include "MK40DZ10.h"
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
volatile uint32* SIMDriver::sysClkGateCtrlReg[SIMDriver::NUM_SYS_CLK_GATING_CTRL_REGS] = {&SIM_SCGC1, &SIM_SCGC2, &SIM_SCGC3, &SIM_SCGC4,
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
void SIMDriver::EnableSysClkGating(SIMDriver::sys_clk clk)
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
void SIMDriver::DisableSysClkGating(SIMDriver::sys_clk clk)
{
  /*
   * Clear the bit in the system clock gating control register corresponding to the specified system clock.
   */
  *sysClkGateCtrlReg[(uint8)clk >> 5] &= ~((uint32)1 << ((uint8)clk & 0x1F));
}
