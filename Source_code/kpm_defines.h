/*--------------------------------------------------------------
File Name   : KPM_DEFINES.H
Description : Contains GPIO pin definitions
              for 4x4 matrix keypad interfacing
              with LPC2148.
--------------------------------------------------------------*/

#ifndef _KPM_DEFINES_H_
#define _KPM_DEFINES_H_



/*--------------------------------------------------------------
Keypad Row Connections

Rows are configured as OUTPUT pins
--------------------------------------------------------------*/
#define ROW0   16      /* P1.16 */

#define ROW1   17      /* P1.17 */

#define ROW2   18      /* P1.18 */

#define ROW3   19      /* P1.19 */



/*--------------------------------------------------------------
Keypad Column Connections

Columns are configured as INPUT pins
--------------------------------------------------------------*/
#define COL0   20      /* P1.20 */

#define COL1   21      /* P1.21 */

#define COL2   22      /* P1.22 */

#define COL3   23      /* P1.23 */



#endif
