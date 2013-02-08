/*****************************************************************************************************************************************************
*
*  PeriphDriver.h  -  This file contains the MCU peripheral driver class interface.
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
#ifndef PERIPH_DRIVER_H
#define PERIPH_DRIVER_H

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the peripheral driver abstract base class.
 */
class PeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * This method is the pure virtual destructor for the peripheral driver abstract base class.
   */
  virtual ~PeriphDriver(void) = 0;
};

#endif
