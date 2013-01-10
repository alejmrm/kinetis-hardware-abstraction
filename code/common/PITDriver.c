/*****************************************************************************************************************************************************
*
*  PITDriver.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the periodic interrupt timer driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "CommonTypes.h"
#include "PITDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is a pointer to the PIT register structure, which encompasses all of the individual timers.
 */
PIT_MemMapPtr PITDriver::moduleReg = PIT_BASE_PTR;

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the PIT driver class.
 */
PITDriver::PITDriver(PITType::tmr tmr)
{
  this->tmr = tmr;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the PIT driver class.
 */
PITDriver::~PITDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the PIT module.
 */
void PITDriver::EnableModule(void)
{
  /*
   * Clear the module disable bit in the PIT module control register.
   */
  moduleReg->MCR &= ~(PIT_MCR_MDIS_MASK);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method sets the timeout period for the timer managed by the class instance.
 */
void PITDriver::SetPeriod(uint32 period)
{
  /*
   * Set the load value register for the timer to the specified period value.
   */
  moduleReg->CHANNEL[(uint8)tmr].LDVAL = period;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method provides the present count value for the timer managed by the class instance.
 */
uint32 PITDriver::GetCnt(void)
{
  /*
   * Return the contents of the current timer value register for the timer.
   */
  return moduleReg->CHANNEL[(uint8)tmr].CVAL;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method enables the timer managed by the class instance.
 */
void PITDriver::EnableTmr(void)
{
  moduleReg->CHANNEL[(uint8)tmr].TCTRL |= PIT_TCTRL_TEN_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method disables the timer managed by the class instance.
 */
void PITDriver::DisableTmr(void)
{
  moduleReg->CHANNEL[(uint8)tmr].TCTRL &= ~(PIT_TCTRL_TEN_MASK);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method enables the interrupt corresponding to the timer managed by the class instance.
 */
void PITDriver::EnableIntrpt(void)
{
  moduleReg->CHANNEL[(uint8)tmr].TCTRL |= PIT_TCTRL_TIE_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method disables the interrupt corresponding to the timer managed by the class instance.
 */
void PITDriver::DisableIntrpt(void)
{
  moduleReg->CHANNEL[(uint8)tmr].TCTRL &= ~(PIT_TCTRL_TIE_MASK);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method indicates whether the interrupt corresponding to the timer managed by the class instance is pending.
 */
bool PITDriver::IntrptIsPending(void)
{
  return ((moduleReg->CHANNEL[(uint8)tmr].TFLG & PIT_TFLG_TIF_MASK) != 0) ? true : false;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method clears the interrupt corresponding to the timer managed by the class instance.
 */
void PITDriver::ClearIntrpt(void)
{
  moduleReg->CHANNEL[(uint8)tmr].TFLG |= PIT_TFLG_TIF_MASK;
}
