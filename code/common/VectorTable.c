/*****************************************************************************************************************************************************
*
*  VectorTable.c  -  This file contains the interrupt vector table class implementation.
*
*  Copyright (c) 2013, stokeware
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
#include <string.h>
#include "CommonTypes.h"
#include "VectorTable.h"

/*****************************************************************************************************************************************************
*
*  External Functions
*
*****************************************************************************************************************************************************/
/*
 * This function is the entry point for program execution defined in the IAR startup code.
 */
extern "C"  {
  void __iar_program_start(void);
}

/*****************************************************************************************************************************************************
*
*  Private Methods
*
*****************************************************************************************************************************************************/
/*
 * This static method is the default interrupt service routine for interrupts that have not been assigned a specific handler function.
 */
void VectorTable::DefaultIsr(void)
{
  while (true)  { }
}

/*****************************************************************************************************************************************************
*
*  Private Data
*
*****************************************************************************************************************************************************/
/*
 * This static constant data member is the copy of the interrupt vector table stored in flash memory.
 */
#pragma segment = "CSTACK"
#pragma location = ".flash_table"

const VectorTable::table VectorTable::flashTable = {
  __sfe("CSTACK"),              // 0x0000 - ARM core: Initial stack pointer
  {
    __iar_program_start,        // 0x0004 - ARM core: Initial program counter
    VectorTable::DefaultIsr,    // 0x0008 - ARM core: Non-maskable interrupt (NMI)
    VectorTable::DefaultIsr,    // 0x000C - ARM core: Hard fault
    VectorTable::DefaultIsr,    // 0x0010 - ARM core: MemManage fault
    VectorTable::DefaultIsr,    // 0x0014 - ARM core: Bus fault
    VectorTable::DefaultIsr,    // 0x0018 - ARM core: Usage fault
    VectorTable::DefaultIsr,    // 0x001C
    VectorTable::DefaultIsr,    // 0x0020
    VectorTable::DefaultIsr,    // 0x0024
    VectorTable::DefaultIsr,    // 0x0028
    VectorTable::DefaultIsr,    // 0x002C - ARM core: Supervisor call (SVCall))
    VectorTable::DefaultIsr,    // 0x0030 - ARM core: Debug monitor
    VectorTable::DefaultIsr,    // 0x0034
    VectorTable::DefaultIsr,    // 0x0038 - ARM core: Pendable request for system service (PendableSrvReq)
    VectorTable::DefaultIsr,    // 0x003C - ARM core: System tick timer (SysTick)
    VectorTable::DefaultIsr,    // 0x0040 - DMA: Channel 0 transfer complete
    VectorTable::DefaultIsr,    // 0x0044 - DMA: Channel 1 transfer complete
    VectorTable::DefaultIsr,    // 0x0048 - DMA: Channel 2 transfer complete
    VectorTable::DefaultIsr,    // 0x004C - DMA: Channel 3 transfer complete
    VectorTable::DefaultIsr,    // 0x0050 - DMA: Channel 4 transfer complete
    VectorTable::DefaultIsr,    // 0x0054 - DMA: Channel 5 transfer complete
    VectorTable::DefaultIsr,    // 0x0058 - DMA: Channel 6 transfer complete
    VectorTable::DefaultIsr,    // 0x005C - DMA: Channel 7 transfer complete
    VectorTable::DefaultIsr,    // 0x0060 - DMA: Channel 8 transfer complete
    VectorTable::DefaultIsr,    // 0x0064 - DMA: Channel 9 transfer complete
    VectorTable::DefaultIsr,    // 0x0068 - DMA: Channel 10 transfer complete
    VectorTable::DefaultIsr,    // 0x006C - DMA: Channel 11 transfer complete
    VectorTable::DefaultIsr,    // 0x0070 - DMA: Channel 12 transfer complete
    VectorTable::DefaultIsr,    // 0x0074 - DMA: Channel 13 transfer complete
    VectorTable::DefaultIsr,    // 0x0078 - DMA: Channel 14 transfer complete
    VectorTable::DefaultIsr,    // 0x007C - DMA: Channel 15 transfer complete
    VectorTable::DefaultIsr,    // 0x0080 - DMA: Error interrupt channels 0-15
    VectorTable::DefaultIsr,    // 0x0084 - MCM: Normal interrupt
    VectorTable::DefaultIsr,    // 0x0088 - Flash memory: Command complete
    VectorTable::DefaultIsr,    // 0x008C - Flash memory: Read collision
    VectorTable::DefaultIsr,    // 0x0090 - Mode controller: Low-voltage detect, low-voltage warning
    VectorTable::DefaultIsr,    // 0x0094 - LLWU: Low leakage wakeup
    VectorTable::DefaultIsr,    // 0x0098 - WDOG or EWM: Watchdog
    VectorTable::DefaultIsr,    // 0x009C
    VectorTable::DefaultIsr,    // 0x00A0 - I2C0
    VectorTable::DefaultIsr,    // 0x00A4 - I2C1
    VectorTable::DefaultIsr,    // 0x00A8 - SPI0: All sources
    VectorTable::DefaultIsr,    // 0x00AC - SPI1: All sources
    VectorTable::DefaultIsr,    // 0x00B0 - SPI2: All sources
    VectorTable::DefaultIsr,    // 0x00B4 - CAN0: OR'ed message buffer
    VectorTable::DefaultIsr,    // 0x00B8 - CAN0: Bus off
    VectorTable::DefaultIsr,    // 0x00BC - CAN0: Error
    VectorTable::DefaultIsr,    // 0x00C0 - CAN0: Transmit warning
    VectorTable::DefaultIsr,    // 0x00C4 - CAN0: Receive warning
    VectorTable::DefaultIsr,    // 0x00C8 - CAN0: Wake up
    VectorTable::DefaultIsr,    // 0x00CC - I2S0: Transmit
    VectorTable::DefaultIsr,    // 0x00D0 - I2S0: Receive
    VectorTable::DefaultIsr,    // 0x00D4 - CAN1: OR'ed message buffer
    VectorTable::DefaultIsr,    // 0x00D8 - CAN1: Bus off
    VectorTable::DefaultIsr,    // 0x00DC - CAN1: Error
    VectorTable::DefaultIsr,    // 0x00E0 - CAN1: Transmit warning
    VectorTable::DefaultIsr,    // 0x00E4 - CAN1: Receive warning
    VectorTable::DefaultIsr,    // 0x00E8 - CAN1: Wake up
    VectorTable::DefaultIsr,    // 0x00EC
    VectorTable::DefaultIsr,    // 0x00F0 - UART0: All LON sources
    VectorTable::DefaultIsr,    // 0x00F4 - UART0: All status sources
    VectorTable::DefaultIsr,    // 0x00F8 - UART0: All error sources
    VectorTable::DefaultIsr,    // 0x00FC - UART1: All status sources
    VectorTable::DefaultIsr,    // 0x0100 - UART1: All error sources
    VectorTable::DefaultIsr,    // 0x0104 - UART2: All status sources
    VectorTable::DefaultIsr,    // 0x0108 - UART2: All error sources
    VectorTable::DefaultIsr,    // 0x010C - UART3: All status sources
    VectorTable::DefaultIsr,    // 0x0110 - UART3: All error sources
    VectorTable::DefaultIsr,    // 0x0114 - UART4: All status sources
    VectorTable::DefaultIsr,    // 0x0118 - UART4: All error sources
    VectorTable::DefaultIsr,    // 0x011C - UART5: All status sources
    VectorTable::DefaultIsr,    // 0x0120 - UART5: All error sources
    VectorTable::DefaultIsr,    // 0x0124 - ADC0
    VectorTable::DefaultIsr,    // 0x0128 - ADC1
    VectorTable::DefaultIsr,    // 0x012C - CMP0
    VectorTable::DefaultIsr,    // 0x0130 - CMP1
    VectorTable::DefaultIsr,    // 0x0134 - CMP2
    VectorTable::DefaultIsr,    // 0x0138 - FTM0: All sources
    VectorTable::DefaultIsr,    // 0x013C - FTM1: All sources
    VectorTable::DefaultIsr,    // 0x0140 - FTM2: All sources
    VectorTable::DefaultIsr,    // 0x0144 - CMT
    VectorTable::DefaultIsr,    // 0x0148 - RTC: Alarm interrupt
    VectorTable::DefaultIsr,    // 0x014C - RTC: Seconds interrupt
    VectorTable::DefaultIsr,    // 0x0150 - PIT: Channel 0
    VectorTable::DefaultIsr,    // 0x0154 - PIT: Channel 1
    VectorTable::DefaultIsr,    // 0x0158 - PIT: Channel 2
    VectorTable::DefaultIsr,    // 0x015C - PIT: Channel 3
    VectorTable::DefaultIsr,    // 0x0160 - PDB
    VectorTable::DefaultIsr,    // 0x0164 - USB OTG
    VectorTable::DefaultIsr,    // 0x0168 - USB charger detect
    VectorTable::DefaultIsr,    // 0x016C
    VectorTable::DefaultIsr,    // 0x0170
    VectorTable::DefaultIsr,    // 0x0174
    VectorTable::DefaultIsr,    // 0x0178
    VectorTable::DefaultIsr,    // 0x017C
    VectorTable::DefaultIsr,    // 0x0180 - SDHC
    VectorTable::DefaultIsr,    // 0x0184 - DAC0
    VectorTable::DefaultIsr,    // 0x0188 - DAC1
    VectorTable::DefaultIsr,    // 0x018C - TSI: All sources
    VectorTable::DefaultIsr,    // 0x0190 - MCG
    VectorTable::DefaultIsr,    // 0x0194 - Low power timer
    VectorTable::DefaultIsr,    // 0x0198 - Segment LCD: All sources
    VectorTable::DefaultIsr,    // 0x019C - Port control module: Pin detect (Port A)
    VectorTable::DefaultIsr,    // 0x01A0 - Port control module: Pin detect (Port B)
    VectorTable::DefaultIsr,    // 0x01A4 - Port control module: Pin detect (Port C)
    VectorTable::DefaultIsr,    // 0x01A8 - Port control module: Pin detect (Port D)
    VectorTable::DefaultIsr,    // 0x01AC - Port control module: Pin detect (Port E)
    VectorTable::DefaultIsr,    // 0x01B0
    VectorTable::DefaultIsr,    // 0x01B4
    VectorTable::DefaultIsr     // 0x01B8 - Software: Software interrupt
  }
};
/*
 * This static constant data member is the copy of the interrupt vector table stored in RAM memory.
 */
#pragma data_alignment = 512

VectorTable::table VectorTable::ramTable;

/*****************************************************************************************************************************************************
*
*  Public Methods
*
*****************************************************************************************************************************************************/
/*
 * This method is the constructor for the vector table class.
 */
VectorTable::VectorTable(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This method is the destructor for the vector table class.
 */
VectorTable::~VectorTable(void)
{
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method initializes the vector table functionality.
 */
void VectorTable::Init(void)
{
  /*
   * Copy the contents of the vector table in flash memory to its RAM location.
   */
  memcpy(&VectorTable::ramTable, &VectorTable::flashTable, sizeof(VectorTable::table));
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method provides the starting vector table address.
 */
void* VectorTable::GetAddr(void)
{
  return (void*)&VectorTable::ramTable;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method sets the vector table entry corresponding to the specified interrupt to the specified interrupt service routine.
 */
void VectorTable::SetIsr(VectorTable::intrpt_id intrpt, VectorTable::isr* isrPtr)
{
  VectorTable::ramTable.isrPtr[(uint8)intrpt-1] = isrPtr;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
/*
 * This static method clears the vector table entry corresponding to the specified interrupt.
 */
void VectorTable::ClearIsr(VectorTable::intrpt_id intrpt)
{
  VectorTable::ramTable.isrPtr[(uint8)intrpt-1] = DefaultIsr;
}
