//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>

SEDHOM_Display_OS OS;
// var for touch
// int last_x,last_y;
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Light_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  OS.Icon.Temperature_Meter_Icon(100,50,90,Show,RED,OS.Not_Mode(),OS.Icon.Blur(60,40,250,170,20,2,OS.Mode()));
  ///////////////////////////////////////////////////////////////////////////////////////////////////
}
void loop() 
{
  //  if(OS.Touch.Is_Presssed())
  //  {
  //     int x = OS.Touch.get_X_point();
  //     int y = OS.Touch.get_Y_point();
  //     if(x != last_x || y != last_y)
  //     {
  //       ////////////////////////

  //       ////////////////////////
  //       last_x = x;
  //       last_y = y;
  //     }
  //  }
  //  OS.Time.Stop_Display(100);
}





