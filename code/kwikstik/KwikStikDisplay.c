/*****************************************************************************************************************************************************
*
*  KwikStikDisplay.c  -  Copyright 2013, stokeware
*
*  This file contains the KwikStik display class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "CommonTypes.h"
#include "KwikStikDisplay.h"
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
  // Master General Purpose Control Register - Set mux to LCD analog operation.
  // After RESET these register are configured as 0 but indicated here for reference
  PORTB_PCR1  = PORT_PCR_MUX(0); //LCD_P1
  PORTB_PCR2  = PORT_PCR_MUX(0); //LCD_P2
  PORTB_PCR3  = PORT_PCR_MUX(0); //LCD_P3
  PORTB_PCR4  = PORT_PCR_MUX(0); //LCD_P4
  PORTB_PCR5  = PORT_PCR_MUX(0); //LCD_P5
  PORTB_PCR6  = PORT_PCR_MUX(0); //LCD_P6
  PORTB_PCR7  = PORT_PCR_MUX(0); //LCD_P7
  PORTB_PCR8  = PORT_PCR_MUX(0); //LCD_P8
  PORTB_PCR9  = PORT_PCR_MUX(0); //LCD_P9
  PORTB_PCR10 = PORT_PCR_MUX(0); //LCD_P10
  PORTB_PCR11 = PORT_PCR_MUX(0); //LCD_P11
  PORTB_PCR16 = PORT_PCR_MUX(0); //LCD_P12
  PORTB_PCR17 = PORT_PCR_MUX(0); //LCD_P13
  PORTB_PCR18 = PORT_PCR_MUX(0); //LCD_P14
  PORTB_PCR19 = PORT_PCR_MUX(0); //LCD_P15
  PORTB_PCR20 = PORT_PCR_MUX(0); //LCD_P16
  PORTB_PCR21 = PORT_PCR_MUX(0); //LCD_P17
  PORTB_PCR22 = PORT_PCR_MUX(0); //LCD_P18
  PORTB_PCR23 = PORT_PCR_MUX(0); //LCD_P19
  PORTC_PCR0  = PORT_PCR_MUX(0); //LCD_P20
  PORTC_PCR1  = PORT_PCR_MUX(0); //LCD_P21
  PORTC_PCR2  = PORT_PCR_MUX(0); //LCD_P22
  PORTC_PCR3  = PORT_PCR_MUX(0); //LCD_P23
  PORTC_PCR4  = PORT_PCR_MUX(0); //LCD_P24
  PORTC_PCR5  = PORT_PCR_MUX(0); //LCD_P25
  PORTC_PCR6  = PORT_PCR_MUX(0); //LCD_P26
  PORTC_PCR7  = PORT_PCR_MUX(0); //LCD_P27
  PORTC_PCR8  = PORT_PCR_MUX(0); //LCD_P28
  PORTC_PCR9  = PORT_PCR_MUX(0); //LCD_P29
  PORTC_PCR10 = PORT_PCR_MUX(0); //LCD_P30
  PORTC_PCR11 = PORT_PCR_MUX(0); //LCD_P31
  PORTC_PCR12 = PORT_PCR_MUX(0); //LCD_P32
  PORTC_PCR13 = PORT_PCR_MUX(0); //LCD_P33
  PORTC_PCR14 = PORT_PCR_MUX(0); //LCD_P34
  PORTC_PCR15 = PORT_PCR_MUX(0); //LCD_P35
  PORTC_PCR16 = PORT_PCR_MUX(0); //LCD_P36
  PORTC_PCR17 = PORT_PCR_MUX(0); //LCD_P37
  PORTC_PCR18 = PORT_PCR_MUX(0); //LCD_P38
  PORTC_PCR19 = PORT_PCR_MUX(0); //LCD_P39
  PORTD_PCR0  = PORT_PCR_MUX(0); //LCD_P40
  PORTD_PCR1  = PORT_PCR_MUX(0); //LCD_P41
  PORTD_PCR2  = PORT_PCR_MUX(0); //LCD_P42
  PORTD_PCR3  = PORT_PCR_MUX(0); //LCD_P43
  PORTD_PCR4  = PORT_PCR_MUX(0); //LCD_P44
  PORTD_PCR5  = PORT_PCR_MUX(0); //LCD_P45
  PORTD_PCR6  = PORT_PCR_MUX(0); //LCD_P46
  PORTD_PCR7  = PORT_PCR_MUX(0); //LCD_P47
  /*
   * Disable the LCD controller waveform generator.
   */
  SLCDDriver::DisableCtrl();

  // Enable LCD pins 1-47
  LCD_PENH = 0;
  LCD_PENH = 0x0000FFFF;
  LCD_PENL = 0;
  LCD_PENL = 0xFFFFFFFE;
  // Enable LCD pins used as Backplanes 0-7
  LCD_BPENH = 0;
  LCD_BPENH = 0x0000FF00;
  LCD_BPENL = 0;
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
