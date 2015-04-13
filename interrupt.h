#ifndef _INTERRUPT__H
#define _INTERRUPT__H

typedef uint16_t softvec_type_t;

typedef void (*softvec_handler_t)(softvec_type_t type, uint16_t sp);

#define SOFTVECS ((softvec_handler_t *)&softvec[0])

softvec_handler_t *softvec[32];

extern int16_t softvec_setintr(softvec_type_t type, softvec_handler_t handler);
extern int16_t softvec_init(void);
//void intr_serintr(void) __attribute__ ((interrupt));

#endif
