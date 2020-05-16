/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 28 Jan 2020       */
/*******************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "Keypad_config.h"
#include "Keypad_interface.h"s
#include "Keypad_private.h"




u8 KEYPAD_GetPressedKey(void)
{
	u8 Keypad_Rows_Port[Keypad_Rows_Number]	= KEYPAD_Rows_PORT;
	u8 Keypad_Columns_Port[Keypad_Columns_Number] =	KEYPAD_Columns_PORT;
	
	u8 Keypad_Rows_Pin[Keypad_Rows_Number] = KEYPAD_Rows_PIN;
	u8 Keypad_Columns_Pin[Keypad_Columns_Number] = KEYPAD_Columns_PIN;
	
	u8 Keypad_Keys[Keypad_Rows_Number][Keypad_Columns_Number] =	KEYPAD_KEYS	;
	
	u8 RowIndex,ColumnIndex,PinState;
	
	u8 PressedKey=KEYPAD_DEFAULT;

	for(RowIndex=0;RowIndex<Keypad_Rows_Number;RowIndex++)
	{
		/*Activate the current Row*/
		DIO_setPinValue(Keypad_Rows_Port[RowIndex],Keypad_Rows_Pin[RowIndex],0);
		
		/*Check Columns if Pressed*/
		for(ColumnIndex=0;ColumnIndex<Keypad_Columns_Number;ColumnIndex++)
		{
			PinState =DIO_getPinValue(Keypad_Columns_Port[ColumnIndex],Keypad_Columns_Pin[ColumnIndex]);
			/*Check if the Key is Pressed*/
			if(0 == PinState)
			{
				PressedKey = Keypad_Keys[RowIndex][ColumnIndex];
				
				/*busy waiting until the key is released*/
				/*while(0==PinState)
				{
					PinState =getPinValue(Keypad_Columns_Port[ColumnIndex],Keypad_Columns_Pin[ColumnIndex]);
				}
				return PressedKey;*/
			}
		}
		
		/*Deactivate the current Row*/
		DIO_setPinValue(Keypad_Rows_Port[RowIndex],Keypad_Rows_Pin[RowIndex],1);
	}
	return PressedKey;
				
}

