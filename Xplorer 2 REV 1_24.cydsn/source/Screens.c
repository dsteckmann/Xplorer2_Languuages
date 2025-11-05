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

//CONST_LCDSTRING_PTR sESCToExit[4]    = { &mESC_to_Exit[0],&mESC_to_Exit[0],&mESC_to_Exit[0],&mESC_to_Exit[0] };
//CONST_LCDSTRING Enter_to_Accept    = { 10, "<ENTER> to Accept" };   // <ENTER> to Accept
//CONST_LCDSTRING YES_to_Accept      = { 10, "<YES> to Accept" };  
//CONST_LCDSTRING up_down_select_text = { 10, " UP/DOWN for Next" };   
//CONST_LCDSTRING ENTER_select_text   = { 10, "<ENTER> to Select" };   // <ENTER> to Accept
//CONST_LCDSTRING UpDownforNext       = { 10, " UP/DOWN for Next" }; 

CONST_LCDSTRING  Blank[2]  =  {  // <ESC> to Exit
                                  { 0, "                    " },
                                  { 0, "                    "} 
                              };   


CONST_LCDSTRING  ESC_to_Exit[2]  =  {  // <ESC> to Exit
                                        { 10, "<ESC> to Exit" },
                                        { 10, "<ESC> para Salir"} 
                                     };       

CONST_LCDSTRING  Press_YES_or_NO[2]  =  {  // <ESC> to Exit
                                           { 10, "Press YES or NO" },
                                           { 10, "Presione SI/YES o NO"} 
                                        };

CONST_LCDSTRING Enter_to_Accept[2]    = {  // <ENTER> to Accept
                                           { 10, "<ENTER> to Accept" },
                                           { 10, "ENTER para Aceptar"} 
                                         };


CONST_LCDSTRING YES_to_Accept[2]  = {  // YES to Accept
                                      { 10, "<YES to Accept" },
                                      { 10, "SI para Aceptar"} 
                                    };


CONST_LCDSTRING Up_Down_Next[2] =  {  // UP/DOWN for Next
                                      { 10, "UP/DOWN for Next" },
                                      { 10, "Arriba/Abajo"} 
                                    };

CONST_LCDSTRING SelectNumber[2] =  {  // Select #, ESC Exit
                                      { 10, "Select #, ESC Exit" },
                                      { 10, "Sel #,ESC para Salir"} 
                                    };

CONST_LCDSTRING_PTR up_down_select_text[4]    = { &Blank[0],&Blank[0],&Up_Down_Next[0],&SelectNumber[0] };


CONST_LCDSTRING Enter_to_Select[2]    = {  // <ENTER> to Select
                                           { 10, "<ENTER> to Select" },
                                           { 10, "<ENTER> a Escoger"} 
                                        };

//<ENTER> to Select
//  UP/DOWN for Next 
//  <ESC> Exit
CONST_LCDSTRING_PTR up_down_Enter_select_text[4]    = { &Blank[0],&Enter_to_Select[0],&Up_Down_Next[0],&ESC_to_Exit[0] };


//Calibration Due!
//Last Calibration On
//
//
CONST_LCDSTRING calib_due[2]    = {  // Calibration Due!
                                           { 10, "Calibration Due!" },
                                           { 10, "Require Calibracion"} 
                                        };

CONST_LCDSTRING last_calibration[2]    = {  //Last Calibration On
                                           { 10, "Last Calibration On" },
                                           { 10, "Ultima cal. hecha en"} 
                                         };

CONST_LCDSTRING_PTR calibration_due[4]    = { &calib_due[0],&last_calibration[0],&Blank[0],&Blank[0] };

  

// display for the main menu
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

