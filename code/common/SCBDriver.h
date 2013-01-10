/*****************************************************************************************************************************************************
*
*  SCBDriver.h  -  Copyright 2012-2013, stokeware
*
*  This file contains the system control block driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef SCB_DRIVER_H
#define SCB_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the SCB driver class. It is derived from the peripheral driver abstract base class.
 */
class SCBDriver : public PeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the SCB driver class.
   */
  SCBDriver(void);
  ~SCBDriver(void);
  /*
   * This static method sets the starting address of the vector table.
   */
  static void SetVectorTableAddr(void* addr);
};

#endif
