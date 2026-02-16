//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Pages_OS Pages(OS);
SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
//=======================================================================================
//=======================================================================================
void setup()
{
  OS.Init_Screen(OS.Rotate_90,OS.Night_mode);
  /////////////////////////////////////////////////////////////////////////////////////////////
  SEDHOM_List_of_pages = { Home_page , Switch_page , Setting_page , Wifi_page }; // takes any number of function name's
  Handling_pages.Handle_all_pages(SEDHOM_Handling_pages_paramters);
}
void loop()
{
     if(Touch.onTap(400,280,40,40)) Handling_pages.push_page();
     if(Touch.onTap(20,30,50,50)) Handling_pages.pop_page();
}
void Home_page()
{
   OS.Fill_Screen(OS.Mode());
   Icons.Power_off_Icon(40,40,RED,OS.Mode());
   Icons.After_Arrow_Icon(400,280,BLUE,OS.Not_Mode());
   Icons.Home_Icon(200,140,GREEN,Icons.Blur(200,130,60,60,15,2,OS.Mode(),Rect));
   Icons.Text_C(250,50,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"Home Page");
   Icons.Text_C(20,280,BigFont,RED,"Page 1");
}
void Setting_page()
{
   OS.Fill_Screen(OS.Mode());
   Icons.After_Arrow_Icon(400,280,BLUE,OS.Not_Mode());
   Icons.Back_Arrow_Icon(20,40,RED,OS.Not_Mode());
   Icons.Setting_Icon(240,160,Cyan,Icons.Blur(230,160,0,0,30,2,OS.Mode(),Circle));
   Icons.Text_C(250,50,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"Setting Page");
   Icons.Text_C(20,280,BigFont,RED,"Page 3");
}
void Switch_page()
{
   OS.Fill_Screen(OS.Mode());
   Icons.After_Arrow_Icon(400,280,BLUE,OS.Not_Mode());
   Icons.Back_Arrow_Icon(20,40,RED,OS.Not_Mode());
   Icons.Button_Icon(200,130,Icons.Blur(190,120,70,70,15,2,OS.Mode(),Rect));
   Icons.Text_C(250,50,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"Switches Page");
   Icons.Text_C(20,280,BigFont,RED,"Page 2");
}
void Wifi_page()
{
   OS.Fill_Screen(OS.Mode());
   Icons.Back_Arrow_Icon(20,40,RED,OS.Not_Mode());
   Icons.WIFI_Icon(240,160,WIFI_Status_conected_level_2_half,GREEN,DarkGrey,Icons.Blur(208,125,65,65,15,2,OS.Mode(),Rect));
   Icons.Add_Icon(400,260,GREEN);
   Icons.Text_C(250,50,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"WIFI Page");
   Icons.Text_C(20,280,BigFont,RED,"Page 4");
}





