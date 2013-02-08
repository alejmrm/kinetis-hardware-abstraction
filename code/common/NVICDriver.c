/*****************************************************************************************************************************************************
*
*  NVICDriver.c  -  This file contains the nested vectored interrupt controller driver class implementation.
*
*  Copyright (c) 2012-2013, stokeware
*
*  Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above
*  copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
*  IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*****************************************************************************************************************************************************/
#include "MK40DZ10.h"
#include "CommonTypes.h"
#include "NVICDriver.h"

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static data member is a pointer to the NVIC register structure.
 */
NVIC_MemMapPtr NVICDriver::moduleReg = NVIC_BASE_PTR;

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
 * This static method enables the specified interrupt.
 */
void NVICDriver::EnableIntrpt(NVICDriver::intrpt_id intrpt)
{
  /*
   * Set the bit in the interrupt set-enable register corresponding to the specified interrupt.
   */
  moduleReg->ISER[(uint8)intrpt >> 5] |= ((uint32)1 << ((uint8)intrpt & 0x1F));
}
