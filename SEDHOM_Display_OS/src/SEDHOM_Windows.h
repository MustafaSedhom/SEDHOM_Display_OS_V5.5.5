#ifndef SEDHOM_WINDOWS_H_
#define SEDHOM_WINDOWS_H_
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include "SEDHOM_Icons.h"
#include "SEDHOM_Widgets.h"
#include "SEDHOM_Display_Touch.h"
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
class SEDHOM_Windows
{
  private:
    // make object to use icons functions
    SEDHOM_Icons Icons;
    // make object to use touch functions
    SEDHOM_Touch Touch;
    //
    void WIFI_node(Icon_Data_t Wifi_node,String name,int value,Color_t WIFI_on,WIFI_STATUS_t status);
    //#########################################################################################################################################
    public:
      void set_windows_mode(Color_t mode = Color_Black);
      //drawing window functions 
      void Start_new_Window(String title = "  New Window",Color_t title_color = Color_Blue,Icon_Data_t window = {{50,90},Color_White,Color_Black}, Area_t window_area = {300,200},bool show_Divider = false);
      void Color_Setting_Window(Icon_Data_t Color_window = {{50,90},Color_White,Color_Black});
      void WIFI_Setting_Window(Icon_Data_t Wifi_Window =  {{30,30},Color_White,Color_Black});
      //#########################################################################################################################################
};
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// define all functions for drawing windows
void SEDHOM_Windows::set_windows_mode(Color_t mode = Color_Black)
{
  Icons.Set_Mode(mode);
}
void SEDHOM_Windows::Start_new_Window(String title,Color_t title_color,Icon_Data_t window, Area_t window_area , bool show_Divider)
{
   Icons.Border_Rectangle(window,window_area,20,3);
   Icons.Close_Icon({window.coordinate.x+window_area.w-50,window.coordinate.y+10,window.color,Color_Red});
   Icons.Text({window.coordinate.x+15,window.coordinate.y+35},FONT_BIG,title_color,title);

   if(show_Divider) Icons.Divider({{window.coordinate.x+35,window.coordinate.y+55},window.color,window.Background},VERTICAL,window_area.w-75,2);
}
void SEDHOM_Windows::Color_Setting_Window(Icon_Data_t Color_Window)
{
  Color_t colors_array [2][4]
  {
    {Color_Red,Color_Green,Color_Blue,Color_Magenta},
    {Color_Yellow,Color_Cyan,Color_DarkGrey,Color_Maroon},
  };
  Start_new_Window(" Color Setting",Color_Window.color,Color_Window,{300,200},true);
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      Icons.Square({{(Color_Window.coordinate.x+20)+((70*i)),((Color_Window.coordinate.y+70)+(j*65))},50,10,Shape_Fill,colors_array[j][i]});
    }
  }
  
}
void SEDHOM_Windows::WIFI_Setting_Window(Icon_Data_t Wifi_Window)
{
  Start_new_Window("     WiFi Setting",Wifi_Window.color,Wifi_Window,{400,230},true);
  Icons.Divider({{Wifi_Window.coordinate.x+330,Wifi_Window.coordinate.y+60},Wifi_Window.color,Wifi_Window.Background},HORIZONTAL,160,2);
  Icons.Equilateral_Triangle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+90},30,Shape_Fill,Direction_Up,Color_DarkGrey});
  Icons.Equilateral_Triangle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+200},30,Shape_Fill,Direction_Down,Color_Green});
  Icons.Circle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+120},8,Shape_Fill,Color_Blue});
  Icons.Circle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+145},8,Shape_Fill,Color_DarkGrey});
  Icons.Circle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+170},8,Shape_Fill,Color_DarkGrey});
  
  WIFI_node({{Wifi_Window.coordinate.x+10,Wifi_Window.coordinate.y+82},Wifi_Window.color,Wifi_Window.Background},
    "Mustafa 123",80,Color_Green,WIFI_Status_connected_level_1);
  WIFI_node({{Wifi_Window.coordinate.x+10,Wifi_Window.coordinate.y+110},Wifi_Window.color,Wifi_Window.Background},
    "name_wifi",40,Color_Green,WIFI_Status_connected_level_2_half);
  WIFI_node({{Wifi_Window.coordinate.x+10,Wifi_Window.coordinate.y+140},Wifi_Window.color,Wifi_Window.Background},
    "we_fg975",40,Color_Green,WIFI_Status_connected_level_2_half);
  WIFI_node({{Wifi_Window.coordinate.x+10,Wifi_Window.coordinate.y+170},Wifi_Window.color,Wifi_Window.Background},
    "Bon 24680_uy",40,Color_Green,WIFI_Status_connected_level_2_half);
  WIFI_node({{Wifi_Window.coordinate.x+10,Wifi_Window.coordinate.y+200},Wifi_Window.color,Wifi_Window.Background},
    "Egypt_Keda",40,Color_Green,WIFI_Status_connected_level_2_half);

  
}

void SEDHOM_Windows::WIFI_node(Icon_Data_t Wifi_node,String name,int value,Color_t WIFI_on,WIFI_STATUS_t status)
{
  static int number = 1;
  Icons.Text({Wifi_node.coordinate.x,Wifi_node.coordinate.y},FONT_BIG,Wifi_node.color,String(number++)+String(">"));
  Icons.Text({Wifi_node.coordinate.x+30,Wifi_node.coordinate.y},FONT_BIG,Color_Magenta,name);
  Icons.WIFI_Icon({{Wifi_node.coordinate.x+250,Wifi_node.coordinate.y},WIFI_on,Wifi_node.Background},Color_DarkGrey,status);
  Icons.Text({Wifi_node.coordinate.x+270,Wifi_node.coordinate.y},FONT_BIG,Wifi_node.color,String(value)+String("%"));
}


//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif // !SEDHOM_WINDOWS_H_