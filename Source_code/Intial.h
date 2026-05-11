/*--------------------------------------------------------------
File Name   : INTIAL.H
Description : Master header file for EnviroTime project.
              Contains function declarations for
              system initialization, RTC editing,
              alarm handling, password security,
              keypad input, and display modules.
--------------------------------------------------------------*/

#ifndef INTIAL_H
#define INTIAL_H

#include "type.h"



/*--------------------------------------------------------------
System Initialization
--------------------------------------------------------------*/
void Init_system(void);



/*--------------------------------------------------------------
Main Menu Processing
--------------------------------------------------------------*/
void process_edit_menu(void);

u32 open_edit_menu(void);



/*--------------------------------------------------------------
Display Functions
--------------------------------------------------------------*/
void display_envirotime(void);



/*--------------------------------------------------------------
Password Functions
--------------------------------------------------------------*/
u32 password(void);

void update_password(s8 *);

void get_password_from_user(s8 *);



/*--------------------------------------------------------------
Alarm Functions
--------------------------------------------------------------*/
void alarm_time_setting(void);

void check_alarm(void);



/*--------------------------------------------------------------
RTC Edit Functions
--------------------------------------------------------------*/
void edit_rtc_settings(void);

u32 rtc_edit_menu(void);



/*--------------------------------------------------------------
RTC Parameter Update Functions
--------------------------------------------------------------*/
void set_rtc_hour(u32 *);

void set_rtc_minute(u32 *);

void set_rtc_second(u32 *);

void set_rtc_day(u32 *);

void set_rtc_date(u32 *);

void set_rtc_month(u32 *);

void set_rtc_year(u32 *);



/*--------------------------------------------------------------
Date Validation
--------------------------------------------------------------*/
u32 days_in_month(u32, u32);



/*--------------------------------------------------------------
Keypad Input Functions
--------------------------------------------------------------*/
u32 get_number_from_keypad(void);

u32 get_hour_from_user(void);

u32 get_min_from_user(void);

u32 select_time_edit_option(void);



#endif
