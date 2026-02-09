#ifndef SEDHOM_OS_ICONS_AND_WIDGETS_H_
#define SEDHOM_OS_ICONS_AND_WIDGETS_H_
//////////////////////////////////////////////////////////////////////////////////////////
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Display_QRCodes.h"
///////////////////////////////////////////////////////////////////////////

init_Display_variable();

///////////////////////////////////////////////////////////////////////////
// Icons class
class SEDHOM_Icons  
{
  private:
        uint16_t mode;
  public:
        // to set and handling mode
        uint16_t Not_Mode();
        uint16_t Mode();
        void Set_Mode(Color_t Mode);
        // colors
        Color_t set_Color(int r,int g,int b);
        // define Basic shapes
        void draw_Pixel(int x,int y,Color_t color);
        void draw_Line(int x0,int y0,int x1,int y1,Color_t color);    
        void fill_Rectangle(int x,int y,int w,int h,int r,Color_t color);    
        void draw_Rectangle(int x,int y,int w,int h,int r,Color_t color);  
        void fill_Circle(int x,int y,int r,Color_t color); 
        void draw_Circle(int x,int y,int r,Color_t color);
        void fill_Triangle(int x0,int y0,int x1,int y1,int x2,int y2,Color_t color); 
        void draw_Triangle(int x0,int y0,int x1,int y1,int x2,int y2,Color_t color);

        void Right_Triangle(int x, int y, int h, int w,bool fill_or_draw, Color_t color);
        void Equilateral_Triangle_Up(int x, int y, int h,bool fill_or_draw, Color_t color);
        void Equilateral_Triangle_Down(int x, int y, int h,bool fill_or_draw, Color_t color); 
        void Equilateral_Triangle_Right(int x, int y, int h,bool fill_or_draw, Color_t color); 
        void Equilateral_Triangle_Left(int x, int y, int h,bool fill_or_draw, Color_t color); 

        void TEXT(int x,int y,const GFXfont* font,Color_t color,string_t txt);
        void Container(int x,int y,int h,int w,int raduis,Color_t color);
        void fill_rectangle_with_end(int x,int y,int h,int w,int end_volume,Color_t color,Color_t end_color);
        void Draw_Custom_int_shap(int x,int y,int h,int w,int color,int arr[]);
        void Draw_Custom_Char(int x,int y,int h,int w,int color,char arr[]);
        // effects 
        Color_t Blur(int x,int y,int h,int w,int r,int Blur_value,Color_t mode,bool circle_or_rectangle = 1);
        Color_t Color_Blur(int x,int y,int h,int w,int r,Color_t color,Color_t mode,bool circle_or_rectangle = 1);
        // Draw SEDhOM Icons
        void QRCode_Icon(int x,int y,int size,int version,string_t content,Color_t color,Color_t Background);
        void WIFI_Icon(int x,int y,WIFI_STATUS_t state,Color_t color_on,Color_t color_off,Color_t Background);
        void Battary_Icon(int x,int y,int range,Color_t color,Color_t txt_color,Color_t Background,bool low_charge_red_color);
        void Home_Icon(int x,int y,Color_t color,Color_t Background);
        void Setting_Icon(int x,int y,Color_t color,Color_t Background);
        void Add_Icon(int x,int y,Color_t color,Color_t Background=0);
        void SD_Card_Icon(int x,int y,Color_t Background=0);
        void Control_Icon(int x,int y,Color_t color,Color_t Background);
        void Sensor_Icon(int x,int y,Color_t color,Color_t Background=0);
        void Power_off_Icon(int x,int y,Color_t color,Color_t Background);
        void Bluetooth_Icon(int x , int y ,BLUETOOTH_STATUS_t connect_status,Color_t color,Color_t Background);
        void Button_Icon(int x,int y,Color_t Background=0,bool print_on_and_off = 0);
        void Display_Time_Icon(int x,int y,int hour,int minut,int sec,word_t time_name,Color_t color,Color_t Background=0);
        void Terminal_Icon(int x,int y,Color_t Background=0);
        void About_Icon(int x,int y ,Color_t color,Color_t Background);
        void Display_Date_Icon(int x,int y,Color_t color,Color_t text_color,int year,word_t month_name,int Day,word_t week_day_name,Color_t Background);
        void UP_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void DOWN_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void LEFT_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void RIGHT_Aroow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void Back_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void After_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void Color_Icon(int x,int y,Color_t Background=0);
        void Time_Icon(int x,int y,Color_t color,Color_t Background);
        void Date_Icon(int x,int y,Color_t color,Color_t Background);
        void Switch_Icon(int x,int y,Color_t color_on,Color_t color_off,Color_t thumb_color,Color_t txt_color,bool state,Color_t Background=0);
        void label_Icon(int x,int y,int h,int w,int end,word_t string_in_label,Color_t color_str_in_label,Color_t color,Color_t Background);
        void slide_Icon(int x,int y,int h,byte_t range ,Color_t color_active,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color,Color_t Background=0);
        void file_Icon(int x,int y,Color_t color,Color_t end_color,Color_t file_extend_color,word_t file_extend,Color_t Background);
        void folder_Icon(int x,int y,Color_t folder_color,Color_t Background=0);
        void Divider_vertical(int x,int y,int length , int thikness,Color_t color);
        void Divider_Horezontal(int x,int y,int length , int thikness,Color_t color);
        void ID_Card_Icon(int x,int y,Color_t color,Color_t main_font_color,Color_t font_color,Color_t image_background,bool default_image,bool eye,bool prof,char* name,char* unversity,char* department_1,char* department_2,char* Born,char* number,Color_t Background=0);
        void Joy_Stick_Icon(int x,int y,int thumb_x,int thumb_y,int size,int thumb_size,Color_t color,Color_t OutLine,Color_t thumb,Color_t in ,Color_t Background=0);
        void Temperature_Meter_Icon(int x,int y,int value,bool show_val_dashes,Color_t color,Color_t Outline,Color_t Background);
        void Tone_Icon(int x,int y,bool is_muted_or_not,Color_t color,Color_t Background);
        void Sound_value_Icon(int x,int y,int value,Color_t color,Color_t thikness_color,Color_t Background,bool thikness_or_not=0);
        void Video_Icon(int x,int y,Color_t color,Color_t Background);
        void Block_Icon(int x,int y,bool open_or_closed,Color_t color,Color_t Background);
        void Signal_Icon(int x,int y,SIGNAL_STATUS_t state,Color_t color_on,Color_t color_off,Color_t Background);
        void Bell_Icon(int x,int y,bool mute_or_not,bool filled_or_not,Color_t color,Color_t Background);




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
// colors
Color_t SEDHOM_Icons::set_Color(int r,int g,int b)
{
   return(Set_Color(r,g,b));
}
// Basic shapes function  
void SEDHOM_Icons::draw_Pixel(int x,int y,Color_t color)
{
    Draw_Pixel(x,y,color);
}
void SEDHOM_Icons::draw_Line(int x0, int y0, int x1, int y1, uint16_t color)
{
    Draw_Line(x0,y0,x1,y1,color);
}                                     
void SEDHOM_Icons::fill_Rectangle(int x,int y,int w,int h,int r,Color_t color)
{
    Fill_Rectangle(x,y,h,w,r,color);
}    
void SEDHOM_Icons::draw_Rectangle(int x,int y,int w,int h,int r,Color_t color)
{
    Draw_Rectangle(x,y,h,w,r,color);
}    
void SEDHOM_Icons::fill_Circle(int x,int y,int r,Color_t color)
{
    Fill_Circle(x,y,r,color);
}    
void SEDHOM_Icons::draw_Circle(int x,int y,int r,Color_t color)
{
    Draw_Circle(x,y,r,color);
}    
void SEDHOM_Icons::fill_Triangle(int x0,int y0,int x1,int y1,int x2,int y2,Color_t color)
{
     Fill_Triangle(x0,y0,x1,y1,x2,y2,color);
}    
void SEDHOM_Icons::draw_Triangle(int x0,int y0,int x1,int y1,int x2,int y2,Color_t color)
{
     Draw_Triangle(x0,y0,x1,y1,x2,y2,color);
}  
void SEDHOM_Icons::Right_Triangle(int x, int y, int h, int w,bool fill_or_draw, Color_t color)
{
    if(fill_or_draw) {Fill_Triangle(x, y, x, y + w, x + h, y + w, color);}
    else {Draw_Triangle(x, y, x, y + w, x + h, y + w, color);}
}
void SEDHOM_Icons::Equilateral_Triangle_Up(int x, int y, int h,bool fill_or_draw, uint16_t color) 
{
    float height = h * sqrt(3) / 2.0;

    int x_0 = x;              
    int y_0 = y - (2.0/3.0)*height;

    int x_1 = x - h/2;        
    int y_1 = y + (1.0/3.0)*height;

    int x_2 = x + h/2;        
    int y_2 = y + (1.0/3.0)*height;

    if(fill_or_draw) fill_Triangle( x_0,  y_0,  x_1,  y_1,  x_2,  y_2, color);
    else draw_Triangle( x_0,  y_0,  x_1,  y_1,  x_2,  y_2, color);
}
void SEDHOM_Icons::Equilateral_Triangle_Down(int x, int y, int h,bool fill_or_draw, uint16_t color) 
{
    float height = h * sqrt(3) / 2.0;

    int x_0 = x;               
    int y_0 = y + (2.0/3.0)*height;  

    int x_1 = x - h/2;        
    int y_1 = y - (1.0/3.0)*height;  

    int x_2 = x + h/2;        
    int y_2 = y - (1.0/3.0)*height;  

    if(fill_or_draw) fill_Triangle(x_0, y_0, x_1, y_1, x_2, y_2, color);
    else draw_Triangle(x_0, y_0, x_1, y_1, x_2, y_2, color);
}
void SEDHOM_Icons::Equilateral_Triangle_Right(int x, int y, int h,bool fill_or_draw, uint16_t color)
{
    float height = h * sqrt(3) / 2.0;

    int x_0 = x + (2.0/3.0)*h; 
    int y_0 = y;

    int x_1 = x - (1.0/3.0)*h; 
    int y_1 = y - height/2;

    int x_2 = x - (1.0/3.0)*h; 
    int y_2 = y + height/2;

    if(fill_or_draw) fill_Triangle(x_0, y_0, x_1, y_1, x_2, y_2, color);
    else draw_Triangle(x_0, y_0, x_1, y_1, x_2, y_2, color);
}
void SEDHOM_Icons::Equilateral_Triangle_Left(int x, int y, int h,bool fill_or_draw, uint16_t color)
{
    float height = h * sqrt(3) / 2.0;

    int x_0 = x - (2.0/3.0)*h; 
    int y_0 = y;

    int x_1 = x + (1.0/3.0)*h; 
    int y_1 = y - height/2;

    int x_2 = x + (1.0/3.0)*h;
    int y_2 = y + height/2;

    if(fill_or_draw) fill_Triangle(x_0, y_0, x_1, y_1, x_2, y_2, color);
    else draw_Triangle(x_0, y_0, x_1, y_1, x_2, y_2, color);
}
void SEDHOM_Icons::TEXT(int x,int y,const GFXfont* font,Color_t color,string_t txt) 
{
    Text(x,y,font,color,txt);
}
void SEDHOM_Icons::Container(int x,int y,int h,int w,int raduis,Color_t color)
{
    Fill_Rectangle(x, y, h, w, raduis, color);
}
void SEDHOM_Icons::fill_rectangle_with_end(int x,int y,int h,int w,int end_volume,Color_t color,Color_t end_color)
{
    Fill_Rectangle(x,y,h,w,5,end_color);
    Fill_Rectangle(x + end_volume,y + end_volume,h - 2*end_volume,w - 2*end_volume,5,color);
}
void SEDHOM_Icons::Draw_Custom_Char(int x,int y,int h,int w,int color,char arr[])
{
  for(int i=0; i<h; i++) 
  {
    for(int j=0; j<w; j++) 
    {
      if(((arr[i]) >> (w-1-j)) & 0x01)
      {
        draw_Pixel(x+j, y+i, color); 
      }
    }
  }
}
void SEDHOM_Icons::Draw_Custom_int_shap(int x,int y,int h,int w,int color,int arr[])
{
      for(int i=0; i<h; i++) 
  {
    for(int j=0; j<w; j++) 
    {
      if(((arr[i]) >> (w-1-j)) & 0x01)
      {
        draw_Pixel(x+j, y+i, color); 
      }
    }
  }
}
// effects
Color_t SEDHOM_Icons::Blur(int x,int y,int h,int w,int r,int Blur_value,Color_t mode,bool circle_or_rectangle = 1)
{
  Color_t color_value = map(Blur_value,mode?20:0,mode?0:20,0,255);

  Color_t color = set_Color(color_value,color_value,color_value);
  if(circle_or_rectangle)
  {
    fill_Rectangle(x,y,h,w,r,color);
  }
  else
  {
    fill_Circle(x,y,r,color);
  }
  return color;
}
Color_t SEDHOM_Icons::Color_Blur(int x,int y,int h,int w,int r,Color_t color,Color_t mode,bool circle_or_rectangle = 1)
{
  if(circle_or_rectangle)
  {
    fill_Rectangle(x,y,h,w,r,color);
  }
  else
  {
    fill_Circle(x,y,r,color);
  }
  return color;
}
// icons and widgets
void SEDHOM_Icons::QRCode_Icon(int x,int y,int size,int version,string_t content,Color_t color,Color_t Background)
{
    SEDHOM_QRCode(x,y,size,Background,color,version,content);
    
}
void SEDHOM_Icons::WIFI_Icon(int x,int y,WIFI_STATUS_t state,Color_t color_on,Color_t color_off,Color_t Background)
{
    if(state != WIFI_Status_not_connected)
    {
        uint16_t one=RED,two=RED,three=RED,four=RED;
        if(state==WIFI_Status_no_internet){one=color_off;two=color_off;three=color_off;four=color_off;}
        else if(state==WIFI_Status_conected_level_1){one=color_off;two=color_off;three=color_off;four=color_on;}
        else if(state==WIFI_Status_conected_level_2_half){one=color_off;two=color_off;three=color_on;four=color_on;}
        else if(state==WIFI_Status_conected_level_3){one=color_off;two=color_on;three=color_on;four=color_on;}
        else if(state==WIFI_Status_conected_level_4_full){one=color_on;two=color_on;three=color_on;four=color_on;}
        Fill_Circle(x,y,20,one);
        Fill_Circle(x,y,20-3,Background);
        Fill_Circle(x,y,20-6,two);
        Fill_Circle(x,y,20-9,Background);
        Fill_Circle(x,y,20-12,three);
        Fill_Circle(x,y,20-15,Background);
        Fill_Rectangle(x-21,y,42,20,5,Background);
        Fill_Triangle(x-3,y+5,x+24,y+5,x+21,y-20,Background);
        Fill_Triangle(x+3,y+5,x-24,y+5,x-21,y-20,Background);
        Fill_Circle(x,y,20-18,four);
        if(state==WIFI_Status_no_internet)
        {
        Text(x+8,y,BigFont,color_off,"!");
        }
    }
    else if(state==WIFI_Status_not_connected)
    {
      Fill_Rectangle(x-15,y-27,37,38,5,Background);
    }
    Fill_Rectangle(x-10,y+13,20,10,0,Background);
} 
void SEDHOM_Icons::Battary_Icon(int x,int y,int range,Color_t color,Color_t txt_color,Color_t Background,bool low_charge_red_color=true)
{
    int txt_x=0;
    int txt_y_index = y+22;
    uint16_t color_Battary;
    if(low_charge_red_color==1)
    {
        if(range<20){color_Battary=RED; txt_x=(range>=10)?x-60:x-45;txt_color=Not_Mode();}
        else if(range>=20){color_Battary=color;txt_x=(range==100)?x-65:x-58;}
    }
    else if(low_charge_red_color==0)
    {
        if(range<20){color_Battary=GREEN; txt_x=(range>=10)?x-53:x-45;}
        else if(range>=20){color_Battary=GREEN;txt_x=(range==100)?x-65:x-58;}
    }
    int rangeB=map(range,0,100,5,45);
    Fill_Rectangle(x, y, 50,30, 5, color_Battary);
    Fill_Rectangle(x+3, y+3, 50-6,30-6, 5, Background);
    Fill_Rectangle(x+50-1, y+10,10,10,0,color_Battary);
    Fill_Rectangle(x+2,y+3,rangeB,30-6,5,color_Battary);
    char range_as_str[10];
    sprintf(range_as_str, "%d", range);
    Text(txt_x+60,txt_y_index,BigFont,txt_color,range_as_str);
    Text_Add("%");
}
void SEDHOM_Icons::Home_Icon(int x,int y,Color_t color,Color_t Background)
{
    
    Fill_Triangle(x+30,y,(x+30)+25,y+15,(x+30)-25,y+15,color);
    Fill_Rectangle(x+10, y+12,40,25,5,color);
    Fill_Rectangle(x+23, y+20,15,20,5,Background);
}
void SEDHOM_Icons::Setting_Icon(int x,int y,Color_t color,Color_t Background)
{
    Fill_Circle(x-10, y,10, color);
    Fill_Circle(x-10, y-10, 3, color);
    Fill_Circle(x-10, y+10, 3, color);
    Fill_Circle(x, y-5, 3, color);
    Fill_Circle(x, y+5, 3, color);
    Fill_Circle(x-20, y-5, 3, color);
    Fill_Circle(x-20, y+5, 3, color);

    Fill_Circle(x-10, y, 5, Background);
}
void SEDHOM_Icons::Add_Icon(int x,int y,Color_t color,Color_t Background=0)
{
    Fill_Rectangle(x+15,y-2+15,30,5,5,color);
    Fill_Rectangle(x+13+15,y-14+15,5,30,5,color);
}
void SEDHOM_Icons::SD_Card_Icon(int x,int y,Color_t Background=0)
{
    Fill_Rectangle(x-5, y-5,40,45,5,WHITE);
    Fill_Rectangle(x, y,30,35,5,BLACK);
    Fill_Rectangle(x+15,y,17,8,5,WHITE);
    Fill_Triangle(x+30,y+8,x+17,y+8,x+17,y,BLACK);
    Fill_Rectangle(x+4,y+20,2,10,5,YELLOW);
    Fill_Rectangle(x+11,y+20,2,10,5,YELLOW);
    Fill_Rectangle(x+18,y+20,2,10,5,YELLOW);
    Fill_Rectangle(x+25,y+20,2,10,5,YELLOW);
    Fill_Rectangle(x+12,y+1,5,8,0,BLACK);
}
void SEDHOM_Icons::Control_Icon(int x,int y,Color_t color,Color_t Background)
{
    Fill_Rectangle(x, y,40,3,5, color);
    Fill_Rectangle(x,y+15,40,3,5,color);
    Fill_Rectangle(x,y+30,40,3,5,color);
    Fill_Circle(x+28,y+1,6,color);
    Fill_Circle(x+12,y+16,6,color);
    Fill_Circle(x+31-2,y+30+1,6,color);
    Fill_Circle(x+28,y+1,3,Background);
    Fill_Circle(x+12,y+16,3,Background);
    Fill_Circle(x+29,y+31,3,Background);
}
void SEDHOM_Icons::Sensor_Icon(int x,int y,Color_t color,Color_t Background=0)
{
    Fill_Rectangle(x+3,y,30,10,5,color);
    Fill_Circle(x+18, y+10,5,color);
    Draw_Line(x+12,y+17,x+6,y+25,color);
    Draw_Line(x+23,y+17,x+30,y+25,color);
    Draw_Line(x+18,y+17,x+18,y+25,color);
}
void SEDHOM_Icons::Power_off_Icon(int x,int y,Color_t color,Color_t Background)
{
    Fill_Circle(x,y,20,color);
    Fill_Circle(x,y,17,Background);
    Fill_Rectangle(x-8, y-20,16,20, 0,Background);
    Fill_Rectangle(x-1, y-23,2,23,0,color);
}
void SEDHOM_Icons::Bluetooth_Icon(int x , int y ,BLUETOOTH_STATUS_t connect_status,Color_t color,Color_t Background)
{
 if(connect_status == BLuetooth_Status_open_and_not_connected || connect_status == BLuetooth_Status_open_and_connected )
 {
    Fill_Triangle( (x) , (y) , (x+15) , (y+10) , (x) , (y+20) , color);
    Fill_Triangle( (x) , (y)+15 , (x+15) , (y+10)+15 , (x) , (y+20)+15 , color);
    Fill_Triangle( (x-15) , (y+5) , (x) , (y+16) , (x-15) , (y+30) , color);
    Fill_Triangle( (x-15)+2 , (y+5)+3 , (x)-2 , (y+16) , (x-15)+2 , (y+30)-3 , Background);
    Fill_Triangle( (x)+2 , (y)+3 , (x+15)-2 , (y+10) , (x)+2 , (y+20)-4 , Background);
    Fill_Triangle( ((x))+2 , ((y)+15)+3 , ((x+15))-2 , ((y)+15)+10 , ((x))+2 , ((y+20)+15)-3 , Background);
    Fill_Rectangle(x-18, y+2,6,30,0, Background);
    if(connect_status == BLuetooth_Status_open_and_connected)
    {
        Fill_Circle(x-10, y+17, 1, color);
        Fill_Circle(x+13, y+18, 1, color);
    }
 }
 else
 {
    Fill_Rectangle(x-20, y-10,42,50,0, Background);
 }
}
void SEDHOM_Icons::Button_Icon(int x,int y,Color_t Background=0,bool print_on_and_off = 0)
{
    Fill_Rectangle(x,y,50,20 ,30,GREEN);
    Fill_Circle(x+39,y+10,7,WHITE);
    Fill_Rectangle(x,y+25,50,20,30,RED);
    Fill_Circle(x+10,y+35,7,WHITE);

    if(print_on_and_off)
    {
         Text(x+8, y+16,SmallFont,WHITE,"ON");
         Text(x+23, y+41,SmallFont,WHITE,"OFF");
    }
}
void SEDHOM_Icons::Display_Time_Icon(int x,int y,int hour,int minut,int sec,word_t time_name,Color_t color,Color_t Background=0)
{
    char Hour_as_str[3];
    char min_as_str[3];
    char sec_as_str[3];
    sprintf(Hour_as_str,"%d",hour);
    sprintf(min_as_str,"%d",minut);
    sprintf(sec_as_str,"%d",sec);
    //hour
    if(hour < 10)
    {
       Text(x,y+35,FONT_SEVENSEGMENT,color,"0");
       Text_Add(Hour_as_str);       
    }
    else
    {
       Text(x,y+35,FONT_SEVENSEGMENT,color,Hour_as_str);
    }
    // minutes
    if(minut < 10)
    {
       Text(x+83,y+35,FONT_SEVENSEGMENT,color,"0");
       Text_Add(min_as_str);       
    }
    else
    {
       Text(x+83,y+35,FONT_SEVENSEGMENT,color,min_as_str);
    }
    // seprator
    Fill_Circle(x+73,y,5,color);
    Fill_Circle(x+73,y+20,5,color);
    //sec
    Text(x+146,y,BigFont,color,sec_as_str);
    // time name
    Text(x+146,y+38,BigFont,color,time_name);
}
void SEDHOM_Icons::Terminal_Icon(int x,int y,Color_t Background=0)
{
    Fill_Rectangle(x,y,50,50,5,WHITE);
    Fill_Rectangle(x+3,y+3,44,44,5,BLACK);
    Text(x+10,y+30,BigFont,GREEN,">_");
}
void SEDHOM_Icons::About_Icon(int x,int y ,Color_t color,Color_t Background)
{
    Fill_Circle(x,y,20,color);
    Fill_Circle(x,y,17,Background);
    Text(x-6,y+8,BigFont,color,"!");
}
void SEDHOM_Icons::Display_Date_Icon(int x,int y,Color_t color,Color_t text_color,int year,char * month_name,int Day,char * week_day_name,Color_t Background)
{
    char year_as_str[5];
    char Day_as_str[5];
    sprintf(year_as_str,"%d",year);
    sprintf(Day_as_str,"%d",Day);
    Fill_Rectangle(x,y,130,130,15,color);
    Text(x+42,y+40,BigFont,text_color,week_day_name);
    Text(x+47,y+65,BigFont,text_color,Day_as_str);
    Text(x+42,y+90,BigFont,text_color,month_name);
    Text(x+35,y+115,BigFont,text_color,year_as_str);

    // Draw_Line(x+15,y,x+10,y+8,Background);
    // Draw_Line(x+15+1,y,x+10+1,y+8,Background);
    // Draw_Line(x+15+2,y,x+10+2,y+8,Background);
    // Draw_Line(x+15+3,y,x+10+3,y+8,Background);
    // Draw_Line(x+15+4,y,x+10+4,y+8,Background);
    // Draw_Line(x+15+20,y,x+10+20,y+8,Background);
    // Draw_Line(x+15+1+20,y,x+10+1+20,y+8,Background);
    // Draw_Line(x+15+2+20,y,x+10+2+20,y+8,Background);
    // Draw_Line(x+15+3+20,y,x+10+3+20,y+8,Background);
    // Draw_Line(x+15+4+20,y,x+10+4+20,y+8,Background);
    // Draw_Line(x+15+40,y,x+10+40,y+8,Background);
    // Draw_Line(x+15+1+40,y,x+10+1+40,y+8,Background);
    // Draw_Line(x+15+2+40,y,x+10+2+40,y+8,Background);
    // Draw_Line(x+15+3+40,y,x+10+3+40,y+8,Background);
    // Draw_Line(x+15+4+40,y,x+10+4+40,y+8,Background);
    // Draw_Line(x+15+60,y,x+10+60,y+8,Background);
    // Draw_Line(x+15+1+60,y,x+10+1+60,y+8,Background);
    // Draw_Line(x+15+2+60,y,x+10+2+60,y+8,Background);
    // Draw_Line(x+15+3+60,y,x+10+3+60,y+8,Background);
    // Draw_Line(x+15+4+60,y,x+10+4+60,y+8,Background);
    // Draw_Line(x+15+80,y,x+10+80,y+8,Background);
    // Draw_Line(x+15+1+80,y,x+10+1+80,y+8,Background);
    // Draw_Line(x+15+2+80,y,x+10+2+80,y+8,Background);
    // Draw_Line(x+15+3+80,y,x+10+3+80,y+8,Background);
    // Draw_Line(x+15+4+80,y,x+10+4+80,y+8,Background);
    // Draw_Line(x+15+100,y,x+10+100,y+8,Background);
    // Draw_Line(x+15+1+100,y,x+10+1+100,y+8,Background);
    // Draw_Line(x+15+2+100,y,x+10+2+100,y+8,Background);
    // Draw_Line(x+15+3+100,y,x+10+3+100,y+8,Background);
    // Draw_Line(x+15+4+100,y,x+10+4+100,y+8,Background);

    Fill_Circle(x+114-100,y+8,4,Background);
    Fill_Circle(x+114-80,y+8,4,Background);
    Fill_Circle(x+114-60,y+8,4,Background);
    Fill_Circle(x+114-40,y+8,4,Background);
    Fill_Circle(x+114-20,y+8,4,Background);
    Fill_Circle(x+114,y+8,4,Background);

}
void SEDHOM_Icons::UP_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0)
{
  Fill_Triangle(x-20-6,y+25+3,x,y-6,x+20+6,y+25+3,end_color);
  Fill_Triangle(x-20,y+25,x,y,x+20,y+25,color);
  fill_rectangle_with_end(x-10,y+25,20,20,3,color,end_color);
  Fill_Rectangle(x-10+3,y+25,20-6,20-3,0,color);
}
void SEDHOM_Icons::DOWN_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0)
{
  Fill_Triangle(x-20-6,y+25-3,x,y-6+60,x+20+6,y+25-3,end_color);
  Fill_Triangle(x-20,y+25,x,y+50,x+20,y+25,color);
  fill_rectangle_with_end(x-10,y+5,20,20,3,color,end_color);
  Fill_Rectangle(x-10+3,y+8,20-6,20-3,0,color);
}
void SEDHOM_Icons::LEFT_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0)
{
  Fill_Triangle(x-6,y,x+25+3,y-25-6,x+25+3,y+25+6,end_color);
  Fill_Triangle(x,y,x+25,y-25,x+25,y+25,color);
  fill_rectangle_with_end(x+25,y-8-1,20,20,3,color,end_color);
  Fill_Rectangle(x+25,y-8+3-1,20-3,20-6,0,color);
}
void SEDHOM_Icons::RIGHT_Aroow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0)
{
  Fill_Triangle(x+6+50,y,x+25-3,y-25-6,x+25-3,y+25+6,end_color);
  Fill_Triangle(x+50,y,x+25,y-25,x+25,y+25,color);
  fill_rectangle_with_end(x+5,y-8-1,20,20,3,color,end_color);
  Fill_Rectangle(x+8,y-8+3-1,20-3,20-6,0,color);
}
void SEDHOM_Icons::Color_Icon(int x,int y,Color_t Background=0)
{
    Fill_Rectangle(x,y,30,30,5,MAGENTA);
    Fill_Rectangle(x+5,y+5,30,30,5,RED);
    Fill_Rectangle(x+10,y+10,30,30,5,BLUE);
    Fill_Rectangle(x+15,y+15,30,30,5,GREEN);
}
void SEDHOM_Icons::Time_Icon(int x,int y,Color_t color,Color_t Background)
{
    Fill_Circle(x,y,20,color);
    Fill_Circle(x,y,17,Background);
    Fill_Rectangle(x-2,y-14,3,12,5,color);
    Fill_Rectangle(x,y-1,10,3,5,color);
    Fill_Circle(x,y,4,color);
}
void SEDHOM_Icons::Date_Icon(int x,int y,Color_t color,Color_t Background)
{
    Fill_Rectangle(x,y,45,48,5,color);
    Fill_Rectangle(x+2,y+10,41,36,5,Background);
    Fill_Circle(x+5,y+5,3,Background);
    Fill_Circle(x+23,y+5,3,Background);
    Fill_Circle(x+40,y+5,3,Background);
    Text(x+20,y+24,SmallFont,color,"6");
    Text(x+12,y+33,SmallFont,color,"Jun");
    Text(x+9,y+46,SmallFont,color,"2025");
}
void SEDHOM_Icons::Back_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0)
{
  Fill_Triangle(x-6,y,x+25+3,y-15-6,x+25+3,y+15+6,end_color);
  Fill_Triangle(x,y,x+25,y-15,x+25,y+15,color);
  fill_rectangle_with_end(x+25,y-8-1,25,18,3,color,end_color);
  Fill_Rectangle(x+22,y-8+3-1,12,12,5,color);
}
void SEDHOM_Icons::After_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0)
{
  Fill_Triangle(x+6+50,y,x+25-3,y-15-6,x+25-3,y+15+6,end_color);
  Fill_Triangle(x+50,y,x+25,y-15,x+25,y+15,color);
  fill_rectangle_with_end(x,y-8-1,25,18,3,color,end_color);
  fill_Rectangle(x+15,y-8+3-1,12,13,5,color);
}
void SEDHOM_Icons::Switch_Icon(int x,int y,Color_t color_on,Color_t color_off,Color_t thumb_color,Color_t txt_color,bool state,Color_t Background=0)
{
    Color_t color = color_off;
    int index = x+57;
    int index_str = x-13;
    word_t state_str = "OFF";
    color = (state) ? color_on : color_off ;
    index = (state) ? (x+20) : (x+80) ;
    index_str = (state) ? (x+50) : (x+10) ;
    state_str = (state) ? "ON" : "OFF" ;
    Fill_Rectangle(x,y,100,40,50,color);
    Fill_Circle(index,y+20,15,thumb_color);//not mode
    Text((index_str),y+28,BigFont,txt_color,state_str);//mode
}
void SEDHOM_Icons::label_Icon(int x,int y,int h,int w,int end,word_t string_in_label,Color_t color_str_in_label,Color_t color,Color_t Background)
{
    Color_t label_color_in_func = color;
    float num = atoi(string_in_label);
    if(string_in_label == "OFF" || string_in_label == "off" || num == 0){label_color_in_func = RED;}
    else if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = color;}
    //else {label_color_in_func = color;}
    if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = color;}
   Fill_Rectangle(x,y,h,w,5,label_color_in_func); 
   Fill_Rectangle(x+end,y+end,h-2*end,w-2*end,5,Background); 
   Text(x+10,y+(0.6*w),SmallFont,color_str_in_label,string_in_label);
}
void SEDHOM_Icons::slide_Icon(int x,int y,int h,byte_t range ,Color_t color_active,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color,Color_t Background=0)
{
    long index = map(range,0,100,0,h);
    char range_str[5];
    sprintf(range_str,"%d",range);

    Fill_Rectangle(x,y,h,10,5,color_not_active);
    Fill_Rectangle(x,y,index,10,5,color_active);
    Fill_Circle(x+index,y+5,10,Not_Mode());
    fill_rectangle_with_end(x+h+15,y-10,40,30,3,Mode(),box_color);
    Text(x+h+8+15,y+19-8,SmallFont,range_in_box_color,range_str);
}
void SEDHOM_Icons::file_Icon(int x,int y,Color_t color,Color_t end_color,Color_t file_extend_color,word_t file_extend,Color_t Background)
{
    fill_rectangle_with_end(x,y,50,60,3,Background,end_color);
    fill_rectangle_with_end(x-10,y+30,30,20,3,color,end_color);
    fill_rectangle_with_end(x+29,y-1,30,21,3,Background,Background);
    Fill_Triangle(x+6+43,y+20,x+29,y,x+29,y+20,end_color);
    Fill_Triangle(x+43,y+18,x+29+3,y+6,x+29+3,y+18,color);
    Fill_Rectangle(x+10,y+15,15,2,5,end_color);
    Fill_Rectangle(x+10,y+25,30,2,5,end_color);    
    Fill_Rectangle(x+25,y+35,15,2,5,end_color);
    Fill_Rectangle(x+25,y+45,15,2,5,end_color);
    Text(x-5,y+46,SmallFont,file_extend_color,file_extend);
}
void SEDHOM_Icons::folder_Icon(int x,int y,Color_t folder_color,Color_t Background=0)
{
    Fill_Rectangle(x,y,30,40,5,folder_color);
    Fill_Rectangle(x+28,y+5,40,20,5,folder_color);
    fill_rectangle_with_end(x+5,y+10,60,20,1,WHITE,BLACK);
    Fill_Rectangle(x,y+20,68,35,5,folder_color);
    Fill_Rectangle(x,y+20,69,1,0,BLACK);

}
void SEDHOM_Icons::Divider_vertical(int x,int y,int length , int thikness,Color_t color)
{
    Fill_Rectangle(x,y,length,thikness,1,color);
}
void SEDHOM_Icons::Divider_Horezontal(int x,int y,int length , int thikness,Color_t color)
{
    Fill_Rectangle(x,y,thikness,length,1,color);
}
void SEDHOM_Icons::ID_Card_Icon(int x,int y,Color_t color,Color_t main_font_color,Color_t font_color,Color_t image_background,bool default_image,bool eye,bool prof,char* name,char* unversity,char* department_1,char* department_2,char* Born,char* number,Color_t Background=0)
{
    #define x1   x
    #define y1   y

    #define h1    270
    #define w1    200

    Color_t color_id =0;
    if(color == WHITE) color_id = BLACK;
    else if(color == BLACK) color_id = WHITE;
    else  color_id = color;
    Container(x1-3,y1-3,h1+6,w1+6,20,color_id);
    Container(x1,y1,h1,w1,20,color);
    Text(((prof)?x1+60:x1+80),y1+20,BigFont,main_font_color,((prof)?"PROFESSER":"STUDENT"));
    Divider_vertical(x1+10,y1+35,h1-20,3,main_font_color);
    Text(x1+30,y1+55,SmallFont,font_color,"IDENTITY CARD");

    Text(x1+10,y1+70,SmallFont,main_font_color,((prof)?"Dr Name":"Nmae"));
    Text(x1+10,y1+85,SmallFont,font_color,name);

    Text(x1+10,y1+100,SmallFont,main_font_color,((prof)?"Unversity":"Stadies at"));
    Text(x1+10,y1+115,SmallFont,font_color,unversity);

    Text(x1+10,y1+130,SmallFont,main_font_color,"Department");
    Text(x1+10,y1+145,SmallFont,font_color,department_1);
    Text(x1+10,y1+160,SmallFont,font_color,department_2);

    Text(x1+10,y1+175,SmallFont,main_font_color,"Born");
    Text(x1+10,y1+190,SmallFont,font_color,Born);

    Container(x1+160,y1+45,100,110,0,image_background);
    
    if(default_image)
    {
        Fill_Circle(x1+210,y1+160,40,DARKGREY);
        Fill_Circle(x1+210,y1+100,25,DARKGREY);
        if(eye)
        {
            Fill_Circle(x1+220,y1+97,7,BLACK);
            Fill_Circle(x1+220,y1+97,5,DARKGREY);
            Fill_Circle(x1+220,y1+97,1,BLACK);//eye
            Divider_vertical(x1+205,y1+97,10,2,BLACK);
            Fill_Circle(x1+200,y1+97,7,BLACK);
            Fill_Circle(x1+200,y1+97,5,DARKGREY);
            Fill_Circle(x1+200,y1+97,1,BLACK);//eye
            Divider_vertical(x1+225,y1+97,10,2,BLACK);
            Divider_vertical(x1+185,y1+97,10,2,BLACK);
        }
    }
    Fill_Rectangle(x1+150,y1+155,120,45,15,color);
    Text(x1+157,y1+175,SmallFont,font_color,number);
}
void SEDHOM_Icons::Joy_Stick_Icon(int x,int y,int thumb_x,int thumb_y,int size,int thumb_size,Color_t color,Color_t OutLine,Color_t thumb,Color_t in ,Color_t Background=0)
{
  fill_Circle(x,y,size,OutLine);
  fill_Circle(x,y,size-3,color);
  Equilateral_Triangle_Up(x,y-35,10,Fill_shape,in);
  Equilateral_Triangle_Down(x,y+35,10,Fill_shape,in);
  Equilateral_Triangle_Right(x+35,y,10,Fill_shape,in);
  Equilateral_Triangle_Left(x-35,y,10,Fill_shape,in);
  int dx = thumb_x - x;
  int dy = thumb_y - y;
  if ((dx*dx + dy*dy) <= (size/2)*(size/2))
  {
      fill_Circle(thumb_x, thumb_y, thumb_size, thumb);
  }
}
void SEDHOM_Icons::Temperature_Meter_Icon(int x,int y,int value,bool show_val_dashes,Color_t color,Color_t Outline,Color_t Background)
{
  Color_t color_dash =RED;
  value = constrain(value, 0, 100);
  fill_Circle(x+50/2,y+150+25,50,Outline);
  fill_Rectangle(x,y,150,50,5,Outline);
  fill_Rectangle(x+5,y+5,150,50-10,5,Background);
  fill_Circle(x+50/2,y+150+25,50-5,Background);
  fill_Circle(x+50/2,y+150+25,50-13,color);
  int levelHeight = map(value, 0, 100, 0, 140);
  fill_Rectangle(x+12,y + 150 - levelHeight,levelHeight,50-24,5,color);
  if(show_val_dashes)
  {
   TEXT(x+55,y+10,FONT_BIG,red,"-100");
    TEXT(x+55,y+135,FONT_BIG,Blue,"-0");
    for (int i=0;i<=10; i++) 
    {
      if(i==3) color_dash = Orange;
      else if(i==8) color_dash = blue;
      TEXT(x+55,y+25+i*10,FONT_BIG,color_dash,"-");
    }
  }
}
void SEDHOM_Icons::Tone_Icon(int x,int y,bool is_muted_or_not,Color_t color,Color_t Background)
{
   fill_Circle(x,y,5,color);
   fill_Circle(x,y,5-2,Background);
   fill_Circle(x+20,y,5,color);
   fill_Circle(x+20,y,5-2,Background);
   fill_Rectangle(x+4,y-20,20,2,0,color);
   fill_Rectangle(x+4+20,y-20,20,2,0,color);
   fill_Rectangle(x+4,y-20,2,20,0,color);
   if(is_muted_or_not)
   {   
     draw_Line(x-5,y-20,x+32,y-5,color);    
     draw_Line(x-5,y-20+1,x+32,y-5+1,color);    
   }
}
void SEDHOM_Icons::Sound_value_Icon(int x,int y,int value,Color_t color,Color_t thikness_color,Color_t Background,bool thikness_or_not=0)
{
  int val = value;
  value = constrain(value,0,100);
  value = map(value,0,100,150,0);
  fill_Rectangle(x,y,150,50,40,thikness_or_not?thikness_color:color);
  fill_Rectangle(x+5,y+5,150-10,50-10,40,Background);
  fill_Rectangle(x+5,(y+value+5),((val<15)?(0):(150-value-10)),50-10,40,color);
  Tone_Icon(65,180,(val==0)?true:false,(val<20)?color:Background,(val<20)?Background:color);
}
void SEDHOM_Icons::Video_Icon(int x,int y,Color_t color,Color_t Background)
{
   fill_Rectangle(x,y,35,50,8,color);
   Equilateral_Triangle_Right(x+24,y+17,20,Fill_shape,Background);
}
void SEDHOM_Icons::Block_Icon(int x,int y,bool open_or_closed,Color_t color,Color_t Background)
{
  if(!open_or_closed)
  {
    fill_Rectangle(x+21,y-15,30,20,10,color);
     fill_Rectangle(x+21+2,y-15+2,30-4,20-4,10,Background);
     fill_Rectangle(x+26,y,20,26,2,Background);
  }
  else
  {
     fill_Rectangle(x+3,y-15,30,20,10,color);
     fill_Rectangle(x+3+2,y-15+2,30-4,20-4,10,Background);
  }
  fill_Rectangle(x,y,20,26,2,color);
  fill_Circle(x+12,y+6,4,Background);
  fill_Rectangle(x+10,y+9,8,5,2,Background);
}
void SEDHOM_Icons::Signal_Icon(int x,int y,SIGNAL_STATUS_t state,Color_t color_on,Color_t color_off,Color_t Background)
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
     color_one = color_on;
     color_two = color_off;
     color_three = color_off;
     color_four = color_off;
     color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_2)
  {
    color_one = color_on;
    color_two = color_on;
    color_three = color_off;
    color_four = color_off;
    color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_3)
  {
    color_one = color_on;
    color_two = color_on;
    color_three = color_on;
    color_four = color_off;
    color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_4)
  {
    color_one = color_on;
    color_two = color_on;
    color_three = color_on;
    color_four = color_on;
    color_five = color_off;
  }
  else if(state == Signal_Status_Signal_level_5_full)
  {
    color_one = color_on;
    color_two = color_on;
    color_three = color_on;
    color_four = color_on;
    color_five = color_on;
  }
  else return ;

  fill_Rectangle(x,y+20,5,5,0,color_one);
  fill_Rectangle(x+10,y+15,10,5,0,color_two);
  fill_Rectangle(x+20,y+10,15,5,0,color_three);
  fill_Rectangle(x+30,y+5,20,5,0,color_four);
  fill_Rectangle(x+40,y,25,5,0,color_five);
}

void SEDHOM_Icons::Bell_Icon(int x,int y,bool mute_or_not,bool filled_or_not,Color_t color,Color_t Background)
{
   fill_Rectangle(x-3,y+20,5,30-4,4,color);
   fill_Rectangle(x-5,y+23,5,30,4,color);
   fill_Rectangle(x-7,y+26,5,30+4,4,color);
   fill_Rectangle(x,y,30,20,10,color);
   fill_Circle(x+10,y+32,5,color);
   if(filled_or_not)
   {
      fill_Rectangle(x-3+2,y+20+2,5-1,30-4-4,4,Background);
      fill_Rectangle(x-5+2,y+23+2,5-1,30-4,4,Background);
      fill_Rectangle(x-7+2,y+26+2,5-4,30+4-4,4,Background);
      fill_Rectangle(x+2,y+2,30-4,20-4,10,Background);
   }
   if(!mute_or_not)
   {
     draw_Line(x-10,y+3,x+35,y+28,Background);
     draw_Line(x-10,y+4,x+35,y+29,Background);
     draw_Line(x-10,y+5,x+35,y+30,GREEN);
     draw_Line(x-10,y+6,x+35,y+31,GREEN);
     draw_Line(x-10,y+7,x+35,y+32,Background);
     draw_Line(x-10,y+8,x+35,y+33,Background);
   }
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/////////////////////////////////////////////////////////////////////////////
#endif // !SEDHOM_OS_ICONS_AND_WIDGETS_H_