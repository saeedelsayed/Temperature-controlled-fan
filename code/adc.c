/**************************************************************************************************************
 *
 * MODULE: ADC
 *
 * FILE NAME: adc.c
 *
 * Description: Source file for the ADC driver
 *
 * Created on: October 7 , 2022
 *
 * Author: Saeed Elsayed
 *
 **************************************************************************************************************/

#include "adc.h"
#include <avr/io.h>
#include "common_macros.h"
/*
 * Description:
 * function that initialize the ADC
 */
void ADC_init(const ADC_ConfigType* Config_Ptr)  // send the prescaler wanted and the reference volt as a struct
{

	ADMUX |= ((Config_Ptr->ref_volt)<<6);    // choose the reference volt
	SET_BIT(ADCSRA,ADEN);         // enable the ADC
	ADCSRA |= Config_Ptr->prescaler;   // choose the prescaler

}


/*
 * Description:
 * read the analog data from a specific channel and use the ADC to convert it to digital
 */
uint16 ADC_readChannel(uint8 ch_num)
{

	ch_num&=0x07;              // make sure the number is not greater than 7 as the AVR have only 8 analog pins
	ADMUX &= 0xE0;             // clear the first five pins of ADMUX as they which specify the channel
	ADMUX |= ch_num;           // determine the channel number
	SET_BIT(ADCSRA,ADSC);      // start the conversion
	while(BIT_IS_CLEAR(ADCSRA,ADIF));   // wait until the conversion is complete so the flag will be set
	SET_BIT(ADCSRA,ADIF);               // clear the flag by writing one to it
	return ADC;                         // read the value of the ADC

}
