/*******************************/
/* Author  : Areej Ayman Helal */
/* Version : V01               */
/* Date    : 3 Feb  2020       */
/*******************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADMUX   *((volatile u8 *)0x27)
#define ADCSRA  *((volatile u8 *)0x26)
#define ADCH    *((volatile u8 *)0x25)
#define ADCL    *((volatile u8 *)0x24)

void ADC_init(void);
u8 ADC_GetChannelReading(u8 channel);
#endif /* ADC_INTERFACE_H_ */
