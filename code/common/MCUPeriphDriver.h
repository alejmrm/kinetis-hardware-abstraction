/*****************************************************************************************************************************************************
*
*  MCUPeriphDriver.h  -  Copyright 2012, stokeware
*
*  This file contains the MCU peripheral driver base class definitions.
*
*****************************************************************************************************************************************************/
#ifndef MCU_PERIPH_DRIVER_H
#define MCU_PERIPH_DRIVER_H

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the MCU peripheral driver abstract base class.
 */
class MCUPeriphDriver
{
  public:
    MCUPeriphDriver(void)  { };
    ~MCUPeriphDriver(void)  { };
};
/*
 * This class is the MCU IO port peripheral driver class, derived from the MCU peripheral driver abstract base class.
 */
class MCUIOPortDriver : public MCUPeriphDriver
{
  public:
    MCUIOPortDriver(void)  { };
    ~MCUIOPortDriver(void)  { };
    void SetPinLvl(void);
    void GetPinLvl(void);
};

#endif
