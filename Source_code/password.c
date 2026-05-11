/*--------------------------------------------------------------
File Name   : PASSWORD.C
Description : Implements password authentication
              for secure access to edit mode.
              Supports password masking and
              backspace correction.
--------------------------------------------------------------*/

#include "lcd.h"
#include "type.h"
#include "lcd_defines.h"
#include "kpm.h"
#include "delay.h"
#include <string.h>


/* Password length */
#define PASSWORD_LENGTH 4


/* Default system password */
s8 default_password[PASSWORD_LENGTH+1] = "1234";



/*--------------------------------------------------------------
Function Name : password()
Description   : Reads password from keypad,
                masks entered characters,
                compares with stored password,
                and returns access status.

Keys Used:
0-9 ? Password entry
B   ? Backspace

Return:
1 ? Password correct
0 ? Password incorrect
--------------------------------------------------------------*/
u32 password(void)
{
    /* Buffer to store entered password */
    s8 entered[PASSWORD_LENGTH+1];

    /* Keypad input */
    s8 key;


    /* Character index */
    u32 i = 0;


    /* Display password prompt */
    CmdLCD(CLEAR_LCD);

    delay_ms(2);

    CmdLCD(GOTO_LINE1_POS0);

    StrLCD("Enter Password:");

    delay_ms(100);


    /* Clear second LCD line */
    clear_line2();

    CmdLCD(GOTO_LINE2_POS0);



    /************************************************
                 PASSWORD ENTRY
    ************************************************/
    while(i < PASSWORD_LENGTH)
    {
        /* Read keypad input */
        key = KeyScan();



        /********************************************
                    BACKSPACE
        ********************************************/
        if(key == 'B')
        {
            if(i > 0)
            {
                /* Move back one position */
                i--;


                /* Remove last character */
                entered[i] = '\0';


                /* Move cursor back */
                CmdLCD(GOTO_LINE2_POS0 + i);


                /* Clear masked character */
                CharLCD(' ');


                /* Place cursor again */
                CmdLCD(GOTO_LINE2_POS0 + i);
            }
        }



        /********************************************
                    NORMAL KEY ENTRY
        ********************************************/
        else
        {
            /* Store entered key */
            entered[i] = key;


            /* Show actual key briefly */
            CharLCD(entered[i]);

            delay_ms(150);


            /* Replace character with * */
            CmdLCD(GOTO_LINE2_POS0 + i);

            CharLCD('*');


            /* Move to next position */
            i++;
        }


        /* Debounce delay */
        delay_ms(300);
    }


    /* Add string terminator */
    entered[i] = '\0';



    /************************************************
                PASSWORD VALIDATION
    ************************************************/
    if(strcmp(entered, default_password) == 0)
    {
        /* Password correct */
        CmdLCD(CLEAR_LCD);

        delay_ms(2);

        StrLCD("ACCEPTED");

        delay_ms(1000);


        CmdLCD(CLEAR_LCD);

        delay_ms(2);


        return 1;
    }
    else
    {
        /* Password incorrect */
        CmdLCD(CLEAR_LCD);

        delay_ms(2);

        StrLCD("Invalid password");

        delay_ms(1000);


        CmdLCD(CLEAR_LCD);

        delay_ms(2);


        return 0;
    }
}
