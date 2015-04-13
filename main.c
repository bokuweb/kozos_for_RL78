/********************************************************************//**
* @file     main.c
* @brief    main function
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/

/* defines -------------------------------------------------------- */
#define LED1_PIN   P6_bit.no2
#define LED1       PM6_bit.no2

/* Includes -------------------------------------------------------- */
#include "iodefine.h"
#include "defines.h"
#include "serial.h"
#include "interrupt.h"
#include "lib.h"
#include "intr.h"

/* Private Variable ------------------------------------------------ */

/* Private Functions ----------------------------------------------- */

/******************************************************************//**
 * @brief       serial interrup handler
 * @param       none
 * @return      none
 *********************************************************************/
static void intr(softvec_type_t type, uint16_t sp)
{
    uint16_t c;
    static char buf[32];
    static int16_t len;

    LED1 = ~LED1;
    
    c = kz_getc();

    if (c != '\n') {
        buf[len++] = c;
    } else {
        buf[len++] = '\0';
        if (!kz_strncmp(buf, "echo", 4)) {
            kz_puts(buf + 4);
            kz_puts("\n");
        } else {
            kz_puts("unknown.\n");
        }
        kz_puts("> ");
        len = 0;
    }
}

/******************************************************************//**
 * @brief       initialize
 * @param       none
 * @return      none
 *********************************************************************/
static void init(void)
{
    LED1_PIN = 0; // Make Pin as O/P
    LED1 = 0;     // Turn LED ON
    softvec_init();
    serial_init();
}

/******************************************************************//**
 * @brief       dump
 * @param       none
 * @return      none
 *********************************************************************/
static int16_t dump(char_t *buf, int32_t size)
{
    uint32_t i;


    if (size < 0) {
        kz_puts("no data.\n");
        return -1;
    }
    for (i = 0; i < size; i++) {
        kz_putxval(buf[i], 2);
        if ((i & 0xf) == 15) {
            kz_puts("\n");
        } else {
            if ((i & 0xf) == 7) kz_puts(" ");
            kz_puts(" ");
        }
    }
    kz_puts("\n");

    return 0;
}

/* Public Functions ------------------------------------------------ */

/******************************************************************//**
 * @brief       initialize serial function
 * @param       none
 * @return      none
 *********************************************************************/    
int16_t main(void)
{
    static char_t buf[32];

    DI();

    init();

    kz_puts("Hello World.\n");

    softvec_setintr(SOFTVEC_TYPE_SERINTR, intr);

    serial_intr_recv_enable();

    EI();

    while (true) {

    }

    return 0;
}
