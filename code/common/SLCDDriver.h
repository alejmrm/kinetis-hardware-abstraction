/*****************************************************************************************************************************************************
*
*  SLCDDriver.h  -  Copyright 2013, stokeware
*
*  This file contains the LCD controller driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef SLCD_DRIVER_H
#define SLCD_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the SLCD driver class. It is derived from the peripheral driver abstract base class.
 */
class SLCDDriver : public PeriphDriver
{
  /****************
   * Public Types
   ***************/
  public:

  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the SLCD driver class.
   */
  SLCDDriver(void);
  ~SLCDDriver(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the SLCD register structure.
   */
  static LCD_MemMapPtr moduleReg;
};

#endif
