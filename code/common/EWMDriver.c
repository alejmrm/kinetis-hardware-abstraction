/*****************************************************************************************************************************************************
*
*  EWMDriver.c  -  Copyright 2013, stokeware
*
*  This file contains the external watchdog monitor driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
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
   * Set the EWM control register module enable bit.
   */
  moduleReg->CTRL |= ((uint8)1 << 0);
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
