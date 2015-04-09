/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  RL78G13_LED_SAMPLE                     */
/*      FILE         :  vector_table.c                         */
/*      DESCRIPTION  :  Vector Table                           */
/*      CPU SERIES   :  RL78 - G13                             */
/*      CPU TYPE     :  R5F100LE                               */
/*                                                             */
/***************************************************************/                            
#include "interrupt_handlers.h"

extern void PowerON_Reset (void);

const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
	0xef, 0xff, 0xe8, 0x85
};

const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define VEC          __attribute__ ((section (".vec")))
const void *HardwareVectors[] VEC = {
	// Address 0x0
	PowerON_Reset,
	// Secure for Debugging
	(void*)0xFFFF
};

#define VECT_SECT          __attribute__ ((section (".vects")))
const void *Vectors[] VECT_SECT = {
	//INT_WDTI (0x4)
	INT_WDTI,
	//INT_LVI (0x6)
	INT_LVI,
	//INT_P0 (0x8)
	INT_P0,
	//INT_P1 (0xA)
	INT_P1,
	//INT_P2 (0xC)
	INT_P2,
	//INT_P3 (0xE)
	INT_P3,
	//INT_P4 (0x10)
	INT_P4,
	//INT_P5 (0x12)
	INT_P5,
	//INT_CSI20/INT_IIC20/INT_ST2 (0x14)
	INT_ST2,
	//INT_CSI21/INT_IIC21/INT_SR2 (0x16)
	INT_SR2,
	//INT_SRE2 (0x18)
	INT_SRE2,
	//INT_DMA0 (0x1A)
	INT_DMA0,
	//INT_DMA1 (0x1C)
	INT_DMA1,
	//INT_CSI00/INT_IIC00/INT_ST0 (0x1E)
	INT_ST0,
	//INT_CSI01/INT_IIC01/INT_SR0 (0x20)
	INT_SR0,
	//INT_SRE0/INT_TM01H (0x22)
	INT_TM01H,
	//INT_CSI10/INT_IIC10/INT_ST1 (0x24)
	INT_ST1,
	//INT_CSI11/INT_IIC11/INT_SR1 (0x26)
	INT_SR1,
	//INT_SRE1/INT_TM03H (0x28)
	INT_TM03H,
	//INT_IICA0 (0x2A)
	INT_IICA0,
	//INT_TM00 (0x2C)
	INT_TM00,
	//INT_TM01 (0x2E)
	INT_TM01,
	//INT_TM02 (0x30)
	INT_TM02,
	//INT_TM03 (0x32)
	INT_TM03,
	//INT_AD (0x34)
	INT_AD,
	//INT_RTC (0x36)
	INT_RTC,
	//INT_IT (0x38)
	INT_IT,
	//INT_KR (0x3A)
	INT_KR,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_TM04 (0x42)
	INT_TM04,
	//INT_TM05 (0x44)
	INT_TM05,
	//INT_TM06 (0x46)
	INT_TM06,
	//INT_TM07 (0x48)
	INT_TM07,
	//INT_P6 (0x4A)
	INT_P6,
	//INT_P7 (0x4C)
	INT_P7,
	//INT_P8 (0x4E)
	INT_P8,
	//INT_P9 (0x50)
	INT_P9,
	//INT_P10 (0x52)
	INT_P10,
	//INT_P11 (0x54)
	INT_P11,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_MD (0x5E)
	INT_MD,
	// Padding
	(void*)0xFFFF,
	//INT_FL (0x62)
	INT_FL,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	//INT_BRK_I (0x7E)
	INT_BRK_I,
};

