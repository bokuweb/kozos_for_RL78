/********************************************************************//**
* @file     serial.c
* @brief    serial driver
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/

/* Pragma directive ------------------------------------------------ */


/* Includes -------------------------------------------------------- */
#include "defines.h"
#include "serial.h"
#include "iodefine.h"
#include "iodefine_ext.h"

/* defines --------------------------------------------------------- */

/* Private Variable ------------------------------------------------ */

/* Private Functions ----------------------------------------------- */

/******************************************************************//**
 * @brief       check whether that can be sent
 * @param       none
 * @return      none
 *********************************************************************/
static int16_t serial_is_send_enable(void)
{
    return ((SSR00 & 0x0020) == 0);
}

/* Public Functions ------------------------------------------------ */

/******************************************************************//**
 * @brief       initialize serial function
 * @param       none
 * @return      none
 *********************************************************************/
int16_t serial_init(void)
{
    SAU0EN = 1U;    /* supply SAU0 clock */
    NOP();
    NOP();
    NOP();
    NOP();

    SPS0 = 0x0044;
    ST0 |= 0x0003;

    STMK0  = 1U;    /* disable INTST0 interrupt     */
    STIF0  = 0U;    /* clear INTST0 interrupt flag  */
    SRMK0  = 1U;    /* disable INTSR0 interrupt     */
    SRIF0  = 0U;    /* clear INTSR0 interrupt flag  */
    SREMK0 = 1U;    /* disable INTSRE0 interrupt    */
    SREIF0 = 0U;    /* clear INTSRE0 interrupt flag */

    /* Set INTST0 low priority */
    STPR10 = 1U;
    STPR00 = 1U;

    /* Set INTSR0 low priority */
    SRPR10 = 1U;
    SRPR00 = 1U;

    SMR00 = 0x0022;
    SCR00 = 0x8097;
    SDR00 = 0xCE00;

    NFEN0 |= 0x01;

    SIR01 = 0x0007;
    SMR01 = 0x0122;
    SCR01 = 0x4097;

    SDR01 = 0xCE00;
    SO0  |= 0x0001;
    SOE0 |= 0x0001;    /* enable UART0 output */

    /* Set RxD0 pin */
    PM1 |= 0x02U;

    /* Set TxD0 pin */
    P1  |= 0x04U;
    PM1 &= 0xFBU;

    SS0 |= 0x0003;
    STIF0 = 0U;    /* clear INTST0 interrupt flag */
    SRIF0 = 0U;    /* clear INTSR0 interrupt flag */
    STMK0 = 0U;    /* enable INTST0 interrupt */
    SRMK0 = 0U;    /* enable INTSR0 interrupt */

    return 0;
}


/******************************************************************//**
 * @brief       initialize serial function
 * @param       none
 * @return      none
 *********************************************************************/
int16_t serial_send_byte(uint8_t c)
{
    while(!serial_is_send_enable())
        ;
    TXD0 = c;

    return 0;
}

    
