#include <SEDHOM_Display_OS.h>

SEDHOM_Display_OS  OS;

void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Dark_Mode);
  /////////////////////////////////////////////////////////////////////////////////////////////
  SEDHOM_List_of_pages = { Home_page , Switch_page , Setting_page , Wifi_page }; // takes any number of function name's
  OS.Handle_page.Handle_all_pages(SEDHOM_Handling_pages_paramters);
}
void loop()
{
     if(OS.Touch.onTap(400,280,40,40)) OS.Handle_page.push_page();
     if(OS.Touch.onTap(20,30,50,50)) OS.Handle_page.pop_page();
}
void Home_page()
{
   OS.Fill_Screen(OS.Mode());
   OS.Icon.Power_off_Icon(40,40,RED,OS.Mode());
   OS.Icon.After_Arrow_Icon(400,280,BLUE,OS.Not_Mode());
   OS.Icon.Home_Icon(200,140,GREEN,OS.Icon.Blur(200,130,60,60,15,2,OS.Mode(),Rect));
   OS.Icon.TEXT(250,50,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"Home Page");
   OS.Icon.TEXT(20,280,BigFont,RED,"Page 1");
}
void Setting_page()
{
   OS.Fill_Screen(OS.Mode());
   OS.Icon.After_Arrow_Icon(400,280,BLUE,OS.Not_Mode());
   OS.Icon.Back_Arrow_Icon(20,40,RED,OS.Not_Mode());
   OS.Icon.Setting_Icon(240,160,Cyan,OS.Icon.Blur(230,160,0,0,30,2,OS.Mode(),Circle));
   OS.Icon.TEXT(250,50,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"Setting Page");
   OS.Icon.TEXT(20,280,BigFont,RED,"Page 3");
}
void Switch_page()
{
   OS.Fill_Screen(OS.Mode());
   OS.Icon.After_Arrow_Icon(400,280,BLUE,OS.Not_Mode());
   OS.Icon.Back_Arrow_Icon(20,40,RED,OS.Not_Mode());
   OS.Icon.Button_Icon(200,130,OS.Icon.Blur(190,120,70,70,15,2,OS.Mode(),Rect));
   OS.Icon.TEXT(250,50,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"Switches Page");
   OS.Icon.TEXT(20,280,BigFont,RED,"Page 2");
}
void Wifi_page()
{
   OS.Fill_Screen(OS.Mode());
   OS.Icon.Back_Arrow_Icon(20,40,RED,OS.Not_Mode());
   OS.Icon.WIFI_Icon(240,160,WIFI_Status_conected_level_2_half,GREEN,DarkGrey,OS.Icon.Blur(208,125,65,65,15,2,OS.Mode(),Rect));
   OS.Icon.Add_Icon(400,260,GREEN);
   OS.Icon.TEXT(250,50,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"WIFI Page");
   OS.Icon.TEXT(20,280,BigFont,RED,"Page 4");
}





