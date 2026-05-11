/*--------------------------------------------------------------
File Name   : PROCESS_EDIT_MENU.C
Description : Processes selected option from
              main edit menu and calls
              corresponding feature modules.
--------------------------------------------------------------*/

#include "Intial.h"


/* Default password declared in PASSWORD.C */
extern s8 default_password[5];



/*--------------------------------------------------------------
Function Name : process_edit_menu()
Description   : Opens main edit menu, reads user
                selection, and executes the
                corresponding operation.

Menu Options:

0 ? Edit RTC
1 ? Set Alarm
2 ? Update PIN
3 ? Exit
--------------------------------------------------------------*/
void process_edit_menu(void)
{
    /* Selected menu option */
    u32 select;


    while(1)
    {
        /* Open edit menu and get user selection */
        select = open_edit_menu();


        /* Exit option selected */
        if(select == 3)
            return;



        /* Process selected menu */
        switch(select)
        {
            /****************************************
                      EDIT RTC
            ****************************************/
            case 0:

                edit_rtc_settings();

                break;



            /****************************************
                      SET ALARM
            ****************************************/
            case 1:

                alarm_time_setting();

                break;



            /****************************************
                      UPDATE PASSWORD
            ****************************************/
            case 2:

                update_password(default_password);

                break;
        }
    }
}
