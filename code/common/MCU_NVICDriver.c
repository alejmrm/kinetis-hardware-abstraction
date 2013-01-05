/*****************************************************************************************************************************************************
*
*  MCU_NVICDriver.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the MCU nested vectored interrupt controller driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_NVICDriver.h"
#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static data member is a pointer to the NVIC register structure.
 */
NVIC_MemMapPtr NVICDriver::nvicReg = NVIC_BASE_PTR;

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
void NVICDriver::EnableIntrpt(nvic_intrpt intrpt)
{
  /*
   * Set the bit in the interrupt set-enable register corresponding to the specified interrupt.
   */
  nvicReg->ISER[(uint8)intrpt >> 5] |= ((uint32)1 << ((uint8)intrpt & 0x1F));
}
