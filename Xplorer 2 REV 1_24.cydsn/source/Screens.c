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
#include "screens.h"


/* --------------------------------------------------------------------- */
/************************* Reuseable Lines *******************************/
/* --------------------------------------------------------------------- */


CONST_LCDSTRING  mBlank[]  =  {{ 0, "                    " },{ 0, "                    "} };   

//<ESC> to Exit
CONST_LCDSTRING  mESC_to_Exit[]        =  {{ 10, "<ESC> to Exit"     }, { 10, "<ESC> para Salir"}      };       

//Press YES or NO
CONST_LCDSTRING  mPress_YES_or_NO[]    =  {{ 10, "Press YES or NO"   }, { 10, "Presione YES o NO"}  };

// <ENTER to Accept
CONST_LCDSTRING  mEnter_to_Accept[]    =  {{ 10, "<ENTER> to Accept" }, { 10, "<ENTER> para Aceptar"}    };

// Press ENTER
CONST_LCDSTRING  mPressEnter[]         =  {{ 10, "Press <ENTER>" }, { 10, "Presione <ENTER>"}};

//<YES> to Accept
CONST_LCDSTRING mYES_to_Accept[]       =  {{ 10, "<YES> to Accept"    }, { 10, "YES/Si para Aceptar"}       };

//UP/DOWN for Next
CONST_LCDSTRING Up_Down_Next[]        =  {{ 10, "UP/DOWN for Next" },  { 10, "Arriba/Abajo"}          };


//UP/DOWN to CHANGE
CONST_LCDSTRING Up_Down_Change[]        =  {{ 10, "UP/DOWN to Change" },  { 10, "Arriba/Abajo"}          };

//Select #, ESC Exit
CONST_LCDSTRING SelectNumber[]        =  {{ 10, "Select #, ESC Exit" },{ 10, "Sel #,ESC para Salir"}  };

//Select #
CONST_LCDSTRING m_Select[]        =  {{ 10, "Select #" },{ 10, "Sel #"}  };

//Press START to Test
CONST_LCDSTRING m_PressStart[]                = {{ 10, "Press START" }, { 10, "Presione <START>"} };


//<YES> to Continue
CONST_LCDSTRING m_Yes_to_Continue[]                = {{ 10, "<YES> to Continue" }, { 10, "<YES> para Continuar"} };

//
//
//UP/DOWN for Next
//Select #, ESC Exit
CONST_LCDSTRING_PTR s_up_down_select_text[]    = { &mBlank[0],&mBlank[0],&Up_Down_Next[0],&SelectNumber[0] };

// <ENTER> to Select
CONST_LCDSTRING Enter_to_Select[]    =  {{ 10, "<ENTER> to Select" }, { 10, "<ENTER> a Escoger"}      };

//
//  UP/DOWN to Change
//  <YES> to Accept
//  <ESC> Exit
CONST_LCDSTRING_PTR s_Up_Down_Change_Exit[]    = { mBlank,Up_Down_Change,mYES_to_Accept,mESC_to_Exit };

//
//<ENTER> to Select
//  UP/DOWN for Next 
//  <ESC> Exit
CONST_LCDSTRING_PTR s_up_down_Enter_select_text[]    = { &mBlank[0],&Enter_to_Select[0],&Up_Down_Next[0],&mESC_to_Exit[0] };


//Calibration Due!
//Last Calibration On
//
//<ESC> to Exit
CONST_LCDSTRING calib_due[]           = {{ 10, "Calibration Due!" },    { 10, "Require Calibracion"} };
CONST_LCDSTRING last_calibration[]    = {{ 10, "Last Calibration On" }, { 10, "Ultima cal. hecha en"}};
CONST_LCDSTRING_PTR s_Calibration_due[]    = { &calib_due[0],&last_calibration[0],&mBlank[0],mESC_to_Exit };

//GAUGE READY  
CONST_LCDSTRING mGaugeReady[]          = {{ 10, "GAUGE READY" },    { 10, "PREPARADO"} };

//
//High Voltage Test
// In Progess
//
CONST_LCDSTRING HighVoltageTest[]          = {{ 10, "High Voltage Test" },    { 10, "Prueba de Alto Volt."} };
CONST_LCDSTRING InProgress[]               = {{ 10, "In Progress" }, { 10, "En Progreso"}};
CONST_LCDSTRING_PTR s_HighVoltageTest[]    = { mBlank,HighVoltageTest,InProgress,mBlank };

//Keypad Test
CONST_LCDSTRING KeyPadTest[]           = {{ 10, "Keypad Test" },    { 10, "Prueba del Teclado"} };

//Tube Test
CONST_LCDSTRING TubeTest[]           = {{ 10, "Tube Test" },    { 10, "Prueba de Tubos"} };

// 
// Self Test
// Passed
//
CONST_LCDSTRING SelfTest[]                  = {{ 10, "Self Test" },    { 10, "Auto Prueba"} };
CONST_LCDSTRING Passed[]                    = {{ 10, "Passed" }, { 10, "Aprobada"}};
CONST_LCDSTRING_PTR s_SelfTestPassedTest[ ] = { mBlank,SelfTest,Passed,mBlank };

// "Depth" must be 6 characters
//Depth:Safe
CONST_LCDSTRING m_DepthSafe[]                 = {{ 0, "Depth:Safe" }, { 0, "Prof.:SEG."} };
//Depth:BS
CONST_LCDSTRING m_DepthBS[]                   = {{ 0, "Depth:BS" }, { 0, "Prof.:RD" } };
//Depth:None
CONST_LCDSTRING m_DepthNone[]                 = {{ 0, "Depth:None" }, { 0, "Prof.:None"} };

//Depth:
CONST_LCDSTRING m_Depth[]                     = {{ 0, "Depth:" }, { 0, "Prof.:"} };


//Keypad:PASS
CONST_LCDSTRING KeypadPass[]                = {{ 0, "Keypad:PASS" }, { 0, "Teclado:PASADO"} };
//Keypad:FAIL
CONST_LCDSTRING KeypadFAIL[]                = {{ 0, "Keypad:FAIL" }, { 0, "Teclado:FALLADO"} };

//TEMP:PASS
CONST_LCDSTRING TempPass[]                = {{ 0, "Temp.:PASS" }, { 0, "Temp.:PASADO"} };
//TEMP:FAIL
CONST_LCDSTRING TempFAIL[]                = {{ 0, "Temp.:FAIL" }, { 0, "Temp.:FALLADO"} };


//Press START to Test
CONST_LCDSTRING m_PressStartToTest[]                = {{ 10, "Press START to Test" }, { 10, "Presione <START>"} };

//RECHARGE BATTERY
CONST_LCDSTRING m_RechargeBattery[]                = {{ 10, "RECHARGE BATTERY" }, { 10, "Recargar la Bateria"} };

//Reading # 
CONST_LCDSTRING m_ReadingNumber[]                = {{ 10, "Reading # " }, { 10, "Lectura # "} };


//FAIL
CONST_LCDSTRING m_FAIL[]                = {{ 0, "FAIL" }, { 0, "FALLADO"} };

//PASS
CONST_LCDSTRING m_PASS[]                = {{ 0, "PASS" }, { 0, "PASADO"} };

//Take New Standard Count?
CONST_LCDSTRING m_TakeNewStdCont[]       = {{10,"Take New Std Count?"}, {10,"Nueva Cuenta Std?"}};

//Use New STD Count?
CONST_LCDSTRING m_UseNewStdCont[]       = {{10,"Use New STD Count?"}, {10,"Use Nueva Cuent Std?"}};

//DS (Density Standard Count)
//MS (Moisture Standard Count)


//Place Gauge on 
//Standard Block 
//in SAFE Position
//Press START
CONST_LCDSTRING m_PlaceGauge[]       = {{10,"Place Gauge on"},{10,"Coloque el Equipo en"}};
CONST_LCDSTRING m_StdBlock[]         = {{10,"Standard Block"},{10,"el Bloque Standard"}};
CONST_LCDSTRING m_Position[]         = {{10,"in SAFE Position"},{10,"en Posicion se Segur"}};
CONST_LCDSTRING_PTR s_PlaceGaugeOnStdBLock[ ] = { m_PlaceGauge,m_StdBlock,m_Position,m_PressStart };



//Depth not in SAFE
//Position
//
//
CONST_LCDSTRING m_DepthNotinSafe[]  = {{10,"Depth not at Safe"},{10,"Profundidad no en la"}};
CONST_LCDSTRING Position[]           = {{10,"Position"},{10,"Posicion de Segura"}};
CONST_LCDSTRING_PTR s_DepthNotInSafePos[ ] = { m_DepthNotinSafe,Position,mBlank,mBlank }; 

//Standard Count
CONST_LCDSTRING mStandardCount[] = {{10,"Standard Count"},{10,"Conteo Estandar"}};

// display for the main menu
//1. Recall
//2. Offset 
//3. Auto Scroll
//4. Backlight
//5. Stat Test
//6. Drift Test
//7. GPS
//8. Autp Depth
//9. Review STD cnts.
//10. Select Language
//11. Set Units
//13. Serial Number
//14. Date/Time
//15. Buzzer/Alarm
//16. Special Cal.
//17. Nomograph
//18. Cal. Constants
//19. Soil Air Voids
//20. Diagnostic Test
CONST_LCDSTRING M1[]  = {{0,"1. Recall           "},{0,"1. Recordar          "}};
CONST_LCDSTRING M2[]  = {{0,"2. Offset           "},{0,"2. Compensacion      "}};
CONST_LCDSTRING M3[]  = {{0,"3. Auto Scroll      "},{0,"3. Voluta Auto       "}};
CONST_LCDSTRING M4[]  = {{0,"4. Backlight        "},{0,"4. Iluninacion LCD   "}};
CONST_LCDSTRING M5[]  = {{0,"5. Stat Test        "},{0,"5. Prueba estadist.  "}};
CONST_LCDSTRING M6[]  = {{0,"6. Drift Test       "},{0,"6. Prueba desviacion "}};
CONST_LCDSTRING M7[]  = {{0,"7. GPS              "},{0,"7. GPS               "}};
CONST_LCDSTRING M8[]  = {{0,"8. Auto Depth       "},{0,"8. Profundidad Auto  "}};
CONST_LCDSTRING M9[]  = {{0,"9. Review STD cnts. "},{0,"9. Revisar STD Cnts  "}};
CONST_LCDSTRING MP10[] = {{0,"10. Select Language "},{0,"10. Lengua          "}};
CONST_LCDSTRING MP11[] = {{0,"11. Set Units       "},{0,"11. Unidades        "}};
CONST_LCDSTRING MP12[] = {{0,"12. Standard Mode   "},{0,"12. Modo AVG del STD"}};
CONST_LCDSTRING MP13[] = {{0,"13. Serial Number   "},{0,"13. Numero de Serie "}};
CONST_LCDSTRING MP14[] = {{0,"14. Date/Time       "},{0,"14. Fecha y Hora    "}};
CONST_LCDSTRING MP15[] = {{0,"15. Buzzer/Alarm    "},{0,"15. Alarma En. / Ap."}};
CONST_LCDSTRING MP16[] = {{0,"16. Special Cal.    "},{0,"16. Calib. Especial "}};
CONST_LCDSTRING MP17[] = {{0,"17. Nomograph       "},{0,"17. Nomograph       "}};
CONST_LCDSTRING MP18[] = {{0,"18. Cal. Constants  "},{0,"18. Const. de Calib."}};
CONST_LCDSTRING MP19[] = {{0,"19. Soil Air Voids  "},{0,"19. Tierra Aire Nulo"}};
CONST_LCDSTRING MP20[] = {{0,"20. Diagnostic Test "},{0,"20. Auto Diagnostico"}};




//"Incorrect BLE"
//"Module Firmware"
//"The MyGauge App"
//"may not work!"
CONST_LCDSTRING  mIncorrectBLE_1[]  = {{10,"Incorrect BLE"},  {10,"Incorrect BLE"}};
CONST_LCDSTRING  mIncorrectBLE_2[]  = {{10,"Module Firmware"},{10,"Module Firmware"}};
CONST_LCDSTRING  mIncorrectBLE_3[]  = {{10,"The MyGauge App"},{10,"The MyGauge App"}};
CONST_LCDSTRING  mIncorrectBLE_4[]  = {{10,"may not work!"},  {10,"may not work!"}};
CONST_LCDSTRING_PTR s_IncorrectBLE[4] = { mIncorrectBLE_1,mIncorrectBLE_2,mIncorrectBLE_3,mIncorrectBLE_4 };      

//Count Time
CONST_LCDSTRING mCountTime[] = {{0,"Count Time:"}, {0,"Tiempo Cont:"}};


//1. Send Data to USB
//2. Print Data
//
//Select #, ESC Exit
CONST_LCDSTRING sendDataUSB[]  = {{10,"1. Send Data to USB"},{10,"1. Trans. Info al USB"}};
CONST_LCDSTRING   printData[]  = {{10,"2. Print Data"},{10,"2. Imprimir Info."}};
CONST_LCDSTRING_PTR s_printMenuDisplay[ ] = { sendDataUSB,printData,mBlank,SelectNumber };

//Write Data to USB
//1. Write All Data
//2. Write One Project
// <ESC> to Exit
CONST_LCDSTRING writeDataToUSB[]   = {{10,"Write Data to USB"},{10,"Escriba Datos a USB"}};
CONST_LCDSTRING writeAllDataUSB[]  = {{10,"1. Write All Data"},{10,"1. Toda la Info."}};
CONST_LCDSTRING writeOneProj[]     = {{10,"2. Write One Project"},{10,"2. Un Proyecto"}};
CONST_LCDSTRING_PTR s_writeUSB_text[ ] = { writeDataToUSB,writeAllDataUSB,writeOneProj,mESC_to_Exit};

//Insert External
//Drive in USB Port
//
// Press ENTER
CONST_LCDSTRING insertExternal_1[]   = {{10,"Insert External"},  {10,"Conecte el Disposit-"}};
CONST_LCDSTRING insertExternal_2[]   = {{10,"Drive in USB Port"},{10,"ivo de Memoria"}};
CONST_LCDSTRING insertExternal_3[]   = {{10,"                 "},{10,"Externa al USB."}} ;
CONST_LCDSTRING_PTR s_insertExternalUSB_text[ ] = { insertExternal_1,insertExternal_2,insertExternal_3,mPressEnter};

//
//   Writing Data
//   to USB Drive
//
CONST_LCDSTRING writingData_1[]   = {{10,"Writing Data"},  {10,"Escribiendo la"}};
CONST_LCDSTRING writingData_2[]   = {{10,"to USB Drive"},{10,"Informacion al USB"}};
CONST_LCDSTRING_PTR s_writingDataUSB_text[ ] = { mBlank,writingData_1,writingData_2,mBlank};

//
//   No USB Device
//   Detected
//
CONST_LCDSTRING noUSB_1[]   = {{10,"No USB Device"},  {10,"No se Detecta"}};
CONST_LCDSTRING noUSB_2[]   = {{10,"Detected"},{10,"USB"}};
CONST_LCDSTRING_PTR s_noUSBDeviceDetected[ ] = { mBlank,noUSB_1,noUSB_2,mBlank};


//
//   Data Download
//   Complete
//
CONST_LCDSTRING DataDownload_1[]   = {{10,"Data Download"},  {10,"Descarga de"}};
CONST_LCDSTRING DataDownload_2[]   = {{10,"Complete"},{10,"Informacion Completa"}};
CONST_LCDSTRING_PTR s_DataDownloadComplete[ ] = { mBlank,DataDownload_1,DataDownload_2,mBlank};


//
//   No Projects
//    Stored
//
CONST_LCDSTRING noProjects_1[]   = {{10,"No Projects"},  {10,"No Hay Proyectos"}};
CONST_LCDSTRING noProjects_2[]   = {{10,"Stored"},{10,"En la Memoria"}};
CONST_LCDSTRING_PTR snoProjectsStored[ ] = { mBlank,noProjects_1,noProjects_2,mBlank};




//  Press START for   
//  30 s. Tube Test     
//  mBlank    
//  Press ESC to Exit 
CONST_LCDSTRING m_temp10[]   = {{10,"Press START for"},  {10,"Press START for"}};
CONST_LCDSTRING m_temp11[]   = {{10,"0 s. Tube Test"},{10,"0 s. Tube Test"}};
CONST_LCDSTRING_PTR s_count_test_txt[ ] = { m_temp10,m_temp11,mBlank,mESC_to_Exit};


//mBlank
//Lights are on      
//mBlank    
//mBlank
CONST_LCDSTRING m_temp12[]   = {{10,"Lights are on"},  {10,"Lights are on"}};
CONST_LCDSTRING_PTR s_lights_are_on_txt[ ] = { mBlank,m_temp12,mBlank,mBlank};



//      M Count:
// Combo DCount:   
//Single DCount:    
//Press ESC to Exit
CONST_LCDSTRING m_temp13[]   = {{0,"      M Count:"},{0,"     H Cuenta:"}};
CONST_LCDSTRING m_temp14[]   = {{0," Combo DCount:"},{0," Combo DCount:"}};
CONST_LCDSTRING m_temp15[]   = {{0,"Single DCount:"},{0,"Single DCount:"}};
CONST_LCDSTRING_PTR s_display_count_text[ ] = { m_temp13,m_temp14,m_temp15,mESC_to_Exit};


//     Press START   
// to Turn on Lights    
//    for 5 secs        
//Press ESC to Exit
CONST_LCDSTRING m_temp16[]   = {{10,"Press START"},  {10,"Press START"}};
CONST_LCDSTRING m_temp17[]   = {{10,"to Turn on Light"},{10,"to Turn on Light"}};
CONST_LCDSTRING m_temp18[]   = {{10,"for 5 secs"},{10,"for 5 secs"}};
CONST_LCDSTRING_PTR s_light_test_txt[ ] = { m_temp16,m_temp17,m_temp18,mESC_to_Exit};


//TEST IN PROCESS
//Keep Pressing OFF   
//mBlank    
//Press ESC to Exit
CONST_LCDSTRING m_temp19[]   = {{10,"TEST IN PROCESS"},  {10,"TEST IN PROCESS"}};
CONST_LCDSTRING m_temp20[]   = {{10,"Keep Pressing OFF "},{10,"Keep Pressing OFF "}};
CONST_LCDSTRING_PTR s_press_off_txt[ ] = { m_temp19,m_temp20,mBlank,mESC_to_Exit};


//Hold OFF Key Down
//for 25secs   
//mBlank    
///Press ESC to Exit
CONST_LCDSTRING m_temp21[]   = {{10,"Hold OFF Key Down"},  {10,"Hold OFF Key Down"}};
CONST_LCDSTRING m_temp22[]   = {{10,"for 25secs"},{10,"for 25secs"}};
CONST_LCDSTRING_PTR s_shut_down_txt[ ] = { m_temp21,m_temp22,mBlank,mESC_to_Exit};

//1. English
//2. Spanish   
//mBlank    
//mBlank
CONST_LCDSTRING m_temp23[]   = {{0,"1. English"},{0,"1. Ingles"}};
CONST_LCDSTRING m_temp24[]   = {{0,"2. Spanish"},{0,"2. Spanish"}};
CONST_LCDSTRING_PTR s_select_language_text[ ] = { m_temp23,m_temp24,mBlank,mBlank};

//mBlank   
//Serial Port
//Activated
//mBlank
CONST_LCDSTRING m_temp25[]   = {{10,"Serial Port"},  {10,"Conexion de"}};
CONST_LCDSTRING m_temp26[]   = {{10,"Activated"},{10,"Transferencia"}};
CONST_LCDSTRING m_temp27[]    = {{10," "},{10,"Activada"}};
CONST_LCDSTRING_PTR s_serial_port_text[ ] = { mBlank,m_temp25,m_temp27,mBlank};


//Enter Station
//Name:
//YES to Accept
//ESC to Exit
CONST_LCDSTRING m_temp28[]   = {{10,"Enter Station"},  {10,"Entre Nombre de la"}};
CONST_LCDSTRING m_temp29[]   = {{0,"   Name:"},  {0,"Estacion:"}};
CONST_LCDSTRING_PTR s_enter_station_name_text[ ] = { m_temp28,m_temp29,mYES_to_Accept,mESC_to_Exit};



//
//Print Data
//Complete
//

CONST_LCDSTRING m_printdata[]   = {{0,"Print Data"},  {10,"Imprima"}};
CONST_LCDSTRING m_temp31[]   = {{0,"Complete"},  {10,"completa"}};
CONST_LCDSTRING_PTR s_print_complete_text[ ] = { mBlank,m_printdata,m_temp31,mBlank};


//Print Data
//1. Print All Data
//2. Print One Project
// ESC to Exit
CONST_LCDSTRING m_temp32[]   = {{0,"1. Print All Data"},    {0,"1. Toda la Info."}};
CONST_LCDSTRING m_temp33[]   = {{0,"2. Print One Project"}, {0,"2. Un Proyecto"}};
CONST_LCDSTRING_PTR s_print_data_text[ ] = { m_printdata,m_temp32,m_temp33,mESC_to_Exit};


//NiCd Volt =
// Alk Volt =
//
// ESC to Exit
CONST_LCDSTRING m_temp34[]   = {{0,"NiCd Volt ="},  {0,"NiCd Volt ="}};
CONST_LCDSTRING m_temp35[]   = {{0," Alk Volt ="},  {0," Alk Volt ="}};
CONST_LCDSTRING_PTR s_batt_volt_text[ ] = { m_temp34,m_temp35,mBlank,mESC_to_Exit};


//Erase Project Data?
//
//YES to Continue
//ESC to Exit
CONST_LCDSTRING m_line36[]   = {{0,"Erase Project Data?"},  {0,"Borrar Informacion?"}};
CONST_LCDSTRING_PTR s_erase_project_data_text[ ] = { m_line36,mBlank,m_Yes_to_Continue,mESC_to_Exit};

//Press ENTER to
//Delete Data In
//Project:
//ESC to Exit
CONST_LCDSTRING m_line37[]  = {{0,"Press ENTER to"},  {0,"Press ENTER Para"}};
CONST_LCDSTRING m_line38[]  = {{0,"Delete Data In"},  {0,"Borrar Toda la Info."}};
CONST_LCDSTRING m_line39[]  = {{0,"Project: "},       {0,"Proyecto: "}};
CONST_LCDSTRING_PTR s_delete_project_text[ ] = { m_line37,m_line38,m_line39,mESC_to_Exit};


//
//All Data
//Erased
//
CONST_LCDSTRING m_line40[]   = {{10,"All Data"},  {10,"Toda la Informacion"}};
CONST_LCDSTRING m_line41[]   = {{10,"Erased"},  {10,"Ha Sido Borrada"}};
CONST_LCDSTRING_PTR s_all_data_erased_text[ ] = { mBlank,m_line40,m_line41,mBlank};


//Erase All Data
//From Memory?
//YES to Continue
//ESC to Exit
CONST_LCDSTRING m_line42[]   = {{10,"Erase All Data"},  {10,"Borrar Toda la Info."}};
CONST_LCDSTRING m_line43[]   = {{10,"From Memory?"},    {10,"en la Memoria?"}};
CONST_LCDSTRING_PTR s_erase_data_text[ ] = { m_line42,m_line43,m_Yes_to_Continue,mESC_to_Exit};



//Press ENTER to
//Delete All Data
//
//
CONST_LCDSTRING m_line44[]   = {{10,"Press ENTER to"},  {10,"Oprima Entrada para"}};
CONST_LCDSTRING m_line45[]   = {{10,"Delete All Data"},  {10,"Borrar Toda la"}};
CONST_LCDSTRING m_line46[]   = {{10," "},  {10,"Informacion."}};
CONST_LCDSTRING_PTR s_enter_to_delete_text[ ] = { m_line44,m_line45,m_line46,mBlank};


//Delete Data
//1. Delete All Data
//2. Delete One Proj.
//
CONST_LCDSTRING m_line47[]   = {{0,"Delete Data"},  {0,"Borrar la Info."}};
CONST_LCDSTRING m_line48[]   = {{0,"1. Delete All Data"},  {0,"1. Toda Informacion"}};
CONST_LCDSTRING m_line49[]   = {{0,"2. Delete One Proj."},  {0,"2. Un Projecto"}};
CONST_LCDSTRING_PTR s_delete_data_text[ ] = { m_line47,m_line48,m_line49,mBlank};


//
//No Data Stored
//
//
CONST_LCDSTRING m_no_stored_data[]   = {{10,"No Data Stored"},  {10,"no hay datos"}};
CONST_LCDSTRING m_almencendos[]   = {{10," "},  {10,"almacenados"}};
CONST_LCDSTRING_PTR s_no_stored_data[ ] = { mBlank,m_no_stored_data,m_almencendos,mBlank};


CONST_LCDSTRING m_SelectProject[]   = {{10,"Select Project"},  {0,"Seleccionar Proyecto"}};
CONST_LCDSTRING m_SelectStation[]   = {{10,"Select Station"},  {0,"Seleccionar Estacion"}};


//Project Limit
//Exceeded, Delete
//One or More Projects
//
CONST_LCDSTRING m_line50[]   = {{10,"Project Limit"},  {10,"Proyecto Limites"}};
CONST_LCDSTRING m_line51[]   = {{10,"Exceeded, Delete"},  {10,"Exceso de Proyectos,"}};
CONST_LCDSTRING m_line52[]   = {{10,"One or More Projects"},  {10,"Borrar Uno o Mas"}};
CONST_LCDSTRING m_line53[]   = {{10," "},  {10,"Proyectos."}};
CONST_LCDSTRING_PTR s_project_limit_text[ ] = { m_line50,m_line51,m_line52,m_line53};


//
//Enter Station Name
//Before Each Reading
//
CONST_LCDSTRING m_line54[]   = {{10,"Enter Station Name"},  {10,"Ingrese el Nombre de"}};
CONST_LCDSTRING m_line55[]   = {{10,"Before Each Reading"},  {10,"la Estacion Antes de"}};
CONST_LCDSTRING m_line56[]   = {{10," "},  {10,"Tomar Cada Lectura"}};
CONST_LCDSTRING_PTR s_station_name_text[ ] = { mBlank,m_line54,m_line55,m_line56};

// These lines are used to display the measurement results.
// The name of each result is abbreviated. The English meaning is given
// M Count:   English-Moisture Count
// D Count:   English-Density Count
// MCR:       English-Moisture Count Ratio
// DCR:       English-Density Count Ratio
// DT:        English-Top Density (nomograph mode)
// WD:        English-Wet Density
// %MAX:      English-Percent MAX density
// %Voids:    English-Percent Voids
// Moist:     English-Moisture Density
// DD:        English-Dry Density
// %PR:       English-Percent Proctor
// Soil %AV:  English-Percent Soil Air Voids

//0
// M Count:
CONST_LCDSTRING m_M_Count[]    = {{0,"M Count:"},  {0,"H Cuenta:"}};

//1
// D Count:
CONST_LCDSTRING m_D_Count[]    = {{0,"D Count:"},{0,"D Cuenta:"}};

//2
//MCR:
CONST_LCDSTRING m_MCR[]        = {{0,"    MCR:"},{0,"     HCR:"}};

//3
//DCR:
CONST_LCDSTRING m_DCR[]        = {{0,"    DCR:"},{0,"     DCR:"}};

//4
//DT:
CONST_LCDSTRING m_DT[]         = {{0,"     DT:"},{0,"      DT:"}};

//5
//WD:
CONST_LCDSTRING m_WD[]         = {{0,"     WD:"},{0,"    WD:"}};


//6
//%MAX:
CONST_LCDSTRING m_per_max[]    = {{0,"   %MAX:"},{0,"    %HA:"}};

//7
//%Voids:
CONST_LCDSTRING m_per_voids[]  = {{0," %Voids:"},{0,"%Voids"}};

//8
//Moist:
CONST_LCDSTRING m_Moist[]      = {{0,"Moist:"},{0,"Humedad:"}};

//9
//%Moist:
CONST_LCDSTRING m_per_Moist[]  = {{0,"%Moist:"},{0,"%Humedad:"}};

//10
// DD:
CONST_LCDSTRING m_DD[]         = {{0,"     DD:"},{0,"     DD:"}};

//11
//%PR:
CONST_LCDSTRING m_per_proct[]  = {{0,"    %PR:"},{0,"     %PR:"}};

//12
// Soil %AV
CONST_LCDSTRING m_soil_av[]    = {{0,"Soil %AV:"},{0,"Soil %AV:"}};



//Station # 
//Increments by 1
//For Each Reading
//
CONST_LCDSTRING m_line57[]   = {{10,"Station # "},  {10,"Estacion# "}};
CONST_LCDSTRING m_line58[]   = {{10,"Increments by 1"},  {10,"Encrementar en 1"}};
CONST_LCDSTRING m_line59[]   = {{10,"For Each Reading"},  {10,"Para Cada Lectura"}};
CONST_LCDSTRING_PTR s_station_increment[ ] = { m_line57,m_line58,m_line59,mBlank};



//Starting Station
//Number:
//YES to Accept
//ESC to Exit
CONST_LCDSTRING m_line60[]   = {{0,"Starting Station"},  {0,"Estacion de inicio"}};
CONST_LCDSTRING m_line61[]   = {{0,"Number:"},  {0,"Numero:"}};
CONST_LCDSTRING_PTR s_station_start[ ] = { m_line60,m_line61,mYES_to_Accept,mESC_to_Exit};


//Station Name Mode
//1. Auto (sequential)
//2. Manual Entry
//Select #, ESC Exit
CONST_LCDSTRING m_line62[]   = {{0,"Station Name Mode"},     {0,"Opc. Nombre Estacion"}};
CONST_LCDSTRING m_line63[]   = {{0,"1. Auto (sequential)"},  {0,"1. Automatico"}};
CONST_LCDSTRING m_line64[]   = {{0,"2. Manual Entry"},       {0,"2. Ingreso Manual"}};
CONST_LCDSTRING_PTR s_station_mode_text[ ] = { m_line62,m_line63,m_line64,SelectNumber};



//
//Project Name
//
//
CONST_LCDSTRING m_line65[]   = {{10,"Project Name"},  {10,"Nombre del Projecto"}};
CONST_LCDSTRING_PTR s_project_name[ ] = { mBlank,m_line65,mBlank,mBlank};



//Enter Project
//Name:
//YES to Accept
//ESC to Exit
CONST_LCDSTRING m_line66[]   = {{0,"Enter Project"},  {0,"Ingrese Nombre del"}};
CONST_LCDSTRING m_line67[]   = {{10,"Name:"},  {10,"Proyecto:"}};
CONST_LCDSTRING_PTR s_enter_project_name[ ] = { m_line66,m_line67,mYES_to_Accept,mESC_to_Exit};


//
//Please Enter
//Valid Date
//Valid Time
CONST_LCDSTRING m_please_enter[]   = {{10,"Please Enter"},  {10,"Favor Ingresar"}};
CONST_LCDSTRING m_line69[]   = {{10,"Valid Date"},  {10,"Fecha y Validos"}};
CONST_LCDSTRING m_line70[]   = {{10,"Valid Time"},  {10,"Hora y Validos"}};
CONST_LCDSTRING_PTR s_enter_valid_date[ ] = { mBlank,m_please_enter,m_line69,mBlank};
CONST_LCDSTRING_PTR s_enter_valid_time[ ] = { mBlank,m_please_enter,m_line70,mBlank};


//
//Idle Shutdown
//
//
CONST_LCDSTRING m_line71[]   = {{10,"Idle Shutdown"},  {10,"Inactivo Apagar"}};
CONST_LCDSTRING_PTR s_shutdown_inactivity[ ] = { mBlank,m_line71,mBlank,mBlank};


//
//Shutdown
//
//
CONST_LCDSTRING m_line72[]   = {{10,"Shutdown"},  {10,"Apagar"}};
CONST_LCDSTRING_PTR s_shutdown[ ] = { mBlank,m_line72,mBlank,mBlank};

//Press Any Key
//ESC to Exit
//
//
CONST_LCDSTRING m_press_any_key[]   = {{10,"Press Any Key"},  {10,"Press Any Key"}};
CONST_LCDSTRING_PTR s_press_key_text[ ] = { m_press_any_key,mESC_to_Exit,mBlank,mBlank};



//
//DS Voltage =
//Depth      =
//ESC_to_Exit
CONST_LCDSTRING m_DSVoltage[]   = {{0,"DS Voltage ="},  {0,"DS Voltaje ="}};
CONST_LCDSTRING m_deph[]   = {{0,"Depth      ="},  {0,"Depth      ="}};
CONST_LCDSTRING_PTR s_depth_voltage_text[ ] = { mBlank,m_DSVoltage,m_deph,mESC_to_Exit};


//
//Gauge Temp =
//
//ESC_to_Exit
CONST_LCDSTRING m_gauge_temp[]   = {{0,"Gauge Temp ="},  {0,"Temperatura="}};
CONST_LCDSTRING_PTR s_gauge_temp_text[ ] = { mBlank,m_gauge_temp,mBlank,mESC_to_Exit};


//
// *** WARNING ***
//Gauge Too Hot
//
CONST_LCDSTRING m_warning[]   = {{10," *** WARNING ***"},  {10,"*** ADVERTENCIA ***"}};
CONST_LCDSTRING m_tooHot[]   = {{10,"Gauge Too Hot"},  {10,"Calibrador Demasiado"}};
CONST_LCDSTRING m_caliente[]   = {{10," "},  {10,"Caliente!"}};
CONST_LCDSTRING_PTR s_warning_text[ ] = { mBlank,m_warning,m_tooHot,mBlank};


//*** WARNING ***
//Alkaline Battery
//is  Low
//
CONST_LCDSTRING m_alkaline[]   = {{10,"Alkaline Battery"},  {10,"Bateria Alcalin"}};
CONST_LCDSTRING m_islow[]      = {{10,"is  Low"},  {10,"es Baja"}};
CONST_LCDSTRING_PTR s_display_alk_warning[ ] = { m_warning,m_alkaline,m_islow,mBlank};



//1. Proctor
//2. MAX DENS
//3. Soil SG
//Select #, ESC Exit
CONST_LCDSTRING m_Proctor[]   = {{0,"1. Proctor"},  {0,"1. Proctor"}};
CONST_LCDSTRING m_MAXDENS[]   = {{0,"2. MAX DENS"}, {0,"2. Densidad Maxima"}};
CONST_LCDSTRING m_SoilSG[]   = {{0,"3. Soil SG"},  {0,"3. Tierra GS"}};
CONST_LCDSTRING_PTR s_prma_text[ ] = { m_Proctor,m_MAXDENS,m_SoilSG,mESC_to_Exit};


//
// Battery Low
// Shutdown: 5 sec.
//
CONST_LCDSTRING m_batterylow[]    = {{10,"Battery Low"},  {10,"Bateria Baja"}};
CONST_LCDSTRING m_shutdown[]      = {{10,"Shutdown: 5 sec."},  {10,"Interrupcion: 5 seg."}};
CONST_LCDSTRING_PTR s_battery_shutdwn_text[ ] = { mBlank,m_batterylow,m_shutdown,mBlank};

//Trench Offset:
CONST_LCDSTRING m_trench_offset[]   = {{0,"Trench Offset:"},  {0,"Zanja Compen:"}};

//
//Use Value?
//Press YES or NO
//ESC to Exit
CONST_LCDSTRING m_use_value[]   = {{0,"Use Value?"},  {0,"Cambiar Valor? "}};
CONST_LCDSTRING_PTR s_use_val_text[ ] = { mBlank,m_use_value,mPress_YES_or_NO,mESC_to_Exit};


//
//GET NEW OFFSET?
//Press YES or NO
//ESC to Exit
CONST_LCDSTRING m_get_new_offset[]   = {{0,"Get New Offset?"},  {0,"Get New Offset? "}};
CONST_LCDSTRING_PTR s_get_new_offset_text[ ] = { mBlank,m_get_new_offset,mPress_YES_or_NO,mESC_to_Exit};

//Depth Slope:
CONST_LCDSTRING m_depth_slope[]    = {{0,"Depth Slope:"},{0,"Depth Slope:"}};

//MAX:
CONST_LCDSTRING m_max[]    = {{0,"MAX:"},{0," HA:"}};

//PR:
//English - (Proctor)
CONST_LCDSTRING m_pr[]    = {{0,"PR:"},{0,"PR:"}};

//Shtdwn Time Hours:
CONST_LCDSTRING m_sht_dwn_time[]    = {{0,"Shtdwn Time Hours:"},{0,"Shtdwn Time Hours:"}};


//Cal Date
//English - (Calibration Date)
CONST_LCDSTRING m_cal_date[]    = {{0,"Cal Date:"},{0,"Cal Date:"}};


//Soil SG:
//English - (Specific Gravity)
CONST_LCDSTRING m_soil_sg[]    = {{0,"Soil SG"},{0,"Soil SG"}};


//
//Change Value?
//Press YES or NO
//ESC to Exit
CONST_LCDSTRING m_change_value[]   = {{0,"Change Value?"},  {0,"Cambiar Valor?"}};
CONST_LCDSTRING_PTR s_change_val_text[ ] = { mBlank,m_change_value,mPress_YES_or_NO,mESC_to_Exit};



//Select
//1. AM
//2. PM
//
CONST_LCDSTRING m_Select1[]   = {{10,"Select"},  {10,"Seleccione"}};
CONST_LCDSTRING m_AM[]   = {{0,"1. AM"},  {0,"1. AM"}};
CONST_LCDSTRING m_PM[]   = {{0,"2. PM"},  {0,"2. PM"}};
CONST_LCDSTRING_PTR s_am_pm_text[ ] = { m_Select1,m_AM,m_PM,mBlank};



//Enter Present
//Time: hh:mm
//YES to Accept
//ESC to Exit
CONST_LCDSTRING m_EnterPresent[]   = {{0,"Enter Present"},   {0,"Ingrese la Hora"}};
CONST_LCDSTRING m_Timehhmm[]       = {{0,"Time: hh:mm"},     {0,"Actl: hh:mm"}};
CONST_LCDSTRING_PTR s_enter_time_text[ ] = { m_EnterPresent,m_Timehhmm,mYES_to_Accept,mESC_to_Exit};


//
//Nomograph
//Enabled
//
CONST_LCDSTRING m_Nomograph[]   = {{10,"Nomograph"},  {10,"Capa Delgada"}};
CONST_LCDSTRING m_Enabled[]   = {{10,"Enabled"},   {10,"Habilitado"}};
CONST_LCDSTRING_PTR s_nomograph_enabled_text[ ] = { mBlank,m_Nomograph,m_Enabled,mBlank};



//Enter Bottom
//Density:
//Enter to Accept
//ESC to Exit
CONST_LCDSTRING m_enterbottom[]   = {{0,"Enter Bottom"},  {0,"Entre el Valor de la"}};
CONST_LCDSTRING m_density[]       = {{0,"Density:"},      {0,"Densidad"}};
CONST_LCDSTRING_PTR s_enter_bot_dense_text[ ] = { m_enterbottom,m_density,mEnter_to_Accept,mESC_to_Exit};



//Enter Material
//Thickness:
//Enter to Accept
//ESC to Exit
CONST_LCDSTRING m_enter_mat[]   = {{0,"Enter Material"},  {0,"Enter Material"}};
CONST_LCDSTRING m_thickness[]   = {{0,"Thickness:"},      {0,"Thickness:"}};
CONST_LCDSTRING_PTR s_enter_mat_thickness_text[ ] = { m_enter_mat,m_thickness,mEnter_to_Accept,mESC_to_Exit};


//Mat Thick=
//Bot Dens =
//Are Values OK?
//Press YES or NO
CONST_LCDSTRING m_MatThick[]      = {{0,"Mat Thick="},  {0,"Espesor Mat"}};
CONST_LCDSTRING m_BotDens2[]      = {{0,"Bot Dens ="},  {0,"Dens. Fondo"}};
CONST_LCDSTRING m_AreValuesOK[]   = {{0,"Are Values OK?"},  {0,"Valores Correctos?"}};
CONST_LCDSTRING_PTR s_nomograph_vals_text[ ] = { m_MatThick,m_BotDens2,m_AreValuesOK,mPress_YES_or_NO};

//Activate Saved
//Values?
//Press YES or NO
//ESC to Exit
CONST_LCDSTRING m_activate_saved[]   = {{10,"Activate Saved"},  {10,"Activar los Valore"}};
CONST_LCDSTRING m_values[]          = {{10,"Values?"},  {10,"Guardados?"}};
CONST_LCDSTRING_PTR s_activate_saved_vals_text[ ] = { m_activate_saved,m_values,mPress_YES_or_NO,mESC_to_Exit};


//Disable Nomograph
//Mode?
//Press YES or NO
//ESC to Exit
CONST_LCDSTRING m_disable_nomograph[]   = {{0,"Disable Nomograph"},  {0,"desactivar el modo"}};
CONST_LCDSTRING m_mode[]                = {{0,"Mode?"},              {0,"nomograma?"}};
CONST_LCDSTRING_PTR s_disable_nomograph_text[ ] = { m_disable_nomograph,m_mode,mPress_YES_or_NO,mESC_to_Exit};


//Enable Nomograph
//Mode?
//Press YES or NO
//ESC to Exit
CONST_LCDSTRING m_enable_nomograph[]   = {{0,"Enable Nomograph"},  {0,"Activar el modo"}};
CONST_LCDSTRING_PTR s_enable_nomograph_text[ ] = { m_enable_nomograph,m_mode,mPress_YES_or_NO,mESC_to_Exit};


//
//Special Calibration
//Enabled
//
CONST_LCDSTRING m_speccal[]     = {{10,"Special Calibration"},  {10,"Calibracion Especial"}};
CONST_LCDSTRING m_enabled[]   = {{10,"Enabled"},  {10,"Habilitada"}};
CONST_LCDSTRING_PTR s_speccal_enabled_text[ ] = { mBlank,m_speccal,m_enabled,mBlank};


//# of Counts:
//Depth:
//Press START to
//Begin Count
CONST_LCDSTRING m_num_counts[]   = {{0,"# of Counts:"},   {0,"# de Cuentas"}};
CONST_LCDSTRING m_depth[]        = {{0,"Depth:"},         {0,"Prof.:"}};
CONST_LCDSTRING m_pstart[]       = {{0,"Press START to"}, {0,"Precione Inciar Para"}};
CONST_LCDSTRING m_begin_count[]  = {{0,"Begin Count"},    {0,"Comensar a Contar"}};
CONST_LCDSTRING_PTR s_start_speccal_text[ ] = { m_num_counts,m_depth,m_pstart,m_begin_count};




//Enter Number:
//of Counts:
//Enter to Accept
//ESC to Exit
CONST_LCDSTRING m_enter_number[] = {{0,"Enter Number:"},  { 0,"Ingrese Numero de"}};
CONST_LCDSTRING m_counts[]       = {{0,"of Counts:"},     { 0,"de Cuentas:"}};
CONST_LCDSTRING_PTR s_enter_number_counts_text[ ] = { m_enter_number,m_counts,mEnter_to_Accept,mESC_to_Exit};


//
//Activate Special
//Calibration?
//Press YES or NO
CONST_LCDSTRING m_activateSpecial[]   = {{10,"Activate Special"},  {10,"Activar Calibracion"}};
CONST_LCDSTRING m_calibration[]   = {{10,"Calibration?"},  {10,"Especial?"}};
CONST_LCDSTRING_PTR s_activate_speccal_text[ ] = { mBlank,m_activateSpecial,m_calibration,mPress_YES_or_NO};


//Use Stored Count
//Data?
//Press YES or NO
//ESC to Exit
CONST_LCDSTRING m_UseStored[]   = {{10,"Use Stored Count"},  {10,"Usar las Cuentas"}};
CONST_LCDSTRING m_data[]   = {{10,"Data?"},  {10,"Data?"}};
CONST_LCDSTRING_PTR s_use_stored_count_text[ ] = { m_UseStored,m_data,mPress_YES_or_NO,mESC_to_Exit};


//Enter Value For
//
//Enter to Accept
//ESC to Exit

CONST_LCDSTRING m_EnterValue[]   = {{0,"Enter Value For"},  {0,"Entre el Valor de"}};

//******************************************************************************************
// These translations must have the same length
// B =
CONST_LCDSTRING m_BValue[]   = {{0,"B ="},  {10,"B ="}};
CONST_LCDSTRING_PTR s_BEnterValue[ ] = { m_EnterValue,m_BValue,mEnter_to_Accept,mESC_to_Exit};

// Density =
CONST_LCDSTRING m_Density[]   = {{0,"Density ="},  {10,"Densidad="}};
CONST_LCDSTRING_PTR s_DensityEnterValue[ ] = { m_EnterValue,m_Density,mEnter_to_Accept,mESC_to_Exit};

//Density Now?
CONST_LCDSTRING m_DenistyNow[]   = {{0,"Density Now?"},  {0,"Densidad Ahora?"}};
CONST_LCDSTRING_PTR s_DensityNowEnterValue[ ] = { m_EnterValue,m_DenistyNow,mEnter_to_Accept,mESC_to_Exit};


//Proctor:
CONST_LCDSTRING m_Proct[]   = {{0,"Proctor:"},  {0,"Proctor:"}};
CONST_LCDSTRING_PTR s_ProctEnterValue[ ] = { m_EnterValue,m_DenistyNow,mEnter_to_Accept,mESC_to_Exit};


//MAX DENS:
CONST_LCDSTRING m_MAXDen[]   = {{0,"MAX DENS:"},  {0,"MAX DENS:"}};
CONST_LCDSTRING_PTR s_MAXDensityEnterValue[ ] = { m_EnterValue,m_DenistyNow,mEnter_to_Accept,mESC_to_Exit};

//SOIL SG:
CONST_LCDSTRING m_sg[]   = {{0,"SOIL SG:"},  {0,"SOIL SG:"}};
CONST_LCDSTRING_PTR s_SGEnterValue[ ] = { m_EnterValue,m_DenistyNow,mEnter_to_Accept,mESC_to_Exit};

//SHT DWN (HOURS):
CONST_LCDSTRING m_shut[]   = {{0,"SHT DWN (HOURS):"},  {0,"SHT DWN (HOURS):"}};
CONST_LCDSTRING_PTR s_ShutDownHRSEnterValue[ ] = { m_EnterValue,m_DenistyNow,mEnter_to_Accept,mESC_to_Exit};

//Depth Slope:
CONST_LCDSTRING m_dslope[]   = {{0,"Depth Slope:"},  {0,"Depth Slope:"}};
CONST_LCDSTRING_PTR s_depthslopeEnterValue[ ] = { m_EnterValue,m_DenistyNow,mEnter_to_Accept,mESC_to_Exit};
//********************************************************************************



//Use Gauge to Derive 
//B Value?
//Press YES or NO
//ESC to Exit
CONST_LCDSTRING m_use_gauge[]   = {{10,"Use Gauge to Derive"},  {10,"Use el Equipo Para"}};
CONST_LCDSTRING m_bvalue[]   = {{10,"B Value?"},  {10,"Obtener el Valor B?"}};
CONST_LCDSTRING_PTR s_use_gauge_text[ ] = { m_use_gauge,m_bvalue,mPress_YES_or_NO,mESC_to_Exit};


//Values OK? YES/NO
CONST_LCDSTRING m_values_ok[]   = {{10,"Values OK? YES/NO"},  {10,"Valores OK? SI/NO"}};


//View Last Saved
//Spec Cal. Data?
//Press Yes or No
//ESC to Exit
CONST_LCDSTRING m_viewLast[]   = {{10,"View Last Saved"},  {10,"Vista de la Ultima"}};
CONST_LCDSTRING m_SpecCalData[]   = {{10,"Spec Cal. Data?"},  {10,"Cal. Esp Registrada?"}};
CONST_LCDSTRING_PTR s_view_last_speccal_text[ ] = { m_viewLast,m_SpecCalData,mPress_YES_or_NO,mESC_to_Exit};



//Reset Memory
//to Default?
//Press Yes or No
//ESC to Exit
CONST_LCDSTRING m_reset_mem[]   = {{10,"Reset Memory"},  {10,"Borrar Memoria"}};
CONST_LCDSTRING m_to_default[]   = {{10,"to Default?"},  {10,"a Inicio?"}};
CONST_LCDSTRING_PTR s_memory_reset_text[ ] = { m_reset_mem,m_to_default,mPress_YES_or_NO,mESC_to_Exit};

//Disable Special
//Calibration?
//Press Yes or No
//ESC to Exit
CONST_LCDSTRING m_dis_special[]   = {{10,"Disable Special"},  {10,"Deshabilitar Calib."}};
CONST_LCDSTRING m_cal[]   = {{10,"Calibration?"},  {10,"Especial?"}};
CONST_LCDSTRING_PTR s_disable_speccal_text[ ] = { m_dis_special,m_cal,mPress_YES_or_NO,mESC_to_Exit};

//Enable Special
//Calibration?
//Press Yes or No
//ESC to Exit
CONST_LCDSTRING m_en_special[]   = {{10,"Enable Special"},  {10,"Habilitar Calib."}};
CONST_LCDSTRING_PTR s_enable_speccal_text[ ] = { m_en_special,m_cal,mPress_YES_or_NO,mESC_to_Exit};

//MOISTURE CONST
CONST_LCDSTRING m_moist_const[]   = {{10,"MOISTURE CONST"},  {10,"CONSTANTE DE HUMEDAD"}};

//
//Access Code
//Incorrect
//
CONST_LCDSTRING m_access_code[]   = {{10,"Access Code"},  {10,"Codego de Acceso"}};
CONST_LCDSTRING m_incorrect[]   = {{10,"Incorrect"},  {10,"Incorrecto"}};
CONST_LCDSTRING_PTR s_access_number_incorrect_text[ ] = { mBlank,m_access_code,m_incorrect,mBlank};


// display for the cal menu
//0. Moist Consts
//1. Depth BS  
//2. Depth 2
//3. Depth 3
//4. Depth 4
//5. Depth 5
//6. Depth 6
//7. Depth 7
//8. Depth 8
//9. Depth 9
//10. Depth 10
//11. Depth 11
//12. Depth 12
//13. Calibration Date
//14. Calib Std Counts
CONST_LCDSTRING C0[]  = {{0,"0. Moist Consts"},{0,"0. Const. de Humedad"}};
CONST_LCDSTRING C1[]  = {{0,"1. Depth BS"},    {0,"1. Retro-Dispercion"}};
CONST_LCDSTRING C2[]  = {{0,"2. Depth 2"},     {0,"2. Profundidad # 2"}};
CONST_LCDSTRING C3[]  = {{0,"3. Depth 3"},     {0,"3. Profundidad # 2"}};
CONST_LCDSTRING C4[]  = {{0,"4. Depth 3"},     {0,"4. Profundidad # 2"}};
CONST_LCDSTRING C5[]  = {{0,"5. Depth 5"},     {0,"5. Profundidad # 2"}};
CONST_LCDSTRING C6[]  = {{0,"6. Depth 6"},     {0,"6. Profundidad # 2"}};
CONST_LCDSTRING C7[]  = {{0,"7. Depth 7"},     {0,"7. Profundidad # 2"}};
CONST_LCDSTRING C8[]  = {{0,"8. Depth 8"},     {0,"8. Profundidad # 2"}};
CONST_LCDSTRING C9[]  = {{0,"9. Depth 9"},     {0,"9. Profundidad # 2"}};
CONST_LCDSTRING C10[] = {{0,"10. Depth 10"},   {0,"10. Profundidad # 2"}};
CONST_LCDSTRING C11[] = {{0,"11. Depth 11"},   {0,"11. Profundidad # 2"}};
CONST_LCDSTRING C12[] = {{0,"12. Depth 12"},   {0,"12. Profundidad # 2"}};
CONST_LCDSTRING C13[] = {{0,"13. Calibration Date"},{0,"13.Fecha de Calib."}};
CONST_LCDSTRING C14[] = {{0,"14. Calib Std Counts"},{0,"14.Calib Est Cuenta"}};


//Enter Moisture Std
//Count:
//YES to Accept
//ESC to Exit
CONST_LCDSTRING m_moist_std[]   = {{0,"Enter Moisture Std"},  {0,"Ingrese Humedad. Est"}};
CONST_LCDSTRING m_count[]   = {{0,"Count:"},  {0,"Cuenta:"}};
CONST_LCDSTRING_PTR s_enter_cal_mois_std_text[ ] = { m_moist_std,m_count,mYES_to_Accept,mESC_to_Exit};

//Enter Density Std
//Count:
//YES to Accept
//ESC to Exit
CONST_LCDSTRING m_density_std[]   = {{0,"Enter Density Std"},  {0,"Ingrese Densidad Est"}};
CONST_LCDSTRING_PTR s_enter_cal_den_std_text[ ] = { m_density_std,m_count,mYES_to_Accept,mESC_to_Exit};


//Enter Access
//Number: 
//YES to Accept
//ESC to Exit
CONST_LCDSTRING m_enter_access[]   = {{0,"Enter Access"},  {0,"Ingrese el Codego de"}};
CONST_LCDSTRING m_numb[]           = {{0,"Number: "},     {0,"Acceso:"}};
CONST_LCDSTRING_PTR s_enter_access_number_text[ ] = { m_enter_access,m_numb,mYES_to_Accept,mESC_to_Exit};


//1. Density
//2. Moisture
//3. Trench
//Select #, ESC Exit
CONST_LCDSTRING m_dens1[]   = {{0,"1. Density"},    {0,"1. Densidad"}};
CONST_LCDSTRING m_moist2[]   = {{10,"2. Moisture"},  {0,"2. Humedad"}};
CONST_LCDSTRING m_Trench[]   = {{10,"3. Trench"},    {0,"3. Zanja"}};
CONST_LCDSTRING_PTR s_offsets_text[ ] = { m_dens1,m_moist2,m_Trench,SelectNumber};


//Thin Layer Enabled
//Place in BS Position
//
//Press Enter
CONST_LCDSTRING m_tl_enable[]   = {{10,"Thin Layer Enabled"},  {10,"Thin Layer Enabled"}};
CONST_LCDSTRING m_place_bs[]   = {{10,"Place in BS Position"},  {10,"Place in BS Position"}};
CONST_LCDSTRING_PTR s_place_in_bs_text[ ] = { m_tl_enable,m_place_bs,mBlank,mPressEnter};


//Avg Std Mode Enabled
CONST_LCDSTRING m_avg_stand_mode_enabled_text[]   = {{10,"Avg Std Mode Enabled"},  {10,"Media Modo Activar"}};


//%Soil Air Voids
//Disabled
//Want to Enable?
//Press YES or NO
CONST_LCDSTRING m_Soil_Air[]   = {{10,"%Soil Air Voids"},  {10,"%Tiearra Aire Nulo"}};
CONST_LCDSTRING m_Disabled[]   = {{10,"Disabled"},         {10,"Deshabilitado"}};
CONST_LCDSTRING m_WanttoEnable[]   = {{10,"Want to Enable?"},  {10,"desea habilitar?"}};
CONST_LCDSTRING_PTR s_SAV_disabled_text[ ] = { m_Soil_Air,m_Disabled,m_WanttoEnable,mPress_YES_or_NO};

//%Soil Air Voids
//Enabled
//Want to Disable?
//Press YES or NO
CONST_LCDSTRING m_WanttoDisable[]   = {{10,"Want to Disable?"},  {10,"desea desactivar?"}};
CONST_LCDSTRING_PTR s_SAV_enabled_text[ ] = { m_Soil_Air,m_Enabled,m_WanttoDisable,mPress_YES_or_NO};

//Decay Mode Enabled
CONST_LCDSTRING m_decay_mode_en[]   = {{10,"Decay Mode Enabled"},  {10,"Desint. Modo Activar"}};


//1. Average Mode
//2. Decay Mode
// 
////ESC to Exit
CONST_LCDSTRING m_AverageMode[]   = {{0,"1. Average Mode"}, {0,"1. Media Mod"}};
CONST_LCDSTRING m_DecayMode[]     = {{0,"2. Decay Mode"},   {0,"2. Desinteg. Mod"}};
CONST_LCDSTRING_PTR s_stand_mode_settings_text[ ] = { m_AverageMode,m_DecayMode,mBlank,mESC_to_Exit};

//No Data To Store
//Start
//New Measurement
//
// (English uses 3 lines, Spaniah needs 4 lines )
CONST_LCDSTRING m_noData[]   = {{10,"No Data To Store"}, {10,"No hay datos"}};
CONST_LCDSTRING m_start[]   = {{10,"Start"},            {10,"para almacenar"}};
CONST_LCDSTRING m_new_meas_1[]   = {{10,"New Measurement"},  {10,"Iniciar nueva medicion"}};
CONST_LCDSTRING m_new_meas_2[]   = {{10," "},                {10, "medicion"}};
CONST_LCDSTRING_PTR s_no_data_to_store_text[ ] = { m_noData,m_start,m_new_meas_1,m_new_meas_2};

//Error setting
//Clock
//Restart Gauge
//Press <ENTER>
CONST_LCDSTRING m_Error_setting[]   = {{10,"Error setting"},  {10,"Error al configurar"}};
CONST_LCDSTRING m_Clock[]           = {{10,"Clock"},          {10," el Reloj"}};
CONST_LCDSTRING m_Restart_Gauge[]   = {{10,"Restart Gauge"},  {10,"Reiniciar Medidor"}};
CONST_LCDSTRING_PTR s_clock_set_error_text[ ] = { m_Error_setting,m_Clock,m_Restart_Gauge,mPressEnter};


//Depth Strip Type
//1. Xplorer
//2. 3440
//Select #
//ESC to Exit
CONST_LCDSTRING m_DepthStripType[]   = {{10,"Depth Strip Type"},  {10,"Sensor de profund."}};
CONST_LCDSTRING m_Xplorer[]   = {{0,"1. Xplorer"},  {0,"1. Xplorer"}};
CONST_LCDSTRING m_3440[]      = {{0,"2. 3440"},     {0,"2. 3440"}};
CONST_LCDSTRING_PTR s_depth_strip_type[ ] = { m_DepthStripType,m_Xplorer,m_3440,m_Select,mESC_to_Exit};


// displine_e ( m_
//dispscrn_e ( s_
//
//
//
//
CONST_LCDSTRING m_line1[]   = {{10,""},  {10,""}};
CONST_LCDSTRING m_line2[]   = {{10,""},  {10,""}};
CONST_LCDSTRING m_line3[]   = {{10,""},  {10,""}};
CONST_LCDSTRING m_line4[]   = {{10,""},  {10,""}};
CONST_LCDSTRING_PTR s_twmp_txt[ ] = { mBlank,mBlank,mBlank,mBlank};