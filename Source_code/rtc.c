/*--------------------------------------------------------------
File Name   : RTC.C
Description : Implements Real Time Clock (RTC)
              initialization, time/date/day setting,
              reading, and LCD display functions
              for LPC2148
--------------------------------------------------------------*/

#include <lpc21xx.h>

#include "lcd.h"
#include "lcd_defines.h"
#include "type.h"


/*--------------------------------------------------------------
RTC Clock Configuration

FOSC = Crystal frequency = 12 MHz
CCLK = CPU clock = 60 MHz
PCLK = Peripheral clock = 15 MHz
--------------------------------------------------------------*/
#define FOSC 12000000

#define CCLK (5 * FOSC)

#define PCLK (CCLK / 4)



/*--------------------------------------------------------------
RTC Prescaler Calculation

RTC requires 32768 Hz clock.

PREINT  = Integer divider
PREFRAC = Fractional divider
--------------------------------------------------------------*/
#define PREINT_VAL  ((PCLK / 32768) - 1)

#define PREFRAC_VAL (PCLK - ((PREINT_VAL + 1) * 32768))



/* RTC Control Register bits */
#define RTC_ENABLE  (1 << 0)

#define RTC_RESET   (1 << 1)

#define RTC_CLKSRC  (1 << 4)



/* Day lookup table */
s8 week[][4] =
{
    "SUN",
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT"
};



/*--------------------------------------------------------------
Function Name : Init_RTC()
Description   : Initializes LPC2148 RTC module
                using PCLK as clock source
--------------------------------------------------------------*/
void Init_RTC(void)
{
    /* Load RTC prescaler values */
    PREINT = PREINT_VAL;

    PREFRAC = PREFRAC_VAL;


    /* Reset RTC */
    CCR = RTC_RESET;


    /* Release reset */
    CCR = 0x00;


    /* Enable RTC */
    CCR = RTC_ENABLE;
}



/*--------------------------------------------------------------
Function Name : SetRTCTimeInfo()
Description   : Sets RTC hour, minute and second.

Parameters:
hour ? 0–23
min  ? 0–59
sec  ? 0–59
--------------------------------------------------------------*/
void SetRTCTimeInfo(u32 hour, u32 min, u32 sec)
{
    HOUR = hour;

    MIN = min;

    SEC = sec;
}



/*--------------------------------------------------------------
Function Name : SetRTCDateInfo()
Description   : Sets RTC date, month and year.

Parameters:
date  ? 1–31
month ? 1–12
year  ? 2000+
--------------------------------------------------------------*/
void SetRTCDateInfo(u32 date, u32 month, u32 year)
{
    DOM = date;

    MONTH = month;

    YEAR = year;
}



/*--------------------------------------------------------------
Function Name : SetRTCDay()
Description   : Sets RTC day of week.

Values:
0 = Sunday
1 = Monday
...
6 = Saturday
--------------------------------------------------------------*/
void SetRTCDay(u32 day)
{
    DOW = day;
}



/*--------------------------------------------------------------
Function Name : GetRTCTimeInfo()
Description   : Reads current RTC time.

Parameters:
hour   ? pointer to hour
minute ? pointer to minute
second ? pointer to second
--------------------------------------------------------------*/
void GetRTCTimeInfo(s32 *hour,
                    s32 *minute,
                    s32 *second)
{
    *hour = HOUR;

    *minute = MIN;

    *second = SEC;
}



/*--------------------------------------------------------------
Function Name : GetRTCDateInfo()
Description   : Reads current RTC date.

Parameters:
date  ? pointer to date
month ? pointer to month
year  ? pointer to year
--------------------------------------------------------------*/
void GetRTCDateInfo(s32 *date,
                    s32 *month,
                    s32 *year)
{
    *date = DOM;

    *month = MONTH;

    *year = YEAR;
}



/*--------------------------------------------------------------
Function Name : GetRTCDay()
Description   : Reads current RTC day.

Parameter:
day ? pointer to day
--------------------------------------------------------------*/
void GetRTCDay(s32 *day)
{
    *day = DOW;
}



/*--------------------------------------------------------------
Function Name : DisplayRTCTime()
Description   : Displays time on LCD.

Format:
HH:MM:SS
--------------------------------------------------------------*/
void DisplayRTCTime(u32 hour,
                    u32 minute,
                    u32 second)
{
    /* Hour */
    CharLCD((hour / 10) + '0');

    CharLCD((hour % 10) + '0');

    CharLCD(':');


    /* Minute */
    CharLCD((minute / 10) + '0');

    CharLCD((minute % 10) + '0');

    CharLCD(':');


    /* Second */
    CharLCD((second / 10) + '0');

    CharLCD((second % 10) + '0');
}



/*--------------------------------------------------------------
Function Name : DisplayRTCDate()
Description   : Displays date on LCD.

Format:
DD/MM/YYYY
--------------------------------------------------------------*/
void DisplayRTCDate(u32 date,
                    u32 month,
                    u32 year)
{
    /* Date */
    CharLCD((date / 10) + '0');

    CharLCD((date % 10) + '0');

    CharLCD('/');


    /* Month */
    CharLCD((month / 10) + '0');

    CharLCD((month % 10) + '0');

    CharLCD('/');


    /* Year */
    U32LCD(year);
}



/*--------------------------------------------------------------
Function Name : DisplayRTCDay()
Description   : Displays day name on LCD.

Examples:
SUN, MON, TUE...
--------------------------------------------------------------*/
void DisplayRTCDay(u32 dow)
{
    /* Valid day */
    if(dow <= 6)
    {
        StrLCD(week[dow]);
    }
    else
    {
        /* Invalid day */
        StrLCD("ERR");
    }
}
