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

#endif
