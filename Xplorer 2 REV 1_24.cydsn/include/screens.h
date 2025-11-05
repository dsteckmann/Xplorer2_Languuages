/*
 * File: Screens.h
 * Desc: This file contains all the menus and displays for code
 *       residing in constant ROM.  This file should be included
 *       by any file that references these structures.
 *
 * NOTE! Any LCDSTRING which never gets modified by code should be
 *      defined as "const" so it gets placed into ROM and not into
 *      the initialized data area (RAM).						
 *      Any LCDSTRING which must be modified by code somewhere can
 *      be defined without "const", and it will wind up in the
 *      initialized data area, available to be modified.	
 *															
 *
 */
#ifndef SCREENSH
#define SCREENSH  	

#include <project.h>
  
#define LANGUAGES 2   
  
/* This structure is used for defining 'screens' for the LCD */
typedef struct sLCDSTRING
{
	const uint8_t lineloc;                      // Location of initial character on line
	char * linestring;                        // LCDSTRING const * const s_calWaitingToFoamC [4]Pointer to string
}  LCDSTRING;
  
#define CONST_LCDSTRING const LCDSTRING
#define CONST_LCDSTRING_PTR CONST_LCDSTRING * const  

extern CONST_LCDSTRING  mESC_to_Exit[];
extern CONST_LCDSTRING_PTR sESCToExit[]  ;

extern CONST_LCDSTRING_PTR s_Calibration_due[] ;
extern CONST_LCDSTRING mGaugeReady[] ;
extern CONST_LCDSTRING mCountTime[];
extern CONST_LCDSTRING_PTR s_Up_Down_Change_Exit[]; 
extern CONST_LCDSTRING_PTR s_IncorrectBLE[];

#endif



