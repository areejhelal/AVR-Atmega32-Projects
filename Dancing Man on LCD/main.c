/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 28 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include "CLCD_interface.h"
# define F_CPU 12000000UL


#include "PORT_register.h"

void main (void)
{
	PortInitialize();
	CLCD_voidInitialize();

	while(1)
	{
		//CGRAM 0
		CLCD_voidWriteCmd(0x40);
		/*7amoksha*/
		CLCD_voidWriteData(0b01110);
		CLCD_voidWriteData(0b01110);
		CLCD_voidWriteData(0b00100);
		CLCD_voidWriteData(0b11111);
		CLCD_voidWriteData(0b00100);
		CLCD_voidWriteData(0b01010);
		CLCD_voidWriteData(0b01010);
		CLCD_voidWriteData(0b01010);

		//CGRAM 1
		CLCD_voidWriteCmd(0x48);
		/*Ball*/
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b11000);
		CLCD_voidWriteData(0b11000);

		//CGRAM 2
		CLCD_voidWriteCmd(0x50);
		/*7amoksha's Playing Football*/
		CLCD_voidWriteData(0b01110);
		CLCD_voidWriteData(0b01110);
		CLCD_voidWriteData(0b00100);
		CLCD_voidWriteData(0b11111);
		CLCD_voidWriteData(0b00100);
		CLCD_voidWriteData(0b01010);
		CLCD_voidWriteData(0b01010);
		CLCD_voidWriteData(0b01001);

		//CGRAM 3
		CLCD_voidWriteCmd(0x58);
		/*Ball flying*/
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b11000);
		CLCD_voidWriteData(0b11000);
		CLCD_voidWriteData(0b00000);
		CLCD_voidWriteData(0b00000);

		//CGRAM 4
		CLCD_voidWriteCmd(0x60);
		/*7amoksha's dancing*/
		CLCD_voidWriteData(0b01110);
		CLCD_voidWriteData(0b01110);
		CLCD_voidWriteData(0b10101);
		CLCD_voidWriteData(0b01110);
		CLCD_voidWriteData(0b00100);
		CLCD_voidWriteData(0b01010);
		CLCD_voidWriteData(0b10001);
		CLCD_voidWriteData(0b10001);

		/*DDRAM*/
		CLCD_voidWriteCmd(0b10000000);
		/*Clear*/
		CLCD_voidWriteCmd(0b00000001);

		/*scene 1*/
		CLCD_voidGoToXPos(0,0);

		CLCD_void_WriteString("I'm Not 7amoksha");

		CLCD_voidGoToXPos(3,1);

		CLCD_voidWriteData(0);

		_delay_ms(20000);


		/*Clear*/
		CLCD_voidWriteCmd(0b00000001);

		/*scene 2*/

		for(int i=0;i<5;i++)
		{
			/*Clear*/
			CLCD_voidWriteCmd(0b00000001);
			CLCD_voidGoToXPos(0,0);
			CLCD_void_WriteString("I can Play FB");
			CLCD_voidGoToXPos(3,1);
			CLCD_voidWriteData(0);
			CLCD_voidGoToXPos(4,1);
			CLCD_voidWriteData(1);
			_delay_ms(1000);
			/*Clear*/
			CLCD_voidWriteCmd(0b00000001);
			CLCD_voidGoToXPos(0,0);
			CLCD_void_WriteString("I Can Play FB");
			CLCD_voidGoToXPos(3,1);
			CLCD_voidWriteData(2);
			CLCD_voidGoToXPos(4,1);
			CLCD_voidWriteData(3);
			_delay_ms(1000);

		}

		/*scene 3*/

		for(int i=0;i<5;i++)
		{
			/*Clear*/
			CLCD_voidWriteCmd(0b00000001);
			CLCD_voidGoToXPos(0,0);
			CLCD_void_WriteString("I Can Dance");
			CLCD_voidGoToXPos(3,1);
			CLCD_voidWriteData(0);
			_delay_ms(1000);
			/*Clear*/
			CLCD_voidWriteCmd(0b00000001);
			CLCD_voidGoToXPos(0,0);
			CLCD_void_WriteString("I can Dance");
			CLCD_voidGoToXPos(3,1);
			CLCD_voidWriteData(4);
			_delay_ms(1000);

		}

	}


}


