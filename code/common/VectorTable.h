/*****************************************************************************************************************************************************
*
*  VectorTable.h  -  Copyright 2013, stokeware
*
*  This file contains the interrupt vector table class interface.
*
*****************************************************************************************************************************************************/
#ifndef VECTOR_TABLE_H
#define VECTOR_TABLE_H

#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Constant Definitions
*
*****************************************************************************************************************************************************/
/*
 * This constant defines the number of interrupt service routines contained in the vector table.
 */
#define NUM_VECTOR_TABLE_ISR  110

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
/*
 * This type defines the signature of interrupt service routines appearing in the vector table.
 */
typedef void vector_table_isr(void);
/*
 * This type defines the interrupt vector table structure.
 */
typedef struct {
  void*             stackPtr;                     // Initial stack pointer
  vector_table_isr* isr[NUM_VECTOR_TABLE_ISR];    // Array of pointers to interrupt service routines
} vector_table;

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
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the vector table class.
   */
  VectorTable(void);
  ~VectorTable(void);

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
  static const vector_table vectorTable;
};

#endif
