/**************************************************************************************************************
 *
 * MODULE: lm35_sensor
 *
 * FILE NAME: lm35_sensor.h
 *
 * Description: Header file for the lm35_sensor driver
 *
 * Created on: October 7, 2022
 *
 * Author: Saeed Elsayed
 *
 **************************************************************************************************************/


#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

#define SENSOR_CHANNEL_ID           2           // the analog pin in port A which the sensor is connected to
#define SENSOR_MAX_VOLT_VALUE       1.5
#define SENSOR_MAX_TEMPERATURE      150


/*
 * Description:
 * function that get the temperature from the ADC
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
