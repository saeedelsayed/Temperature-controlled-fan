/**************************************************************************************************************
 *
 * MODULE: lm35_sensor
 *
 * FILE NAME: lm35_sensor.c
 *
 * Description: Source file for the lm35_sensor driver
 *
 * Created on: October 7, 2022
 *
 * Author: Saeed Elsayed
 *
 **************************************************************************************************************/

#include "lm35_sensor.h"
#include "adc.h"

/*
 * Description:
 * function that initialize the LM35 sensor
 */
uint8 LM35_getTemperature(){
	uint16 ADC_value;
	uint8 TEMP_value;

	ADC_value = ADC_readChannel(SENSOR_CHANNEL_ID);     // take the digital value of the ADC which represent
                                                        // the analog value of the sensor
	//calculate the temperature value using the equation of the sensor temperature
	TEMP_value = (uint8)(((uint32)ADC_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return TEMP_value;   // return the value of the temperature
}
