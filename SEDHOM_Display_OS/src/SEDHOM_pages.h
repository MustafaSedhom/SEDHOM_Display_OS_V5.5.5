#ifndef SEDHOM_PAGES_H_
#define SEDHOM_PAGES_H_
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include "SEDHOM_Icons.h"
#include "SEDHOM_Widgets.h"
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class SEDHOM_Pages
{
  private:
    //page mode
    Color_t mode;
    // make object to use icons functions
    SEDHOM_Icons Icon;
    // make object to use icons functions
    SEDHOM_Widgets Widget;
    // make object to use touch functions
    SEDHOM_Touch Touch;
  public:
    //
    void set_pages_mode(Color_t Mode = Color_Black);
    void Start_new_page(bool show_back_arrow = true,WIFI_STATUS_t WIFI_state = WIFI_Status_connected_level_2_half,BLUETOOTH_STATUS_t Bluetooth_state = BLuetooth_Status_open_and_not_connected,int Battery_Value = 22,Time_Data_t time = {12,33,17,"Am"},Color_t Wifi_on = Color_Blue,Color_t Wifi_off= Color_DarkGrey,Color_t BLE_color= Color_Yellow,Color_t Battery_color = Color_Green,Color_t Time_color = Color_Magenta,Color_t Reverse_color = Color_Blue,Color_t Background=Color_Black);

};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SEDHOM_Pages::set_pages_mode(Color_t Mode)
{
  Icon.Set_Mode(Mode);
  this->mode = Mode;
}
void SEDHOM_Pages::Start_new_page(bool show_back_arrow,WIFI_STATUS_t WIFI_state,BLUETOOTH_STATUS_t Bluetooth_state,int Battery_Value,Time_Data_t time,Color_t Wifi_on,Color_t Wifi_off,Color_t BLE_color,Color_t Battery_color,Color_t Time_color,Color_t Reverse_color,Color_t Background)
{
  Widget.Big_frame_widget((Background==Color_Black)?Color_White:Color_Black,(Background==Color_Black)?Color_Black:Color_White);
  Widget.APP_Bar_Widget(show_back_arrow, WIFI_state, Bluetooth_state, Battery_Value, time, Wifi_on, Wifi_off, BLE_color, Battery_color, Time_color, Reverse_color, Background);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#endif // !SEDHOM_PAGES_H_