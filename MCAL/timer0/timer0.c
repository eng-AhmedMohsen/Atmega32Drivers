/*
 * timer0.c
 *
 * Created: 18-Apr-22 8:11:15 AM
 *  Author: Ahmed
 */ 
#include "timer0.h"

std_return_t MCAL_timer0_init(timer0_config_t *_timer, uint8 _TCNT_init_val)
{
	std_return_t ret = ret_ok;
	if(_timer == '\0')
	{
		ret = ret_not_ok;
	}
	else
	{
		/* init Timer0 */
		TCCR0_reg->bit.WGM00_bit = 0;
		TCCR0_reg->bit.WGM01_bit = 0;
		
		/* set init val*/
		(*TCNT0_reg) = _TCNT_init_val;
	}
	return ret;
}

std_return_t MCAL_timer0_start(timer0_config_t *_timer)
{
	std_return_t ret = ret_ok;
	if(_timer == '\0')
	{
		ret = ret_not_ok;
	}
	else
	{
		/*set clk to start*/
		switch(_timer->clk)
		{
			case(TIMER0_CLK_BY_1):
			{
				TCCR0_reg->bit.CS00_bit = 1;
				TCCR0_reg->bit.CS01_bit = 0;
				TCCR0_reg->bit.CS02_bit = 0;
				break;
			}
			case(TIMER0_CLK_BY_8):
			{
				TCCR0_reg->bit.CS00_bit = 0;
				TCCR0_reg->bit.CS01_bit = 1;
				TCCR0_reg->bit.CS02_bit = 0;
				break;
			}
			case(TIMER0_CLK_BY_64):
			{
				TCCR0_reg->bit.CS00_bit = 1;
				TCCR0_reg->bit.CS01_bit = 1;
				TCCR0_reg->bit.CS02_bit = 0;
				break;
			}
			case(TIMER0_CLK_BY_256):
			{
				TCCR0_reg->bit.CS00_bit = 0;
				TCCR0_reg->bit.CS01_bit = 0;
				TCCR0_reg->bit.CS02_bit = 1;
				break;
			}
			case(TIMER0_CLK_BY_1024):
			{
				TCCR0_reg->bit.CS00_bit = 1;
				TCCR0_reg->bit.CS01_bit = 0;
				TCCR0_reg->bit.CS02_bit = 1;
				break;
			}
		}
	}
	return ret;	
}
std_return_t MCAL_timer0_stop(timer0_config_t *_timer)
{
	std_return_t ret = ret_ok;
	if(_timer == '\0')
	{
		ret = ret_not_ok;
	}
	else
	{
		/* disable clk */
		TCCR0_reg->bit.CS00_bit = 0;
		TCCR0_reg->bit.CS01_bit = 0;
		TCCR0_reg->bit.CS02_bit = 0;
	}
	return ret;	
}