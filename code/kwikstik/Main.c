/*****************************************************************************************************************************************************
*
*  Main.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the main function for the KwikStik test project.
*
*****************************************************************************************************************************************************/
#include "MCU_Types.h"
#include "NVICDriver.h"
#include "PITDriver.h"
#include "SCBDriver.h"
#include "SIMDriver.h"
#include "VectorTable.h"

PITDriver ctrlIntrptTmrDriver(PIT_TMR_1);

/*****************************************************************************************************************************************************
*
*  Public Functions
*
*****************************************************************************************************************************************************/
int main(void)
{
  SCBDriver::SetVectorTableAddr(VectorTable::GetAddr());
  SIMDriver::EnableSysClkGating(SIM_SYS_CLK_PIT);
  NVICDriver::EnableIntrpt(NVIC_INTRPT_PIT_1);

  PITDriver::EnableModule();
  ctrlIntrptTmrDriver.SetPeriod(10000);
  ctrlIntrptTmrDriver.EnableIntrpt();
  ctrlIntrptTmrDriver.EnableTmr();

  while (true) { }
}

void HandlePITInt(void)
{
  ctrlIntrptTmrDriver.ClearIntrpt();
}
