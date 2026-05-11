/*--------------------------------------------------------------
File Name   : DEVICE_SETTINGS.C
Description : Handles keypad-based numeric input,
              input validation, and menu navigation
--------------------------------------------------------------*/

#include "kpm.h"
#include "lcd.h"
#include "delay.h"
#include "type.h"
#include "lcd_defines.h"


/*--------------------------------------------------------------
Function Name : get_number_from_keypad()
Description   : Reads 1-digit or 2-digit numeric input
                from keypad.

Keys Used:
0–9 ? Number entry
B   ? Backspace
S   ? Confirm

Return        : Entered numeric value
--------------------------------------------------------------*/
u32 get_number_from_keypad(void)
{
    char buf[3] = {0,0,0};   /* Buffer for 2-digit input */
    char key;
    u32 value = 0;
    int pos = 0;


    /* Move cursor to second line */
    CmdLCD(GOTO_LINE2_POS0);


    while(1)
    {
        /* Scan keypad */
        key = KeyScan();

        /* Key debounce delay */
        delay_ms(120);


        /* Check if key is numeric */
        if(key >= '0' && key <= '9')
        {
            /* Allow maximum 2 digits */
            if(pos < 2)
            {
                /* Store digit */
                buf[pos] = key;

                /* Display digit on LCD */
                CmdLCD(GOTO_LINE2_POS0 + pos);
                CharLCD(key);

                pos++;
            }
        }


        /* Backspace operation */
        else if(key == 'B')
        {
            if(pos > 0)
            {
                pos--;

                /* Remove previous digit */
                buf[pos] = '\0';

                /* Clear LCD character */
                CmdLCD(GOTO_LINE2_POS0 + pos);
                CharLCD(' ');

                /* Move cursor back */
                CmdLCD(GOTO_LINE2_POS0 + pos);
            }
        }


        /* Confirm entered value */
        else if(key == 'S')
        {
            /* Single digit */
            if(pos == 1)
            {
                value = buf[0] - '0';

                return value;
            }

            /* Two digits */
            else if(pos == 2)
            {
                value = ((buf[0]-'0') * 10) +
                         (buf[1]-'0');

                return value;
            }
        }
    }
}



/*--------------------------------------------------------------
Function Name : get_hour_from_user()
Description   : Gets valid hour input from user.

Valid Range   : 0–23

Return        : Valid hour value
--------------------------------------------------------------*/
u32 get_hour_from_user(void)
{
    u32 h;


    while(1)
    {
        /* Display prompt */
        CmdLCD(CLEAR_LCD);
        delay_ms(300);

        StrLCD("Enter Hour 0-23");


        /* Read user input */
        h = get_number_from_keypad();


        /* Validate input */
        if(h <= 23)
            return h;


        /* Invalid input message */
        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Hour!");

        delay_ms(1000);
    }
}



/*--------------------------------------------------------------
Function Name : get_min_from_user()
Description   : Gets valid minute input from user.

Valid Range   : 0–59

Return        : Valid minute value
--------------------------------------------------------------*/
u32 get_min_from_user(void)
{
    u32 m;


    while(1)
    {
        /* Display prompt */
        CmdLCD(CLEAR_LCD);
        delay_ms(300);

        StrLCD("Enter Min 0-59");


        /* Read user input */
        m = get_number_from_keypad();


        /* Validate input */
        if(m <= 59)
            return m;


        /* Invalid input message */
        CmdLCD(CLEAR_LCD);

        StrLCD("Invalid Minute!");

        delay_ms(800);
    }
}



/*--------------------------------------------------------------
Function Name : select_time_edit_option()
Description   : Displays scrollable menu for
                time editing options.

Keys Used:
U ? Move Up
D ? Move Down
S ? Select

Return        : Selected menu index
--------------------------------------------------------------*/
u32 select_time_edit_option(void)
{
    /* Menu options */
    char opt[][16] =
    {
        "1.HOUR",
        "2.MINUTE",
        "3.HOUR+MIN",
        "4.EXIT"
    };

    u32 s = 0;

    char key;


    while(1)
    {
        /* Display current menu option */
        CmdLCD(CLEAR_LCD);

        StrLCD(opt[s]);

        delay_ms(200);


        /* Read keypad input */
        key = KeyScan();


        /* Move up */
        if(key == 'U')
        {
            if(s == 0)
                s = 3;
            else
                s--;
        }


        /* Move down */
        else if(key == 'D')
        {
            if(s == 3)
                s = 0;
            else
                s++;
        }


        /* Select option */
        else if(key == 'S')
        {
            return s;
        }
    }
}