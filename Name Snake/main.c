/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 15 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>
# define F_CPU 12000000UL


#include "PORT_register.h"

void main (void)
{
	PortInitialize();
	CLCD_voidInitialize();
	/*set function*/
	CLCD_voidWriteCmd(0b00111000);
	while(1)
	{

		/*first step*/
		CLCD_voidWriteData('A');
		CLCD_voidWriteData('r');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('j');
		_delay_ms(500);
		/*clear*/
		CLCD_voidWriteCmd(0b00000001);

		/*second step 0x42*/
		/*set ddram*/
		CLCD_voidWriteCmd(0b11000010);

		CLCD_voidWriteData('A');
		CLCD_voidWriteData('r');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('j');
		_delay_ms(500);
		/*clear*/
		CLCD_voidWriteCmd(0b00000001);

		/*third step 0x05*/
		/*set ddram*/
		CLCD_voidWriteCmd(0b10000101);

		CLCD_voidWriteData('A');
		CLCD_voidWriteData('r');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('j');
		_delay_ms(500);
		/*clear*/
		CLCD_voidWriteCmd(0b00000001);

		/*4th step 0x47*/
		/*set ddram*/
		CLCD_voidWriteCmd(0b11000111);

		CLCD_voidWriteData('A');
		CLCD_voidWriteData('r');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('j');
		_delay_ms(500);
		/*clear*/
		CLCD_voidWriteCmd(0b00000001);

		/*5th step 0x0A*/
		/*set ddram*/
		CLCD_voidWriteCmd(0b10001010);

		CLCD_voidWriteData('A');
		CLCD_voidWriteData('r');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('j');
		_delay_ms(500);
		/*clear*/
		CLCD_voidWriteCmd(0b00000001);

		/*6th step 0x4B*/
		/*set ddram*/
		CLCD_voidWriteCmd(0b11001011);

		CLCD_voidWriteData('A');
		CLCD_voidWriteData('r');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('e');
		CLCD_voidWriteData('j');
		_delay_ms(500);
		/*clear*/
		CLCD_voidWriteCmd(0b00000001);

	}


}


