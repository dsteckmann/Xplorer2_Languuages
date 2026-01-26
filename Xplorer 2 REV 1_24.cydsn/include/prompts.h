#ifndef PROMPTS_H
#define PROMPTS_H
#include "Globals.h"
#include <project.h>
#include "DataTypes.h"

void up_down_ENTER_select_text();  
void display_version(void);
void initializing(void);
void main_menu_display(uint8_t menu_trk);
void project_menu_display(uint8_t menu_trk) ;
void diag_menu_display(uint8_t menu_trk);
void display_depth(BYTE function, BYTE depth_temp);
void ready(BYTE cnt_temp, int line);
void display_count_time(BYTE value_temp, uint8_t position );
void YES_to_Accept(BYTE position);
void up_down_select_text(int16_t both);
void display_version(void);
void initializing(void);
void main_menu_display(uint8_t menu_trk);
void project_menu_display(uint8_t menu_trk);
void display_depth(BYTE function, BYTE depth_temp);
void max_stations_text(char *temp_str);
void self_test_text(BYTE which_test);
void voltage_out_of_range(float volts_temp);
void diagnostics_text(BYTE which_prompt);
void USB_text(BYTE which_prompt);
void printer_text(BYTE which_prompt);
void display_time(BYTE cnt_temp,uint8_t line);
void display_station_name(char *temp_str, uint8);
void enable_disable_text(char *temp_str,char c);
void set_units_text(void);
void offset_on_off_text(char *temp_str, int16_t enabled);
void enter_offset_text(char *temp_str);
void offset_enable_disable_text(char *temp_str, int16_t enabled);
void cal_menu_text(BYTE display_set);
void cal_depth_text(int16_t depth_temp);
void reset_cal_date_text(BYTE which_prompt);
void bscatter_const_text(void);
extern void Press_YES_or_NO (BYTE position);
void recount_txt();
void progress_bar( BYTE display_set);
void store_consts();
void review_consts();
void block_densities_txt ( BYTE display_set);
void cnt_result_display_txt(BYTE display_set, int j);
void cnt_display_txt(BYTE display_set, int j);
void yes_when_ready_txt();
void auto_cal_depth(BYTE display_set, int j);
void block_txt(BYTE display_set);
void auto_cal_text(BYTE display_set);
void self_test_pf_text(BYTE source, int16_t test_failed);
void stat_drift_count_text(BYTE source);
void count_text(BYTE source);
void delete_project_text(char *temp_str);
void select_from_list_text(BYTE from_where);
void station_increment_text(uint16_t inc);
void station_start_text(char *temp_str);
void project_name_text(char *temp_str);
uint8 enter_project_name_text(char *temp_str);
void enter_valid_text(BYTE which_source);
void speccal_results_text(int16_t loops, uint16_t cnt_temp);
void enter_valid_text(BYTE which_source);
void mode_menu_display(unsigned int menu_trk);

void display_count_text ( uint16_t moist, uint32_t dens,uint32_t dens_combo );
void display_offset ( struct offsets_struct  which_offsets);
void display_offset_on ( struct offsets_struct  which_offsets);
void sd_menu_display(uint8_t menu_trk) ;
void eeprom_msg(void);

#endif


