#ifndef SEDHOM_WIDGETS_H_
#define SEDHOM_WIDGETS_H_
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include "SEDHOM_Icons.h"
#include "SEDHOM_Widgets.h"
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class SEDHOM_Widgets
{
  private:
    // make object to use icons functions
    SEDHOM_Icons Icon;
  public:
    //
    void set_widgets_mode(Color_t mode)
    {
      Icon.Set_Mode(mode);
    }
    void APP_Bar_Widget(bool show_back_arrow,WIFI_STATUS_t WIFI_state,BLUETOOTH_STATUS_t Bluetooth_state,int Battary_Value,Time_t time,Color_t Wifi_on,Color_t Wifi_off,Color_t BLE_color,Color_t Battary_color,Color_t Time_color,Color_t Reverse_color,Color_t Background)
    {
      if(show_back_arrow)
      {
        Icon.Back_Arrow_Icon(20,30,Reverse_color,(Background == Black) ? white : Black);
      }
      else
      {
        Icon.Power_off_Icon(30,30,Reverse_color,(Background == Black) ? Black : white);
      }
      Icon.WIFI_Icon(373,38,WIFI_state,Wifi_on,Wifi_off,Background);
      Icon.Bluetooth_Icon(330,12,Bluetooth_state,BLE_color,Background);
      Icon.Battary_Icon(410,15,Battary_Value,Battary_color,(Background == Black) ? white : Black,Background);
      Icon.Display_Time_Icon(130,20,time,Time_color);
    }
    void Big_frame_widget(Color_t color,Color_t Background)
    {
      Icon.fill_Rectangle(1,1,320-2,480-2,5,color);
      Icon.fill_Rectangle(1+2,1+2,320-2-4,480-2-4,5,Background);

      Icon.fill_Rectangle(1,60+3,3,480-2,5,color);
    }
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#endif // !SEDHOM_WIDGETS_H_