//============================================================================================================================================
#pragma once
//============================================================================================================================================
//============================================================================================================================================
// MCU Settings (Board Settings)
//============================================================================================================================================
// include Driver Lib
#include <Arduino.h>
// MCU 
#define API_MCU_Type_Name()                                   "Atmega328P"
#define API_MCU_Type_Details()                                "-> $S:16MHz $F:32KB (0.5KB bootloader)\n -> $R:2KB $EER:1KB $core:1"
#define API_Board_Type_Name()                                 "Arduino Uno"
#define API_Board_Type_Details()                              "-> $GPIO:14 digital I/O (6 PWM), 6 analog\n -> $USB:Type-B $P:5V"
// Timers
#define API_Micros_Function()                                  micros()   
// Pins
//>>>>> APIs
#define API_MCU_Pin_Direction(__pin__,__mode__)                pinMode(__pin__, __mode__)      
#define API_MCU_Pin_Read(__pin__)                              digitalRead(__pin__)      
#define API_MCU_Pin_Write(__pin__,__mode__)                    digitalWrite(__pin__, __mode__)      
#define API_MCU_Pin_Mode_INPUT                                 0x0      
#define API_MCU_Pin_Mode_OUTPUT                                0x1      
#define API_MCU_Pin_Mode_INPUT_PULLUP                          0x2      
#define API_MCU_Pin_Mode_INPUT_PULLDOWN                        0x2      
//============================================================================================================================================
// Display Settings
//============================================================================================================================================
// include Driver Lib
#include <MCUFRIEND_kbv.h>
// define APIs from driver
#define API_Driver_Class_Name                                    MCUFRIEND_kbv      
#define API_Display_Object_Name                                  SEDHOM_Display  
#define API_Driver_Parameters                                   
#define API_Make_New_Display                                     API_Driver_Class_Name  API_Display_Object_Name   API_Driver_Parameters
// Make Object of Display Driver to Pass APIs
API_Make_New_Display;
//>>>>> APIs
#define API_Init_Screen()                                        API_Display_Object_Name.begin(API_Display_Object_Name.readID());
#define API_Screen_height()                                      API_Display_Object_Name.height() 
#define API_Screen_width()                                       API_Display_Object_Name.width()
#define API_Start_Write()                                        API_Display_Object_Name.startWrite()
#define API_End_Write()                                          API_Display_Object_Name.endWrite()
#define API_Invert_Display(__state__)                            API_Display_Object_Name.invertDisplay(__state__)
#define API_Draw_Pixel(__x__,__y__,__color__)                    API_Display_Object_Name.drawPixel(__x__,__y__,__color__)
#define API_Write_Pixel(__x__,__y__,__color__)                   API_Display_Object_Name.writePixel(__x__,__y__,__color__)
#define API_Write_Fast_VLine(__x__,__y__,__h__,__color__)        API_Display_Object_Name.writeFastVLine(__x__,__y__,__h__,__color__)
#define API_Write_Fast_HLine(__x__,__y__,__w__,__color__)        API_Display_Object_Name.writeFastHLine(__x__,__y__,__w__,__color__)
#define API_Write_Fill_Rect(__x__,__y__,__w__,__h__,__color__)   API_Display_Object_Name.writeFillRect(__x__,__y__,__w__,__h__,__color__)
#define API_Draw_Fast_VLine(__x__,__y__,__h__,__color__)         API_Display_Object_Name.drawFastVLine(__x__,__y__,__h__,__color__)
#define API_Draw_Fast_HLine(__x__,__y__,__w__,__color__)         API_Display_Object_Name.drawFastHLine(__x__,__y__,__w__,__color__)
#define API_Fill_Rect(__x__,__y__,__w__,__h__,__color__)         API_Display_Object_Name.fillRect(__x__,__y__,__w__,__h__,__color__)
#define API_Fill_Screen(__color__)                               API_Display_Object_Name.fillScreen(__color__)
#define API_Set_Rotation(__r__)                                  API_Display_Object_Name.setRotation(__r__)
//============================================================================================================================================
// Touch Settings
//============================================================================================================================================
// include Driver Lib
#include <TouchScreen.h>
// Pins
#define Touch_Y_Positive_Pin                             A3  // Y+ : reads Y coordinate (analog)
#define Touch_X_Negative_Pin                             A2  // X- : reads X coordinate (analog)
#define Touch_Y_Negative_Pin                             9   // Y- : drive pin (digital)
#define Touch_X_Positive_Pin                             8   // X+ : drive pin (digital)  
// define APIs from driver
#define API_Touch_Driver_Class_Name                      TouchScreen
#define API_Touch_Point_Driver_Class_Name                TSPoint
#define API_Touch_Object_Name                            SEDHOM_Touch_Driver
#define API_Touch_Driver_Parameters                      (Touch_X_Positive_Pin, Touch_Y_Positive_Pin, Touch_X_Negative_Pin, Touch_Y_Negative_Pin, 300)
#define API_Make_New_Touch                               API_Touch_Driver_Class_Name  API_Touch_Object_Name  API_Touch_Driver_Parameters
// Make Object of Touch Driver to Pass APIs
API_Make_New_Touch;
//>>>>> APIs
#define API_Get_Touch_Point()                             API_Touch_Object_Name.getPoint()
#define API_Set_Touch_Pins_Setting()                      API_MCU_Pin_Direction(Touch_Y_Positive_Pin, API_MCU_Pin_Mode_OUTPUT);API_MCU_Pin_Direction(Touch_X_Negative_Pin, API_MCU_Pin_Mode_OUTPUT);API_MCU_Pin_Write(Touch_Y_Positive_Pin, 1);API_MCU_Pin_Write(Touch_X_Negative_Pin, 1);
// Calibration
#define API_Touch_X_Raw_Left_Edge()                       954
#define API_Touch_X_Raw_Right_Edge()                      88
#define API_Touch_Y_Raw_Top_Edge()                        908
#define API_Touch_Y_Raw_Bottom_Edge()                     125
#define API_Touch_Pressure_Min()                          10
#define API_Touch_Pressure_Max()                          1000
//============================================================================================================================================






