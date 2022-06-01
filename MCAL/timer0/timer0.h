/*
 * timer0.h
 *
 * Created: 18-Apr-22 8:11:22 AM
 *  Author: Ahmed
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "timer0_config.h"
#include "atmega32a_registers_file.h"
#include "std_types.h"

typedef enum
{
	TIMER0_CLK_DISABLE = 0,
	TIMER0_CLK_BY_1,
	TIMER0_CLK_BY_8,
	TIMER0_CLK_BY_64,
	TIMER0_CLK_BY_256,
	TIMER0_CLK_BY_1024
}timer0_clk_t;

typedef struct
{
	timer0_clk_t clk:3;
}timer0_config_t;



	std_return_t MCAL_timer0_init(timer0_config_t *_timer, uint8 _TCNT_init_val);


std_return_t MCAL_timer0_start(timer0_config_t *_timer);
std_return_t MCAL_timer0_stop(timer0_config_t *_timer);

#endif /* TIMER0_H_ */