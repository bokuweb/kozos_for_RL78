/********************************************************************//**
* @file     vector.c
* @brief    
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/
#include "defines.h"
#include "interrupt.h"

extern void start(void);
extern void intr_serintr(void);

const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
    0xef, 0xff, 0xe8, 0x85
};

const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define VEC __attribute__ ((section (".vec")))
const void *HardwareVectors[] VEC = {
    // Address 0x0
    start,
    // Secure for Debugging
    (void*)0xFFFF
};

#define VECT_SECT __attribute__ ((section (".vects")))
const void *Vectors[] VECT_SECT = {
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	intr_serintr,
	intr_serintr,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF, //INT_TM00,
	(void*)0xFFFF, //INT_TM01,
	(void*)0xFFFF, //INT_TM02,
	(void*)0xFFFF, //INT_TM03,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF,
	(void*)0xFFFF //intr_syscall,
};

