/*--------------------------------------------------------------
File Name   : LCD.C
Description : Implements 16x2 LCD interfacing in 8-bit mode
              using LPC2148 GPIO pins
--------------------------------------------------------------*/

#include <lpc21xx.h>

#include "type.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "delay.h"


/*--------------------------------------------------------------
Function Name : WriteLCD()
Description   : Sends one byte of data/command to LCD.
                RS decides whether byte is command or data.

Parameter     : byte ? command/data byte
--------------------------------------------------------------*/
void WriteLCD(u8 byte)
{
    /* RW = 0, LCD write mode */
    IOCLR0 = (1 << LCD_RW);


    /* Clear LCD data pins */
    IOCLR0 = (0xFF << LCD_DATA);


    /* Send byte to LCD data pins */
    IOSET0 = (byte << LCD_DATA);


    /* Generate Enable pulse */
    IOSET0 = (1 << LCD_EN);

    delay_us(1);

    IOCLR0 = (1 << LCD_EN);


    /* Wait for LCD processing */
    delay_ms(2);
}


/*--------------------------------------------------------------
Function Name : CmdLCD()
Description   : Sends command byte to LCD.

Parameter     : CmdByte ? LCD command
--------------------------------------------------------------*/
void CmdLCD(u8 CmdByte)
{
    /* RS = 0 for command */
    IOCLR0 = (1 << LCD_RS);


    /* Send command to LCD */
    WriteLCD(CmdByte);
}


/*--------------------------------------------------------------
Function Name : Init_LCD()
Description   : Initializes 16x2 LCD in 8-bit mode
--------------------------------------------------------------*/
void Init_LCD(void)
{
    /* Configure LCD data pins as output */
    IODIR0 |= (0xFF << LCD_DATA);


    /* Configure LCD control pins as output */
    IODIR0 |= (1 << LCD_RS);

    IODIR0 |= (1 << LCD_RW);

    IODIR0 |= (1 << LCD_EN);


    /* LCD power-on delay */
    delay_ms(15);


    /* LCD initialization sequence */
    CmdLCD(MODE_8BIT_1LINE);

    delay_us(4100);

    CmdLCD(MODE_8BIT_1LINE);

    delay_us(100);

    CmdLCD(MODE_8BIT_1LINE);


    /* Configure LCD as 8-bit, 2-line mode */
    CmdLCD(MODE_8BIT_2LINE);


    /* Display ON, cursor OFF */
    CmdLCD(DISP_ON_CUR_OFF);


    /* Clear LCD display */
    CmdLCD(CLEAR_LCD);


    /* Cursor moves right after each character */
    CmdLCD(SHIFT_CUR_RIGHT);
}


/*--------------------------------------------------------------
Function Name : CharLCD()
Description   : Displays a single character on LCD.

Parameter     : asciiVal ? character to display
--------------------------------------------------------------*/
void CharLCD(u8 asciiVal)
{
    /* RS = 1 for data */
    IOSET0 = (1 << LCD_RS);


    /* Send character to LCD */
    WriteLCD(asciiVal);
}


/*--------------------------------------------------------------
Function Name : StrLCD()
Description   : Displays a string on LCD.

Parameter     : p ? pointer to string
--------------------------------------------------------------*/
void StrLCD(s8 *p)
{
    /* Display characters until NULL character */
    while(*p)
    {
        CharLCD(*p++);
    }
}


/*--------------------------------------------------------------
Function Name : U32LCD()
Description   : Displays unsigned integer on LCD.

Parameter     : n ? unsigned integer value
--------------------------------------------------------------*/
void U32LCD(u32 n)
{
    u8 digit[10];

    s32 i = 0;


    /* If number is zero */
    if(n == 0)
    {
        CharLCD('0');
    }
    else
    {
        /* Extract digits in reverse order */
        while(n > 0)
        {
            digit[i++] = (n % 10) + '0';

            n = n / 10;
        }


        /* Display digits in correct order */
        for(--i; i >= 0; i--)
        {
            CharLCD(digit[i]);
        }
    }
}


/*--------------------------------------------------------------
Function Name : S32LCD()
Description   : Displays signed integer on LCD.

Parameter     : n ? signed integer value
--------------------------------------------------------------*/
void S32LCD(s32 n)
{
    /* Display negative sign if number is negative */
    if(n < 0)
    {
        CharLCD('-');

        n = -n;
    }


    /* Display absolute value */
    U32LCD(n);
}


/*--------------------------------------------------------------
Function Name : F32LCD()
Description   : Displays floating point number on LCD.

Parameters:
fn  ? float value
nop ? number of decimal places
--------------------------------------------------------------*/
void F32LCD(f32 fn, u32 nop)
{
    u32 n, i;


    /* Display negative sign if value is negative */
    if(fn < 0.0)
    {
        CharLCD('-');

        fn = -fn;
    }


    /* Integer part */
    n = fn;

    U32LCD(n);


    /* Decimal point */
    CharLCD('.');


    /* Fractional part */
    for(i = 0; i < nop; i++)
    {
        fn = (fn - n) * 10;

        n = fn;

        CharLCD(n + '0');
    }
}


/*--------------------------------------------------------------
Function Name : BuildCGRAM()
Description   : Builds custom characters in LCD CGRAM.

Parameters:
p      ? pointer to custom character pattern array
nBytes ? number of bytes to write
--------------------------------------------------------------*/
void BuildCGRAM(u8 *p, u8 nBytes)
{
    u32 i;


    /* Move LCD address to CGRAM start */
    CmdLCD(GOTO_CGRAM_START);


    /* RS = 1 for CGRAM data */
    IOSET0 = (1 << LCD_RS);


    /* Write custom character bytes */
    for(i = 0; i < nBytes; i++)
    {
        WriteLCD(p[i]);
    }


    /* Return cursor to first line */
    CmdLCD(GOTO_LINE1_POS0);
}


/*--------------------------------------------------------------
Function Name : clear_line2()
Description   : Clears second line of LCD and places cursor
                back at start of line 2
--------------------------------------------------------------*/
void clear_line2(void)
{
    /* Move cursor to line 2 */
    CmdLCD(GOTO_LINE2_POS0);


    /* Clear 16 characters of line 2 */
    StrLCD("                ");


    /* Move cursor back to line 2 start */
    CmdLCD(GOTO_LINE2_POS0);
}