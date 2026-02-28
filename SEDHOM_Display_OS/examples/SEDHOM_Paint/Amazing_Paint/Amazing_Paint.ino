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
//======================================================================================= OS;

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
  OS.Init_Screen(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Draw colors
  for(int i=0;i < 7;i++)
  {
     Icons.fill_Rectangle(10+(60*i),10,50,50,5,colors[i]);
  }
  for(int i=0;i < 7;i++)
  {
     Icons.fill_Rectangle(450,65+(i*35),(i*(2)),20,0,OS.Not_Mode());
  }
  // Icons.Divider_vertical(5,63,OS.Screen_Height()-10,2,OS.Not_Mode());
  // Icons.Divider_Horezontal(434,5,OS.Screen_Width()-10,2,OS.Not_Mode());
  Icons.Text_C(445,40,FONT_FREESANSBOLD_BIG,RED,"X");
}
void loop() 
{
    // check if delet pressed or not
    if(Touch.onTap(430,0,648,65))
    {
      Icons.fill_Rectangle(0,65,OS.Screen_Width(),OS.Screen_Height()-47,0,OS.Mode());
    }
    for(int i=0;i < 7;i++)
    {
      if(Touch.onTap(10+(60*i),10,50,50)) pin_color = colors[i];
    }
    // check if color pressed or not
    for(int i=0;i < 7;i++)
    {
      if(Touch.onTap(450,65+(i*35),20,20)) pin_thikness = i ;
    }
    // if touch pressed in drawer space the draw line 
    if(Touch.onTap(5,70,OS.Screen_Height()-60,OS.Screen_Width()))
    {
      Icons.fill_Circle(Touch.get_X_point(),Touch.get_Y_point(),pin_thikness,pin_color);
    }
}






