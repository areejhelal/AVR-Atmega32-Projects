/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 3 Feb  2020       */
/*******************************/

#define SET_BIT(VAR,BIT_NO) (VAR|=(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO) (VAR &=(~(1<<BIT_NO)))
#define TOGGLE_BIT(VAR,BIT_NO) (VAR ^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO) ((VAR >>BIT_NO) &0x01)
