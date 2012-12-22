/*****************************************************************************************************************************************************
*
*  Main.c  -  Copyright 2012, stokeware
*
*  This file contains the main function for the KwikStik test project.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_IntTmrDriver.h"
#include "MCU_NVICDriver.h"
#include "MCU_Types.h"

IntTmrDriver ctrlIntTmrDriver(INT_TMR_1);

/*****************************************************************************************************************************************************
*
*  Public Functions
*
*****************************************************************************************************************************************************/
int main(void)
{
  NVICDriver::InitModule();

  SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
  NVIC_BASE_PTR->ISER[2] |= ((uint32)1 << 5);
  IntTmrDriver::EnableModule();
  ctrlIntTmrDriver.SetPeriod(10000);
  ctrlIntTmrDriver.EnableInt();
  ctrlIntTmrDriver.EnableTmr();

  while (true) { }
}

extern "C" {
  void PIT1_IRQHandler(void);
}

void PIT1_IRQHandler(void)
{
  ctrlIntTmrDriver.ClearInt();
}
