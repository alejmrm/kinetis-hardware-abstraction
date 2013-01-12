/*****************************************************************************************************************************************************
*
*  VectorTable.h  -  Copyright 2013, stokeware
*
*  This file contains the interrupt vector table class interface.
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
  } table_format;

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
   * This static method provides the starting vector table address.
   */
  static void* GetAddr(void);

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
   * This static constant data member is the interrupt vector table.
   */
  static const table_format table;
};

#endif
