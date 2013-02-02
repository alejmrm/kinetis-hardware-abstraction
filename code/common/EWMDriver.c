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
   * Set the module enable bit in the EWM control register.
   */
  moduleReg->CTRL |= EWM_CTRL_EWMEN_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the EWM input port.
 */
void EWMDriver::EnableInput(void)
{
  /*
   * Set the input enable bit in the EWM control register.
   */
  moduleReg->CTRL |= EWM_CTRL_INEN_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method disables the EWM input port.
 */
void EWMDriver::DisableInput(void)
{
  /*
   * Clear the input enable bit in the EWM control register.
   */
  moduleReg->CTRL &= ~EWM_CTRL_INEN_MASK;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the EWM interrupt.
 */
void EWMDriver::EnableIntrpt(void)
{
  /*
   * Set the interrupt enable bit in the EWM control register.
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
   * Clear the interrupt enable bit in the EWM control register.
   */
  moduleReg->CTRL &= ~((uint8)1 << 3);
}
