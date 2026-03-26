//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
// SEDHOM_Communications_OS Call(OS);
SEDHOM_Animations_OS Animates(OS);
// SEDHOM_Math_OS Math(OS);
//=======================================================================================
Color_t effect_color;
//======================================================================================= 
void setup()
{
  ///////////////////////////////////////////////////////////////////////////////////////
  OS.Init_OS(OS.Rotate_90,OS.Night_mode);
  // OS.Set_Device_Mode(Light_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////
  Icons.Arrow_Icon({50,50,Color_Magenta,OS.Mode()},Direction_Right,OS.Not_Mode());
  Icons.Arrow_Icon({380,50,Color_Magenta,OS.Mode()},Direction_Left,OS.Not_Mode());
  effect_color=Icons.Blur_Effect({{145,120},OS.Not_Mode(),OS.Mode()},{150,150},20,15);
  ////////////////////////////////////////////////////////////////////////////////////////
}
//======================================================================================= 
void loop() 
{
  Animates.Rotate_Cube_Animation({160,145},40,OS.Not_Mode(),effect_color,50,10);
}
//======================================================================================= 





