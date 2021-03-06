/*****************************************************************************************************************************************************
*
*  PITDriver.c  -  This file contains the periodic interrupt timer driver class implementation.
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
#include <MK40DZ10.h>
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
PITDriver::PITDriver(void)
{
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
 * This static method sets the timeout period for the specified timer.
 */
void PITDriver::SetPeriod(tmr_id tmr, uint32 period)
{
  /*
   * Set the load value register for the timer to the specified period value.
   */
  moduleReg->CHANNEL[(uint8)tmr].LDVAL = period;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method provides the present count value for the specified timer.
 */
uint32 PITDriver::GetCnt(tmr_id tmr)
{
  /*
   * Return the contents of the current timer value register for the timer.
   */
  return moduleReg->CHANNEL[(uint8)tmr].CVAL;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the specified timer.
 */
void PITDriver::EnableTmr(tmr_id tmr)
{
  moduleReg->CHANNEL[(uint8)tmr].TCTRL |= PIT_TCTRL_TEN_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method disables the specified timer.
 */
void PITDriver::DisableTmr(tmr_id tmr)
{
  moduleReg->CHANNEL[(uint8)tmr].TCTRL &= ~(PIT_TCTRL_TEN_MASK);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the interrupt corresponding to the specified timer.
 */
void PITDriver::EnableIntrpt(tmr_id tmr)
{
  moduleReg->CHANNEL[(uint8)tmr].TCTRL |= PIT_TCTRL_TIE_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method disables the interrupt corresponding to the specified timer.
 */
void PITDriver::DisableIntrpt(tmr_id tmr)
{
  moduleReg->CHANNEL[(uint8)tmr].TCTRL &= ~(PIT_TCTRL_TIE_MASK);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method indicates whether the interrupt corresponding to the specified timer is pending.
 */
bool PITDriver::IntrptIsPending(tmr_id tmr)
{
  return ((moduleReg->CHANNEL[(uint8)tmr].TFLG & PIT_TFLG_TIF_MASK) != 0) ? true : false;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method clears the interrupt corresponding to the specified timer.
 */
void PITDriver::ClearIntrpt(tmr_id tmr)
{
  moduleReg->CHANNEL[(uint8)tmr].TFLG |= PIT_TFLG_TIF_MASK;
}
