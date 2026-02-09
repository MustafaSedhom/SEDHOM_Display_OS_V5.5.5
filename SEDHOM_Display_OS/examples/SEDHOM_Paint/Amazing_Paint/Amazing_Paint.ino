//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
SEDHOM_Display_OS OS;

int pin_thikness =3;
Color_t pin_color = RED ;
// list of colors
Color_t colors[]={
  GREEN,
  BLUE,
  RED,
  MAGENTA,
  CYAN,
  DARKGREY,
  ORANGE,
};
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Light_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Draw colors
  for(int i=0;i < 7;i++)
  {
     OS.Icon.fill_Rectangle(10+(60*i),10,50,50,5,colors[i]);
  }
  for(int i=0;i < 7;i++)
  {
     OS.Icon.fill_Rectangle(450,65+(i*35),(i*(2)),20,0,OS.Icon.Not_Mode());
  }
  OS.Icon.Divider_vertical(5,63,OS.Screen_Height()-10,2,OS.Icon.Not_Mode());
  OS.Icon.Divider_Horezontal(434,5,OS.Screen_Width()-10,2,OS.Icon.Not_Mode());
  OS.Icon.TEXT(445,40,FONT_FREESANSBOLD_BIG,RED,"X");
}
void loop() 
{
    // check if delet pressed or not
    if(OS.Touch.onTap(430,0,648,65))
    {
      OS.Icon.fill_Rectangle(0,65,OS.Screen_Width(),OS.Screen_Height()-47,0,OS.Icon.Mode());
    }
    for(int i=0;i < 7;i++)
    {
      if(OS.Touch.onTap(10+(60*i),10,50,50)) pin_color = colors[i];
    }
    // check if color pressed or not
    for(int i=0;i < 7;i++)
    {
      if(OS.Touch.onTap(450,65+(i*35),20,20)) pin_thikness = i ;
    }
    // if touch pressed in drawer space the draw line 
    if(OS.Touch.onTap(5,70,OS.Screen_Height()-60,OS.Screen_Width()))
    {
      OS.Icon.fill_Circle(OS.Touch.get_X_point(),OS.Touch.get_Y_point(),pin_thikness,pin_color);
    }
}






