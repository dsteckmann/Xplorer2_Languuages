
//#include "project.h"
#include "Globals.h"
#include "DataStructs.h"
#include "LCD_drivers.h"
#include "prompts.h"
#include "screens.h"
//#include <stdio.h>
//#include <string.h>

void main_menu_display(uint8_t menu_trk)   // display for the main menu
{  
  switch (menu_trk)
  {
    
    case 1: 
      // 1. Recall
      // 2. Offset
      displine_e ( LINE1, M1, 1 );    
      displine_e ( LINE2, M2, 1 );    
      break;    
    
    case 2: 
      // 3. Auto Scroll
      // 4. Backlight
      displine_e ( LINE1, M3, 1 );    
      displine_e ( LINE2, M4, 1 );       
      break;
      
    case 3:    
      // 5. Stat Test
      // 6. Drift Test
      displine_e ( LINE1, M5, 1 );    
      displine_e ( LINE2, M6, 1 );         
      break;

    case 4: 
      // 7. GPS
      // 8. Auto Depth
      displine_e ( LINE1, M7, 1 );    
      displine_e ( LINE2, M8, 1 );        
      break;
    case 5: 
       // 9. Review STD cnts.
       // 10. Select Language
       displine_e ( LINE1, M9, 1 );    
       displine_e ( LINE2, MP10, 1 );
       break;    
        
    case 6:   
       // 11. Set Units
       // 12. Standard Mode
       displine_e ( LINE1, MP11, 1 );    
       displine_e ( LINE2, MP12, 1 );      
       break;    
   
    case 7: 
       // 13. Serial Number
       // 14. Date/Time
       displine_e ( LINE1, MP13, 1 );    
       displine_e ( LINE2, MP14, 1 );      
       break;   
   
    case 8:
       // 15. Buzzer/Alarm
       // 16. Special Cal.
       displine_e ( LINE1, MP15, 1 );    
       displine_e ( LINE2, MP16, 1 );      
       break;    
   
    case 9:
       // 17. Nomograph
       // 18. Cal. Constants
       displine_e ( LINE1, MP17, 1 );    
       displine_e ( LINE2, MP18, 1 );       
       break;    
        
    case 0:   
       // 19. Soil Air Voids
       // 20. Diagnostic Test
       displine_e ( LINE1, MP19, 1 );    
       displine_e ( LINE2, MP20, 1 );       
       break;      
  }

  if(in_menu)
  {  up_down_select_text(1);  }
}

//1. Battery Voltage
//2. Extended Counts
//3. Check Temperature
//4. Memory Reset
//5. Depth Sensor Test
//6. KEY PAD Test
//7. USB Store Test
//8. Count Test
//9. Shut Down Test
//10.Light Test
//11. GPS Test 
//12. Update Firmware
//13. SD Card Test
//14. Reset BLE Module
//15.Idle Shutdwn Time
void diag_menu_display( uint8_t menu_trk)
{
  LCD_position(LINE1);    
  switch (menu_trk)
  {
    case 1:    
        //1. Battery Voltage
        //2. Extended Counts    
        displine_e ( LINE1, m_diag_menu_1,1);
        displine_e ( LINE2, m_diag_menu_2,1);
        break;    
    case 2:    
        //3. Check Temperature  
        //4. Memory Reset
        displine_e ( LINE1, m_diag_menu_3,1);
        displine_e ( LINE2, m_diag_menu_4,1);
        break;   
    case 3:
        //5. Depth Sensor Test
        //6. KEY PAD Test   
        displine_e ( LINE1, m_diag_menu_5,1);
        displine_e ( LINE2, m_diag_menu_6,1);
        break;
    case 4:
        //7. USB Store Test
        //8. Count Test
        displine_e ( LINE1, m_diag_menu_7,1);
        displine_e ( LINE2, m_diag_menu_8,1);
        break;                   
    case 5:
        //9. Shut Down Test
        //10.Light Test
        displine_e ( LINE1, m_diag_menu_9,1);
        displine_e ( LINE2, m_diag_menu_10,1);
        break;                   
    
    case 6:
        //11. GPS Test 
        //12. Update Firmware
        displine_e ( LINE1, m_diag_menu_11,1);
        displine_e ( LINE2, m_diag_menu_12,1);
        break;      
  
   case 7:
        //13. SD Card Test
        //14. Reset BLE Module
        displine_e ( LINE1, m_diag_menu_13,1);
        displine_e ( LINE2, m_diag_menu_14,1);
        break;    
      
    case 0:
        //15.Idle Shutdwn Time
        displine_e ( LINE1, m_diag_menu_15,1);
        displine_e ( LINE2, mBlank,1);
        break;      
  }
  if(in_menu)
    up_down_select_text(1);  
}

void sd_menu_display(uint8_t menu_trk)   // display for the project menu
{
  switch (menu_trk)
  {
    case 1:
    //1. SD Card Test 
    displine_e ( LINE1, m_sd_1, 1 );
    //2. Format SD Card 
    displine_e ( LINE2, m_sd_2, 1 );
    break;
    
    case 2:
    //3. Delete Proj. Dir.
    displine_e ( LINE1, m_sd_3, 1 );
    //4. Create Proj. Dir.
    displine_e ( LINE2, m_sd_4, 1 );
    break;
    
    case 0:
    //5. Add/Delete Files
    displine_e ( LINE1, m_sd_3, 1 );
    //4. Create Proj. Dir.
    displine_e ( LINE2, mBlank, 1 );
    
    break;
    
  }
   
  if (in_menu)
  {  up_down_select_text(1);  }
}

void display_count_time(BYTE value_temp, uint8_t position )
{
  // Count Time:
  displine_e ( position, mCountTime ,1);
     
  if(value_temp <= 30)
  {
    switch ( g_language )
    {
      default:
      case L_ENGLISH :     
          _LCD_PRINTF( "%u sec. ",value_temp );
          break;
      case L_SPANISH:
          _LCD_PRINTF( "%u seg.",value_temp ); 
          break;
    }       
  }
  else
  {
    _LCD_PRINTF(" %u min. ",value_temp/60); 
  }
}

void max_stations_text(char *temp_str)
{  
  //
  //Max # of Stations
  //Has Been Exceeded.
  //Start New Project  
  dispscrn_e ( s_max_stations_text );
  LCD_position(LINE1);
  _LCD_PRINTF("%s",temp_str);
}


// Keep This
void self_test_text(BYTE which_test)
{  
  CLEAR_DISP;
    if(which_test < 3)  
    {
      if(which_test==0)
      {      
        //
        //High Voltage Test
        // In Progess
        //
        dispscrn_e( s_HighVoltageTest );
      }
      else if (which_test==1)
      {
        //Keypad Test
        displine_e ( LINE2, KeyPadTest,1 );
      }  
      else if(which_test==2)
      {
        // Tube Test
        displine_e ( LINE2, TubeTest,1 );
      }  
    }
    else 
    {     
      // 
      // Self Test
      // Passed
      //
      dispscrn_e ( s_SelfTestPassedTest );
    }
}

void printer_text(BYTE which_prompt)
{
  if(which_prompt==0)
  {   
    //Printing Data
    //Please Wait
    //
    //
    dispscrn_e ( s_printing_data_wait_txt );
  }
  else if(which_prompt==1)
  {   
    //
    //No Printer
    //Detected
    //
    dispscrn_e ( s_NoPrinterDetected );
  }
  else if(which_prompt==2)
  {   
    //Connect Printer
    //To Gauge
    //
    //Press ENTER
    dispscrn_e ( s_ConnectPrinterToGauge );
  } 
 
}


void USB_text(BYTE which_prompt)
{
  if(which_prompt==1)
  {   
    //
    //   Writing Data
    //   to USB Drive
    //
    dispscrn_e ( s_writingDataUSB_text );
  }
  else if(which_prompt==2)
  {   
    //
    //   No USB Device
    //   Detected
    //
    dispscrn_e ( s_noUSBDeviceDetected );
  }
  else if(which_prompt==3)
  {    
    //
    //   Data Download
    //   Complete
    //
    dispscrn_e ( s_DataDownloadComplete );
  }
  else if(which_prompt==0)
  {
    //Insert External
    //Drive in USB Port
    //
    // Press ENTER
    dispscrn_e ( s_insertExternalUSB_text );
  }
}


void display_offset ( struct offsets_struct  which_offsets)
{
   
  LCD_position (LINE3+17);
  //LCD_print("Offset:");
     
     if ( which_offsets.den_offset_pos )
     {
      LCD_print("D");
     }
     if ( which_offsets.moist_offset_pos )
     {
      LCD_print("M");
     }  
     if ( which_offsets.tren_offset_pos )
     {
      LCD_print("T");
     }   
  
}

void display_offset_on ( struct offsets_struct  which_offsets)
{
   
  LCD_position (LINE2 + 12);
  if ( which_offsets.den_offset_pos ||  which_offsets.moist_offset_pos ||  which_offsets.tren_offset_pos )
  { 
   switch (g_language )
   {
      case L_ENGLISH:
        LCD_print("OFFSET:Y");  
        break;
      case L_SPANISH:
        LCD_print("COMPEN:S");  
        break;
      default:
        LCD_print("OFFSET:Y");  
        break;
    }    
  }
  else
  { 
    switch (g_language )
    {
      case L_ENGLISH:
        LCD_print("OFFSET:N");  
        break;
      case L_SPANISH:
        LCD_print("COMPEN:N");  
        break;
      default:
        LCD_print("OFFSET:N");  
        break;  
    }    
  } 	
}


void display_time(BYTE cnt_temp,uint8_t line)
{
  LCD_position(line);
  switch (g_language)
  {
    case L_ENGLISH:
    default:
      displine_e( line,mCountTime,1);
      _LCD_PRINTF("%3u sec. ",cnt_temp);
      break;
    case L_SPANISH: 
      LCD_print( "    Tiempo:");
      _LCD_PRINTF("%3u seg. ",cnt_temp);
      break;
  }
}

void display_station_name(char *temp_str,uint8 line)
{
   displine_e ( line,m_Station1, 1 ); 
  _LCD_PRINTF("%s",temp_str);
}

void enable_disable_text(char *temp_str,char c)
{
  CLEAR_DISP;
  LCD_position (LINE1);
  switch ( g_language )
  {
    case L_ENGLISH:
    default:
    {
      switch(c)
      {
        case 'L':
        _LCD_PRINTF("%s LCD/Keypad",temp_str);
        LCD_position(LINE2);
        LCD_print("Backlight?");   
        break;
        
        case 'S':
        _LCD_PRINTF("%s Auto",temp_str);
        LCD_position(LINE2);
        LCD_print("Scroll?");  
        break;
        
        case 'D':
        _LCD_PRINTF("%s Auto",temp_str);
        LCD_position(LINE2);
        LCD_print("Depth?");   
        break;
        
        case 'A':
        _LCD_PRINTF("%s AVG STD",temp_str);
        LCD_position(LINE2);
        LCD_print("Mode?");      
        break;
        
        case 'O':
        _LCD_PRINTF("%s Auto",temp_str);
        LCD_position(LINE2);
        LCD_print("Store?");
        break;
        
        case 'B':
        _LCD_PRINTF("%s Buzzer?",temp_str);
        break;
        
        case 'G':
        _LCD_PRINTF("%s GPS?",temp_str);
        break;
        
        case 'M':
        _LCD_PRINTF("%s SMART MC?",temp_str);
         break;
        
        case 'Q':
        _LCD_PRINTF("%s Chi2 Test?",temp_str);
        break;
      }    
    break;
    }  
   
    case  L_SPANISH:
    {    
      switch(c)
      {
        case 'L':
        _LCD_PRINTF("%s Iluminacion",temp_str); // Encender / Apagar Iluminacion LCD
        LCD_position(LINE2);
        LCD_print("LCD?");   
        break;
      
        case 'S':
        _LCD_PRINTF("%s Cambia Auto",temp_str); // Habilitar / Deshabilitar Cambio Automático de Pantalla
        LCD_position(LINE2);
        LCD_print("de Pantalla?");  
        break;
      
        case 'D':
        _LCD_PRINTF("%s",temp_str); // Habilitar / Deshabilitar  Profundidad Automatica
        LCD_position(LINE2);
        LCD_print("Profundidad Auto?");   
        break;
      
        case 'A':
        _LCD_PRINTF("%s Modo",temp_str); // Habilitar / Deshabilitar Modo AVG STD
        LCD_position(LINE2);
        LCD_print("AVG STD?");      
        break;
      
        case 'O':
        _LCD_PRINTF("%s Auto",temp_str);  // Habilitar / Deshabilitar Auto Memoria
        LCD_position(LINE2);
        LCD_print("Memoria?");
        break;
      
        case 'B':
        _LCD_PRINTF("%s Alarma?",temp_str);  // Habilitar / Deshabilitar Alarma
        break;
      
        case 'G':
        _LCD_PRINTF("%s GPS?",temp_str);  // Habilitar / Deshabilitar  Memoria GPS
        break;
        
        case 'M':
       _LCD_PRINTF("%s SMART MC?",temp_str);
       break;

      case 'Q':
      _LCD_PRINTF("%s Chi2 Test?",temp_str);
      break;
      }    
    break;  
    }
  }  
}

void set_units_text(void)
{
  CLEAR_DISP;
  LCD_PrintAtPosition ( "1.   PCF", LINE1 );
  LCD_PrintAtPosition ( "2. kg/m3", LINE2 );
  LCD_PrintAtPosition ( "3.   GCC", LINE3 );
}

///******************************************************************************************************/
// Redo the whole offet routine to make it compatible with new message screens of multiple languages
void offset_on_off_text(char *temp_str, int16_t enabled)
{
  if(Features.language_f)
  {
    if(enabled)                              
    {        
      LCD_position (LINE1);
      _LCD_PRINTF("%s Offset ON",temp_str);        
      LCD_position (LINE2);
      LCD_print("Want to Disable?");
    }
    else
    {
      LCD_position (LINE1);
      _LCD_PRINTF("%s Offset OFF",temp_str);             
      LCD_position (LINE2);
      LCD_print("Want to Enable?");
    }      
  }
    else
    {
      if(enabled)                             //    Densidad / Humedad / Zanja  Compensacion Habilitado Desea Deshabilitarlo?   
      {        
        LCD_position (LINE1);
        _LCD_PRINTF("%s Compensacion",temp_str);        
        LCD_position (LINE2);
        LCD_print("Habilitado Desea");
        LCD_position(LINE3); 
        LCD_print("Deshabilitarlo?");
      }
      else
      {
        LCD_position (LINE1);
        _LCD_PRINTF("%s Compensacion",temp_str);  // Densidad / Humedad / Zanja - Compensacion Deshabilitado desea Habilitarlo?               
        LCD_position (LINE2);
        LCD_print("Deshabilitado Desea");
        LCD_position(LINE3);
        LCD_print("Habilitarlo?");
      }      
    }  
}

void enter_offset_text(char *temp_str)
{
  LCD_position(LINE1);
  if(Features.language_f)
  {
    _LCD_PRINTF("Enter %s",temp_str);  
    LCD_position(LINE2);
    LCD_print("Offset:");
  }
    else
    {
      LCD_print("Ingresar Compensac'n");
      LCD_position(LINE2);
      _LCD_PRINTF("%s",temp_str);
    }
}
void offset_enable_disable_text(char *temp_str, int16_t enabled)
{  
  CLEAR_DISP;
  LCD_position(LINE2);
  
  if(Features.language_f)
  {
    if(!enabled)
    {    
      _LCD_PRINTF(" %s Offset",temp_str);
      LCD_position(LINE3);
      LCD_print("   Disabled");           
    }
    else
    {
      _LCD_PRINTF(" %s Offset",temp_str);
      LCD_position(LINE3);
      LCD_print("   Enabled");
    }
  }
    else
    {  
      if(!enabled)
      {    
        _LCD_PRINTF(" %s Compensacion",temp_str);
        LCD_position(LINE3);
        LCD_print("   Deshabilitado");           
      }
      else
      {
        _LCD_PRINTF(" %s Offset",temp_str);
        LCD_position(LINE3);
        LCD_print("   Habilitado"); 
      }
    }
}

///******************************************************************************************************/
void cal_depth_text(int16_t depth_temp)
{
  char dstr[10];
  CLEAR_DISP;   
  
  if ( depth_temp == 1 )
  {
   //Depth:BS
   displine_e ( LINE1, m_DepthBS,1 );
  }
  else 
  {
    //Depth:
    sprintf( dstr,"%d",depth_temp);
    displine_e ( LINE1, m_Depth,1 );
    _LCD_PRINTF(" %s", dstr ); 
  }
}


void cal_menu_text(BYTE display_set)
{
    switch(display_set)
    {
      case 1:
            //0. Moist Consts
            displine_e ( LINE1,C0,1 );
            //1. Depth BS
            displine_e ( LINE2,C1,1 );
            break;
      case 2:
            //2. Depth 2
            //3. Depth 3
            displine_e ( LINE1,C2,1 );
            displine_e ( LINE2,C3,1 );
            break;            
      case 3:
            //4. Depth 4
            //5. Depth 5
            displine_e ( LINE1,C4,1 );
            displine_e ( LINE2,C5,1 );
            break;  
      case 4:
            //6. Depth 6
            //7. Depth 7
            displine_e ( LINE1,C6,1 );
            displine_e ( LINE2,C7,1 );
            break;  
      case 5:
            //8. Depth 8
            //9. Depth 9
            displine_e ( LINE1,C8,1 );
            displine_e ( LINE2,C9,1 );
            break;  
      case 6:
            //10. Depth 10
            //11. Depth 11
            displine_e ( LINE1,C10,1 );
            displine_e ( LINE2,C11,1 );
            break;  
      case 7:
            //12. Depth 12
            //13. Calibration Date
            displine_e ( LINE1,C12,1 );
            displine_e ( LINE2,C13,1 );
            break; 
      case 0:
            //14. Calib Std Counts
            //        
            displine_e ( LINE1,C14,1 );
            displine_e ( LINE2,mBlank,1 );
            break; 
  }
}

void speccal_results_text(int16_t loops,uint16_t cnt_temp)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  
  switch ( g_language )
  {
    case L_ENGLISH:
    default:
       _LCD_PRINTF("#%d Density",loops);
       LCD_position(LINE2);
       _LCD_PRINTF("Count: %u",cnt_temp);
       LCD_position(LINE3);
       LCD_print("YES to Continue");
      break;
  case L_SPANISH:
      _LCD_PRINTF("#%d Cuentas de",loops);  // Numero de Cuentas de Densidad " Si " para Continuar
      LCD_position(LINE2);
      _LCD_PRINTF("Densidad: %u",cnt_temp);
      LCD_position(LINE3);
      LCD_print("SI para Continuar");
      break;
  }  
}


//Enter Project
//Name:
//YES to Accept
//ESC to Exit
uint8 enter_project_name_text(char *temp_str)
{
  dispscrn_e (s_enter_project_name );
  _LCD_PRINTF("%s",temp_str);
  uint8 lcd_line; 
  switch ( g_language )
  {
    case L_ENGLISH:
         default:
         lcd_line = LINE2+6;
         break;
  
    case L_SPANISH:
         lcd_line = LINE2+10;
         break;
  }
  return lcd_line;
}

void station_start_text(char *temp_str)
{ 
  //Starting Station
  //Number:
  //YES to Accept
  //ESC to Exit
  dispscrn_e ( s_station_start ); 
  gotoloc ( LINE1+9,1);
  _LCD_PRINTF("%s",temp_str);
}

void station_increment_text(uint16_t inc)
{ 
  //Station # 
  //Increments by 1
  //For Each Reading
  //
  dispscrn_e ( s_station_increment );
  gotoloc (LINE1+10,1);
  _LCD_PRINTF("%u",inc);
}

void select_from_list_text(BYTE from_where)
{
  CLEAR_DISP;
  if(from_where==0)
  {  
    displine_e ( LINE2, m_SelectProject,1 );
    //   Select Project;
  }
  else if(from_where==1)
  { 
    displine_e ( LINE2, m_SelectStation,1 );
    // Select Station
  }

}

void stat_drift_count_text(BYTE source)
{
  switch (g_language )
  {
    case L_ENGLISH:
    default:
    {     
      switch ( source )
      {
        case  0: LCD_print("D%% Drift:  "); break;
        case  1: LCD_print("Dens. Avg: ");  break;
        case  2: LCD_print("M%% Drift:  "); break;
        case  3: LCD_print("Moist.AVG: ");  break;      
        case  4: LCD_print("Dens. R:   ");  break;
        case  5: LCD_print("Moist R:   ");  break;
        default: break;
      }
      break;
    }
    
    case L_SPANISH:
    {     
      switch(source)
      {
        case  0: LCD_print("D%% Drift:  "); break;
        case  1: LCD_print("Dens. Avg: ");  break;
        case  2: LCD_print("H%% Drift:  0"); break;
        case  3: LCD_print("Humedad.AVG: ");  break;
        case  4: LCD_print("Dens. R:   ");  break;
        case  5: LCD_print("Humedad R:   ");  break;
      }
    }
  }  
}


void display_count_text ( uint16_t moist, uint32_t dens,uint32_t dens_combo )
{ 
  char line_buff [21];
  
  //      M Count:
  // Combo DCount:   
  //Single DCount:    
  //Press ESC to Exit
  dispscrn_e ( s_display_count_text );
  
  // print moisture count
  snprintf ( line_buff,20,"%u",moist);
  LCD_position (LINE1+14);  
  LCD_print( line_buff);
  
  // print density combo count
  snprintf ( line_buff,20,"%lu",(unsigned long)dens_combo);
  LCD_position (LINE2+14);  
  LCD_print( line_buff);
 
  // print density combo count
  snprintf ( line_buff,20,"%lu",(unsigned long)dens);
  LCD_position (LINE3+14);  
  LCD_print( line_buff);  
}

void Press_YES_or_NO (BYTE position)
{ 
  LCD_position(position); 
  if(Features.language_f)
  {  LCD_print("Press YES or NO"); }
   else
  {  LCD_print("Presione SI o NO"); } 
}

void ESC_to_Exit(BYTE position)
{
  LCD_position(position);
  if(Features.language_f)
  {  LCD_print("ESC to Exit"); }
   else
  { LCD_print("ESC para Salir");}
}

void Enter_to_Accept(BYTE position)
{ 
  LCD_position(position);
  if(Features.language_f)
    LCD_print("ENTER to Accept");
   else
   LCD_print("SI para Aceptar");  

}


void YES_to_Accept(BYTE position)
{ 
  LCD_position(position);
  if(Features.language_f)
    LCD_print("YES to Accept");
   else
   LCD_print("SI para Aceptar");  

}

void up_down_select_text(int16_t both)
{  
  if(both)
  {
    //UP/DOWN for Next  
    displine_e ( LINE3, Up_Down_Next, 1 );
  }
  //Select #, ESC Exit   
  displine_e ( LINE4, SelectNumber, 1 );
}


void up_down_ENTER_select_text()
{  

  LCD_position(LINE2);
  if(Features.language_f)
    LCD_print(" <ENTER> to Select  "); 
  else
   LCD_print(" <ENTER> a Escoger  ");
  
  LCD_position(LINE3);
  if(Features.language_f)
    LCD_print("  UP/DOWN for Next  ");
  else 
    LCD_print("   Arriba/Abajo     ");       
  
  LCD_position(LINE4);
  if(Features.language_f)
    LCD_print("     <ESC> Exit     "); 
  else
    LCD_print("     <ESC> Salir    ");  
   
}

void display_version(void) { 
  char temp_str[20];
  struct features_struct  Feat        =  NV_RAM_MEMBER_RD(FEATURE_SETTINGS); 
  CLEAR_DISP;
  LCD_position(LINE1); 
  // if 3440 
  if ( GAUGE_3440 == NV_RAM_MEMBER_RD (gauge_type ) )
  {
     LCD_print("      3400     ");
  }  
  else if ( GAUGE_3500 == NV_RAM_MEMBER_RD (gauge_type ) )
  {
    LCD_print("      Xplorer 2");
  } 
  else if ( GAUGE_3440_PLUS == NV_RAM_MEMBER_RD (gauge_type ) )
  {
    LCD_print("    3400 PLUS  ");
  }
  
  sprintf(temp_str,"    Version %.2f",VERSION );
  LCD_PrintAtPosition(temp_str,LINE2);
  
  if (Feat.dummy_mode == TRUE )
  { 
    CtrStrNC("DEMO", LINE3); //LCD_PrintAtPosition("       DEMO         ",LINE3);
  }  
}

void eeprom_msg(void)
{ 
  CLEAR_DISP;    
  LCD_position (LINE2+9);
  LCD_print("EE");  
  CyDelay ( 1000 );
}


void initializing(void)
{ 
  CLEAR_DISP;    
  LCD_position (LINE2+5);
  LCD_print("Initializing");  // no spanish needed now.  Should only see on first programming
}



void project_menu_display(uint8_t menu_trk)   // display for the project menu
{
  if(Features.language_f)
  {
     switch (menu_trk)
    {
      case 1:
      LCD_position(LINE1);
      LCD_print("1. Auto Store       ");
      LCD_position(LINE2);
      LCD_print("2. Start New Project");
      break;
      
      case 2:
      LCD_position(LINE1);
      LCD_print("3. Sel. Stored Proj.");
      LCD_position(LINE2);
      LCD_print("4. Review Data      ");
      break;
      
      case 0:
      LCD_position(LINE1);
      LCD_print("5. Delete Data      ");
      LCD_position(LINE2);
      LCD_print("                    ");      
      break;   
     }
   }
    else
    {
      switch (menu_trk)
      {
        case 1:
        LCD_position(LINE1);
        LCD_print("1. Auto Memoria      ");
        LCD_position(LINE2);
        LCD_print("2. Nuevo Proyecto    ");
        break;
      
        case 2:
        LCD_position(LINE1);
        LCD_print("3. Proyect Memorizado");
        LCD_position(LINE2);
        LCD_print("4. Revisar la Info.  ");
        break;
       
        case 0 :
        LCD_position(LINE1);
        LCD_print("5. Borrar la Info.   ");       
        LCD_position(LINE2);
        LCD_print("                    ");       
      }
   }
  if(in_menu)
  {  up_down_select_text(1);  }
}


void mode_menu_display(unsigned int menu_trk)
{
  LCD_position(LINE1);    
  switch (menu_trk)
  {
    case 1: LCD_print("1. NORMAL           ");     
            LCD_position(LINE2);      
            LCD_print("2. DUMMY            ");
            break;
    case 2:    
            LCD_print("3. InstroTek        ");
            LCD_position(LINE2);      
            LCD_print("4. Troxler  3440    ");   
           break; 
    case 0:    
            LCD_print("5. Troxler 3440 Plus");
            LCD_position(LINE2);      
            LCD_print("                    ");   
            break;
            
    default:
            break;    
   }
 
  if(in_menu)
    up_down_select_text(1);  
}
// Strat Main Menu
void main_menu_strata_display(uint8_t menu_trk)   // display for the main menu
{  
  LCD_position(LINE1);  
  switch (menu_trk)
  {
    
    case 1: 
        LCD_print(" 1. Stat Test        ");
        LCD_position(LINE2);
        LCD_print(" 2. Drift Test       ");     
        break;    
    
    case 2: 
        LCD_print(" 3. Recall           ");
        LCD_position(LINE2);
        LCD_print(" 4. Offset           ");     
        break;    
    case 3:    
        LCD_print(" 5. Diagnostic Test ");            
        LCD_position(LINE2);      
        LCD_print(" 6. Review STD cnts.");
        break;
   case 4:    
        LCD_print(" 7. Standard Mode   ");
        LCD_position(LINE2);          
        LCD_print(" 8. Auto Scroll     ");    
        break;        
    case 5:   
        LCD_print(" 9. Set Units       ");
         LCD_position(LINE2);
        LCD_print("10. LCD Light       ");      
        break;    
    case 6:   
        LCD_print("11. Serial Number   ");
        LCD_position(LINE2);      
        LCD_print("12. Date/Time       ");      
        break;   
    case 0:
        LCD_print("13. Buzzer/Alarm    ");
         LCD_position(LINE2);
        LCD_print("14. Cal. Constants  ");
         break;    
  }  
 
  if( in_menu )
  {  
   up_down_select_text(1);  
  }

}





