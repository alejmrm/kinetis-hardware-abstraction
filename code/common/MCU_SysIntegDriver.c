/*****************************************************************************************************************************************************
*
*  MCU_SysIntegDriver.c  -  Copyright 2012, stokeware
*
*  This file contains the MCU system integration module driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_SysIntegDriver.h"
#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static data member is a pointer to the MCU system integration module register structure.
 */
SIM_MemMapPtr sysIntegModuleReg = SIM_BASE_PTR;

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the system integration module peripheral driver class.
 */
SysIntegDriver::SysIntegDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the system integration module peripheral driver class.
 */
SysIntegDriver::~SysIntegDriver(void)
{
}
