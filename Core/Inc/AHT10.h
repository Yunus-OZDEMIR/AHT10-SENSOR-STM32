/*
 * AHT10.h
 *
 *  Created on: Sep 11, 2022
 *      Author: YUNUS ÖZDEMİR
 */

#ifndef INC_AHT10_H_
#define INC_AHT10_H_

#define AHT10_Address		(0x38<<1)
#define TrıgMeasurement		0xAC


void AHT_SENSOR_READ(uint8_t *Humidity, uint8_t *Temperature);

#endif /* INC_AHT10_H_ */
