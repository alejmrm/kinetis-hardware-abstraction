/*****************************************************************************************************************************************************
*
*  SLCDDriver.h  -  This file contains the LCD controller driver class interface.
*
*  Copyright (c) 2013, stokeware
*
*  Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above
*  copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
*  IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*****************************************************************************************************************************************************/
#ifndef SLCD_DRIVER_H
#define SLCD_DRIVER_H

#include <MK40DZ10.h>
#include "CommonTypes.h"
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
  /*
   * This type defines the operations for which the LCD pins can be configured.
   */
  typedef enum  {
    PIN_OPERATION_FRONTPLANE = 0,
    PIN_OPERATION_BACKPLANE
  } pin_operation;
  /*
   * This type defines the front plane segments to which each LCD pin may be connected.
   */
  typedef enum  {
    FRONTPLANE_SEGMENT_A = 0, FRONTPLANE_SEGMENT_B, FRONTPLANE_SEGMENT_C, FRONTPLANE_SEGMENT_D,
    FRONTPLANE_SEGMENT_E,     FRONTPLANE_SEGMENT_F, FRONTPLANE_SEGMENT_G, FRONTPLANE_SEGMENT_H
  } frontplane_segment;
  /*
   * This type defines a mechanism for accessing multiple front plane segments in a single operation. The segment pattern is an 8-bit value in which
   * the individual bits correspond to the values defined in the segment_id type.
   */
  typedef uint8 frontplane_segment_pattern;
  /*
   * This type defines the back plane phases to which each LCD pin may be connected.
   */
  typedef enum  {
    BACKPLANE_PHASE_A = 0, BACKPLANE_PHASE_B, BACKPLANE_PHASE_C, BACKPLANE_PHASE_D,
    BACKPLANE_PHASE_E,     BACKPLANE_PHASE_F, BACKPLANE_PHASE_G, BACKPLANE_PHASE_H
  } backplane_phase;
  /*
   * This type defines a mechanism for accessing multiple back plane phases in a single operation. The phase pattern is an 8-bit value in which the
   * individual bits correspond to the values defined in the phase_id type.
   */
  typedef uint8 backplane_phase_pattern;

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
  /*
   * This static method sets the operation of the specified pin.
   */
  static void SetPinOperation(pin_id pin, pin_operation operation);

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
