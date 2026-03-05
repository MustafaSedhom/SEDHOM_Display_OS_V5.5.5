#ifndef SEDHOM_OS_ICONS_H_
#define SEDHOM_OS_ICONS_H_
//////////////////////////////////////////////////////////////////////////////////////////
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Basic_Shapes.h"
#include "SEDHOM_Text.h"
#include "SEDHOM_Effects.h"
///////////////////////////////////////////////////////////////////////////
// Icons class
class SEDHOM_Icons : public SEDHOM_Basic_Shapes , public SEDHOM_Text ,public SEDHOM_Effects , public SEDHOM_Colors
{
  private:
        uint16_t mode;
        
  public:
        SEDHOM_Icons()
        {
        } 
        #define default_parameter_for_icon  {{150,80},Magenta,Black}
        #define default_parameter_for_text  {FONT_BIG,Blue,"Text"}
        // to set and handling mode
        void Set_Mode(Color_t Mode){mode = Mode;}
        // Draw SEDHOM Icons
        void WIFI_Icon(Icon_Data_t Icon = default_parameter_for_icon ,Color_t color_off = DarkGrey,WIFI_STATUS_t state = WIFI_Status_connected_level_4_full);
        void Battery_Icon(Icon_Data_t Icon = default_parameter_for_icon  ,int range = 50 ,Color_t txt_color = White ,bool low_charge_red_color = true);
        void Home_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Setting_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Add_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void SD_Card_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Control_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Sensor_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Power_off_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Bluetooth_Icon(Icon_Data_t Icon = default_parameter_for_icon ,BLUETOOTH_STATUS_t connect_status = BLuetooth_Status_open_and_connected);
        void Button_Icon(Icon_Data_t Icon = default_parameter_for_icon,bool print_on_and_off = 0);
        void Display_Time_Icon(Icon_Data_t Icon = default_parameter_for_icon , Time_Data_t time = {5,13,42,"AM"});
        void Terminal_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void About_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Display_Date_Icon(Icon_Data_t Icon =default_parameter_for_icon,Date_Data_t Date = {2026,2,16,"Feb","Mon"},Color_t Text_color = BLUE);
        void Arrow_Icon(Icon_Data_t Icon = default_parameter_for_icon,Direction_t Dir = Direction_Right,Color_t border_color = -1);
        void Color_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Time_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Date_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Switch_Icon(Icon_Data_t Icon = default_parameter_for_icon,Color_t color_off = RED,Color_t thumb_color = WHITE,Color_t txt_color = WHITE,SWITCH_STATUS_t state = SWITCH_State_ON);
        void label_Icon(Icon_Data_t Icon = default_parameter_for_icon ,Area_t area = {100,50},int Border = 3,Color_t color_str_in_label = Magenta,String string_in_label = "Label");
        void slider_Icon(Icon_Data_t Icon = default_parameter_for_icon,int h = 200,byte_t range =50 ,Color_t color_not_active = Color_DarkGrey ,Color_t ball_color = WHITE,Color_t box_color = RED,Color_t range_in_box_color = BLUE);
        void file_Icon(Icon_Data_t Icon = default_parameter_for_icon,Color_t Border_color = RED,Color_t file_extend_color = Color_Blue,String file_extend = "txt");
        void folder_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Divider(Icon_Data_t Icon = default_parameter_for_icon,Orientation_t orientation = VERTICAL,int length = 50,int thickness = 5);
        void ID_Card_Icon(Icon_Data_t Icon = default_parameter_for_icon, User_ID_Data_t User = {} ,Color_t main_font_color = RED,Color_t font_color = Blue);
        void Joy_Stick_Icon(Icon_Data_t Icon = default_parameter_for_icon ,Coordinate_t thumb = {150,80} ,int thumb_size = 15,Color_t Border_color = BLUE,Color_t thumb_color = white,Color_t Color_inside_arrow = BLACK);
        void Temperature_Meter_Icon(Icon_Data_t Icon = default_parameter_for_icon,Color_t Border = WHITE,int value = 50,bool show_val_dashes = true);
        void Tone_Icon(Icon_Data_t Icon = default_parameter_for_icon,bool is_muted_or_not = false);
        void Sound_value_Icon(Icon_Data_t Icon = default_parameter_for_icon,int value = 50,Color_t thickness_color = GREEN,bool thickness_or_not = false);
        void Video_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Block_Icon(Icon_Data_t Icon = default_parameter_for_icon,bool open_or_closed = false);
        void Signal_Icon(Icon_Data_t Icon = default_parameter_for_icon,SIGNAL_STATUS_t state = Signal_Status_Signal_level_3,Color_t color_off = DarkGrey);
        void Bell_Icon(Icon_Data_t Icon = default_parameter_for_icon,bool mute_or_not = false,bool filled_or_not = true);
        void Menu_Icon_1(Icon_Data_t Icon = default_parameter_for_icon); // : : :
        void Menu_Icon_2(Icon_Data_t Icon = default_parameter_for_icon); // ...
        void Menu_Icon_3(Icon_Data_t Icon = default_parameter_for_icon); // :
        void Menu_Icon_4(Icon_Data_t Icon = default_parameter_for_icon); // : :
        void Menu_Icon_5(Icon_Data_t Icon = default_parameter_for_icon); // = 
        void Moon_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Sun_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Check_Box_Icon(Icon_Data_t Icon = default_parameter_for_icon,bool status = true,Color_t check_color = GREEN,Color_t checked_fill_color = Black);
        void Radio_Button_Icon(Icon_Data_t Icon = default_parameter_for_icon,bool status = true,Color_t check_color = Green);
        void Text_Feild_Icon(  Icon_Data_t Icon = default_parameter_for_icon,Text_Data_t Text = {} ,int length = 200,int max_char = 10);
        void Warning_Icon( Icon_Data_t Icon = default_parameter_for_icon,Color_t txt_color = RED,Shape_filled_t filled = Shape_Draw );
        void Chandelier_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Smart_TV_Icon(Icon_Data_t Icon = default_parameter_for_icon,Color_t WIFI_icon = White);
        void Air_Conditioner_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Close_Icon(Icon_Data_t Icon = default_parameter_for_icon);
        void Star_Icon(Icon_Data_t Icon = default_parameter_for_icon);
};
// define all functions and Draw all Widgets and icons
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// SEDHOM Icons
void SEDHOM_Icons::WIFI_Icon(Icon_Data_t Icon,Color_t color_off,WIFI_STATUS_t state)
{
    if(state != WIFI_Status_not_connected)
    {
        uint16_t one=RED,two=RED,three=RED,four=RED;
        if(state==WIFI_Status_no_internet){one=color_off;two=color_off;three=color_off;four=color_off;}
        else if(state==WIFI_Status_connected_level_1){one=color_off;two=color_off;three=color_off;four=Icon.color;}
        else if(state==WIFI_Status_connected_level_2_half){one=color_off;two=color_off;three=Icon.color;four=Icon.color;}
        else if(state==WIFI_Status_connected_level_3){one=color_off;two=Icon.color;three=Icon.color;four=Icon.color;}
        else if(state==WIFI_Status_connected_level_4_full){one=Icon.color;two=Icon.color;three=Icon.color;four=Icon.color;}
        Circle({{Icon.coordinate.x,Icon.coordinate.y},20,Shape_Fill,one});
        Circle({{Icon.coordinate.x,Icon.coordinate.y},20-3,Shape_Fill,Icon.Background});
        Circle({{Icon.coordinate.x,Icon.coordinate.y},20-6,Shape_Fill,two});
        Circle({{Icon.coordinate.x,Icon.coordinate.y},20-9,Shape_Fill,Icon.Background});
        Circle({{Icon.coordinate.x,Icon.coordinate.y},20-12,Shape_Fill,three});
        Circle({{Icon.coordinate.x,Icon.coordinate.y},20-15,Shape_Fill,Icon.Background});
        Rectangle({{Icon.coordinate.x-21,Icon.coordinate.y},{42,20},5,Shape_Fill,Icon.Background});
        Triangle({{Icon.coordinate.x-3,Icon.coordinate.y+5},{Icon.coordinate.x+24,Icon.coordinate.y+5},{Icon.coordinate.x+21,Icon.coordinate.y-20},Shape_Fill,Icon.Background});
        Triangle({{Icon.coordinate.x+3,Icon.coordinate.y+5},{Icon.coordinate.x-24,Icon.coordinate.y+5},{Icon.coordinate.x-21,Icon.coordinate.y-20},Shape_Fill,Icon.Background});
        Circle({{Icon.coordinate.x,Icon.coordinate.y},20-18,Shape_Fill,four});
        if(state==WIFI_Status_no_internet)
        {
        Text_C({Icon.coordinate.x+8,Icon.coordinate.y},FONT_BIG,color_off,"!");
        }
    }
    else if(state==WIFI_Status_not_connected)
    {
      Rectangle({{Icon.coordinate.x-15,Icon.coordinate.y-27},{37,38},5,Shape_Fill,Icon.Background});
    }
    Rectangle({{Icon.coordinate.x-10,Icon.coordinate.y+13},{20,10},0,Shape_Fill,Icon.Background});
} 
void SEDHOM_Icons::Battery_Icon(Icon_Data_t Icon ,int range,Color_t txt_color,bool low_charge_red_color)
{
    int txt_x=0;
    int txt_y_index = Icon.coordinate.y+22;
    uint16_t color_Battery;
    if(low_charge_red_color==1)
    {
        if(range<20){color_Battery=RED; txt_x=(range>=10)?Icon.coordinate.x-60:Icon.coordinate.x-45;txt_color= ((Icon.Background == Color_Black)?Color_White : Color_Black );}
        else if(range>=20){color_Battery=Icon.color;txt_x=(range==100)?Icon.coordinate.x-65:Icon.coordinate.x-58;}
    }
    else if(low_charge_red_color==0)
    {
        if(range<20){color_Battery=GREEN; txt_x=(range>=10)?Icon.coordinate.x-53:Icon.coordinate.x-45;}
        else if(range>=20){color_Battery=GREEN;txt_x=(range==100)?Icon.coordinate.x-65:Icon.coordinate.x-58;}
    }
    int rangeB=map(range,0,100,5,45);
    Rectangle({{Icon.coordinate.x, Icon.coordinate.y}, {50,30}, 5,Shape_Fill, color_Battery});
    Rectangle({{Icon.coordinate.x+3, Icon.coordinate.y+3}, {50-6,30-6}, 5,Shape_Fill, Icon.Background});
    Rectangle({{Icon.coordinate.x+50-1,Icon.coordinate.y+10},{10,10},0,Shape_Fill,color_Battery});
    Rectangle({{Icon.coordinate.x+2,Icon.coordinate.y+3},{rangeB,30-6},5,Shape_Fill,color_Battery});
    Text({txt_x+60,txt_y_index},FONT_BIG,txt_color,String(range) + "%");
}
void SEDHOM_Icons::Home_Icon(Icon_Data_t Icon)
{
    
    Triangle({{Icon.coordinate.x+30,Icon.coordinate.y},{(Icon.coordinate.x+30)+25,Icon.coordinate.y+15},{(Icon.coordinate.x+30)-25,Icon.coordinate.y+15},Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x+10, Icon.coordinate.y+12},{40,25},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x+23, Icon.coordinate.y+20},{15,20},5,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Setting_Icon(Icon_Data_t Icon)
{
    Circle({{Icon.coordinate.x-10, Icon.coordinate.y},10,Shape_Fill, Icon.color});
    Circle({{Icon.coordinate.x-10, Icon.coordinate.y-10}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.coordinate.x-10, Icon.coordinate.y+10}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.coordinate.x, Icon.coordinate.y-5}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.coordinate.x, Icon.coordinate.y+5}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.coordinate.x-20, Icon.coordinate.y-5}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.coordinate.x-20, Icon.coordinate.y+5}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.coordinate.x-10, Icon.coordinate.y}, 5,Shape_Fill, Icon.Background});
}
void SEDHOM_Icons::Add_Icon(Icon_Data_t Icon)
{
    Rectangle({{Icon.coordinate.x+15,Icon.coordinate.y-2+15},{30,5},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x+13+15,Icon.coordinate.y-14+15},{5,30},5,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::SD_Card_Icon(Icon_Data_t Icon)
{
    Rectangle({{Icon.coordinate.x-5, Icon.coordinate.y-5},{40,45},5,Shape_Fill,WHITE});
    Rectangle({{Icon.coordinate.x, Icon.coordinate.y},{30,35},5,Shape_Fill,BLACK});
    Rectangle({{Icon.coordinate.x+15,Icon.coordinate.y},{17,8},5,Shape_Fill,WHITE});
    Triangle({{Icon.coordinate.x+30,Icon.coordinate.y+8},{Icon.coordinate.x+17,Icon.coordinate.y+8},{Icon.coordinate.x+17,Icon.coordinate.y},Shape_Fill,BLACK});
    Rectangle({{Icon.coordinate.x+4,Icon.coordinate.y+20},{2,10},5,Shape_Fill,YELLOW});
    Rectangle({{Icon.coordinate.x+11,Icon.coordinate.y+20},{2,10},5,Shape_Fill,YELLOW});
    Rectangle({{Icon.coordinate.x+18,Icon.coordinate.y+20},{2,10},5,Shape_Fill,YELLOW});
    Rectangle({{Icon.coordinate.x+25,Icon.coordinate.y+20},{2,10},5,Shape_Fill,YELLOW});
    Rectangle({{Icon.coordinate.x+12,Icon.coordinate.y+1},{5,8},0,Shape_Fill,BLACK});
}
void SEDHOM_Icons::Control_Icon(Icon_Data_t Icon)
{
    Rectangle({{Icon.coordinate.x, Icon.coordinate.y},{40,3},5,Shape_Fill, Icon.color});
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y+15},{40,3},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y+30},{40,3},5,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x+28,Icon.coordinate.y+1},6,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x+12,Icon.coordinate.y+16},6,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x+31-2,Icon.coordinate.y+30+1},6,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x+28,Icon.coordinate.y+1},3,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+12,Icon.coordinate.y+16},3,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+29,Icon.coordinate.y+31},3,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Sensor_Icon(Icon_Data_t Icon)
{
    Rectangle({{Icon.coordinate.x+3,Icon.coordinate.y},{30,10},5,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x+18, Icon.coordinate.y+10},5,Shape_Fill,Icon.color});
    Line({{Icon.coordinate.x+12,Icon.coordinate.y+17},{Icon.coordinate.x+6,Icon.coordinate.y+25},Icon.color});
    Line({{Icon.coordinate.x+23,Icon.coordinate.y+17},{Icon.coordinate.x+30,Icon.coordinate.y+25},Icon.color});
    Line({{Icon.coordinate.x+18,Icon.coordinate.y+17},{Icon.coordinate.x+18,Icon.coordinate.y+25},Icon.color});
}
void SEDHOM_Icons::Power_off_Icon(Icon_Data_t Icon)
{
    Circle({{Icon.coordinate.x,Icon.coordinate.y},20,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x,Icon.coordinate.y},17,Shape_Fill,Icon.Background});
    Rectangle({{Icon.coordinate.x-8, Icon.coordinate.y-20},{16,20}, 0,Shape_Fill,Icon.Background});
    Rectangle({{Icon.coordinate.x-1, Icon.coordinate.y-23},{2,23},0,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Bluetooth_Icon(Icon_Data_t Icon,BLUETOOTH_STATUS_t connect_status)
{
 if(connect_status == BLuetooth_Status_open_and_not_connected || connect_status == BLuetooth_Status_open_and_connected )
 {
    Triangle({{(Icon.coordinate.x) , (Icon.coordinate.y)} , {(Icon.coordinate.x+15) , (Icon.coordinate.y+10)} , {(Icon.coordinate.x) , (Icon.coordinate.y+20)},Shape_Fill , Icon.color});
    Triangle({{(Icon.coordinate.x) , (Icon.coordinate.y)+15} , {(Icon.coordinate.x+15) , (Icon.coordinate.y+10)+15} , {(Icon.coordinate.x) , (Icon.coordinate.y+20)+15},Shape_Fill , Icon.color});
    Triangle({{(Icon.coordinate.x-15) , (Icon.coordinate.y+5) },{ (Icon.coordinate.x) , (Icon.coordinate.y+16)} , {(Icon.coordinate.x-15) , (Icon.coordinate.y+30)},Shape_Fill , Icon.color});
    Triangle({{(Icon.coordinate.x-15)+2 , (Icon.coordinate.y+5)+3 }, {(Icon.coordinate.x)-2 , (Icon.coordinate.y+16)} , {(Icon.coordinate.x-15)+2 , (Icon.coordinate.y+30)-3},Shape_Fill , Icon.Background});
    Triangle({{(Icon.coordinate.x)+2 , (Icon.coordinate.y)+3 },{ (Icon.coordinate.x+15)-2 , (Icon.coordinate.y+10) }, {(Icon.coordinate.x)+2 , (Icon.coordinate.y+20)-4},Shape_Fill , Icon.Background});
    Triangle({{((Icon.coordinate.x))+2 , ((Icon.coordinate.y)+15)+3} , {((Icon.coordinate.x+15))-2 , ((Icon.coordinate.y)+15)+10 }, {((Icon.coordinate.x))+2 , ((Icon.coordinate.y+20)+15)-3},Shape_Fill , Icon.Background});
    Rectangle({{Icon.coordinate.x-18, Icon.coordinate.y+2},{6,30},0,Shape_Fill, Icon.Background});
    if(connect_status == BLuetooth_Status_open_and_connected)
    {
        Circle({{Icon.coordinate.x-10, Icon.coordinate.y+17}, 1,Shape_Fill, Icon.color});
        Circle({{Icon.coordinate.x+13, Icon.coordinate.y+18}, 1,Shape_Fill, Icon.color});
    }
 }
 else
 {
    Rectangle({{Icon.coordinate.x-20, Icon.coordinate.y-10},{42,50},0,Shape_Fill, Icon.Background});
 }
}
void SEDHOM_Icons::Button_Icon(Icon_Data_t Icon,bool print_on_and_off)
{
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{50,20} ,30,Shape_Fill,GREEN});
    Circle({{Icon.coordinate.x+39,Icon.coordinate.y+10},7,Shape_Fill,WHITE});
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y+25},{50,20},30,Shape_Fill,RED});
    Circle({{Icon.coordinate.x+10,Icon.coordinate.y+35},7,Shape_Fill,WHITE});

    if(print_on_and_off)
    {
        Text_C({Icon.coordinate.x+8, Icon.coordinate.y+16},FONT_SMALL,WHITE,"ON");
        Text_C({Icon.coordinate.x+23, Icon.coordinate.y+41},FONT_SMALL,WHITE,"OFF");
    }
}
void SEDHOM_Icons::Display_Time_Icon(Icon_Data_t Icon,Time_Data_t time)
{
    //hour
    Text({Icon.coordinate.x,Icon.coordinate.y+35},FONT_SEVENSEGMENT,Icon.color,(time.hour < 10) ? ("0" + String(time.hour)) : String(time.hour));
    // minutes
    Text({Icon.coordinate.x+83,Icon.coordinate.y+35},FONT_SEVENSEGMENT,Icon.color,(time.minute < 10) ? ("0" + String(time.minute)) : String(time.minute));
    // separator
    Circle({{Icon.coordinate.x+73,Icon.coordinate.y},5,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x+73,Icon.coordinate.y+20},5,Shape_Fill,Icon.color});
    //sec
    Text({Icon.coordinate.x+146,Icon.coordinate.y},FONT_BIG,Icon.color,String(time.sec));
    // time name
    Text({Icon.coordinate.x+146,Icon.coordinate.y+38},FONT_BIG,Icon.color,String(time.time_name));
}
void SEDHOM_Icons::Terminal_Icon(Icon_Data_t Icon)
{
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{50,50},5,Shape_Fill,WHITE});
    Rectangle({{Icon.coordinate.x+3,Icon.coordinate.y+3},{44,44},5,Shape_Fill,BLACK});
    Text_C({Icon.coordinate.x+10,Icon.coordinate.y+30},FONT_BIG,GREEN,">_");
}
void SEDHOM_Icons::About_Icon(Icon_Data_t Icon)
{
    Circle({{Icon.coordinate.x,Icon.coordinate.y},20,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x,Icon.coordinate.y},17,Shape_Fill,Icon.Background});
    Text_C({Icon.coordinate.x-6,Icon.coordinate.y+8},FONT_BIG,Icon.color,"!");
}
void SEDHOM_Icons::Display_Date_Icon(Icon_Data_t Icon,Date_Data_t Date,Color_t Text_color)
{
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{130,130},15,Shape_Fill,Icon.color});
    Text({Icon.coordinate.x+42,Icon.coordinate.y+40},FONT_BIG,Text_color,String(Date.week_day_name));
    Text({Icon.coordinate.x+47,Icon.coordinate.y+65},FONT_BIG,Text_color,String(Date.Day));
    Text({Icon.coordinate.x+42,Icon.coordinate.y+90},FONT_BIG,Text_color,String(Date.month_name));
    Text({Icon.coordinate.x+35,Icon.coordinate.y+115},FONT_BIG,Text_color,String(Date.year));

    int x_start = Icon.coordinate.x + 15;
    int y_start = Icon.coordinate.y;
    int x_end_start = Icon.coordinate.x + 10;
    int y_end_start = Icon.coordinate.y + 8;

    for (int offset_block = 0; offset_block <= 100; offset_block += 20) // 0, 20, 40, 60, 80, 100
    {
        for (int i = 0; i <= 4; i++) // 0,1,2,3,4
        {
          Line({{(x_start + i + offset_block),y_start},{(x_end_start + i + offset_block),y_end_start},Icon.Background});
        }
    }


    Circle({{Icon.coordinate.x+114-100,Icon.coordinate.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+114-80,Icon.coordinate.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+114-60,Icon.coordinate.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+114-40,Icon.coordinate.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+114-20,Icon.coordinate.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+114,Icon.coordinate.y+8},4,Shape_Fill,Icon.Background});

}
void SEDHOM_Icons::Arrow_Icon(Icon_Data_t Icon,Direction_t Dir,Color_t border_color)
{
  switch (Dir)
  {
  case Direction_Up:
    Triangle({{Icon.coordinate.x-20-6,Icon.coordinate.y+25+3},{Icon.coordinate.x,Icon.coordinate.y-6},{Icon.coordinate.x+20+6,Icon.coordinate.y+25+3},Shape_Fill,border_color});
    Triangle({{Icon.coordinate.x-20,Icon.coordinate.y+25},{Icon.coordinate.x,Icon.coordinate.y},{Icon.coordinate.x+20,Icon.coordinate.y+25},Shape_Fill,Icon.color});
    Border_Rectangle({Icon.coordinate.x-10,Icon.coordinate.y+25,border_color,Icon.color},{20,20},5,3);
    Rectangle({{Icon.coordinate.x-10+3,Icon.coordinate.y+25},{20-6,20-3},0,Shape_Fill,Icon.color});
    break;
  case Direction_Down:
    Triangle({{Icon.coordinate.x-20-6,Icon.coordinate.y+25-3},{Icon.coordinate.x,Icon.coordinate.y-6+60},{Icon.coordinate.x+20+6,Icon.coordinate.y+25-3},Shape_Fill,border_color});
    Triangle({{Icon.coordinate.x-20,Icon.coordinate.y+25},{Icon.coordinate.x,Icon.coordinate.y+50},{Icon.coordinate.x+20,Icon.coordinate.y+25},Shape_Fill,Icon.color});
    Border_Rectangle({Icon.coordinate.x-10,Icon.coordinate.y+5,border_color,Icon.color},{20,20},5,3);
    Rectangle({{Icon.coordinate.x-10+3,Icon.coordinate.y+8},{20-6,20-3},0,Shape_Fill,Icon.color});
    break;
  case Direction_Right:
    Triangle({{Icon.coordinate.x-6,Icon.coordinate.y},{Icon.coordinate.x+25+3,Icon.coordinate.y-15-6},{Icon.coordinate.x+25+3,Icon.coordinate.y+15+6},Shape_Fill,border_color});
    Triangle({{Icon.coordinate.x,Icon.coordinate.y},{Icon.coordinate.x+25,Icon.coordinate.y-15},{Icon.coordinate.x+25,Icon.coordinate.y+15},Shape_Fill,Icon.color});
    Border_Rectangle({Icon.coordinate.x+25,Icon.coordinate.y-8-1,border_color,Icon.color},{25,18},5,3);
    Rectangle({{Icon.coordinate.x+22,Icon.coordinate.y-8+3-1},{12,12},5,Shape_Fill,Icon.color});
    break;
  case Direction_Left:
    Triangle({{Icon.coordinate.x+6+50,Icon.coordinate.y},{Icon.coordinate.x+25-3,Icon.coordinate.y-15-6},{Icon.coordinate.x+25-3,Icon.coordinate.y+15+6},Shape_Fill,border_color});
    Triangle({{Icon.coordinate.x+50,Icon.coordinate.y},{Icon.coordinate.x+25,Icon.coordinate.y-15},{Icon.coordinate.x+25,Icon.coordinate.y+15},Shape_Fill,Icon.color});
    Border_Rectangle({Icon.coordinate.x,Icon.coordinate.y-8-1,border_color,Icon.color},{25,18},5,3);
    Rectangle({{Icon.coordinate.x+15,Icon.coordinate.y-8+3-1},{12,13},5,Shape_Fill,Icon.color});
    break;

  }
}
void SEDHOM_Icons::Color_Icon(Icon_Data_t Icon)
{
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{30,30},5,Shape_Fill,MAGENTA});
    Rectangle({{Icon.coordinate.x+5,Icon.coordinate.y+5},{30,30},5,Shape_Fill,RED});
    Rectangle({{Icon.coordinate.x+10,Icon.coordinate.y+10},{30,30},5,Shape_Fill,BLUE});
    Rectangle({{Icon.coordinate.x+15,Icon.coordinate.y+15},{30,30},5,Shape_Fill,GREEN});
}
void SEDHOM_Icons::Time_Icon(Icon_Data_t Icon)
{
    Circle({{Icon.coordinate.x,Icon.coordinate.y},20,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x,Icon.coordinate.y},17,Shape_Fill,Icon.Background});
    Rectangle({{Icon.coordinate.x-2,Icon.coordinate.y-14},{3,12},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y-1},{10,3},5,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x,Icon.coordinate.y},4,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Date_Icon(Icon_Data_t Icon)
{
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{45,48},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x+2,Icon.coordinate.y+10},{41,36},5,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+5,Icon.coordinate.y+5},3,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+23,Icon.coordinate.y+5},3,Shape_Fill,Icon.Background});
    Circle({{Icon.coordinate.x+40,Icon.coordinate.y+5},3,Shape_Fill,Icon.Background});
    Text_C({Icon.coordinate.x+20,Icon.coordinate.y+24},FONT_SMALL,Icon.color,"6");
    Text_C({Icon.coordinate.x+12,Icon.coordinate.y+33},FONT_SMALL,Icon.color,"Jun");
    Text_C({Icon.coordinate.x+9,Icon.coordinate.y+46},FONT_SMALL,Icon.color,"2025");
}
void SEDHOM_Icons::Switch_Icon(Icon_Data_t Icon,Color_t color_off,Color_t thumb_color,Color_t txt_color,SWITCH_STATUS_t state)
{
    Color_t State_color = color_off;
    int index = Icon.coordinate.x+57;
    int index_str = Icon.coordinate.x-13;
    String state_str = "OFF";
    State_color = (state == SWITCH_State_ON) ? Icon.color : color_off ;
    index = (state == SWITCH_State_ON) ? (Icon.coordinate.x+20) : (Icon.coordinate.x+80) ;
    index_str = (state == SWITCH_State_ON) ? (Icon.coordinate.x+50) : (Icon.coordinate.x+10) ;
    state_str = (state == SWITCH_State_ON) ? "ON" : "OFF" ;
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{100,40},50,Shape_Fill,State_color});
    Circle({{index,Icon.coordinate.y+20},15,Shape_Fill,thumb_color});
    Text({(index_str),Icon.coordinate.y+28},FONT_BIG,txt_color,state_str);
}
void SEDHOM_Icons::label_Icon(Icon_Data_t Icon ,Area_t area,int Border,Color_t color_str_in_label,String string_in_label)
{
    Color_t label_color_in_func = Icon.color;
    float num = 1;

    if(string_in_label == "OFF" || string_in_label == "off" || num == 0){label_color_in_func = RED;}
    else if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = Icon.color;}
    if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = Icon.color;}

    Border_Rectangle({Icon.coordinate.x,Icon.coordinate.y,label_color_in_func,Icon.Background},area,5,Border);
    Text({Icon.coordinate.x+10,Icon.coordinate.y+(0.6*area.w)},FONT_SMALL,color_str_in_label,string_in_label);
}
void SEDHOM_Icons::slider_Icon(Icon_Data_t Icon ,int h,byte_t range ,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color)
{
    long index = map(range,0,100,0,h);
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{h,10},5,Shape_Fill,color_not_active});
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{index,10},5,Shape_Fill,Icon.color});
    Circle({{Icon.coordinate.x+index,Icon.coordinate.y+5},10,Shape_Fill,((Icon.Background == Color_Black)?Color_White : Color_Black)});
    Border_Rectangle({Icon.coordinate.x+h+15,Icon.coordinate.y-10,box_color,Icon.Background},{40,30},5,3);
    Text({Icon.coordinate.x+h+8+15,Icon.coordinate.y+19-8},FONT_SMALL,range_in_box_color,String(range));
}
void SEDHOM_Icons::file_Icon(Icon_Data_t Icon,Color_t Border_color,Color_t file_extend_color,String file_extend)
{
    Border_Rectangle({Icon.coordinate.x,Icon.coordinate.y,Border_color,Icon.Background},{50,60},5,3);
    Border_Rectangle({Icon.coordinate.x-10,Icon.coordinate.y+30,Border_color,Icon.Background},{30,21},5,3);
    Border_Rectangle({Icon.coordinate.x+29,Icon.coordinate.y-1,Icon.Background,Icon.Background},{30,21},5,3);
    Triangle({{Icon.coordinate.x+6+43,Icon.coordinate.y+20},{Icon.coordinate.x+29,Icon.coordinate.y},{Icon.coordinate.x+29,Icon.coordinate.y+20},Shape_Fill,Border_color});
    Triangle({{Icon.coordinate.x+43,Icon.coordinate.y+18},{Icon.coordinate.x+29+3,Icon.coordinate.y+6},{Icon.coordinate.x+29+3,Icon.coordinate.y+18},Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x+10,Icon.coordinate.y+15},{15,2},5,Shape_Fill,Border_color});
    Rectangle({{Icon.coordinate.x+10,Icon.coordinate.y+25},{30,2},5,Shape_Fill,Border_color});    
    Rectangle({{Icon.coordinate.x+25,Icon.coordinate.y+35},{15,2},5,Shape_Fill,Border_color});
    Rectangle({{Icon.coordinate.x+25,Icon.coordinate.y+45},{15,2},5,Shape_Fill,Border_color});
    Text({Icon.coordinate.x-5,Icon.coordinate.y+46},FONT_SMALL,file_extend_color,file_extend);
}
void SEDHOM_Icons::folder_Icon(Icon_Data_t Icon)
{
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{30,40},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x+28,Icon.coordinate.y+5},{40,20},5,Shape_Fill,Icon.color});
    Border_Rectangle({Icon.coordinate.x+5,Icon.coordinate.y+10,BLACK,WHITE},{60,20},5,1);
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y+20},{68,35},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y+20},{69,1},0,Shape_Fill,BLACK});
}
void SEDHOM_Icons::Divider(Icon_Data_t Icon,Orientation_t orientation,int length,int thickness)
{
  int local_length;
  int local_thickness;
  if(orientation==VERTICAL)
  {
    local_length = length;
    local_thickness = thickness;
  }
  else
  {
    local_length = thickness;
    local_thickness = length;
  }
  
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{local_length,local_thickness},1,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::ID_Card_Icon(Icon_Data_t Icon, User_ID_Data_t User ,Color_t main_font_color,Color_t font_color)
{
    #define x1   Icon.coordinate.x
    #define y1   Icon.coordinate.y

    #define w1    270
    #define h1    200

    Color_t color_id =0;
    if(Icon.color == WHITE) color_id = BLACK;
    else if(Icon.color == BLACK) color_id = WHITE;
    else  color_id = Icon.color;
    Rectangle({{x1-3,y1-3},{w1+6,h1+6},20,Shape_Fill,color_id});
    Rectangle({{x1,y1},{w1,h1},20,Shape_Fill,Icon.color});
    Text_C({((User.is_professor)?x1+60:x1+80),y1+20},FONT_BIG,main_font_color,((User.is_professor)?"PROFESSOR":"STUDENT"));
    Divider({x1+10,y1+35,main_font_color,Icon.Background},VERTICAL,w1-20,3);
    Text_C({x1+30,y1+55},FONT_SMALL,font_color,"IDENTITY CARD");

    Text_C({x1+10,y1+70},FONT_SMALL,main_font_color,((User.is_professor)?"Dr Name":"Name"));
    Text_C({x1+10,y1+85},FONT_SMALL,font_color,User.user_name);

    Text_C({x1+10,y1+100},FONT_SMALL,main_font_color,((User.is_professor)?"University":"Studies at"));
    Text_C({x1+10,y1+115},FONT_SMALL,font_color,User.university);

    Text_C({x1+10,y1+130},FONT_SMALL,main_font_color,"Department");
    Text_C({x1+10,y1+145},FONT_SMALL,font_color,User.department_1);
    Text_C({x1+10,y1+160},FONT_SMALL,font_color,User.department_2);

    Text_C({x1+10,y1+175},FONT_SMALL,main_font_color,"Born");
    Text_C({x1+10,y1+190},FONT_SMALL,font_color,User.Born);

    Rectangle({{x1+160,y1+45},{100,110},0,Shape_Fill,User.image_background});
    
    if(User.default_image)
    {
        Circle({{x1+210,y1+160},40,Shape_Fill,DARKGREY});
        Circle({{x1+210,y1+100},25,Shape_Fill,DARKGREY});
        if(User.eye)
        {
            Circle({{x1+220,y1+97},7,Shape_Fill,BLACK});
            Circle({{x1+220,y1+97},5,Shape_Fill,DARKGREY});
            Circle({{x1+220,y1+97},1,Shape_Fill,BLACK});//eye
            Divider({x1+205,y1+97,Black,Icon.Background},VERTICAL,10,2);
            Circle({{x1+200,y1+97},7,Shape_Fill,BLACK});
            Circle({{x1+200,y1+97},5,Shape_Fill,DARKGREY});
            Circle({{x1+200,y1+97},1,Shape_Fill,BLACK});//eye
            Divider({x1+225,y1+97,Black,Icon.Background},VERTICAL,10,2);
            Divider({x1+185,y1+97,Black,Icon.Background},VERTICAL,10,2);
        }
    }
    Rectangle({{x1+150,y1+155},{120,45},15,Shape_Fill,Icon.color});
    Text_C({x1+157,y1+175},FONT_SMALL,font_color,User.number);
}
void SEDHOM_Icons::Joy_Stick_Icon(Icon_Data_t Icon ,Coordinate_t thumb ,int thumb_size,Color_t Border_color,Color_t thumb_color,Color_t Color_inside_arrow)
{
  Circle({{Icon.coordinate.x,Icon.coordinate.y},50,Shape_Fill,Border_color});
  Circle({{Icon.coordinate.x,Icon.coordinate.y},50-3,Shape_Fill,Icon.color});
  Equilateral_Triangle({{Icon.coordinate.x,Icon.coordinate.y-35},10,Shape_Fill,Direction_Up,Color_inside_arrow});
  Equilateral_Triangle({{Icon.coordinate.x,Icon.coordinate.y+35},10,Shape_Fill,Direction_Down,Color_inside_arrow});
  Equilateral_Triangle({{Icon.coordinate.x+35,Icon.coordinate.y},10,Shape_Fill,Direction_Right,Color_inside_arrow});
  Equilateral_Triangle({{Icon.coordinate.x-35,Icon.coordinate.y},10,Shape_Fill,Direction_Left,Color_inside_arrow});
  int dx = thumb.x - Icon.coordinate.x;
  int dy = thumb.y - Icon.coordinate.y;
  if ((dx*dx + dy*dy) <= (50/2)*(50/2))
  {
      Circle({{thumb.x, thumb.y}, thumb_size,Shape_Fill, thumb_color});
  }
}
void SEDHOM_Icons::Temperature_Meter_Icon(Icon_Data_t Icon,Color_t Border,int value,bool show_val_dashes)
{
  Color_t color_dash =RED;
  value = constrain(value, 0, 100);
  Circle({{Icon.coordinate.x+50/2,Icon.coordinate.y+150+25},50,Shape_Fill,Border});
  Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{50,150},5,Shape_Fill,Border});
  Rectangle({{Icon.coordinate.x+5,Icon.coordinate.y+5},{50-10,150},5,Shape_Fill,Icon.Background});
  Circle({{Icon.coordinate.x+50/2,Icon.coordinate.y+150+25},50-5,Shape_Fill,Icon.Background});
  Circle({{Icon.coordinate.x+50/2,Icon.coordinate.y+150+25},50-13,Shape_Fill,Icon.color});
  int levelHeight = map(value, 0, 100, 0, 140);
  Rectangle({{Icon.coordinate.x+12,Icon.coordinate.y + 150 - levelHeight},{50-24,levelHeight},5,Shape_Fill,Icon.color});
  if(show_val_dashes)
  {
   Text_C({Icon.coordinate.x+55,Icon.coordinate.y+10},FONT_BIG,red,"-100");
    Text_C({Icon.coordinate.x+55,Icon.coordinate.y+135},FONT_BIG,Blue,"-0");
    for (int i=0;i<=10; i++) 
    {
      if(i==3) color_dash = Orange;
      else if(i==8) color_dash = blue;
      Text_C({Icon.coordinate.x+55,Icon.coordinate.y+25+i*10},FONT_BIG,color_dash,"-");
    }
  }
}
void SEDHOM_Icons::Tone_Icon(Icon_Data_t Icon,bool is_muted_or_not)
{
   Circle({{Icon.coordinate.x,Icon.coordinate.y},5,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x,Icon.coordinate.y},5-2,Shape_Fill,Icon.Background});
   Circle({{Icon.coordinate.x+20,Icon.coordinate.y},5,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x+20,Icon.coordinate.y},5-2,Shape_Fill,Icon.Background});
   Rectangle({{Icon.coordinate.x+4,Icon.coordinate.y-20},{2,20},0,Shape_Fill,Icon.color});
   Rectangle({{Icon.coordinate.x+4+20,Icon.coordinate.y-20},{2,20},0,Shape_Fill,Icon.color});
   Rectangle({{Icon.coordinate.x+4,Icon.coordinate.y-20},{20,2},0,Shape_Fill,Icon.color});
   if(is_muted_or_not)
   {   
     Line({{Icon.coordinate.x-5,Icon.coordinate.y-20},{Icon.coordinate.x+32,Icon.coordinate.y-5},Icon.color});    
     Line({{Icon.coordinate.x-5,Icon.coordinate.y-20+1},{Icon.coordinate.x+32,Icon.coordinate.y-5+1},Icon.color});    
   }
}
void SEDHOM_Icons::Sound_value_Icon(Icon_Data_t Icon,int value,Color_t thickness_color,bool thickness_or_not)
{
  int val = value;
  value = constrain(value,0,100);
  value = map(value,0,100,150,0);
  Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{50,150},40,Shape_Fill,thickness_or_not?thickness_color:Icon.color});
  Rectangle({{Icon.coordinate.x+5,Icon.coordinate.y+5},{50-10,150-10},40,Shape_Fill,Icon.Background});
  Rectangle({{Icon.coordinate.x+5,(Icon.coordinate.y+value+5)},{50-10,((val<15)?(0):(150-value-10))},40,Shape_Fill,Icon.color});
  Tone_Icon({Icon.coordinate.x+12,Icon.coordinate.y+130,(val<20)?Icon.color:Icon.Background,(val<20)?Icon.Background:Icon.color},(val==0)?true:false);
}
void SEDHOM_Icons::Video_Icon(Icon_Data_t Icon)
{
   Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{50,35},8,Shape_Fill,Icon.color});
   Equilateral_Triangle({{Icon.coordinate.x+24,Icon.coordinate.y+17},20,Shape_Fill,Direction_Right,Icon.Background});
}
void SEDHOM_Icons::Block_Icon(Icon_Data_t Icon,bool open_or_closed)
{
  if(!open_or_closed)
  {
     Rectangle({{Icon.coordinate.x+21,Icon.coordinate.y-15},{20,30},10,Shape_Fill,Icon.color});
     Rectangle({{Icon.coordinate.x+21+2,Icon.coordinate.y-15+2},{20-4,30-4},10,Shape_Fill,Icon.Background});
     Rectangle({{Icon.coordinate.x+26,Icon.coordinate.y},{26,20},2,Shape_Fill,Icon.Background});
  }
  else
  {
     Rectangle({{Icon.coordinate.x+3,Icon.coordinate.y-15},{20,30},10,Shape_Fill,Icon.color});
     Rectangle({{Icon.coordinate.x+3+2,Icon.coordinate.y-15+2},{20-4,30-4},10,Shape_Fill,Icon.Background});
  }
  Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{26,20},2,Shape_Fill,Icon.color});
  Circle({{Icon.coordinate.x+12,Icon.coordinate.y+6},4,Shape_Fill,Icon.Background});
  Rectangle({{Icon.coordinate.x+10,Icon.coordinate.y+9},{5,8},2,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Signal_Icon(Icon_Data_t Icon,SIGNAL_STATUS_t state,Color_t color_off)
{
  Color_t color_one,color_two,color_three,color_four,color_five;

  if (state == Signal_Status_No_Signal)
  {
      color_one = color_off;
     color_two = color_off;
     color_three = color_off;
     color_four = color_off;
     color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_1)
  {
     color_one = Icon.color;
     color_two = color_off;
     color_three = color_off;
     color_four = color_off;
     color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_2)
  {
    color_one = Icon.color;
    color_two = Icon.color;
    color_three = color_off;
    color_four = color_off;
    color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_3)
  {
    color_one = Icon.color;
    color_two = Icon.color;
    color_three = Icon.color;
    color_four = color_off;
    color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_4)
  {
    color_one = Icon.color;
    color_two = Icon.color;
    color_three = Icon.color;
    color_four = Icon.color;
    color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_5_full)
  {
    color_one = Icon.color;
    color_two = Icon.color;
    color_three = Icon.color;
    color_four = Icon.color;
    color_five = Icon.color;
  }
  else return ;

  Rectangle({{Icon.coordinate.x,Icon.coordinate.y+20},{5,5},0,Shape_Fill,color_one});
  Rectangle({{Icon.coordinate.x+10,Icon.coordinate.y+15},{5,10},0,Shape_Fill,color_two});
  Rectangle({{Icon.coordinate.x+20,Icon.coordinate.y+10},{5,15},0,Shape_Fill,color_three});
  Rectangle({{Icon.coordinate.x+30,Icon.coordinate.y+5},{5,20},0,Shape_Fill,color_four});
  Rectangle({{Icon.coordinate.x+40,Icon.coordinate.y},{5,25},0,Shape_Fill,color_five});
}
void SEDHOM_Icons::Bell_Icon(Icon_Data_t Icon,bool mute_or_not,bool filled_or_not)
{
   Rectangle({{Icon.coordinate.x-3,Icon.coordinate.y+20},{30-4,5},4,Shape_Fill,Icon.color});
   Rectangle({{Icon.coordinate.x-5,Icon.coordinate.y+23},{30,5},4,Shape_Fill,Icon.color});
   Rectangle({{Icon.coordinate.x-7,Icon.coordinate.y+26},{30+4,5},4,Shape_Fill,Icon.color});
   Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{20,30},10,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x+10,Icon.coordinate.y+32},5,Shape_Fill,Icon.color});
   if(!filled_or_not)
   {
      Rectangle({{Icon.coordinate.x-3+2,Icon.coordinate.y+20+2},{30-4-4,5-1},4,Shape_Fill,Icon.Background});
      Rectangle({{Icon.coordinate.x-5+2,Icon.coordinate.y+23+2},{30-4,5-1},4,Shape_Fill,Icon.Background});
      Rectangle({{Icon.coordinate.x-7+2,Icon.coordinate.y+26+2},{30+4-4,5-4},4,Shape_Fill,Icon.Background});
      Rectangle({{Icon.coordinate.x+2,Icon.coordinate.y+2},{20-4,30-4},10,Shape_Fill,Icon.Background});
   }
   if(mute_or_not)
   {
     Line({{Icon.coordinate.x-10,Icon.coordinate.y+3},{Icon.coordinate.x+35,Icon.coordinate.y+28},Icon.Background});
     Line({{Icon.coordinate.x-10,Icon.coordinate.y+4},{Icon.coordinate.x+35,Icon.coordinate.y+29},Icon.Background});
     Line({{Icon.coordinate.x-10,Icon.coordinate.y+5},{Icon.coordinate.x+35,Icon.coordinate.y+30},Icon.color});
     Line({{Icon.coordinate.x-10,Icon.coordinate.y+6},{Icon.coordinate.x+35,Icon.coordinate.y+31},Icon.color});
     Line({{Icon.coordinate.x-10,Icon.coordinate.y+7},{Icon.coordinate.x+35,Icon.coordinate.y+32},Icon.Background});
     Line({{Icon.coordinate.x-10,Icon.coordinate.y+8},{Icon.coordinate.x+35,Icon.coordinate.y+33},Icon.Background});
   }
}
void SEDHOM_Icons::Menu_Icon_1(Icon_Data_t Icon) // : : :
{
  for(int j=0;j<3;j++)
  {
    for(int i=0;i<3;i++)
    {
     Circle({{Icon.coordinate.x+(j*10),Icon.coordinate.y+(i*10)},3,Shape_Fill,Icon.color});
    }
  }
}
void SEDHOM_Icons::Menu_Icon_2(Icon_Data_t Icon) // ...
{
 for(int i=0;i<3;i++)
  {
    Circle({{Icon.coordinate.x+(i*10),Icon.coordinate.y},3,Shape_Fill,Icon.color});
  }
}
void SEDHOM_Icons::Menu_Icon_3(Icon_Data_t Icon) // :
{
 for(int i=0;i<3;i++)
  {
    Circle({{Icon.coordinate.x,Icon.coordinate.y+(i*10)},3,Shape_Fill,Icon.color});
  }
}
void SEDHOM_Icons::Menu_Icon_4(Icon_Data_t Icon) // : :
{
  for(int j=0;j<2;j++)
  {
    for(int i=0;i<2;i++)
    {
     Circle({{Icon.coordinate.x+(j*20),Icon.coordinate.y+(i*20)},3,Shape_Fill,Icon.color});
    }
  }
}
void SEDHOM_Icons::Menu_Icon_5(Icon_Data_t Icon) // =
{
  for(int j=0;j<3;j++)
  {
    Rectangle({{Icon.coordinate.x,Icon.coordinate.y+(j*10)},{30,5},5,Shape_Fill,Icon.color});
  }
}
void SEDHOM_Icons::Moon_Icon(Icon_Data_t Icon)
{
   Circle({{Icon.coordinate.x, Icon.coordinate.y},20,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x+10,Icon.coordinate.y-10},20,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Sun_Icon(Icon_Data_t Icon)
{
  // master circle
   Circle({{Icon.coordinate.x, Icon.coordinate.y},15,Shape_Fill,Icon.color});
   // small circles
   Circle({{Icon.coordinate.x-25,Icon.coordinate.y},3,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x+25,Icon.coordinate.y},3,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x,Icon.coordinate.y-25},3,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x,Icon.coordinate.y+25},3,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x+20,Icon.coordinate.y+20},3,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x-20,Icon.coordinate.y-20},3,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x+20,Icon.coordinate.y-20},3,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x-20,Icon.coordinate.y+20},3,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Check_Box_Icon(Icon_Data_t Icon,bool status,Color_t check_color,Color_t checked_fill_color)
{
  Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{40,40},5,Shape_Fill,Icon.color});
  Rectangle({{Icon.coordinate.x+3,Icon.coordinate.y+3},{40-6,40-6},5,Shape_Fill,status ? checked_fill_color : Icon.Background});
  if(status)
  {
      for(int i=-1; i<=3; i++) 
      {
          Line({{Icon.coordinate.x+7, Icon.coordinate.y+25+i}, {Icon.coordinate.x+15, Icon.coordinate.y+30+i}, (i<=2 && i>=-1) ? check_color : Icon.Background});
      }
      for(int i=-3; i<=3; i++) 
      {
          Line({{Icon.coordinate.x+15, Icon.coordinate.y+30+i},{ Icon.coordinate.x+30, Icon.coordinate.y+10+i}, (i<=2 && i>=-2) ? check_color : Icon.Background});
      }
  }

}
void SEDHOM_Icons::Radio_Button_Icon(Icon_Data_t Icon,bool status,Color_t check_color)
{
  // border
   Circle({{Icon.coordinate.x,Icon.coordinate.y},15,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x,Icon.coordinate.y},12,Shape_Fill,Icon.Background});
   // status
  if(status) Circle({{Icon.coordinate.x,Icon.coordinate.y},5,Shape_Fill,check_color});
}
void SEDHOM_Icons::Text_Feild_Icon( Icon_Data_t Icon,Text_Data_t Txt ,int length,int max_char)
{
   Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{length,40},20,Shape_Fill,Icon.color});
   Rectangle({{Icon.coordinate.x+3,Icon.coordinate.y+3},{length-6,40-6},20,Shape_Fill,Icon.Background});
   if( Txt.txt.length() > max_char)
   {
      String word = "...";
      String part = Txt.txt.substring(0, max_char-3);
      String all = part + word ;
      Text({Icon.coordinate.x+10,Icon.coordinate.y+25},Txt.txt_font,Txt.txt_color,all);
   }
   else
   {
    Text({Icon.coordinate.x+10,Icon.coordinate.y+25},Txt.txt_font,Txt.txt_color,Txt.txt);
   }
}
void SEDHOM_Icons::Warning_Icon( Icon_Data_t Icon,Color_t txt_color,Shape_filled_t filled )
{
  Equilateral_Triangle({{Icon.coordinate.x,Icon.coordinate.y},40,filled,Direction_Up,Icon.color});
  Text_C({Icon.coordinate.x-6,Icon.coordinate.y+5},FONT_BIG,txt_color,"!");
}
void SEDHOM_Icons::Chandelier_Icon(Icon_Data_t Icon)
{
   Circle({{Icon.coordinate.x,Icon.coordinate.y},20,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x,Icon.coordinate.y},20-3,Shape_Fill,Icon.Background});
   Rectangle({{Icon.coordinate.x-23,Icon.coordinate.y},{46,25},0,Shape_Fill,Icon.Background});
   Circle({{Icon.coordinate.x,Icon.coordinate.y+2},8,Shape_Fill,Icon.color});
   Circle({{Icon.coordinate.x,Icon.coordinate.y+2},5,Shape_Fill,Icon.Background});
   Rectangle({{Icon.coordinate.x-10,Icon.coordinate.y-10},{20,10},0,Shape_Fill,Icon.Background});
   Rectangle({{Icon.coordinate.x-21,Icon.coordinate.y},{43,3},0,Shape_Fill,Icon.color});
   Rectangle({{Icon.coordinate.x-1,Icon.coordinate.y-33},{3,15},2,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Smart_TV_Icon(Icon_Data_t Icon,Color_t WIFI_icon)
{
  // Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{60,50},7,Shape_Fill,Icon.color});
  // Rectangle({{Icon.coordinate.x+3,Icon.coordinate.y+3},{60-6,50-6},7,Shape_Fill,Icon.Background});
  Border_Rectangle({Icon.coordinate.x,Icon.coordinate.y,Icon.color,Icon.Background},{60,50},7,3);
  WIFI_Icon({Icon.coordinate.x+30,Icon.coordinate.y+33,WIFI_icon,Icon.Background},WIFI_icon,WIFI_Status_connected_level_4_full);
  Rectangle({{Icon.coordinate.x+8,Icon.coordinate.y+50-3},{50-6,3},5,Shape_Fill,Icon.color});
  Rectangle({{Icon.coordinate.x+22,Icon.coordinate.y+50-3},{15,10},0,Shape_Fill,Icon.color});
  Rectangle({{Icon.coordinate.x+10,Icon.coordinate.y+50-3+10},{40,5},5,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Air_Conditioner_Icon(Icon_Data_t Icon)
{
  Border_Rectangle(Icon,{80,40},10,3);
  Rectangle({{Icon.coordinate.x+50,Icon.coordinate.y+8},{20,5},5,Shape_Fill,Icon.color});
  Border_Rectangle({Icon.coordinate.x +15 , Icon.coordinate.y +25 ,Icon.color , Icon.Background},{50,20},10,3);
  Rectangle({{Icon.coordinate.x+12,Icon.coordinate.y+37},{53,3},5,Shape_Fill,Icon.color});
  Rectangle({{Icon.coordinate.x+12,Icon.coordinate.y+40},{55,8},5,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Close_Icon(Icon_Data_t Icon)
{
  Border_Rectangle(Icon,{40,40},20,3);
  Text_C({Icon.coordinate.x+13,Icon.coordinate.y+28},FONT_BIG,Icon.color,"X");
}
void SEDHOM_Icons::Star_Icon(Icon_Data_t Icon)
{
  Equilateral_Triangle({{Icon.coordinate},30,Shape_Fill,Direction_Up,Icon.color});
  Equilateral_Triangle({{Icon.coordinate.x+10,Icon.coordinate.y},30,Shape_Fill,Direction_Down,Icon.color});
}







//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/////////////////////////////////////////////////////////////////////////////
#endif // !SEDHOM_OS_ICONS_H_