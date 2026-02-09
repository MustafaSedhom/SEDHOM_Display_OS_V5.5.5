//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>

SEDHOM_Display_OS OS;
// Joy stick var
int last_x,last_y;
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Dark_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  OS.Icon.Joy_Stick_Icon(200,150,200,150,50,20,OS.Mode(),OS.Not_Mode(),Magenta,OS.Not_Mode());
}
void loop() 
{
   if(OS.Touch.Is_Presssed())
   {
      int x = OS.Touch.get_X_point();
      int y = OS.Touch.get_Y_point();
      if(x != last_x || y != last_y)
      {
        OS.Icon.Joy_Stick_Icon(200,150,x,y,50,20,OS.Mode(),OS.Not_Mode(),Magenta,OS.Not_Mode());
        last_x = x;
        last_y = y;
      }
   }
   OS.Time.Stop_Display(100);
}





