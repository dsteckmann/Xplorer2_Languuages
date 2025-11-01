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
  
CONST_LCDSTRING NNReady      = { 10, "Gauge Ready" };    
CONST_LCDSTRING LowBattery   = { 10, "Low Battery" };    
CONST_LCDSTRING StartTest    = { 10,  "<Start> to Begin" };    
CONST_LCDSTRING Blank        = { 0,   ""                 };

CONST_LCDSTRING PressEnter   = { 10, "Press <ENTER>" };       // Press <ENTER>
CONST_LCDSTRING Enabled      = { 10, "ENABLED" };             // ENABLED
CONST_LCDSTRING Disabled     = { 10, "DISABLED" };            // DISABLED
CONST_LCDSTRING NumbOn       = { 0, "1. ON" };                // 1. ON
CONST_LCDSTRING NumbOff      = { 0, "2. OFF" };               // 2. OFF
CONST_LCDSTRING EscToAbort   = { 10, "<ESC> to Abort" };      // <ESC> to Abort

CONST_LCDSTRING PressNumb    = { 10, "Press # to Select" };   // Press # to Select		
CONST_LCDSTRING EnterToSel   = { 10, "<ENTER> to Select" };   // <ENTER> to Select
CONST_LCDSTRING EnterToCont  = { 10, "<ENTER> to Continue" }; // <ENTER> to Continue
CONST_LCDSTRING m_yesorNo    = { 10, "<YES> or <NO>" };        // <YES> or <NO>
CONST_LCDSTRING m_YesToChange  = { 10, "<YES> to Change" };      
CONST_LCDSTRING ExceedsLimit = { 10, "Exceeds Limits!" };
CONST_LCDSTRING ChangeValue  = { 10, "Change Value?" };
CONST_LCDSTRING EnterValueFor = { 0, "Enter Value for " };                   
CONST_LCDSTRING SelectESC     = { 0, "Select #, ESC Exit" };
//CONST_LCDSTRING EnterToAccept = { 10, "<ENTER> to Accept" };   // <ENTER> to Accept
CONST_LCDSTRING StopToExit    = { 10, "<STOP> to Exit" };      // <STOP> to Exit
CONST_LCDSTRING EnterorEsc    = { 10, "<ENTER> or <ESC>" };    // <Enter> or <ESC>
CONST_LCDSTRING YesToAccept   = { 10, "<YES> to Accept" };   
CONST_LCDSTRING NoToExit      = { 10, "<No> to Exit" };   

CONST_LCDSTRING StartEsc      = { 10, "<START> or <ESC>" };    // <Start> or <ESC>
CONST_LCDSTRING mProject      = { 0, "Project:" };   
CONST_LCDSTRING Selected      = { 10, "Selected" };  

CONST_LCDSTRING  mESC_to_Exit[2]       =  {  // <ESC> to Exit
                                        { 10, "<ESC> to Exit" },
                                        { 10, "<ESC> para Salir"} 
                                      };       

CONST_LCDSTRING  mPress_YES_or_NO[2]  =  {  // <ESC> to Exit
                                           { 10, "Press YES or NO" },
                                           { 10, "Presione SI/YES o NO"} 
                                         };




CONST_LCDSTRING_PTR sESCToExit[4]    = { &mESC_to_Exit[0],&mESC_to_Exit[0],&mESC_to_Exit[0],&mESC_to_Exit[0] };


//CONST_LCDSTRING Enter_to_Accept    = { 10, "<ENTER> to Accept" };   // <ENTER> to Accept
//CONST_LCDSTRING YES_to_Accept      = { 10, "<YES> to Accept" };  
//CONST_LCDSTRING up_down_select_text = { 10, " UP/DOWN for Next" };   
//CONST_LCDSTRING ENTER_select_text   = { 10, "<ENTER> to Select" };   // <ENTER> to Accept
//CONST_LCDSTRING UpDownforNext       = { 10, " UP/DOWN for Next" };   


CONST_LCDSTRING  SL1                     = { 2, "Arrows for Scroll" };
CONST_LCDSTRING  SL3                     = { 3, "Arrows for +/-" };
CONST_LCDSTRING_PTR s_scrollList [4]  = { &Blank, &Blank, &SL1, &EnterToSel };

CONST_LCDSTRING M1  = {0,"1."};
CONST_LCDSTRING M2  = {0,"2."};
CONST_LCDSTRING M3  = {0,"3."};
CONST_LCDSTRING M4  = {0,"4."};
CONST_LCDSTRING M5  = {0,"5."};
CONST_LCDSTRING M6  = {0,"6."};
CONST_LCDSTRING M7  = {0,"7."};
CONST_LCDSTRING M8  = {0,"8."};
CONST_LCDSTRING M9  = {0,"9."};
CONST_LCDSTRING MP0 = {0,"10."};
CONST_LCDSTRING MP1 = {0,"11."};
CONST_LCDSTRING MP2 = {0,"12."};
CONST_LCDSTRING MP3 = {0,"13."};
CONST_LCDSTRING MP4 = {0,"14."};
CONST_LCDSTRING MP5 = {0,"15."};
CONST_LCDSTRING MP6 = {0,"16."};
CONST_LCDSTRING MP7 = {0,"17."};
CONST_LCDSTRING MP8 = {0,"18."};
CONST_LCDSTRING MP9 = {0,"19."};
CONST_LCDSTRING_PTR s_MenuNum [19] = {&M1,&M2,&M3,&M4,&M5,&M6,&M7,&M8,&M9,&MP0,&MP1,&MP2,&MP3,&MP4,&MP5,&MP6,&MP7,&MP8,&MP9};

CONST_LCDSTRING C0  = {0,"0."};
CONST_LCDSTRING_PTR s_CalIDMenuNum [20] = {&C0, &M1,&M2,&M3,&M4,&M5,&M6,&M7,&M8,&M9,&MP0,&MP1,&MP2,&MP3,&MP4,&MP5,&MP6,&MP7,&MP8,&MP9 };

