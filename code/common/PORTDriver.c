/*****************************************************************************************************************************************************
*
*  PORTDriver.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the port control and interrupt driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_Types.h"
#include "PORTDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is an array containing pointers to the PORT register structures for each of the ports.
 */
PORT_MemMapPtr PORTDriver::portRegs[NUM_PORT_PORTS] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the PORT driver class.
 */
PORTDriver::PORTDriver(port_pin pin)
{
  port = (port_port)((uint8)pin / NUM_PORT_PORT_PINS);
  portPin = (port_port_pin)((uint8)pin % NUM_PORT_PORT_PINS);
  portReg = portRegs[(uint8)port];
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
void PORTDriver::SetMuxMode(port_pin_mux_mode mode)
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
void PORTDriver::SetIntDmaMode(port_pin_int_dma_mode mode)
{
  /*
   * Set the interrupt configuration bits in the pin control register corresponding to the pin to the value corresponding to the specified mode.
   */
  portReg->PCR[(uint8)portPin] &= ~(PORT_PCR_IRQC_MASK);
  portReg->PCR[(uint8)portPin] |= ((uint32)mode << PORT_PCR_IRQC_SHIFT);
}
