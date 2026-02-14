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
void setup()
{
  // Serial.begin(115200);
  OS.Init_Screen(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Icon_t myIcon;
  myIcon.x = 150;
  myIcon.y = 80;
  myIcon.color = Color_Magenta;
  myIcon.Background = OS.Mode(); 
  Text_t myText;
  myText.txt = "Mustafa Sedhom";
  myText.txt_font = FONT_BIG;
  myText.txt_color = Color_Blue ;
  Time_t mytime;
  mytime.time_name = "PM";
  mytime.hour = 20 ;
  mytime.minut = 30 ;
  mytime.sec = 15;
  Date_t myDate ;
  myDate.Day = 15;
  myDate.month = 12;
  myDate.year = 2020;
  myDate.month_name = "Jan";
  myDate.week_day_name = "WED";
  User_ID_Data_t User;
  // all Icons
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Icons.WIFI_Icon(myIcon,Color_DarkGrey,WIFI_Status_conected_level_2_half);
  // Icons.Battary_Icon(myIcon,44,OS.Not_Mode());
  // Icons.Home_Icon(myIcon);
  // Icons.Setting_Icon(myIcon);
  // Icons.Add_Icon(myIcon);
  // Icons.SD_Card_Icon(myIcon);
  // Icons.Control_Icon(myIcon);
  // Icons.Sensor_Icon(myIcon);
  // Icons.Power_off_Icon(myIcon);
  // Icons.Bluetooth_Icon(myIcon,BLuetooth_Status_open_and_connected);
  // Icons.Button_Icon(myIcon,true);
  // Icons.Display_Time_Icon(myIcon,mytime);
  // Icons.Terminal_Icon(myIcon);
  // Icons.About_Icon(myIcon);
  // Icons.Display_Date_Icon(myIcon,myDate,GREEN);
  // Icons.UP_Arrow_Icon(myIcon,WHITE);
  // Icons.Back_Arrow_Icon(myIcon,GREEN);
  // Icons.After_Arrow_Icon(myIcon,GREEN);
  // Icons.Color_Icon(myIcon);
  // Icons.Time_Icon(myIcon);
  // Icons.Date_Icon(myIcon);
  // Icons.Switch_Icon(myIcon,Color_Red,OS.Not_Mode(),OS.Mode(), SWITCH_State_OFF);
  // Icons.label_Icon(myIcon,{100,50},3,GREEN,"mustafa");
  // Icons.slider_Icon(myIcon,100,75,Color_DarkGrey,OS.Not_Mode(),Magenta,Green);
  // Icons.file_Icon(myIcon,OS.Not_Mode(),GREEN,"kgk");
  // Icons.folder_Icon(myIcon);
  // Icons.Divider_vertical(myIcon,100,5);
  // Icons.ID_Card_Icon(myIcon,User,GREEN,RED);
  // Icons.Joy_Stick_Icon(myIcon,{myIcon.x,myIcon.y},15,GREEN,WHITE,BLUE);
  // Icons.Temperature_Meter_Icon(myIcon,OS.Not_Mode(),50);
  // Icons.Tone_Icon(myIcon);
  // Icons.Sound_value_Icon(myIcon,50);
  // Icons.Video_Icon(myIcon);
  // Icons.Block_Icon(myIcon,true);
  // Icons.Signal_Icon(myIcon, Signal_Status_Signal_level_3,Color_DarkGrey);
  // Icons.Bell_Icon(myIcon);
  // Icons.Menu_Icon_1(myIcon);
  // Icons.Menu_Icon_2(myIcon);
  // Icons.Menu_Icon_3(myIcon);
  // Icons.Menu_Icon_4(myIcon);
  // Icons.Menu_Icon_5(myIcon);
  // Icons.Moon_Icon(myIcon);
  // Icons.Sun_Icon(myIcon);
  // Icons.Check_Box_Icon(myIcon,true,GREEN,OS.Mode());
  // Icons.Radio_Button_Icon(myIcon,true,GREEN);
  // Icons.Text_Feild_Icon(myIcon,myText,200,10);
  // Icons.Warning_Icon(myIcon,RED);
  // Icons.Chandelier_Icon(myIcon);
  // Icons.Smart_TV_Icon(myIcon);
  // Icons.Air_Conditioner_Icon(myIcon);
  // Icons.fill_rectangle_with_end(100,100,70,20,3,GREEN,Blue);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
}
//=======================================================================================
void loop() 
{

}
//=======================================================================================







