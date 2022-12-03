#include "BQ76952-basic.h"
#include "BQ76952-status-check.h"
#include <string.h>
#include <stdio.h>

/*
 * Pass in the position integer, see ENUM in Header File
 * Returns the current status in the provided buffer
 */
void requestStatus(uint8_t buff [], uint16_t position){
	HAL_StatusTypeDef ret;
	buff [0] = STATUS_ADDRESS;
	ret = HAL_I2C_Master_Transmit(PTR_BQ76952_I2C_HANDLE, BQ76952_I2C_ADDRESS, buff, 1, 1000);

	if(ret != HAL_OK){
		strcpy((char*)buff, "BQ76952 I2C TX Error\r\n");
		return;
	}
	ret = HAL_I2C_Master_Receive(PTR_BQ76952, BQ76952_I2C_ADDRESS, buff, 2, 1000);
	if(ret != HAL_OK){
		strcpy((char*)buff, "BQ76952 I2C RX Error\r\n");
		return;
	}
	uint16_t status = (uint16_t)buff [0] << 8 | buff[1];
	switch(position){
		case CFGUPDATE:
			if(position & status){
				strcpy((char*)buff, "Config Update Is Enabled\r\n");
			}
			else{
				strcpy((char*)buff, "Config Update Is Disabled\r\n");
			}
			break;
		case PCHG_MODE:
			if(position & status){
				strcpy((char*)buff, "Precharge Mode Enabled\r\n");
			}
			else{
				strcpy((char*)buff, "Precharge Mode Disabled\r\n");
			}
			break;
		case SLEEP_EN:
			if(position & status){
				strcpy((char*)buff, "Sleep Mode Allowed\r\n");
			}
			else{
				strcpy((char*)buff, "Sleep Mode is Disabled\r\n");
			}
			break;
		case POR:
			if(position & status){
				strcpy((char*)buff, "Full Reset has Occurred\r\n");
			}
			else{
				strcpy((char*)buff, "Full Reset has Not Occurred\r\n");
			}
			break;
		case WD:
			if(position & status){
				strcpy((char*)buff, "Reset From Watchdog Timer Reset\r\n");
			}
			else{
				strcpy((char*)buff, "Reset Normally\r\n");
			}
			break;
		case COW_CHK:
			if(position & status){
				strcpy((char*)buff, "Open Wire Check is Occurring\r\n");
			}
			else{
				strcpy((char*)buff, "No Open Wire Check\r\n");
			}
			break;
		case OTPW:
			if(position & status){
				strcpy((char*)buff, "OTP Writes are Pending\r\n");
			}
			else{
				strcpy((char*)buff, "No Writes Pending to OTP \r\n");
			}
			break;
		case OTPB:
			if(position & status){
				strcpy((char*)buff, "OTP Writes are Blocked\r\n");
			}
			else{
				strcpy((char*)buff, "OTP Writes are Allowed\r\n");
			}
			break;
		case SEC:
			uint16_t val = ((position | (position<<1)) & status)>>8;
			if(val == 0){
				strcpy((char*)buff, "Device Not Initialized\r\n");
			}
			else if(val == 1){
				strcpy((char*)buff, "Device is in FULLACCESSS Mode\r\n");
			}
			else if(val == 2){
				strcpy((char*)buff, "Device is in UNSEALED Mode\r\n");
			}
			else{
				strcpy((char*)buff, "Device is in SEALED Mode\r\n");
			}
			break;
		case FUSE:
			if(position & status){
				strcpy((char*)buff, "Fuse Asserted\r\n");
			}
			else{
				strcpy((char*)buff, "Fuse not Asserted\r\n");
			}
			break;
		case SS:
			if(position & status){
				strcpy((char*)buff, "Safety Fault Triggered\r\n");
			}
			else{
				strcpy((char*)buff, "No Safety Fault Triggered\r\n");
			}
			break;
		case PF:
			if(position & status){
				strcpy((char*)buff, "Permanent Fault Triggered\r\n");
			}
			else{
				strcpy((char*)buff, "No Permanent Fault Triggered\r\n");
			}
			break;
		case SDM:
			if(position & status){
				strcpy((char*)buff, "Shutdown Occurred/Is Pending\r\n");
			}
			else{
				strcpy((char*)buff, "No Shutdown Occurred\r\n");
			}
			break;
		case SLEEP:
			if(position & status){
				strcpy((char*)buff, "Device Is in Sleep Mode\r\n");
			}
			else{
				strcpy((char*)buff, "Device Is not in Sleep Mode\r\n");
			}
			break;
		default:
			strcpy((char*)buff, "Status Does Not Exist\r\n");
	}
}

/**
 * Not Completed
 */
uint16_t getVoltage(){
	float voltage = 0;

	return voltage;
}
