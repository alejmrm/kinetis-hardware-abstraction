/*****************************************************************************************************************************************************
*
*  NVICDriver.h  -  This file contains the nested vectored interrupt controller driver class interface.
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
#ifndef NVIC_DRIVER_H
#define NVIC_DRIVER_H

#include <MK40DZ10.h>
#include "CoreDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the NVIC driver class. It is derived from the core driver abstract base class.
 */
class NVICDriver : public CoreDriver
{
  /****************
   * Public Types
   ***************/
  public:
  /*
   * This type defines the interrupts managed by the NVIC.
   */
  typedef enum  {
    INTRPT_PIT_0 = 68,
    INTRPT_PIT_1 = 69,
    INTRPT_PIT_2 = 70,
    INTRPT_PIT_3 = 71
  } intrpt_id;

  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the NVIC driver class.
   */
  NVICDriver(void);
  ~NVICDriver(void);
  /*
   * This static method enables the specified interrupt.
   */
  static void EnableIntrpt(NVICDriver::intrpt_id intrpt);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the NVIC register structure.
   */
  static NVIC_MemMapPtr moduleReg;
};

#endif
