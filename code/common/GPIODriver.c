/*****************************************************************************************************************************************************
*
*  GPIODriver.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the general purpose I/O driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
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
GPIO_MemMapPtr GPIODriver::moduleReg[GPIOType::NUM_PORTS] = {PTA_BASE_PTR, PTB_BASE_PTR, PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the GPIO driver class.
 */
GPIODriver::GPIODriver(GPIOType::pin pin)
{
  port = (GPIOType::port)((uint8)pin / GPIOType::NUM_PORT_PINS);
  portPin = (GPIOType::port_pin)((uint8)pin % GPIOType::NUM_PORT_PINS);
  portReg = moduleReg[(uint8)port];
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
 * This method sets the direction of the pin managed by the class instance.
 */
void GPIODriver::SetDir(GPIOType::pin_dir dir)
{
  /*
   * Clear or set the bit in the port data direction register corresponding to the pin, depending on the specified direction.
   */
  if (dir == GPIOType::PIN_DIR_IN)
    portReg->PDDR &= ~((uint32)1 << (uint8)portPin);
  else if (dir == GPIOType::PIN_DIR_OUT)
    portReg->PDDR |= ((uint32)1 << (uint8)portPin);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method sets the level of the pin managed by the class instance.
 */
void GPIODriver::SetLvl(GPIOType::pin_lvl lvl)
{
  /*
   * Set the bit corresponding to the pin in either the port clear output register or the port set output register, depending on the specified level.
   */
  if (lvl == GPIOType::PIN_LVL_LO)
    portReg->PCOR = ((uint32)1 << (uint8)portPin);
  else if (lvl == GPIOType::PIN_LVL_HI)
    portReg->PSOR = ((uint32)1 << (uint8)portPin);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method provides the level of the pin managed by the class instance.
 */
GPIOType::pin_lvl GPIODriver::GetLvl(void)
{
  /*
   * Check the value of the port data input register bit corresponding to the pin. If the bit value is zero, the pin level is low. If the bit value
   * is one, the pin level is high.
   */
  if (portReg->PDIR & ((uint32)1 << (uint8)portPin) == 0)
    return GPIOType::PIN_LVL_LO;
  else
    return GPIOType::PIN_LVL_HI;
}
