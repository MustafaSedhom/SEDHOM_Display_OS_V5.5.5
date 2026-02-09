//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
// object from library
SEDHOM_Display_OS OS;
// var for touch
int last_x,last_y; 
// key_board_output variable
// String var;
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Night_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  OS.Window.Full_Key_Board_Window(Blue);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
}
void loop() 
{
   if(OS.Touch.Is_Presssed())
   {
      int x = OS.Touch.get_X_point();
      int y = OS.Touch.get_Y_point();
      if(x != last_x || y != last_y)
      {
        ////////////////////////
        bool finish = OS.Window.Handling_Touch_Full_Key_Board_Window();
        // if(finish) var = OS.Window.Full_KeyBoard_window_user_input_TXT // return keyboard txt after pressed Done
        ////////////////////////
        last_x = x;
        last_y = y;
      }
   }
   OS.Time.Stop_Display(100); // micro seconds
}








