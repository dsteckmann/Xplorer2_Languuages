/*******************************************************************
 *
 *    DESCRIPTION: Screens.c
 *
 * 
 * 
 *    Notes: The number in the first argument when forming a LCDSTRING
 *           indicates the column location of the first letter to be displayed.
 *           A special case '10' is used to center the string on the LCD.
 *           The 'displine' function in LCD.c recognizes a lineloc argument
 *           of '10' as a special case and calculates the correct spacing
 *           to center the line.
 *
 *******************************************************************/

/** include files **/
#include "Globals.h"

#define CONST_LCDSTRING const LCDSTRING
#define CONST_LCDSTRING_PTR CONST_LCDSTRING * const
/* --------------------------------------------------------------------- */
/************************* Reuseable Lines *******************************/
/* --------------------------------------------------------------------- */


CONST_LCDSTRING  Blank[2]  =  {{ 0, "                    " },{ 0, "                    "} };   

//<ESC> to Exit
CONST_LCDSTRING  mESC_to_Exit[2]        =  {{ 10, "<ESC> to Exit"     }, { 10, "<ESC> para Salir"}      };       

//Press YES or NO
CONST_LCDSTRING  mPress_YES_or_NO[2]    =  {{ 10, "Press YES or NO"   }, { 10, "Presione SI/YES o NO"}  };

// <ENTER to Accept
CONST_LCDSTRING  mEnter_to_Accept[2]    =  {{ 10, "<ENTER> to Accept" }, { 10, "ENTER para Aceptar"}    };

//<YES> to Accept
CONST_LCDSTRING mYES_to_Accept[2]       =  {{ 10, "<YES> to Accept"    }, { 10, "YES/Si para Aceptar"}       };

//UP/DOWN for Next
CONST_LCDSTRING Up_Down_Next[2]        =  {{ 10, "UP/DOWN for Next" },  { 10, "Arriba/Abajo"}          };


//UP/DOWN to CHANGE
CONST_LCDSTRING Up_Down_Change[2]        =  {{ 10, "UP/DOWN to Change" },  { 10, "Arriba/Abajo"}          };

//Select #, ESC Exit
CONST_LCDSTRING SelectNumber[2]        =  {{ 10, "Select #, ESC Exit" },{ 10, "Sel #,ESC para Salir"}  };

//
//
//UP/DOWN for Next
//Select #, ESC Exit
CONST_LCDSTRING_PTR s_up_down_select_text[4]    = { &Blank[0],&Blank[0],&Up_Down_Next[0],&SelectNumber[0] };

// <ENTER> to Select
CONST_LCDSTRING Enter_to_Select[2]    =  {{ 10, "<ENTER> to Select" }, { 10, "<ENTER> a Escoger"}      };

//
//  UP/DOWN to Change
//  <YES> to Accept
//  <ESC> Exit
CONST_LCDSTRING_PTR s_Up_Down_Change_Exit[4]    = { Blank,Up_Down_Change,mYES_to_Accept,mESC_to_Exit };

//
//<ENTER> to Select
//  UP/DOWN for Next 
//  <ESC> Exit
CONST_LCDSTRING_PTR s_up_down_Enter_select_text[4]    = { &Blank[0],&Enter_to_Select[0],&Up_Down_Next[0],&mESC_to_Exit[0] };


//Calibration Due!
//Last Calibration On
//
//<ESC> to Exit
CONST_LCDSTRING calib_due[2]           = {{ 10, "Calibration Due!" },    { 10, "Require Calibracion"} };
CONST_LCDSTRING last_calibration[2]    = {{ 10, "Last Calibration On" }, { 10, "Ultima cal. hecha en"}};
CONST_LCDSTRING_PTR s_Calibration_due[4]    = { &calib_due[0],&last_calibration[0],&Blank[0],mESC_to_Exit };

//GAUGE READY  
CONST_LCDSTRING mGaugeReady[2]          = {{ 10, "GAUGE READY" },    { 10, "PREPARADO"} };


// display for the main menu
//1. Recall
//2. Offset 
//3. Auto Scroll
//4. Backlight
//5. Stat Test
//6. Drift Test
//7. GPS
//8. Autp Depth
//9. Review STD cnts.
//10. Select Language
//11. Set Units
//13. Serial Number
//14. Date/Time
//15. Buzzer/Alarm
//16. Special Cal.
//17. Nomograph
//18. Cal. Constants
//19. Soil Air Voids
//20. Diagnostic Test
CONST_LCDSTRING M1  = {0,"1. Recall           "};
CONST_LCDSTRING M2  = {0,"2. Offset           "};
CONST_LCDSTRING M3  = {0,"3. Auto Scroll      "};
CONST_LCDSTRING M4  = {0,"4. Backlight        "};
CONST_LCDSTRING M5  = {0,"5. Stat Test        "};
CONST_LCDSTRING M6  = {0,"6. Drift Test       "};
CONST_LCDSTRING M7  = {0,"7. GPS              "};
CONST_LCDSTRING M8  = {0,"8. Autp Depth       "};
CONST_LCDSTRING M9  = {0,"9. Review STD cnts. "};
CONST_LCDSTRING MP10 = {0,"10. Select Language "};
CONST_LCDSTRING MP11 = {0,"11. Set Units       "};
CONST_LCDSTRING MP12 = {0,"12. Standard Mode   "};
CONST_LCDSTRING MP13 = {0,"13. Serial Number   "};
CONST_LCDSTRING MP14 = {0,"14. Date/Time       "};
CONST_LCDSTRING MP15 = {0,"15. Buzzer/Alarm    "};
CONST_LCDSTRING MP16 = {0,"16. Special Cal.    "};
CONST_LCDSTRING MP17 = {0,"17. Nomograph       "};
CONST_LCDSTRING MP18 = {0,"18. Cal. Constants  "};
CONST_LCDSTRING MP19 = {0,"19. Soil Air Voids  "};
CONST_LCDSTRING MP20 = {0,"20. Diagnostic Test "};
CONST_LCDSTRING_PTR s_MenuNum [20] = {&M1,&M2,&M3,&M4,&M5,&M6,&M7,&M8,&M9,&MP10,&MP11,&MP12,&MP13,&MP14,&MP15,&MP16,&MP17,&MP18,&MP19,&MP20};

//CONST_LCDSTRING C0  = {0,"0."};
//CONST_LCDSTRING_PTR s_CalIDMenuNum [20] = {&C0, &M1,&M2,&M3,&M4,&M5,&M6,&M7,&M8,&M9,&MP0,&MP1,&MP2,&MP3,&MP4,&MP5,&MP6,&MP7,&MP8,&MP9 };


//"Incorrect BLE"
//"Module Firmware"
//"The MyGauge App"
//"may not work!"
CONST_LCDSTRING  mIncorrectBLE_1  = {10,"Incorrect BLE"};
CONST_LCDSTRING  mIncorrectBLE_2  = {10,"Module Firmware"};
CONST_LCDSTRING  mIncorrectBLE_3  = {10,"The MyGauge App"};
CONST_LCDSTRING  mIncorrectBLE_4  = {10,"may not work!"};
CONST_LCDSTRING_PTR s_IncorrectBLE[4] = { &mIncorrectBLE_1,&mIncorrectBLE_2,&mIncorrectBLE_3,&mIncorrectBLE_4 };      

//Count Time
CONST_LCDSTRING mCountTime[] = {{0,"Count Time:"}, {0,"    Tiempo:"}};

