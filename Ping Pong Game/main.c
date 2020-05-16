/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 29 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
# define F_CPU 12000000UL


#include "PORT_register.h"

void main (void)
{
	PortInitialize();
	CLCD_voidInitialize();

	static u8 y1 =0,y2=1,y=1 ,x=1;
	//CGRAM 0
	CLCD_voidWriteCmd(0x40);
	/*Right Madrab*/
	CLCD_voidWriteData(0b00011);
	CLCD_voidWriteData(0b00011);
	CLCD_voidWriteData(0b00011);
	CLCD_voidWriteData(0b00011);
	CLCD_voidWriteData(0b00011);
	CLCD_voidWriteData(0b00011);
	CLCD_voidWriteData(0b00011);
	CLCD_voidWriteData(0b00011);

	//CGRAM 1
	CLCD_voidWriteCmd(0x48);
	/*Left Madrab*/
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b11000);

	//CGRAM 2
	CLCD_voidWriteCmd(0x50);
	/*ball up*/
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b11000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);

	//CGRAM 3
	CLCD_voidWriteCmd(0x58);
	/*ball Down*/
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00000);
	CLCD_voidWriteData(0b00011);
	CLCD_voidWriteData(0b00011);



	/*DDRAM*/
	CLCD_voidWriteCmd(0b10000000);


	CLCD_voidGoToXPos(0,y1);

	CLCD_voidWriteData(0);

	CLCD_voidGoToXPos(15,y2);

	CLCD_voidWriteData(1);

	while(1)
	{


		if(DIO_getPinValue('B',0)==0)
		{
			if(y1==1)
			{
				y1=0;
			}
			else if(y1==0)
			{
				y1=1;
			}

			_delay_ms(20);
		}
		if(DIO_getPinValue('B',1)==0)
		{
			if(y2==1)
			{
				y2=0;
			}
			else if(y2==0)
			{
				y2=1;
			}

			_delay_ms(20);

		}

		if(x<14)
		{
		/*madrabz*/
		CLCD_voidGoToXPos(0,y1);

		CLCD_voidWriteData(0);

		CLCD_voidGoToXPos(15,y2);

		CLCD_voidWriteData(1);

		/*ball*/
		CLCD_voidGoToXPos(y,0);

		CLCD_voidWriteData(3);

		/*Clear and delay*/
		_delay_ms(500);
		CLCD_voidWriteCmd(0b00000001);
		y++;
		x++;
		}
		//winner or loser
		if(y2==1&&x==14)
		{
			CLCD_voidWriteCmd(0b00000001);
			CLCD_void_WriteString("Player 1 Wins !");
			_delay_ms(2000);


		}
		//ball back
		if(x>=14 && x<29)
		{
			/*madrabz*/
			CLCD_voidGoToXPos(0,y1);

			CLCD_voidWriteData(0);

			CLCD_voidGoToXPos(15,y2);

			CLCD_voidWriteData(1);

			/*ball*/
			CLCD_voidGoToXPos(y,0);

			CLCD_voidWriteData(3);

			/*Clear and delay*/
			_delay_ms(500);
			CLCD_voidWriteCmd(0b00000001);
			y--;
			x++;
			if(x==28)
			{
				x=1;
				y=1;
			}
		}
		//winner or loser
		if(y1==1&&x==1)
		{
			CLCD_voidWriteCmd(0b00000001);
			CLCD_void_WriteString("Player 2 Wins !");
			_delay_ms(2000);


		}


	}


}




