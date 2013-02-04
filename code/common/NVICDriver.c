/*****************************************************************************************************************************************************
*
*  NVICDriver.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the nested vectored interrupt controller driver class implementation.
*
*****************************************************************************************************************************************************/
#include "MK40DZ10.h"
#include "CommonTypes.h"
#include "NVICDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static data member is a pointer to the NVIC register structure.
 */
NVIC_MemMapPtr NVICDriver::moduleReg = NVIC_BASE_PTR;

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the NVIC driver class.
 */
NVICDriver::NVICDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the NVIC driver class.
 */
NVICDriver::~NVICDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the specified interrupt.
 */
void NVICDriver::EnableIntrpt(NVICDriver::intrpt_id intrpt)
{
  /*
   * Set the bit in the interrupt set-enable register corresponding to the specified interrupt.
   */
  moduleReg->ISER[(uint8)intrpt >> 5] |= ((uint32)1 << ((uint8)intrpt & 0x1F));
}
