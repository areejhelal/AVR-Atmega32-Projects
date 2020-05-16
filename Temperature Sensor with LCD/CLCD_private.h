/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 3 Feb  2020       */
/*******************************/

static void CLCD_voidSetDataPort(u8 Copy_u8Data);
#define CLCD_u8_LINE_TWO_ADD_OFFSET 	0x40
#define CLCD_u8_SET_DDRAM_ADD_CMD 		0x80
#define FOUR_BITS_MODE 					0
#define EIGHT_BITS_MODE 				1
static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data);
static void CLCD_voidSetEnablePulse(void);
