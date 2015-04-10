/********************************************************************//**
* @file     lib.c
* @brief    library
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/

/* Includes -------------------------------------------------------- */
#include "defines.h"
#include "serial.h"
#include "lib.h"

/* Private Variable ------------------------------------------------ */

/* Private Functions ----------------------------------------------- */

/* Public Functions ------------------------------------------------ */

/******************************************************************//**
 * @brief       memset
 * @param       
 * @return      
 *********************************************************************/
void *kz_memset(void *b, int c, long len)
{
    char_t *p;
    for (p = b; len > 0; len--) {
        *(p++) = c;
    }
    return b;
}

/******************************************************************//**
 * @brief       memcpy
 * @param       
 * @return      
 *********************************************************************/
void *kz_memcpy(void *dst, const void *src, uint32_t len)
{
    char_t *d = dst;
    const char_t *s = src;

    for (; len > 0; len--) {
        *(d++) = *(s++);
    }
    return dst;
}

/******************************************************************//**
 * @brief       memcmp
 * @param       
 * @return      
 *********************************************************************/
int16_t *kz_memcmp(const void *b1, const void *b2, uint32_t len)
{
    const char_t *p1 = b1;
    const char_t *p2 = b2;

    for (; len > 0; len--) {
        if (*p1 != *p2) {
            return (*p1 > *p2) ? 1 : -1;
        }
        p1++;
        p2++;
    }
    return 0;
}

/******************************************************************//**
 * @brief       strlen
 * @param       
 * @return      
 *********************************************************************/
uint16_t kz_strlen(const char_t *s)
{
    uint16_t len;

    for (len = 0; *s; s++, len++)
        ;
    return len;
}

/******************************************************************//**
 * @brief       strcpy
 * @param       
 * @return      
 *********************************************************************/
char_t *kz_strcpy(char_t *dst, const char_t *src)
{
    char_t *d = dst;
    for (;; dst++, src++) {
        *dst = *src;
        if (!*src) break;
    }
    return d;
}

/******************************************************************//**
 * @brief       strcmp
 * @param       
 * @return      
 *********************************************************************/
int16_t *kz_strcmp(const char_t *s1, const char_t *s2)
{
    while (*s1 || *s2) {
        if (*s1 != *s2) return (*s1 > *s2) ? 1 : -1;
        s1++;
        s2++;
    }
    return 0;
}

/******************************************************************//**
 * @brief       strncmp
 * @param       
 * @return      
 *********************************************************************/
int16_t *kz_strncmp(const char_t *s1, const char_t *s2, uint16_t len)
{
    while ((*s1 || *s2) && (len > 0)) {
        if (*s1 != *s2) return (*s1 > *s2) ? 1 : -1;
        s1++;
        s2++;
        len--;
    }
    return 0;
}

/******************************************************************//**
 * @brief       putc
 * @param       
 * @return      
 *********************************************************************/
int16_t kz_putc(uint8_t c)
{
    if (c == '\n')
        serial_send_byte('\r');
    return serial_send_byte(c);
}

/******************************************************************//**
 * @brief       puts
 * @param       
 * @return      
 *********************************************************************/
int16_t kz_puts(uint8_t *str)
{
    while (*str)
        kz_putc (*(str++));
    return 0;
}

/******************************************************************//**
 * @brief       
 * @param       
 * @return      
 *********************************************************************/
int16_t kz_putxval(uint32_t value, int16_t column)
{
    char buf[9];
    char *p;

    p = buf + sizeof(buf) - 1;
    *(p--) = '\0';

    if (!value && !column) column++;

    while (value || column) {
        *(p--) = "0123456789abcdef"[value & 0xf];
        value >>= 4;
        if (column) column--;
    }
    kz_puts(p + 1);
    return 0;
}
