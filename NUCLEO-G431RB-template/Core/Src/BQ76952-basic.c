#include "BQ76952-basic.h"
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


/*
 * Tests that I2C communication to the device is functional, the status variable is where
 * the result will be stored. This buffer should be of length >= 24
 */
void TestConnection(char* status)
{
	HAL_StatusTypeDef i2c_com_status;


	//0x03 -> access safety status register A
	i2c_com_status = HAL_I2C_Master_Transmit(PTR_BQ76952_I2C_HANDLE,
											BQ76952_I2C_ADDRESS,
											0x03, 1, 1000);

	if (ret != HAL_OK)
	{
		strcpy((char*)buf, "BQ76952 I2C TX Error\r\n\0");
		return;
	}

	i2c_com_status = HAL_I2C_Master_Receive(PTR_BQ76952_I2C_HANDLE,
											BQ76952_I2C_ADDRESS,
											status, 1, 1000);

	if (ret != HAL_OK)
	{
		strcpy((char*)buf, "BQ76952 I2C RX Error\r\n\0");
		return;
	}

	strcpy((char*)buf, "BQ76952 I2C Comms OK\r\n\0");
}



