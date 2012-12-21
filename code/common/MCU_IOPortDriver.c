/*****************************************************************************************************************************************************
*
*  MCU_IOPortDriver.c  -  Copyright 2012, stokeware
*
*  This file contains the MCU I/O port driver class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_IOPortDriver.h"
#include "MCU_Types.h"

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the I/O port peripheral driver class.
 */
IOPortDriver::IOPortDriver(io_port port)
{
  this->port = port;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the I/O port peripheral driver class.
 */
IOPortDriver::~IOPortDriver(void)
{
}
