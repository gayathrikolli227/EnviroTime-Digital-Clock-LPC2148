/*--------------------------------------------------------------
File Name   : LM35.H
Description : Header file for LM35 temperature
              sensor module. Contains function
              declaration for reading temperature
              in degree Celsius.
--------------------------------------------------------------*/

#ifndef __LM35_H__
#define __LM35_H__

#include "type.h"



/*--------------------------------------------------------------
Function Name : Read_LM35_Temp()

Description:
Reads analog voltage from LM35 sensor
through ADC and converts it into
temperature in degree Celsius.

Return:
Temperature value in °C
--------------------------------------------------------------*/
u32 Read_LM35_Temp(void);



#endif
