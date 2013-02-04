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

void HandlePITInt(void)
{
  PITDriver::ClearIntrpt(PITDriver::TMR_1);
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
  PITDriver::SetPeriod(PITDriver::TMR_1, 10000);
  PITDriver::EnableIntrpt(PITDriver::TMR_1);
  PITDriver::EnableTmr(PITDriver::TMR_1);

  while (true) { }
}
