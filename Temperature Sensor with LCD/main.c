/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 3 Feb  2020       */
/*******************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"
# define F_CPU 12000000UL


#include "PORT_register.h"

void main (void)
{
	PortInitialize();
	CLCD_voidInitialize();
	ADC_init();
	 while(1)
	 {
		 u8 ADC_Reading= ADC_GetChannelReading(0);
		 u16 Analog_value_MV= ((u32)ADC_Reading*5000UL)/256UL;
		 u16 Temp = Analog_value_MV/10;
		 CLCD_voidWriteCmd(0b00000001);
		 CLCD_voidWriteNumber(Temp);
	 }
}




