/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 16 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "Keypad_interface.h"
#include <util/delay.h>
#include "CLCD_interface.h"
# define F_CPU 12000000UL


#include "PORT_register.h"

void main (void)
{
	PortInitialize();
	CLCD_voidInitialize();
	/*set function*/
	CLCD_voidWriteCmd(0b00111000);
	/*r = 0 or 1
	 c = 0:15 */
	u8 r= 0, c=0;

	while(1)
	{
		u8 x = KEYPAD_GetPressedKey();
		_delay_ms(50);
		CLCD_voidWriteCmd(0b00000001);

		CLCD_voidGoToXPos(c,r);

		CLCE_void_WriteString("Areej");
		if(KEYPAD_GetPressedKey()!=0)
		{
		switch(x)
		{
		//up
		case 1:
			r=0;
			CLCD_voidGoToXPos(c,r);
			CLCE_void_WriteString("Areej");
			break;
			//left
		case 4:
			c-=2;
			CLCD_voidGoToXPos(c,r);
			CLCE_void_WriteString("Areej");
			break;
			//right
		case 6:
			c+=2;
			CLCD_voidGoToXPos(c,r);
			CLCE_void_WriteString("Areej");
			break;
			//down
		case 9:
			r=1;
			CLCD_voidGoToXPos(c,r);
			CLCE_void_WriteString("Areej");
			break;

		}


		}
	}


}


