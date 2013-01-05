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
*  External Functions
*
*****************************************************************************************************************************************************/
/*
 * This function is the entry point for program execution defined in the IAR startup code.
 */
extern "C"  {
  void __iar_program_start(void);
}

/*****************************************************************************************************************************************************
*
*  Private Methods
*
*****************************************************************************************************************************************************/
/*
 * This static method is the default interrupt service routine for interrupts that have not been assigned a specific handler function.
 */
void VectorTable::DefaultIsr(void)
{
  while (true)  { }
}

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static constant data member is the interrupt vector table.
 */
#pragma segment = "CSTACK"
#pragma location = ".intvec"

const vector_table VectorTable::vectorTable = {
  __sfe("CSTACK"),
  {
    __iar_program_start,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr,
    VectorTable::DefaultIsr
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
