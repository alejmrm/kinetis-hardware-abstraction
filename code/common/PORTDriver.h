/*****************************************************************************************************************************************************
*
*  PORTDriver.h  -  This file contains the port control and interrupt driver class interface.
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
#ifndef PORT_DRIVER_H
#define PORT_DRIVER_H

#include <MK40DZ10.h>
#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the PORT driver class. It is derived from the peripheral driver abstract base class.
 */
class PORTDriver : public PeriphDriver
{
  /*********************
   * Private Constants
   ********************/
  private:
  /*
   * This constant defines the number of ports.
   */
  enum {NUM_PORTS = 5};

  /****************
   * Public Types
   ***************/
  public:
  /*
   * This type defines the available port pins.
   */
  typedef enum  {
    /*
     * Port A.
     */
    PIN_A0 = 0, PIN_A1,  PIN_A2,  PIN_A3,  PIN_A4,  PIN_A5,  PIN_A6,  PIN_A7,
    PIN_A8,     PIN_A9,  PIN_A10, PIN_A11, PIN_A12, PIN_A13, PIN_A14, PIN_A15,
    PIN_A16,    PIN_A17, PIN_A18, PIN_A19, PIN_A20, PIN_A21, PIN_A22, PIN_A23,
    PIN_A24,    PIN_A25, PIN_A26, PIN_A27, PIN_A28, PIN_A29, PIN_A30, PIN_A31,
    /*
     * Port B.
     */
    PIN_B0,     PIN_B1,  PIN_B2,  PIN_B3,  PIN_B4,  PIN_B5,  PIN_B6,  PIN_B7,
    PIN_B8,     PIN_B9,  PIN_B10, PIN_B11, PIN_B12, PIN_B13, PIN_B14, PIN_B15,
    PIN_B16,    PIN_B17, PIN_B18, PIN_B19, PIN_B20, PIN_B21, PIN_B22, PIN_B23,
    PIN_B24,    PIN_B25, PIN_B26, PIN_B27, PIN_B28, PIN_B29, PIN_B30, PIN_B31,
    /*
     * Port C.
     */
    PIN_C0,     PIN_C1,  PIN_C2,  PIN_C3,  PIN_C4,  PIN_C5,  PIN_C6,  PIN_C7,
    PIN_C8,     PIN_C9,  PIN_C10, PIN_C11, PIN_C12, PIN_C13, PIN_C14, PIN_C15,
    PIN_C16,    PIN_C17, PIN_C18, PIN_C19, PIN_C20, PIN_C21, PIN_C22, PIN_C23,
    PIN_C24,    PIN_C25, PIN_C26, PIN_C27, PIN_C28, PIN_C29, PIN_C30, PIN_C31,
    /*
     * Port D.
     */
    PIN_D0,     PIN_D1,  PIN_D2,  PIN_D3,  PIN_D4,  PIN_D5,  PIN_D6,  PIN_D7,
    PIN_D8,     PIN_D9,  PIN_D10, PIN_D11, PIN_D12, PIN_D13, PIN_D14, PIN_D15,
    PIN_D16,    PIN_D17, PIN_D18, PIN_D19, PIN_D20, PIN_D21, PIN_D22, PIN_D23,
    PIN_D24,    PIN_D25, PIN_D26, PIN_D27, PIN_D28, PIN_D29, PIN_D30, PIN_D31,
    /*
     * Port E.
     */
    PIN_E0,     PIN_E1,  PIN_E2,  PIN_E3,  PIN_E4,  PIN_E5,  PIN_E6,  PIN_E7,
    PIN_E8,     PIN_E9,  PIN_E10, PIN_E11, PIN_E12, PIN_E13, PIN_E14, PIN_E15,
    PIN_E16,    PIN_E17, PIN_E18, PIN_E19, PIN_E20, PIN_E21, PIN_E22, PIN_E23,
    PIN_E24,    PIN_E25, PIN_E26, PIN_E27, PIN_E28, PIN_E29, PIN_E30, PIN_E31
  } pin_id;
  /*
   * This type defines the port multiplexing modes for which the pins can be configured.
   */
  typedef enum  {
    PIN_MUX_MODE_DISABLED_ANALOG = 0,
    PIN_MUX_MODE_ALT_1_GPIO      = 1,
    PIN_MUX_MODE_ALT_2           = 2,
    PIN_MUX_MODE_ALT_3           = 3,
    PIN_MUX_MODE_ALT_4           = 4,
    PIN_MUX_MODE_ALT_5           = 5,
    PIN_MUX_MODE_ALT_6           = 6,
    PIN_MUX_MODE_ALT_7           = 7
  } pin_mux_mode;
  /*
   * This type defines the port interrupt and DMA modes for which the pins can be configured.
   */
  typedef enum  {
    PIN_INT_DMA_MODE_DISABLED         = 0,
    PIN_INT_DMA_MODE_DMA_RISING_EDGE  = 1,
    PIN_INT_DMA_MODE_DMA_FALLING_EDGE = 2,
    PIN_INT_DMA_MODE_DMA_EITHER_EDGE  = 3,
    PIN_INT_DMA_MODE_INT_LVL_LO       = 8,
    PIN_INT_DMA_MODE_INT_RISING_EDGE  = 9,
    PIN_INT_DMA_MODE_INT_FALLING_EDGE = 10,
    PIN_INT_DMA_MODE_INT_EITHER_EDGE  = 11,
    PIN_INT_DMA_MODE_INT_LVL_HI       = 12
  } pin_int_dma_mode;

  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the PORT driver class.
   */
  PORTDriver(void);
  ~PORTDriver(void);
  /*
   * This static method clears the interrupt status for the specified pin.
   */
  static void ClearIntStatus(pin_id pin);
  /*
   * This static method configures the multiplexing mode for the specified pin.
   */
  static void SetMuxMode(pin_id pin, pin_mux_mode mode);
  /*
   * This static method configures the interrupt and DMA mode for the specified pin.
   */
  static void SetIntDmaMode(pin_id pin, pin_int_dma_mode mode);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is an array containing pointers to the PORT register structures for each of the ports.
   */
  static PORT_MemMapPtr moduleReg[NUM_PORTS];
};

#endif
