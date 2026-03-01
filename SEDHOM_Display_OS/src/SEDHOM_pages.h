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
    SEDHOM_Icons Icons;
    // make object to use icons functions
    SEDHOM_Widgets Widgets;
    // make object to use touch functions
    SEDHOM_Touch Touch;
    ////////////////////////////////////
      const Color_t colors[7]={
        GREEN,
        BLUE,
        RED,
        MAGENTA,
        CYAN,
        DARKGREY,
        ORANGE,
      };
    ///////////////////////////////////
  public:
    //
    void set_Pages_mode(Color_t Mode = Color_Black);
    void Start_new_Page(bool show_back_arrow = true,WIFI_STATUS_t WIFI_state = WIFI_Status_connected_level_2_half,BLUETOOTH_STATUS_t Bluetooth_state = BLuetooth_Status_open_and_not_connected,int Battery_Value = 22,Time_Data_t time = {12,33,17,"Am"},Color_t Wifi_on = Color_Blue,Color_t Wifi_off= Color_DarkGrey,Color_t BLE_color= Color_Yellow,Color_t Battery_color = Color_Green,Color_t Time_color = Color_Magenta,Color_t Reverse_color = Color_Blue,Color_t Background=Color_Black);
    void Paint_Page();
    void Handling_Paint_Page();
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SEDHOM_Pages::set_Pages_mode(Color_t Mode)
{
  Icons.Set_Mode(Mode);
  this->mode = Mode;
}
void SEDHOM_Pages::Start_new_Page(bool show_back_arrow,WIFI_STATUS_t WIFI_state,BLUETOOTH_STATUS_t Bluetooth_state,int Battery_Value,Time_Data_t time,Color_t Wifi_on,Color_t Wifi_off,Color_t BLE_color,Color_t Battery_color,Color_t Time_color,Color_t Reverse_color,Color_t Background)
{
  Widgets.Big_frame_widget((Background==Color_Black)?Color_White:Color_Black,(Background==Color_Black)?Color_Black:Color_White);
  Widgets.APP_Bar_Widget(show_back_arrow, WIFI_state, Bluetooth_state, Battery_Value, time, Wifi_on, Wifi_off, BLE_color, Battery_color, Time_color, Reverse_color, Background);
}
void SEDHOM_Pages::Paint_Page()
{
  // Draw colors boxes
  for(int i=0;i < 7;i++)
  {
     Icons.Rectangle({{10+(60*i),10},{50,50},5,Shape_Fill,colors[i]});
  }
  // Draw Fnt boxes
  for(int i=0;i < 7;i++)
  {
     Icons.Rectangle({{480-30,65+(i*35)},{20,(i*(2))},0,Shape_Fill,Color_White});
  }

  Icons.Divider({{5,63},Color_White,Color_Black},VERTICAL,480-10,2);
  Icons.Divider({{480-47,5},Color_White,Color_Black},HORIZONTAL,320-10,2);

  Icons.Text_C({480-30,45},FONT_FREESANSBOLD_BIG,RED,"X");
}
void SEDHOM_Pages::Handling_Paint_Page()
{
  // variables for control pin of drawing
  static int pin_thickness =3;
  static Color_t pin_color = RED ;
  // handling touch
    // check if delete pressed or not
  if(Touch.onTap({{435,0},{40,40}}))
  {
    Icons.Rectangle({{1,65},{480-49,320-63},0,Shape_Fill,Color_Black});
  }
  // check if color pressed or not
  for(int i=0;i < 7;i++)
  {
    if(Touch.onTap({{10+(60*i),10},{50,50}})) pin_color = colors[i];
  }
  // check if font thickness pressed or not
  for(int i=0;i < 7;i++)
  {
    if(Touch.onTap({{450,65+(i*35)},{20,20}})) pin_thickness = i ;
  }
  // if touch pressed in drawer space the draw line 
  if(Touch.onTap({{5,70},{480-60,320}}))
  {
    Icons.Circle({{Touch.get_X_point(),Touch.get_Y_point()},pin_thickness,Shape_Fill,pin_color});
  }
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#endif // !SEDHOM_PAGES_H_