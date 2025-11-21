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

#define CONST_LCDSTRING const LCDSTRING
#define CONST_LCDSTRING_PTR CONST_LCDSTRING * const  
  
#define LANGUAGES 2   
  
/* This structure is used for defining 'screens' for the LCD */
typedef struct sLCDSTRING
{
	const uint8_t lineloc;                      // Location of initial character on line
	char * linestring;                        // LCDSTRING const * const s_calWaitingToFoamC [4]Pointer to string
}  LCDSTRING;
  
#define CONST_LCDSTRING const LCDSTRING
#define CONST_LCDSTRING_PTR CONST_LCDSTRING * const  

extern CONST_LCDSTRING M1[];  
extern CONST_LCDSTRING M2[];  
extern CONST_LCDSTRING M3[];  
extern CONST_LCDSTRING M4[];  
extern CONST_LCDSTRING M5[];  
extern CONST_LCDSTRING M6[];  
extern CONST_LCDSTRING M7[];  
extern CONST_LCDSTRING M8[];  
extern CONST_LCDSTRING M9[];  
extern CONST_LCDSTRING MP10[];
extern CONST_LCDSTRING MP11[];
extern CONST_LCDSTRING MP12[];
extern CONST_LCDSTRING MP13[];
extern CONST_LCDSTRING MP14[];
extern CONST_LCDSTRING MP15[];
extern CONST_LCDSTRING MP16[];
extern CONST_LCDSTRING MP17[];
extern CONST_LCDSTRING MP18[];
extern CONST_LCDSTRING MP19[];
extern CONST_LCDSTRING MP20[];


extern CONST_LCDSTRING  mESC_to_Exit[];
extern CONST_LCDSTRING_PTR sESCToExit[]  ;

extern CONST_LCDSTRING_PTR s_Calibration_due[] ;
extern CONST_LCDSTRING mGaugeReady[] ;
extern CONST_LCDSTRING mCountTime[];
extern CONST_LCDSTRING_PTR s_Up_Down_Change_Exit[]; 
extern CONST_LCDSTRING_PTR s_IncorrectBLE[];
extern CONST_LCDSTRING_PTR s_HighVoltageTest[]  ;
extern CONST_LCDSTRING KeyPadTest[];
extern CONST_LCDSTRING TubeTest[] ;
extern CONST_LCDSTRING_PTR s_SelfTestPassedTest[] ;
extern CONST_LCDSTRING DepthSafe[];
extern CONST_LCDSTRING DepthBS[] ;
extern CONST_LCDSTRING DepthNone[];
extern CONST_LCDSTRING Depth[] ;
extern CONST_LCDSTRING KeypadFAIL[];
extern CONST_LCDSTRING KeypadPass[];
extern CONST_LCDSTRING TempFAIL[] ;
extern CONST_LCDSTRING TempPass[];
extern CONST_LCDSTRING m_PressStartToTest[] ;
extern CONST_LCDSTRING m_RechargeBattery[]  ;
extern CONST_LCDSTRING m_ReadingNumber[]  ;
extern CONST_LCDSTRING m_FAIL[] ;
extern CONST_LCDSTRING m_PASS[];
extern CONST_LCDSTRING m_TakeNewStdCont[];
extern CONST_LCDSTRING  mPress_YES_or_NO[];
extern CONST_LCDSTRING m_UseNewStdCont[] ;
extern CONST_LCDSTRING_PTR s_PlaceGaugeOnStdBLock[ ] ;
extern CONST_LCDSTRING_PTR s_DepthNotInSafePos[ ];
extern CONST_LCDSTRING mStandardCount[];
extern CONST_LCDSTRING Up_Down_Next[];
extern CONST_LCDSTRING SelectNumber[] ;
extern CONST_LCDSTRING_PTR s_printMenuDisplay[ ];
extern CONST_LCDSTRING_PTR s_writeUSB_text[ ];
extern CONST_LCDSTRING_PTR s_insertExternalUSB_text[ ] ;
extern CONST_LCDSTRING_PTR s_writingDataUSB_text[ ];
extern CONST_LCDSTRING_PTR s_noUSBDeviceDetected[ ];
extern CONST_LCDSTRING_PTR s_DataDownloadComplete[ ];
extern CONST_LCDSTRING_PTR snoProjectsStored[ ];

#endif



