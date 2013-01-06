/*****************************************************************************************************************************************************
*
*  VectorTable.c  -  Copyright 2013, stokeware
*
*  This file contains the interrupt vector table class implementation.
*
*****************************************************************************************************************************************************/
#include <freescale/MK40X256VMD100.h>
#include "MCU_Types.h"
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
/*
 * This function is the periodic interrupt timer interrupt service routine.
 */
void HandlePITInt(void);

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
 * This static constant data member is the interrupt vector table.
 */
#pragma segment = "CSTACK"
#pragma location = ".intvec"

const vector_table VectorTable::vectorTable = {
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
    VectorTable::DefaultIsr,    // 0x0084
    VectorTable::DefaultIsr,    // 0x0088
    VectorTable::DefaultIsr,    // 0x008C
    VectorTable::DefaultIsr,    // 0x0090
    VectorTable::DefaultIsr,    // 0x0094
    VectorTable::DefaultIsr,    // 0x0098
    VectorTable::DefaultIsr,    // 0x009C
    VectorTable::DefaultIsr,    // 0x00A0
    VectorTable::DefaultIsr,    // 0x00A4
    VectorTable::DefaultIsr,    // 0x00A8
    VectorTable::DefaultIsr,    // 0x00AC
    VectorTable::DefaultIsr,    // 0x00B0
    VectorTable::DefaultIsr,    // 0x00B4
    VectorTable::DefaultIsr,    // 0x00B8
    VectorTable::DefaultIsr,    // 0x00BC
    VectorTable::DefaultIsr,    // 0x00C0
    VectorTable::DefaultIsr,    // 0x00C4
    VectorTable::DefaultIsr,    // 0x00C8
    VectorTable::DefaultIsr,    // 0x00CC
    VectorTable::DefaultIsr,    // 0x00D0
    VectorTable::DefaultIsr,    // 0x00D4
    VectorTable::DefaultIsr,    // 0x00D8
    VectorTable::DefaultIsr,    // 0x00DC
    VectorTable::DefaultIsr,    // 0x00E0
    VectorTable::DefaultIsr,    // 0x00E4
    VectorTable::DefaultIsr,    // 0x00E8
    VectorTable::DefaultIsr,    // 0x00EC
    VectorTable::DefaultIsr,    // 0x00F0
    VectorTable::DefaultIsr,    // 0x00F4
    VectorTable::DefaultIsr,    // 0x00F8
    VectorTable::DefaultIsr,    // 0x00FC
    VectorTable::DefaultIsr,    // 0x0100
    VectorTable::DefaultIsr,    // 0x0104
    VectorTable::DefaultIsr,    // 0x0108
    VectorTable::DefaultIsr,    // 0x010C
    VectorTable::DefaultIsr,    // 0x0110
    VectorTable::DefaultIsr,    // 0x0114
    VectorTable::DefaultIsr,    // 0x0118
    VectorTable::DefaultIsr,    // 0x011C
    VectorTable::DefaultIsr,    // 0x0120
    VectorTable::DefaultIsr,    // 0x0124
    VectorTable::DefaultIsr,    // 0x0128
    VectorTable::DefaultIsr,    // 0x012C
    VectorTable::DefaultIsr,    // 0x0130
    VectorTable::DefaultIsr,    // 0x0134
    VectorTable::DefaultIsr,    // 0x0138
    VectorTable::DefaultIsr,    // 0x013C
    VectorTable::DefaultIsr,    // 0x0140
    VectorTable::DefaultIsr,    // 0x0144
    VectorTable::DefaultIsr,    // 0x0148
    VectorTable::DefaultIsr,    // 0x014C
    VectorTable::DefaultIsr,    // 0x0150 - PIT: Channel 0
    HandlePITInt,               // 0x0154 - PIT: Channel 1
    VectorTable::DefaultIsr,    // 0x0158 - PIT: Channel 2
    VectorTable::DefaultIsr,    // 0x015C - PIT: Channel 3
    VectorTable::DefaultIsr,    // 0x0160
    VectorTable::DefaultIsr,    // 0x0164
    VectorTable::DefaultIsr,    // 0x0168
    VectorTable::DefaultIsr,    // 0x016C
    VectorTable::DefaultIsr,    // 0x0170
    VectorTable::DefaultIsr,    // 0x0174
    VectorTable::DefaultIsr,    // 0x0178
    VectorTable::DefaultIsr,    // 0x017C
    VectorTable::DefaultIsr,    // 0x0180
    VectorTable::DefaultIsr,    // 0x0184
    VectorTable::DefaultIsr,    // 0x0188
    VectorTable::DefaultIsr,    // 0x018C
    VectorTable::DefaultIsr,    // 0x0190
    VectorTable::DefaultIsr,    // 0x0194
    VectorTable::DefaultIsr,    // 0x0198
    VectorTable::DefaultIsr,    // 0x019C
    VectorTable::DefaultIsr,    // 0x01A0
    VectorTable::DefaultIsr,    // 0x01A4
    VectorTable::DefaultIsr,    // 0x01A8
    VectorTable::DefaultIsr,    // 0x01AC
    VectorTable::DefaultIsr,    // 0x01B0
    VectorTable::DefaultIsr,    // 0x01B4
    VectorTable::DefaultIsr     // 0x01B8
  }
};

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
 * This static method provides the starting vector table address.
 */
void* VectorTable::GetAddr(void)
{
  return (void*)&VectorTable::vectorTable;
}