#ifndef  SEDHOM_DISPLAY_SETTING_H_
#define  SEDHOM_DISPLAY_SETTING_H_
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//                                       write Basic shapes in here and change heder file
//============================================================================================================================================
// I use functions like
// 1-> var = map(var,x0,y0,x1,y1);
// 2-> var = constrain(var,x,y);
// 3-> var = sqrt(x);
// 4-> sizeof(var);
// 5-> pinMode(pin,mode);
// 6-> digitalWrite(pin,value);
//*************************************************************************************************
// include you lib driver here for TFT display
//*************************************************************************************************
////////////////////////////////////////
#include <Adafruit_GFX.h>   
#include <SPI.h>
#include <SD.h>
///////////////////////////////////////
// #include <UTFTGLUE.h>    
#include <MCUFRIEND_kbv.h>
// #include <Adafruit_TFTLCD.h>      
///////////////////////////////////////
#include <TouchScreen.h>
//////////////////////////////////////
#include <QRCodeGFX.h>
//////////////////////////////////////
// SEDHOMs lib
#include "SEDHOM_Colors.h"
#include "SEDHOM_Display_Fonts.h"
#include "SEDHOM_Arabic_Font.h"
//============================================================================================================================================
//*************************************************************************************************
// define your object for you Display here but you should name Display Like a do  
//*************************************************************************************************
// static UTFTGLUE Display(0,A2,A1,A3,A4,A0); 
MCUFRIEND_kbv Display;
#define init_Display_variable()      extern MCUFRIEND_kbv Display;
// #define LCD_CS A3 // Chip Select goes to Analog 3
// #define LCD_CD A2 // Command/Data goes to Analog 2
// #define LCD_WR A1 // LCD Write goes to Analog 1
// #define LCD_RD A0 // LCD Read goes to Analog 0
// #define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin
// static Adafruit_TFTLCD Display(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
///////////////////////////////////////////////////
// for Qrcode lib
#define init_Qr_code()  extern MCUFRIEND_kbv Display;static QRCodeGFX qrcode(Display);
//////////////////////////////////////////////////
// for touch
#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin
// touch screen dimentions
const int TS_LEFT = 954, TS_RT = 88, TS_TOP = 908, TS_BOT = 125;
#define MINPRESSURE 10
#define MAXPRESSURE 1000
///////////////////////////////////////////////////
//SD Card
#define SD_CS           10     //for uno
#define SD_Card_Class   SDClass
//============================================================================================================================================
//*************************************************************************************************
// define init_screen to prepare screen to draw shapes
//*************************************************************************************************
// #define init_Screen()                                    Display.InitLCD();
#define init_Screen(Rotate_)                                 Display.begin(Display.readID());Display.setRotation(Rotate_);
// #define init_Screen()                                    Display.begin(Display.readID());
//============================================================================================================================================
//*************************************************************************************************
// set Rotation of screen
//*************************************************************************************************
#define Rotate_screeen(x_)                                    Display.setRotation(x_); 
//============================================================================================================================================
//*************************************************************************************************
// define screen width and height (per pixels) like width = 320 && Height = 480
//*************************************************************************************************
#define Screen_height      480
#define Screen_width       320
//============================================================================================================================================
//*************************************************************************************************
// define Basic shapes for draw Icons & widgets & screens & windows and pages
//*************************************************************************************************
#define Fill_Rectangle(x_,y_,h_,w_,r_,color_)                  Display.fillRoundRect(x_,y_,h_,w_,r_,color_);
#define Draw_Rectangle(x_,y_,h_,w_,r_,color_)                  Display.drawRoundRect(x_,y_,h_,w_,r_,color_);
#define Fill_Circle(x_,y_,r_,color_)                           Display.fillCircle(x_,y_,r_,color_);
#define Draw_Circle(x_,y_,r_,color_)                           Display.drawCircle(x_,y_,r_,color_);
#define Fill_Triangle(x0_,y0_,x1_,y1_,x2_,y2_,color_)          Display.fillTriangle(x0_,y0_,x1_,y1_,x2_,y2_,color_);
#define Draw_Triangle(x0_,y0_,x1_,y1_,x2_,y2_,color_)          Display.drawTriangle(x0_,y0_,x1_,y1_,x2_,y2_,color_);
#define Draw_Line(x0_,y0_,x1_,y1_,color_)                      Display.drawLine(x0_,y0_,x1_,y1_,color_);
#define Draw_Pixel(x_,y_,color_)                               Display.drawPixel(x_,y_,color_);
//============================================================================================================================================
//*************************************************************************************************
// define draw picture to display it on tft     
//*************************************************************************************************
#define Draw_RGB_Picture(x_,y_,h_,w_,pictur_array_)                        Display.drawRGBBitmap(x_, y_, pictur_array_, w_, h_);
#define Draw_Single_Color_Picture(x_,y_,h_,w_,color_,pictur_array_)        Display.drawBitmap(x_, y_, pictur_array_, w_, h_, color_);
//============================================================================================================================================
//*************************************************************************************************
// define draw string 
//*************************************************************************************************
#define Text_Normal(x_,y_,size_,color_,txt_)     Display.setCursor(x_,y_);Display.setTextSize(size_);Display.setTextColor(color_);Display.print(txt_);
#define Text(x_,y_,font_,color_,txt_)            Display.setCursor(x_,y_);Display.setFont(font_);Display.setTextColor(color_);Display.print(txt_);
#define Text_Add(str_)                           Display.print(str_);
// #define Text(x,y,font,color,txt)         Display.setCursor(x,y);Display.setFont(font);Display.setTextColor(color);Display.write(txt);
// #define Text(x,y,size,color,txt)         Display.setTextColor(color);Display.print(txt,x,y);
//============================================================================================================================================
//*************************************************************************************************
// fill all screen with color
//*************************************************************************************************
#define FillScreen(color_)                       Display.fillScreen(color_);
//============================================================================================================================================
//*************************************************************************************************
// set Display Color 
//*************************************************************************************************
#define Set_Color(r_,g_,b_)                      Display.color565(r_,g_,b_)
//*************************************************************************************************
// time to calc it
#define wait_time(time_)                       delay(time_);   
// #define wait_time(time_)                    _delay_ms(time_);   
#define millis_func()                          millis();   
#define milcros_func()                         micros();   
//============================================================================================================================================
//============================================================================================================================================
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#endif /*SEDHOM_DISPLAY_SETTING_H_*/








