/*--------------------------------------------------------------
File Name   : MAIN_PROJ.C
Description : Main application file for EnviroTime project.
              It initializes the system, displays RTC and
              temperature data, checks password-protected
              edit mode, handles wrong password lockout,
              and controls alarm stop operation.
--------------------------------------------------------------*/

#include <lpc21xx.h>

#include "type.h"
#include "kpm.h"
#include "lcd.h"
#include "rtc.h"
#include "lcd_defines.h"
#include "kpm_defines.h"
#include "Intial.h"
#include "delay.h"
#include "adc.h"
#include "lm35.h"


/* GPIO pin definitions */
#define BUZZER_PIN      25
#define EDIT_SW         0
#define ALARM_STOP_SW   1


/* Default password declared in password module */
extern s8 default_password[5];


/* Initial RTC time */
u32 h  = 12;
u32 mi = 30;
u32 s  = 0;


/* Initial RTC date/day */
u32 d  = 3;
u32 mo = 5;
u32 y  = 2026;
u32 da = 1;


/* Initial alarm time */
u32 alarm_hour = 12;
u32 alarm_min  = 31;


/* Security and alarm flags */
u32 wrong_count = 0;
u32 alarm_flag  = 0;


/*--------------------------------------------------------------
Function Name : main()
Description   : Main program execution starts here.
                Continuously displays RTC and temperature,
                checks alarm condition, and handles user input.
--------------------------------------------------------------*/
int main()
{
    /* Initialize LCD, RTC, ADC, keypad, switches and buzzer */
    Init_system();


    /* Configure P0.25 as GPIO output for buzzer / LED */
    PINSEL1 &= ~(3 << 18);

    IODIR0 |= (1 << BUZZER_PIN);


    /* Display startup message */
    CmdLCD(CLEAR_LCD);

    StrLCD("ENVIRO TIME");

    CmdLCD(GOTO_LINE2_POS0);

    StrLCD("CLOCK & TEMP");


    /* Show startup message for 1.5 seconds */
    delay_ms(1500);

    CmdLCD(CLEAR_LCD);


    /* Infinite loop */
    while(1)
    {
        /* Display time, date, day and temperature */
        display_envirotime();


        /* Check whether current time matches alarm time */
        check_alarm();



        /********************************************************
                         EDIT SWITCH CHECK
          Edit switch is active LOW.
          When pressed, password verification is performed.
        ********************************************************/
        if(((IOPIN0 >> EDIT_SW) & 1) == 0)
        {
            /* Debounce delay */
            delay_ms(50);


            /* Confirm switch press */
            if(((IOPIN0 >> EDIT_SW) & 1) == 0)
            {
                /* Wait until switch is released */
                while(((IOPIN0 >> EDIT_SW) & 1) == 0);



                /************************************************
                          WRONG PASSWORD LOCKOUT
                  If wrong password is entered 3 times,
                  system locks for 45 seconds.
                ************************************************/
                if(wrong_count >= 3)
                {
                    u32 sec_count, beep;


                    /* Buzzer beeps 3 times */
                    for(beep = 0; beep < 3; beep++)
                    {
                        IOSET0 = (1 << BUZZER_PIN);

                        delay_ms(200);


                        IOCLR0 = (1 << BUZZER_PIN);

                        delay_ms(200);
                    }


                    /* Display system locked message */
                    CmdLCD(CLEAR_LCD);

                    delay_ms(5);

                    CmdLCD(GOTO_LINE1_POS0);

                    StrLCD("SYSTEM LOCKED");


                    /* Display countdown timer */
                    for(sec_count = 45; sec_count > 0; sec_count--)
                    {
                        CmdLCD(GOTO_LINE2_POS0);

                        StrLCD("WAIT: ");


                        /* Display two digit countdown */
                        CharLCD((sec_count / 10) + '0');

                        CharLCD((sec_count % 10) + '0');


                        StrLCD(" SEC   ");


                        delay_ms(1000);
                    }


                    /* Reset wrong password count */
                    wrong_count = 0;


                    CmdLCD(CLEAR_LCD);

                    delay_ms(5);


                    continue;
                }



                /************************************************
                         PASSWORD VERIFICATION
                ************************************************/
                if(password())
                {
                    /* If password is correct, reset wrong count */
                    wrong_count = 0;


                    /* Open edit menu */
                    process_edit_menu();
                }
                else
                {
                    /* Increment wrong password count */
                    wrong_count++;


                    /* Display access denied message */
                    CmdLCD(CLEAR_LCD);

                    StrLCD("ACCESS DENIED");

                    delay_ms(500);


                    /* Buzzer alert for wrong password */
                    IOSET0 = (1 << BUZZER_PIN);

                    delay_ms(1000);

                    IOCLR0 = (1 << BUZZER_PIN);


                    CmdLCD(CLEAR_LCD);

                    delay_ms(5);
                }
            }
        }



        /********************************************************
                      ALARM STOP SWITCH CHECK
          Alarm stop switch is active LOW.
          If alarm is active and stop switch is pressed,
          buzzer is turned OFF.
        ********************************************************/
        if(alarm_flag == 1 &&
           (((IOPIN0 >> ALARM_STOP_SW) & 1) == 0))
        {
            /* Turn OFF buzzer */
            IOCLR0 = (1 << BUZZER_PIN);


            /* Clear alarm active flag */
            alarm_flag = 0;


            /* Wait until stop switch is released */
            while(((IOPIN0 >> ALARM_STOP_SW) & 1) == 0);
        }


        /* Small delay before next loop execution */
        delay_ms(200);
    }
}
