/********************************************************************//**
* @file     
* @brief    
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/
#include "intr.h"

    .global _intr_serintr

_intr_serintr:
    push    ax
    push    bc
    push    de
    push    hl
    movw    ax, #SOFTVEC_TYPE_SERINTR
    push    ax      /* type */
    movw    ax, sp
    push    ax      /* sp */
    call    !!_interrupt
    pop     ax      /* sp */
    pop     ax      /* type */
    pop     hl
    pop     de
    pop     bc
    pop     ax
    reti
