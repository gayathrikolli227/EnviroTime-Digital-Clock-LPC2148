/*--------------------------------------------------------------
File Name   : LCD.H
Description : Header file for 16x2 LCD module.
              Contains function declarations for
              LCD initialization, command writing,
              character/string display, numeric
              display, and custom character creation.
--------------------------------------------------------------*/

#ifndef _LCD_H_
#define _LCD_H_

#include "type.h"



/*--------------------------------------------------------------
LCD Initialization
--------------------------------------------------------------*/
void Init_LCD(void);



/*--------------------------------------------------------------
LCD Command/Data Functions
--------------------------------------------------------------*/
void CmdLCD(u8 CmdByte);

void CharLCD(u8 asciiVal);

void WriteLCD(u8 byte);



/*--------------------------------------------------------------
Numeric Display Functions
--------------------------------------------------------------*/
void U32LCD(u32);

void S32LCD(s32);

void F32LCD(f32, u32);



/*--------------------------------------------------------------
String Display Function
--------------------------------------------------------------*/
void StrLCD(s8 *);



/*--------------------------------------------------------------
Custom Character Function
--------------------------------------------------------------*/
void BuildCGRAM(u8 *, u8);



/*--------------------------------------------------------------
Utility Functions
--------------------------------------------------------------*/
void clear_line2(void);



#endif
