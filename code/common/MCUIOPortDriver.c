/*****************************************************************************************************************************************************
*
*  MCUIOPortDriver.c  -  Copyright 2012, stokeware
*
*  This file contains the MCU I/O port driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCUIOPortDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is an array containing pointers to the MCU register structures for each of the I/O ports.
 */
GPIO_MemMapPtr MCUIOPortDriver::ioPortRegs[NUM_IO_PORTS] = {PTA_BASE_PTR, PTB_BASE_PTR, PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the I/O port peripheral driver class.
 */
MCUIOPortDriver::MCUIOPortDriver(io_port port)
{
  this->port = port;
  reg = ioPortRegs[port];
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the I/O port peripheral driver class.
 */
MCUIOPortDriver::~MCUIOPortDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method sets the direction of the specified I/O pin.
 */
void MCUIOPortDriver::SetPinDir(io_pin pin, io_pin_dir dir)
{
  /*
   * Clear or set the bit in the port data direction register corresponding to the specified pin, depending on the specified direction.
   */
  if (dir == IO_PIN_DIR_IN)
    reg->PDDR &= ~((uint32)1 << pin);
  else if (dir == IO_PIN_DIR_OUT)
    reg->PDDR |= ((uint32)1 << pin);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method sets the specified I/O pin to the specified level.
 */
void MCUIOPortDriver::SetPinLvl(io_pin pin, io_pin_lvl lvl)
{
  /*
   * Set the bit corresponding to the specified pin in either the port clear output register or the port set output register, depending on the
   * specified level.
   */
  if (lvl == IO_PIN_LVL_LO)
    reg->PCOR = ((uint32)1 << pin);
  else if (lvl == IO_PIN_LVL_HI)
    reg->PSOR = ((uint32)1 << pin);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method provides the level of the specified I/O pin.
 */
io_pin_lvl MCUIOPortDriver::GetPinLvl(io_pin pin)
{
  /*
   * Check the value of the port data input register bit corresponding to the specified pin. If the bit value is zero, the pin level is low. If the
   * bit value is one, the pin level is high.
   */
  if (reg->PDIR & ((uint32)1 << pin) == 0)
    return IO_PIN_LVL_LO;
  else
    return IO_PIN_LVL_HI;
}
