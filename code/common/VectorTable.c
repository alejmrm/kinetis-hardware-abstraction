/*****************************************************************************************************************************************************
*
*  VectorTable.c  -  Copyright 2013, stokeware
*
*  This file contains the interrupt vector table class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_Types.h"
#include "VectorTable.h"

/*****************************************************************************************************************************************************
*
*  Private Functions
*
*****************************************************************************************************************************************************/
/*
 * This function is the default interrupt service routine for interrupts that have not been assigned a specific handler function.
 */
static void DefaultIsr(void)
{
  while (true)  { }
}

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static constant variable ...
 */
#define vectorTable __vector_table
#pragma language=extended
#pragma segment="CSTACK"

extern "C"  {
  void __iar_program_start(void);
}

#pragma location = ".intvec"

vector_table vectorTable = {
  __sfe("CSTACK"),
  {
    __iar_program_start,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr,
    DefaultIsr
  }
};

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the vector table class.
 */
VectorTable::VectorTable(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the vector table class.
 */
VectorTable::~VectorTable(void)
{
}
