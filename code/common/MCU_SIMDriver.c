/*****************************************************************************************************************************************************
*
*  MCU_SIMDriver.c  -  Copyright 2012, stokeware
*
*  This file contains the system integration module driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_SIMDriver.h"
#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static data member is a pointer to the SIM register structure.
 */
SIM_MemMapPtr SIMDriver::simRegs = SIM_BASE_PTR;
/*
 * This static data member is an array of the system clock gating control registers.
 */
uint32 SIMDriver::sysClkGateCtrlRegs[NUM_SYS_CLK_GATING_CTRL_REGS] = {SIM_SCGC1, SIM_SCGC2, SIM_SCGC3, SIM_SCGC4, SIM_SCGC5, SIM_SCGC6, SIM_SCGC7};

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
