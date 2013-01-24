/*****************************************************************************************************************************************************
*
*  SLCDDriver.h  -  Copyright 2013, stokeware
*
*  This file contains the LCD controller driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef SLCD_DRIVER_H
#define SLCD_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the SLCD driver class. It is derived from the peripheral driver abstract base class.
 */
class SLCDDriver : public PeriphDriver
{
  /****************
   * Public Types
   ***************/
  public:
  /*
   * This type defines the available LCD pins.
   */
  typedef enum  {
    PIN_0 = 0, PIN_1,  PIN_2,  PIN_3,  PIN_4,  PIN_5,  PIN_6,  PIN_7,  PIN_8,  PIN_9,  PIN_10, PIN_11, PIN_12, PIN_13, PIN_14, PIN_15,
    PIN_16   , PIN_17, PIN_18, PIN_19, PIN_20, PIN_21, PIN_22, PIN_23, PIN_24, PIN_25, PIN_26, PIN_27, PIN_28, PIN_29, PIN_30, PIN_31,
    PIN_32   , PIN_33, PIN_34, PIN_35, PIN_36, PIN_37, PIN_38, PIN_39, PIN_40, PIN_41, PIN_42, PIN_43, PIN_44, PIN_45, PIN_46, PIN_47,
    PIN_48   , PIN_49, PIN_50, PIN_51, PIN_52, PIN_53, PIN_54, PIN_55, PIN_56, PIN_57, PIN_58, PIN_59, PIN_60, PIN_61, PIN_62, PIN_63
  } pin_id;

  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the SLCD driver class.
   */
  SLCDDriver(void);
  ~SLCDDriver(void);
  /*
   * This static method initializes the SLCD module.
   */
  static void InitModule(void);
  /*
   * These static methods enable and disable the LCD controller waveform generator.
   */
  static void EnableCtrl(void);
  static void DisableCtrl(void);
  /*
   * These static methods enable and disable the specified LCD pin.
   */
  static void EnablePin(pin_id pin);
  static void DisablePin(pin_id pin);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the SLCD register structure.
   */
  static LCD_MemMapPtr moduleReg;
};

#endif
