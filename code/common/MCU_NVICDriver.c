/*****************************************************************************************************************************************************
*
*  MCU_NVICDriver.c  -  Copyright 2012, stokeware
*
*  This file contains the MCU nested vectored interrupt controller driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_NVICDriver.h"
#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Constant Definitions
*
*****************************************************************************************************************************************************/
/*
 * These constants define the number of interrupt service routines contained in the vector table.
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
 *
 */
typedef struct {
  void*             stackPtr;
  vector_table_isr* isr[NUM_VECTOR_TABLE_ISR];
} vector_table;

/*****************************************************************************************************************************************************
*
*  Private Methods
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

static const vector_table vectorTable = {
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
 * This method is the constructor for the NVIC driver class.
 */
NVICDriver::NVICDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the NVIC driver class.
 */
NVICDriver::~NVICDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method initializes the NVIC module.
 */
void NVICDriver::InitModule(void)
{
  SCB_VTOR = (uint32)&vectorTable;
}
