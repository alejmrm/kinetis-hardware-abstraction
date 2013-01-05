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
#include "MCU_SCBDriver.h"
#include "MCU_SIMDriver.h"
#include "MCU_Types.h"
#include "VectorTable.h"

IntTmrDriver ctrlIntTmrDriver(INT_TMR_1);

/*****************************************************************************************************************************************************
*
*  Public Functions
*
*****************************************************************************************************************************************************/
int main(void)
{
  SCBDriver::InitModule();
  SCBDriver::SetVectorTableAddr(VectorTable::GetAddr());

  SIMDriver::EnableSysClkGating(SIM_SYS_CLK_PIT);

  NVIC_BASE_PTR->ISER[2] |= ((uint32)1 << 5);

  IntTmrDriver::EnableModule();
  ctrlIntTmrDriver.SetPeriod(10000);
  ctrlIntTmrDriver.EnableInt();
  ctrlIntTmrDriver.EnableTmr();

  while (true) { }
}

void HandlePITInt(void)
{
  ctrlIntTmrDriver.ClearInt();
}
