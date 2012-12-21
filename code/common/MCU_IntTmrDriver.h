/*****************************************************************************************************************************************************
*
*  MCU_IntTmrDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU periodic interrupt timer driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef MCU_INT_TMR_DRIVER_H
#define MCU_INT_TMR_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "MCU_PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
/*
 * This type defines the superset of available periodic interrupt timers. In general, for a specific MCU, only some of the timers are available.
 */
typedef enum  {
  INT_TMR_0 = 0, INT_TMR_1, INT_TMR_2, INT_TMR_3,
  NUM_INT_TMRS
} int_tmr;

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the periodic interrupt timer peripheral driver class. It is derived from the peripheral driver abstract base class.
 */
class IntTmrDriver : public MCUPeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the periodic interrupt timer peripheral driver class.
   */
  IntTmrDriver(int_tmr tmr);
  ~IntTmrDriver(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the MCU periodic interrupt timer register structure, which encompasses all of the individual timers.
   */
  static PIT_MemMapPtr tmrGroupReg;
  /*
   * This data member is the timer managed by this class instance.
   */
  int_tmr tmr;
};

#endif
