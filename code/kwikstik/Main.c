/*****************************************************************************************************************************************************
*
*  Main.c  -  Copyright 2012-2013, stokeware
*
*  This file contains the main function for the KwikStik test project.
*
*****************************************************************************************************************************************************/
#include "CommonTypes.h"
#include "KwikStikDisplay.h"
#include "NVICDriver.h"
#include "PITDriver.h"
#include "SCBDriver.h"
#include "SIMDriver.h"
#include "SLCDDriver.h"
#include "VectorTable.h"

void HandlePITInt(void)
{
  static bool displayFlag = false;
  static uint16 displayCnt = 0;

  PITDriver::ClearIntrpt(PITDriver::TMR_1);

  if (++displayCnt >= 1000)  {
    if (displayFlag)  {
      KwikStikDisplay::TurnOnAllSegments();
      displayFlag = false;
    }
    else  {
      KwikStikDisplay::TurnOffAllSegments();
      displayFlag = true;
    }
    displayCnt = 0;
  }
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

  SIMDriver::EnableSysClkGating(SIMDriver::SYS_CLK_PORTB);
  SIMDriver::EnableSysClkGating(SIMDriver::SYS_CLK_PORTC);
  SIMDriver::EnableSysClkGating(SIMDriver::SYS_CLK_PORTD);
  SIMDriver::EnableSysClkGating(SIMDriver::SYS_CLK_SLCD);

  SLCDDriver::InitModule();

  KwikStikDisplay::Init();

  PITDriver::EnableModule();
  PITDriver::SetPeriod(PITDriver::TMR_1, 10000);
  PITDriver::EnableIntrpt(PITDriver::TMR_1);
  PITDriver::EnableTmr(PITDriver::TMR_1);

  while (true) { }
}
