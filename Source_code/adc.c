/*--------------------------------------------------------------
File Name   : ADC.C
Description : Initializes ADC module of LPC2148
              and reads analog data from
              LM35 temperature sensor
--------------------------------------------------------------*/

#include <lpc21xx.h>

#include "adc.h"


/*--------------------------------------------------------------
Function Name : Init_ADC()
Description   : Initializes ADC module of LPC2148
                to read analog data from
                LM35 sensor connected to AD0.1
--------------------------------------------------------------*/
void Init_ADC(void)
{
    /* Configure P0.28 as AD0.1 analog input */
    PINSEL1 |= (1 << 24);


    /* ADC Configuration:

       SEL    = Channel 1 (AD0.1)
       CLKDIV = 4
       PDN    = Power ON
    */
    ADCR =
        (1 << 1)  |     /* Select ADC channel 1 */
        (4 << 8)  |     /* ADC clock divider */
        (1 << 21);      /* Power ON ADC */
}



/*--------------------------------------------------------------
Function Name : Read_ADC()
Description   : Starts ADC conversion,
                waits until conversion completes,
                and returns 10-bit ADC result.

Return        : ADC result (0–1023)
--------------------------------------------------------------*/
u32 Read_ADC(void)
{
    /* Start ADC conversion */
    ADCR |= (1 << 24);


    /* Wait until conversion is complete
       DONE bit = bit31 */
    while(((ADDR >> 31) & 1) == 0);


    /* Extract ADC result from bits 15:6 */
    return ((ADDR >> 6) & 1023);
}
