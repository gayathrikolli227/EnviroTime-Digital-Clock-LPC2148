/*--------------------------------------------------------------
File Name   : DELAY.H
Description : Header file for software delay module.
              Contains function declarations for
              microsecond, millisecond, and
              second delay generation.
--------------------------------------------------------------*/

#ifndef __DELAY_H__
#define __DELAY_H__

#include "type.h"



/*--------------------------------------------------------------
Function Name : delay_us()

Description:
Generates delay in microseconds.
--------------------------------------------------------------*/
void delay_us(u32);



/*--------------------------------------------------------------
Function Name : delay_ms()

Description:
Generates delay in milliseconds.
--------------------------------------------------------------*/
void delay_ms(u32);



/*--------------------------------------------------------------
Function Name : delay_s()

Description:
Generates delay in seconds.
--------------------------------------------------------------*/
void delay_s(u32);



#endif
