//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
SEDHOM_Display_OS  OS;
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Dark_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  OS.Icon.WIFI_Icon(100,30,WIFI_Status_no_internet,0,CYAN,OS.Icon.Mode());
  OS.Icon.Battary_Icon(20,130,27,GREEN,OS.Icon.Not_Mode(),OS.Icon.Mode());
  OS.Icon.Add_Icon(20,20,RED);
  OS.Icon.Home_Icon(200,100,BLUE,OS.Icon.Mode());
  OS.Icon.Setting_Icon(200,25,YELLOW,OS.Icon.Mode());
  OS.Icon.SD_Card_Icon(70,70);
  OS.Icon.Control_Icon(100,120,RED,OS.Icon.Mode());
  OS.Icon.Power_off_Icon(20,200,RED,OS.Icon.Mode());
  OS.Icon.Sensor_Icon(20,250,GREEN);
  OS.Icon.Bluetooth_Icon(100,180,BLuetooth_Status_open_and_connected,CYAN,OS.Icon.Mode());
  OS.Icon.Button_Icon(150,50,1);
  OS.Icon.Display_Time_Icon(100,260,4,38,21,"PM",MAGENTA);
  OS.Icon.Terminal_Icon(130,180);
  OS.Icon.About_Icon(230,200,RED,OS.Icon.Mode());
  OS.Icon.UP_Arrow_Icon(400,150,BLUE,OS.Icon.Not_Mode());
  OS.Icon.DOWN_Arrow_Icon(400,220,BLUE,OS.Icon.Not_Mode());
  OS.Icon.RIGHT_Aroow_Icon(420,210,BLUE,OS.Icon.Not_Mode());
  OS.Icon.LEFT_Arrow_Icon(330,210,BLUE,OS.Icon.Not_Mode());
  OS.Icon.Back_Arrow_Icon(330,290,BLUE,OS.Icon.Not_Mode());
  OS.Icon.After_Arrow_Icon(420,290,BLUE,OS.Icon.Not_Mode());
  OS.Icon.Switch_Icon(370,10,GREEN,RED,WHITE,WHITE,off);
  OS.Icon.Switch_Icon(370,70,GREEN,RED,WHITE,WHITE,on);
}

void loop() 
{
}
