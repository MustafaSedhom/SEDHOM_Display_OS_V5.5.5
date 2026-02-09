//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
// SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
// SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
//=======================================================================================
String last_input_from_user = "" ;
bool finish_input = 1;
//=======================================================================================
void setup()
{
  OS.Init_Screen(OS.Rotate_90,OS.Light_mode);
  // Call
  Serial.begin(115200);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Windows.Full_Key_Board_Window(Color_Red,OS.Mode(),Color_Black,Color_Blue);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
}
//=======================================================================================
void loop() 
{
  finish_input = Windows.Handling_Touch_Full_Key_Board_Window();
  if (finish_input) 
  {
    String new_input = Windows.Full_KeyBoard_window_user_input_TXT;    
    if (new_input != last_input_from_user && new_input != "") 
    {
      last_input_from_user = new_input;
      Serial.print("Input: ");
      Serial.println(new_input);
      Windows.Full_KeyBoard_window_user_input_TXT = "";
    }
    finish_input = false;
  }
}
//=======================================================================================





