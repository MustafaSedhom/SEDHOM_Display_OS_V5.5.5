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
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
//=======================================================================================
//=======================================================================================
void setup()
{
  OS.Init_Screen(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
void loop() 
{
    if(Touch.Is_Presssed()) 
    {
      Icons.fill_Circle(Touch.get_X_point(),Touch.get_Y_point(),5,CYAN);
    }
}
