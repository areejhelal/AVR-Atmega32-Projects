/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 16 Jan 2020       */
/*******************************/

/*Description : This API shall initialize LCD*/
void CLCD_voidInitialize(void);

/*Description : This API shall display data on LCD*/
void CLCD_voidWriteData(u8 copy_u8Data);

/*Description : This API shall excute command on LCD*/
void CLCD_voidWriteCmd(u8 copy_u8Cmd);


void setLocation(u8 Row,u8 Col);

/*Description : This API shall excute command on LCD*/
void CLCD_voidWriteCmd(u8 copy_u8Cmd);

#define CLCD_u8_LINE_ONE 0
#define CLCD_u8_LINE_TWO 1

void CLCD_voidGoToXPos(u8 Copy_u8XPos,u8 Copy_u8YPos);

