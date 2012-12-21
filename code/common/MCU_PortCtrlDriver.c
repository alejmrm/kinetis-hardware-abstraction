/*****************************************************************************************************************************************************
*
*  MCU_PortCtrlDriver.c  -  Copyright 2012, stokeware
*
*  This file contains the MCU port control and interrupt driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_PortCtrlDriver.h"
#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is an array containing pointers to the MCU port control register structures for each of the ports.
 */
PORT_MemMapPtr PortCtrlDriver::portCtrlPortRegs[NUM_PORT_CTRL_PORTS] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR,
                                                                        PORTD_BASE_PTR, PORTE_BASE_PTR};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the port control and interrupt peripheral driver class.
 */
PortCtrlDriver::PortCtrlDriver(port_ctrl_pin pin)
{
  port = (port_ctrl_port)((uint8)pin / NUM_PORT_CTRL_PORT_PINS);
  portPin = (port_ctrl_port_pin)((uint8)pin % NUM_PORT_CTRL_PORT_PINS);
  portReg = portCtrlPortRegs[(uint8)port];
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the port control and interrupt peripheral driver class.
 */
PortCtrlDriver::~PortCtrlDriver(void)
{
}
