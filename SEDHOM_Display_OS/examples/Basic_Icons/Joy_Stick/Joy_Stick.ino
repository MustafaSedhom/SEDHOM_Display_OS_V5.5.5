//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
SEDHOM_Touch_OS Touch(OS);
SEDHOM_Time_OS Time(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
//=======================================================================================
//=======================================================================================
// Joy stick var
int last_x,last_y;
void setup()
{
  OS.Init_Screen(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Icons.Joy_Stick_Icon(200,150,200,150,50,20,OS.Mode(),OS.Not_Mode(),Magenta,OS.Not_Mode());
}
void loop() 
{
   if(Touch.Is_Presssed())
   {
      int x = Touch.get_X_point();
      int y = Touch.get_Y_point();
      if(x != last_x || y != last_y)
      {
        Icons.Joy_Stick_Icon(200,150,x,y,50,20,OS.Mode(),OS.Not_Mode(),Magenta,OS.Not_Mode());
        last_x = x;
        last_y = y;
      }
   }
   Time.Stop_Display(100);
}





