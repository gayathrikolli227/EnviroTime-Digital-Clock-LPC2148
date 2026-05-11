/*--------------------------------------------------------------
File Name   : RTC.H
Description : Header file for Real Time Clock (RTC)
              module. Contains function declarations
              for RTC initialization, time/date/day
              setting, reading, and LCD display.
--------------------------------------------------------------*/

#ifndef _RTC_H_
#define _RTC_H_

#include "type.h"



/*--------------------------------------------------------------
RTC Initialization
--------------------------------------------------------------*/
void Init_RTC(void);



/*--------------------------------------------------------------
RTC Time Functions
--------------------------------------------------------------*/
void SetRTCTimeInfo(u32, u32, u32);

void GetRTCTimeInfo(s32 *, s32 *, s32 *);

void DisplayRTCTime(u32, u32, u32);



/*--------------------------------------------------------------
RTC Date Functions
--------------------------------------------------------------*/
void SetRTCDateInfo(u32, u32, u32);

void GetRTCDateInfo(s32 *, s32 *, s32 *);

void DisplayRTCDate(u32, u32, u32);



/*--------------------------------------------------------------
RTC Day Functions
--------------------------------------------------------------*/
void SetRTCDay(u32);

void GetRTCDay(s32 *);

void DisplayRTCDay(u32);



#endif
