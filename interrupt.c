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

/* defines -------------------------------------------------------- */
#define LED1_PIN   P6_bit.no2
#define LED1       PM6_bit.no2

void interrupt(softvec_type_t type, uint16_t sp)
{
    if (type == 2) type = 3;
    //LED1 = ~LED1; 
    //softvec_handler_t handler = SOFTVECS[type];
    //if (handler) handler(type, sp);
}

/*
void intr_serintr(void)
{
    __asm__(
        "push    ax                        \n\t"
        "movw    ax, #2                    \n\t"
        "push    ax                        \n\t"
        "call    !!_interrupt              \n\t"
        "pop     ax                        \n\t"
        "pop     ax                        \n\t"        
    );
}
*/

