/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 14 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "PORT_register.h"
#include "PORT_config.h"
#include "PORT_private.h"

void PortInitialize(void)
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

