/*--------------------------------------------------------------
File Name   : DELAY.C
Description : Provides software delay functions in
              microseconds, milliseconds, and seconds
--------------------------------------------------------------*/

#include "type.h"
#include "delay.h"


/*--------------------------------------------------------------
Function Name : delay_ms()
Description   : Generates delay in milliseconds

Formula:
1 ms ˜ 12000 loops (for 12 MHz clock)

Parameter:
DLYMS ? delay value in milliseconds
--------------------------------------------------------------*/
void delay_ms(u32 DLYMS)
{
    /* Generate millisecond delay */
    for(DLYMS *= 12000; DLYMS > 0; DLYMS--);
}



/*--------------------------------------------------------------
Function Name : delay_us()
Description   : Generates delay in microseconds

Formula:
1 us ˜ 12 loops (for 12 MHz clock)

Parameter:
DLYUS ? delay value in microseconds
--------------------------------------------------------------*/
void delay_us(u32 DLYUS)
{
    /* Generate microsecond delay */
    for(DLYUS *= 12; DLYUS > 0; DLYUS--);
}



/*--------------------------------------------------------------
Function Name : delay_s()
Description   : Generates delay in seconds

Formula:
1 second ˜ 12,000,000 loops (for 12 MHz clock)

Parameter:
DLYS ? delay value in seconds
--------------------------------------------------------------*/
void delay_s(u32 DLYS)
{
    /* Generate second delay */
    for(DLYS *= 12000000; DLYS > 0; DLYS--);
}