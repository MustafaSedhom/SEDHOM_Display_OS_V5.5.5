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
    SEDHOM_Icons Icons;
    // include touch to handle all widgets
    SEDHOM_Touch Touch;
  public:
    // set mode of widgets
    void set_widgets_mode(Color_t mode = Color_Black);
    // Draw Widgets Function
    void APP_Bar_Widget(bool show_back_arrow = true,WIFI_STATUS_t WIFI_state = WIFI_Status_connected_level_2_half,BLUETOOTH_STATUS_t Bluetooth_state = BLuetooth_Status_open_and_not_connected,int Battery_Value = 22,Time_Data_t time = {12,33,17,"Am"},Color_t Wifi_on = Color_Blue,Color_t Wifi_off= Color_DarkGrey,Color_t BLE_color= Color_Yellow,Color_t Battery_color = Color_Green,Color_t Time_color = Color_Magenta,Color_t Reverse_color = Color_Blue,Color_t Background=Color_Black);
    void Big_frame_widget(Color_t color = Color_White,Color_t Background = Color_Black);
    void ERROR_Massage_Widget(String massage = "SEDHOM Display OS Error",Color_t Background = Color_Black,Color_t color=MAGENTA,Color_t color_txt=WHITE,Color_t ERROR_Massage_color = RED,Color_t title_Massage_color = BLUE,String title="ERROR",Shape_filled_t filled = Shape_Fill,int x = 100,int y = 70,int w = 240,int h = 160,int max_lines_of_massage_error =5,int max_char_in_one_line = 20);
    void Drawer_Widget(String Drawer_name = "Drawer",bool show_exit_icon = true,Color_t Drawer_color = Color_Magenta,Color_t Drawer_border_color = Color_White,Color_t Drawer_name_color = Color_White,Color_t exit_button_color = Color_Red);
    void Delete_Drawer_Widget();
    void Handle_Drawer_Widget(Icon_Data_t Icon_menu = {{30,90},Color_Blue,Color_Black},int menu_icon_number = 5,String Drawer_name = "Drawer",bool show_exit_icon = true,Color_t Drawer_color = Color_Magenta,Color_t Drawer_border_color = Color_White,Color_t Drawer_name_color = Color_White,Color_t exit_button_color = Color_Red);



};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SEDHOM_Widgets::set_widgets_mode(Color_t mode)
{
  Icons.Set_Mode(mode);
}
void SEDHOM_Widgets::APP_Bar_Widget(bool show_back_arrow,WIFI_STATUS_t WIFI_state,BLUETOOTH_STATUS_t Bluetooth_state,int Battery_Value,Time_Data_t time,Color_t Wifi_on,Color_t Wifi_off,Color_t BLE_color,Color_t Battery_color,Color_t Time_color,Color_t Reverse_color,Color_t Background)
{
  if(show_back_arrow)
  {
    Icons.Arrow_Icon({20,30,Reverse_color,(Background == Black) ? white : Black},Direction_Right,(Background == Color_Black) ? Color_White : Color_Black);
  }
  else
  {
    Icons.Power_off_Icon({30,30,Reverse_color,(Background == Black) ? Black : white});
  }
  Icons.WIFI_Icon({373,38,Wifi_on,Background},Wifi_off,WIFI_state);
  Icons.Bluetooth_Icon({330,12,BLE_color,Background},Bluetooth_state);
  Icons.Battery_Icon({410,15,Battery_color,Background},Battery_Value,(Background == Black) ? white : Black);
  Icons.Display_Time_Icon({130,20,Time_color,Background},time);
}
void SEDHOM_Widgets::Big_frame_widget(Color_t color,Color_t Background)
{
  Icons.Rectangle({{1,1},{480-2,320-2},5,Shape_Fill,color});
  Icons.Rectangle({{1+2,1+2},{480-2-4,320-2-4},5,Shape_Fill,Background});

  Icons.Rectangle({{1,60+3},{480-2,3},5,Shape_Fill,color});
}
void SEDHOM_Widgets::ERROR_Massage_Widget(String massage,Color_t Background,Color_t color,Color_t color_txt,Color_t ERROR_Massage_color ,Color_t title_Massage_color ,String title,Shape_filled_t filled ,int x ,int y ,int w ,int h ,int max_lines_of_massage_error ,int max_char_in_one_line )
{
  #define x_start 100
  #define y_start 70
  // draw box of error massage
  Icons.Rectangle({{x_start,y_start},{w,h},5,Shape_Fill,color});
  Icons.Rectangle({{x_start+3,y_start+3},{w-6,h-6},5,Shape_Fill,Background});
  // draw box and exit button
  Icons.Rectangle({{x_start+w-40,y_start},{40,40},5,Shape_Fill,color});
  Icons.Rectangle({{x_start+w-40+3,y_start+3},{40-6,40-6},5,Shape_Fill,Background});
  Icons.Circle({{x_start+w-40+20,y_start+20},6,Shape_Fill,RED});
  // draw txt of title message
  if(title.length() > 7)
  {
     Icons.Text({x_start+10,y_start+20},FONT_BIG,title_Massage_color,title);
  }
  else
  {
     Icons.Text({x_start+60,y_start+20},FONT_BIG,title_Massage_color,title);
  }
  // draw Wrongmessage
  Icons.Warning_Icon({x_start+w-40,y_start+80,Color_Yellow,Background},RED,filled);
  // draw Text of error message

  int lineHeight = 15;
  int messageLength = massage.length();
  int startY = y_start + 50;

  for (int i = 0; i < messageLength; i += max_char_in_one_line)
  {
    String line = massage.substring(i, i + max_char_in_one_line);
      if (startY > max_lines_of_massage_error * lineHeight + y_start + 50) {
        break; // Stop if the maximum number of lines is exceeded
      }
        Icons.Text(
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
  Icons.Rectangle({{x_start+20,y_start+h-40},{60,30},5,Shape_Fill,color});
  Icons.Rectangle({{x_start+20+3,y_start+h-40+3},{60-6,30-6},5,Shape_Fill,Background});
  Icons.Text_C({x_start+32,y_start+h-18},FONT_BIG,color_txt,"OK");
  // draw close button
  Icons.Rectangle({{x_start+w-80,y_start+h-40},{60,30},5,Shape_Fill,color});
  Icons.Rectangle({{x_start+w-80+3,y_start+h-40+3},{60-6,30-6},5,Shape_Fill,Background});
  Icons.Text_C({x_start+w-80+8,y_start+h-18},FONT_BIG,color_txt,"Out");
  
}
void SEDHOM_Widgets::Drawer_Widget(String Drawer_name,bool show_exit_icon ,Color_t Drawer_color,Color_t Drawer_border_color,Color_t Drawer_name_color,Color_t exit_button_color)
{
  #define pos_x    3
  #define pos_y    0
  // draw basic shape
  Icons.Rectangle({{pos_x+5,pos_y+68},{150,246},10,Shape_Fill,Drawer_border_color});
  Icons.Rectangle({{pos_x+8,pos_y+71},{144,240},8,Shape_Fill,Drawer_color});
  // draw exit icon
  if(show_exit_icon)
  { 
    Icons.Circle({{pos_x+130,pos_y+90},15,Shape_Fill,exit_button_color});
    Icons.Text_C({pos_x+123,pos_y+99},FONT_BIG,Drawer_color,"X");
  }
  // draw Drawer_name text
  Icons.Text({pos_x+15,pos_y+98},FONT_BIG,Drawer_name_color,Drawer_name);
  Icons.Divider({{pos_x+25,pos_y+110},Drawer_border_color,Drawer_color},VERTICAL,100,2);
  // Drawer content
  #define Icon_color Color_Blue
  Icons.Control_Icon({{60,125},Icon_color,Drawer_color});
  Icons.Divider({{pos_x+25,pos_y+170},Drawer_border_color,Drawer_color},VERTICAL,100,2);
  Icons.Home_Icon({{50,180},Icon_color,Drawer_color});
  Icons.Divider({{pos_x+25,pos_y+240},Drawer_border_color,Drawer_color},VERTICAL,100,2);
  Icons.Setting_Icon({{50,250},Icon_color,Drawer_color});
}
void SEDHOM_Widgets::Delete_Drawer_Widget()
{
  Icons.Rectangle({{4,67},{160,250},10,Shape_Fill,Color_Black});
}
void SEDHOM_Widgets::Handle_Drawer_Widget(Icon_Data_t Icon_menu,int menu_icon_number,String Drawer_name,bool show_exit_icon ,Color_t Drawer_color,Color_t Drawer_border_color,Color_t Drawer_name_color,Color_t exit_button_color)
{
  static bool var = false;
    if(!var)
    {
     if(Touch.onTap({{Icon_menu.coordinate.x-10,Icon_menu.coordinate.y-10},{40,40}}))
      {
       Drawer_Widget(Drawer_name,show_exit_icon,Drawer_color,Drawer_border_color,Drawer_name_color,exit_button_color);
      var = true;
      }
    }
    if(var)
    {
      if(Touch.onTap({{110,70},{40,40}}))
      {
          Delete_Drawer_Widget();
          var = false;
          switch (menu_icon_number)
          {
          case 1:
            Icons.Menu_Icon_1(Icon_menu);
            break;
          case 2:
            Icons.Menu_Icon_2(Icon_menu);
            break;
          case 3:
            Icons.Menu_Icon_3(Icon_menu);
            break;
          case 4:
            Icons.Menu_Icon_4(Icon_menu);
            break;
          
          default:
           Icons.Menu_Icon_5(Icon_menu);
            break;
          }
      }
    }
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#endif // !SEDHOM_WIDGETS_H_