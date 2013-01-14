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
#include "SLCDDriver.h"
#include "VectorTable.h"

PITDriver ctrlIntrptTmrDriver(PITDriver::TMR_1);

/*****************************************************************************************************************************************************
*
*  Public Functions
*
*****************************************************************************************************************************************************/
int main(void)
{
  SCBDriver::SetVectorTableAddr(VectorTable::GetAddr());
  SIMDriver::EnableSysClkGating(SIMDriver::SYS_CLK_PIT);
  NVICDriver::EnableIntrpt(NVICDriver::INTRPT_PIT_1);

  SLCDDriver::InitModule();

  PITDriver::EnableModule();
  ctrlIntrptTmrDriver.SetPeriod(10000);
  ctrlIntrptTmrDriver.EnableIntrpt();
  ctrlIntrptTmrDriver.EnableTmr();

  while (true) { }
}

void HandlePITInt(void)
{
  static bool lcdFlag = false;
  static uint16 lcdCnt = 0;

  ctrlIntrptTmrDriver.ClearIntrpt();

  if (++lcdCnt >= 1000)  {
    if (lcdFlag)  {
      SLCDDriver::TurnOnAllSegments();
      lcdFlag = false;
    }
    else  {
      SLCDDriver::TurnOffAllSegments();
      lcdFlag = true;
    }
    lcdCnt = 0;
  }
}
