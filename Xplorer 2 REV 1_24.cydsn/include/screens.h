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

#include "Globals.h" // for LCDSTRING

  
#define CONST_LCDSTRING const LCDSTRING
#define CONST_LCDSTRING_PTR CONST_LCDSTRING * const  
  
/* Reuseable Lines ********************************************/
extern LCDSTRING const NNReady;  
extern LCDSTRING const LowBattery;
extern LCDSTRING const StartTest ;  
extern LCDSTRING const * const s_scrollList [4];
extern LCDSTRING const * const s_MenuNum [19];

extern LCDSTRING const Blank;
extern LCDSTRING const EscToExit;
extern LCDSTRING const EnterToAccept;
extern LCDSTRING const ChangeValue;
extern LCDSTRING const m_yesorNo ;
extern LCDSTRING const EnterValueFor;
extern LCDSTRING const EnterToCont ;
extern LCDSTRING const EnterorEsc ;
extern LCDSTRING const YesToAccept ;
extern LCDSTRING const StartEsc   ;
extern LCDSTRING const SelectESC;

/* Startup Screens *********************************************/
extern LCDSTRING const * const s_Startup [4];
extern LCDSTRING const * const s_SelfTest [4];
extern LCDSTRING const * const s_TestingLCD [4];
extern LCDSTRING const * const s_Ready [4];

/* Time/Date Screens ********************************************/

// Special  *****************************************

extern LCDSTRING const reviewReviewESC1   ;

extern LCDSTRING const * const s_MainMenu [];
extern const int ClkScrnMenuLength;
extern const int mainlength;

extern LCDSTRING const * const s_CalibMenu [];
extern int const callength;

extern LCDSTRING const * const s_DiagMenu []; 
extern int const diaglength ;

extern LCDSTRING const * const s_StartInputError [4] ;
extern LCDSTRING const * const s_stackWarning[4];
extern LCDSTRING const * const s_EEPROMDATAError [4] ;


extern LCDSTRING const * const s_BeepTime [4] ;
extern LCDSTRING const * const s_BeepTimeMin [4];
extern LCDSTRING const mBeepTime;


extern LCDSTRING const * const s_dataStoreOn [4] ;
extern LCDSTRING const mDataOn;
extern LCDSTRING const * const s_dataStoreOff [4] ; 
extern LCDSTRING const mDataOff ;

extern LCDSTRING const * const s_FileName[4]   ;
extern LCDSTRING const * const s_currentFileName [4]  ;
extern LCDSTRING const  mcurrentFileName ;

extern LCDSTRING const * const s_currentCAPDAC [4];
extern LCDSTRING const * const s_EnterCapDac [4];
extern LCDSTRING const  mcurrentCapDAC ;

extern LCDSTRING const * const s_TestingOpening[4];
extern LCDSTRING const * const s_TestingPumpingDown[4];
extern LCDSTRING const  mTesting;

extern LCDSTRING const * s_SensorOffset [4] ;
extern LCDSTRING const * const s_EnterSOffset [4] ;
extern LCDSTRING const lSensOffset ;
extern LCDSTRING const * const s_fileNewID [4] ;

extern LCDSTRING const * const s_EnterSerialNumber [4];
extern LCDSTRING const * const s_SerialNumber [4]  ;
extern LCDSTRING const mSerialNumb  ;
extern LCDSTRING const * const s_TestingClosing[4];
extern LCDSTRING const * const s_StartInputError [4] ;
extern LCDSTRING const * s_EnterCurrentDate[4]; 
extern LCDSTRING const * const sEnterPresentTime[4];
extern LCDSTRING const * const sClockSetError[4] ;
extern LCDSTRING const * const sEnterTime[4];

extern LCDSTRING const * s_SlopeChange [4];
extern LCDSTRING const * const s_EnterSlope [4];
extern LCDSTRING const * const s_EnterInter [4];
extern LCDSTRING const * const s_EnterOffset [4];
extern LCDSTRING const * s_InterChange [4] ;


extern LCDSTRING const * const s_EnterStandard [4] ;
extern LCDSTRING const * s_StandardChange [4];
extern LCDSTRING const * const s_EnterLSLimit [4];
extern LCDSTRING const * const s_UpperHeight [4];
extern LCDSTRING const * const s_LowerHeight [4];

extern LCDSTRING const * const s_CalibMenu [];
extern int const callength;
extern LCDSTRING const CalID;
extern LCDSTRING const * const s_CalIDMenuNum [];
extern LCDSTRING const * const s_calEEpromFull[] ;
extern LCDSTRING const * const s_calEnterName[];
extern LCDSTRING const * const s_calNewID [];
extern LCDSTRING const * const s_EnterUnboiledLS [] ;
extern LCDSTRING const * const s_AC_Loss_Warning [];
extern LCDSTRING const * const s_EnterACLossWarning [];
extern LCDSTRING const mAC_Loss_Warning[];
extern LCDSTRING const * const s_confidenceInterval [];
extern LCDSTRING const * const s_selectConfidence [] ;
extern LCDSTRING const m_confidence[];
extern LCDSTRING const * const s_CalType [4];
extern LCDSTRING const * const s_UnboiledSample [];
extern LCDSTRING const * const s_WetAggSample [];
extern const LCDSTRING * const s_AccessCodeInput[];
extern const LCDSTRING * const s_AccessCodeError[];
extern LCDSTRING const * const s_changeMode2 [4] ;
extern LCDSTRING const * const s_changeMode1 [4] ;
extern LCDSTRING const m_mode2sides ;
extern LCDSTRING const m_mode1side  ; 

extern LCDSTRING const * const s_SDMenu [];
extern int const sdlength;

extern LCDSTRING const * const s_GPSOff [];
extern LCDSTRING const * const s_GPSOn [];
extern LCDSTRING const mGPSOff ;  
extern LCDSTRING const mGPSOn ;  
extern LCDSTRING const * const s_BatteryLowError[];
extern LCDSTRING const * const s_currentAirReading[];
extern LCDSTRING const * const s_PlaceOnStandard [];
extern LCDSTRING const * const s_PlaceOnReferenceStandard[];
extern LCDSTRING const * const s_LayGaugeOnSide[];
extern LCDSTRING const * const s_DACCalib [];
extern LCDSTRING const * const s_currentDACIntercept [];
extern LCDSTRING const * const s_EnterCapDacInter [];
extern LCDSTRING const * const s_currentCAPDACSlope[];
extern LCDSTRING const * const s_EnterCapDacSlope [];
extern LCDSTRING const  mcurrentDACSlope   ;
extern LCDSTRING const  mcurrentDACIntercept  ;
extern LCDSTRING const * const s_PlaceOnDACStandard [];
extern LCDSTRING const * const s_UnableToReadSensor [];
extern LCDSTRING const * const s_LEDOn [4];
extern LCDSTRING const * const s_LEDOff [4];
extern LCDSTRING const mLEDOff ;
extern LCDSTRING const mLEDOn;
extern LCDSTRING const * const s_EnterProjectName [4];
extern LCDSTRING const * const s_StationNameMode [4] ;
extern LCDSTRING const * const s_AutoStoreOff [4];
extern LCDSTRING const * const s_AutoStoreOn [4];
extern LCDSTRING const mAutoStoreOff ;
extern LCDSTRING const mAutoStoreOn  ;
extern LCDSTRING const * const s_LimitExceeded [4];
extern LCDSTRING const * const s_StationIncrBy1 [4] ;
extern LCDSTRING const * const s_UPDownEnterSelect [4];
extern LCDSTRING const * const s_DeleteData [4];
extern LCDSTRING const * const s_EnterToDeleteData [4];
extern LCDSTRING const * const s_EraseAllData [4];
extern LCDSTRING const * const s_EnterToDeleteProjectData [4];
extern LCDSTRING const * const s_EraseProjectData [4];
extern LCDSTRING const * const s_NoProjectSelected [4];
extern LCDSTRING const * const s_EnterStationName [4];
extern LCDSTRING const * const s_WriteDataUSB [4];
extern LCDSTRING const * const s_StartingStationNum [4] ;
extern LCDSTRING const * const s_SendDataToUSB [4] ;
extern LCDSTRING const * const s_StationLimitExceeded [4];
extern LCDSTRING const * const s_BuzzerOn [4];
extern LCDSTRING const * const s_BuzzerOff [4] ;
extern LCDSTRING const mBuzzerOff;
extern LCDSTRING const mBuzzerOn;
extern int const extendedTestlength;
extern LCDSTRING const * const s_extendedTestMenu []; 
extern LCDSTRING const * const s_currentTestNumber [4];
extern LCDSTRING const * const s_EnterTestNumber [4];
extern LCDSTRING const  mEnterTestNumber ;
extern LCDSTRING const * const s_currentTestTime [4];
extern LCDSTRING const * const s_EnterTestTime [4] ;
extern LCDSTRING const  mEnterTestTime ;

extern LCDSTRING const  mSingleMode ;                    
extern LCDSTRING const  mMultipleMode;
extern LCDSTRING const * const s_ReadingMode  [4];

extern LCDSTRING const * const s_EnterGmm [4];
extern LCDSTRING const * s_SlopeChange [4] ;
extern LCDSTRING const * const s_EnterAggSz [4];
extern LCDSTRING const * s_AggSzChange [4];
extern LCDSTRING const * const s_EnterOffset [4];
extern LCDSTRING const * s_OffsetChange [4];
extern LCDSTRING const m_Offset ;
extern LCDSTRING const m_AggSz;
extern LCDSTRING const m_Gmm;
extern LCDSTRING const CalID ;
extern LCDSTRING const * const s_calNewID [4];

extern LCDSTRING const * const s_FactMenu [];
extern int const factlength;

extern LCDSTRING const * s_InitPercentChange[4];
extern LCDSTRING const * const s_EnterPercentComp [4];

extern LCDSTRING const * const s_PercentCompModeOn [4] ;
extern LCDSTRING const * const s_PercentCompModeOff [4] ;
extern LCDSTRING const m_PercentCompModeOFF;
extern LCDSTRING const m_PercentCompModeON;

extern LCDSTRING const * const s_PlaceOnUncompacted [] ;
extern LCDSTRING const * s_CompactionDensity  [];
extern LCDSTRING const * s_CompactionDensityAccept  [];
extern LCDSTRING const * s_CompactionMenu [];
extern LCDSTRING const m_initialPercent;
extern LCDSTRING const * s_DensityOffset [];
extern LCDSTRING const * const s_OffsetON  [];
extern LCDSTRING const * const s_OffsetOFF  [];
extern LCDSTRING const m_OffsetON ;
extern LCDSTRING const m_OffsetOFF;
extern LCDSTRING const * s_m_densityOffset [];
extern LCDSTRING const * s_GMMChange [];
extern LCDSTRING const * const s_PercentMenu [];
extern int const percentlength;
extern LCDSTRING const * const s_PercentOff [];
extern LCDSTRING const mPercentOff;
extern LCDSTRING const * const s_PercentOn [];
extern LCDSTRING const mPercentOn; 

extern LCDSTRING const * const s_BTOn [];
extern LCDSTRING const mBTOn;
extern LCDSTRING const * const s_BTOff [];
extern LCDSTRING const mBTOff;

extern LCDSTRING const * const s_TempCompOn [];
extern LCDSTRING const mTempCompOn;

extern LCDSTRING const mTempCompOff ;
extern LCDSTRING const * const s_TempCompOff [];

extern LCDSTRING const * const s_readingNumber [];
extern LCDSTRING const * const s_EnterReadingNumber[];
extern LCDSTRING const  mreadingNumber;
extern LCDSTRING const * const s_multiSelected []  ;
extern LCDSTRING const * const s_singleSelected [] ;
extern LCDSTRING const * const s_aggSizeMenu [];
extern int const menu_aggsize_length;
extern LCDSTRING const * const s_aggSizeInMenu [];
extern LCDSTRING const msize5;
extern LCDSTRING const msize4;
extern LCDSTRING const msize3;
extern LCDSTRING const msize2;
extern LCDSTRING const msize1;
extern LCDSTRING const msizeIn5;
extern LCDSTRING const msizeIn4;
extern LCDSTRING const msizeIn3;
extern LCDSTRING const msizeIn2;
extern LCDSTRING const msizeIn1;
extern LCDSTRING const Selected;
extern LCDSTRING const * s_ActivateOffset [];
LCDSTRING const * const s_MaxaggSizemm [5];
LCDSTRING const * const s_MaxaggSizeIn [5];
LCDSTRING const * s_ActivateMix [4];
LCDSTRING const * s_ChangeSaveValue[4];
LCDSTRING const * const s_EnterValue [4] ;
LCDSTRING const * const s_CapChannel[4];
LCDSTRING const * const s_CalEntry[4];
LCDSTRING const * const s_writeCalibUSB[4] ;
LCDSTRING const * const s_readCalibUSB[4];
LCDSTRING const * const s_ContinuousModeModeOn[4]; 
LCDSTRING const * const s_ContinuousModeModeOff[4]; 
LCDSTRING const m_ContinuousModeON;
LCDSTRING const m_ContinuousModeOFF;
LCDSTRING const * const sEnterTimeDayMonth[4] ;
LCDSTRING const * const sSelectTimeItem[4];
LCDSTRING const month_day_YearOrder;
LCDSTRING const day_month_YearOrder;
LCDSTRING const * const sMonthDayOrderChange[4];
LCDSTRING const * const sDayMonthOrderChange[4];
LCDSTRING const * const s_EnterValueMonth [4];
LCDSTRING const * const s_EnterValueDay [4];
LCDSTRING const * const s_EnterValueYear [4];
LCDSTRING const * const s_EnterValueMinutes [4] ;
LCDSTRING const * const s_EnterValueHour [4];
LCDSTRING const * const s24HourModeChange[4];
LCDSTRING const * const sAmPmModeChange[4] ;
LCDSTRING const m24_Hour_Mode  ;
LCDSTRING const mAM_PM_Mode  ;

extern LCDSTRING const * const s_CalibMenu [];
extern int const callength;
extern LCDSTRING const CalID;
extern LCDSTRING const * const s_CalIDMenuNum [];
extern LCDSTRING const * const s_calEEpromFull[] ;
extern LCDSTRING const * const s_calEnterName[];
extern LCDSTRING const * const s_calNewID [];

extern LCDSTRING const * const s_EnterGmm [4];
extern LCDSTRING const * s_SlopeChange [4] ;
extern LCDSTRING const * const s_EnterAggSz [4];
extern LCDSTRING const * s_AggSzChange [4];
extern LCDSTRING const * const s_EnterOffset [4];
extern LCDSTRING const * s_OffsetChange [4];
extern LCDSTRING const m_Offset ;
extern LCDSTRING const m_AggSz;
extern LCDSTRING const m_Gmm;
extern LCDSTRING const CalID ;
extern LCDSTRING const * const s_calNewID [4];
extern LCDSTRING const * const s_aggSizeMenu [];
extern int const menu_aggsize_length;
extern LCDSTRING const * const s_aggSizeInMenu [];
extern LCDSTRING const msize5;
extern LCDSTRING const msize4;
extern LCDSTRING const msize3;
extern LCDSTRING const msize2;
extern LCDSTRING const msize1;
extern LCDSTRING const msizeIn5;
extern LCDSTRING const msizeIn4;
extern LCDSTRING const msizeIn3;
extern LCDSTRING const msizeIn2;
extern LCDSTRING const msizeIn1;
extern LCDSTRING const Selected;
extern LCDSTRING const * s_ActivateOffset [];
extern LCDSTRING const * const s_MaxaggSizemm [5];
extern LCDSTRING const * const s_MaxaggSizeIn [5];
extern LCDSTRING const * s_ActivateMix [4];
extern LCDSTRING const * const s_EnterDEPTH [4] ;
extern LCDSTRING const * const s_BottomTempOff [4] ;
extern LCDSTRING const * const s_BottomTempOn [4] ;
LCDSTRING const mBottomTempOff ;
LCDSTRING const mBottomTempOn ;
LCDSTRING const * const sFactCalTypeLow[4];
LCDSTRING const * const sFactCalTypeHigh[4];
LCDSTRING const mFactCalType;
LCDSTRING const mTypeLow ;
LCDSTRING const mTypeHigh;

extern LCDSTRING const * const s_SelectSenType[4];
extern LCDSTRING const  * const s_HF_ModeSelected [4];
extern LCDSTRING const * const s_LFModeSelected [4];
extern LCDSTRING const * const s_ThicknessOn [4] ;
extern LCDSTRING const * const s_ThicknessOff[4] ;
extern LCDSTRING const mThicknessOff ;
extern LCDSTRING const mThicknessOn ;
extern LCDSTRING const * s_ThickMode [4] ;

LCDSTRING const m_matThickness;
LCDSTRING const * const s_matThickness [4] ;
LCDSTRING const * const s_EnterThickness [4] ;

CONST_LCDSTRING  mESC_to_Exit[LANGUAGES];
CONST_LCDSTRING_PTR sESCToExit[4]  ;
CONST_LCDSTRING_PTR s_IncorrectBLE[4];
CONST_LCDSTRING_PTR s_Calibration_due[4] ;
CONST_LCDSTRING mGaugeReady[LANGUAGES] ;
CONST_LCDSTRING mCountTime[LANGUAGES];
CONST_LCDSTRING_PTR s_Up_Down_Change_Exit[4]; 
#endif



