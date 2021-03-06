/****************************************************************
 Author     : 	Ahmed Mohsen                               
 Layer      : 	MCAL 		                                         
 SWC        :   ADC		                        		     
 Date       : 	26-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX                *((volatile u8*)0x27)		/*ADC multilpexer selection register*/
#define ADMUX_REFS1			 7                           /*Reference selection Bit1*/
#define ADMUX_REFS0			 6                           /*Reference selection Bit0*/
#define ADMUX_ADLAR			 5                           /*Left adjust result*/

#define ADCSRA               *((volatile u8*)0x26)		/*ADC control and status registerA*/
#define ADCSRA_ADEN			 7                          /*Enable*/
#define ADCSRA_ADSC			 6                          /*Start conversion*/
#define ADCSRA_ADATE		 5                          /*Auto trigger enable*/
#define ADCSRA_ADIF			 4                          /*Interrupt flag*/
#define ADCSRA_ADIE			 3                          /*Interrupt enable*/


#define ADCH                 *((volatile u8*)0x25)		/*Data high register*/
#define ADCL                 *((volatile u8*)0x24)		/*Data low register*/


#endif