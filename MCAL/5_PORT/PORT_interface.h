/*
	Author		: Ahmed Mohsen
	Layer		: MCAL	
	SWC			: PORT
	Version		: 1.00	
	Date		: 31-8-2020
*/


#ifndef PORT_INTERFACE_H_
#define PORT_INTERFACE_H_

#include "STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_register.h"


/*
	Name		 : PORT_voidInit	
	parameter	 : none
	return		 : none	
	Description	 : init all uc pins
*/
void PORT_voidInit(void);


#endif