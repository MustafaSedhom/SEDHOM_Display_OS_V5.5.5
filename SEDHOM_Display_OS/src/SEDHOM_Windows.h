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
    void WIFI_node(Icon_Data_t Wifi_node,String name,int range,Color_t name_color,Color_t WIFI_on,WIFI_STATUS_t status,byte_t max_char_in_name);
    //#########################################################################################################################################
    public:
      void set_windows_mode(Color_t mode = Color_Black);
      //drawing window functions 
      void Start_new_Window(String title = "  New Window",Color_t title_color = Color_Blue,Icon_Data_t window = {{50,90},Color_White,Color_Black}, Area_t window_area = {300,200},bool show_Divider = false);
      void Color_Setting_Window(Icon_Data_t Color_window = {{50,90},Color_White,Color_Black});
      void WIFI_ListView_Window(WIFI_Data_Simple_t wifi_Data[5], Icon_Data_t Wifi_Window =  {{30,30},Color_White,Color_Black},byte_t page_number = 1);
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
void SEDHOM_Windows::WIFI_ListView_Window(WIFI_Data_Simple_t wifi_Data[], Icon_Data_t Wifi_Window , byte_t page_number)
{
  Color_t arrow_down ,arrow_up ;
  Color_t Wifi_Window_1 ,Wifi_Window_2 ,Wifi_Window_3 ;
  switch (page_number)
  {
  case 1:
    {
      arrow_down = Color_Green,arrow_up = Color_DarkGrey;
      Wifi_Window_1 = Color_Blue,Wifi_Window_2 = Color_DarkGrey,Wifi_Window_3 = Color_DarkGrey;
    }
    break;
  case 2:
    {
      arrow_down = Color_Green,arrow_up = Color_Green;
      Wifi_Window_1 = Color_DarkGrey,Wifi_Window_2 = Color_Blue,Wifi_Window_3 = Color_DarkGrey;
    }
    break;
  case 3:
    {
      arrow_down = Color_DarkGrey,arrow_up = Color_Green;
      Wifi_Window_1 = Color_DarkGrey,Wifi_Window_2 = Color_DarkGrey,Wifi_Window_3 = Color_Blue;
    }
    break;
  }
  Start_new_Window("     WiFi Setting",Wifi_Window.color,Wifi_Window,{400,230},true);
  Icons.Divider({{Wifi_Window.coordinate.x+330,Wifi_Window.coordinate.y+60},Wifi_Window.color,Wifi_Window.Background},HORIZONTAL,160,2);
  Icons.Equilateral_Triangle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+90},30,Shape_Fill,Direction_Up,arrow_up});
  Icons.Equilateral_Triangle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+200},30,Shape_Fill,Direction_Down,arrow_down});
  Icons.Circle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+120},8,Shape_Fill,Wifi_Window_1});
  Icons.Circle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+145},8,Shape_Fill,Wifi_Window_2});
  Icons.Circle({{Wifi_Window.coordinate.x+360,Wifi_Window.coordinate.y+170},8,Shape_Fill,Wifi_Window_3});
  
    for (int i = 0; i < 5; i++)
    {
      WIFI_node({{Wifi_Window.coordinate.x+10,(Wifi_Window.coordinate.y+82+(30*i))},Wifi_Window.color,Wifi_Window.Background},
         wifi_Data[i].name,wifi_Data[i].range,Color_Magenta,Color_Green,wifi_Data[i].wifi_status,12);
    }
}

void SEDHOM_Windows::WIFI_node(Icon_Data_t Wifi_node,String name,int range,Color_t name_color,Color_t WIFI_on,WIFI_STATUS_t status,byte_t max_char_in_name)
{
  static int number = 1;
  String all_name;
  if( name.length() > max_char_in_name)
  {
    String word = "...";
    String part = name.substring(0, max_char_in_name-3);
    all_name = part + word ;
  }
  else
  {
    all_name = name;
  }
  if(range>=100) range=99;
  Icons.Text({Wifi_node.coordinate.x,Wifi_node.coordinate.y},FONT_BIG,Wifi_node.color,String(number++)+String(">"));
  Icons.Text({Wifi_node.coordinate.x+30,Wifi_node.coordinate.y},FONT_BIG,name_color,all_name);
  Icons.WIFI_Icon({{Wifi_node.coordinate.x+250,Wifi_node.coordinate.y},WIFI_on,Wifi_node.Background},Color_DarkGrey,status);
  Icons.Text({Wifi_node.coordinate.x+270,Wifi_node.coordinate.y},FONT_BIG,Wifi_node.color,String(range)+String("%"));
}


//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif // !SEDHOM_WINDOWS_H_