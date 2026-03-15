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
  OS.Init_OS(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  WIFI_Config_t my_WIFI = {
    .SSID = "Mustafa SEDHOM" ,
    .Password = "1234567890" ,
    .range = 50 ,
    .RSSI = -50 ,
    .Secured = true ,
    .channel = 5 ,
    .Encryption_Type = WIFI_AUTH_WPA2_ENTERPRISE ,
    .wifi_status = WIFI_Status_connected_level_2_half ,
  };
  StaticJsonDocument<256> Wifi_setting;
  Wifi_setting["SSID"] = my_WIFI.SSID;
  Wifi_setting["Password"] = my_WIFI.Password;
  Wifi_setting["Range"] = my_WIFI.range;
  Wifi_setting["RSSI"] = my_WIFI.RSSI;
  Wifi_setting["Secured"] = my_WIFI.Secured;
  Wifi_setting["Channel"] = my_WIFI.channel;
  Wifi_setting["Encryption_Type"] = my_WIFI.Encryption_Type;
  Wifi_setting["WIFI_status"] = my_WIFI.wifi_status;
  // serializeJsonPretty(doc,Serial);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Icons.Text_C_Field_Icon(50,100,300,50,BLUE,GREEN,FONT_BIG,OS.Mode(),Wifi_setting["SSID"].as<String>());
  Icons.Text_C_Field_Icon(50,200,300,50,BLUE,GREEN,FONT_BIG,OS.Mode(),Wifi_setting["Password"].as<String>());
  Icons.WIFI_Icon(70,50,Wifi_setting["WIFI_status"].as<WIFI_STATUS_t>(),Color_Green,Color_DarkGrey,OS.Mode());
  ///////////////////////////////////////////////////////////////////////////////////////////////////
}
//=======================================================================================
void loop() 
{

}
//=======================================================================================







