/*
 * BQ76952-status-check.h
 *
 *  Created on: Nov. 18, 2022
 *      Author: Richard Li
 */



#ifndef INC_BQ76952_STATUS_CHECK_H_
#define INC_BQ76952_STATUS_CHECK_H_

#include <stdint.h>

const uint8_t STATUS_ADDRESS = 0x12; //status check address


typedef enum
{
  CFGUPDATE    = 1,       //CONFIG_UPDATE
  PCHG_MODE    = 1<<1,    //PRECHARGE MODE
  SLEEP_EN     = 1<<2,    //SLEEP MODE ALLOWED
  POR          = 1<<3,	  //RAM CONFIGURATIONS LOST FORM CONFIG_UPDATE EXIT
  WD           = 1<<4,    //WATCHDOG TIMER RESET
  COW_CHK      = 1<<5,    //OPEN WIRE CHECKS
  OTPW         = 1<<6,    //PENDING DATA
  OTPB         = 1<<7,    //OTP WRITING PERMISSION
  SEC          = 11<<8,   //SECURITY STATE
  FUSE 		   = 1<<10,   //FUSE
  SS		   = 1<<11,   //SAFETY FAULT
  PF		   = 1<<12,   //PERMANENT FAULT
  SDM		   = 1<<13,   //SHUTDOWN MODE
  SLEEP 	   = 1<<15    //SLEEP MODE
} Status_TypeDef;


void requestStatus(uint8_t buff [], uint16_t position);

#endif /* INC_BQ76952_STATUS_CHECK_H_ */
