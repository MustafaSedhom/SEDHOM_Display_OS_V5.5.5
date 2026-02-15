#ifndef SEDHOM_OS_ICONS_H_
#define SEDHOM_OS_ICONS_H_
//////////////////////////////////////////////////////////////////////////////////////////
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Display_QRCodes.h"

#include "SEDHOM_Basic_Shapes.h"
#include "SEDHOM_Text.h"
#include "SEDHOM_Effects.h"
///////////////////////////////////////////////////////////////////////////
init_Display_variable();
///////////////////////////////////////////////////////////////////////////
// Icons class
class SEDHOM_Icons : public SEDHOM_Basic_Shapes , public SEDHOM_Text ,public SEDHOM_Effects , public SEDHOM_Colors
{
  private:
        uint16_t mode;
  public:
        // to set and handling mode
        uint16_t Not_Mode();
        uint16_t Mode();
        void Set_Mode(Color_t Mode);
        // Draw SEDHOM Icons
        void WIFI_Icon(Icon_t Icon ,Color_t color_off,WIFI_STATUS_t state);
        void Battary_Icon(Icon_t Icon  ,int range,Color_t txt_color,bool low_charge_red_color = true);
        void Home_Icon(Icon_t Icon = {});
        void Setting_Icon(Icon_t Icon = {});
        void Add_Icon(Icon_t Icon = {});
        void SD_Card_Icon(Icon_t Icon = {});
        void Control_Icon(Icon_t Icon = {});
        void Sensor_Icon(Icon_t Icon = {});
        void Power_off_Icon(Icon_t Icon = {});
        void Bluetooth_Icon(Icon_t Icon ,BLUETOOTH_STATUS_t connect_status);
        void Button_Icon(Icon_t Icon = {},bool print_on_and_off = 0);
        void Display_Time_Icon(Icon_t Icon , Time_t time);
        void Terminal_Icon(Icon_t Icon = {});
        void About_Icon(Icon_t Icon = {});
        void Display_Date_Icon(Icon_t Icon,Date_t Date,Color_t text_color);
        void UP_Arrow_Icon(Icon_t Icon = {},Color_t border_color = -1);
        void DOWN_Arrow_Icon(Icon_t Icon = {},Color_t border_color = -1);
        void LEFT_Arrow_Icon(Icon_t Icon = {},Color_t border_color = -1);
        void RIGHT_Aroow_Icon(Icon_t Icon = {},Color_t border_color = -1);
        void Back_Arrow_Icon(Icon_t Icon = {},Color_t border_color = -1);
        void After_Arrow_Icon(Icon_t Icon = {},Color_t border_color = -1);
        void Color_Icon(Icon_t Icon = {});
        void Time_Icon(Icon_t Icon = {});
        void Date_Icon(Icon_t Icon = {});
        void Switch_Icon(Icon_t Icon,Color_t color_off,Color_t thumb_color,Color_t txt_color,SWITCH_STATUS_t state);
        void label_Icon(Icon_t Icon ,Area_t area,int Border,Color_t color_str_in_label,String string_in_label);
        void slider_Icon(Icon_t Icon ,int h,byte_t range ,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color);
        void file_Icon(Icon_t Icon,Color_t Border_color,Color_t file_extend_color,String file_extend);
        void folder_Icon(Icon_t Icon = {});
        void Divider_vertical(Icon_t Icon ,int length , int thikness);
        void Divider_Horezontal(Icon_t Icon ,int length , int thikness);
        void ID_Card_Icon(Icon_t Icon, User_ID_Data_t User ,Color_t main_font_color,Color_t font_color);
        void Joy_Stick_Icon(Icon_t Icon ,Coordenate_t thumb ,int thumb_size,Color_t Border_color,Color_t thumb_color,Color_t Color_insde_arrow);
        void Temperature_Meter_Icon(Icon_t Icon,Color_t Border,int value,bool show_val_dashes = true);
        void Tone_Icon(Icon_t Icon,bool is_muted_or_not = false);
        void Sound_value_Icon(Icon_t Icon,int value,Color_t thikness_color = GREEN,bool thikness_or_not = false);
        void Video_Icon(Icon_t Icon = {});
        void Block_Icon(Icon_t Icon,bool open_or_closed = false);
        void Signal_Icon(Icon_t Icon,SIGNAL_STATUS_t state,Color_t color_off);
        void Bell_Icon(Icon_t Icon,bool mute_or_not = false,bool filled_or_not = true);
        void Menu_Icon_1(Icon_t Icon = {}); // : : :
        void Menu_Icon_2(Icon_t Icon = {}); // ...
        void Menu_Icon_3(Icon_t Icon = {}); // :
        void Menu_Icon_4(Icon_t Icon = {}); // : :
        void Menu_Icon_5(Icon_t Icon = {}); // = 
        void Moon_Icon(Icon_t Icon = {});
        void Sun_Icon(Icon_t Icon = {});
        void Check_Box_Icon(Icon_t Icon,bool status,Color_t check_color,Color_t checked_fill_color);
        void Radio_Button_Icon(Icon_t Icon,bool status,Color_t check_color);
        void Text_Feild_Icon(  Icon_t Icon = {},Text_t text = {} ,int lenght = 200,int max_char = 10);
        void Warning_Icon( Icon_t Icon,Color_t txt_color,Shape_filled_t filled = Shape_Draw );
        void Chandelier_Icon(Icon_t Icon);
        void Smart_TV_Icon(Icon_t icon,Color_t WIFI_icon = White);
        void Air_Conditioner_Icon(Icon_t Icon);
};
// define all functions and Draw all Widgets and icons
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// mode functions
uint16_t SEDHOM_Icons::Not_Mode()
{
   if(mode == BLACK) return WHITE;
   else return BLACK;
}
uint16_t SEDHOM_Icons::Mode()
{
   return mode;
}
void SEDHOM_Icons::Set_Mode(Color_t Mode)
{
    mode = Mode;
    FillScreen(mode); 
}
// SEDHOM Icons
void SEDHOM_Icons::WIFI_Icon(Icon_t Icon,Color_t color_off,WIFI_STATUS_t state)
{
    if(state != WIFI_Status_not_connected)
    {
        uint16_t one=RED,two=RED,three=RED,four=RED;
        if(state==WIFI_Status_no_internet){one=color_off;two=color_off;three=color_off;four=color_off;}
        else if(state==WIFI_Status_conected_level_1){one=color_off;two=color_off;three=color_off;four=Icon.color;}
        else if(state==WIFI_Status_conected_level_2_half){one=color_off;two=color_off;three=Icon.color;four=Icon.color;}
        else if(state==WIFI_Status_conected_level_3){one=color_off;two=Icon.color;three=Icon.color;four=Icon.color;}
        else if(state==WIFI_Status_conected_level_4_full){one=Icon.color;two=Icon.color;three=Icon.color;four=Icon.color;}
        Circle({{Icon.x,Icon.y},20,Shape_Fill,one});
        Circle({{Icon.x,Icon.y},20-3,Shape_Fill,Icon.Background});
        Circle({{Icon.x,Icon.y},20-6,Shape_Fill,two});
        Circle({{Icon.x,Icon.y},20-9,Shape_Fill,Icon.Background});
        Circle({{Icon.x,Icon.y},20-12,Shape_Fill,three});
        Circle({{Icon.x,Icon.y},20-15,Shape_Fill,Icon.Background});
        Rectangle({{Icon.x-21,Icon.y},{42,20},5,Shape_Fill,Icon.Background});
        Triangle({{Icon.x-3,Icon.y+5},{Icon.x+24,Icon.y+5},{Icon.x+21,Icon.y-20},Shape_Fill,Icon.Background});
        Triangle({{Icon.x+3,Icon.y+5},{Icon.x-24,Icon.y+5},{Icon.x-21,Icon.y-20},Shape_Fill,Icon.Background});
        Circle({{Icon.x,Icon.y},20-18,Shape_Fill,four});
        if(state==WIFI_Status_no_internet)
        {
        TEXT(Icon.x+8,Icon.y,BigFont,color_off,"!");
        }
    }
    else if(state==WIFI_Status_not_connected)
    {
      Rectangle({{Icon.x-15,Icon.y-27},{37,38},5,Shape_Fill,Icon.Background});
    }
    Rectangle({{Icon.x-10,Icon.y+13},{20,10},0,Shape_Fill,Icon.Background});
} 
void SEDHOM_Icons::Battary_Icon(Icon_t Icon ,int range,Color_t txt_color,bool low_charge_red_color)
{
    int txt_x=0;
    int txt_y_index = Icon.y+22;
    uint16_t color_Battary;
    if(low_charge_red_color==1)
    {
        if(range<20){color_Battary=RED; txt_x=(range>=10)?Icon.x-60:Icon.x-45;txt_color=Not_Mode();}
        else if(range>=20){color_Battary=Icon.color;txt_x=(range==100)?Icon.x-65:Icon.x-58;}
    }
    else if(low_charge_red_color==0)
    {
        if(range<20){color_Battary=GREEN; txt_x=(range>=10)?Icon.x-53:Icon.x-45;}
        else if(range>=20){color_Battary=GREEN;txt_x=(range==100)?Icon.x-65:Icon.x-58;}
    }
    int rangeB=map(range,0,100,5,45);
    Rectangle({{Icon.x, Icon.y}, {50,30}, 5,Shape_Fill, color_Battary});
    Rectangle({{Icon.x+3, Icon.y+3}, {50-6,30-6}, 5,Shape_Fill, Icon.Background});
    Rectangle({{Icon.x+50-1,Icon.y+10},{10,10},0,Shape_Fill,color_Battary});
    Rectangle({{Icon.x+2,Icon.y+3},{rangeB,30-6},5,Shape_Fill,color_Battary});
    Text_cpp(txt_x+60,txt_y_index,BigFont,txt_color,String(range) + "%");
}
void SEDHOM_Icons::Home_Icon(Icon_t Icon)
{
    
    Triangle({{Icon.x+30,Icon.y},{(Icon.x+30)+25,Icon.y+15},{(Icon.x+30)-25,Icon.y+15},Shape_Fill,Icon.color});
    Rectangle({{Icon.x+10, Icon.y+12},{40,25},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.x+23, Icon.y+20},{15,20},5,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Setting_Icon(Icon_t Icon)
{
    Circle({{Icon.x-10, Icon.y},10,Shape_Fill, Icon.color});
    Circle({{Icon.x-10, Icon.y-10}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.x-10, Icon.y+10}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.x, Icon.y-5}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.x, Icon.y+5}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.x-20, Icon.y-5}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.x-20, Icon.y+5}, 3,Shape_Fill, Icon.color});
    Circle({{Icon.x-10, Icon.y}, 5,Shape_Fill, Icon.Background});
}
void SEDHOM_Icons::Add_Icon(Icon_t Icon)
{
    Rectangle({{Icon.x+15,Icon.y-2+15},{30,5},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.x+13+15,Icon.y-14+15},{5,30},5,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::SD_Card_Icon(Icon_t Icon)
{
    Rectangle({{Icon.x-5, Icon.y-5},{40,45},5,Shape_Fill,WHITE});
    Rectangle({{Icon.x, Icon.y},{30,35},5,Shape_Fill,BLACK});
    Rectangle({{Icon.x+15,Icon.y},{17,8},5,Shape_Fill,WHITE});
    Triangle({{Icon.x+30,Icon.y+8},{Icon.x+17,Icon.y+8},{Icon.x+17,Icon.y},Shape_Fill,BLACK});
    Rectangle({{Icon.x+4,Icon.y+20},{2,10},5,Shape_Fill,YELLOW});
    Rectangle({{Icon.x+11,Icon.y+20},{2,10},5,Shape_Fill,YELLOW});
    Rectangle({{Icon.x+18,Icon.y+20},{2,10},5,Shape_Fill,YELLOW});
    Rectangle({{Icon.x+25,Icon.y+20},{2,10},5,Shape_Fill,YELLOW});
    Rectangle({{Icon.x+12,Icon.y+1},{5,8},0,Shape_Fill,BLACK});
}
void SEDHOM_Icons::Control_Icon(Icon_t Icon)
{
    Rectangle({{Icon.x, Icon.y},{40,3},5,Shape_Fill, Icon.color});
    Rectangle({{Icon.x,Icon.y+15},{40,3},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.x,Icon.y+30},{40,3},5,Shape_Fill,Icon.color});
    Circle({{Icon.x+28,Icon.y+1},6,Shape_Fill,Icon.color});
    Circle({{Icon.x+12,Icon.y+16},6,Shape_Fill,Icon.color});
    Circle({{Icon.x+31-2,Icon.y+30+1},6,Shape_Fill,Icon.color});
    Circle({{Icon.x+28,Icon.y+1},3,Shape_Fill,Icon.Background});
    Circle({{Icon.x+12,Icon.y+16},3,Shape_Fill,Icon.Background});
    Circle({{Icon.x+29,Icon.y+31},3,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Sensor_Icon(Icon_t Icon)
{
    Rectangle({{Icon.x+3,Icon.y},{30,10},5,Shape_Fill,Icon.color});
    Circle({{Icon.x+18, Icon.y+10},5,Shape_Fill,Icon.color});
    Line({{Icon.x+12,Icon.y+17},{Icon.x+6,Icon.y+25},Icon.color});
    Line({{Icon.x+23,Icon.y+17},{Icon.x+30,Icon.y+25},Icon.color});
    Line({{Icon.x+18,Icon.y+17},{Icon.x+18,Icon.y+25},Icon.color});
}
void SEDHOM_Icons::Power_off_Icon(Icon_t Icon)
{
    Circle({{Icon.x,Icon.y},20,Shape_Fill,Icon.color});
    Circle({{Icon.x,Icon.y},17,Shape_Fill,Icon.Background});
    Rectangle({{Icon.x-8, Icon.y-20},{16,20}, 0,Shape_Fill,Icon.Background});
    Rectangle({{Icon.x-1, Icon.y-23},{2,23},0,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Bluetooth_Icon(Icon_t Icon,BLUETOOTH_STATUS_t connect_status)
{
 if(connect_status == BLuetooth_Status_open_and_not_connected || connect_status == BLuetooth_Status_open_and_connected )
 {
    Triangle({{(Icon.x) , (Icon.y)} , {(Icon.x+15) , (Icon.y+10)} , {(Icon.x) , (Icon.y+20)},Shape_Fill , Icon.color});
    Triangle({{(Icon.x) , (Icon.y)+15} , {(Icon.x+15) , (Icon.y+10)+15} , {(Icon.x) , (Icon.y+20)+15},Shape_Fill , Icon.color});
    Triangle({{(Icon.x-15) , (Icon.y+5) },{ (Icon.x) , (Icon.y+16)} , {(Icon.x-15) , (Icon.y+30)},Shape_Fill , Icon.color});
    Triangle({{(Icon.x-15)+2 , (Icon.y+5)+3 }, {(Icon.x)-2 , (Icon.y+16)} , {(Icon.x-15)+2 , (Icon.y+30)-3},Shape_Fill , Icon.Background});
    Triangle({{(Icon.x)+2 , (Icon.y)+3 },{ (Icon.x+15)-2 , (Icon.y+10) }, {(Icon.x)+2 , (Icon.y+20)-4},Shape_Fill , Icon.Background});
    Triangle({{((Icon.x))+2 , ((Icon.y)+15)+3} , {((Icon.x+15))-2 , ((Icon.y)+15)+10 }, {((Icon.x))+2 , ((Icon.y+20)+15)-3},Shape_Fill , Icon.Background});
    Rectangle({{Icon.x-18, Icon.y+2},{6,30},0,Shape_Fill, Icon.Background});
    if(connect_status == BLuetooth_Status_open_and_connected)
    {
        Circle({{Icon.x-10, Icon.y+17}, 1,Shape_Fill, Icon.color});
        Circle({{Icon.x+13, Icon.y+18}, 1,Shape_Fill, Icon.color});
    }
 }
 else
 {
    Rectangle({{Icon.x-20, Icon.y-10},{42,50},0,Shape_Fill, Icon.Background});
 }
}
void SEDHOM_Icons::Button_Icon(Icon_t Icon,bool print_on_and_off)
{
    Rectangle({{Icon.x,Icon.y},{50,20} ,30,Shape_Fill,GREEN});
    Circle({{Icon.x+39,Icon.y+10},7,Shape_Fill,WHITE});
    Rectangle({{Icon.x,Icon.y+25},{50,20},30,Shape_Fill,RED});
    Circle({{Icon.x+10,Icon.y+35},7,Shape_Fill,WHITE});

    if(print_on_and_off)
    {
        TEXT(Icon.x+8, Icon.y+16,SmallFont,WHITE,"ON");
        TEXT(Icon.x+23, Icon.y+41,SmallFont,WHITE,"OFF");
    }
}
void SEDHOM_Icons::Display_Time_Icon(Icon_t Icon,Time_t time)
{
    //hour
    Text_cpp(Icon.x,Icon.y+35,FONT_SEVENSEGMENT,Icon.color,(time.hour < 10) ? ("0" + String(time.hour)) : String(time.hour));
    // minutes
    Text_cpp(Icon.x+83,Icon.y+35,FONT_SEVENSEGMENT,Icon.color,(time.minut < 10) ? ("0" + String(time.minut)) : String(time.minut));
    // seprator
    Circle({{Icon.x+73,Icon.y},5,Shape_Fill,Icon.color});
    Circle({{Icon.x+73,Icon.y+20},5,Shape_Fill,Icon.color});
    //sec
    Text_cpp(Icon.x+146,Icon.y,BigFont,Icon.color,String(time.sec));
    // time name
    Text_cpp(Icon.x+146,Icon.y+38,BigFont,Icon.color,String(time.time_name));
}
void SEDHOM_Icons::Terminal_Icon(Icon_t Icon)
{
    Rectangle({{Icon.x,Icon.y},{50,50},5,Shape_Fill,WHITE});
    Rectangle({{Icon.x+3,Icon.y+3},{44,44},5,Shape_Fill,BLACK});
    TEXT(Icon.x+10,Icon.y+30,BigFont,GREEN,">_");
}
void SEDHOM_Icons::About_Icon(Icon_t Icon)
{
    Circle({{Icon.x,Icon.y},20,Shape_Fill,Icon.color});
    Circle({{Icon.x,Icon.y},17,Shape_Fill,Icon.Background});
    TEXT(Icon.x-6,Icon.y+8,BigFont,Icon.color,"!");
}
void SEDHOM_Icons::Display_Date_Icon(Icon_t Icon,Date_t Date,Color_t text_color)
{
    Rectangle({{Icon.x,Icon.y},{130,130},15,Shape_Fill,Icon.color});
    Text_cpp(Icon.x+42,Icon.y+40,BigFont,text_color,String(Date.week_day_name));
    Text_cpp(Icon.x+47,Icon.y+65,BigFont,text_color,String(Date.Day));
    Text_cpp(Icon.x+42,Icon.y+90,BigFont,text_color,String(Date.month_name));
    Text_cpp(Icon.x+35,Icon.y+115,BigFont,text_color,String(Date.year));

    int x_start = Icon.x + 15;
    int y_start = Icon.y;
    int x_end_start = Icon.x + 10;
    int y_end_start = Icon.y + 8;

    for (int offset_block = 0; offset_block <= 100; offset_block += 20) // 0, 20, 40, 60, 80, 100
    {
        for (int i = 0; i <= 4; i++) // 0,1,2,3,4
        {
          Line({{(x_start + i + offset_block),y_start},{(x_end_start + i + offset_block),y_end_start},Icon.Background});
        }
    }


    Circle({{Icon.x+114-100,Icon.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.x+114-80,Icon.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.x+114-60,Icon.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.x+114-40,Icon.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.x+114-20,Icon.y+8},4,Shape_Fill,Icon.Background});
    Circle({{Icon.x+114,Icon.y+8},4,Shape_Fill,Icon.Background});

}
void SEDHOM_Icons::UP_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Triangle({{Icon.x-20-6,Icon.y+25+3},{Icon.x,Icon.y-6},{Icon.x+20+6,Icon.y+25+3},Shape_Fill,border_color});
  Triangle({{Icon.x-20,Icon.y+25},{Icon.x,Icon.y},{Icon.x+20,Icon.y+25},Shape_Fill,Icon.color});
  fill_rectangle_with_end(Icon.x-10,Icon.y+25,20,20,3,Icon.color,border_color);
  Rectangle({{Icon.x-10+3,Icon.y+25},{20-6,20-3},0,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::DOWN_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Triangle({{Icon.x-20-6,Icon.y+25-3},{Icon.x,Icon.y-6+60},{Icon.x+20+6,Icon.y+25-3},Shape_Fill,border_color});
  Triangle({{Icon.x-20,Icon.y+25},{Icon.x,Icon.y+50},{Icon.x+20,Icon.y+25},Shape_Fill,Icon.color});
  fill_rectangle_with_end(Icon.x-10,Icon.y+5,20,20,3,Icon.color,border_color);
  Rectangle({{Icon.x-10+3,Icon.y+8},{20-6,20-3},0,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::LEFT_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Triangle({{Icon.x-6,Icon.y},{Icon.x+25+3,Icon.y-25-6},{Icon.x+25+3,Icon.y+25+6},Shape_Fill,border_color});
  Triangle({{Icon.x,Icon.y},{Icon.x+25,Icon.y-25},{Icon.x+25,Icon.y+25},Shape_Fill,Icon.color});
  fill_rectangle_with_end(Icon.x+25,Icon.y-8-1,20,20,3,Icon.color,border_color);
  Rectangle({{Icon.x+25,Icon.y-8+3-1},{20-3,20-6},0,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::RIGHT_Aroow_Icon(Icon_t Icon,Color_t border_color)
{
  Triangle({{Icon.x+6+50,Icon.y},{Icon.x+25-3,Icon.y-25-6},{Icon.x+25-3,Icon.y+25+6},Shape_Fill,border_color});
  Triangle({{Icon.x+50,Icon.y},{Icon.x+25,Icon.y-25},{Icon.x+25,Icon.y+25},Shape_Fill,Icon.color});
  fill_rectangle_with_end(Icon.x+5,Icon.y-8-1,20,20,3,Icon.color,border_color);
  Rectangle({{Icon.x+8,Icon.y-8+3-1},{20-3,20-6},0,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Back_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Triangle({{Icon.x-6,Icon.y},{Icon.x+25+3,Icon.y-15-6},{Icon.x+25+3,Icon.y+15+6},Shape_Fill,border_color});
  Triangle({{Icon.x,Icon.y},{Icon.x+25,Icon.y-15},{Icon.x+25,Icon.y+15},Shape_Fill,Icon.color});
  fill_rectangle_with_end(Icon.x+25,Icon.y-8-1,18,25,3,Icon.color,border_color);
  Rectangle({{Icon.x+22,Icon.y-8+3-1},{12,12},5,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::After_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Triangle({{Icon.x+6+50,Icon.y},{Icon.x+25-3,Icon.y-15-6},{Icon.x+25-3,Icon.y+15+6},Shape_Fill,border_color});
  Triangle({{Icon.x+50,Icon.y},{Icon.x+25,Icon.y-15},{Icon.x+25,Icon.y+15},Shape_Fill,Icon.color});
  fill_rectangle_with_end(Icon.x,Icon.y-8-1,18,25,3,Icon.color,border_color);
  Rectangle({{Icon.x+15,Icon.y-8+3-1},{12,13},5,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Color_Icon(Icon_t Icon)
{
    Rectangle({{Icon.x,Icon.y},{30,30},5,Shape_Fill,MAGENTA});
    Rectangle({{Icon.x+5,Icon.y+5},{30,30},5,Shape_Fill,RED});
    Rectangle({{Icon.x+10,Icon.y+10},{30,30},5,Shape_Fill,BLUE});
    Rectangle({{Icon.x+15,Icon.y+15},{30,30},5,Shape_Fill,GREEN});
}
void SEDHOM_Icons::Time_Icon(Icon_t Icon)
{
    Circle({{Icon.x,Icon.y},20,Shape_Fill,Icon.color});
    Circle({{Icon.x,Icon.y},17,Shape_Fill,Icon.Background});
    Rectangle({{Icon.x-2,Icon.y-14},{3,12},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.x,Icon.y-1},{10,3},5,Shape_Fill,Icon.color});
    Circle({{Icon.x,Icon.y},4,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Date_Icon(Icon_t Icon)
{
    Rectangle({{Icon.x,Icon.y},{45,48},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.x+2,Icon.y+10},{41,36},5,Shape_Fill,Icon.Background});
    Circle({{Icon.x+5,Icon.y+5},3,Shape_Fill,Icon.Background});
    Circle({{Icon.x+23,Icon.y+5},3,Shape_Fill,Icon.Background});
    Circle({{Icon.x+40,Icon.y+5},3,Shape_Fill,Icon.Background});
    TEXT(Icon.x+20,Icon.y+24,SmallFont,Icon.color,"6");
    TEXT(Icon.x+12,Icon.y+33,SmallFont,Icon.color,"Jun");
    TEXT(Icon.x+9,Icon.y+46,SmallFont,Icon.color,"2025");
}
void SEDHOM_Icons::Switch_Icon(Icon_t Icon,Color_t color_off,Color_t thumb_color,Color_t txt_color,SWITCH_STATUS_t state)
{
    Color_t State_color = color_off;
    int index = Icon.x+57;
    int index_str = Icon.x-13;
    String state_str = "OFF";
    State_color = (state == SWITCH_State_ON) ? Icon.color : color_off ;
    index = (state == SWITCH_State_ON) ? (Icon.x+20) : (Icon.x+80) ;
    index_str = (state == SWITCH_State_ON) ? (Icon.x+50) : (Icon.x+10) ;
    state_str = (state == SWITCH_State_ON) ? "ON" : "OFF" ;
    Rectangle({{Icon.x,Icon.y},{100,40},50,Shape_Fill,State_color});
    Circle({{index,Icon.y+20},15,Shape_Fill,thumb_color});
    Text_cpp((index_str),Icon.y+28,BigFont,txt_color,state_str);
}
void SEDHOM_Icons::label_Icon(Icon_t Icon ,Area_t area,int Border,Color_t color_str_in_label,String string_in_label)
{
    Color_t label_color_in_func = Icon.color;
    float num = 1;

    if(string_in_label == "OFF" || string_in_label == "off" || num == 0){label_color_in_func = RED;}
    else if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = Icon.color;}
    if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = Icon.color;}

    Border_Rectangle({Icon.x,Icon.y,label_color_in_func,Icon.Background},area.w,area.h,5,Border);
    Text_cpp(Icon.x+10,Icon.y+(0.6*area.w),SmallFont,color_str_in_label,string_in_label);
}
void SEDHOM_Icons::slider_Icon(Icon_t Icon ,int h,byte_t range ,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color)
{
    long index = map(range,0,100,0,h);
    Rectangle({{Icon.x,Icon.y},{h,10},5,Shape_Fill,color_not_active});
    Rectangle({{Icon.x,Icon.y},{index,10},5,Shape_Fill,Icon.color});
    Circle({{Icon.x+index,Icon.y+5},10,Shape_Fill,Not_Mode()});
    fill_rectangle_with_end(Icon.x+h+15,Icon.y-10,30,40,3,Mode(),box_color);
    Text_cpp(Icon.x+h+8+15,Icon.y+19-8,SmallFont,range_in_box_color,String(range));
}
void SEDHOM_Icons::file_Icon(Icon_t Icon,Color_t Border_color,Color_t file_extend_color,String file_extend)
{
    fill_rectangle_with_end(Icon.x,Icon.y,60,50,3,Icon.Background,Border_color);
    fill_rectangle_with_end(Icon.x-10,Icon.y+30,20,30,3,Icon.color,Border_color);
    fill_rectangle_with_end(Icon.x+29,Icon.y-1,21,30,3,Icon.Background,Icon.Background);
    Triangle({{Icon.x+6+43,Icon.y+20},{Icon.x+29,Icon.y},{Icon.x+29,Icon.y+20},Shape_Fill,Border_color});
    Triangle({{Icon.x+43,Icon.y+18},{Icon.x+29+3,Icon.y+6},{Icon.x+29+3,Icon.y+18},Shape_Fill,Icon.color});
    Rectangle({{Icon.x+10,Icon.y+15},{15,2},5,Shape_Fill,Border_color});
    Rectangle({{Icon.x+10,Icon.y+25},{30,2},5,Shape_Fill,Border_color});    
    Rectangle({{Icon.x+25,Icon.y+35},{15,2},5,Shape_Fill,Border_color});
    Rectangle({{Icon.x+25,Icon.y+45},{15,2},5,Shape_Fill,Border_color});
    Text_cpp(Icon.x-5,Icon.y+46,SmallFont,file_extend_color,file_extend);
}
void SEDHOM_Icons::folder_Icon(Icon_t Icon)
{
    Rectangle({{Icon.x,Icon.y},{30,40},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.x+28,Icon.y+5},{40,20},5,Shape_Fill,Icon.color});
    fill_rectangle_with_end(Icon.x+5,Icon.y+10,20,60,1,WHITE,BLACK);
    Rectangle({{Icon.x,Icon.y+20},{68,35},5,Shape_Fill,Icon.color});
    Rectangle({{Icon.x,Icon.y+20},{69,1},0,Shape_Fill,BLACK});
}
void SEDHOM_Icons::Divider_vertical(Icon_t Icon,int length,int thikness)
{
    Rectangle({{Icon.x,Icon.y},{length,thikness},1,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Divider_Horezontal(Icon_t Icon ,int length , int thikness)
{
    Rectangle({{Icon.x,Icon.y},{thikness,length},1,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::ID_Card_Icon(Icon_t Icon, User_ID_Data_t User ,Color_t main_font_color,Color_t font_color)
{
    #define x1   Icon.x
    #define y1   Icon.y

    #define h1    270
    #define w1    200

    Color_t color_id =0;
    if(Icon.color == WHITE) color_id = BLACK;
    else if(Icon.color == BLACK) color_id = WHITE;
    else  color_id = Icon.color;
    Container(x1-3,y1-3,h1+6,w1+6,20,color_id);
    Container(x1,y1,h1,w1,20,Icon.color);
    TEXT(((User.is_professser)?x1+60:x1+80),y1+20,BigFont,main_font_color,((User.is_professser)?"PROFESSER":"STUDENT"));
    Divider_vertical({x1+10,y1+35,main_font_color,Icon.Background},h1-20,3);
    TEXT(x1+30,y1+55,SmallFont,font_color,"IDENTITY CARD");

    TEXT(x1+10,y1+70,SmallFont,main_font_color,((User.is_professser)?"Dr Name":"Nmae"));
    TEXT(x1+10,y1+85,SmallFont,font_color,User.user_name);

    TEXT(x1+10,y1+100,SmallFont,main_font_color,((User.is_professser)?"Unversity":"Stadies at"));
    TEXT(x1+10,y1+115,SmallFont,font_color,User.universty);

    TEXT(x1+10,y1+130,SmallFont,main_font_color,"Department");
    TEXT(x1+10,y1+145,SmallFont,font_color,User.department_1);
    TEXT(x1+10,y1+160,SmallFont,font_color,User.department_2);

    TEXT(x1+10,y1+175,SmallFont,main_font_color,"Born");
    TEXT(x1+10,y1+190,SmallFont,font_color,User.Born);

    Container(x1+160,y1+45,100,110,0,User.image_background);
    
    if(User.default_image)
    {
        Circle({{x1+210,y1+160},40,Shape_Fill,DARKGREY});
        Circle({{x1+210,y1+100},25,Shape_Fill,DARKGREY});
        if(User.eye)
        {
            Circle({{x1+220,y1+97},7,Shape_Fill,BLACK});
            Circle({{x1+220,y1+97},5,Shape_Fill,DARKGREY});
            Circle({{x1+220,y1+97},1,Shape_Fill,BLACK});//eye
            Divider_vertical({x1+205,y1+97,Black,Icon.Background},10,2);
            Circle({{x1+200,y1+97},7,Shape_Fill,BLACK});
            Circle({{x1+200,y1+97},5,Shape_Fill,DARKGREY});
            Circle({{x1+200,y1+97},1,Shape_Fill,BLACK});//eye
            Divider_vertical({x1+225,y1+97,Black,Icon.Background},10,2);
            Divider_vertical({x1+185,y1+97,Black,Icon.Background},10,2);
        }
    }
    Rectangle({{x1+150,y1+155},{120,45},15,Shape_Fill,Icon.color});
    TEXT(x1+157,y1+175,SmallFont,font_color,User.number);
}
void SEDHOM_Icons::Joy_Stick_Icon(Icon_t Icon ,Coordenate_t thumb ,int thumb_size,Color_t Border_color,Color_t thumb_color,Color_t Color_insde_arrow)
{
  Circle({{Icon.x,Icon.y},50,Shape_Fill,Border_color});
  Circle({{Icon.x,Icon.y},50-3,Shape_Fill,Icon.color});
  Equilateral_Triangle({{Icon.x,Icon.y-35},10,Shape_Fill,Direction_Up,Color_insde_arrow});
  Equilateral_Triangle({{Icon.x,Icon.y+35},10,Shape_Fill,Direction_Down,Color_insde_arrow});
  Equilateral_Triangle({{Icon.x+35,Icon.y},10,Shape_Fill,Direction_Right,Color_insde_arrow});
  Equilateral_Triangle({{Icon.x-35,Icon.y},10,Shape_Fill,Direction_Left,Color_insde_arrow});
  int dx = thumb.x - Icon.x;
  int dy = thumb.y - Icon.y;
  if ((dx*dx + dy*dy) <= (50/2)*(50/2))
  {
      Circle({{thumb.x, thumb.y}, thumb_size,Shape_Fill, thumb_color});
  }
}
void SEDHOM_Icons::Temperature_Meter_Icon(Icon_t Icon,Color_t Border,int value,bool show_val_dashes)
{
  Color_t color_dash =RED;
  value = constrain(value, 0, 100);
  Circle({{Icon.x+50/2,Icon.y+150+25},50,Shape_Fill,Border});
  Rectangle({{Icon.x,Icon.y},{50,150},5,Shape_Fill,Border});
  Rectangle({{Icon.x+5,Icon.y+5},{50-10,150},5,Shape_Fill,Icon.Background});
  Circle({{Icon.x+50/2,Icon.y+150+25},50-5,Shape_Fill,Icon.Background});
  Circle({{Icon.x+50/2,Icon.y+150+25},50-13,Shape_Fill,Icon.color});
  int levelHeight = map(value, 0, 100, 0, 140);
  Rectangle({{Icon.x+12,Icon.y + 150 - levelHeight},{50-24,levelHeight},5,Shape_Fill,Icon.color});
  if(show_val_dashes)
  {
   TEXT(Icon.x+55,Icon.y+10,FONT_BIG,red,"-100");
    TEXT(Icon.x+55,Icon.y+135,FONT_BIG,Blue,"-0");
    for (int i=0;i<=10; i++) 
    {
      if(i==3) color_dash = Orange;
      else if(i==8) color_dash = blue;
      TEXT(Icon.x+55,Icon.y+25+i*10,FONT_BIG,color_dash,"-");
    }
  }
}
void SEDHOM_Icons::Tone_Icon(Icon_t Icon,bool is_muted_or_not)
{
   Circle({{Icon.x,Icon.y},5,Shape_Fill,Icon.color});
   Circle({{Icon.x,Icon.y},5-2,Shape_Fill,Icon.Background});
   Circle({{Icon.x+20,Icon.y},5,Shape_Fill,Icon.color});
   Circle({{Icon.x+20,Icon.y},5-2,Shape_Fill,Icon.Background});
   Rectangle({{Icon.x+4,Icon.y-20},{2,20},0,Shape_Fill,Icon.color});
   Rectangle({{Icon.x+4+20,Icon.y-20},{2,20},0,Shape_Fill,Icon.color});
   Rectangle({{Icon.x+4,Icon.y-20},{20,2},0,Shape_Fill,Icon.color});
   if(is_muted_or_not)
   {   
     Line({{Icon.x-5,Icon.y-20},{Icon.x+32,Icon.y-5},Icon.color});    
     Line({{Icon.x-5,Icon.y-20+1},{Icon.x+32,Icon.y-5+1},Icon.color});    
   }
}
void SEDHOM_Icons::Sound_value_Icon(Icon_t Icon,int value,Color_t thikness_color,bool thikness_or_not)
{
  int val = value;
  value = constrain(value,0,100);
  value = map(value,0,100,150,0);
  Rectangle({{Icon.x,Icon.y},{50,150},40,Shape_Fill,thikness_or_not?thikness_color:Icon.color});
  Rectangle({{Icon.x+5,Icon.y+5},{50-10,150-10},40,Shape_Fill,Icon.Background});
  Rectangle({{Icon.x+5,(Icon.y+value+5)},{50-10,((val<15)?(0):(150-value-10))},40,Shape_Fill,Icon.color});
  Tone_Icon({Icon.x+12,Icon.y+130,(val<20)?Icon.color:Icon.Background,(val<20)?Icon.Background:Icon.color},(val==0)?true:false);
}
void SEDHOM_Icons::Video_Icon(Icon_t Icon)
{
   Rectangle({{Icon.x,Icon.y},{50,35},8,Shape_Fill,Icon.color});
   Equilateral_Triangle({{Icon.x+24,Icon.y+17},20,Shape_Fill,Direction_Right,Icon.Background});
}
void SEDHOM_Icons::Block_Icon(Icon_t Icon,bool open_or_closed)
{
  if(!open_or_closed)
  {
     Rectangle({{Icon.x+21,Icon.y-15},{20,30},10,Shape_Fill,Icon.color});
     Rectangle({{Icon.x+21+2,Icon.y-15+2},{20-4,30-4},10,Shape_Fill,Icon.Background});
     Rectangle({{Icon.x+26,Icon.y},{26,20},2,Shape_Fill,Icon.Background});
  }
  else
  {
     Rectangle({{Icon.x+3,Icon.y-15},{20,30},10,Shape_Fill,Icon.color});
     Rectangle({{Icon.x+3+2,Icon.y-15+2},{20-4,30-4},10,Shape_Fill,Icon.Background});
  }
  Rectangle({{Icon.x,Icon.y},{26,20},2,Shape_Fill,Icon.color});
  Circle({{Icon.x+12,Icon.y+6},4,Shape_Fill,Icon.Background});
  Rectangle({{Icon.x+10,Icon.y+9},{5,8},2,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Signal_Icon(Icon_t Icon,SIGNAL_STATUS_t state,Color_t color_off)
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

  Rectangle({{Icon.x,Icon.y+20},{5,5},0,Shape_Fill,color_one});
  Rectangle({{Icon.x+10,Icon.y+15},{5,10},0,Shape_Fill,color_two});
  Rectangle({{Icon.x+20,Icon.y+10},{5,15},0,Shape_Fill,color_three});
  Rectangle({{Icon.x+30,Icon.y+5},{5,20},0,Shape_Fill,color_four});
  Rectangle({{Icon.x+40,Icon.y},{5,25},0,Shape_Fill,color_five});
}
void SEDHOM_Icons::Bell_Icon(Icon_t Icon,bool mute_or_not,bool filled_or_not)
{
   Rectangle({{Icon.x-3,Icon.y+20},{30-4,5},4,Shape_Fill,Icon.color});
   Rectangle({{Icon.x-5,Icon.y+23},{30,5},4,Shape_Fill,Icon.color});
   Rectangle({{Icon.x-7,Icon.y+26},{30+4,5},4,Shape_Fill,Icon.color});
   Rectangle({{Icon.x,Icon.y},{20,30},10,Shape_Fill,Icon.color});
   Circle({{Icon.x+10,Icon.y+32},5,Shape_Fill,Icon.color});
   if(!filled_or_not)
   {
      Rectangle({{Icon.x-3+2,Icon.y+20+2},{30-4-4,5-1},4,Shape_Fill,Icon.Background});
      Rectangle({{Icon.x-5+2,Icon.y+23+2},{30-4,5-1},4,Shape_Fill,Icon.Background});
      Rectangle({{Icon.x-7+2,Icon.y+26+2},{30+4-4,5-4},4,Shape_Fill,Icon.Background});
      Rectangle({{Icon.x+2,Icon.y+2},{20-4,30-4},10,Shape_Fill,Icon.Background});
   }
   if(mute_or_not)
   {
     Line({{Icon.x-10,Icon.y+3},{Icon.x+35,Icon.y+28},Icon.Background});
     Line({{Icon.x-10,Icon.y+4},{Icon.x+35,Icon.y+29},Icon.Background});
     Line({{Icon.x-10,Icon.y+5},{Icon.x+35,Icon.y+30},Icon.color});
     Line({{Icon.x-10,Icon.y+6},{Icon.x+35,Icon.y+31},Icon.color});
     Line({{Icon.x-10,Icon.y+7},{Icon.x+35,Icon.y+32},Icon.Background});
     Line({{Icon.x-10,Icon.y+8},{Icon.x+35,Icon.y+33},Icon.Background});
   }
}
void SEDHOM_Icons::Menu_Icon_1(Icon_t Icon) // : : :
{
  for(int j=0;j<3;j++)
  {
    for(int i=0;i<3;i++)
    {
     Circle({{Icon.x+(j*10),Icon.y+(i*10)},3,Shape_Fill,Icon.color});
    }
  }
}
void SEDHOM_Icons::Menu_Icon_2(Icon_t Icon) // ...
{
 for(int i=0;i<3;i++)
  {
    Circle({{Icon.x+(i*10),Icon.y},3,Shape_Fill,Icon.color});
  }
}
void SEDHOM_Icons::Menu_Icon_3(Icon_t Icon) // :
{
 for(int i=0;i<3;i++)
  {
    Circle({{Icon.x,Icon.y+(i*10)},3,Shape_Fill,Icon.color});
  }
}
void SEDHOM_Icons::Menu_Icon_4(Icon_t Icon) // : :
{
  for(int j=0;j<2;j++)
  {
    for(int i=0;i<2;i++)
    {
     Circle({{Icon.x+(j*20),Icon.y+(i*20)},3,Shape_Fill,Icon.color});
    }
  }
}
void SEDHOM_Icons::Menu_Icon_5(Icon_t Icon) // =
{
  for(int j=0;j<3;j++)
  {
    Rectangle({{Icon.x,Icon.y+(j*10)},{30,5},5,Shape_Fill,Icon.color});
  }
}
void SEDHOM_Icons::Moon_Icon(Icon_t Icon)
{
   Circle({{Icon.x, Icon.y},20,Shape_Fill,Icon.color});
   Circle({{Icon.x+10,Icon.y-10},20,Shape_Fill,Icon.Background});
}
void SEDHOM_Icons::Sun_Icon(Icon_t Icon)
{
  // master circle
   Circle({{Icon.x, Icon.y},15,Shape_Fill,Icon.color});
   // small circles
   Circle({{Icon.x-25,Icon.y},3,Shape_Fill,Icon.color});
   Circle({{Icon.x+25,Icon.y},3,Shape_Fill,Icon.color});
   Circle({{Icon.x,Icon.y-25},3,Shape_Fill,Icon.color});
   Circle({{Icon.x,Icon.y+25},3,Shape_Fill,Icon.color});
   Circle({{Icon.x+20,Icon.y+20},3,Shape_Fill,Icon.color});
   Circle({{Icon.x-20,Icon.y-20},3,Shape_Fill,Icon.color});
   Circle({{Icon.x+20,Icon.y-20},3,Shape_Fill,Icon.color});
   Circle({{Icon.x-20,Icon.y+20},3,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Check_Box_Icon(Icon_t Icon,bool status,Color_t check_color,Color_t checked_fill_color)
{
  Rectangle({{Icon.x,Icon.y},{40,40},5,Shape_Fill,Icon.color});
  Rectangle({{Icon.x+3,Icon.y+3},{40-6,40-6},5,Shape_Fill,status ? checked_fill_color : Icon.Background});
  if(status)
  {
      for(int i=-1; i<=3; i++) 
      {
          Line({{Icon.x+7, Icon.y+25+i}, {Icon.x+15, Icon.y+30+i}, (i<=2 && i>=-1) ? check_color : Icon.Background});
      }
      for(int i=-3; i<=3; i++) 
      {
          Line({{Icon.x+15, Icon.y+30+i},{ Icon.x+30, Icon.y+10+i}, (i<=2 && i>=-2) ? check_color : Icon.Background});
      }
  }

}
void SEDHOM_Icons::Radio_Button_Icon(Icon_t Icon,bool status,Color_t check_color)
{
  // border
   Circle({{Icon.x,Icon.y},15,Shape_Fill,Icon.color});
   Circle({{Icon.x,Icon.y},12,Shape_Fill,Icon.Background});
   // status
  if(status) Circle({{Icon.x,Icon.y},5,Shape_Fill,check_color});
}
void SEDHOM_Icons::Text_Feild_Icon( Icon_t Icon,Text_t text ,int lenght,int max_char)
{
   Rectangle({{Icon.x,Icon.y},{lenght,40},20,Shape_Fill,Icon.color});
   Rectangle({{Icon.x+3,Icon.y+3},{lenght-6,40-6},20,Shape_Fill,Icon.Background});
   if( text.txt.length() > max_char)
   {
      String word = "...";
      String part = text.txt.substring(0, max_char-3);
      String all = part + word ;
      Text_cpp(Icon.x+10,Icon.y+25,text.txt_font,text.txt_color,all);
   }
   else
   {
    Text_cpp(Icon.x+10,Icon.y+25,text.txt_font,text.txt_color,text.txt);
   }
}
void SEDHOM_Icons::Warning_Icon( Icon_t Icon,Color_t txt_color,Shape_filled_t filled )
{
  Equilateral_Triangle({{Icon.x,Icon.y},40,filled,Direction_Up,Icon.color});
  Text_cpp(Icon.x-6,Icon.y+5,BigFont,txt_color,"!");
}
void SEDHOM_Icons::Chandelier_Icon(Icon_t Icon)
{
   Circle({{Icon.x,Icon.y},20,Shape_Fill,Icon.color});
   Circle({{Icon.x,Icon.y},20-3,Shape_Fill,Icon.Background});
   Rectangle({{Icon.x-23,Icon.y},{46,25},0,Shape_Fill,Icon.Background});
   Circle({{Icon.x,Icon.y+2},8,Shape_Fill,Icon.color});
   Circle({{Icon.x,Icon.y+2},5,Shape_Fill,Icon.Background});
   Rectangle({{Icon.x-10,Icon.y-10},{20,10},0,Shape_Fill,Icon.Background});
   Rectangle({{Icon.x-21,Icon.y},{43,3},0,Shape_Fill,Icon.color});
   Rectangle({{Icon.x-1,Icon.y-33},{3,15},2,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Smart_TV_Icon(Icon_t Icon,Color_t WIFI_icon)
{
  Rectangle({{Icon.x,Icon.y},{60,50},7,Shape_Fill,Icon.color});
  Rectangle({{Icon.x+3,Icon.y+3},{60-6,50-6},7,Shape_Fill,Icon.Background});
  WIFI_Icon({Icon.x,Icon.y,WIFI_icon,Icon.Background},WIFI_icon,WIFI_Status_conected_level_4_full);
  Rectangle({{Icon.x+8,Icon.y+50-3},{50-6,3},5,Shape_Fill,Icon.color});
  Rectangle({{Icon.x+22,Icon.y+50-3},{15,10},0,Shape_Fill,Icon.color});
  Rectangle({{Icon.x+10,Icon.y+50-3+10},{40,5},5,Shape_Fill,Icon.color});
}
void SEDHOM_Icons::Air_Conditioner_Icon(Icon_t Icon)
{
  Border_Rectangle(Icon,40,80,10,3);
  Rectangle({{Icon.x+50,Icon.y+8},{20,5},5,Shape_Fill,Icon.color});
  Border_Rectangle({Icon.x +15 , Icon.y +25 ,Icon.color , Icon.Background},20,50,10,3);
  Rectangle({{Icon.x+12,Icon.y+37},{53,3},5,Shape_Fill,Icon.color});
  Rectangle({{Icon.x+12,Icon.y+40},{55,8},5,Shape_Fill,Icon.Background});
}








//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/////////////////////////////////////////////////////////////////////////////
#endif // !SEDHOM_OS_ICONS_H_