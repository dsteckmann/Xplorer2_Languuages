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


CONST_LCDSTRING  mBlank[2]  =  {{ 0, "                    " },{ 0, "                    "} };   

//<ESC> to Exit
CONST_LCDSTRING  mESC_to_Exit[2]        =  {{ 10, "<ESC> to Exit"     }, { 10, "<ESC> para Salir"}      };       

//Press YES or NO
CONST_LCDSTRING  mPress_YES_or_NO[2]    =  {{ 10, "Press YES or NO"   }, { 10, "Presione SI/YES o NO"}  };

// <ENTER to Accept
CONST_LCDSTRING  mEnter_to_Accept[2]    =  {{ 10, "<ENTER> to Accept" }, { 10, "ENTER para Aceptar"}    };

// Press ENTER
CONST_LCDSTRING  mPressEnter[2]         =  {{ 10, "Press <ENTER>" }, { 10, "Presione <ENTER>"}};

//<YES> to Accept
CONST_LCDSTRING mYES_to_Accept[2]       =  {{ 10, "<YES> to Accept"    }, { 10, "YES/Si para Aceptar"}       };

//UP/DOWN for Next
CONST_LCDSTRING Up_Down_Next[2]        =  {{ 10, "UP/DOWN for Next" },  { 10, "Arriba/Abajo"}          };


//UP/DOWN to CHANGE
CONST_LCDSTRING Up_Down_Change[2]        =  {{ 10, "UP/DOWN to Change" },  { 10, "Arriba/Abajo"}          };

//Select #, ESC Exit
CONST_LCDSTRING SelectNumber[2]        =  {{ 10, "Select #, ESC Exit" },{ 10, "Sel #,ESC para Salir"}  };

//Press START to Test
CONST_LCDSTRING m_PressStart[]                = {{ 10, "Press START" }, { 10, "Presione <START>"} };


//<YES> to Continue
CONST_LCDSTRING m_Yes_to_Continue[]                = {{ 10, "<YES> to Continue" }, { 10, "<YES> para Continuar"} };

//
//
//UP/DOWN for Next
//Select #, ESC Exit
CONST_LCDSTRING_PTR s_up_down_select_text[4]    = { &mBlank[0],&mBlank[0],&Up_Down_Next[0],&SelectNumber[0] };

// <ENTER> to Select
CONST_LCDSTRING Enter_to_Select[2]    =  {{ 10, "<ENTER> to Select" }, { 10, "<ENTER> a Escoger"}      };

//
//  UP/DOWN to Change
//  <YES> to Accept
//  <ESC> Exit
CONST_LCDSTRING_PTR s_Up_Down_Change_Exit[4]    = { mBlank,Up_Down_Change,mYES_to_Accept,mESC_to_Exit };

//
//<ENTER> to Select
//  UP/DOWN for Next 
//  <ESC> Exit
CONST_LCDSTRING_PTR s_up_down_Enter_select_text[4]    = { &mBlank[0],&Enter_to_Select[0],&Up_Down_Next[0],&mESC_to_Exit[0] };


//Calibration Due!
//Last Calibration On
//
//<ESC> to Exit
CONST_LCDSTRING calib_due[2]           = {{ 10, "Calibration Due!" },    { 10, "Require Calibracion"} };
CONST_LCDSTRING last_calibration[2]    = {{ 10, "Last Calibration On" }, { 10, "Ultima cal. hecha en"}};
CONST_LCDSTRING_PTR s_Calibration_due[4]    = { &calib_due[0],&last_calibration[0],&mBlank[0],mESC_to_Exit };

//GAUGE READY  
CONST_LCDSTRING mGaugeReady[2]          = {{ 10, "GAUGE READY" },    { 10, "PREPARADO"} };

//
//High Voltage Test
// In Progess
//
CONST_LCDSTRING HighVoltageTest[2]          = {{ 10, "High Voltage Test" },    { 10, "Prueba de Alto Volt."} };
CONST_LCDSTRING InProgress[2]               = {{ 10, "In Progress" }, { 10, "En Progreso"}};
CONST_LCDSTRING_PTR s_HighVoltageTest[4]    = { mBlank,HighVoltageTest,InProgress,mBlank };

//Keypad Test
CONST_LCDSTRING KeyPadTest[2]           = {{ 10, "Keypad Test" },    { 10, "Prueba del Teclado"} };

//Tube Test
CONST_LCDSTRING TubeTest[2]           = {{ 10, "Tube Test" },    { 10, "Prueba de Tubos"} };

// 
// Self Test
// Passed
//
CONST_LCDSTRING SelfTest[]                  = {{ 10, "Self Test" },    { 10, "Auto Prueba"} };
CONST_LCDSTRING Passed[]                    = {{ 10, "Passed" }, { 10, "Aprobada"}};
CONST_LCDSTRING_PTR s_SelfTestPassedTest[ ] = { mBlank,SelfTest,Passed,mBlank };

// "Depth" must be 6 characters
//Depth:Safe
CONST_LCDSTRING DepthSafe[]                 = {{ 0, "Depth:Safe  " }, { 0, "Prof.:SEG.  "} };
//Depth:BS
CONST_LCDSTRING DepthBS[]                   = {{ 0, "Depth:BS    " }, { 0, "Prof.:RD    " } };
//Depth:None
CONST_LCDSTRING DepthNone[]                 = {{ 0, "Depth:None  " }, { 0, "Prof.:None  "} };
//Depth:
CONST_LCDSTRING Depth[]                     = {{ 0, "Depth:      " }, { 0, "Prof.:      "} };


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
CONST_LCDSTRING m_temp13[]   = {{0,"      M Count:"},{0,"      M Count:"}};
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


// M Count:
CONST_LCDSTRING m_M_Count[]   = {{0,"M Count:"},  {0,"H Cuenta:"}};

// D Count:
CONST_LCDSTRING m_D_Count[]   = {{0,"D Count:"},{0,"D Cuenta:"}};

//MCR:
CONST_LCDSTRING m_MCR[]       = {{0,"    MCR:"},{0,"     HCR:"}};

//DCR:
CONST_LCDSTRING m_DCR[]       = {{0,"    DCR:"},{0,"     DCR:"}};

//DT:
CONST_LCDSTRING m_DT[]        = {{0,"     DT:"},{0,"      DT:"}};

//WD:
CONST_LCDSTRING m_WD[]        = {{0,"     WD:"},{0,"    WD:"}};

//%MAX:
CONST_LCDSTRING m_per_max[]   = {{0,"   %MAX:"},{0,"    %HA:"}};

//%Voids:
CONST_LCDSTRING m_per_voids[] = {{0," %Voids:"},{0,"%Voids"}};

//Moist:
CONST_LCDSTRING m_Moist[]        = {{0,"Moist:"},{0,"Humedad:"}};

//%Moist:
CONST_LCDSTRING m_per_Moist[]   = {{0,"%Moist:"},{0,"%Humedad:"}};

// DD:
CONST_LCDSTRING m_DD[]          = {{0,"     DD:"},{0,"     DD:"}};

//%PR:
CONST_LCDSTRING m_per_proct[]  = {{0,"    %PR:"},{0,"     %PR:"}};

// Soil %AV
CONST_LCDSTRING m_soil_av[]     = {{0,"Soil %AV:"},{0,"Soil %AV:"}};





//
//
//
//
CONST_LCDSTRING m_line1[]   = {{10,""},  {10,""}};
CONST_LCDSTRING m_line2[]   = {{10,""},  {10,""}};
CONST_LCDSTRING m_line3[]   = {{10,""},  {10,""}};
CONST_LCDSTRING m_line4[]   = {{10,""},  {10,""}};
CONST_LCDSTRING_PTR s_twmp_txt[ ] = { mBlank,mBlank,mBlank,mBlank};