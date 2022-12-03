/*
 * BQ76952-basic.c
 *
 *  Created on: Nov. 12, 2022
 *      Author: Aspen Erlandsson, IG: @xzips
 *
 * TI-BQ76952 Basic driver to cover the core functionalities necessary for future development,
 * namely: Initiate a connection with the device, receive basic information such as device ID,
 * as well as unit test cases as they apply to the BMS Core Functionality Driver.
 *
 */

#define BQ76952
#include <stdint.h>


static const uint8_t BQ76952_I2C_ADDRESS = 0b0011000 << 1;
I2C_HandleTypeDef *PTR_BQ76952_I2C_HANDLE = &hi2c1;//placeholder


/*
 * Tests that I2C communication to the device is functional, the status variable is where
 * the result will be stored. This buffer should be of length >= 24
 */

void TestConnection(char *status);

uint8_t BQ76952_I2C_Read(I2C_HandleTypeDef *DEVICE_ADRRESS, uint16_t I2C_ADDRESS, uint8_t buff, uint16_t numBytes);

#ifndef BQ76952_BASIC_H_
#define BQ76952_BASIC_H_
















#endif /* BQ76952_BASIC_H_ */
