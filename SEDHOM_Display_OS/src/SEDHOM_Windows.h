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
      void Draw_new_Window(String title = "  New Window",Color_t title_color = Color_Blue,Icon_Data_t window = {{50,90},Color_White,Color_Black}, Area_t window_area = {300,200});
    //#########################################################################################################################################
};
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// define all functions for drawing windows
void SEDHOM_Windows::set_windows_mode(Color_t mode = Color_Black)
{
  Icons.Set_Mode(mode);
}
void SEDHOM_Windows::Draw_new_Window(String title,Color_t title_color,Icon_Data_t window, Area_t window_area)
{
   Icons.Border_Rectangle(window,window_area,20,3);
   Icons.Close_Icon({window.coordinate.x+window_area.w-50,window.coordinate.y+10,window.color,Color_Red});
   Icons.Text({window.coordinate.x+10,window.coordinate.y+30},FONT_BIG,title_color,title);
}






//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif // !SEDHOM_WINDOWS_H_