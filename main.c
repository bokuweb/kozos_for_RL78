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

/* Public Functions ------------------------------------------------ */

int16_t main(void)
{
    LED1_PIN = 0; // Make Pin as O/P
    LED1 = 0;     // Turn LED ON

    serial_init();
    kz_puts("Hello World!\n");
    while (true) {
        ;
    }
    return 0;
}
