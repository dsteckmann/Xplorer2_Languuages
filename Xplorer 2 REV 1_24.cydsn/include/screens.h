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
extern CONST_LCDSTRING  mBlank[] ;
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
extern CONST_LCDSTRING_PTR s_count_test_txt[];
extern CONST_LCDSTRING_PTR s_lights_are_on_txt[ ] ;
extern CONST_LCDSTRING_PTR s_display_count_text[ ] ;
extern CONST_LCDSTRING_PTR s_light_test_txt[ ] ;
extern CONST_LCDSTRING_PTR s_press_off_txt[ ];
extern CONST_LCDSTRING_PTR s_shut_down_txt[ ] ;
extern CONST_LCDSTRING_PTR s_select_language_text[ ];
extern CONST_LCDSTRING_PTR s_serial_port_text[ ];
extern CONST_LCDSTRING_PTR s_enter_station_name_text[ ];
extern CONST_LCDSTRING_PTR s_print_complete_text[ ] ;
extern CONST_LCDSTRING_PTR s_print_data_text[ ];
extern CONST_LCDSTRING_PTR s_batt_volt_text[ ];
extern CONST_LCDSTRING_PTR s_erase_project_data_text[ ];
extern CONST_LCDSTRING_PTR s_delete_project_text[ ];
extern CONST_LCDSTRING_PTR s_all_data_erased_text[ ];
extern CONST_LCDSTRING_PTR s_erase_data_text[ ];
extern CONST_LCDSTRING_PTR s_enter_to_delete_text[ ];
extern CONST_LCDSTRING_PTR s_delete_data_text[ ];
extern CONST_LCDSTRING_PTR s_no_stored_data[ ];
extern CONST_LCDSTRING m_SelectProject[] ;
extern CONST_LCDSTRING m_SelectStation[];
extern CONST_LCDSTRING_PTR s_project_limit_text[ ];
extern CONST_LCDSTRING_PTR s_station_name_text[ ];
extern CONST_LCDSTRING m_M_Count[];   
extern CONST_LCDSTRING m_D_Count[];   
extern CONST_LCDSTRING m_MCR[];       
extern CONST_LCDSTRING m_DCR[];       
extern CONST_LCDSTRING m_DT[];        
extern CONST_LCDSTRING m_WD[];        
extern CONST_LCDSTRING m_per_max[];   
extern CONST_LCDSTRING m_per_voids[]; 
extern CONST_LCDSTRING m_Moist[];     
extern CONST_LCDSTRING m_per_Moist[]; 
extern CONST_LCDSTRING m_DD[];       
extern CONST_LCDSTRING m_per_proct[];
extern CONST_LCDSTRING m_soil_av[];
extern CONST_LCDSTRING_PTR s_station_increment[ ];
extern CONST_LCDSTRING_PTR s_station_start[ ];
extern CONST_LCDSTRING_PTR s_station_mode_text[ ];
extern CONST_LCDSTRING_PTR s_project_name[ ];
extern CONST_LCDSTRING_PTR s_enter_project_name[ ];
extern CONST_LCDSTRING_PTR s_enter_valid_time[] ;
extern CONST_LCDSTRING_PTR s_enter_valid_date[ ];
extern CONST_LCDSTRING_PTR s_shutdown_inactivity[ ];
extern CONST_LCDSTRING_PTR s_shutdown[ ];
extern CONST_LCDSTRING_PTR s_press_key_text[ ];
extern CONST_LCDSTRING_PTR s_depth_voltage_text[ ];
extern CONST_LCDSTRING_PTR s_gauge_temp_text[ ];
extern CONST_LCDSTRING_PTR s_warning_text[ ];
extern CONST_LCDSTRING_PTR s_display_alk_warning[ ];
extern CONST_LCDSTRING_PTR s_prma_text[ ];
extern CONST_LCDSTRING_PTR s_battery_shutdwn_text[ ];
extern CONST_LCDSTRING m_trench_offset[] ;
extern CONST_LCDSTRING_PTR s_use_val_text[ ];
extern CONST_LCDSTRING_PTR s_get_new_offset_text[ ];
extern CONST_LCDSTRING_PTR s_change_val_text[ ];
extern CONST_LCDSTRING m_max[];
extern CONST_LCDSTRING m_depth_slope[] ;
extern CONST_LCDSTRING m_pr[] ;
extern CONST_LCDSTRING m_sht_dwn_time[] ;
extern CONST_LCDSTRING m_cal_date[];
extern CONST_LCDSTRING m_soil_sg[];
extern CONST_LCDSTRING_PTR s_am_pm_text[ ];
extern CONST_LCDSTRING_PTR s_enter_time_text[ ];
extern CONST_LCDSTRING_PTR s_nomograph_enabled_text[ ];
extern CONST_LCDSTRING_PTR s_enter_bot_dense_text[ ];
extern CONST_LCDSTRING_PTR s_enter_mat_thickness_text[ ];
extern CONST_LCDSTRING_PTR s_nomograph_vals_text[ ];
extern CONST_LCDSTRING_PTR s_activate_saved_vals_text[ ];
extern CONST_LCDSTRING_PTR s_disable_nomograph_text[ ] ;
extern CONST_LCDSTRING_PTR s_enable_nomograph_text[ ];
extern CONST_LCDSTRING_PTR s_speccal_enabled_text[ ];
extern CONST_LCDSTRING m_Yes_to_Continue[] ;
extern CONST_LCDSTRING_PTR s_start_speccal_text[ ];
extern CONST_LCDSTRING_PTR s_enter_number_counts_text[ ];
extern CONST_LCDSTRING_PTR s_activate_speccal_text[ ] ;

#endif

//dispscrn_e ( 

