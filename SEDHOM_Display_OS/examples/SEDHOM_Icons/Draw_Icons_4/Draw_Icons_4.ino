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



















