/*****************************************************************************************************************************************************
*
*  GPIODriver.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the general purpose I/O driver class implementation.
*
*****************************************************************************************************************************************************/
#include "MK40DZ10.h"
#include "CommonTypes.h"
#include "GPIODriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is an array containing pointers to the MCU register structures for each of the GPIO ports.
 */
GPIO_MemMapPtr GPIODriver::moduleReg[GPIODriver::NUM_PORTS] = {PTA_BASE_PTR, PTB_BASE_PTR, PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the GPIO driver class.
 */
GPIODriver::GPIODriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the GPIO driver class.
 */
GPIODriver::~GPIODriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method sets the direction of the specified pin.
 */
void GPIODriver::SetDir(GPIODriver::pin_id pin, GPIODriver::pin_dir dir)
{
  /*
   * Clear or set the bit in the port data direction register corresponding to the pin, depending on the specified direction.
   */
  if (dir == GPIODriver::PIN_DIR_IN)
    moduleReg[(uint8)pin >> 5]->PDDR &= ~((uint32)1 << ((uint8)pin & 0x1F));
  else if (dir == GPIODriver::PIN_DIR_OUT)
    moduleReg[(uint8)pin >> 5]->PDDR |= ((uint32)1 << ((uint8)pin & 0x1F));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method sets the level of the specified pin.
 */
void GPIODriver::SetLvl(GPIODriver::pin_id pin, GPIODriver::pin_lvl lvl)
{
  /*
   * Set the bit corresponding to the pin in either the port clear output register or the port set output register, depending on the specified level.
   */
  if (lvl == GPIODriver::PIN_LVL_LO)
    moduleReg[(uint8)pin >> 5]->PCOR = ((uint32)1 << ((uint8)pin & 0x1F));
  else if (lvl == GPIODriver::PIN_LVL_HI)
    moduleReg[(uint8)pin >> 5]->PSOR = ((uint32)1 << ((uint8)pin & 0x1F));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method provides the level of the specified pin.
 */
GPIODriver::pin_lvl GPIODriver::GetLvl(GPIODriver::pin_id pin)
{
  /*
   * Check the value of the port data input register bit corresponding to the pin. If the bit value is zero, the pin level is low. If the bit value
   * is one, the pin level is high.
   */
  if (moduleReg[(uint8)pin >> 5]->PDIR & ((uint32)1 << ((uint8)pin & 0x1F)) == 0)
    return GPIODriver::PIN_LVL_LO;
  else
    return GPIODriver::PIN_LVL_HI;
}
