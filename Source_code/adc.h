/*--------------------------------------------------------------
File Name   : ADC.H
Description : Header file for ADC module.
              Contains function prototypes
              for ADC initialization and
              ADC data acquisition.
--------------------------------------------------------------*/

#ifndef __ADC_H__
#define __ADC_H__

#include "type.h"


/*--------------------------------------------------------------
Function Name : Init_ADC()

Description:
Initializes LPC2148 ADC peripheral
for analog sensor interfacing.
--------------------------------------------------------------*/
void Init_ADC(void);



/*--------------------------------------------------------------
Function Name : Read_ADC()

Description:
Starts ADC conversion and returns
10-bit digital ADC value.

Return:
ADC result (0–1023)
--------------------------------------------------------------*/
u32 Read_ADC(void);


#endif
