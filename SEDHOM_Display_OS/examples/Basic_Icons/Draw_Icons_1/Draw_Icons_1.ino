//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
// SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
//=======================================================================================
//=======================================================================================
SEDHOM_Display_OS  OS;
void setup()
{
  OS.Init_Screen(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Icons.WIFI_Icon(100,30,WIFI_Status_no_internet,0,CYAN,OS.Mode());
  Icons.Battary_Icon(20,130,27,GREEN,OS.Icon.Not_Mode(),OS.Mode());
  Icons.Add_Icon(20,20,RED);
  Icons.Home_Icon(200,100,BLUE,OS.Mode());
  Icons.Setting_Icon(200,25,YELLOW,OS.Mode());
  Icons.SD_Card_Icon(70,70);
  Icons.Control_Icon(100,120,RED,OS.Mode());
  Icons.Power_off_Icon(20,200,RED,OS.Mode());
  Icons.Sensor_Icon(20,250,GREEN);
  Icons.Bluetooth_Icon(100,180,BLuetooth_Status_open_and_connected,CYAN,OS.Mode());
  Icons.Button_Icon(150,50,1);
  Icons.Display_Time_Icon(100,260,4,38,21,"PM",MAGENTA);
  Icons.Terminal_Icon(130,180);
  Icons.About_Icon(230,200,RED,OS.Mode());
  Icons.UP_Arrow_Icon(400,150,BLUE,OS.Not_Mode());
  Icons.DOWN_Arrow_Icon(400,220,BLUE,OS.Not_Mode());
  Icons.RIGHT_Arrow_Icon(420,210,BLUE,OS.Not_Mode());
  Icons.LEFT_Arrow_Icon(330,210,BLUE,OS.Not_Mode());
  Icons.Back_Arrow_Icon(330,290,BLUE,OS.Not_Mode());
  Icons.After_Arrow_Icon(420,290,BLUE,OS.Not_Mode());
  Icons.Switch_Icon(370,10,GREEN,RED,WHITE,WHITE,off);
  Icons.Switch_Icon(370,70,GREEN,RED,WHITE,WHITE,on);
}

void loop() 
{
}
