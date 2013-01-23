/*****************************************************************************************************************************************************
*
*  SLCDDriver.c  -  Copyright 2013, stokeware
*
*  This file contains the LCD controller driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "CommonTypes.h"
#include "SLCDDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is a pointer to the SLCD register structure.
 */
LCD_MemMapPtr SLCDDriver::moduleReg = LCD_BASE_PTR;

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the SLCD driver class.
 */
SLCDDriver::SLCDDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the SLCD driver class.
 */
SLCDDriver::~SLCDDriver(void)
{
}
/*
 * This static method initializes the SLCD module.
 */
void SLCDDriver::InitModule(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method enables the specified LCD pin.
 */
void SLCDDriver::EnablePin(SLCDDriver::pin_id pin)
{
  /*
   * Set the bit in the LCD pin enable register corresponding to the specified pin.
   */
  moduleReg->PEN[(uint8)pin >> 5] |= ((uint32)1 << ((uint8)pin & 0x1F));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method disables the specified LCD pin.
 */
void SLCDDriver::DisablePin(SLCDDriver::pin_id pin)
{
  /*
   * Clear the bit in the LCD pin enable register corresponding to the specified pin.
   */
  moduleReg->PEN[(uint8)pin >> 5] &= ~((uint32)1 << ((uint8)pin & 0x1F));
}
