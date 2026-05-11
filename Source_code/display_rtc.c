/*--------------------------------------------------------------
File Name   : DISPLAY_RTC.C
Description : Reads RTC date/time and LM35 temperature
              and displays them on 16x2 LCD
--------------------------------------------------------------*/
#include "lcd.h"
#include "lcd_defines.h"
#include "rtc.h"
#include "lm35.h"


/*--------------------------------------------------------------
Function Name : display_envirotime()
Description   : Displays current time, date, day,
                and temperature on LCD.

LCD Format:

Line 1 : HH:MM:SS T:27°C
Line 2 : DD/MM/YYYY WED
--------------------------------------------------------------*/
void display_envirotime(void)
{
    /* Variables for RTC data */
    s32 hour, min, sec;
    s32 date, month, year;
    s32 day;

    /* Variable for temperature */
    u32 temp;


    /* Read current RTC time */
    GetRTCTimeInfo(&hour, &min, &sec);


    /* Read current RTC date */
    GetRTCDateInfo(&date, &month, &year);


    /* Read current day */
    GetRTCDay(&day);


    /* Read temperature from LM35 */
    temp = Read_LM35_Temp();


    /**********************************************************
                    LINE 1 : TIME + TEMPERATURE

                   Example:
                   12:30:25 T:27°C
    **********************************************************/
    CmdLCD(GOTO_LINE1_POS0);


    /* Display time */
    DisplayRTCTime(hour, min, sec);


    /* Move cursor to temperature field */
    CmdLCD(GOTO_LINE1_POS0 + 9);


    /* Display temperature label */
    StrLCD("T:");


    /* Display temperature with leading zero
       if temperature is less than 10 */
    if(temp < 10)
    {
        CharLCD('0');

        CharLCD(temp + '0');
    }
    else
    {
        CharLCD((temp / 10) + '0');

        CharLCD((temp % 10) + '0');
    }


    /* Display degree symbol and C */
    CharLCD(0xDF);

    CharLCD('C');



    /**********************************************************
                     LINE 2 : DATE + DAY

                    Example:
                    03/05/2026 WED
    **********************************************************/
    CmdLCD(GOTO_LINE2_POS0);


    /* Display date */
    DisplayRTCDate(date, month, year);


    /* Move cursor to day field */
    CmdLCD(GOTO_LINE2_POS0 + 11);


    /* Display day */
    DisplayRTCDay(day);
}
