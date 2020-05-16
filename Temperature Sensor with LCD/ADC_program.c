/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 3 Feb  2020       */
/*******************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
void ADC_init(void){
	/*AREF is selected*/
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	/*Left adjustment is selected*/
	SET_BIT(ADMUX,5);
	/*Enable ADC*/
	SET_BIT(ADCSRA,7);
	/*Prescaler is 128 */
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
}
 u8 ADC_GetChannelReading(u8 channel){
	 ADMUX &=0b11100000;
	 ADMUX |=channel;
	 /*enable ADC*/
	 //SET_BIT(ADCSRA,7);
	 /*Start ADC*/
	 SET_BIT(ADCSRA,6);
	 while((GET_BIT(ADCSRA,4))==0);
	 /*Clear the flag*/
	 SET_BIT(ADCSRA,4);
	 return ADCH;
 }
