/*--------------------------------------------------------------
File Name   : UPDATE_PASSWORD.C
Description : Allows user to change system password.
              User must enter old password,
              then enter and confirm new password.
              Supports backspace correction.
--------------------------------------------------------------*/

#include "lcd.h"
#include "type.h"
#include "lcd_defines.h"
#include "kpm.h"
#include "delay.h"
#include <string.h>
#include "Intial.h"


/* Password length */
#define PASSWORD_LENGTH 4


/* Global password declared in PASSWORD.C */
extern s8 default_password[PASSWORD_LENGTH+1];



/*--------------------------------------------------------------
Function Name : update_password()
Description   : Verifies old password and updates
                system password if new password
                matches confirmation password.

Parameters:
saved_pass ? pointer to current password
--------------------------------------------------------------*/
void update_password(s8 *saved_pass)
{
    /* Buffers for password storage */
    s8 old_entered[5];

    s8 new_password[5];

    s8 confirm_password[5];



    /************************************************
                STEP 1 : OLD PASSWORD
    ************************************************/
    CmdLCD(CLEAR_LCD);

    delay_ms(2);

    StrLCD("OLD PASSWORD");

    delay_ms(200);

    CmdLCD(GOTO_LINE2_POS0);


    /* Read old password */
    get_password_from_user(old_entered);



    /* Verify old password */
    if(strcmp(old_entered, saved_pass) != 0)
    {
        CmdLCD(CLEAR_LCD);

        delay_ms(2);

        StrLCD("WRONG PASSWORD");

        delay_ms(800);


        /* Exit without updating */
        return;
    }



    /************************************************
                STEP 2 : NEW PASSWORD
    ************************************************/
    CmdLCD(CLEAR_LCD);

    delay_ms(2);

    StrLCD("NEW PASSWORD");

    CmdLCD(GOTO_LINE2_POS0);


    /* Read new password */
    get_password_from_user(new_password);



    /************************************************
              STEP 3 : CONFIRM PASSWORD
    ************************************************/
    CmdLCD(CLEAR_LCD);

    delay_ms(2);

    StrLCD("CONFIRM PASSWORD");

    CmdLCD(GOTO_LINE2_POS0);


    /* Read confirmation password */
    get_password_from_user(confirm_password);



    /************************************************
                PASSWORD VALIDATION
    ************************************************/
    if(strcmp(new_password, confirm_password) == 0)
    {
        /* Update global password */
        strcpy(default_password, new_password);


        /* Success message */
        CmdLCD(CLEAR_LCD);

        StrLCD("PASSWORD UPDATED");

        delay_ms(800);


        CmdLCD(CLEAR_LCD);
    }
    else
    {
        /* Password mismatch */
        CmdLCD(CLEAR_LCD);

        StrLCD("PASSWORD MISMATCH");

        delay_ms(800);
    }
}



/*--------------------------------------------------------------
Function Name : get_password_from_user()
Description   : Reads 4-digit password from keypad.

Features:
0–9 ? Digit entry
B   ? Backspace
*   ? Password masking

Parameter:
buffer ? pointer to password buffer
--------------------------------------------------------------*/
void get_password_from_user(s8 *buffer)
{
    s8 key;

    u32 i = 0;


    /* Move cursor to second LCD line */
    CmdLCD(GOTO_LINE2_POS0);



    while(i < PASSWORD_LENGTH)
    {
        /* Read keypad input */
        key = KeyScan();



        /********************************************
                  NUMERIC INPUT
        ********************************************/
        if(key >= '0' && key <= '9')
        {
            /* Store entered digit */
            buffer[i] = key;


            /* Display * instead of actual digit */
            CharLCD('*');


            i++;
        }



        /********************************************
                    BACKSPACE
        ********************************************/
        else if(key == 'B')
        {
            if(i > 0)
            {
                /* Move back */
                i--;


                /* Remove previous digit */
                buffer[i] = '\0';


                /* Clear LCD character */
                CmdLCD(GOTO_LINE2_POS0 + i);

                CharLCD(' ');


                /* Position cursor again */
                CmdLCD(GOTO_LINE2_POS0 + i);
            }
        }


        /* Debounce delay */
        delay_ms(200);
    }


    /* String terminator */
    buffer[i] = '\0';
}
