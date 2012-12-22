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
#pragma section = ".intvec"

void NVICDriver::InitModule(void)
{
  SCB_VTOR = (unsigned int)__segment_begin(".intvec");
}
