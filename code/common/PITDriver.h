/*****************************************************************************************************************************************************
*
*  PITDriver.h  -  Copyright 2012-2013, stokeware
*
*  This file contains the periodic interrupt timer driver class interface.
*
*****************************************************************************************************************************************************/
#ifndef PIT_DRIVER_H
#define PIT_DRIVER_H

#include <freescale/MK40X256VMD100.h>
#include "CommonTypes.h"
#include "PeriphDriver.h"

/*****************************************************************************************************************************************************
*
*  Type Definitions
*
*****************************************************************************************************************************************************/
/*
 * This type defines the superset of available PIT timers. In general, for a specific MCU, only some of the timers are available.
 */
typedef enum  {
  PIT_TMR_0 = 0, PIT_TMR_1, PIT_TMR_2, PIT_TMR_3,
  NUM_PIT_TMRS
} pit_tmr;

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the PIT driver class. It is derived from the peripheral driver abstract base class.
 */
class PITDriver : public PeriphDriver
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the PIT driver class.
   */
  PITDriver(pit_tmr tmr);
  ~PITDriver(void);
  /*
   * This static method enables the PIT module.
   */
  static void EnableModule(void);
  /*
   * This method sets the timeout period for the timer managed by the class instance.
   */
  void SetPeriod(uint32 period);
  /*
   * This method provides the present count value for the timer managed by the class instance.
   */
  uint32 GetCnt(void);
  /*
   * These methods enable and disable the timer managed by the class instance.
   */
  void EnableTmr(void);
  void DisableTmr(void);
  /*
   * These methods enable and disable the interrupt corresponding to the timer managed by the class instance.
   */
  void EnableIntrpt(void);
  void DisableIntrpt(void);
  /*
   * This method indicates whether the interrupt corresponding to the timer managed by the class instance is pending.
   */
  bool IntrptIsPending(void);
  /*
   * This method clears the interrupt corresponding to the timer managed by the class instance.
   */
  void ClearIntrpt(void);

  /****************
   * Private Data
   ***************/
  private:
  /*
   * This static data member is a pointer to the PIT register structure, which encompasses all of the individual timers.
   */
  static PIT_MemMapPtr pitReg;
  /*
   * This data member is the timer managed by this class instance.
   */
  pit_tmr tmr;
};

#endif
