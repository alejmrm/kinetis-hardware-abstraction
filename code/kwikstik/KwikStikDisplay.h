/*****************************************************************************************************************************************************
*
*  KwikStikDisplay.h  -  This file contains the KwikStik display class interface.
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
#ifndef KWIKSTIK_DISPLAY_H
#define KWIKSTIK_DISPLAY_H

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the KwikStik display class.
 */
class KwikStikDisplay
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the KwikStik display class.
   */
  KwikStikDisplay(void);
  ~KwikStikDisplay(void);
  /*
   * This static method initializes the KwikStik display.
   */
  static void Init(void);
  /*
   * These static methods turn on and turn off all LCD segments.
   */
  static void TurnOnAllSegments(void);
  static void TurnOffAllSegments(void);
};

#endif
