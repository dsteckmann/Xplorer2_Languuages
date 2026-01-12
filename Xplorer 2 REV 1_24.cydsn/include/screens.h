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
extern CONST_LCDSTRING m_DepthSafe[];
extern CONST_LCDSTRING m_DepthBS[] ;
extern CONST_LCDSTRING m_DepthNone[];
extern CONST_LCDSTRING m_Depth[] ;
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
extern CONST_LCDSTRING_PTR s_use_stored_count_text[ ];
extern CONST_LCDSTRING_PTR s_EnterValue[ ] ;
extern CONST_LCDSTRING_PTR s_BEnterValue[ ];
extern CONST_LCDSTRING_PTR s_DensityEnterValue[ ];
extern CONST_LCDSTRING_PTR s_DensityNowEnterValue[ ] ;
extern CONST_LCDSTRING_PTR s_ProctEnterValue[ ] ;
extern CONST_LCDSTRING_PTR s_MAXDensityEnterValue[ ];
extern CONST_LCDSTRING_PTR s_SGEnterValue[ ];
extern CONST_LCDSTRING_PTR s_ShutDownHRSEnterValue[ ];
extern CONST_LCDSTRING_PTR s_depthslopeEnterValue[ ] ;
extern CONST_LCDSTRING_PTR s_use_gauge_text[ ] ;
extern CONST_LCDSTRING m_values_ok[]  ;
extern CONST_LCDSTRING_PTR s_view_last_speccal_text[ ] ;
extern CONST_LCDSTRING_PTR s_memory_reset_text[ ]  ;
extern CONST_LCDSTRING_PTR s_disable_speccal_text[ ] ;
extern  CONST_LCDSTRING_PTR s_enable_speccal_text[ ];
extern  CONST_LCDSTRING m_moist_const[] ;
extern CONST_LCDSTRING_PTR s_access_number_incorrect_text[ ]  ;
extern CONST_LCDSTRING C0[] ;
extern CONST_LCDSTRING C1[] ;
extern CONST_LCDSTRING C2[] ;
extern CONST_LCDSTRING C3[] ;
extern CONST_LCDSTRING C4[] ;
extern CONST_LCDSTRING C5[] ;
extern CONST_LCDSTRING C6[] ;
extern CONST_LCDSTRING C7[] ;
extern CONST_LCDSTRING C8[] ;
extern CONST_LCDSTRING C9[] ;
extern CONST_LCDSTRING C10[];
extern CONST_LCDSTRING C11[];
extern CONST_LCDSTRING C12[];
extern CONST_LCDSTRING C13[];
extern CONST_LCDSTRING C14[];
extern CONST_LCDSTRING_PTR s_enter_cal_mois_std_text[ ] ;
extern  CONST_LCDSTRING_PTR s_enter_cal_den_std_text[ ];
extern  CONST_LCDSTRING_PTR s_enter_access_number_text[ ] ;
extern CONST_LCDSTRING_PTR s_offsets_text[ ]  ;
extern  CONST_LCDSTRING_PTR s_place_in_bs_text[ ] ;
extern  CONST_LCDSTRING m_avg_stand_mode_enabled_text[]   ;
extern CONST_LCDSTRING_PTR s_SAV_disabled_text[ ] ;
extern CONST_LCDSTRING_PTR s_SAV_enabled_text[ ] ;
extern CONST_LCDSTRING m_decay_mode_en[]  ;
extern  CONST_LCDSTRING_PTR s_stand_mode_settings_text[ ];
extern CONST_LCDSTRING_PTR s_no_data_to_store_text[ ] ;
extern CONST_LCDSTRING_PTR s_clock_set_error_text[ ]  ;
extern  CONST_LCDSTRING_PTR s_depth_strip_type[ ] ;
extern CONST_LCDSTRING_PTR s_auto_depth_settings[ ]  ;
extern CONST_LCDSTRING m_AutoDepthDisabled[] ;
extern CONST_LCDSTRING m_AutoDepthEnabled[]  ;
extern CONST_LCDSTRING_PTR s_RodinBS[];
extern CONST_LCDSTRING_PTR s_RodinSafe[];
extern CONST_LCDSTRING m_ResetAVGCount[];
extern CONST_LCDSTRING m_trench_text[];
extern CONST_LCDSTRING m_spec_text[];
extern CONST_LCDSTRING m_drift_text[]   ;
extern CONST_LCDSTRING m_nomograph_text[] ;
extern CONST_LCDSTRING_PTR s_depth_not_in_bs_text[ ] ;
extern CONST_LCDSTRING_PTR s_not_in_bs_text[ ] ;
extern CONST_LCDSTRING m_stat_text[] ;
extern CONST_LCDSTRING m_Station1[] ;
extern CONST_LCDSTRING_PTR s_printing_data_wait_txt[ ] ;
extern CONST_LCDSTRING_PTR s_NoPrinterDetected[ ]  ;
extern CONST_LCDSTRING_PTR s_ConnectPrinterToGauge[ ] ;
extern CONST_LCDSTRING_PTR s_PlaceonSTDBlock[ ] ;
extern CONST_LCDSTRING_PTR s_PleaseWaitTimeleft[ ];
extern CONST_LCDSTRING m_InvalidMoistStd[];
extern CONST_LCDSTRING m_InvalidDensityStd[];
extern CONST_LCDSTRING_PTR s_disable_auto_depth[ ];
extern CONST_LCDSTRING_PTR s_no_valid_depth_selected[ ];
extern CONST_LCDSTRING_PTR s_max_stations_text[ ];
extern CONST_LCDSTRING_PTR s_no_project_selected[ ];
extern CONST_LCDSTRING m_Project[];
extern CONST_LCDSTRING_PTR s_trench_count[ ] ;
extern CONST_LCDSTRING_PTR s_DriftStatTest5[ ] ;
extern CONST_LCDSTRING_PTR s_StatTest20[ ] ;
extern CONST_LCDSTRING m_sd_5[] ;
extern CONST_LCDSTRING m_sd_4[] ;
extern CONST_LCDSTRING m_sd_3[] ;
extern CONST_LCDSTRING m_sd_2[] ;
extern CONST_LCDSTRING m_sd_1[] ;
extern CONST_LCDSTRING m_diag_menu_1[] ;
extern CONST_LCDSTRING m_diag_menu_2[] ;
extern CONST_LCDSTRING m_diag_menu_3[] ;
extern CONST_LCDSTRING m_diag_menu_4[] ;
extern CONST_LCDSTRING m_diag_menu_5[] ;
extern CONST_LCDSTRING m_diag_menu_6[] ;
extern CONST_LCDSTRING m_diag_menu_7[] ;
extern CONST_LCDSTRING m_diag_menu_8[] ;
extern CONST_LCDSTRING m_diag_menu_9[] ;
extern CONST_LCDSTRING m_diag_menu_10[] ;
extern CONST_LCDSTRING m_diag_menu_11[] ;
extern CONST_LCDSTRING m_diag_menu_12[] ;
extern CONST_LCDSTRING m_diag_menu_13[] ;
extern CONST_LCDSTRING m_diag_menu_14[] ;
extern CONST_LCDSTRING m_diag_menu_15[] ;

//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;
//extern  ;

//extern 





#endif

//dispscrn_e ( 

