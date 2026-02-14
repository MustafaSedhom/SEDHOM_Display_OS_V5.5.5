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
    void set_widgets_mode(Color_t mode);
    void APP_Bar_Widget(bool show_back_arrow,WIFI_STATUS_t WIFI_state,BLUETOOTH_STATUS_t Bluetooth_state,int Battary_Value,Time_t time,Color_t Wifi_on,Color_t Wifi_off,Color_t BLE_color,Color_t Battary_color,Color_t Time_color,Color_t Reverse_color,Color_t Background);
    void Big_frame_widget(Color_t color,Color_t Background);
    void ERROR_Massage_Widget(String masseage,Color_t Background,Color_t color=MAGENTA,Color_t color_txt=WHITE,Color_t ERROR_Massage_color = RED,Color_t title_Massage_color = BLUE,String title="ERROR",bool filled_or_not = Fill_shape,int x = 100,int y = 70,int w = 160,int h = 240,int max_lines_of_masseage_error =5,int max_char_in_one_line = 20);
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
void SEDHOM_Widgets::Big_frame_widget(Color_t color,Color_t Background)
{
  Icon.fill_Rectangle(1,1,320-2,480-2,5,color);
  Icon.fill_Rectangle(1+2,1+2,320-2-4,480-2-4,5,Background);

  Icon.fill_Rectangle(1,60+3,3,480-2,5,color);
}
void SEDHOM_Widgets::ERROR_Massage_Widget(String masseage,Color_t Background,Color_t color,Color_t color_txt,Color_t ERROR_Massage_color ,Color_t title_Massage_color ,String title,bool filled_or_not ,int x ,int y ,int w ,int h ,int max_lines_of_masseage_error ,int max_char_in_one_line )
{
  #define x_start 100
  #define y_start 70
  // draw box of error masseage
  Icon.fill_Rectangle(x_start,y_start,w,h,5,color);
  Icon.fill_Rectangle(x_start+3,y_start+3,w-6,h-6,5,Background);
  // draw box and exit button
  Icon.fill_Rectangle(x_start+h-40,y_start,40,40,5,color);
  Icon.fill_Rectangle(x_start+h-40+3,y_start+3,40-6,40-6,5,Background);
  Icon.fill_Circle(x_start+h-40+20,y_start+20,6,RED);
  // draw txt of title messaage
  if(title.length() > 7)
  {
     Icon.Text_cpp(x_start+10,y_start+20,BigFont,title_Massage_color,title);
  }
  else
  {
     Icon.Text_cpp(x_start+60,y_start+20,BigFont,title_Massage_color,title);
  }
  // draw Wrongmassage
  Icon.Warning_Icon(x_start+h-40,y_start+80,Color_Yellow,RED,Background,filled_or_not);
  // draw text of error message

  int lineHeight = 15;
  int messageLength = masseage.length();
  int startY = y_start + 50;

  for (int i = 0; i < messageLength; i += max_char_in_one_line)
  {
    String line = masseage.substring(i, i + max_char_in_one_line);
      if (startY > max_lines_of_masseage_error * lineHeight + y_start + 50) {
        break; // Stop if the maximum number of lines is exceeded
      }
        Icon.Text_cpp(
        x_start + 10,
        startY ,
        SmallFont,
        ERROR_Massage_color,
        line
    );
    startY += lineHeight;
  }
  // draw ok button
  Icon.fill_Rectangle(x_start+20,y_start+w-40,30,60,5,color);
  Icon.fill_Rectangle(x_start+20+3,y_start+w-40+3,30-6,60-6,5,Background);
  Icon.TEXT(x_start+32,y_start+w-18,BigFont,color_txt,"OK");
  // draw close button
  Icon.fill_Rectangle(x_start+h-80,y_start+w-40,30,60,5,color);
  Icon.fill_Rectangle(x_start+h-80+3,y_start+w-40+3,30-6,60-6,5,Background);
  Icon.TEXT(x_start+h-80+8,y_start+w-18,BigFont,color_txt,"Out");
  
}


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#endif // !SEDHOM_WIDGETS_H_