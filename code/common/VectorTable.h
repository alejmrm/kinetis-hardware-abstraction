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
};

#endif
