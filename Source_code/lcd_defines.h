/*--------------------------------------------------------------
File Name   : LCD_DEFINES.H
Description : Contains GPIO pin definitions and
              HD44780 LCD command definitions
              used in EnviroTime project.
--------------------------------------------------------------*/

#ifndef _LCD_DEFINES_H_
#define _LCD_DEFINES_H_



/*--------------------------------------------------------------
LCD GPIO Pin Connections

LCD Data Pins : P0.8  to P0.15
RS            : P0.16
RW            : P0.17
EN            : P0.18
--------------------------------------------------------------*/
#define LCD_DATA   8

#define LCD_RS     16

#define LCD_RW     17

#define LCD_EN     18



/*--------------------------------------------------------------
HD44780 LCD Commands
--------------------------------------------------------------*/

/* Clear display */
#define CLEAR_LCD          0x01


/* Return cursor to home position */
#define RET_CUR_HOME       0x02


/* Cursor movement */
#define SHIFT_CUR_RIGHT    0x06

#define SHIFT_CUR_LEFT     0x07


/* Display control */
#define DISP_OFF           0x08

#define DISP_ON_CUR_OFF    0x0C

#define DISP_ON_CUR_ON     0x0E

#define DISP_ON_CUR_BLINK  0x0F


/* Display shift */
#define SHIFT_DISP_LEFT    0x10

#define SHIFT_DISP_RIGHT   0x14


/* Interface mode */
#define MODE_8BIT_1LINE    0x30

#define MODE_4BIT_1LINE    0x20

#define MODE_8BIT_2LINE    0x38

#define MODE_4BIT_2LINE    0x28



/*--------------------------------------------------------------
LCD Cursor Position Commands
--------------------------------------------------------------*/
#define GOTO_LINE1_POS0    0x80

#define GOTO_LINE2_POS0    0xC0

#define GOTO_LINE3_POS0    0x94

#define GOTO_LINE4_POS0    0xD4



/*--------------------------------------------------------------
CGRAM Address for custom characters
--------------------------------------------------------------*/
#define GOTO_CGRAM_START   0x40



#endif
