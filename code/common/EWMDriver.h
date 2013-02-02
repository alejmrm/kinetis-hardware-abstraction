/*****************************************************************************************************************************************************
*
*  EWMDriver.h  -  Copyright 2013, stokeware
*
*  This file contains the external watchdog monitor driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef EWM_DRIVER_H
#define EWM_DRIVER_H

#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the EWM driver class. It is derived from the peripheral driver abstract base class.
 */
class EWMDriver : public PeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the EWM driver class.
   */
  EWMDriver(void);
  ~EWMDriver(void);
  /*
   * This static method enables the EWM module.
   */
  static void EnableModule(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the EWM register structure.
   */
  static EWM_MemMapPtr moduleReg;
};

#endif
