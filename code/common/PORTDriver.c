/*****************************************************************************************************************************************************
*
*  PORTDriver.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the port control and interrupt driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "CommonTypes.h"
#include "PORTDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is an array containing pointers to the PORT register structures for each of the ports.
 */
PORT_MemMapPtr PORTDriver::moduleReg[PORTDriver::NUM_PORTS] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the PORT driver class.
 */
PORTDriver::PORTDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the PORT driver class.
 */
PORTDriver::~PORTDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method clears the interrupt status for the specified pin.
 */
void PORTDriver::ClearIntStatus(PORTDriver::pin_id pin)
{
  /*
   * Write to the interrupt status flag bit in the pin control register corresponding to the pin to clear the interrupt status.
   */
  moduleReg[(uint8)pin >> 5]->PCR[(uint8)pin & 0x1F] |= ((uint32)1 << PORT_PCR_ISF_SHIFT);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method configures the multiplexing mode for the specified pin.
 */
void PORTDriver::SetMuxMode(PORTDriver::pin_id pin, PORTDriver::pin_mux_mode mode)
{
  /*
   * Set the mux control bits in the pin control register corresponding to the pin to the value corresponding to the mode.
   */
  moduleReg[(uint8)pin >> 5]->PCR[(uint8)pin & 0x1F] &= ~(PORT_PCR_MUX_MASK);
  moduleReg[(uint8)pin >> 5]->PCR[(uint8)pin & 0x1F] |= ((uint32)mode << PORT_PCR_MUX_SHIFT);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method configures the interrupt and DMA mode for the specified pin.
 */
void PORTDriver::SetIntDmaMode(PORTDriver::pin_id pin, PORTDriver::pin_int_dma_mode mode)
{
  /*
   * Set the interrupt configuration bits in the pin control register corresponding to the pin to the value corresponding to the mode.
   */
  moduleReg[(uint8)pin >> 5]->PCR[(uint8)pin & 0x1F] &= ~(PORT_PCR_IRQC_MASK);
  moduleReg[(uint8)pin >> 5]->PCR[(uint8)pin & 0x1F] |= ((uint32)mode << PORT_PCR_IRQC_SHIFT);
}
