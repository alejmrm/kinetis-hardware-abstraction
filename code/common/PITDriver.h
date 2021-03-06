/*****************************************************************************************************************************************************
*
*  PITDriver.h  -  This file contains the periodic interrupt timer driver class interface.
*
*  Copyright (c) 2012-2013, stokeware
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
#ifndef PIT_DRIVER_H
#define PIT_DRIVER_H

#include <MK40DZ10.h>
#include "CommonTypes.h"
#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the PIT driver class. It is derived from the peripheral driver abstract base class.
 */
class PITDriver : public PeriphDriver
{
  /****************
   * Public Types
   ***************/
  public:
  /*
   * This type defines the superset of available PIT timers. In general, for a specific MCU, only some of the timers are available.
   */
  typedef enum  {
    TMR_0 = 0, TMR_1, TMR_2, TMR_3,
    NUM_TMRS
  } tmr_id;

  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the PIT driver class.
   */
  PITDriver(void);
  ~PITDriver(void);
  /*
   * This static method enables the PIT module.
   */
  static void EnableModule(void);
  /*
   * This static method sets the timeout period for the specified timer.
   */
  static void SetPeriod(tmr_id tmr, uint32 period);
  /*
   * This static method provides the present count value for the specified timer.
   */
  static uint32 GetCnt(tmr_id tmr);
  /*
   * These static methods enable and disable the specified timer.
   */
  static void EnableTmr(tmr_id tmr);
  static void DisableTmr(tmr_id tmr);
  /*
   * These static methods enable and disable the interrupt corresponding to the specified timer.
   */
  static void EnableIntrpt(tmr_id tmr);
  static void DisableIntrpt(tmr_id tmr);
  /*
   * This static method indicates whether the interrupt corresponding to the specified timer is pending.
   */
  static bool IntrptIsPending(tmr_id tmr);
  /*
   * This static method clears the interrupt corresponding to the specified timer.
   */
  static void ClearIntrpt(tmr_id tmr);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the PIT register structure, which encompasses all of the individual timers.
   */
  static PIT_MemMapPtr moduleReg;
};

#endif
