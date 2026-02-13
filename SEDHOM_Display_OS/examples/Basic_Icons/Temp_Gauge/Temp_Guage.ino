//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
// SEDHOM_Touch_OS Touch(OS);
SEDHOM_Time_OS Time(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
//=======================================================================================
//=======================================================================================
// var for touch
// int last_x,last_y;
void setup()
{
  OS.Init_Screen(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Icons.Temperature_Meter_Icon(100,50,90,Show,RED,OS.Not_Mode(),Icons.Blur(60,40,250,170,20,2,OS.Mode()));
  ///////////////////////////////////////////////////////////////////////////////////////////////////
}
void loop() 
{
  //  if(Touch.Is_Presssed())
  //  {
  //     int x = Touch.get_X_point();
  //     int y = Touch.get_Y_point();
  //     if(x != last_x || y != last_y)
  //     {
  //       ////////////////////////

  //       ////////////////////////
  //       last_x = x;
  //       last_y = y;
  //     }
  //  }
  //  Time.Stop_Display(100);
}





