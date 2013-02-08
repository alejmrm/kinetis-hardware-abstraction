/*****************************************************************************************************************************************************
*
*  SCBDriver.c  -  This file contains the system control block driver class implementation.
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
#include "SCBDriver.h"

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the SCB driver class.
 */
SCBDriver::SCBDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the SCB driver class.
 */
SCBDriver::~SCBDriver(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method sets the starting address of the vector table.
 */
void SCBDriver::SetVectorTableAddr(void* addr)
{
  SCB_VTOR = (uint32)addr;
}
