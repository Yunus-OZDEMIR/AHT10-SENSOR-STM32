/*
 * AHT10.c
 *
 *  Created on: Sep 11, 2022
 *      Author: YUNUS ÖZDEMİR
 */
#include "stm32f4xx_hal.h"
#include "AHT10.h"
#include <math.h>
extern I2C_HandleTypeDef hi2c1;

uint8_t Buffer[6];

uint8_t SendCommand[2]= {0x33, 0x00};
int32_t Humidity_Data; //RAW DATA
int32_t Temperature_Data;//RAW DATA

uint8_t Temperature;//CALCULATED VALUE
uint8_t Humidity;//CALCULATED VALUE


void AHT_SENSOR_READ(uint8_t *Humidity, uint8_t *Temperature){

	HAL_I2C_Mem_Write(&hi2c1, AHT10_Address, TrıgMeasurement, 1, SendCommand, 2, 100);
	HAL_Delay(75); //Necessary delay for device
	HAL_I2C_Master_Receive(&hi2c1, AHT10_Address, Buffer, 6, 100);

	Humidity_Data = (Buffer[3]>>4) | (Buffer[1]<<12)| (Buffer[2]<<4);
	Temperature_Data = ((Buffer[3] & 0x0F)<<16) | (Buffer[4]<<8 | Buffer[5]);

	*Temperature = ((Temperature_Data / pow(2,20))*200 - 50);
	*Humidity	= ((Humidity_Data / pow(2,20))*100);

}
