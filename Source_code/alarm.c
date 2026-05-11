/*--------------------------------------------------------------
File Name   : ALARM.C
Description : Handles alarm time setting and alarm triggering
              using RTC and buzzer output
--------------------------------------------------------------*/

#include "Intial.h"
#include <lpc21xx.h>
#include "lcd.h"
#include "rtc.h"
#include "lcd_defines.h"
#include "delay.h"
#include "type.h"

/* Buzzer connected to P0.25 */
#define BUZZER_PIN 25

/* Global alarm variables */
extern u32 alarm_hour, alarm_min;
extern u32 alarm_flag;


/*--------------------------------------------------------------
Function Name : alarm_time_setting()
Description   : Gets alarm hour and minute from user
                and stores them as alarm values
--------------------------------------------------------------*/
void alarm_time_setting(void)
{
    /* Clear LCD before hour entry */
    CmdLCD(CLEAR_LCD);

    /* Get alarm hour from user */
    alarm_hour = get_hour_from_user();


    /* Clear LCD before minute entry */
    CmdLCD(CLEAR_LCD);

    /* Get alarm minute from user */
    alarm_min = get_min_from_user();


    /* Display confirmation message */
    CmdLCD(CLEAR_LCD);
    StrLCD("ALARM SAVED");

    /* Display message for 1 second */
    delay_ms(1000);

    /* Clear LCD */
    CmdLCD(CLEAR_LCD);
}


/*--------------------------------------------------------------
Function Name : check_alarm()
Description   : Continuously compares current RTC time
                with alarm time. If both match, buzzer
                is activated.
--------------------------------------------------------------*/
void check_alarm(void)
{
    s32 h, m, s;

    /* Prevent alarm from triggering multiple times
       within same minute */
    static u32 alarm_done = 0;


    /* Read current RTC time */
    GetRTCTimeInfo(&h, &m, &s);


    /* Check whether current time matches alarm time */
    if((h == alarm_hour) &&
       (m == alarm_min) &&
       (alarm_done == 0))
    {
        /* Set alarm active flag */
        alarm_flag = 1;


        /* Turn ON buzzer */
        IOSET0 = (1 << BUZZER_PIN);


        /* Prevent repeated triggering */
        alarm_done = 1;
    }


    /* Reset alarm trigger for next alarm cycle */
    if((h != alarm_hour) || (m != alarm_min))
    {
        alarm_done = 0;
    }
}
