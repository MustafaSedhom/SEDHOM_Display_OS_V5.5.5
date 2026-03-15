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
  Icons.Check_Box_Icon({170,30,Color_Green,OS.Mode()});
  Icons.Check_Box_Icon({240,30,Color_Red,OS.Mode()},false);
  Icons.Radio_Button_Icon({340,50,Color_Green,OS.Mode()});
  Icons.Radio_Button_Icon({410,50,Color_Red,OS.Mode()},false);
  Icons.Text_Field_Icon({150,100,Color_Magenta,OS.Mode()});
  Icons.Warning_Icon({410,120,Color_Red,OS.Mode()});
  Icons.Chandelier_Icon({100,250,Color_Yellow,OS.Mode()});
  Icons.Smart_TV_Icon({200,220,Color_Green,OS.Mode()});
  Icons.Air_Conditioner_Icon({300,230,Color_Magenta,OS.Mode()});
  Icons.Arrow_Icon({20,80,Color_Blue,OS.Mode()},Direction_Right);
  Icons.Arrow_Icon({100,80,Color_Blue,OS.Mode()},Direction_Left);
  Icons.Arrow_Icon({85,20,Color_Blue,OS.Mode()},Direction_Up);
  Icons.Arrow_Icon({85,90,Color_Blue,OS.Mode()},Direction_Down);
}
//=======================================================================================
void loop() 
{

}
//=======================================================================================



















