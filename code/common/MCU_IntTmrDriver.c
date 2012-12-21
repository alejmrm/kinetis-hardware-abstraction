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
PIT_MemMapPtr IntTmrDriver::tmrModuleReg = PIT_BASE_PTR;

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
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the periodic interrupt timer module.
 */
void IntTmrDriver::EnableModule(void)
{
  /*
   * Clear the module disable bit in the periodic interrupt timer module control register.
   */
  tmrModuleReg->MCR &= ~(PIT_MCR_MDIS_MASK);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method sets the timeout period for the timer managed by the class instance.
 */
void IntTmrDriver::SetPeriod(uint32 period)
{
  /*
   * Set the load value register for the timer to the specified period value.
   */
  tmrModuleReg->CHANNEL[(uint8)tmr].LDVAL = period;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method provides the present count value for the timer managed by the class instance.
 */
uint32 IntTmrDriver::GetCnt(void)
{
  /*
   * Return the contents of the current timer value register for the timer.
   */
  return tmrModuleReg->CHANNEL[(uint8)tmr].CVAL;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method enables the timer managed by the class instance.
 */
void IntTmrDriver::EnableTmr(void)
{
  tmrModuleReg->CHANNEL[(uint8)tmr].TCTRL |= PIT_TCTRL_TEN_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method disables the timer managed by the class instance.
 */
void IntTmrDriver::DisableTmr(void)
{
  tmrModuleReg->CHANNEL[(uint8)tmr].TCTRL &= ~(PIT_TCTRL_TEN_MASK);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method enables the interrupt corresponding to the timer managed by the class instance.
 */
void IntTmrDriver::EnableInt(void)
{
  tmrModuleReg->CHANNEL[(uint8)tmr].TCTRL |= PIT_TCTRL_TIE_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method disables the interrupt corresponding to the timer managed by the class instance.
 */
void IntTmrDriver::DisableInt(void)
{
  tmrModuleReg->CHANNEL[(uint8)tmr].TCTRL &= ~(PIT_TCTRL_TIE_MASK);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method indicates whether the interrupt corresponding to the timer managed by the class instance is pending.
 */
bool IntTmrDriver::IntIsPending(void)
{
  return ((tmrModuleReg->CHANNEL[(uint8)tmr].TFLG & PIT_TFLG_TIF_MASK) != 0) ? true : false;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method clears the interrupt corresponding to the timer managed by the class instance.
 */
void IntTmrDriver::ClearInt(void)
{
  tmrModuleReg->CHANNEL[(uint8)tmr].TFLG |= PIT_TFLG_TIF_MASK;
}
