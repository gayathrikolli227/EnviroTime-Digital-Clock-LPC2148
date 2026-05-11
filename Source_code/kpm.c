/*--------------------------------------------------------------
File Name   : KPM.C
Description : Implements 4x4 matrix keypad interfacing
              for key detection and scanning
--------------------------------------------------------------*/

#include "kpm_defines.h"
#include "type.h"
#include <lpc21xx.h>
#include "delay.h"


/*--------------------------------------------------------------
Keypad Layout

     C0   C1   C2   C3
R0   7    8    9    U
R1   4    5    6    D
R2   1    2    3    C
R3   B    0    S    A

U ? Up
D ? Down
S ? Select
B ? Backspace
--------------------------------------------------------------*/
u32 kpmLUT[4][4]=
{
    {'7','8','9','U'},
    {'4','5','6','D'},
    {'1','2','3','C'},
    {'B','0','S','A'}
};



/*--------------------------------------------------------------
Function Name : Init_kpm()
Description   : Initializes keypad GPIO pins.

Rows    ? Output
Columns ? Input
--------------------------------------------------------------*/
void Init_kpm(void)
{
    /* Configure row pins as output */
    IODIR1 |= (15 << ROW0);


    /* Configure column pins as input */
    IODIR1 &= ~(15 << COL0);


    /* Make all rows LOW initially */
    IOCLR1 = (15 << ROW0);
}



/*--------------------------------------------------------------
Function Name : ColScan()
Description   : Checks whether any key is pressed.

Return:
0 ? Key pressed
1 ? No key pressed
--------------------------------------------------------------*/
u32 ColScan(void)
{
    /* Column lines become LOW when key is pressed */
    if(((IOPIN1 >> COL0) & 15) < 15)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



/*--------------------------------------------------------------
Function Name : RowCheck()
Description   : Identifies which row contains
                the pressed key.

Return:
Row number (0–3)
--------------------------------------------------------------*/
u32 RowCheck(void)
{
    u32 r;


    for(r = 0; r < 4; r++)
    {
        /* Set all rows HIGH */
        IOSET1 = (15 << ROW0);


        /* Make current row LOW */
        IOCLR1 = (1 << (ROW0 + r));


        /* Small settling delay */
        delay_ms(1);


        /* Check for key press */
        if(ColScan() == 0)
            break;
    }


    /* Reset all rows LOW */
    IOCLR1 = (15 << ROW0);


    return r;
}



/*--------------------------------------------------------------
Function Name : ColCheck()
Description   : Identifies which column contains
                the pressed key.

Return:
Column number (0–3)
--------------------------------------------------------------*/
u32 ColCheck(void)
{
    u32 c;


    for(c = 0; c < 4; c++)
    {
        /* Pressed column becomes LOW */
        if(((IOPIN1 >> (COL0 + c)) & 1) == 0)
            break;
    }


    return c;
}



/*--------------------------------------------------------------
Function Name : KeyScan()
Description   : Scans keypad, detects row and
                column, and returns corresponding key.

Includes:
- Key press detection
- Debouncing
- Key release detection

Return:
Pressed key character
--------------------------------------------------------------*/
u32 KeyScan(void)
{
    u32 r, c, key;


    /* Initialize keypad */
    Init_kpm();


    /* Wait until key is pressed */
    while(ColScan());


    /* Debounce delay */
    delay_ms(20);


    /* Identify row */
    r = RowCheck();


    /* Identify column */
    c = ColCheck();


    /* Fetch corresponding key */
    key = kpmLUT[r][c];


    /* Wait until key is released */
    while(ColScan() == 0);


    /* Release debounce */
    delay_ms(20);


    /* Return detected key */
    return key;
}
