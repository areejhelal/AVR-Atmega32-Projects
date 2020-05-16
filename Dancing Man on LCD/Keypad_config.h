/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 28 Jan 2020       */
/*******************************/

/*Keypad pins configuration */
#define Keypad_R0_PORT 'B'
#define Keypad_R0_PIN	0

#define Keypad_R1_PORT	'B'
#define Keypad_R1_PIN	1

#define Keypad_R2_PORT	'B'
#define Keypad_R2_PIN	2

#define Keypad_R3_PORT	'B'
#define Keypad_R3_PIN	3

#define Keypad_C0_PORT	'B'
#define Keypad_C0_PIN	4

#define Keypad_C1_PORT	'B'
#define Keypad_C1_PIN	5

#define Keypad_C2_PORT	'B'
#define Keypad_C2_PIN	6

#define Keypad_C3_PORT	'B'
#define Keypad_C3_PIN	7

/*Rows and Columns number configuration*/
#define Keypad_Rows_Number 		4
#define Keypad_Columns_Number	4

#define KEYPAD_Rows_PORT {Keypad_R0_PORT,Keypad_R1_PORT,Keypad_R2_PORT,Keypad_R3_PORT}
#define KEYPAD_Rows_PIN {Keypad_R0_PIN,Keypad_R1_PIN,Keypad_R2_PIN,Keypad_R3_PIN}

#define KEYPAD_Columns_PORT {Keypad_C0_PORT,Keypad_C1_PORT,Keypad_C2_PORT,Keypad_C3_PORT}
#define KEYPAD_Columns_PIN {Keypad_C0_PIN,Keypad_C1_PIN,Keypad_C2_PIN,Keypad_C3_PIN}

/*Choose the Keypad Keys representation*/
#define KEYPAD_KEYS {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}}

/*Choose Default Value when no key is pressed*/
#define KEYPAD_DEFAULT 0x00
