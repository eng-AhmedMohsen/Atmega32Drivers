/*
 * usart.h
 *
 * Created: 16-Apr-22 10:54:55 AM
 *  Author: Ahmed
 */ 


#ifndef USART_H_
#define USART_H_
#include "atmega32a_registers_file.h"
#include "std_types.h"

typedef enum
{
	USART_TX_COMPLETE_INTERRUPT = 0,
	USART_RX_COMPLETE_INTERRUPT,
	USART_DATA_REGISTER_EMPTY_INTERRUPT
}usart_interrupt_t;

typedef enum
{
	USART_ASYNCHRONOUS_MODE = 0,
	USART_SYNCHRONOUS_MODE
}usart_mode_t;

typedef enum
{
	USART_PARITY_DISABLED = 0,
	USART_PARITY_EVEN,
	USART_PARITY_ODD
}usart_parity_t;


typedef enum
{
	USART_STOP_BIT_1 = 0,
	USART_STOP_BIT_2
}usart_stop_bits_t;

typedef enum
{
	USART_CHAR_SIZE_5_BIT = 0,
	USART_CHAR_SIZE_6_BIT,
	USART_CHAR_SIZE_7_BIT,
	USART_CHAR_SIZE_8_BIT,
	USART_CHAR_SIZE_9_BIT
}usart_char_size_t;

typedef enum
{
	USART_TRANSMIT_ON_RISING = 0,
	USART_TRANSMIT_ON_FALLING
}usart_clock_polarity_t;

typedef enum
{
	USART_BAUD_RATE_9600,
	USART_BAUD_RATE_4800
}usart_baud_rate_t;

typedef struct
{
	usart_mode_t mode :1;
	usart_parity_t parity :2;
	usart_stop_bits_t stop_bits :1;
	usart_char_size_t char_size :3;
	usart_clock_polarity_t polarity :1;
	usart_baud_rate_t baud_rate :1;
}usart_config_t;

std_return_t MCAL_usart_init(usart_config_t *_usart);
std_return_t MCAL_usart_send(usart_config_t *_usart, uint8 _data);
std_return_t MCAL_usart_send_string(usart_config_t *_usart, uint8 *_data);
std_return_t MCAL_usart_recieve(usart_config_t *_usart, uint8 *_data);


#endif /* USART_H_ */