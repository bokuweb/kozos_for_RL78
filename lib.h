/********************************************************************//**
* @file     lib.h
* @brief    library header
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/
#ifndef _LIB_H_INCLUDE_
#define _LIB_H_INCLUDE_

void *kz_memset(void *b, int c, long len);
void *kz_memcpy(void *dst, const void *src, uint32_t len);
int16_t *kz_memcmp(const void *b1, const void *b2, uint32_t len);
uint16_t kz_strlen(const char_t *s);
char_t *kz_strcpy(char_t *dst, const char_t *src);
int16_t *kz_strcmp(const char_t *s1, const char_t *s2);
int16_t *kz_strncmp(const char_t *s1, const char_t *s2, uint16_t len);
int16_t kz_putc(uint8_t c);
int16_t kz_puts(uint8_t *str);
int16_t kz_putxval(uint32_t value, int16_t column);

#endif
