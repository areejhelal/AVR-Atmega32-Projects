/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 29 Jan 2020       */
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
#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE

	/*Set RS = 0 */
	DIO_setPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);

	/*Set RW = 0 */
	DIO_setPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);

	/*Send 0010*/
	CLCD_voidSetHalfDataPort(0b0010);
	/*Send Enable Pulse */
	CLCD_voidSetEnablePulse();

	/*Send 0010 Again*/
	CLCD_voidSetHalfDataPort(0b0010);
	/*Send Enable Pulse */
	CLCD_voidSetEnablePulse();

	/*Send 2 Lines Display , Font =5*7*/
	CLCD_voidSetHalfDataPort(0b1000);
	/*Send Enable Pulse */
	CLCD_voidSetEnablePulse();
	/*Display On Command*/
	CLCD_voidWriteCmd(0b00001100);
	/*Display Clear*/
	CLCD_voidWriteCmd(0b00000001);
	_delay_ms(2);

#elif	CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
	/*Set Two Lines*/
	CLCD_voidWriteCmd(0b00111100);
	/*Display On Command*/
	CLCD_voidWriteCmd(0b00001100);
	/*Display Clear*/
	CLCD_voidWriteCmd(0b00000001);
	_delay_ms(2);

#else #error "wrong Data Length Choice"
#endif


}

/*Description : This API shall display data on LCD*/
void CLCD_voidWriteData(u8 Copy_u8Data)
{
	/*Set RS = 1 */
	DIO_setPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
	/*Set RW = 0 */
	DIO_setPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);	


#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE
	/*Set Higher Order 4 bits of the command*/
	CLCD_voidSetHalfDataPort(Copy_u8Data >> 4);

	/*Send the enable Pulse*/
	CLCD_voidSetEnablePulse();

	/*Set Lower Order 4 bits of the command*/
	CLCD_voidSetHalfDataPort(Copy_u8Data);

	/*Send the enable Pulse*/
	CLCD_voidSetEnablePulse();

#elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
	/*Set Data on data port */
	CLCD_voidSetDataPort(Copy_u8Data);

	/*Send the enable Pulse*/
	CLCD_voidSetEnablePulse();

#else	#error "Wrong Data Length Choice"
#endif


}

/*Description : This API shall excute command on LCD*/
void CLCD_voidWriteCmd(u8 Copy_u8Cmd)
{

	/*Set RS = 0 */
	DIO_setPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);

	/*Set RW = 0 */
	DIO_setPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);

#if CLCD_u8_DATA_LENGTH == FOUR_BITS_MODE
	/*Set Higher Order 4 bits of the command*/
	CLCD_voidSetHalfDataPort(Copy_u8Cmd >> 4);

	/*Send the enable Pulse*/
	CLCD_voidSetEnablePulse();

	/*Set Lower Order 4 bits of the command*/
	CLCD_voidSetHalfDataPort(Copy_u8Cmd);

	/*Send the enable Pulse*/
	CLCD_voidSetEnablePulse();

#elif CLCD_u8_DATA_LENGTH == EIGHT_BITS_MODE
	/*Set Data on data port */
	CLCD_voidSetDataPort(Copy_u8Cmd);

	/*Send the enable Pulse*/
	CLCD_voidSetEnablePulse();

#else	#error "Wrong Data Length Choice"
#endif

}

static void CLCD_voidSetEnablePulse(void)
{
	/*Enable pulse */
	DIO_setPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	DIO_setPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);

}

static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data)
{
	u8 Local_u8BitVal;
	Local_u8BitVal = GET_BIT(Copy_u8Data,0);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D4,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,1);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D5,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,2);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D6,Local_u8BitVal);

	Local_u8BitVal = GET_BIT(Copy_u8Data,3);
	DIO_setPinValue(CLCD_u8_DATA_PORT,CLCD_u8_D7,Local_u8BitVal);
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


void setLocation(u8 Row,u8 Col)
{
	switch(Row)
	{
	case 0:
		switch(Col)
		{
		case 1:
			/*set ddram*/
			CLCD_voidWriteCmd(0b10000000);
			break;
		case 2:
			/*set ddram*/
			CLCD_voidWriteCmd(0b10000010);
			break;
		case 3:
			/*set ddram*/
			CLCD_voidWriteCmd(0b10000100);
			break;
		case 4:
			/*set ddram*/
			CLCD_voidWriteCmd(0b10000111);
			break;
		case 5:
			/*set ddram*/
			CLCD_voidWriteCmd(0b10001000);
			break;
		case 6:
			/*set ddram*/
			CLCD_voidWriteCmd(0b10001010);
			break;
		case 7:
			/*set ddram*/
			CLCD_voidWriteCmd(0b10001100);
			break;
		case 8:
			/*set ddram*/
			CLCD_voidWriteCmd(0b10001110);
			break;

		}

		break;
		case 1:
			switch(Col)
			{
			case 1:
				/*set ddram*/
				CLCD_voidWriteCmd(0b11000000);
				break;
			case 2:
				/*set ddram*/
				CLCD_voidWriteCmd(0b11000010);
				break;
			case 3:
				/*set ddram*/
				CLCD_voidWriteCmd(0b11000100);
				break;
			case 4:
				/*set ddram*/
				CLCD_voidWriteCmd(0b11000110);
				break;
			case 5:
				/*set ddram*/
				CLCD_voidWriteCmd(0b11001000);
				break;
			case 6:
				/*set ddram*/
				CLCD_voidWriteCmd(0b11001010);
				break;
			case 7:
				/*set ddram*/
				CLCD_voidWriteCmd(0b10001100);
				break;
			case 8:
				/*set ddram*/
				CLCD_voidWriteCmd(0b11001110);
				break;

			}
			break;
	}

}

void CLCD_voidGoToXPos(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8DDRamAdd;
	if(Copy_u8YPos==CLCD_u8_LINE_ONE)
	{
		Local_u8DDRamAdd=Copy_u8XPos;
	}
	else if(Copy_u8YPos==CLCD_u8_LINE_TWO)
	{
		Local_u8DDRamAdd=Copy_u8XPos + CLCD_u8_LINE_TWO_ADD_OFFSET;
	}
	else
	{
		/*Do Nothing*/
	}
	CLCD_voidWriteCmd(Local_u8DDRamAdd|CLCD_u8_SET_DDRAM_ADD_CMD);
}

void CLCD_void_WriteString(const char* Copy_pchString)
{
	while(*Copy_pchString !='\0')
	{
		CLCD_voidWriteData(*Copy_pchString);
		Copy_pchString ++;
	}
}
