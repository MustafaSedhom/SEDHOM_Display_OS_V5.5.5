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
  Icons.WIFI_Icon({50,50,Color_Blue,OS.Mode()});
  Icons.Battery_Icon({100,10,Color_Green,OS.Mode()});
  Icons.Home_Icon({170,50,Color_Magenta,OS.Mode()});
  Icons.Setting_Icon({250,30,Color_Cyan,OS.Mode()});
  Icons.Add_Icon({280,10,Color_Green,OS.Mode()});
  Icons.SD_Card_Icon({250,250,Color_Green,OS.Mode()});
  Icons.Control_Icon({350,50,Color_Blue,OS.Mode()});
  Icons.Sensor_Icon({400,50,Color_Red,OS.Mode()});
  Icons.Power_off_Icon({50,150,Color_Red,OS.Mode()});
  Icons.Bluetooth_Icon({150,150,Color_Yellow,OS.Mode()});
  Icons.Button_Icon({100,250,Color_Green,OS.Mode()});
  Icons.Display_Time_Icon({250,150,Color_Magenta,OS.Mode()});
  Icons.Terminal_Icon({300,250,Color_Green,OS.Mode()});
  Icons.About_Icon({50,250,Color_White,OS.Mode()}); 
}
//=======================================================================================
void loop() 
{

}

//=======================================================================================



















