//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Icons Icons;
SEDHOM_Animations Animates;
SEDHOM_Pages Page;
SEDHOM_Widgets Widgets;
SEDHOM_Windows Windows;
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
  // Icons.WIFI_Icon();
  // Icons.Battery_Icon();
  // Icons.Home_Icon();
  // Icons.Setting_Icon();
  // Icons.Add_Icon();
  // Icons.SD_Card_Icon();
  // Icons.Control_Icon();
  // Icons.Sensor_Icon();
  // Icons.Power_off_Icon();
  // Icons.Bluetooth_Icon();
  // Icons.Button_Icon();
  // Icons.Display_Time_Icon();
  // Icons.Terminal_Icon();
  // Icons.About_Icon();
  // Icons.Display_Date_Icon();
  // Icons.Color_Icon();
  // Icons.Time_Icon();
  // Icons.Date_Icon();
  // Icons.Switch_Icon();
  // Icons.label_Icon();
  // Icons.slider_Icon();
  // Icons.file_Icon();
  // Icons.folder_Icon();
  // Icons.Divider();
  // Icons.ID_Card_Icon();
  // Icons.Joy_Stick_Icon();
  // Icons.Temperature_Meter_Icon();
  // Icons.Tone_Icon();
  // Icons.Sound_value_Icon();
  // Icons.Video_Icon();
  // Icons.Block_Icon();
  // Icons.Signal_Icon();
  // Icons.Bell_Icon();
  // Icons.Menu_Icon_1();
  // Icons.Menu_Icon_2();
  // Icons.Menu_Icon_3();
  // Icons.Menu_Icon_4();
  // Icons.Menu_Icon_5();
  // Icons.Moon_Icon();
  // Icons.Sun_Icon();
  // Icons.Check_Box_Icon();
  // Icons.Radio_Button_Icon();
  // Icons.Text_Field_Icon();
  // Icons.Warning_Icon();
  // Icons.Chandelier_Icon();
  // Icons.Smart_TV_Icon();
  // Icons.Air_Conditioner_Icon();
  // Icons.Arrow_Icon();
  // Icons.Text();
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  // Widgets.ERROR_Massage_Widget("GR",OS.Mode());
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  // Shapes.Rectangle({{10,20},{50,50},10,Shape_Fill,Color_Green});
  // Icons.Right_Triangle(myIcon,{60,60},Shape_Fill);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  // Icons.Text({10,10},FONT_BIG,GREEN,"SEDHOM");
}
//=======================================================================================
void loop() 
{
  // Animates.Change_Text_Color({100,150},FONT_FREESANSOBLIQUE_BIG,1000,"Eng.Mustafa SEDHOM");
  // Animates.Scrolling_Text({50,200,RED,OS.Mode()},FONT_BIG,500,"MUSTAFA SHAWKY",{0,70});
}
//=======================================================================================



















