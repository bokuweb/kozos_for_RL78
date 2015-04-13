#ifndef _INTERRUPT__H
#define _INTERRUPT__H

uint16_t soft_vec[256];

typedef uint16_t softvec_type_t;

typedef void (*softvec_handler_t)(softvec_type_t type, uint32_t sp);

#define SOFTVECS ((softvec_handler_t *)soft_vec)

//void intr_serintr(void) __attribute__ ((interrupt));

#endif
