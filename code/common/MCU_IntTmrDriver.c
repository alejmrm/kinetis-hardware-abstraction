/*****************************************************************************************************************************************************
*
*  MCU_IntTmrDriver.c  -  Copyright 2012, stokeware
*
*  This file contains the MCU periodic interrupt timer driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_IntTmrDriver.h"
#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is a pointer to the MCU periodic interrupt timer register structure, which encompasses all of the individual timers.
 */
PIT_MemMapPtr IntTmrDriver::tmrGroupReg = PIT_BASE_PTR;

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the periodic interrupt timer peripheral driver class.
 */
IntTmrDriver::IntTmrDriver(int_tmr tmr)
{
  this->tmr = tmr;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the periodic interrupt timer peripheral driver class.
 */
IntTmrDriver::~IntTmrDriver(void)
{
}
