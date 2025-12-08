
//#include "project.h"
#include "Globals.h"
#include "DataStructs.h"
#include "LCD_drivers.h"
#include "prompts.h"
#include "screens.h"
//#include <stdio.h>
//#include <string.h>


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
    //   UP/DOWN for Next  
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

void calibration_due()
{   //213240  213128 saves 112 bytes, could free a lot of space if all are fixed
  if(Features.language_f)
  {
    CtrStrNC("Calibration Due!",LINE1);
    CtrStrNC("Last Calibration On", LINE2);
  }
  else
  {
    CtrStrNC("Require Calibracion",LINE1);
    CtrStrNC("Ultima cal. hecha en", LINE2);
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

void diag_menu_display( uint8_t menu_trk)
{
  LCD_position(LINE1);    
  switch (menu_trk)
    {
      case 1:    
          LCD_print("1. Battery Voltage  ");     
          LCD_position(LINE2);      
          LCD_print("2. Extended Counts  ");
          break;    
      case 2:    
          LCD_print("3. Check Temperature");  
          LCD_position(LINE2);          
          LCD_print("4. Memory Reset    ");
          break;   
      case 3:
          LCD_position(LINE1);
         LCD_print("5. Depth Sensor Test");
         LCD_position(LINE2);
         LCD_print("6. KEY PAD Test     ");      
          break;           
      case 4:
          LCD_position(LINE1);
         LCD_print("7. USB Store Test   ");
         LCD_position(LINE2);
         LCD_print("8. Count Test       ");      
          break;                   
      case 5:
          LCD_position(LINE1);
         LCD_print("9.  Shut Down Test  ");
         LCD_position(LINE2);
         LCD_print("10. Light Test      ");      
          break;                   
      
      case 6:
          LCD_position(LINE1);
         LCD_print("11.  GPS Test       ");
         LCD_position(LINE2);
         LCD_print("12.  Update Firmware");      
          break;      
    
     case 7:
          LCD_position(LINE1);
         LCD_print("13.  SD Card Test   ");
         LCD_position(LINE2);
         LCD_print("14. Reset BLE Module");        
          break;    
        
      case 0:
          LCD_position(LINE1);
         LCD_print("15.Idle Shutdwn Time");
         LCD_position(LINE2);
         LCD_print("                    ");      
        break;      
        
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
    LCD_position(LINE1);
    LCD_print("1. SD Card Test     ");
    LCD_position(LINE2);
    LCD_print("2. Format SD Card   ");
    break;
    
    case 2:
    LCD_position(LINE1);
    LCD_print("3. Delete Proj. Dir.");
    LCD_position(LINE2);
    LCD_print("4. Create Proj. Dir.");
    break;
    
    case 0:
    LCD_position(LINE1);
    LCD_print("5. Add/Delete Files ");
    LCD_position(LINE2);
    LCD_print("                    ");
    break;
    
  }
   
  if (in_menu)
  {  up_down_select_text(1);  }
}


// *******************************************************************************************************************************


void ready(BYTE cnt_temp, int line)
{
  CLEAR_DISP;
  //LCD_position(LINE1);
  if(Features.language_f)
  {
     LCD_PrintAtPositionCentered("GAUGE READY",LINE1+10); 
  }
  else
  {
     LCD_PrintAtPositionCentered("PREPARADO",LINE1+10); 
  }
  
 /*LCD_position(LINE2); 
 
 if(cnt_temp <= 30)
  {
    if(Features.language_f)
     { _LCD_PRINTF("COUNT TIME: %u sec.",cnt_temp);}
    else
     { _LCD_PRINTF("COUNT TIME: %u seg.",cnt_temp); }
  }
  else
    { _LCD_PRINTF("COUNT TIME: %u min.",cnt_temp/60);  }
    
  */  
  LCD_position ( LINE4 );
  LCD_print ("Press START to Test "); 
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

void select_test_or_spec_cal(int16_t inspec)
{  
  CLEAR_DISP;  
  LCD_position(LINE1);
  if(Features.language_f)
  {
    if(!inspec)
    {  LCD_print("Select Test");  }
    else 
     { LCD_print("Select Spec. Cal"); }
  }
    else
    {
      if(!inspec)
        LCD_print("Sel. la Prueba");  
      else 
        LCD_print("Sel. Calib. Especial");  
    }
}

void press_start(BYTE which_test)
{
  CLEAR_DISP; 
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print ( "  Press START for   ");
    LCD_position (LINE3);
    if(which_test==0) //  stat test
    { 
      LCD_print("  20 one min counts ");  
      LCD_position ( LINE1 );
      LCD_print("      Stat Test     ");  
    }
    else if(which_test==1) //  drift test
    {
      LCD_print(" 5 four min counts  ");  
      LCD_position ( LINE1 );
      LCD_print("     Drift Test     ");  
    }
    else if (which_test==2)  // standard
    { 
       LCD_print("  Standard Count."); 
    }
    else if (which_test==3 )
    {
      LCD_print("  Count to Begin");  
    }
  }
    else
    {
      LCD_print(" Pres. Iniciar Para ");
      LCD_position (LINE3);
      if(which_test==0) //  stat test
      {  LCD_print("20m Prb estadistica"); }    
      else if(which_test==1)//   drift test
      {  LCD_print("20m Prb Desviacion"); }
      else if(which_test==2)//   standard
      { LCD_print(" Cuenta Standard"); }
      else if(which_test==3)
      {  LCD_print(" Cuenta a Iniciarse"); }
    }
}

// trench count
void trench_count_press_start(void)
{
  
  char temp_str[10];
  CLEAR_DISP; 
  
  
  if (  Features.SI_units ==  TRUE  )
  {
   sprintf (temp_str,"50mm");
  }
  else
  {
   sprintf(temp_str, "2in");
  }

 if(Features.language_f)
  {
    LCD_PrintAtPositionCentered("Place Gauge in",LINE1+10);
    LCD_PrintAtPosition("Trench on Std. Block",LINE2);
    LCD_PrintAtPositionCentered("in SAFE Position",LINE3+10);
  	LCD_PrintAtPositionCentered("Press Start", LINE4+10 );
  }
  else
  {
    LCD_PrintAtPositionCentered("Place Gauge in",LINE1+10);
    LCD_PrintAtPosition("Trench on Std. Block",LINE2);
    LCD_PrintAtPositionCentered("in SAFE Position",LINE3+10);
  	LCD_PrintAtPositionCentered("Press Start", LINE4+10 );
  }

}



void use_new_std_count()
{  
  LCD_position (LINE3);
  if(Features.language_f)
    { LCD_print("Use New STD Count?");   }
  else
    { LCD_print("Use Nueva Cuent Std?"); }
    
}

void current_project_text ( char *temp_str )
{
 _LCD_PRINTF("Project: %s",temp_str);
}

void max_stations_text(char *temp_str)
{  
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Max # of Stations");
    LCD_position(LINE2);
    _LCD_PRINTF("For %s has",temp_str);
    LCD_position(LINE3);
    LCD_print("Been Exceeded.");
    LCD_position(LINE4);
    LCD_print("Start New Project");  
  }
    else
    {
      LCD_print("Max # de Estaciones");  
      LCD_position(LINE2);
      _LCD_PRINTF("Para %s se ha",temp_str);
      LCD_position(LINE3);
      LCD_print("Execido. Inicie un");
      LCD_position(LINE4);
      LCD_print("Nuevo Proyecto.");   
    }
}
void no_project_selected ( void )
{ 
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  { 
    LCD_print("No Project Has Been");
    LCD_position(LINE2);
    LCD_print("Selected. Please");
    LCD_position(LINE3);
    LCD_print("Create or Select");
    LCD_position(LINE4);
    LCD_print("Project.");  
  }
    else
    { 
      LCD_print("Ningun Projecto se a");  
      LCD_position(LINE2);
      LCD_print("Seleccionado.       ");
      LCD_position(LINE3);
      LCD_print("Elabore o Seleccione");
      LCD_position(LINE4);
      LCD_print("un Projecto.");   
    }  
}

void no_valid_depth_selected ( void )
{ 
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  { 
    LCD_print(" No Valid Depth Has ");
    LCD_position(LINE2);
    LCD_print("   Been Selected.");
  }
    else
    { 
      LCD_print("Ningun Projecto se a");  
      LCD_position(LINE2);
      LCD_print("Seleccionado.       ");
      LCD_position(LINE3);
      LCD_print("Elabore o Seleccione");
      LCD_position(LINE4);
      LCD_print("un Projecto.");   
    }  
}


void disable_auto_depth()
{  
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Disable Auto");
    LCD_position(LINE2);
    LCD_print("Depth?");
  }
    else
    {
      LCD_print("Desconectar");  
      LCD_position(LINE2);
      LCD_print("Profundidad Auto.?");  
    }
}

void calibration_date_txt ( void )
{  
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Cal Date:           ");
    
  }
    else
    {
    LCD_print("Cal Date:           ");
    }
}

void invalid_std_or_const(void)
{
  CLEAR_DISP;
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print("   Invalid STD or");
    LCD_position (LINE3);
    LCD_print("   Cal. Constants");
  }
    else
    {
      LCD_print("Conteo STD const. de");  
      LCD_position (LINE3);
      LCD_print("  Calib. Invalidas");  
    }
}

void invalid_den_std_text(void)
{
  CLEAR_DISP;
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print("Invalid Density Std.");
  }
  else
  {
    LCD_print("Invalid Density Std.");
  }
}

void invalid_mois_std_text(void)
{
  CLEAR_DISP;
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print("Invalid Moist. Std. ");
  }
  else
  {
    LCD_print("Invalid Moist. Std. ");
  }
}


void mat_thickness_error ( void )
{

  CLEAR_DISP;
  LCD_position (LINE1);
  if(Features.language_f)
  {
    LCD_print("Thickness is between");
    LCD_position (LINE2);
    if ( Features.SI_units == FALSE )
    {
      LCD_print ("1 and 4 inches      ");
    }
    else
    {
     LCD_print ( "25 and 100 mm       ");
    }  
  }
  else
  {
     LCD_print("Thickness is between");
    LCD_position (LINE2);
    if ( Features.SI_units == FALSE )
    {
      LCD_print ("1 and 4 inches      ");
    }
    else
    {
     LCD_print ( "25 and 100 mm       ");
    } 
  }

}



void reading(void)
{
  CLEAR_DISP;
  LCD_position(LINE2);
  if(Features.language_f)
  {
    LCD_print("Reading # "); 
  }
  else
  {
    LCD_print("Lectura # ");
  }  
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
   
void voltage_out_of_range(float volts_temp)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    _LCD_PRINTF("   Voltage = %3.0f",(double)volts_temp);
    LCD_position(LINE2);
    LCD_print("    Out of Range");
    LCD_position(LINE4);
    LCD_print("    Test Aborted!");
  }
    else 
    {
      _LCD_PRINTF("   Voltaje = %3.0f",volts_temp);  
      LCD_position(LINE2);
      LCD_print("   Fuera de Rango");
      LCD_position(LINE4);
      LCD_print("  Pruebo Abortada!"); 
    }
}

void diagnostics_text(BYTE which_prompt)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    if(which_prompt==1)
    {
      LCD_print("Place Gauge on");
      LCD_position(LINE2);
      LCD_print("Standard Block");
      LCD_position(LINE3);
      LCD_print("in SAFE Position");
      LCD_position(LINE4);
      LCD_print("and Press START");
    }
    else if(which_prompt==2)
    {         
      LCD_position(LINE2);
      LCD_print("    Please Wait");
      LCD_position(LINE3);
      LCD_print("  Time Left 60:00");   
    }     
  }
    else
    {
      if(which_prompt==1)
      {
        LCD_print("Coloque el Equipo en");  
        LCD_position(LINE2);
        LCD_print("el Bloque Standard");
        LCD_position(LINE3);
        LCD_print("en Posicion se Segur");
        LCD_position(LINE4);
        LCD_print("Presione Inciar");
      }
      else if(which_prompt==2)
      {   
        LCD_position(LINE2);
        LCD_print("  Por Favor Espere");  
        LCD_position(LINE3);
        LCD_print("     Tiempo 60:00");   
      }     
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


void printer_text(BYTE which_prompt)
{
  CLEAR_DISP; 
  LCD_position(LINE2);
  if(Features.language_f)
  {
    if(which_prompt==0)
    {   
      LCD_position(LINE2);
      LCD_print("   Printing Data");
      LCD_position(LINE3);
      LCD_print("    Please Wait");
    }
    else if(which_prompt==1)
    {   
      LCD_position (LINE2);
      LCD_print("     No Printer");  
      LCD_position (LINE3);
      LCD_print("      Detected!");
    }
    else if(which_prompt==2)
    {   
      LCD_position(LINE1);
      LCD_print("  Connect Printer");
      LCD_position(LINE2);
      LCD_print("     To Gauge");      
      LCD_position(LINE4);
      LCD_print("    Press ENTER");  
    } 
  }
    else
     {
      if(which_prompt==0)
      {   
        LCD_position(LINE1);
        LCD_print("   Imprimiendo la");  
        LCD_position(LINE2);
        LCD_print("    Informacion");
        LCD_position(LINE3);
        LCD_print("  Por Favor Espere.");   
      }
      else if(which_prompt==1)
      {   
        LCD_position (LINE2);
        LCD_print("   No se Detecta    ");  
        LCD_position (LINE3);
        LCD_print("    Impresora!");  
      }
      else if(which_prompt==2)
      {   
        LCD_position(LINE1);
        LCD_print("Conecte la Impresora"); 
        LCD_position(LINE2);
        LCD_print("    al Equipo.");      
        LCD_position(LINE4);
        LCD_print("  Presione Iniciar");   
      } 
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

void display_station_name(char *temp_str)
{
  if(Features.language_f)
   { LCD_print("Station: "); }
    else 
   {  LCD_print("Estacion: "); } 
  _LCD_PRINTF("%s",temp_str);
}


void stat_text(void)
{
  if(Features.language_f)
     { LCD_print("Stat Test"); }
    else 
     { LCD_print("Prueba Estadistica"); }
}


void not_in_bs_text ( void )
{
 CLEAR_DISP;
 LCD_position (LINE1);
 if(Features.language_f)
 {
  LCD_print("Nomograph Enabled   ");
  LCD_position (LINE2);
  LCD_print("Depth not at BS     ");
  LCD_position (LINE3);
  LCD_print("Position            ");
 } 
 else 
 {
  LCD_print("Nomograph Enabled   ");
  LCD_position (LINE2);
  LCD_print("Depth not at BS     ");
  LCD_position (LINE3);
  LCD_print("Position            ");
 }  

}

void depth_not_in_bs_text ( void )
{
 CLEAR_DISP;
 LCD_position (LINE1);
 if(Features.language_f)
 {
  LCD_print("Depth not at BS     ");
  LCD_position (LINE2);
  LCD_print("Position            ");
 } 
 else 
 {
  LCD_print("Depth not at BS     ");
  LCD_position (LINE2);
  LCD_print("Position            ");
 }  

}


void depth_not_in_ac_text ( void )
{
 CLEAR_DISP;
 LCD_position (LINE1);
 if(Features.language_f)
 {
  LCD_print("Depth not at AC     ");
  LCD_position (LINE2);
  LCD_print("Position            ");
 } 
 else 
 {
  LCD_print("Depth not at AC     ");
  LCD_position (LINE2);
  LCD_print("Position            ");
 }  

}


void depth_not_in_2_text ( void )
{
  char temp_str[10];
  
  CLEAR_DISP; 
  
  if (  Features.SI_units == TRUE  )
  {
   sprintf(temp_str, "50 mm");
  }
  else
  {
   sprintf(temp_str, "2 in");
  }
 
 LCD_position (LINE1);
 if(Features.language_f)
 {
  _LCD_PRINTF("Depth not at %s",temp_str);
  LCD_position (LINE2);
  LCD_print("Position            ");
 } 
 else 
 {
  _LCD_PRINTF("Depth not at %s",temp_str);
  LCD_position (LINE2);
  LCD_print("Position            ");
 }  

}


void place_in_bs_text ( void )
{
 CLEAR_DISP;
 LCD_position (LINE1);
 
 if(Features.language_f)
 {
  LCD_print("Thin Layer Enabled  ");
  LCD_position (LINE2);
  LCD_print("Place in BS Position");
  LCD_position (LINE4);   
  LCD_print("    Press Enter    ");
 } 
 else 
 {
   LCD_print ("Thin Layer Enabled  ");
  LCD_position (LINE2);
   LCD_print ("Place in BS Position");
  LCD_position (LINE4);   
  LCD_print  ("    Press Enter     ");
 }  
}  

void place_in_ac_text ( void )
{
 CLEAR_DISP;
 LCD_position (LINE1);
 
 if(Features.language_f)
 {
  LCD_print("Thin Layer Enabled  ");
  LCD_position (LINE2);
  LCD_print("Place in AC Position");
  LCD_position (LINE4);   
  LCD_print  ("    Press Enter     ");
 } 
 else 
 {
   LCD_print("Thin Layer Enabled  ");
  LCD_position (LINE2);
  LCD_print("Place in AC Position");
  LCD_position (LINE4);   
  LCD_print  ("    Press Enter     ");
 }  
}


void nomograph_text(void)
{
  if(Features.language_f)
     { LCD_print("      Nomograph     "); }
    else 
     { LCD_print("      Nomograph     "); }
}



void drift_text(void)
{
  if(Features.language_f)
    { LCD_print("Drift Test"); }
    else
    {  LCD_print("Prueba de Desviacion");  }
}

void spec_text(void)
{
  if(Features.language_f)
    { LCD_print("Special Calibration"); }
    else
    {  LCD_print("Calibracion Especial"); }
}

void trench_text(void)
{
  if(Features.language_f)
    { LCD_print("Trench Offset Count "); }
    else
    {  LCD_print("Trench Offset Count "); }
}


void enable_disable_text(char *temp_str,char c)
{
  CLEAR_DISP;
  LCD_position (LINE1);
  if(Features.language_f)
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
  }
    else
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
    }
}
void reset_avg_count(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
   { LCD_print("Reset AVG Count?"); }
    else
      LCD_print("Borrar Cuentas AVG?");   //  Borrar cuentas AVG?
}

void auto_depth_settings(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Auto Depth Settings");
    LCD_position(LINE2);
    LCD_print("1. Enable/Disable");
     if ( NV_RAM_MEMBER_RD( gauge_type ) != GAUGE_3440_PLUS )
     {
      LCD_position(LINE3);
      LCD_print("2. Depth Strip Type");
     } 
    
  }
    else 
     {
      LCD_print("Profund. Automatica");   //Opciones de Profundidad Automatica 1. Habilitar / Deshabilitar 2. Calibrar.
      LCD_position(LINE2);
      LCD_print("1. Habil./Deshabil.");
      if ( NV_RAM_MEMBER_RD( gauge_type ) != GAUGE_3440_PLUS )
      {
       LCD_position(LINE3);
       LCD_print("2. Depth Strip Type");
      }        
    }
}

void depth_strip_type(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Depth Strip Type");
    LCD_position(LINE2);
    LCD_print("1. Xplorer");
    LCD_position(LINE3);
    LCD_print("2. 3440");
  }
  else 
  {
    LCD_print("Depth Strip Type");
    LCD_position(LINE2);
    LCD_print("1. Xplorer");
    LCD_position(LINE3);
    LCD_print("2. 3440");
  }
}


void date_usb_error_text ( void )
{
 CLEAR_DISP;
 LCD_position (LINE1);
 if(Features.language_f)
 {
  LCD_print("Clock/USB Disabled  ");
  LCD_position (LINE2);
  LCD_print("Unplugging Ribbon   ");
  LCD_position (LINE3);
  LCD_print("Cable May Fix Issue");
  LCD_position (LINE4);
  LCD_print("Press <ENTER> ");

 } 
 else 
 { 
  LCD_print("Clock/USB Disabled  ");
  LCD_position (LINE2);
  LCD_print("Unplugging Ribbon   ");
  LCD_position (LINE3);
  LCD_print("Cable May Fix Issue");
  LCD_position (LINE4);
  LCD_print("Press <ENTER> ");
 }  

}


void clock_set_error_text ( void )
{
 CLEAR_DISP;
 LCD_position (LINE1);
 if(Features.language_f)
 {
  LCD_print("    Error setting   ");
  LCD_position (LINE2);
  LCD_print("    Internal Clock  ");
  LCD_position (LINE3);
  LCD_print("   Restart Gauge    ");
  LCD_position (LINE4);
  LCD_print("   Press <ENTER>    ");

 } 
 else 
 { 
  LCD_print("    Error setting   ");
  LCD_position (LINE2);
  LCD_print("    Internal Clock  ");
  LCD_position (LINE3);
  LCD_print("   Restart Gauge    ");
  LCD_position (LINE4);
  LCD_print("   Press <ENTER>    ");
 }  

}

void no_data_to_store_text ( void )
{
 CLEAR_DISP;
 LCD_position (LINE1);
 if(Features.language_f)
 {
  LCD_print("  No Data To Store  ");
  LCD_position (LINE2);
  LCD_print("        Start       ");
  LCD_position (LINE3);
  LCD_print("   New Measurement  ");
 } 
 else 
 {
  LCD_print("  No Data To Store  ");
  LCD_position (LINE2);
  LCD_print("        Start       ");
  LCD_position (LINE3);
  LCD_print("   New Measurement  ");
 }  

}

void stand_mode_settings_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("1. Average Mode     ");
    LCD_position(LINE2);
    LCD_print("2. Decay Mode       ");
  }
  else 
  {
    LCD_print("1. Media Modo     ");
    LCD_position(LINE2);
    LCD_print("2. Desinteg. Modo");
  }
}


void avg_stand_mode_enabled_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_position(LINE2);
    LCD_print("Avg Std Mode Enabled");
  }
  else 
  {
   LCD_position(LINE2);
   LCD_print("Media Modo Activar");
  }
}


void decay_stand_mode_enabled_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_position(LINE2);
    LCD_print("Decay Mode Enabled  ");
  }
  else 
  {
   LCD_position(LINE2);
   LCD_print("Desint. Modo Activar");
  }
}


void gauge_in_safe(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Place Gauge in");
    LCD_position(LINE2);
    LCD_print("SAFE Position");
    LCD_position(LINE3);
    LCD_print("and Press ENTER"); 
  }
    else
    {    
      LCD_print("Coloque el Equipo");  // Coloque el equipo en posicion de seguridad.  Presione Iniciar
      LCD_position(LINE2);
      LCD_print("en Posicion de Segur");
      LCD_position(LINE3);
      LCD_print("Presione Inciar.");
    }
}


void gauge_in_bs_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Place Gauge in      ");
    LCD_position(LINE2);
    LCD_print("BS Position         ");
    LCD_position(LINE3);
    LCD_print("and Press ENTER     "); 
  }
    else
    {    
      LCD_print("Coloque el Equipo");  // Coloque el equipo en posicion de seguridad.  Presione Iniciar
      LCD_position(LINE2);
      LCD_print("en Posicion de BS");
      LCD_position(LINE3);
      LCD_print("Presione Inciar.");
    }
}


void calibration_complete_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("    Calibration");
    LCD_position(LINE2);
    LCD_print("     Complete");
  }
    else
    { 
      LCD_print("    Calibracion");  //Calibración Terminada
      LCD_position(LINE2);
      LCD_print("     Terminada");
    }
}

void calibration_fail_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE2);
  if(Features.language_f)
  {
    LCD_print("    Calibration     ");
    LCD_position(LINE3);
    LCD_print("     Failed         ");
  }
    else
    { 
      LCD_print("    Calibracion");  //Calibración Terminada
      LCD_position(LINE3);
      LCD_print("     Failed    ");
    }
}

void set_units_text(void)
{
  CLEAR_DISP;
 
  LCD_PrintAtPosition ( "1.   PCF", LINE1 );
  LCD_PrintAtPosition ( "2. kg/m3", LINE2 );
  LCD_PrintAtPosition ( "3.   GCC", LINE3 );
  
}
void offsets_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("1. Density");
    LCD_position(LINE2);
    LCD_print("2. Moisture");
    LCD_position(LINE3);
    LCD_print("3. Trench"); 
  }
    else
    {
      LCD_print("1. Densidad");  // 1.Densidad. 2. Humedad 3. Zanja.
      LCD_position(LINE2);
      LCD_print("2. Humedad");
      LCD_position(LINE3);
      LCD_print("3. Zanja"); 
    }  
}


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




void SAV_enable_disable_text( int enabled )
{  
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    if(enabled == 0)
    {    
      LCD_position(LINE1);
      LCD_print("%%Soil Air Voids ");
      LCD_position(LINE2);
      LCD_print("   Disabled");           
      LCD_position(LINE3);
      LCD_print("Want to Enable?");           
    }
    else
    {
      LCD_position(LINE1);
      LCD_print("%%Soil Air Voids ");
      LCD_position(LINE2);
      LCD_print("   Enabled");           
      LCD_position(LINE3);
      LCD_print("Want to Disable?");  
    }
     LCD_position(LINE4);
     LCD_print("Press YES or NO ");
    
  }
  else
  {  
    if(!enabled)
    {    
      LCD_position(LINE1);
      LCD_print("%%Tiearra Aire Nulo  ");  // Soil air voids
      LCD_position(LINE2);
      LCD_print("   Deshabilitado");       // Disabled
      LCD_position(LINE3);
      LCD_print("desea habilitar?");       //Want to Enable
      
    }
    else
    {
      LCD_position(LINE1);
      LCD_print("%%Tiearra Aire Nulo  ");
      LCD_position(LINE2);
      LCD_print("   Habilitado"); 
       LCD_position(LINE3);
      LCD_print("desea desactivar?");    // Want to disable
    }
    LCD_position(LINE4);
    LCD_print("Pulsa YES or NO ");
  }
}

void enter_access_number_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Access"); 
    LCD_position(LINE2);
    LCD_print("Number: ");
  }
    else
    {
      LCD_print("Ingrese el Codego de");    //Ingrese el Código de Acceso.
      LCD_position(LINE2);
      LCD_print("Acceso: ");
    }
}

void enter_cal_den_std_text (void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Density Std   "); 
    LCD_position(LINE2);
    LCD_print("Count:              ");
  }
    else
    {
     LCD_print("Enter Density Std   "); 
     LCD_position(LINE2);
     LCD_print("Count:              ");
    }
}

void enter_cal_mois_std_text (void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Moisture Std  "); 
    LCD_position(LINE2);
    LCD_print("Count:              ");
  }
    else
    {
     LCD_print("Enter Moisture Std  "); 
     LCD_position(LINE2);
     LCD_print("Count:              ");
    }
}

void access_number_incorrect_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE2);
  if(Features.language_f)
  {
    LCD_print("    Access Code");
    LCD_position(LINE3);
    LCD_print("     Incorrect"); 
  }
    else
    {
      LCD_print("  Codego de Acceso");  // Codigo de Acceso Incorrecto
      LCD_position(LINE3);
      LCD_print("     Incorrecto"); 
    }  
}
void cal_menu_text(BYTE display_set)
{
  if(Features.language_f)
  {
    switch(display_set)
    {
      case 1:
            LCD_position(LINE1);
            LCD_print("0. Moist Consts     ");
            LCD_position(LINE2);
            LCD_print("1. Depth BS         ");
            break;
      case 2:
            LCD_position(LINE1);
            LCD_print("2. Depth 2          ");
            LCD_position(LINE2);
            LCD_print("3. Depth 3          ");
            break;
      case 3:
            LCD_position(LINE1);
            LCD_print("4. Depth 4          ");
            LCD_position(LINE2);
            LCD_print("5. Depth 5          ");
            break;
      case 4:
            LCD_position(LINE1);
            LCD_print("6. Depth 6          ");
            LCD_position(LINE2);
            LCD_print("7. Depth 7          ");
            break;
      case 5:
            LCD_position(LINE1);
            LCD_print("8. Depth 8          ");
            LCD_position(LINE2);
            LCD_print("9. Depth 9          ");
            break;
      case 6:
            LCD_position(LINE1);
            LCD_print("10. Depth 10        ");
            LCD_position(LINE2);
            LCD_print("11. Depth 11        ");
            break;
      case 7:
            LCD_position(LINE1);
            LCD_print("12. Depth 12        ");        
             LCD_position(LINE2);
            LCD_print("13. Calibration Date");       
      break;
            
      case 0:
            LCD_position(LINE1);
            LCD_print("14. Calib Std Counts");
            LCD_position(LINE2);
            LCD_print("                    ");
            break;
     
    }       
  }
    else
    {
      switch(display_set) //  0. Costantes de Humedad. 1.Retro-dispercion B. 2. Profundidad
      {
        case 1:
        LCD_position(LINE1);
        LCD_print("0. Const. de Humedad");
        LCD_position(LINE2);
        LCD_print("1. Retro-Dispercion ");
        break;
        case 2:
        LCD_position(LINE1);
        LCD_print("2. Profundidad # 2  ");
        LCD_position(LINE2);
        LCD_print("3. Profundidad # 3  ");
        break;
        case 3:
        LCD_position(LINE1);
        LCD_print("4. Profundidad # 4  ");
        LCD_position(LINE2);
        LCD_print("5. Profundidad # 5  ");
        break;
        case 4:
        LCD_position(LINE1);
        LCD_print("6. Profundidad # 6  ");
        LCD_position(LINE2);
        LCD_print("7. Profundidad # 7  ");
        break;
        case 5:
        LCD_position(LINE1);
        LCD_print("8. Profundidad # 8  ");
        LCD_position(LINE2);
        LCD_print("9. Profundidad # 9  ");
        break;
        case 6:
            LCD_position(LINE1);
            LCD_print("10. Profundidad # 10");
            LCD_position(LINE2);
            LCD_print("11. Profundidad # 11");
        break;
        case 7:
             LCD_position(LINE1);
            LCD_print("12. Profundidad # 12");        
            LCD_position(LINE2);
            LCD_print("13. Cal Date  ");
            break;
         case 0:
            LCD_position(LINE1);
            LCD_print("14. Cal Std Counts  ");
            LCD_position(LINE2);
            LCD_print("15. Thin Layer      ");
            break;

      }       
    }
}
void cal_depth_text(int16_t depth_temp)
{
  char dstr[10];
  
  if ( depth_temp == 1 )
  {
   sprintf( dstr,"BS");
  }
  else if ( depth_temp == 13 )
  {
   sprintf( dstr,"AC");
  }
  else 
  {
   sprintf( dstr,"%d",depth_temp);
  }
  
  CLEAR_DISP;   
    
  LCD_position(LINE1);
  if(Features.language_f)
   { 
    _LCD_PRINTF("Depth # %s", dstr ); 
   }
   else
   {
     _LCD_PRINTF("Profundidad # %s", dstr); 
   }  
   
   
}



void reset_cal_date_text(BYTE which_prompt)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    if(which_prompt==0)
    {
      LCD_print("Reset Calibration   ");
      LCD_position(LINE2);
      LCD_print("Date?");
    }
    else
    {   
      LCD_print("  Calibration Date  ");
      LCD_position(LINE2);
      LCD_print("       Reset        ");
    }
  }
    else
    {
      if(which_prompt==0)
      {
        LCD_print("Borrar la Fecha de  ");  // Borrar la fecha de Calibracion?
        LCD_position(LINE2);
        LCD_print("Calibracion?");
      }
      else
      {   
        LCD_print("Fecha de Calibracion");  // Fecha de Calibracion Borrada
        LCD_position(LINE2);
        LCD_print("      Borrada       ");
      }
    }  
}



void moisture_const_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
   { LCD_print("MOISTURE CONST");   }
    else
      LCD_print("CONSTANTE DE HUMEDAD");
}
void bscatter_const_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
   {  LCD_print("BSCATTER CONST"); }
    else
      LCD_print("RETRO-DISPERSION");  // Constante de Retro-Dispersión
}
void memory_reset_text(void)
{
  CLEAR_DISP;
  LCD_position (LINE1);
  if(Features.language_f)
  {
    LCD_print("Reset Memory");
    LCD_position(LINE2);
    LCD_print("to Default?");
  }
    else
    {
      LCD_print("Borrar Memoria");  // Borrar memoria a Inicio?
      LCD_position(LINE2);
      LCD_print("a Inicio?");
    }
}
void enable_disable_speccal_text(int16_t condition)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    if(condition)
     { LCD_print("Disable Special"); }
    else
     { LCD_print("Enable Special");  }
    
    LCD_position(LINE2);
    LCD_print("Calibration?");
  }
    else
    {
      if(condition)
        LCD_print("Deshabilitar Calib.");  //   Habilitar / Deshabilitar Calibracion Especial?
      else
        LCD_print("Habilitar Calib."); 
      LCD_position(LINE2);
      LCD_print("Especial?");
    }
}
void view_last_speccal_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("View Last Saved     ");                  //   Use existing calibration value?
    LCD_position(LINE2);
    LCD_print("Spec Cal. Data?     ");
  }
    else
    {
      LCD_print("Vista de la Ultima");              //       Vista de la Ultima Calibracion Especial Registrada?
      LCD_position(LINE2);
      LCD_print("Cal. Esp Registrada?");
    }  
}
void vals_ok_text(void)
{
  LCD_position(LINE4);
  if(Features.language_f)
   { LCD_print("Values OK? YES/NO   "); }
    else
      LCD_print("Valores OK? SI/NO  ");  
}
void use_gauge_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Use Gauge to Derive ");
    LCD_position(LINE2);  
    LCD_print("B Value?            ");
  }
    else
    {
      LCD_print("Use el Equipo Para");  // Use el Equipo para obtener el  valor "B"
      LCD_position(LINE2);  
      LCD_print("Obtener el Valor B?");
    }
}

void enter_value_text(BYTE which_value)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Value For");
    LCD_position(LINE2);
    if(which_value==0)
      LCD_print("B =");
    else if(which_value==1)
      LCD_print("Density =");
    else if(which_value==2)
      LCD_print("Density Now?");
    else if(which_value==3)
      LCD_print("Proctor:");
    else if(which_value==4)
      LCD_print("MAX DENS:");
    else if( which_value == 5)
      LCD_print("SOIL SG:");  
    else if( which_value == 6)
    LCD_print("SHT DWN (HOURS):");     
    else if( which_value == 7)
      LCD_print("Depth Slope:");    
      
  }
    else
    {    
      LCD_print("Entre el Valor de"); //  Entre el Valor de Densidad:
      LCD_position(LINE2);
      if(which_value==0)
        LCD_print("B =");
      else if(which_value==1)
        LCD_print("Densidad=");
      else if(which_value==2)
        LCD_print("Densidad Ahora?");  // Entre el Valor de Densidad Ahora:
      else if(which_value==3)
        LCD_print("Proctor:");  // Ingresar valor Proctor
      else if(which_value==4)
        LCD_print("MAX DENS:");  // Ingresar valor Proctor
      else if( which_value == 5)
      LCD_print("SOIL SG:");    
      else if( which_value == 6)
      LCD_print("SHT DWN (HOURS):");   
      else if( which_value == 7)
      LCD_print("Depth Slope:");       
      
        
    }
}
void use_stored_count_text(void)
{
  CLEAR_DISP;
  LCD_position (LINE1);
  if(Features.language_f)
  {
    LCD_print("Use Stored Count");
    LCD_position (LINE2);
    LCD_print("Data?");
  }
    else 
    {
      LCD_print("Usar las Cuentas");  // Usar las Cuentas Guardadas?
      LCD_position (LINE2);
      LCD_print("Data?");
    }
}

void activate_speccal_text(void)
{
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print("Activate Special");
    LCD_position(LINE3);
    LCD_print("Calibration?");
  }
    else
    {
      LCD_print("Activar Calibracion"); //  Activar Calibracion Especial
      LCD_position(LINE3);
      LCD_print("Especial?");
    }
}
void enter_number_counts_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Number");
    LCD_position (LINE2);
    LCD_print("of Counts:   ");
  }
    else
    {
      LCD_print("Ingrese Numero de");  /// Ingrese Numero de Cuentas
      LCD_position (LINE2);
      LCD_print("de Cuentas  ");
    }
}
void start_speccal_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("# of Counts:");
    LCD_position(LINE2);
    LCD_print("Depth:");
    LCD_position(LINE3);
    LCD_print("Press START to");
    LCD_position(LINE4);
    LCD_print("Begin Count");       
  }
    else
     {
      LCD_print("# de Cuentas");  // Numero de Cuentas:     Profundidad:     Precione Iniciar para comensar a contar:      
      LCD_position(LINE2);
      LCD_print("Profundidad:");
      LCD_position(LINE3);
      LCD_print("Precione Inciar Para");
      LCD_position(LINE4);
      LCD_print("Comensar a Contar");       
    }
}
void speccal_results_text(int16_t loops,uint16_t cnt_temp)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    _LCD_PRINTF("#%d Density",loops);
    LCD_position(LINE2);
    _LCD_PRINTF("Count: %u",cnt_temp);
    LCD_position(LINE3);
    LCD_print("YES to Continue");
  }
    else
    {
      _LCD_PRINTF("#%d Cuentas de",loops);  // Numero de Cuentas de Densidad " Si " para Continuar
      LCD_position(LINE2);
      _LCD_PRINTF("Densidad: %u",cnt_temp);
      LCD_position(LINE3);
      LCD_print("SI para Continuar");
    }
}
void speccal_enabled_text(void)
{
  CLEAR_DISP;
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print("Special Calibration");
    LCD_position (LINE3);
    LCD_print("      Enabled");
  }
    else
    {
      LCD_print("Calibracion Especial");  // Calibración Especial Habilitada
      LCD_position (LINE3);
      LCD_print("     Habilitada");
    }
}
void enable_disable_nomograph_text(int16_t condition)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    if(condition)
     { LCD_print("Disable Nomograph   "); }
    else
     { LCD_print("Enable Nomograph    ");  }
    
    LCD_position(LINE2);
    LCD_print("Mode?");
  }
    else
    {
      if(condition)
        LCD_print("Habilitar Comando");   // Habilitar/Deshabilitar Comando capa delgada?
      else
        LCD_print("Deshabilitar Comando");
      LCD_position(LINE2);
      LCD_print("Capa Delgada?");
    }
}


void activate_saved_vals_text(void)
{ 
  CLEAR_DISP;
  LCD_position (LINE1);
  if(Features.language_f)
  {
    LCD_print("Activate Saved");
    LCD_position (LINE2);
    LCD_print("Values?");
  }
    else
    {
      LCD_print("Activar los Valores");  // Activar los Valores Guardados ?
      LCD_position (LINE2);
      LCD_print("Guardados?");
    }
}

void nomograph_vals_text(void)
{
  CLEAR_DISP;       
  LCD_position (LINE1); 
  if(Features.language_f)
  {
    LCD_print("Mat Thick=");
    LCD_position (LINE2);
    LCD_print("Bot Dens =");
    LCD_position (LINE3);
    LCD_print("Are Values OK?");
  }
    else
    {
      LCD_print("Espesor Mat");   // Espesor Material =                       Densidad  de Fondo =                  Estan Los Valores Correctos?
      LCD_position (LINE2);
      LCD_print("Dens. Fondo");
      LCD_position (LINE3);
      LCD_print("Valores Correctos?");
    }
}




void enter_mat_thickness_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Material");
    LCD_position (LINE2);
    LCD_print("Thickness:");
  }
    else
    {
      LCD_print("Enter Material"); 
      LCD_position (LINE2);
      LCD_print("Thickness:");
    }
}
void enter_bot_dense_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Bottom");
    LCD_position (LINE2);
    LCD_print("Density:");
  }
    else
    {
      LCD_print("Entre el Valor de la");  // Entre el Valor de la Densidad de fondo
      LCD_position (LINE2);
      LCD_print("Densidad");
    }
}

void nomograph_enabled_text(void)
{
  CLEAR_DISP;
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print("     Nomograph");
    LCD_position (LINE3);
    LCD_print("      Enabled");
  }
    else
    {
      LCD_print("    Capa Delgada");  // Capa Delgada Habilitado
      LCD_position (LINE3);
      LCD_print("     Habilitado");
    }
}


void enter_time_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Present");
    LCD_position(LINE2);      
    LCD_print("Time: hh:mm"); 
  }
    else
    {
      LCD_print("Ingrese la Hora"); //  Ingrese la Hora Actual   hh : mm 
      LCD_position(LINE2);      
      LCD_print("Actl: hh:mm"); 
    }
}
void am_pm_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  if(Features.language_f)
    { LCD_print("Select"); }
    else
      LCD_print("Seleccione");   //Seleccione 1. AM - PM     
  LCD_position(LINE2);  
  LCD_print("1. AM");       
  LCD_position(LINE3);
  LCD_print("2. PM");
}

void prma_text(void)
{
  CLEAR_DISP;
  
  if(Features.language_f)  
  {
    LCD_position(LINE1);
    LCD_print("1. Proctor");
    LCD_position(LINE2);
    LCD_print("2. MAX DENS");  
    if ( Features.soil_air_voids_on == 1 )
    {
     LCD_position(LINE3);
     LCD_print("3. Soil SG");    
    }
  }  
  else
  {
    LCD_position(LINE1);
    LCD_print("1. Proctor");
    LCD_position(LINE2);
    LCD_print("2. Densidad Máxima");  
    if ( Features.soil_air_voids_on == 1 )
    {
     LCD_position(LINE3);
     LCD_print("3. Tierra GS");    
    }
  }
  
}

void change_val_text(void)
{
  LCD_position(LINE2);
  if(Features.language_f)
     {LCD_print("Change Value?");}  // Cambiar Valor? 
    else
      LCD_print("Cambiar Valor?");
}

void get_new_offset_text(void)
{
  LCD_position(LINE2);
  if(Features.language_f)
     {LCD_print("Get New Offset?     ");}  
    else
     {LCD_print("Get New Offset?     ");}  
}


void use_val_text(void)
{
  LCD_position(LINE2);
  if(Features.language_f)
     {LCD_print("Use Value?");}  // Cambiar Valor? 
    else
     { LCD_print("Use Value?");}
}

void battery_shutdwn_text(void)
{
  CLEAR_DISP;
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print("    Battery Low");
    LCD_position (LINE3);
    LCD_print("  Shutdown: 5 sec.");
  }
    else
    {
      LCD_print("    Bateria Baja");   // Batería Baja       Interrupción en XX segundos
      LCD_position (LINE3);
      LCD_print("Interrupcion: 5 seg.");
    }
}
void display_alk_warning(void)
{
  CLEAR_DISP;
  LCD_position (LINE1);
  if(Features.language_f)
  {
    LCD_print("  *** WARNING ***");
    LCD_position (LINE2);
    LCD_print("  Alkaline Battery  ");
    LCD_position (LINE3);
    LCD_print("      is  Low       ");
  }
    else
    {
      LCD_print(" *** ADVERTENCIA ***");  // *** ADVERTENCIA ***    Calibrador Demasiado Caliente    ¿Voltaje Bajo?
      LCD_position (LINE2);
      LCD_print("  Bateria Alcalina  ");    //Batería Baja       Interrupción en XX segundos
      LCD_position (LINE3);
      LCD_print("      es Baja       ");
    }
}

void warning_text(BYTE which_source)
{
  CLEAR_DISP;
  LCD_position (LINE2);
  if(Features.language_f)
  {
    LCD_print("  *** WARNING ***");
    LCD_position (LINE3);
    if(which_source==0)
      { LCD_print("   Gauge Too Hot");   }
    else 
      { LCD_print("    Low Voltage ");   }
  }
    else
    {
      LCD_print(" *** ADVERTENCIA ***");   //*** ADVERTENCIA ***    Calibrador Demasiado Caliente    ¿Voltaje Bajo?
      LCD_position (LINE3);
      if(which_source==0)
      {
        LCD_print("Calibrador Demasiado");   
        LCD_position(LINE4);
        LCD_print("     Caliente!");
      }
      else
        LCD_print("    Voltaje Bajo");   
    }  
}
void gauge_temp_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE2);
  if(Features.language_f)
    { LCD_print("Gauge Temp ="); } // Temperatura del Densimetro 
    else
      LCD_print("Temperatura=");
}

void depth_voltage_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE2);
  
  if(Features.language_f)
  { 
   LCD_print("DS Voltage ="); 
   LCD_position(LINE3);
   LCD_print("Depth      = "); 
  } // Temperatura del Densimetro 
   else
  { 
   LCD_print("DS Voltaje =");
  }  
}
   
void press_key_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE1);
  
  if(Features.language_f)
  { 
   LCD_print("   Press Any Key    "); 
   LCD_position(LINE2);
   LCD_print("    ESC to Exit    "); 
  } 
  else
  { 
    LCD_print("   Press Any Key    "); 
   LCD_position(LINE2);
   LCD_print("    ESC to Exit    "); 
  }  
   
  
}


void high_voltage_text(void)
{
  CLEAR_DISP;
  LCD_position(LINE2);
  if(Features.language_f)
   { LCD_print("High Voltage =");  }
    else
      LCD_print("Voltaje Alto =");  //Voltaje Alto
}
void shut_down_text_text(void)
{
  CURSOR_OFF;
  CLEAR_DISP;
  LCD_position (LINE2 + 6);
  if(Features.language_f)
    { LCD_print("Shutdown"); }
    else
      LCD_print(" Apagar");  // Apagar
}
void shutdown_inactivity_text_text(void)
{
  //LCD_init();
  CURSOR_OFF;
  CLEAR_DISP;
  LCD_position (LINE2 + 1);
  if(Features.language_f)
    { LCD_print("Idle Shutdown"); }
    else
      LCD_print(" Inactivo Apagar");  // Apagar
}

void enter_valid_text(BYTE which_source)
{
  CLEAR_DISP;
  LCD_position(LINE2);
  if(Features.language_f)
  {
    LCD_print("    Please Enter");
    LCD_position(LINE3);  
    LCD_print("     Valid ");
    if(which_source==0)
      { LCD_print("Date"); }
    else
      { LCD_print("Time"); }
  }
    else
    {
      LCD_print("   Favor Ingresar");   //Favor ingresar fecha y hora validos
      LCD_position(LINE3);  
      if(which_source==0)
        LCD_print(" Fecha y Validos");
      else 
        LCD_print(" Hora y Validos");
    }
  delay_ms(1000);
}
void enter_project_name_text(char *temp_str)
{
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Enter Project ");
    LCD_position(LINE2);
    LCD_print("Name: ");
  }
    else
    {
      LCD_print("Ingrese Nombre del ");   // Ingrese nombre del proyecto
      LCD_position(LINE2);
      LCD_print("Proyecto: ");
    }
  _LCD_PRINTF("%s",temp_str);
}

void project_name_text(char *temp_str)
{
  CLEAR_DISP;
  LCD_position(LINE2);
  if(Features.language_f)
    { LCD_print("    Project Name");   }
    else
      LCD_print("Nombre del Projecto");  // Nombre del Projecto
  LCD_position(LINE3);
  _LCD_PRINTF(  "    %s",temp_str);   
}
void station_mode_text()
{
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Station Name Mode");
    LCD_position(LINE2);
    LCD_print("1. Auto (sequential)");
    LCD_position(LINE3);
    LCD_print("2. Manual Entry"); 
  }
    else
    {
      LCD_print("Opc. Nombre Estacion");    // Opciones Nombre Estacion  1. Automatico (Secuencial)  2. Ingreso manual
      LCD_position(LINE2);
      LCD_print("1. Automatico");
      LCD_position(LINE3);
      LCD_print("2. Ingreso Manual"); 
    }
}
void station_start_text(char *temp_str)
{ 
  LCD_position(LINE1);
  if(Features.language_f)
  {
    LCD_print("Starting Station");
    LCD_position(LINE2);
    _LCD_PRINTF("Number: %s",temp_str); 
  }
    else
    {
      LCD_print("Iniciacion del");   //  Iniciacion del  Numero de Estacion
      LCD_position(LINE2);
      _LCD_PRINTF("Numero de Estacion: %s",temp_str); 
    }
}
void station_increment_text(uint16_t inc)
{ 
  LCD_position(LINE1);
  if(Features.language_f)
  {
    _LCD_PRINTF("Station # %u",inc);
    LCD_position(LINE2);
    LCD_print("Increments by 1");
    LCD_position(LINE3);
    LCD_print("For Each Reading");
  }
    else
    {
      _LCD_PRINTF("Estacion# %u",inc);   //Estacion #  Incrementar en 1 (uno) para cada lectura 
      LCD_position(LINE2);
      LCD_print("Encrementar en 1");
      LCD_position(LINE3);
      LCD_print("Para Cada Lectura");
    }
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



void count_text(BYTE source)
{ 
  if(Features.language_f)
  {
    switch(source)
    {
      case  0: LCD_print("M Count:"); break;
      case  1: LCD_print("D Count:"); break;
      case  2: LCD_print("    MCR:"); break;
      case  3: LCD_print("    DCR:"); break;
      case  4: LCD_print("    DT:");  break;
      case  5: LCD_print("    WD:");  break;
      case  6: LCD_print("  %%MAX:"); break;
      case  7: LCD_print("%%Voids:"); break;
      case  8: LCD_print("Moist:");  break;
      case  9: LCD_print("%%Moist:"); break;
      case 10: LCD_print("   DD:");   break;
      case 11: LCD_print("   %%PR:");  break;
      case 12: LCD_print("Soil %%AV:"); break;   
   }
  }
    else
    {
      switch(source)
      {
        case  0: LCD_print("H Cuenta:"); break;
        case  1: LCD_print("D Cuenta:"); break;
        case  2: LCD_print("     HCR:"); break;
        case  3: LCD_print("     DCR:"); break;
        case  4: LCD_print("      DT:");  break;
        case  5: LCD_print("    WD:");  break;
        case  6: LCD_print("   %%HA:"); break;
        case  7: LCD_print("%%Voids:"); break;
        case  8: LCD_print(" Humedad:");  break;
        case  9: LCD_print("%%Humedad:"); break;
        case 10: LCD_print("      DD:");   break;
        case 11: LCD_print("     %%PR:");  break;
        case 12: LCD_print(" Humedad:"); break;   
      }
    }
}

void stat_drift_count_text(BYTE source)
{
  if(Features.language_f)
  {
    switch(source)
    {     
      case  0: LCD_print("D%% Drift:  "); break;
      case  1: LCD_print("Dens. Avg: ");  break;
      case  2: LCD_print("M%% Drift:  "); break;
      case  3: LCD_print("Moist.AVG: ");  break;      
      case  4: LCD_print("Dens. R:   ");  break;
      case  5: LCD_print("Moist R:   ");  break;
    }
  }
    else
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








