/********************************************************************//**
* @file     vector.c
* @brief    interrupt vector
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/

/* Includes -------------------------------------------------------- */
#include "defines.h"
#include "interrupt_handlers.h"

extern void start(void);


const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
    0xef, 0xff, 0xe8, 0x85
};

const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define VEC  __attribute__ ((section (".vec")))
const void *HardwareVectors[] VEC = {
    /* Address 0x0 */
    start,
    /* Secure for Debugging */
    (void*)0xFFFF
};

#define VECT_SECT __attribute__ ((section (".vects")))
const void *Vectors[] VECT_SECT = {
    INT_WDTI,
    INT_LVI,
    INT_P0,
    INT_P1,
    INT_P2,
    INT_P3,
    INT_P4,
    INT_P5,
    INT_ST2,
    INT_SR2,
    INT_SRE2,
    INT_DMA0,
    INT_DMA1,
    INT_ST0,
    INT_SR0,
    INT_TM01H,
    INT_ST1,
    INT_SR1,
    INT_TM03H,
    INT_IICA0,
    INT_TM00,
    INT_TM01,
    INT_TM02,
    INT_TM03,
    INT_AD,
    INT_RTC,
    INT_IT,
    INT_KR,
    (void*)0xFFFF,
    (void*)0xFFFF,
    (void*)0xFFFF,
    INT_TM04,
    INT_TM05,
    INT_TM06,
    INT_TM07,
    INT_P6,
    INT_P7,
    INT_P8,
    INT_P9,
    INT_P10,
    INT_P11,
    (void*)0xFFFF,
    (void*)0xFFFF,
    (void*)0xFFFF,
    (void*)0xFFFF,
    INT_MD,
    (void*)0xFFFF,
    INT_FL,
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
    INT_BRK_I,
};

