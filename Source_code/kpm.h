/*--------------------------------------------------------------
File Name   : KPM.H
Description : Header file for 4x4 matrix keypad
              module. Contains function declarations
              for keypad initialization,
              row/column scanning,
              and key detection.
--------------------------------------------------------------*/

#ifndef _KPM_H_
#define _KPM_H_

#include "type.h"



/*--------------------------------------------------------------
Function Name : Init_kpm()

Description:
Initializes keypad GPIO pins.
Rows are configured as outputs,
columns as inputs.
--------------------------------------------------------------*/
void Init_kpm(void);



/*--------------------------------------------------------------
Function Name : ColScan()

Description:
Checks whether any key is pressed.

Return:
0 ? Key pressed
1 ? No key pressed
--------------------------------------------------------------*/
u32 ColScan(void);



/*--------------------------------------------------------------
Function Name : RowCheck()

Description:
Identifies row of pressed key.

Return:
Row number (0–3)
--------------------------------------------------------------*/
u32 RowCheck(void);



/*--------------------------------------------------------------
Function Name : ColCheck()

Description:
Identifies column of pressed key.

Return:
Column number (0–3)
--------------------------------------------------------------*/
u32 ColCheck(void);



/*--------------------------------------------------------------
Function Name : KeyScan()

Description:
Scans keypad and returns
pressed key value.

Return:
ASCII value of pressed key
--------------------------------------------------------------*/
u32 KeyScan(void);



#endif
