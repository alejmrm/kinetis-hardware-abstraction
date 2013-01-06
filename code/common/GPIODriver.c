/*****************************************************************************************************************************************************
*
*  GPIODriver.c  -  Copyright 2012, stokeware
*
*  This file contains the general purpose I/O driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "GPIODriver.h"
#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static class data member is an array containing pointers to the MCU register structures for each of the GPIO ports.
 */
GPIO_MemMapPtr GPIODriver::gpioPortRegs[NUM_GPIO_PORTS] = {PTA_BASE_PTR, PTB_BASE_PTR, PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the GPIO driver class.
 */
GPIODriver::GPIODriver(gpio_pin pin)
{
  port = (gpio_port)((uint8)pin / NUM_GPIO_PORT_PINS);
  portPin = (gpio_port_pin)((uint8)pin % NUM_GPIO_PORT_PINS);
  portReg = gpioPortRegs[(uint8)port];
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
void GPIODriver::SetDir(gpio_pin_dir dir)
{
  /*
   * Clear or set the bit in the port data direction register corresponding to the pin, depending on the specified direction.
   */
  if (dir == GPIO_PIN_DIR_IN)
    portReg->PDDR &= ~((uint32)1 << (uint8)portPin);
  else if (dir == GPIO_PIN_DIR_OUT)
    portReg->PDDR |= ((uint32)1 << (uint8)portPin);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method sets the level of the pin managed by the class instance.
 */
void GPIODriver::SetLvl(gpio_pin_lvl lvl)
{
  /*
   * Set the bit corresponding to the pin in either the port clear output register or the port set output register, depending on the specified level.
   */
  if (lvl == GPIO_PIN_LVL_LO)
    portReg->PCOR = ((uint32)1 << (uint8)portPin);
  else if (lvl == GPIO_PIN_LVL_HI)
    portReg->PSOR = ((uint32)1 << (uint8)portPin);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method provides the level of the pin managed by the class instance.
 */
gpio_pin_lvl GPIODriver::GetLvl(void)
{
  /*
   * Check the value of the port data input register bit corresponding to the pin. If the bit value is zero, the pin level is low. If the bit value
   * is one, the pin level is high.
   */
  if (portReg->PDIR & ((uint32)1 << (uint8)portPin) == 0)
    return GPIO_PIN_LVL_LO;
  else
    return GPIO_PIN_LVL_HI;
}
