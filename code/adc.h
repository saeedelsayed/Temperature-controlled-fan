/**************************************************************************************************************
 *
 * MODULE: ADC
 *
 * FILE NAME: adc.h
 *
 * Description: Header file for the ADC driver
 *
 * Created on: October 7 , 2022
 *
 * Author: Saeed Elsayed
 *
 **************************************************************************************************************/


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE          1023             // the ADC in the AVR has 10 pins that carry its value
#define ADC_REF_VOLT_VALUE         2.56             // we choose what we like

typedef enum                    // enum for the different types of the ADC reference volt
{
	AREF, AVCC, internal = 3
}ADC_ReferenceVolatge;

typedef enum                    // enum for the different types of the ADC prescaler
{
	F_CPU_2 = 1, F_CPU_4, F_CPU_8, F_CPU_16, F_CPU_32, F_CPU_64, F_CPU_128
}ADC_Prescaler;

typedef struct      // struct that will be passed to the initialization function to choose the reference volt
{                   // and the prescaler
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;


/*
 * Description:
 * function that initialize the ADC
 */
void ADC_init(const ADC_ConfigType* Config_Ptr);


/*
 * Description:
 * read the analog data from a specific channel and use the ADC to convert it to digital
 */
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
