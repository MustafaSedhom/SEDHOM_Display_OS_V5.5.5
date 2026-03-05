#ifndef SEDHOM_WINDOWS_H_
#define SEDHOM_WINDOWS_H_
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include "SEDHOM_Icons.h"
#include "SEDHOM_Widgets.h"
#include "SEDHOM_Display_Touch.h"
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
class SEDHOM_Windows
{
  private:
    // make object to use icons functions
    SEDHOM_Icons Icons;
    // make object to use touch functions
    SEDHOM_Touch Touch;

    //#########################################################################################################################################
    public:
      void set_windows_mode(Color_t mode = Color_Black);
      //drawing window functions 
      void Start_new_Window(String title = "  New Window",Color_t title_color = Color_Blue,Icon_Data_t window = {{50,90},Color_White,Color_Black}, Area_t window_area = {300,200},bool show_Divider = false);
      void Color_Window(Icon_Data_t Color_window = {{50,90},Color_White,Color_Black}, Area_t Color_window_area = {300,200});
      //#########################################################################################################################################
};
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// define all functions for drawing windows
void SEDHOM_Windows::set_windows_mode(Color_t mode = Color_Black)
{
  Icons.Set_Mode(mode);
}
void SEDHOM_Windows::Start_new_Window(String title,Color_t title_color,Icon_Data_t window, Area_t window_area , bool show_Divider)
{
   Icons.Border_Rectangle(window,window_area,20,3);
   Icons.Close_Icon({window.coordinate.x+window_area.w-50,window.coordinate.y+10,window.color,Color_Red});
   Icons.Text({window.coordinate.x+15,window.coordinate.y+35},FONT_BIG,title_color,title);

   if(show_Divider) Icons.Divider({{window.coordinate.x+35,window.coordinate.y+55},window.color,window.Background},VERTICAL,window_area.w-75,2);
}
void SEDHOM_Windows::Color_Window(Icon_Data_t Color_Window,Area_t Color_Window_area)
{
  Start_new_Window(" Color Setting",Color_White,Color_Window,Color_Window_area,true);
  // Icons.Square({{90,150},50,15,Shape_Fill,Color_Green});
}





//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif // !SEDHOM_WINDOWS_H_