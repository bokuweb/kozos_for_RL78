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
#include "lib.h"

/* Private Variable ------------------------------------------------ */

/* Private Functions ----------------------------------------------- */

/******************************************************************//**
 * @brief       initialize
 * @param       none
 * @return      none
 *********************************************************************/
static void init(void)
{
    LED1_PIN = 0; // Make Pin as O/P
    LED1 = 0;     // Turn LED ON

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
    static char_t buf[16];
    static int32_t size = -1;
    static uint8_t *loadbuf = NULL;

    init();

    kz_puts("started.\n");

    while (true) {
        kz_puts("kz > ");
        kz_gets(buf);

        if (!kz_strcmp(buf, "run")) {

        } else if (!kz_strcmp(buf, "dump")) {
            kz_puts("size: ");
            kz_putxval(size, 0);
            kz_puts("\n");
            dump(loadbuf, size);
        } else {
            kz_puts("unknown.\n");
        }
    }

    return 0;
}
