/*****************************************************************************************************************************************************
*
*  MCU_SIMDriver.c  -  Copyright 2012, stokeware
*
*  This file contains the MCU system integration module driver class implementation.
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
 * This static data member is a pointer to the MCU system integration module register structure.
 */
SIM_MemMapPtr simReg = SIM_BASE_PTR;

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the system integration module peripheral driver class.
 */
SIMDriver::SIMDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the system integration module peripheral driver class.
 */
SIMDriver::~SIMDriver(void)
{
}
