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
PORT_MemMapPtr PORTDriver::moduleReg[PORTType::NUM_PORTS] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the PORT driver class.
 */
PORTDriver::PORTDriver(PORTType::pin pin)
{
  port = (PORTType::port)((uint8)pin / PORTType::NUM_PORT_PINS);
  portPin = (PORTType::port_pin)((uint8)pin % PORTType::NUM_PORT_PINS);
  portReg = moduleReg[(uint8)port];
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
 * This method clears the interrupt status for the pin managed by the class instance.
 */
void PORTDriver::ClearIntStatus(void)
{
  /*
   * Write to the interrupt status flag bit in the pin control register corresponding to the pin to clear the interrupt status.
   */
  portReg->PCR[(uint8)portPin] |= ((uint32)1 << PORT_PCR_ISF_SHIFT);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method configures the multiplexing mode for the pin managed by the class instance.
 */
void PORTDriver::SetMuxMode(PORTType::pin_mux_mode mode)
{
  /*
   * Set the mux control bits in the pin control register corresponding to the pin to the value corresponding to the specified mode.
   */
  portReg->PCR[(uint8)portPin] &= ~(PORT_PCR_MUX_MASK);
  portReg->PCR[(uint8)portPin] |= ((uint32)mode << PORT_PCR_MUX_SHIFT);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method configures the interrupt and DMA mode for the pin managed by the class instance.
 */
void PORTDriver::SetIntDmaMode(PORTType::pin_int_dma_mode mode)
{
  /*
   * Set the interrupt configuration bits in the pin control register corresponding to the pin to the value corresponding to the specified mode.
   */
  portReg->PCR[(uint8)portPin] &= ~(PORT_PCR_IRQC_MASK);
  portReg->PCR[(uint8)portPin] |= ((uint32)mode << PORT_PCR_IRQC_SHIFT);
}
