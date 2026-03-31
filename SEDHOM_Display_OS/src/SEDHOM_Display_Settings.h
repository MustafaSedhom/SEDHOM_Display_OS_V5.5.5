#ifndef  SEDHOM_DISPLAY_SETTING_H_
#define  SEDHOM_DISPLAY_SETTING_H_
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//                                       write Basic shapes in here and change heder file
//============================================================================================================================================
// I use functions like
// 1-> var = map(var,x0,y0,x1,y1);
// 2-> var = constrain(var,x,y);
// 3-> var = sqrt(x);
// 4-> sizeof(var); // in cPP and c we can use sizeof() to get the size of a variable or data type in bytes. It is a compile-time operator that returns the size of the operand in bytes. For example, sizeof(int) will return the size of an integer variable in bytes, which is typically 4 bytes on most platforms. Similarly, sizeof(var) will return the size of the variable var in bytes. This can be useful for memory management and understanding how much space a variable occupies in memory.

// 5-> pinMode(pin,mode);
// 6-> digitalWrite(pin,value);     // depends on mcu driver
// 6-> var = digitalRead(pin);
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
// #include <QRCodeGFX.h>
//////////////////////////////////////
#include <ArduinoJson.h>
//////////////////////////////////////
//============================================================================================================================================
//*************************************************************************************************
// define your object for you Display here but you should name Display Like a do  
//************************************************************************************************* 
MCUFRIEND_kbv Display;
// #define LCD_CS A3 // Chip Select goes to Analog 3
// #define LCD_CD A2 // Command/Data goes to Analog 2
// #define LCD_WR A1 // LCD Write goes to Analog 1
// #define LCD_RD A0 // LCD Read goes to Analog 0
// #define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin
// static Adafruit_TFTLCD Display(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
///////////////////////////////////////////////////
// for Qrcode lib
//////////////////////////////////////////////////
// for touch
#if defined(ESP32)
#define XM 34  
#define XP 32
#define YM 33
#define YP 35
#else
  #define YP A3  // must be an analog pin, use "An" notation!
  #define XM A2  // must be an analog pin, use "An" notation!
  #define YM 9   // can be a digital pin
  #define XP 8   // can be a digital pin
#endif
#define set_pins_for_touch()     pinMode(YP, OUTPUT);pinMode(XM, OUTPUT);digitalWrite(YP, HIGH);digitalWrite(XM, HIGH);
// touch screen dimensions
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
#define Rotate_screen(x_)                                    Display.setRotation(x_); 
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
// #define Draw_RGB_Picture(x_,y_,h_,w_,picture_array_)                        Display.drawRGBBitmap(x_, y_, picture_array_, w_, h_);
// #define Draw_Single_Color_Picture(x_,y_,h_,w_,color_,picture_array_)        Display.drawBitmap(x_, y_, picture_array_, w_, h_, color_);
//============================================================================================================================================
//*************************************************************************************************
// define draw string 
//*************************************************************************************************
// #define Text_Normal(x_,y_,size_,color_,txt_)     Display.setCursor(x_,y_);Display.setTextSize(size_);Display.setTextColor(color_);Display.print(txt_);
#define Text_Driver(x_,y_,font_,color_,txt_)            Display.setCursor(x_,y_);Display.setFont(font_);Display.setTextColor(color_);Display.print(txt_);
// #define Text_Add(str_)                           Display.print(str_);
// #define Text_C(x,y,font,color,txt)         Display.setCursor(x,y);Display.setFont(font);Display.setText_CColor(color);Display.write(txt);
// #define Text_C(x,y,size,color,txt)         Display.setText_CColor(color);Display.print(txt,x,y);
//============================================================================================================================================
//*************************************************************************************************
// fill all screen with color
//*************************************************************************************************
// #define FillScreen(color_)                       Display.fillScreen(color_);
//============================================================================================================================================
//*************************************************************************************************
// set Display Color 
//*************************************************************************************************
// #define Set_Color(r_,g_,b_)                      Display.color565(r_,g_,b_)
//*************************************************************************************************
// time to calc it
#define wait_time(time_)                        delay(time_);   
#define micros_func()                           micros();   
//============================================================================================================================================
// #if defined(ARDUINO)
//     #define OS_MICROS() micros()
// #elif defined(ESP32)
//     #define OS_MICROS() micros()
// #elif defined(STM32F1)
//     #define OS_MICROS() HAL_GetTick() * 1000UL
// #else
//     #error "Please define OS_MICROS() for your MCU!"
// #endif
// #include "Settings.h"

// add all functions to this file in future and add RTOS OS for this operating system and make it OS
// // Delay in milliseconds
// static void delay(uint32_t ms) {
//     uint32_t start = millis();
//     while ((millis() - start) < ms) {
//         // Optionally, add low-power or yield here
//     }
// }

// // Delay in microseconds
// static void delayMicroseconds(uint32_t us) {
//     uint32_t start = micros();
//     while ((micros() - start) < us) {
//         // Busy wait
//     }
// }

// // Square function
// template <typename T>
// inline T sqr(T value) {
//     return value * value;
// }
    // static long map(long x, long in_min, long in_max, long out_min, long out_max) {
    //     return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    // }

    // // Map function for float/double values
    // template <typename T>
    // static T map(T x, T in_min, T in_max, T out_min, T out_max) {
    //     return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    // }
// // Constrain integer values
// static long constrain(long x, long lower, long upper) {
//     if (x < lower) return lower;
//     if (x > upper) return upper;
//     return x;
// }

// // Constrain floating-point values
// template <typename T>
// static T constrain(T x, T lower, T upper) {
//     if (x < lower) return lower;
//     if (x > upper) return upper;
//     return x;
// }

// template <typename T>
// T sqrt_custom(T x) {
//     if (x <= 0) return 0;

//     T guess = x / 2;
//     for (int i = 0; i < 20; ++i) {
//         guess = 0.5 * (guess + x / guess);
//     }

//     return guess;
// }

// template <typename T>
// inline T abs_custom(T value) {
//     return (value < 0) ? -value : value;
// }

// template <typename T>
// T pow_custom(T base, int exp) {
//     T result = 1;
//     bool negative = (exp < 0);
//     if (negative) exp = -exp;

//     while (exp) {
//         if (exp & 1) result *= base;
//         base *= base;
//         exp >>= 1;
//     }

//     if (negative) return 1 / result;
//     return result;
// }

// uint8_t RGB_to_Gray(uint8_t R, uint8_t G, uint8_t B)
// {
//     return (R*77 + G*150 + B*29) >> 8;
// }

// Font structures for newer Adafruit_GFX (1.1 and later).
// Example fonts are included in 'Fonts' directory.
// To use a font in your Arduino sketch, #include the corresponding .h
// file and pass address of GFXfont struct to setFont().  Pass NULL to
// revert to 'classic' fixed-space bitmap font.

// #ifndef _GFXFONT_H_
// #define _GFXFONT_H_

// /// Font data stored PER GLYPH
// typedef struct {
//   uint16_t bitmapOffset; ///< Pointer into GFXfont->bitmap
//   uint8_t width;         ///< Bitmap dimensions in pixels
//   uint8_t height;        ///< Bitmap dimensions in pixels
//   uint8_t xAdvance;      ///< Distance to advance cursor (x axis)
//   int8_t xOffset;        ///< X dist from cursor pos to UL corner
//   int8_t yOffset;        ///< Y dist from cursor pos to UL corner
// } GFXglyph;

// /// Data stored for FONT AS A WHOLE
// typedef struct {
//   uint8_t *bitmap;  ///< Glyph bitmaps, concatenated
//   GFXglyph *glyph;  ///< Glyph array
//   uint16_t first;   ///< ASCII extents (first char)
//   uint16_t last;    ///< ASCII extents (last char)
//   uint8_t yAdvance; ///< Newline distance (y axis)
// } GFXfont;

// #endif // _GFXFONT_H_

// #include <Arduino.h>

// typedef struct {
//   uint16_t bitmapOffset;  // مكان الحرف داخل الصورة الكاملة للخط
//   uint8_t width;          // عرض الحرف بالبكسل
//   uint8_t height;         // ارتفاع الحرف بالبكسل
//   uint8_t xAdvance;       // بعد ما نرسم الحرف، نتحرك قد إيه لليمين
//   int8_t xOffset;         // مكان بداية الرسم بالنسبة للكيرسور
//   int8_t yOffset;         // مكان بداية الرسم رأسي بالنسبة للكيرسور
// } GFXglyph;
// typedef struct {
//   uint8_t *bitmap;   // الصورة الكاملة لكل الحروف
//   GFXglyph *glyph;   // مصفوفة الحروف
//   uint16_t first;    // ASCII للحرف الأول
//   uint16_t last;     // ASCII للحرف الأخير
//   uint8_t yAdvance;  // المسافة بين السطور
// } GFXfont;
//============================================================================================================================================
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#endif /*SEDHOM_DISPLAY_SETTING_H_*/








