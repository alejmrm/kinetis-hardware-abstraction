/*****************************************************************************************************************************************************
*
*  Main.c  -  Copyright 2012, stokeware
*
*  This file contains the main function for the KwikStik test project.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_IntTmrDriver.h"
#include "MCU_SCBDriver.h"
#include "MCU_Types.h"

#pragma section = ".intvec"

IntTmrDriver ctrlIntTmrDriver(INT_TMR_1);

/*****************************************************************************************************************************************************
*
*  Public Functions
*
*****************************************************************************************************************************************************/
int main(void)
{
  SCBDriver::InitModule();
  SCBDriver::SetVectorTableAddr((void*)__segment_begin(".intvec"));

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
