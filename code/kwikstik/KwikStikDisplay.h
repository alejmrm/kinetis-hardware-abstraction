/*****************************************************************************************************************************************************
*
*  KwikStikDisplay.h  -  Copyright 2013, stokeware
*
*  This file contains the KwikStik display class interface.
*
*****************************************************************************************************************************************************/
#ifndef KWIKSTIK_DISPLAY_H
#define KWIKSTIK_DISPLAY_H

/*****************************************************************************************************************************************************
*
*  Class Definitions
*
*****************************************************************************************************************************************************/
/*
 * This class is the KwikStik display class.
 */
class KwikStikDisplay
{
  /******************
   * Public Methods
   *****************/
  public:
  /*
   * These methods are the constructor and destructor for the KwikStik display class.
   */
  KwikStikDisplay(void);
  ~KwikStikDisplay(void);
  /*
   * This static method initializes the KwikStik display.
   */
  static void Init(void);
};

#endif
