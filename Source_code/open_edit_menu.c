/*--------------------------------------------------------------
File Name   : OPEN_EDIT_MENU.C
Description : Displays main edit menu and allows
              user to navigate through menu options
              using keypad keys.
--------------------------------------------------------------*/

#include <string.h>

#include "lcd.h"
#include "type.h"
#include "lcd_defines.h"
#include "delay.h"
#include "kpm.h"


/*--------------------------------------------------------------
Main Edit Menu Options

1. EDIT RTC
2. SET ALARM
3. UPDATE PIN
4. EXIT

Navigation Keys:

U ? Move Up
D ? Move Down
S ? Select
--------------------------------------------------------------*/
char menu[4][16]=
{
    "1.EDIT RTC",
    "2.SET ALARM",
    "3.UPDATE PIN",
    "4.EXIT"
};



/*--------------------------------------------------------------
Function Name : open_edit_menu()
Description   : Displays scrollable edit menu and
                returns selected menu option.

Keys Used:
U ? Move Up
D ? Move Down
S ? Select

Return:
0 ? EDIT RTC
1 ? SET ALARM
2 ? UPDATE PIN
3 ? EXIT
--------------------------------------------------------------*/
u32 open_edit_menu(void)
{
    /* Current selected menu index */
    u32 index = 0;

    char key;


    while(1)
    {
        /* Clear LCD */
        CmdLCD(CLEAR_LCD);


        /* Display current menu option */
        StrLCD(menu[index]);


        /* Read keypad input */
        key = KeyScan();


        /**********************************************
                     Move Up
        **********************************************/
        if(key == 'U')
        {
            /* Wrap around from first to last */
            if(index == 0)
                index = 3;
            else
                index--;
        }


        /**********************************************
                     Move Down
        **********************************************/
        else if(key == 'D')
        {
            /* Wrap around from last to first */
            if(index == 3)
                index = 0;
            else
                index++;
        }


        /**********************************************
                     Select Option
        **********************************************/
        else if(key == 'S')
        {
            /* Return selected menu index */
            return index;
        }
    }
}
