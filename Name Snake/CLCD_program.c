/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 15 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_register.h"
#include "CLCD_private.h"

 
 
/*Description : This API shall initialize LCD*/
void CLCD_voidInitialize(void)
{
	
	_delay_ms(40);
	CLCD_voidWriteCmd(0b00111000);
	CLCD_voidWriteCmd(0b00001100);
	CLCD_voidWriteCmd(0b00000001);
	_delay_ms(2);
	
}

/*Description : This API shall display data on LCD*/
void CLCD_voidWriteData(u8 Copy_u8Data)
{
	/*Set RS = 1 */
	DIO_setPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
	/*Set RW = 0 */
	DIO_setPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);	
	/*Set Data on data port */
	CLCD_voidSetDataPort(Copy_u8Data);		
	/*Enable pulse */
	DIO_setPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	DIO_setPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
	
}

/*Description : This API shall excute command on LCD*/
void CLCD_voidWriteCmd(u8 Copy_u8Cmd)
{
	/*Set RS = 0 */
	DIO_setPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
	/*Set RW = 0 */
	DIO_setPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);		
	/*Set Data on data port */
	CLCD_voidSetDataPort(Copy_u8Cmd);			
	/*Enable pulse */
		DIO_setPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	DIO_setPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
	
}
 
static void CLCD_voidSetDataPort(u8 Copy_u8Data)
{
	u8 Local_u8BitVal;
	Local_u8BitVal = GET_BIT(Copy_u8Data,0);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D0,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,1);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D1,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,2);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D2,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,3);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D3,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,4);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D4,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,5);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D5,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,6);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D6,Local_u8BitVal);
	Local_u8BitVal = GET_BIT(Copy_u8Data,7);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D7,Local_u8BitVal);
}
