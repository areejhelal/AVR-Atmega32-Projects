/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 14 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "Keypad_interface.h"
#include <util/delay.h>
# define F_CPU 12000000UL


#include "PORT_register.h"


void main (void)
{
	PortInitialize();
	CLCD_voidInitialize();
	/*set function*/
	CLCD_voidWriteCmd(0b00111000);
	u8 arr[3];
	u8 pass[3]={1,2,3};
	u8 i=0,j=0,k=0;
	u8 static f=0;

	/*clear*/
	CLCD_voidWriteCmd(0b00000001);
	CLCD_voidWriteData('P');
	CLCD_voidWriteData('a');
	CLCD_voidWriteData('s');
	CLCD_voidWriteData('s');
	CLCD_voidWriteData('w');
	CLCD_voidWriteData('o');
	CLCD_voidWriteData('r');
	CLCD_voidWriteData('d');
	CLCD_voidWriteData(':');

	while(1)
	{


		u8 x = KEYPAD_GetPressedKey();
		_delay_ms(200);
		if(KEYPAD_GetPressedKey!=0)
		{
			switch(x)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				if(i<3)
				{
					arr[i]=x;
					CLCD_voidWriteData('*');
					i++;
				}
				break;

			case 10:
				for(j=0;j<3;j++)
				{
					if(arr[j]==pass[j])
					{
						f++;

					}
				}
				if(f==3)
				{

					/*add 0x47*/
					/*set ddram*/
					CLCD_voidWriteCmd(0b11000111);
					CLCD_voidWriteData('v');
					CLCD_voidWriteData('a');
					CLCD_voidWriteData('l');
					CLCD_voidWriteData('i');
					CLCD_voidWriteData('d');
					f=0;
					j=0;
					break;
				}
				else
				{
					if(k<3&&f!=3)
					{
						x=11;
						i=0;
						k++;
						j=0;
						/*Try Again*/
						/*clear*/
						CLCD_voidWriteCmd(0b00000001);
						CLCD_voidWriteData('T');
						CLCD_voidWriteData('r');
						CLCD_voidWriteData('y');
						CLCD_voidWriteData(' ');
						CLCD_voidWriteData('A');
						CLCD_voidWriteData('g');
						CLCD_voidWriteData('a');
						CLCD_voidWriteData('i');
						CLCD_voidWriteData('n');
						CLCD_voidWriteData(':');

					}
					}
					if(k==3)
					{
						/*add 0x47*/
						/*set ddram*/
						CLCD_voidWriteCmd(0b11000111);
						CLCD_voidWriteData('i');
						CLCD_voidWriteData('n');
						CLCD_voidWriteData('v');
						CLCD_voidWriteData('a');
						CLCD_voidWriteData('l');
						CLCD_voidWriteData('i');
						CLCD_voidWriteData('d');
						j=0;
						k=0;
					}
					break;

			case 11:
				i=0;
				/*clear*/
				CLCD_voidWriteCmd(0b00000001);
				CLCD_voidWriteData('P');
				CLCD_voidWriteData('a');
				CLCD_voidWriteData('s');
				CLCD_voidWriteData('s');
				CLCD_voidWriteData('w');
				CLCD_voidWriteData('o');
				CLCD_voidWriteData('r');
				CLCD_voidWriteData('d');
				CLCD_voidWriteData(':');
				break;
				}

			}
		}
	}


