#ifndef SEDHOM_WIDGETS_H_
#define SEDHOM_WIDGETS_H_
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include "SEDHOM_Icons.h"
#include "SEDHOM_Widgets.h"
#include "SEDHOM_Display_Touch.h"
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class SEDHOM_Widgets
{
  private:
    // make object to use icons functions
    SEDHOM_Icons Icon;
    // includde touch to handle all widgets
    SEDHOM_Touch Touch;
  public:
    //
    void set_widgets_mode(Color_t mode = Color_Black);
    void APP_Bar_Widget(bool show_back_arrow = true,WIFI_STATUS_t WIFI_state = WIFI_Status_conected_level_2_half,BLUETOOTH_STATUS_t Bluetooth_state = BLuetooth_Status_open_and_not_connected,int Battary_Value = 22,Time_t time = {12,33,17,"Am"},Color_t Wifi_on = Color_Blue,Color_t Wifi_off= Color_DarkGrey,Color_t BLE_color= Color_Yellow,Color_t Battary_color = Color_Green,Color_t Time_color = Color_Magenta,Color_t Reverse_color = Color_Blue,Color_t Background=Color_Black);
    void Big_frame_widget(Color_t color = Color_White,Color_t Background = Color_Black);
    void ERROR_Massage_Widget(String masseage = "SEDHOM Display OS Error",Color_t Background = Color_Black,Color_t color=MAGENTA,Color_t color_txt=WHITE,Color_t ERROR_Massage_color = RED,Color_t title_Massage_color = BLUE,String title="ERROR",Shape_filled_t filled = Shape_Fill,int x = 100,int y = 70,int w = 240,int h = 160,int max_lines_of_masseage_error =5,int max_char_in_one_line = 20);
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SEDHOM_Widgets::set_widgets_mode(Color_t mode)
{
  Icon.Set_Mode(mode);
}
void SEDHOM_Widgets::APP_Bar_Widget(bool show_back_arrow,WIFI_STATUS_t WIFI_state,BLUETOOTH_STATUS_t Bluetooth_state,int Battary_Value,Time_t time,Color_t Wifi_on,Color_t Wifi_off,Color_t BLE_color,Color_t Battary_color,Color_t Time_color,Color_t Reverse_color,Color_t Background)
{
  if(show_back_arrow)
  {
    Icon.Arrow_Icon({20,30,Reverse_color,(Background == Black) ? white : Black},Direction_Right,(Background == Color_Black) ? Color_White : Color_Black);
  }
  else
  {
    Icon.Power_off_Icon({30,30,Reverse_color,(Background == Black) ? Black : white});
  }
  Icon.WIFI_Icon({373,38,Wifi_on,Background},Wifi_off,WIFI_state);
  Icon.Bluetooth_Icon({330,12,BLE_color,Background},Bluetooth_state);
  Icon.Battary_Icon({410,15,Battary_color,Background},Battary_Value,(Background == Black) ? white : Black);
  Icon.Display_Time_Icon({130,20,Time_color,Background},time);
}
void SEDHOM_Widgets::Big_frame_widget(Color_t color,Color_t Background)
{
  Icon.Rectangle({{1,1},{480-2,320-2},5,Shape_Fill,color});
  Icon.Rectangle({{1+2,1+2},{480-2-4,320-2-4},5,Shape_Fill,Background});

  Icon.Rectangle({{1,60+3},{480-2,3},5,Shape_Fill,color});
}
void SEDHOM_Widgets::ERROR_Massage_Widget(String masseage,Color_t Background,Color_t color,Color_t color_txt,Color_t ERROR_Massage_color ,Color_t title_Massage_color ,String title,Shape_filled_t filled ,int x ,int y ,int w ,int h ,int max_lines_of_masseage_error ,int max_char_in_one_line )
{
  #define x_start 100
  #define y_start 70
  // draw box of error masseage
  Icon.Rectangle({{x_start,y_start},{w,h},5,Shape_Fill,color});
  Icon.Rectangle({{x_start+3,y_start+3},{w-6,h-6},5,Shape_Fill,Background});
  // draw box and exit button
  Icon.Rectangle({{x_start+w-40,y_start},{40,40},5,Shape_Fill,color});
  Icon.Rectangle({{x_start+w-40+3,y_start+3},{40-6,40-6},5,Shape_Fill,Background});
  Icon.Circle({{x_start+w-40+20,y_start+20},6,Shape_Fill,RED});
  // draw txt of title messaage
  if(title.length() > 7)
  {
     Icon.Text({x_start+10,y_start+20},FONT_BIG,title_Massage_color,title);
  }
  else
  {
     Icon.Text({x_start+60,y_start+20},FONT_BIG,title_Massage_color,title);
  }
  // draw Wrongmassage
  Icon.Warning_Icon({x_start+w-40,y_start+80,Color_Yellow,Background},RED,filled);
  // draw Text of error message

  int lineHeight = 15;
  int messageLength = masseage.length();
  int startY = y_start + 50;

  for (int i = 0; i < messageLength; i += max_char_in_one_line)
  {
    String line = masseage.substring(i, i + max_char_in_one_line);
      if (startY > max_lines_of_masseage_error * lineHeight + y_start + 50) {
        break; // Stop if the maximum number of lines is exceeded
      }
        Icon.Text(
        {
          x_start + 10,
          startY 
        },
        
          FONT_SMALL,
          ERROR_Massage_color
        ,
          line
        
    );
    startY += lineHeight;
  }
  // draw ok button
  Icon.Rectangle({{x_start+20,y_start+h-40},{60,30},5,Shape_Fill,color});
  Icon.Rectangle({{x_start+20+3,y_start+h-40+3},{60-6,30-6},5,Shape_Fill,Background});
  Icon.Text_C({x_start+32,y_start+h-18},FONT_BIG,color_txt,"OK");
  // draw close button
  Icon.Rectangle({{x_start+w-80,y_start+h-40},{60,30},5,Shape_Fill,color});
  Icon.Rectangle({{x_start+w-80+3,y_start+h-40+3},{60-6,30-6},5,Shape_Fill,Background});
  Icon.Text_C({x_start+w-80+8,y_start+h-18},FONT_BIG,color_txt,"Out");
  
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#endif // !SEDHOM_WIDGETS_H_