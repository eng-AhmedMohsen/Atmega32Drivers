/*
 * usart.c
 *
 * Created: 16-Apr-22 10:55:04 AM
 *  Author: Ahmed
 */ 

#include "usart.h"

std_return_t MCAL_usart_init(usart_config_t *_usart)
{
	/* wRITE tHIS PIN TO 1 TO WRITE TO ucsrc*/
	UCSRC_reg->bit.URSEL_bit = 1;
	
	/* set mode */
	UCSRC_reg->bit.UMSEL_bit = _usart->mode;

	/* set stop bits*/
	UCSRC_reg->bit.USBS_bit = _usart->stop_bits;
	
	/* Set polarity */
	UCSRC_reg->bit.UCPOL_bit = 0;
	
	/* set baud rate (with std frequency 8Mhz)*/
	*UBRRL_reg = (uint8)51;
	
	/* parity mode */
	switch(_usart->parity)
	{
		case(USART_PARITY_DISABLED):
		{
			UCSRC_reg->bit.UPM0_bit = 0;
			UCSRC_reg->bit.UPM1_bit = 0;
			break;
		}
		case(USART_PARITY_EVEN):
		{
			UCSRC_reg->bit.UPM0_bit = 0;
			UCSRC_reg->bit.UPM1_bit = 1;
			break;
		}
		case(USART_PARITY_ODD):
		{
			UCSRC_reg->bit.UPM0_bit = 1;
			UCSRC_reg->bit.UPM1_bit = 1;
			break;
		}
	}
	
	/* Char Size */
	switch(_usart->char_size)
	{
		case(USART_CHAR_SIZE_5_BIT):
		{
			UCSRC_reg->bit.UCSZ0_bit = 0;
			UCSRC_reg->bit.UCSZ1_bit = 0;
			UCSRB_reg->bit.UCSZ2_bit = 0;
			break;
		}
		case(USART_CHAR_SIZE_6_BIT):
		{
			UCSRC_reg->bit.UCSZ0_bit = 1;
			UCSRC_reg->bit.UCSZ1_bit = 0;
			UCSRB_reg->bit.UCSZ2_bit = 0;
			break;
		}
		case(USART_CHAR_SIZE_7_BIT):
		{
			UCSRC_reg->bit.UCSZ0_bit = 0;
			UCSRC_reg->bit.UCSZ1_bit = 1;
			UCSRB_reg->bit.UCSZ2_bit = 0;
			break;
		}
		case(USART_CHAR_SIZE_8_BIT):
		{
			UCSRC_reg->bit.UCSZ0_bit = 1;
			UCSRC_reg->bit.UCSZ1_bit = 1;
			UCSRB_reg->bit.UCSZ2_bit = 0;
			break;
		}
		case(USART_CHAR_SIZE_9_BIT):
		{
			UCSRC_reg->bit.UCSZ0_bit = 1;
			UCSRC_reg->bit.UCSZ1_bit = 1;
			UCSRB_reg->bit.UCSZ2_bit = 1;
			break;
		}
	}

	/* enable USART */
	UCSRB_reg->bit.TXEN_bit = 1;
	UCSRB_reg->bit.RXEN_bit = 1;
	return ret_ok;
}

std_return_t MCAL_usart_send(usart_config_t *_usart, uint8 _data)
{
	/* We Don't Use More than 8 bits for data */
	while(UCSRA_reg->bit.UDRE_bit == 0);
	*UDR_reg = _data;
	return ret_ok;
}

std_return_t MCAL_usart_recieve(usart_config_t *_usart, uint8 *_data)
{
	/* We Don't Use More than 8 bits for data */
	while(UCSRA_reg->bit.RXC_bit == 0);
	(*_data) = (*UDR_reg);
	return ret_ok;	
}

std_return_t MCAL_usart_send_string(usart_config_t *_usart, uint8 *_data)
{
	/* We Don't Use More than 8 bits for data */
	
	uint8 counter = 0;
	
	while(_data[counter] != '\0')
	{
		while(UCSRA_reg->bit.UDRE_bit == 0);
		*UDR_reg = _data[counter];
		counter++;		
	}
		
	return ret_ok;	
}