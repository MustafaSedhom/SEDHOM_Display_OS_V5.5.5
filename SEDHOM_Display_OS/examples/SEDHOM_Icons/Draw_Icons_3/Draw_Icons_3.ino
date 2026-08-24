//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Icons Icons;
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



















