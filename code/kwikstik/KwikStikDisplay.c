/*****************************************************************************************************************************************************
*
*  KwikStikDisplay.c  -  Copyright 2013, stokeware
*
*  This file contains the KwikStik display class implementation.
*
*****************************************************************************************************************************************************/
#include "MK40DZ10.h"
#include "CommonTypes.h"
#include "KwikStikDisplay.h"
#include "PORTDriver.h"
#include "SLCDDriver.h"

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the KwikStik display class.
 */
KwikStikDisplay::KwikStikDisplay(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the KwikStik display class.
 */
KwikStikDisplay::~KwikStikDisplay(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method initializes the KwikStik display.
 */
void KwikStikDisplay::Init(void)
{
  MCG_C1 |= MCG_C1_IRCLKEN_MASK;
  /*
   * Configure the port pins corresponding to the LCD pins for analog operation.
   */
  PORTDriver::SetMuxMode(PORTDriver::PIN_B1, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B2, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B3, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B4, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B5, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B6, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B7, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B8, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B9, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B10, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B11, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B16, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B17, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B18, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B19, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B20, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B21, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B22, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_B23, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C0, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C1, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C2, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C3, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C4, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C5, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C6, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C7, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C8, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C9, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C10, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C11, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C12, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C13, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C14, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C15, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C16, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C17, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C18, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_C19, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_D0, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_D1, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_D2, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_D3, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_D4, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_D5, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_D6, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  PORTDriver::SetMuxMode(PORTDriver::PIN_D7, PORTDriver::PIN_MUX_MODE_DISABLED_ANALOG);
  /*
   * Disable the LCD controller waveform generator.
   */
  SLCDDriver::DisableCtrl();
  /*
   * Enable the LCD pins used in the KwikStik display.
   */
  SLCDDriver::EnablePin(SLCDDriver::PIN_1);
  SLCDDriver::EnablePin(SLCDDriver::PIN_2);
  SLCDDriver::EnablePin(SLCDDriver::PIN_3);
  SLCDDriver::EnablePin(SLCDDriver::PIN_4);
  SLCDDriver::EnablePin(SLCDDriver::PIN_5);
  SLCDDriver::EnablePin(SLCDDriver::PIN_6);
  SLCDDriver::EnablePin(SLCDDriver::PIN_7);
  SLCDDriver::EnablePin(SLCDDriver::PIN_8);
  SLCDDriver::EnablePin(SLCDDriver::PIN_9);
  SLCDDriver::EnablePin(SLCDDriver::PIN_10);
  SLCDDriver::EnablePin(SLCDDriver::PIN_11);
  SLCDDriver::EnablePin(SLCDDriver::PIN_12);
  SLCDDriver::EnablePin(SLCDDriver::PIN_13);
  SLCDDriver::EnablePin(SLCDDriver::PIN_14);
  SLCDDriver::EnablePin(SLCDDriver::PIN_15);
  SLCDDriver::EnablePin(SLCDDriver::PIN_16);
  SLCDDriver::EnablePin(SLCDDriver::PIN_17);
  SLCDDriver::EnablePin(SLCDDriver::PIN_18);
  SLCDDriver::EnablePin(SLCDDriver::PIN_19);
  SLCDDriver::EnablePin(SLCDDriver::PIN_20);
  SLCDDriver::EnablePin(SLCDDriver::PIN_21);
  SLCDDriver::EnablePin(SLCDDriver::PIN_22);
  SLCDDriver::EnablePin(SLCDDriver::PIN_23);
  SLCDDriver::EnablePin(SLCDDriver::PIN_24);
  SLCDDriver::EnablePin(SLCDDriver::PIN_25);
  SLCDDriver::EnablePin(SLCDDriver::PIN_26);
  SLCDDriver::EnablePin(SLCDDriver::PIN_27);
  SLCDDriver::EnablePin(SLCDDriver::PIN_28);
  SLCDDriver::EnablePin(SLCDDriver::PIN_29);
  SLCDDriver::EnablePin(SLCDDriver::PIN_30);
  SLCDDriver::EnablePin(SLCDDriver::PIN_31);
  SLCDDriver::EnablePin(SLCDDriver::PIN_32);
  SLCDDriver::EnablePin(SLCDDriver::PIN_33);
  SLCDDriver::EnablePin(SLCDDriver::PIN_34);
  SLCDDriver::EnablePin(SLCDDriver::PIN_35);
  SLCDDriver::EnablePin(SLCDDriver::PIN_36);
  SLCDDriver::EnablePin(SLCDDriver::PIN_37);
  SLCDDriver::EnablePin(SLCDDriver::PIN_38);
  SLCDDriver::EnablePin(SLCDDriver::PIN_39);
  SLCDDriver::EnablePin(SLCDDriver::PIN_40);
  SLCDDriver::EnablePin(SLCDDriver::PIN_41);
  SLCDDriver::EnablePin(SLCDDriver::PIN_42);
  SLCDDriver::EnablePin(SLCDDriver::PIN_43);
  SLCDDriver::EnablePin(SLCDDriver::PIN_44);
  SLCDDriver::EnablePin(SLCDDriver::PIN_45);
  SLCDDriver::EnablePin(SLCDDriver::PIN_46);
  SLCDDriver::EnablePin(SLCDDriver::PIN_47);
  /*
   * Enable the front plane segments and back plane phases used in the KwikStik display.
   */
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_1, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_2, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_3, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_4, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_5, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_6, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_7, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_8, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_9, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_10, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_11, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_12, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_13, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_14, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_15, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_16, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_17, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_18, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_19, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_20, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_21, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_22, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_23, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_24, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_25, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_26, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_27, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_28, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_29, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_30, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_31, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_32, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_33, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_34, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_35, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_36, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_37, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_38, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_39, SLCDDriver::PIN_OPERATION_FRONTPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_40, SLCDDriver::PIN_OPERATION_BACKPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_41, SLCDDriver::PIN_OPERATION_BACKPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_42, SLCDDriver::PIN_OPERATION_BACKPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_43, SLCDDriver::PIN_OPERATION_BACKPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_44, SLCDDriver::PIN_OPERATION_BACKPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_45, SLCDDriver::PIN_OPERATION_BACKPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_46, SLCDDriver::PIN_OPERATION_BACKPLANE);
  SLCDDriver::SetPinOperation(SLCDDriver::PIN_47, SLCDDriver::PIN_OPERATION_BACKPLANE);

  // Configure backplane phase
  LCD_WF43TO40 = 0x08040201;
  LCD_WF47TO44 = 0x80402010;
  // Fill information on what segments are going to be turned on. Front Plane information
  LCD_WF3TO0   = 0;
  LCD_WF7TO4   = 0;
  LCD_WF11TO8  = 0;
  LCD_WF15TO12 = 0;
  LCD_WF19TO16 = 0;
  LCD_WF23TO20 = 0;
  LCD_WF27TO24 = 0;
  LCD_WF31TO28 = 0;
  LCD_WF35TO32 = 0;
  LCD_WF39TO36 = 0;

  // Configure LCD Control Register
  LCD_GCR |=  ( LCD_GCR_CPSEL_MASK
              | LCD_GCR_RVEN_MASK
              | LCD_GCR_RVTRIM(15)
              | !LCD_GCR_HREFSEL_MASK // ( 0 - 3 Volts LCDs / 1 - 5 Volts LCDs)
              | LCD_GCR_LADJ(3) //0-3
              | LCD_GCR_VSUPPLY(3) //0-3
              | !LCD_GCR_LCDIEN_MASK
              | !LCD_GCR_FDCIEN_MASK
              | LCD_GCR_ALTDIV(1) //0-3
              | !LCD_GCR_LCDWAIT_MASK
              | !LCD_GCR_LCDSTP_MASK
              | !LCD_GCR_LCDEN_MASK
              | LCD_GCR_SOURCE_MASK
              | LCD_GCR_LCLK(0) //0-3
              | LCD_GCR_DUTY(7) //0-7
              );
  /*
   * Enable the LCD controller waveform generator.
   */
  SLCDDriver::EnableCtrl();
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method turns on all LCD segments.
 */
void KwikStikDisplay::TurnOnAllSegments(void)
{
  LCD_WF3TO0   = 0xFFFFFF00;
  LCD_WF7TO4   = 0xFFFFFFFF;
  LCD_WF11TO8  = 0xFFFFFFFF;
  LCD_WF15TO12 = 0xFFFFFFFF;
  LCD_WF19TO16 = 0xFFFFFFFF;
  LCD_WF23TO20 = 0xFFFFFFFF;
  LCD_WF27TO24 = 0xFFFFFFFF;
  LCD_WF31TO28 = 0xFFFFFFFF;
  LCD_WF35TO32 = 0xFFFFFFFF;
  LCD_WF39TO36 = 0xFFFFFFFF;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method turns off all LCD segments.
 */
void KwikStikDisplay::TurnOffAllSegments(void)
{
  LCD_WF3TO0   = 0x00000000;
  LCD_WF7TO4   = 0x00000000;
  LCD_WF11TO8  = 0x00000000;
  LCD_WF15TO12 = 0x00000000;
  LCD_WF19TO16 = 0x00000000;
  LCD_WF23TO20 = 0x00000000;
  LCD_WF27TO24 = 0x00000000;
  LCD_WF31TO28 = 0x00000000;
  LCD_WF35TO32 = 0x00000000;
  LCD_WF39TO36 = 0x00000000;
}
