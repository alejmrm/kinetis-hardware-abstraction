/*****************************************************************************************************************************************************
*
*  EWMDriver.h  -  This file contains the external watchdog monitor driver class interface.
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
#ifndef EWM_DRIVER_H
#define EWM_DRIVER_H

#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the EWM driver class. It is derived from the peripheral driver abstract base class.
 */
class EWMDriver : public PeriphDriver
{
  /****************
   * Public Types
   ***************/
  public:
  /*
   * This type defines the supported assert states of the EWM input signal.
   */
  typedef enum  {
    ASSERT_STATE_ZERO = 0,
    ASSERT_STATE_ONE
  } assert_state;

  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the EWM driver class.
   */
  EWMDriver(void);
  ~EWMDriver(void);
  /*
   * This static method enables the EWM module.
   */
  static void EnableModule(void);
  /*
   * This static method sets the assert state of the EWM input signal.
   */
  static void SetAssertState(assert_state state);
  /*
   * These static methods enable and disable the EWM input port.
   */
  static void EnableInput(void);
  static void DisableInput(void);
  /*
   * These static methods enable and disable the EWM interrupt.
   */
  static void EnableIntrpt(void);
  static void DisableIntrpt(void);
  /*
   * This static method sets the EWM clock prescaler value.
   */
  static void SetClkPrescaler(uint8 val);
  /*
   * These static methods set the low and high EWM compare values, which define the range of timer counts within which the external watchdog must be
   * serviced.
   */
  static void SetLoCompVal(uint8 val);
  static void SetHiCompVal(uint8 val);
  /*
   * This static method method services the external watchdog.
   */
  static void ServiceWatchdog(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the EWM register structure.
   */
  static EWM_MemMapPtr moduleReg;
  /*
   * These static data members are flags that indicate whether the associated EWM registers have been written.
   */
  static bool moduleIsEnabled;
  static bool clkPrescalerIsSet;
  static bool loCompValIsSet;
  static bool hiCompValIsSet;
};

#endif
