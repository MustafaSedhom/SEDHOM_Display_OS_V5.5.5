//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
// SEDHOM_Shapes_OS Shapes(OS);
// SEDHOM_Text_OS Texts(OS);
// SEDHOM_Colors_OS colors(OS);
SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
// SEDHOM_Effects_OS effect(OS);
// SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
// SEDHOM_Animations_OS Animates(OS);
//=======================================================================================
//=======================================================================================
void setup()
{
  OS.Init_OS(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  // all Icons
  ///////////////////////////////////////////////////////////////////////////////////////////////////

  Icons.Display_Date_Icon({20,20,Color_Blue,OS.Mode()},{2026,2,16,"Feb","Mon"},Color_White);
  Icons.Color_Icon({170,30,Color_Blue,OS.Mode()});
  Icons.Time_Icon({250,50,Color_Blue,OS.Mode()});
  Icons.Date_Icon({290,30,Color_Blue,OS.Mode()});
  Icons.Switch_Icon({350,30,Color_Blue,OS.Mode()});
  Icons.Switch_Icon({350,80,Color_Blue,OS.Mode()},RED,WHITE,WHITE,SWITCH_State_OFF);
  Icons.label_Icon({30,180,Color_Blue,OS.Mode()});
  Icons.slider_Icon({170,140,Color_Blue,OS.Mode()});
  Icons.file_Icon({160,190,Color_Blue,OS.Mode()});
  Icons.folder_Icon({280,190,Color_Blue,OS.Mode()});
  Icons.Divider({20,280,Color_Blue,OS.Mode()},VERTICAL,200,5);  
}
//=======================================================================================
void loop() 
{

}
//=======================================================================================



















