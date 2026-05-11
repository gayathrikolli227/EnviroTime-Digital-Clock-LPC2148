/*--------------------------------------------------------------
File Name   : INIT_SYSTEM.C
Description : Initializes all peripherals used in EnviroTime
              project such as LCD, RTC, Keypad, ADC,
              switches, and buzzer
--------------------------------------------------------------*/

#include <lpc21xx.h>

#include "Intial.h"
#include "lcd.h"
#include "rtc.h"
#include "kpm.h"
#include "adc.h"


/* GPIO pin definitions */
#define BUZZER_PIN      25
#define EDIT_SW         0
#define ALARM_STOP_SW   1


/* Initial RTC values declared globally in main.c */
extern u32 h,mi,s,d,mo,y,da;


/*--------------------------------------------------------------
Function Name : Init_system()
Description   : Initializes system peripherals and sets
                default RTC time/date/day values
--------------------------------------------------------------*/
void Init_system(void)
{
    /* Configure all Port0 pins as GPIO */
    PINSEL0 = 0;

    /* Configure all Port1 pins as GPIO */
    PINSEL1 = 0;


    /* Initialize LCD module */
    Init_LCD();

    /* Initialize RTC module */
    Init_RTC();

    /* Initialize keypad module */
    Init_kpm();

    /* Initialize ADC module for LM35 temperature sensor */
    Init_ADC();


    /******** GPIO DIRECTIONS ********/

    /* Configure buzzer pin P0.25 as output */
    IODIR0 |= (1 << BUZZER_PIN);

    /* Keep buzzer OFF initially */
    IOCLR0 = (1 << BUZZER_PIN);


    /* Configure edit switch P0.0 as input */
    IODIR0 &= ~(1 << EDIT_SW);

    /* Configure alarm stop switch P0.1 as input */
    IODIR0 &= ~(1 << ALARM_STOP_SW);


    /* Set initial RTC time */
    SetRTCTimeInfo(h,mi,s);

    /* Set initial RTC date */
    SetRTCDateInfo(da,mo,y);

    /* Set initial RTC day */
    SetRTCDay(d);
}
