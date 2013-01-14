/*****************************************************************************************************************************************************
*
*  Main.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the main function for the KwikStik test project.
*
*****************************************************************************************************************************************************/
#include "CommonTypes.h"
#include "NVICDriver.h"
#include "PITDriver.h"
#include "SCBDriver.h"
#include "SIMDriver.h"
#include "VectorTable.h"

PITDriver ctrlIntrptTmrDriver(PITDriver::TMR_1);

void HandlePITInt(void)
{
  ctrlIntrptTmrDriver.ClearIntrpt();
}

/*****************************************************************************************************************************************************
*
*  Public Functions
*
*****************************************************************************************************************************************************/
int main(void)
{
  VectorTable::Init();
  SCBDriver::SetVectorTableAddr(VectorTable::GetAddr());
  SIMDriver::EnableSysClkGating(SIMDriver::SYS_CLK_PIT);

  VectorTable::SetIsr(VectorTable::INTRPT_PIT_1, HandlePITInt);
  NVICDriver::EnableIntrpt(NVICDriver::INTRPT_PIT_1);

  PITDriver::EnableModule();
  ctrlIntrptTmrDriver.SetPeriod(10000);
  ctrlIntrptTmrDriver.EnableIntrpt();
  ctrlIntrptTmrDriver.EnableTmr();

  while (true) { }
}
