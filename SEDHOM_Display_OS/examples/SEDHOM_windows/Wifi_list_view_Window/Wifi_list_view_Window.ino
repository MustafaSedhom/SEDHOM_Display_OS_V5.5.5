//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
// SEDHOM_Shapes_OS Shapes(OS);
// SEDHOM_Text_OS Texts(OS);
// SEDHOM_Colors_OS colors(OS);
// SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Effects_OS effect(OS);
// SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
// SEDHOM_Communications_OS Call(OS);
// SEDHOM_Animations_OS Animates(OS);
//=======================================================================================
//======================================================================================= 
void setup()
{
  OS.Init_OS(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////
  WIFI_Data_Simple_t mywifi[]=
  {
    {"mustafa Sedhom",100,WIFI_Status_connected_level_4_full},
    {"Ali-wifi-125",67,WIFI_Status_connected_level_3},
    {"Bon_24680",48,WIFI_Status_connected_level_2_half},
    {"Esp8266-12E",24,WIFI_Status_connected_level_1},
    {"we-Ed321H",13,WIFI_Status_no_internet},
  };
  ///////////////////////////////////////////////////////////////////////////////////////
  Windows.WIFI_ListView_Window(mywifi,{30,30,OS.Not_Mode(),OS.Mode()},1);
  ////////////////////////////////////////////////////////////////////////////////////////
}
void loop() 
{
}





