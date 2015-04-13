/********************************************************************//**
* @file     
* @brief    
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/
#include "defines.h"
#include "iodefine.h"
#include "interrupt.h"
#include "intr.h"
#include "lib.h"

/* defines -------------------------------------------------------- */
#define LED1_PIN   P6_bit.no2
#define LED1       PM6_bit.no2

int16_t softvec_setintr(softvec_type_t type, softvec_handler_t handler)
{
    SOFTVECS[type] = handler;
    return;
}

int16_t softvec_init(void)
{
    int16_t type;

    for (type = 0; type < SOFTVEC_TYPE_NUM; type++) {
        softvec_setintr(type, NULL);
    }
    return 0;
}

void interrupt(softvec_type_t type, uint16_t sp)
{
    softvec_handler_t handler = SOFTVECS[type];
    if (handler) handler(type, sp);
}

