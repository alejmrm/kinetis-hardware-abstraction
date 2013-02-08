/*****************************************************************************************************************************************************
*
*  EWMDriver.c  -  This file contains the external watchdog monitor driver class implementation.
*
*  Copyright (c) 2013, stokeware
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
#include "EWMDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is a pointer to the EWM register structure.
 */
EWM_MemMapPtr EWMDriver::moduleReg = EWM_BASE_PTR;
/*
 * These static data members are flags that indicate whether the associated EWM registers have been written.
 */
bool EWMDriver::moduleIsEnabled = false;
bool EWMDriver::clkPrescalerIsSet = false;
bool EWMDriver::loCompValIsSet = false;
bool EWMDriver::hiCompValIsSet = false;

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the EWM driver class.
 */
EWMDriver::EWMDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the EWM driver class.
 */
EWMDriver::~EWMDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the EWM module.
 */
void EWMDriver::EnableModule(void)
{
  /*
   * If the EWM module has already been enabled, return immediately to avoid generating a bus transfer error by writing to the EWM control register
   * module enable bit more than once.
   */
  if (moduleIsEnabled)
    return;
  /*
   * Set the EWM control register module enable bit.
   */
  moduleReg->CTRL |= ((uint8)1 << 0);
  /*
   * Indicate that the EWM module has been enabled.
   */
  moduleIsEnabled = true;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method sets the assert state of the EWM input signal.
 */
void EWMDriver::SetAssertState(EWMDriver::assert_state state)
{
  /*
   * Set the EWM control register assertion state select bit to the value corresponding to the state.
   */
  if (state == EWMDriver::ASSERT_STATE_ZERO)
    moduleReg->CTRL &= ~((uint8)1 << 1);
  else if (state == EWMDriver::ASSERT_STATE_ONE)
    moduleReg->CTRL |= ((uint8)1 << 1);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the EWM input port.
 */
void EWMDriver::EnableInput(void)
{
  /*
   * Set the EWM control register input enable bit.
   */
  moduleReg->CTRL |= ((uint8)1 << 2);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method disables the EWM input port.
 */
void EWMDriver::DisableInput(void)
{
  /*
   * Clear the EWM control register input enable bit.
   */
  moduleReg->CTRL &= ~((uint8)1 << 2);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the EWM interrupt.
 */
void EWMDriver::EnableIntrpt(void)
{
  /*
   * Set the EWM control register interrupt enable bit.
   */
  moduleReg->CTRL |= ((uint8)1 << 3);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method disables the EWM interrupt.
 */
void EWMDriver::DisableIntrpt(void)
{
  /*
   * Clear the EWM control register interrupt enable bit.
   */
  moduleReg->CTRL &= ~((uint8)1 << 3);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method sets the EWM clock prescaler value.
 */
void EWMDriver::SetClkPrescaler(uint8 val)
{
  /*
   * If the clock prescaler value has already been set, return immediately to avoid generating a bus transfer error by writing to the EWM clock
   * prescaler register more than once.
   */
  if (clkPrescalerIsSet)
    return;
  /*
   * Set the EWM clock prescaler register to the specified value.
   */
  *(uint8*)(0x40061005u) = val;
  /*
   * Indicate that the clock prescaler has been set.
   */
  clkPrescalerIsSet = true;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method sets the EWM low compare value, which defines the low end of the range of timer counts within which the external watchdog must
 * be serviced.
 */
void EWMDriver::SetLoCompVal(uint8 val)
{
  /*
   * If the low compare value has already been set, return immediately to avoid generating a bus transfer error by writing to the EWM compare low
   * register more than once.
   */
  if (loCompValIsSet)
    return;
  /*
   * Set the EWM compare low register to the specified value.
   */
  moduleReg->CMPL = val;
  /*
   * Indicate that the low compare value has been set.
   */
  loCompValIsSet = true;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method sets the EWM high compare value, which defines the high end of the range of timer counts within which the external watchdog must
 * be serviced.
 */
void EWMDriver::SetHiCompVal(uint8 val)
{
  /*
   * If the high compare value has already been set, return immediately to avoid generating a bus transfer error by writing to the EWM compare high
   * register more than once.
   */
  if (hiCompValIsSet)
    return;
  /*
   * Set the EWM compare high register to the specified value.
   */
  moduleReg->CMPH = val;
  /*
   * Indicate that the high compare value has been set.
   */
  hiCompValIsSet = true;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method method services the external watchdog.
 */
void EWMDriver::ServiceWatchdog(void)
{
  /*
   * Write the required sequence of bytes to the EWM service register.
   */
  moduleReg->SERV = 0xB4;
  moduleReg->SERV = 0x2C;
}
