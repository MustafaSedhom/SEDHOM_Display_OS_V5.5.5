//=======================================================================================
// include OS lib from SEDHOM company
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












