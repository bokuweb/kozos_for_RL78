/********************************************************************//**
* @file     serial.h
* @brief    serial
* @date     2015.xx.xx
* @author   bokuweb
***********************************************************************/
#ifndef _SERIAL_H_INCLUDE_
#define _SERIAL_H_INCLUDE_

int16_t serial_init(void);
int16_t serial_send_byte(uint8_t c);
uint8_t serial_recv_byte(void);
int16_t serial_intr_is_send_enable(void);
void serial_intr_send_enable(void);
void serial_intr_send_disable(void);
int16_t serial_intr_is_recv_enable(void);
void serial_intr_recv_enable(void);
void serial_intr_recv_disable(void);
#endif
