//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
SEDHOM_Display_OS OS;
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Dark_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
void loop() 
{
    if(OS.Touch.Is_Presssed()) 
    {
      OS.Icon.fill_Circle(OS.Touch.get_X_point(),OS.Touch.get_Y_point(),5,CYAN);
    }
}
