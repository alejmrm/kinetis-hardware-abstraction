/*****************************************************************************************************************************************************
*
*  VectorTable.h  -  This file contains the interrupt vector table class interface.
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
#ifndef VECTOR_TABLE_H
#define VECTOR_TABLE_H

#include "CommonTypes.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the vector table class.
 */
class VectorTable
{
  /*********************
   * Private Constants
   ********************/
  private:
  /*
   * This constant defines the number of interrupt service routines contained in the vector table.
   */
  enum {NUM_ISRS = 110};

  /****************
   * Public Types
   ***************/
  public:
  /*
   * This type defines the interrupts supported by the vector table class.
   */
  typedef enum  {
    INTRPT_PIT_0 = 84,
    INTRPT_PIT_1 = 85,
    INTRPT_PIT_2 = 86,
    INTRPT_PIT_3 = 87
  } intrpt_id;
  /*
   * This type defines the signature of interrupt service routines appearing in the vector table.
   */
  typedef void isr(void);

  /*****************
   * Private Types
   ****************/
  private:
  /*
   * This type defines the interrupt vector table format.
   */
  typedef struct {
    void* stackPtr;            // Initial stack pointer
    isr*  isrPtr[NUM_ISRS];    // Array of pointers to interrupt service routines
  } table;

  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the vector table class.
   */
  VectorTable(void);
  ~VectorTable(void);
  /*
   * This static method initializes the vector table functionality.
   */
  static void Init(void);
  /*
   * This static method provides the starting vector table address.
   */
  static void* GetAddr(void);
  /*
   * This static method sets the vector table entry corresponding to the specified interrupt to the specified interrupt service routine.
   */
  static void SetIsr(intrpt_id intrpt, isr* isrPtr);
  /*
   * This static method clears the vector table entry corresponding to the specified interrupt.
   */
  static void ClearIsr(intrpt_id intrpt);

  /*******************
   * Private Methods
   ******************/
  private:
  /*
   * This static method is the default interrupt service routine for interrupts that have not been assigned a specific handler function.
   */
  static void DefaultIsr(void);

  /****************
   * Private Data
   ***************/
  /*
   * This static constant data member is the copy of the interrupt vector table stored in flash memory.
   */
  static const table flashTable;
  /*
   * This static data member is the copy of the interrupt vector table stored in RAM memory.
   */
  static table ramTable;
};

#endif
