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
  // Icons.ID_Card_Icon({20,190,Color_Blue,OS.Mode()});
  Icons.Joy_Stick_Icon({50,50,Color_Green,OS.Mode()},{50,50},15,Color_White,Color_White,OS.Mode());
  Icons.Temperature_Meter_Icon({160,10,Color_Red,OS.Mode()});
  Icons.Tone_Icon({330,30,Color_Blue,OS.Mode()});
  Icons.Tone_Icon({400,270,Color_Red,OS.Mode()},true);
  Icons.Sound_value_Icon({30,150,Color_Magenta,OS.Mode()});
  Icons.Video_Icon({280,50,Color_Red,OS.Mode()});
  Icons.Block_Icon({280,130,Color_Green,OS.Mode()});
  Icons.Block_Icon({350,130,Color_Red,OS.Mode()},true);
  Icons.Signal_Icon({330,200,Color_Blue,OS.Mode()});
  Icons.Bell_Icon({420,10,Color_Yellow,OS.Mode()});
  Icons.Moon_Icon({420,90,Color_White,OS.Mode()});
  Icons.Sun_Icon({430,170,Color_Yellow,OS.Mode()});
  Icons.Menu_Icon_1({100,270,Color_Blue,OS.Mode()});
  Icons.Menu_Icon_2({150,280,Color_Blue,OS.Mode()});
  Icons.Menu_Icon_3({200,270,Color_Blue,OS.Mode()});
  Icons.Menu_Icon_4({250,270,Color_Blue,OS.Mode()});
  Icons.Menu_Icon_5({300,270,Color_Blue,OS.Mode()}); 
}
//=======================================================================================
void loop() 
{
}
//=======================================================================================



















