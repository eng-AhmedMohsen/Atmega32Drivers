/*
	Author		: Ahmed Mohsen
	Layer			: MCAL	
	SWC			: PORT
	Version		: 1.00	
	Date		: 31-8-2020
*/


#include "PORT_interface.h"


void PORT_voidInit(void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;
}