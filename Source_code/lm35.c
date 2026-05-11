/*--------------------------------------------------------------
File Name   : LM35.C
Description : Reads analog voltage from LM35 sensor
              through ADC and converts it into
              temperature in degree Celsius
--------------------------------------------------------------*/

#include "type.h"
#include "adc.h"


/*--------------------------------------------------------------
Function Name : Read_LM35_Temp()
Description   : Reads ADC value from LM35 sensor,
                converts ADC value to voltage,
                then converts voltage to temperature.

Formula Used:

Voltage = (ADC_Value × 3.3) / 1023

LM35 Output:
10 mV per °C

Temperature = Voltage × 100

Example:
0.25V ? 25°C

Return        : Temperature in °C
--------------------------------------------------------------*/
u32 Read_LM35_Temp(void)
{
    /* ADC digital value (0–1023) */
    u32 adc_val;


    /* Converted analog voltage */
    f32 voltage;


    /* Temperature in Celsius */
    u32 temp;


    /* Read ADC value from LM35 */
    adc_val = Read_ADC();


    /* Convert ADC value to voltage
       ADC reference voltage = 3.3V */
    voltage = (adc_val * 3.3) / 1023.0;


    /* Convert voltage to temperature
       LM35 gives 10mV per °C */
    temp = voltage * 100;


    /* Return temperature */
    return temp;
}
