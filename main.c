/********************************************************************//**
* @file     main.c
* @brief    main function
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/

/* Pragma directive ------------------------------------------------ */


/* Includes -------------------------------------------------------- */
#include "defines.h"
#include "serial.h"
#include "lib.h"

/* Private Variable ------------------------------------------------ */

/* Private Functions ----------------------------------------------- */

/* Public Functions ------------------------------------------------ */

/******************************************************************//**
 * @brief       main function
 * @param       none
 * @return      none
 *********************************************************************/
int main(void)
{
    serial_init(SERIAL__DEFAULT_DEVICE);

    puts("Hello World!\n");

    while (true)
        ;

    return 0;
}
