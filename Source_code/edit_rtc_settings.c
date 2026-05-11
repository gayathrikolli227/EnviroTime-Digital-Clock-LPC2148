/*--------------------------------------------------------------
File Name   : EDIT_RTC_SETTINGS.C
Description : Handles RTC parameter editing such as
              hour, minute, second, day, date,
              month, and year using keypad input
--------------------------------------------------------------*/

#include "type.h"
#include "delay.h"
#include "lcd.h"
#include "Intial.h"
#include "rtc.h"
#include "kpm.h"
#include "lcd_defines.h"


/* Current RTC parameters */
extern u32 h,mi,s,d,mo,y,da;


/*--------------------------------------------------------------
Function Name : edit_rtc_settings()
Description   : Opens RTC edit menu, allows user
                to modify RTC parameters, and
                updates RTC registers after saving
--------------------------------------------------------------*/
void edit_rtc_settings(void)
{
    u32 choice;

    while(1)
    {
        /* Display RTC edit menu */
        choice = rtc_edit_menu();


        /* Exit option selected */
        if(choice == 7)
        {
            /* Wait for key release */
            while(ColScan()==0);

            delay_ms(150);


            /* Update RTC registers */
            SetRTCTimeInfo(h,mi,s);

            SetRTCDateInfo(da,mo,y);

            SetRTCDay(d);


            /* Confirmation message */
            CmdLCD(CLEAR_LCD);

            StrLCD("RTC UPDATED");

            delay_ms(600);

            CmdLCD(CLEAR_LCD);


            /* Return to main screen */
            display_envirotime();

            delay_ms(800);

            return;
        }


        /* Process selected option */
        switch(choice)
        {
            case 0: set_rtc_hour(&h);      break;

            case 1: set_rtc_minute(&mi);   break;

            case 2: set_rtc_second(&s);    break;

            case 3: set_rtc_day(&d);       break;

            case 4: set_rtc_date(&da);     break;

            case 5: set_rtc_month(&mo);    break;

            case 6: set_rtc_year(&y);      break;
        }
    }
}



/*--------------------------------------------------------------
Function Name : rtc_edit_menu()
Description   : Displays scrollable RTC edit menu.

Keys Used:
U ? Move Up
D ? Move Down
S ? Select

Return        : Selected menu option
--------------------------------------------------------------*/
u32 rtc_edit_menu(void)
{
    char menu[][15]=
    {
        "1.HOUR",
        "2.Minute",
        "3.Second",
        "4.Day",
        "5.Date",
        "6.Month",
        "7.Year",
        "8.Exit"
    };

    u32 selected = 0;

    char key;


    while(1)
    {
        CmdLCD(CLEAR_LCD);

        StrLCD(menu[selected]);

        delay_ms(200);


        key = KeyScan();


        /* Move up */
        if(key == 'U')
        {
            if(selected == 0)
                selected = 7;
            else
                selected--;
        }


        /* Move down */
        else if(key == 'D')
        {
            if(selected == 7)
                selected = 0;
            else
                selected++;
        }


        /* Select option */
        else if(key == 'S')
        {
            return selected;
        }
    }
}



/*--------------------------------------------------------------
Function Name : set_rtc_hour()
Description   : Gets valid hour input.

Valid Range   : 0–23
--------------------------------------------------------------*/
void set_rtc_hour(u32 *h)
{
    u32 temp;


    while(1)
    {
        CmdLCD(CLEAR_LCD);

        delay_ms(500);

        StrLCD("Enter Hour 0-23");


        temp = get_number_from_keypad();


        if(temp <= 23)
        {
            *h = temp;

            CmdLCD(CLEAR_LCD);

            StrLCD("HOUR UPDATED");

            delay_ms(600);

            return;
        }


        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Hour!");

        delay_ms(600);
    }
}



/*--------------------------------------------------------------
Function Name : set_rtc_minute()
Description   : Gets valid minute input.

Valid Range   : 0–59
--------------------------------------------------------------*/
void set_rtc_minute(u32 *mi)
{
    u32 temp;


    while(1)
    {
        CmdLCD(CLEAR_LCD);

        delay_ms(500);

        StrLCD("Enter Min 0-59");


        temp = get_number_from_keypad();


        if(temp <= 59)
        {
            *mi = temp;

            CmdLCD(CLEAR_LCD);

            StrLCD("MIN UPDATED");

            delay_ms(600);

            return;
        }


        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Minute!");

        delay_ms(600);
    }
}



/*--------------------------------------------------------------
Function Name : set_rtc_second()
Description   : Gets valid second input.

Valid Range   : 0–59
--------------------------------------------------------------*/
void set_rtc_second(u32 *s)
{
    u32 temp;


    while(1)
    {
        CmdLCD(CLEAR_LCD);

        delay_ms(500);

        StrLCD("Enter Sec 0-59");


        temp = get_number_from_keypad();


        if(temp <= 59)
        {
            *s = temp;

            CmdLCD(CLEAR_LCD);

            StrLCD("SEC UPDATED");

            delay_ms(600);

            return;
        }


        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Second!");

        delay_ms(600);
    }
}



/*--------------------------------------------------------------
Function Name : set_rtc_day()
Description   : Gets valid day input.

0 = Sunday
1 = Monday
2 = Tuesday
3 = Wednesday
4 = Thursday
5 = Friday
6 = Saturday
--------------------------------------------------------------*/
void set_rtc_day(u32 *d)
{
    u32 temp;


    while(1)
    {
        CmdLCD(CLEAR_LCD);

        delay_ms(500);

        StrLCD("Day 0-6:");


        temp = get_number_from_keypad();


        if(temp <= 6)
        {
            *d = temp;

            CmdLCD(CLEAR_LCD);

            StrLCD("DAY UPDATED");

            delay_ms(600);

            return;
        }


        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Day!");

        delay_ms(600);
    }
}



/*--------------------------------------------------------------
Function Name : set_rtc_year()
Description   : Gets valid 4-digit year.

Valid Range   : 2000–2099

Keys:
B ? Backspace
S ? Confirm
--------------------------------------------------------------*/
void set_rtc_year(u32 *y)
{
    char yr[5];

    u32 index;

    u32 temp;

    char key;

    int i;


    while(1)
    {
        CmdLCD(CLEAR_LCD);

        delay_ms(200);

        StrLCD("YEAR 2000-2099");


        index = 0;


        for(i = 0; i < 5; i++)
            yr[i] = 0;


        CmdLCD(GOTO_LINE2_POS0);


        while(1)
        {
            key = KeyScan();


            if(key == 0)
                continue;


            if(key >= '0' && key <= '9')
            {
                if(index < 4)
                {
                    yr[index] = key;

                    CharLCD(key);

                    index++;
                }
            }


            else if(key == 'B')
            {
                if(index > 0)
                {
                    index--;

                    yr[index] = 0;

                    CmdLCD(GOTO_LINE2_POS0 + index);

                    CharLCD(' ');

                    CmdLCD(GOTO_LINE2_POS0 + index);
                }
            }


            else if(key == 'S')
            {
                if(index == 4)
                    break;
            }


            delay_ms(150);
        }


        temp =
        (yr[0]-'0')*1000 +
        (yr[1]-'0')*100 +
        (yr[2]-'0')*10 +
        (yr[3]-'0');


        if(temp >= 2000 && temp <= 2099)
        {
            *y = temp;

            CmdLCD(CLEAR_LCD);

            StrLCD("YEAR UPDATED");

            delay_ms(600);

            return;
        }


        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Year!");

        delay_ms(700);
    }
}



/*--------------------------------------------------------------
Function Name : set_rtc_month()
Description   : Gets valid month input.

Valid Range   : 1–12
--------------------------------------------------------------*/
void set_rtc_month(u32 *mo)
{
    u32 temp;


    while(1)
    {
        CmdLCD(CLEAR_LCD);

        delay_ms(500);

        StrLCD("Month 1-12:");


        temp = get_number_from_keypad();


        if(temp >= 1 && temp <= 12)
        {
            *mo = temp;

            CmdLCD(CLEAR_LCD);

            StrLCD("MONTH UPDATED");

            delay_ms(500);

            return;
        }


        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Month!");

        delay_ms(500);
    }
}



/*--------------------------------------------------------------
Function Name : days_in_month()
Description   : Returns total days in month.

Supports leap year.
--------------------------------------------------------------*/
u32 days_in_month(u32 month, u32 year)
{
    switch(month)
    {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:

            return 31;


        case 4: case 6:
        case 9: case 11:

            return 30;


        case 2:

            if((year % 4 == 0 && year % 100 != 0) ||
               (year % 400 == 0))
                return 29;
            else
                return 28;


        default:

            return 31;
    }
}



/*--------------------------------------------------------------
Function Name : set_rtc_date()
Description   : Gets valid date input based on
                selected month and year.

Supports leap year validation.
--------------------------------------------------------------*/
void set_rtc_date(u32 *da)
{
    u32 tmp;

    u32 max_days;


    while(1)
    {
        CmdLCD(CLEAR_LCD);

        delay_ms(500);

        StrLCD("Enter Date 1-31");


        tmp = get_number_from_keypad();


        max_days = days_in_month(mo, y);


        if(tmp >= 1 && tmp <= max_days)
        {
            *da = tmp;

            CmdLCD(CLEAR_LCD);

            StrLCD("DATE UPDATED");

            delay_ms(600);

            return;
        }


        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Date!");

        delay_ms(600);
    }
}
