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
    void WIFI_node(Icon_Data_t Wifi_node,String name,int range,Color_t name_color,Color_t WIFI_on , Color_t not_active,WIFI_STATUS_t status,byte_t max_char_in_name = 12);
    //#########################################################################################################################################
    public:
      void set_windows_mode(Color_t mode = Color_Black);
      //drawing window functions 
      void Start_new_Window(String title = "",Color_t title_color = Color_Blue,Icon_Data_t window = {{50,90},Color_White,Color_Black}, Area_t window_area = {300,200},bool show_Divider = false,bool show_close_icon= true);
      void ListView_Window(String title="",Icon_Data_t listview={{30,30},Color_White,Color_Black},Area_t listview_area={400,200}, byte_t listview_number=1,bool show_Divideres = true,bool show_close_icon=true, Color_t choose_active_ball=Color_Magenta,Color_t triangle_choose = Color_Green,Color_t not_active = Color_DarkGrey);
      void Color_Setting_Window(Icon_Data_t Color_window = {{50,90},Color_White,Color_Black});
      void WIFI_ListView_Window(WIFI_Data_Simple_t wifi_Data[5] = nullptr,Icon_Data_t Wifi_listview_window={{30,30},Color_White,Color_Black}, byte_t listview_number=1,bool show_Divideres = true,Color_t wifi_name_color = Color_Magenta ,Color_t Wifi_active_color = Color_Green,Color_t choose_active_ball=Color_Magenta,Color_t triangle_choose = Color_Green,Color_t not_active = Color_DarkGrey);
      //#########################################################################################################################################
};
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// define all functions for drawing windows
void SEDHOM_Windows::set_windows_mode(Color_t mode = Color_Black)
{
  Icons.Set_Mode(mode);
}
void SEDHOM_Windows::Start_new_Window(String title,Color_t title_color,Icon_Data_t window, Area_t window_area , bool show_Divider,bool show_close_icon)
{
   Icons.Border_Rectangle(window,window_area,20,3);
   if(show_close_icon) Icons.Close_Icon({window.coordinate.x+window_area.w-50,window.coordinate.y+10,window.color,Color_Red});
   Icons.Text({window.coordinate.x+15,window.coordinate.y+35},FONT_BIG,title_color,title);
   if(show_Divider) Icons.Divider({{window.coordinate.x+35,window.coordinate.y+55},window.color,window.Background},VERTICAL,window_area.w-75,2);
}
void SEDHOM_Windows::ListView_Window(String title,Icon_Data_t listview,Area_t listview_area, byte_t listview_number, bool show_Divideres , bool show_close_icon, Color_t choose_active_ball , Color_t triangle_choose,Color_t not_active)
{
  Color_t arrow_down ,arrow_up ;
  Color_t Wifi_Window_1 ,Wifi_Window_2 ,Wifi_Window_3 ;
  switch (listview_number)
  {
  case 1:
    {
      arrow_down = triangle_choose,arrow_up = not_active;
      Wifi_Window_1 = choose_active_ball,Wifi_Window_2 = not_active,Wifi_Window_3 = not_active;
    }
    break;
  case 2:
    {
      arrow_down = triangle_choose,arrow_up = triangle_choose;
      Wifi_Window_1 = not_active,Wifi_Window_2 = choose_active_ball,Wifi_Window_3 = not_active;
    }
    break;
  case 3:
    {
      arrow_down = not_active,arrow_up = triangle_choose;
      Wifi_Window_1 = not_active,Wifi_Window_2 = not_active,Wifi_Window_3 = choose_active_ball;
    }
    break;
  }
  Start_new_Window(title,listview.color,listview,listview_area,show_Divideres,show_close_icon);
  if(show_Divideres) Icons.Divider({{listview.coordinate.x+listview_area.w-70,listview.coordinate.y+60},listview.color,listview.Background},HORIZONTAL,listview_area.h-70,2);
  if (listview_area.h>130)
  {
    Icons.Equilateral_Triangle({{listview.coordinate.x+listview_area.w-40,listview.coordinate.y+80},25,Shape_Fill,Direction_Up,arrow_up});
    Icons.Equilateral_Triangle({{listview.coordinate.x+listview_area.w-40,listview.coordinate.y+listview_area.h-30},25,Shape_Fill,Direction_Down,arrow_down});
  }
  if (listview_area.h>170)
  {
    Icons.Circle({{listview.coordinate.x+listview_area.w-40, 
        ((listview_area.h<240) ?  ((listview_area.h<200) ? listview.coordinate.y+100 : listview.coordinate.y+110) : listview.coordinate.y+120 )},
         ((listview_area.h<240) ?  ((listview_area.h<200) ? 3 : 5) : 7 ),Shape_Fill,Wifi_Window_1});
    Icons.Circle({{listview.coordinate.x+listview_area.w-40,
        (( ((listview_area.h<240) ?  ((listview_area.h<200) ? listview.coordinate.y+100 : listview.coordinate.y+110) : listview.coordinate.y+120 )+(listview.coordinate.y+listview_area.h-60))/2)},
        ((listview_area.h<240) ?  ((listview_area.h<200) ? 3 : 5) : 7 ),Shape_Fill,Wifi_Window_2});
    Icons.Circle({{listview.coordinate.x+listview_area.w-40,
        listview.coordinate.y+listview_area.h-60},
        ((listview_area.h<240) ?  ((listview_area.h<200) ? 3 : 5) : 7 ),Shape_Fill,Wifi_Window_3});
  }
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
void SEDHOM_Windows::WIFI_node(Icon_Data_t Wifi_node,String name,int range,Color_t name_color,Color_t WIFI_on,Color_t not_active,WIFI_STATUS_t status,byte_t max_char_in_name)
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
void SEDHOM_Windows::WIFI_ListView_Window(WIFI_Data_Simple_t wifi_Data[],Icon_Data_t Wifi_listview_window,byte_t listview_number,bool show_Divideres,Color_t wifi_name_color ,Color_t Wifi_active_color,Color_t choose_active_ball,Color_t triangle_choose ,Color_t not_active )
{
  #define WIFI_listView_H    400
  #define WIFI_listView_W    230
  //
    WIFI_Data_Simple_t defaultNames[5] = {
      {"None",0,WIFI_Status_no_internet},
      {"None",0,WIFI_Status_no_internet},
      {"None",0,WIFI_Status_no_internet},
      {"None",0,WIFI_Status_no_internet},
      {"None",0,WIFI_Status_no_internet},
  };
    if(wifi_Data == nullptr)
        wifi_Data = defaultNames;
  // Draw List view
  ListView_Window("    WiFi Setting",Wifi_listview_window,{WIFI_listView_H,WIFI_listView_W},listview_number,show_Divideres,true,choose_active_ball,triangle_choose,not_active);
  // containet of list view
  for (int i = 0; i < 5; i++)
  {
    WIFI_node({{Wifi_listview_window.coordinate.x+10,(Wifi_listview_window.coordinate.y+82+(30*i))},Wifi_listview_window.color,
    Wifi_listview_window.Background},wifi_Data[i].name,wifi_Data[i].range,wifi_name_color,Wifi_active_color,not_active,wifi_Data[i].wifi_status,12);
  }
}



//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif // !SEDHOM_WINDOWS_H_