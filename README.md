
# ***SEDHOM Display OS***  
![Version](https://img.shields.io/badge/Version-4.4.4-green) &emsp;
![Platform](https://img.shields.io/badge/Platform-Arduino_IDE-blue) &emsp;
![Language](https://img.shields.io/badge/Language-C++-yellow)

# <img src="images/SEDHOM.jpg" width="30" style="border-radius:40%;"> ***SEDHOM Company***

by ***Eng.Mustafa Sedhom*** Embedded Software and Hardware Engineer

<img src="images/SEDHOM.jpg" width="600" style="border-radius:30%; border:2px solid #00000;">

#
## **about library**

### I draw all icons and widgets and pages by using circles & rectangles and triangles only i dont use any images or bitmap images this way make this library take small size .
### you can use this lib in 
- ### <img src="https://cdn.simpleicons.org/arduino" width="30"/>&emsp; Arduino IDE 
- ### <img src="https://cdn.simpleicons.org/platformio" width="30"/>&emsp; Platform IO

is new version of my Library you can use any tft display and you can install it in arduino ide , platform io or you are embeeded engineer .
you can see most project i made with this library and arduino uno and tft 3.5 inch sheild as apicture and videos look this link in my Google Drive : &ensp; [images and videos link ](https://drive.google.com/drive/folders/16Hg8dgcBH3FalRkK8SDBWj2221bd8Fue?usp=sharing)


# ===============
**show example**
![Blur effect image](images/Blur_page_image.jpeg)
![Blur effect image](images/Blur_and_color_text.jpeg)
![color effect image](images/blur_color_page.jpeg)

[videao link](images/page_1_video.mp4)

<video width="600" controls>
  <source src="images/page_1_video.mp4" type="video/mp4">
</video>

-  code of video and picture

```cpp
//=======================================================================================
// include OS lib from SEDHOM company
// Eng.Mustafa Sedhom
#include <SEDHOM_Display_OS.h>
// object from library
SEDHOM_Display_OS OS;
// page var
Color_t is_selected[][2] =
{
  {0,GREEN},
  {0,BLUE},
  {0,Magenta},
  {0,RED}
};
// var for touch
int last_x,last_y;
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Night_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Desgin_Page_1();
  ///////////////////////////////////////////////////////////////////////////////////////////////////
}
void loop() 
{
   if(OS.Touch.Is_Presssed())
   {
      int x = OS.Touch.get_X_point();
      int y = OS.Touch.get_Y_point();
      if(x != last_x || y != last_y)
      {
        ////////////////////////
        if(OS.Touch.onTap(20,10,120,200))   { is_selected[0][0] = ! is_selected[0][0]; Desgin_Page_1(); } 
        if(OS.Touch.onTap(260,10,120,200))  { is_selected[1][0] = ! is_selected[1][0]; Desgin_Page_1(); } 
        if(OS.Touch.onTap(20,170,120,200))  { is_selected[2][0] = ! is_selected[2][0]; Desgin_Page_1(); } 
        if(OS.Touch.onTap(260,170,120,200)) { is_selected[3][0] = ! is_selected[3][0]; Desgin_Page_1(); } 
        ////////////////////////
        last_x = x;
        last_y = y;
      }
   }
  //  OS.Time.Stop_Display(100); // micro seconds
}
void Desgin_Page_1()
{
  // Page Settings
  #define Blur_effect_value       2
  #define Icons_color             OS.Not_Mode() 
  #define Icons_TXT_color         OS.Not_Mode() 
  #define Second_TXT_color        OS.Not_Mode() 
  
  // Setting Widgets
  OS.Icon.Setting_Icon(70,40,Icons_color,is_selected[0][0] ? OS.Icon.Color_Blur(20,10,120,200,20,is_selected[0][1],OS.Mode()) : OS.Icon.Blur(20,10,120,200,20,Blur_effect_value,OS.Mode()));
  OS.Icon.TEXT(100,40,FONT_FREEMONOBOLD_MEDIUM,Icons_TXT_color,"Setting");
  OS.Icon.TEXT(80,103,FONT_FREEMONOBOLD_SMALL,Second_TXT_color,"System");

  // WIFI Widgets
  OS.Icon.WIFI_Icon(300,50,WIFI_Status_conected_level_4_full,Icons_color,0,is_selected[1][0] ? OS.Icon.Color_Blur(260,10,120,200,20,is_selected[1][1],OS.Mode()) : OS.Icon.Blur(260,10,120,200,20,Blur_effect_value,OS.Mode()));
  OS.Icon.TEXT(380,50,FONT_FREEMONOBOLD_MEDIUM,Icons_TXT_color,"WIFI");
  OS.Icon.TEXT(310,103,FONT_FREEMONOBOLD_SMALL,Second_TXT_color,"Connected");

  // BLE Widgets
  OS.Icon.Bluetooth_Icon(55,190,BLuetooth_Status_open_and_not_connected,Icons_color,is_selected[2][0] ? OS.Icon.Color_Blur(20,170,120,200,20,is_selected[2][1],OS.Mode()) : OS.Icon.Blur(20,170,120,200,20,Blur_effect_value,OS.Mode()));
  OS.Icon.TEXT(100,210,FONT_FREEMONOBOLD_MEDIUM,Icons_TXT_color,"Blutooth");
  OS.Icon.TEXT(50,270,FONT_FREEMONOBOLD_SMALL,Second_TXT_color,"DisConnected");

  // Home Widgets
  OS.Icon.Home_Icon(270,185,Icons_color,is_selected[3][0] ? OS.Icon.Color_Blur(260,170,120,200,20,is_selected[3][1],OS.Mode()) : OS.Icon.Blur(260,170,120,200,20,Blur_effect_value,OS.Mode()));
  OS.Icon.TEXT(380,210,FONT_FREEMONOBOLD_MEDIUM,Icons_TXT_color,"Home");
  OS.Icon.TEXT(345,270,FONT_FREEMONOBOLD_SMALL,Second_TXT_color,"GUI");
}
```

#
## **about this version**
- **last version :** &emsp; ![last version](https://img.shields.io/badge/Version-3.5.1-red)
- adding some widgets and icons .
- adding effect like BLUR effect .
- handling all file for this lib and make it for begineers to use it .
- in SEDHOM_Display_OS.h class that has 4 var .
#
## **why I made this lib ?**
- this lib i use it for drawing some icons in ant tft i use it with arduino uno and nano and mega and esp32 .
- this lib doing any thing about this tft touch display with any mcu like sd card read file touch draw any thing in this tft display .
- GUI simple for control GPIO and smart thing .
- simple use for beginner to use elcronics .
#
## **what this lib do ?**
- draw some icons and wedigts and handling touch and read file from sd card .
- handling pages it's you make it .
- drawing pages i make it for any thing .
- you can make Beuatiful GUI for any machine and smart homes .
#
## **about Writer this Library**

***Eng.Mustafa Sedhom*** ( Embedded Software and Haedware Engineer ) 

  Gmail : **elmohandes24680@gmail.com**

  linkedIn : **[Mustafa Sedhom](https://www.linkedin.com/in/mustafa-sedhom-bb2551322)**

  WhatsApp : **+201144962908**
#
## **properites of Library**
- Icon <- for drawing icons and shapes and effects and text and fonts for text 
    ```Cpp
        // to set and handling mode
        uint16_t Not_Mode();
        uint16_t Mode();
        void Set_Mode(Color_t Mode);
        // colors
        Color_t set_Color(int r,int g,int b);
        // define Basic shapes
        void draw_Pixel(int x,int y,Color_t color);
        void draw_Line(int x0,int y0,int x1,int y1,Color_t color);    
        void fill_Rectangle(int x,int y,int w,int h,int r,Color_t color);    
        void draw_Rectangle(int x,int y,int w,int h,int r,Color_t color);  
        void fill_Circle(int x,int y,int r,Color_t color); 
        void draw_Circle(int x,int y,int r,Color_t color);
        void fill_Triangle(int x0,int y0,int x1,int y1,int x2,int y2,Color_t color); 
        void draw_Triangle(int x0,int y0,int x1,int y1,int x2,int y2,Color_t color);

        void Right_Triangle(int x, int y, int h, int w,bool fill_or_draw, Color_t color);
        void Equilateral_Triangle_Up(int x, int y, int h,bool fill_or_draw, Color_t color);
        void Equilateral_Triangle_Down(int x, int y, int h,bool fill_or_draw, Color_t color); 
        void Equilateral_Triangle_Right(int x, int y, int h,bool fill_or_draw, Color_t color); 
        void Equilateral_Triangle_Left(int x, int y, int h,bool fill_or_draw, Color_t color); 

        void TEXT(int x,int y,const GFXfont* font,Color_t color,string_t txt);
        void Container(int x,int y,int h,int w,int raduis,Color_t color);
        void fill_rectangle_with_end(int x,int y,int h,int w,int end_volume,Color_t color,Color_t end_color);
        void Draw_Custom_int_shap(int x,int y,int h,int w,int color,int arr[]);
        void Draw_Custom_Char(int x,int y,int h,int w,int color,char arr[]);
        // effects 
        Color_t Blur(int x,int y,int h,int w,int r,int Blur_value,Color_t mode,bool circle_or_rectangle = 1);
        // Draw SEDhOM Icons
        void QRCode_Icon(int x,int y,int size,int version,string_t content,Color_t color,Color_t Background);
        void WIFI_Icon(int x,int y,WIFI_STATUS_t state,Color_t color_on,Color_t color_off,Color_t Background);
        void Battary_Icon(int x,int y,int range,Color_t color,Color_t txt_color,Color_t Background,bool low_charge_red_color);
        void Home_Icon(int x,int y,Color_t color,Color_t Background);
        void Setting_Icon(int x,int y,Color_t color,Color_t Background);
        void Add_Icon(int x,int y,Color_t color,Color_t Background=0);
        void SD_Card_Icon(int x,int y,Color_t Background=0);
        void Control_Icon(int x,int y,Color_t color,Color_t Background);
        void Sensor_Icon(int x,int y,Color_t color,Color_t Background=0);
        void Power_off_Icon(int x,int y,Color_t color,Color_t Background);
        void Bluetooth_Icon(int x , int y ,BLUETOOTH_STATUS_t connect_status,Color_t color,Color_t Background);
        void Button_Icon(int x,int y,Color_t Background=0,bool print_on_and_off = 0);
        void Display_Time_Icon(int x,int y,int hour,int minut,int sec,word_t time_name,Color_t color,Color_t Background=0);
        void Terminal_Icon(int x,int y,Color_t Background=0);
        void About_Icon(int x,int y ,Color_t color,Color_t Background);
        void Display_Date_Icon(int x,int y,Color_t color,Color_t text_color,int year,word_t month_name,int Day,word_t week_day_name,Color_t Background);
        void UP_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void DOWN_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void LEFT_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void RIGHT_Aroow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void Back_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void After_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void Color_Icon(int x,int y,Color_t Background=0);
        void Time_Icon(int x,int y,Color_t color,Color_t Background);
        void Date_Icon(int x,int y,Color_t color,Color_t Background);
        void Switch_Icon(int x,int y,Color_t color_on,Color_t color_off,Color_t thumb_color,Color_t txt_color,bool state,Color_t Background=0);
        void label_Icon(int x,int y,int h,int w,int end,word_t string_in_label,Color_t color_str_in_label,Color_t color,Color_t Background);
        void slide_Icon(int x,int y,int h,byte_t range ,Color_t color_active,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color,Color_t Background=0);
        void file_Icon(int x,int y,Color_t color,Color_t end_color,Color_t file_extend_color,word_t file_extend,Color_t Background);
        void folder_Icon(int x,int y,Color_t folder_color,Color_t Background=0);
        void Divider_vertical(int x,int y,int length , int thikness,Color_t color);
        void Divider_Horezontal(int x,int y,int length , int thikness,Color_t color);
        void ID_Card_Icon(int x,int y,Color_t color,Color_t main_font_color,Color_t font_color,Color_t image_background,bool default_image,bool eye,bool prof,char* name,char* unversity,char* department_1,char* department_2,char* Born,char* number,Color_t Background=0);
        void Joy_Stick_Icon(int x,int y,int thumb_x,int thumb_y,int size,int thumb_size,Color_t color,Color_t OutLine,Color_t thumb,Color_t in ,Color_t Background=0);
        void Temperature_Meter_Icon(int x,int y,int value,bool show_val_dashes,Color_t color,Color_t Outline,Color_t Background);
        void Tone_Icon(int x,int y,bool is_muted_or_not,Color_t color,Color_t Background);
        void Sound_value_Icon(int x,int y,int value,Color_t color,Color_t thikness_color,Color_t Background,bool thikness_or_not=0);
        void Video_Icon(int x,int y,Color_t color,Color_t Background);
        void Block_Icon(int x,int y,bool open_or_closed,Color_t color,Color_t Background);

    ```

- Touch <- handling all touch mehods and output function name-> 
    - onTap(x,y,h,w)->bool <- detect touch return true or false and take rectangle space for detect it  .
    - onTap(x,y,h,w,*function)-> void <- detect touch and take rectangle space for detect it and do function  .
    - is_preesed()-> bool <- return true if touch presed in any space in tft screen .
    - get_x_Point()-> int <- return x coordenates for x touch place .
    - get_y_Point()-> int <- return y coordenates for y touch place .
    - get_Z_Point()-> int <- return preesed value  .
    ``` Cpp
      bool Is_Presssed();
      int get_X_point();
      int get_Y_point();
      int get_Z_point();
      bool onTap(int x, int y, int w, int h);
      void onTap(int x, int y, int w, int h,void (*Do_Function)());
    ```
- SD_Card <- handling all function to dealing betwwen sdcard and mcu
    - read() , write() , ... like sd lib do exactly .
- handle_page <- handling pages you do it in your project goto scrolling_betwwen_pages.ino file in example .
    - SEDHOM_List_of_pages   <- put in it all function do you make it .
    - Handle_all_pages(void (*pages_array[])(void), int size)-> void <- to push first page and show it in paramete dont put this parameter and put SEDHOM_Handling_pages_paramters only.
    - goto_page(int number)-> void <- goto page with number .
    - push_page()-> void <- show next page .
    - pop_page()-> void <- show reveres page .
    ```cpp
      // input SEDHOM_Handling_pages_paramters instead of void (*pages_array[])(void), int size
      void Handle_all_pages(void (*pages_array[])(void), int size);
      void goto_page(int number);
      void push_page();
      void pop_page();
    ```

#
## if you want install it in arduino ide 
1. download this folder in your pc
2. put this folder in (~/Documentos/Arduino/libraries) between your arduino libraries .
3. you should install some library becuose this lib is a top layer of drivers 
    - MCUFreind_kbv  <- or choose any driver do you want and adding some setting in SEDHOM_Display_Settings.h file .
    - Adarfruit Touch <- this lib for touch you can use it and edit all setting touch in SEDHOM_Display_Settings.h file .
    - Adafruit GFX <- for drawing basic shapes .
    - QRCodeGFX <- for drawing QRCode icon .
    - SD <- for use sd card and load images and fonts in tft screen .
    - SPI <- this lib embbedded in arduino ide .
4. open arduino ide or restart arduino ide and open (file -> Examples -> SEDHOM_Display_OS -> ... ) choose any project and added any thing you want and use lib .
5. you can open new project and put in top first thing this line #include<SEDHOM_Display_OS.h> and next line SEDHOM_Display_OS   OS; and in setup OS.Init_Screen(Rotate_90_Degree,Night_Mode); and use OS. and show all proertes in this lib and see last pargraf in this to show all prpertes .
#
## else if you want install it in platform io -->

1. download this folder in your pc
2. create platform project .
3. put this folder in (lib folder) between your libraries .
4. you should add some library because this lib is a top layer of drivers input all library in lib folder for you project next SEDHOM_Display_OS folder
    - MCUFreind_kbv  <- or choose any driver do you want and adding some setting in SEDHOM_Display_Settings.h file .
    - Adarfruit Touch <- this lib for touch you can use it and edit all setting touch in SEDHOM_Display_Settings.h file .
    - Adafruit GFX <- for drawing basic shapes .
    - SD <- for use sd card and load images and fonts in tft screen .
    - SPI <- this lib for communication protocal betwwen MCU and SD card .
5. open (SEDHOM_Display_OS ->example-> ... ) choose any project and added any thing you want and use lib .
6. you can open new project and put in top first thing this line #include<SEDHOM_Display_OS.h> and next line SEDHOM_Display_OS   OS; and in setup OS.Init_Screen(Rotate_90_Degree,Night_Mode); and use OS. and show all propirtes in this lib and see last pargraf in this to show all prpertes .
#
## else if you Embedded Engineer and want use this library -->

- put this folder betwwen your project and adding this line #include<SEDHOM_Display_OS.h> and next line SEDHOM_Display_OS   OS; and in main before while loop OS.Init_Screen(Rotate_90_Degree,Night_Mode); and you can OS. to show all properites and in SEDHOM_Display_Setting.h all folders i use it and function yhis file is control all my library all files for drawing and gandling touch only .
#
