#ifndef SEDHOM_OS_ICONS_H_
#define SEDHOM_OS_ICONS_H_
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
        Color_t Set_Hex_Color(uint16_t Hex_code); 
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
        void Text_cpp(int x,int y,const GFXfont* font,Color_t color,String txt);
        void Container(int x,int y,int h,int w,int raduis,Color_t color);
        void Border_Rectangle(Icon_t Border_Rect,int h,int w,int Raduis,int Border_size);
        void fill_rectangle_with_end(int x,int y,int h,int w,int end_volume,Color_t color,Color_t end_color);
        void Draw_Custom_int_shap(int x,int y,int h,int w,int color,int arr[]);
        void Draw_Custom_Char(int x,int y,int h,int w,int color,char arr[]);
        // effects 
        Color_t Blur(int x,int y,int h,int w,int r,int Blur_value,Color_t mode,bool circle_or_rectangle = 1);
        Color_t Color_Blur(int x,int y,int h,int w,int r,Color_t color,Color_t mode,bool circle_or_rectangle = 1,void (*shadow)(Icon_t shadow_icon, int shadow_h,int shadow_w,int shadow_r,Color_t shadow_color) = nullptr);
        Color_t Shadow_effect(Icon_t shadow , Shapes_t shape = Shape_Rectangle, int shadow_size = 5 , int shadow_h = 120 , int shadow_w = 200 ,int shadow_Raduis = 20 , Position_t pos = Position_Right_and_Bottom, Color_t Shadow_color = Color_DarkGrey);
        // Draw SEDhOM Icons
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
        void label_Icon(Icon_t Icon ,int h,int w,int Border,Color_t color_str_in_label,String string_in_label);
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
        void Warning_Icon( Icon_t Icon,Color_t txt_color,bool filled_or_not = false );
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
// colors
Color_t SEDHOM_Icons::set_Color(int r,int g,int b)
{
   return(Set_Color(r,g,b));
}
Color_t SEDHOM_Icons::Set_Hex_Color(uint16_t Hex_code)
{
    int r = ((Hex_code >> 11) & 0x1F) * 255 / 31; // 5-bit red
    int g = ((Hex_code >> 5) & 0x3F) * 255 / 63;  // 6-bit green
    int b = (Hex_code & 0x1F) * 255 / 31;         // 5-bit blue
    return set_Color(r, g, b);
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
void SEDHOM_Icons::Text_cpp(int x,int y,const GFXfont* font,Color_t color,String txt) 
{
    Text(x,y,font,color,txt);
}
void SEDHOM_Icons::Container(int x,int y,int h,int w,int raduis,Color_t color)
{
    Fill_Rectangle(x, y, h, w, raduis, color);
}
void SEDHOM_Icons::Border_Rectangle(Icon_t Border_Rect,int h,int w,int Raduis,int Border_size)
{
  fill_Rectangle(Border_Rect.x,Border_Rect.y,h,w,Raduis,Border_Rect.color);
  fill_Rectangle(Border_Rect.x+Border_size,Border_Rect.y+Border_size,h-(2*Border_size),w-(2*Border_size),Raduis,Border_Rect.Background);
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
Color_t SEDHOM_Icons::Blur(int x,int y,int h,int w,int r,int Blur_value,Color_t mode,bool circle_or_rectangle)
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
Color_t SEDHOM_Icons::Color_Blur(int x,int y,int h,int w,int r,Color_t color,Color_t mode,bool circle_or_rectangle ,void (*shadow)(Icon_t shadow_icon, int shadow_h,int shadow_w,int shadow_r,Color_t shadow_color) )
{
  // if(shadow != nullptr)
  // {
  //   Shadow_effect({x,y,color,0},h,w,r,color);
  // }
  // else
  // {
  //   shadow({x,y,color,0},h,w,r,shadow_color);
  // }
  
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
Color_t SEDHOM_Icons::Shadow_effect(Icon_t shadow, Shapes_t shape , int shadow_size  , int shadow_h , int shadow_w ,int shadow_Raduis , Position_t pos  , Color_t Shadow_color )
{
    int x = shadow.x;
    int y = shadow.y;
    int h = shadow_h;
    int w = shadow_w;

   switch (pos)
    {
    case Position_Center:
        break;

    case Position_Top:
        y -= shadow_size;
        break;

    case Position_Bottom:
        y += shadow_size;
        break;

    case Position_Right:
        x += shadow_size;
        break;

    case Position_Left:
        x -= shadow_size;
        break;

    case Position_Top_Left:
        x -= shadow_size;
        y -= shadow_size;
        break;

    case Position_Top_Right:
        x += shadow_size;
        y -= shadow_size;
        break;

    case Position_Bottom_Left:
        x -= shadow_size;
        y += shadow_size;
        break;

    case Position_Bottom_Right:
        x += shadow_size;
        y += shadow_size;
        break;

    case Position_Right_and_Left:
        x -= shadow_size;
        w += shadow_size * 2;
        break;

    case Position_Right_and_Top:
        x += shadow_size;
        y -= shadow_size;
        break;

    case Position_Right_and_Bottom:
        x += shadow_size;
        y += shadow_size;
        break;

    case Position_Left_and_Top:
        x -= shadow_size;
        y -= shadow_size;
        break;

    case Position_Left_and_Bottom:
        x -= shadow_size;
        y += shadow_size;
        break;

    case Position_Top_and_Bottom:
        y -= shadow_size;
        h += shadow_size * 2;
        break;

    case Position_All:
        x -= shadow_size;
        y -= shadow_size;
        h += shadow_size * 2;
        w += shadow_size * 2;
        break;
    }
    if (shape == Shape_Circle)
    {
      fill_Circle(x , y , shadow_Raduis, Shadow_color);
    }
    else
    {
      fill_Rectangle(x, y, h, w, shadow_Raduis, Shadow_color);
    }
    return Shadow_color;
}
// icons
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
        Fill_Circle(Icon.x,Icon.y,20,one);
        Fill_Circle(Icon.x,Icon.y,20-3,Icon.Background);
        Fill_Circle(Icon.x,Icon.y,20-6,two);
        Fill_Circle(Icon.x,Icon.y,20-9,Icon.Background);
        Fill_Circle(Icon.x,Icon.y,20-12,three);
        Fill_Circle(Icon.x,Icon.y,20-15,Icon.Background);
        Fill_Rectangle(Icon.x-21,Icon.y,42,20,5,Icon.Background);
        Fill_Triangle(Icon.x-3,Icon.y+5,Icon.x+24,Icon.y+5,Icon.x+21,Icon.y-20,Icon.Background);
        Fill_Triangle(Icon.x+3,Icon.y+5,Icon.x-24,Icon.y+5,Icon.x-21,Icon.y-20,Icon.Background);
        Fill_Circle(Icon.x,Icon.y,20-18,four);
        if(state==WIFI_Status_no_internet)
        {
        Text(Icon.x+8,Icon.y,BigFont,color_off,"!");
        }
    }
    else if(state==WIFI_Status_not_connected)
    {
      Fill_Rectangle(Icon.x-15,Icon.y-27,37,38,5,Icon.Background);
    }
    Fill_Rectangle(Icon.x-10,Icon.y+13,20,10,0,Icon.Background);
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
    Fill_Rectangle(Icon.x, Icon.y, 50,30, 5, color_Battary);
    Fill_Rectangle(Icon.x+3, Icon.y+3, 50-6,30-6, 5, Icon.Background);
    Fill_Rectangle(Icon.x+50-1,Icon.y+10,10,10,0,color_Battary);
    Fill_Rectangle(Icon.x+2,Icon.y+3,rangeB,30-6,5,color_Battary);
    char range_as_str[10];
    sprintf(range_as_str, "%d", range);
    Text(txt_x+60,txt_y_index,BigFont,txt_color,range_as_str);
    Text_Add("%");
}
void SEDHOM_Icons::Home_Icon(Icon_t Icon)
{
    
    Fill_Triangle(Icon.x+30,Icon.y,(Icon.x+30)+25,Icon.y+15,(Icon.x+30)-25,Icon.y+15,Icon.color);
    Fill_Rectangle(Icon.x+10, Icon.y+12,40,25,5,Icon.color);
    Fill_Rectangle(Icon.x+23, Icon.y+20,15,20,5,Icon.Background);
}
void SEDHOM_Icons::Setting_Icon(Icon_t Icon)
{
    Fill_Circle(Icon.x-10, Icon.y,10, Icon.color);
    Fill_Circle(Icon.x-10, Icon.y-10, 3, Icon.color);
    Fill_Circle(Icon.x-10, Icon.y+10, 3, Icon.color);
    Fill_Circle(Icon.x, Icon.y-5, 3, Icon.color);
    Fill_Circle(Icon.x, Icon.y+5, 3, Icon.color);
    Fill_Circle(Icon.x-20, Icon.y-5, 3, Icon.color);
    Fill_Circle(Icon.x-20, Icon.y+5, 3, Icon.color);

    Fill_Circle(Icon.x-10, Icon.y, 5, Icon.Background);
}
void SEDHOM_Icons::Add_Icon(Icon_t Icon)
{
    Fill_Rectangle(Icon.x+15,Icon.y-2+15,30,5,5,Icon.color);
    Fill_Rectangle(Icon.x+13+15,Icon.y-14+15,5,30,5,Icon.color);
}
void SEDHOM_Icons::SD_Card_Icon(Icon_t Icon)
{
    Fill_Rectangle(Icon.x-5, Icon.y-5,40,45,5,WHITE);
    Fill_Rectangle(Icon.x, Icon.y,30,35,5,BLACK);
    Fill_Rectangle(Icon.x+15,Icon.y,17,8,5,WHITE);
    Fill_Triangle(Icon.x+30,Icon.y+8,Icon.x+17,Icon.y+8,Icon.x+17,Icon.y,BLACK);
    Fill_Rectangle(Icon.x+4,Icon.y+20,2,10,5,YELLOW);
    Fill_Rectangle(Icon.x+11,Icon.y+20,2,10,5,YELLOW);
    Fill_Rectangle(Icon.x+18,Icon.y+20,2,10,5,YELLOW);
    Fill_Rectangle(Icon.x+25,Icon.y+20,2,10,5,YELLOW);
    Fill_Rectangle(Icon.x+12,Icon.y+1,5,8,0,BLACK);
}
void SEDHOM_Icons::Control_Icon(Icon_t Icon)
{
    Fill_Rectangle(Icon.x, Icon.y,40,3,5, Icon.color);
    Fill_Rectangle(Icon.x,Icon.y+15,40,3,5,Icon.color);
    Fill_Rectangle(Icon.x,Icon.y+30,40,3,5,Icon.color);
    Fill_Circle(Icon.x+28,Icon.y+1,6,Icon.color);
    Fill_Circle(Icon.x+12,Icon.y+16,6,Icon.color);
    Fill_Circle(Icon.x+31-2,Icon.y+30+1,6,Icon.color);
    Fill_Circle(Icon.x+28,Icon.y+1,3,Icon.Background);
    Fill_Circle(Icon.x+12,Icon.y+16,3,Icon.Background);
    Fill_Circle(Icon.x+29,Icon.y+31,3,Icon.Background);
}
void SEDHOM_Icons::Sensor_Icon(Icon_t Icon)
{
    Fill_Rectangle(Icon.x+3,Icon.y,30,10,5,Icon.color);
    Fill_Circle(Icon.x+18, Icon.y+10,5,Icon.color);
    Draw_Line(Icon.x+12,Icon.y+17,Icon.x+6,Icon.y+25,Icon.color);
    Draw_Line(Icon.x+23,Icon.y+17,Icon.x+30,Icon.y+25,Icon.color);
    Draw_Line(Icon.x+18,Icon.y+17,Icon.x+18,Icon.y+25,Icon.color);
}
void SEDHOM_Icons::Power_off_Icon(Icon_t Icon)
{
    Fill_Circle(Icon.x,Icon.y,20,Icon.color);
    Fill_Circle(Icon.x,Icon.y,17,Icon.Background);
    Fill_Rectangle(Icon.x-8, Icon.y-20,16,20, 0,Icon.Background);
    Fill_Rectangle(Icon.x-1, Icon.y-23,2,23,0,Icon.color);
}
void SEDHOM_Icons::Bluetooth_Icon(Icon_t Icon,BLUETOOTH_STATUS_t connect_status)
{
 if(connect_status == BLuetooth_Status_open_and_not_connected || connect_status == BLuetooth_Status_open_and_connected )
 {
    Fill_Triangle( (Icon.x) , (Icon.y) , (Icon.x+15) , (Icon.y+10) , (Icon.x) , (Icon.y+20) , Icon.color);
    Fill_Triangle( (Icon.x) , (Icon.y)+15 , (Icon.x+15) , (Icon.y+10)+15 , (Icon.x) , (Icon.y+20)+15 , Icon.color);
    Fill_Triangle( (Icon.x-15) , (Icon.y+5) , (Icon.x) , (Icon.y+16) , (Icon.x-15) , (Icon.y+30) , Icon.color);
    Fill_Triangle( (Icon.x-15)+2 , (Icon.y+5)+3 , (Icon.x)-2 , (Icon.y+16) , (Icon.x-15)+2 , (Icon.y+30)-3 , Icon.Background);
    Fill_Triangle( (Icon.x)+2 , (Icon.y)+3 , (Icon.x+15)-2 , (Icon.y+10) , (Icon.x)+2 , (Icon.y+20)-4 , Icon.Background);
    Fill_Triangle( ((Icon.x))+2 , ((Icon.y)+15)+3 , ((Icon.x+15))-2 , ((Icon.y)+15)+10 , ((Icon.x))+2 , ((Icon.y+20)+15)-3 , Icon.Background);
    Fill_Rectangle(Icon.x-18, Icon.y+2,6,30,0, Icon.Background);
    if(connect_status == BLuetooth_Status_open_and_connected)
    {
        Fill_Circle(Icon.x-10, Icon.y+17, 1, Icon.color);
        Fill_Circle(Icon.x+13, Icon.y+18, 1, Icon.color);
    }
 }
 else
 {
    Fill_Rectangle(Icon.x-20, Icon.y-10,42,50,0, Icon.Background);
 }
}
void SEDHOM_Icons::Button_Icon(Icon_t Icon,bool print_on_and_off)
{
    Fill_Rectangle(Icon.x,Icon.y,50,20 ,30,GREEN);
    Fill_Circle(Icon.x+39,Icon.y+10,7,WHITE);
    Fill_Rectangle(Icon.x,Icon.y+25,50,20,30,RED);
    Fill_Circle(Icon.x+10,Icon.y+35,7,WHITE);

    if(print_on_and_off)
    {
         Text(Icon.x+8, Icon.y+16,SmallFont,WHITE,"ON");
         Text(Icon.x+23, Icon.y+41,SmallFont,WHITE,"OFF");
    }
}
void SEDHOM_Icons::Display_Time_Icon(Icon_t Icon,Time_t time)
{
    char Hour_as_str[3];
    char min_as_str[3];
    char sec_as_str[3];
    sprintf(Hour_as_str,"%d",time.hour);
    sprintf(min_as_str,"%d",time.minut);
    sprintf(sec_as_str,"%d",time.sec);
    //hour
    if(time.hour < 10)
    {
       Text(Icon.x,Icon.y+35,FONT_SEVENSEGMENT,Icon.color,"0");
       Text_Add(Hour_as_str);       
    }
    else
    {
       Text(Icon.x,Icon.y+35,FONT_SEVENSEGMENT,Icon.color,Hour_as_str);
    }
    // minutes
    if(time.minut < 10)
    {
       Text(Icon.x+83,Icon.y+35,FONT_SEVENSEGMENT,Icon.color,"0");
       Text_Add(min_as_str);       
    }
    else
    {
       Text(Icon.x+83,Icon.y+35,FONT_SEVENSEGMENT,Icon.color,min_as_str);
    }
    // seprator
    Fill_Circle(Icon.x+73,Icon.y,5,Icon.color);
    Fill_Circle(Icon.x+73,Icon.y+20,5,Icon.color);
    //sec
    Text(Icon.x+146,Icon.y,BigFont,Icon.color,sec_as_str);
    // time name
    Text(Icon.x+146,Icon.y+38,BigFont,Icon.color,time.time_name);
}
void SEDHOM_Icons::Terminal_Icon(Icon_t Icon)
{
    Fill_Rectangle(Icon.x,Icon.y,50,50,5,WHITE);
    Fill_Rectangle(Icon.x+3,Icon.y+3,44,44,5,BLACK);
    Text(Icon.x+10,Icon.y+30,BigFont,GREEN,">_");
}
void SEDHOM_Icons::About_Icon(Icon_t Icon)
{
    Fill_Circle(Icon.x,Icon.y,20,Icon.color);
    Fill_Circle(Icon.x,Icon.y,17,Icon.Background);
    Text(Icon.x-6,Icon.y+8,BigFont,Icon.color,"!");
}
void SEDHOM_Icons::Display_Date_Icon(Icon_t Icon,Date_t Date,Color_t text_color)
{
    char year_as_str[5];
    char Day_as_str[5];
    sprintf(year_as_str,"%d",Date.year);
    sprintf(Day_as_str,"%d",Date.Day);
    Fill_Rectangle(Icon.x,Icon.y,130,130,15,Icon.color);
    Text_cpp(Icon.x+42,Icon.y+40,BigFont,text_color,Date.week_day_name);
    Text(Icon.x+47,Icon.y+65,BigFont,text_color,Day_as_str);
    Text_cpp(Icon.x+42,Icon.y+90,BigFont,text_color,Date.month_name);
    Text(Icon.x+35,Icon.y+115,BigFont,text_color,year_as_str);

    int x_start = Icon.x + 15;
    int y_start = Icon.y;
    int x_end_start = Icon.x + 10;
    int y_end_start = Icon.y + 8;

    for (int offset_block = 0; offset_block <= 100; offset_block += 20) // 0, 20, 40, 60, 80, 100
    {
        for (int i = 0; i <= 4; i++) // 0,1,2,3,4
        {
            Draw_Line(x_start + i + offset_block, y_start, x_end_start + i + offset_block, y_end_start,Icon.Background);
        }
    }


    Fill_Circle(Icon.x+114-100,Icon.y+8,4,Icon.Background);
    Fill_Circle(Icon.x+114-80,Icon.y+8,4,Icon.Background);
    Fill_Circle(Icon.x+114-60,Icon.y+8,4,Icon.Background);
    Fill_Circle(Icon.x+114-40,Icon.y+8,4,Icon.Background);
    Fill_Circle(Icon.x+114-20,Icon.y+8,4,Icon.Background);
    Fill_Circle(Icon.x+114,Icon.y+8,4,Icon.Background);

}
void SEDHOM_Icons::UP_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Fill_Triangle(Icon.x-20-6,Icon.y+25+3,Icon.x,Icon.y-6,Icon.x+20+6,Icon.y+25+3,border_color);
  Fill_Triangle(Icon.x-20,Icon.y+25,Icon.x,Icon.y,Icon.x+20,Icon.y+25,Icon.color);
  fill_rectangle_with_end(Icon.x-10,Icon.y+25,20,20,3,Icon.color,border_color);
  Fill_Rectangle(Icon.x-10+3,Icon.y+25,20-6,20-3,0,Icon.color);
}
void SEDHOM_Icons::DOWN_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Fill_Triangle(Icon.x-20-6,Icon.y+25-3,Icon.x,Icon.y-6+60,Icon.x+20+6,Icon.y+25-3,border_color);
  Fill_Triangle(Icon.x-20,Icon.y+25,Icon.x,Icon.y+50,Icon.x+20,Icon.y+25,Icon.color);
  fill_rectangle_with_end(Icon.x-10,Icon.y+5,20,20,3,Icon.color,border_color);
  Fill_Rectangle(Icon.x-10+3,Icon.y+8,20-6,20-3,0,Icon.color);
}
void SEDHOM_Icons::LEFT_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Fill_Triangle(Icon.x-6,Icon.y,Icon.x+25+3,Icon.y-25-6,Icon.x+25+3,Icon.y+25+6,border_color);
  Fill_Triangle(Icon.x,Icon.y,Icon.x+25,Icon.y-25,Icon.x+25,Icon.y+25,Icon.color);
  fill_rectangle_with_end(Icon.x+25,Icon.y-8-1,20,20,3,Icon.color,border_color);
  Fill_Rectangle(Icon.x+25,Icon.y-8+3-1,20-3,20-6,0,Icon.color);
}
void SEDHOM_Icons::RIGHT_Aroow_Icon(Icon_t Icon,Color_t border_color)
{
  Fill_Triangle(Icon.x+6+50,Icon.y,Icon.x+25-3,Icon.y-25-6,Icon.x+25-3,Icon.y+25+6,border_color);
  Fill_Triangle(Icon.x+50,Icon.y,Icon.x+25,Icon.y-25,Icon.x+25,Icon.y+25,Icon.color);
  fill_rectangle_with_end(Icon.x+5,Icon.y-8-1,20,20,3,Icon.color,border_color);
  Fill_Rectangle(Icon.x+8,Icon.y-8+3-1,20-3,20-6,0,Icon.color);
}
void SEDHOM_Icons::Back_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Fill_Triangle(Icon.x-6,Icon.y,Icon.x+25+3,Icon.y-15-6,Icon.x+25+3,Icon.y+15+6,border_color);
  Fill_Triangle(Icon.x,Icon.y,Icon.x+25,Icon.y-15,Icon.x+25,Icon.y+15,Icon.color);
  fill_rectangle_with_end(Icon.x+25,Icon.y-8-1,25,18,3,Icon.color,border_color);
  Fill_Rectangle(Icon.x+22,Icon.y-8+3-1,12,12,5,Icon.color);
}
void SEDHOM_Icons::After_Arrow_Icon(Icon_t Icon,Color_t border_color)
{
  Fill_Triangle(Icon.x+6+50,Icon.y,Icon.x+25-3,Icon.y-15-6,Icon.x+25-3,Icon.y+15+6,border_color);
  Fill_Triangle(Icon.x+50,Icon.y,Icon.x+25,Icon.y-15,Icon.x+25,Icon.y+15,Icon.color);
  fill_rectangle_with_end(Icon.x,Icon.y-8-1,25,18,3,Icon.color,border_color);
  fill_Rectangle(Icon.x+15,Icon.y-8+3-1,12,13,5,Icon.color);
}
void SEDHOM_Icons::Color_Icon(Icon_t Icon)
{
    Fill_Rectangle(Icon.x,Icon.y,30,30,5,MAGENTA);
    Fill_Rectangle(Icon.x+5,Icon.y+5,30,30,5,RED);
    Fill_Rectangle(Icon.x+10,Icon.y+10,30,30,5,BLUE);
    Fill_Rectangle(Icon.x+15,Icon.y+15,30,30,5,GREEN);
}
void SEDHOM_Icons::Time_Icon(Icon_t Icon)
{
    Fill_Circle(Icon.x,Icon.y,20,Icon.color);
    Fill_Circle(Icon.x,Icon.y,17,Icon.Background);
    Fill_Rectangle(Icon.x-2,Icon.y-14,3,12,5,Icon.color);
    Fill_Rectangle(Icon.x,Icon.y-1,10,3,5,Icon.color);
    Fill_Circle(Icon.x,Icon.y,4,Icon.color);
}
void SEDHOM_Icons::Date_Icon(Icon_t Icon)
{
    Fill_Rectangle(Icon.x,Icon.y,45,48,5,Icon.color);
    Fill_Rectangle(Icon.x+2,Icon.y+10,41,36,5,Icon.Background);
    Fill_Circle(Icon.x+5,Icon.y+5,3,Icon.Background);
    Fill_Circle(Icon.x+23,Icon.y+5,3,Icon.Background);
    Fill_Circle(Icon.x+40,Icon.y+5,3,Icon.Background);
    Text(Icon.x+20,Icon.y+24,SmallFont,Icon.color,"6");
    Text(Icon.x+12,Icon.y+33,SmallFont,Icon.color,"Jun");
    Text(Icon.x+9,Icon.y+46,SmallFont,Icon.color,"2025");
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
    Fill_Rectangle(Icon.x,Icon.y,100,40,50,State_color);
    Fill_Circle(index,Icon.y+20,15,thumb_color);//not mode
    Text_cpp((index_str),Icon.y+28,BigFont,txt_color,state_str);//mode
}
void SEDHOM_Icons::label_Icon(Icon_t Icon ,int h,int w,int Border,Color_t color_str_in_label,String string_in_label)
{
    Color_t label_color_in_func = Icon.color;
    float num = 1;

    if(string_in_label == "OFF" || string_in_label == "off" || num == 0){label_color_in_func = RED;}
    else if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = Icon.color;}
    if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = Icon.color;}

    Border_Rectangle({Icon.x,Icon.y,label_color_in_func,Icon.Background},h,w,5,Border);
    Text_cpp(Icon.x+10,Icon.y+(0.6*w),SmallFont,color_str_in_label,string_in_label);
}
void SEDHOM_Icons::slider_Icon(Icon_t Icon ,int h,byte_t range ,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color)
{
    long index = map(range,0,100,0,h);
    char range_str[5];
    sprintf(range_str,"%d",range);

    Fill_Rectangle(Icon.x,Icon.y,h,10,5,color_not_active);
    Fill_Rectangle(Icon.x,Icon.y,index,10,5,Icon.color);
    Fill_Circle(Icon.x+index,Icon.y+5,10,Not_Mode());
    fill_rectangle_with_end(Icon.x+h+15,Icon.y-10,40,30,3,Mode(),box_color);
    Text(Icon.x+h+8+15,Icon.y+19-8,SmallFont,range_in_box_color,range_str);
}
void SEDHOM_Icons::file_Icon(Icon_t Icon,Color_t Border_color,Color_t file_extend_color,String file_extend)
{
    fill_rectangle_with_end(Icon.x,Icon.y,50,60,3,Icon.Background,Border_color);
    fill_rectangle_with_end(Icon.x-10,Icon.y+30,30,20,3,Icon.color,Border_color);
    fill_rectangle_with_end(Icon.x+29,Icon.y-1,30,21,3,Icon.Background,Icon.Background);
    Fill_Triangle(Icon.x+6+43,Icon.y+20,Icon.x+29,Icon.y,Icon.x+29,Icon.y+20,Border_color);
    Fill_Triangle(Icon.x+43,Icon.y+18,Icon.x+29+3,Icon.y+6,Icon.x+29+3,Icon.y+18,Icon.color);
    Fill_Rectangle(Icon.x+10,Icon.y+15,15,2,5,Border_color);
    Fill_Rectangle(Icon.x+10,Icon.y+25,30,2,5,Border_color);    
    Fill_Rectangle(Icon.x+25,Icon.y+35,15,2,5,Border_color);
    Fill_Rectangle(Icon.x+25,Icon.y+45,15,2,5,Border_color);
    Text(Icon.x-5,Icon.y+46,SmallFont,file_extend_color,file_extend);
}
void SEDHOM_Icons::folder_Icon(Icon_t Icon)
{
    Fill_Rectangle(Icon.x,Icon.y,30,40,5,Icon.color);
    Fill_Rectangle(Icon.x+28,Icon.y+5,40,20,5,Icon.color);
    fill_rectangle_with_end(Icon.x+5,Icon.y+10,60,20,1,WHITE,BLACK);
    Fill_Rectangle(Icon.x,Icon.y+20,68,35,5,Icon.color);
    Fill_Rectangle(Icon.x,Icon.y+20,69,1,0,BLACK);
}
void SEDHOM_Icons::Divider_vertical(Icon_t Icon,int length,int thikness)
{
    Fill_Rectangle(Icon.x,Icon.y,length,thikness,1,Icon.color);
}
void SEDHOM_Icons::Divider_Horezontal(Icon_t Icon ,int length , int thikness)
{
    Fill_Rectangle(Icon.x,Icon.y,thikness,length,1,Icon.color);
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
    Text(((User.is_professser)?x1+60:x1+80),y1+20,BigFont,main_font_color,((User.is_professser)?"PROFESSER":"STUDENT"));
    Divider_vertical({x1+10,y1+35,main_font_color,Icon.Background},h1-20,3);
    Text(x1+30,y1+55,SmallFont,font_color,"IDENTITY CARD");

    Text(x1+10,y1+70,SmallFont,main_font_color,((User.is_professser)?"Dr Name":"Nmae"));
    Text(x1+10,y1+85,SmallFont,font_color,User.user_name);

    Text(x1+10,y1+100,SmallFont,main_font_color,((User.is_professser)?"Unversity":"Stadies at"));
    Text(x1+10,y1+115,SmallFont,font_color,User.universty);

    Text(x1+10,y1+130,SmallFont,main_font_color,"Department");
    Text(x1+10,y1+145,SmallFont,font_color,User.department_1);
    Text(x1+10,y1+160,SmallFont,font_color,User.department_2);

    Text(x1+10,y1+175,SmallFont,main_font_color,"Born");
    Text(x1+10,y1+190,SmallFont,font_color,User.Born);

    Container(x1+160,y1+45,100,110,0,User.image_background);
    
    if(User.default_image)
    {
        Fill_Circle(x1+210,y1+160,40,DARKGREY);
        Fill_Circle(x1+210,y1+100,25,DARKGREY);
        if(User.eye)
        {
            Fill_Circle(x1+220,y1+97,7,BLACK);
            Fill_Circle(x1+220,y1+97,5,DARKGREY);
            Fill_Circle(x1+220,y1+97,1,BLACK);//eye
            Divider_vertical({x1+205,y1+97,Black,Icon.Background},10,2);
            Fill_Circle(x1+200,y1+97,7,BLACK);
            Fill_Circle(x1+200,y1+97,5,DARKGREY);
            Fill_Circle(x1+200,y1+97,1,BLACK);//eye
            Divider_vertical({x1+225,y1+97,Black,Icon.Background},10,2);
            Divider_vertical({x1+185,y1+97,Black,Icon.Background},10,2);
        }
    }
    Fill_Rectangle(x1+150,y1+155,120,45,15,Icon.color);
    Text(x1+157,y1+175,SmallFont,font_color,User.number);
}
void SEDHOM_Icons::Joy_Stick_Icon(Icon_t Icon ,Coordenate_t thumb ,int thumb_size,Color_t Border_color,Color_t thumb_color,Color_t Color_insde_arrow)
{
  fill_Circle(Icon.x,Icon.y,50,Border_color);
  fill_Circle(Icon.x,Icon.y,50-3,Icon.color);
  Equilateral_Triangle_Up(Icon.x,Icon.y-35,10,Fill_shape,Color_insde_arrow);
  Equilateral_Triangle_Down(Icon.x,Icon.y+35,10,Fill_shape,Color_insde_arrow);
  Equilateral_Triangle_Right(Icon.x+35,Icon.y,10,Fill_shape,Color_insde_arrow);
  Equilateral_Triangle_Left(Icon.x-35,Icon.y,10,Fill_shape,Color_insde_arrow);
  int dx = thumb.x - Icon.x;
  int dy = thumb.y - Icon.y;
  if ((dx*dx + dy*dy) <= (50/2)*(50/2))
  {
      fill_Circle(thumb.x, thumb.y, thumb_size, thumb_color);
  }
}
void SEDHOM_Icons::Temperature_Meter_Icon(Icon_t Icon,Color_t Border,int value,bool show_val_dashes)
{
  Color_t color_dash =RED;
  value = constrain(value, 0, 100);
  fill_Circle(Icon.x+50/2,Icon.y+150+25,50,Border);
  fill_Rectangle(Icon.x,Icon.y,150,50,5,Border);
  fill_Rectangle(Icon.x+5,Icon.y+5,150,50-10,5,Icon.Background);
  fill_Circle(Icon.x+50/2,Icon.y+150+25,50-5,Icon.Background);
  fill_Circle(Icon.x+50/2,Icon.y+150+25,50-13,Icon.color);
  int levelHeight = map(value, 0, 100, 0, 140);
  fill_Rectangle(Icon.x+12,Icon.y + 150 - levelHeight,levelHeight,50-24,5,Icon.color);
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
   fill_Circle(Icon.x,Icon.y,5,Icon.color);
   fill_Circle(Icon.x,Icon.y,5-2,Icon.Background);
   fill_Circle(Icon.x+20,Icon.y,5,Icon.color);
   fill_Circle(Icon.x+20,Icon.y,5-2,Icon.Background);
   fill_Rectangle(Icon.x+4,Icon.y-20,20,2,0,Icon.color);
   fill_Rectangle(Icon.x+4+20,Icon.y-20,20,2,0,Icon.color);
   fill_Rectangle(Icon.x+4,Icon.y-20,2,20,0,Icon.color);
   if(is_muted_or_not)
   {   
     draw_Line(Icon.x-5,Icon.y-20,Icon.x+32,Icon.y-5,Icon.color);    
     draw_Line(Icon.x-5,Icon.y-20+1,Icon.x+32,Icon.y-5+1,Icon.color);    
   }
}
void SEDHOM_Icons::Sound_value_Icon(Icon_t Icon,int value,Color_t thikness_color,bool thikness_or_not)
{
  int val = value;
  value = constrain(value,0,100);
  value = map(value,0,100,150,0);
  fill_Rectangle(Icon.x,Icon.y,150,50,40,thikness_or_not?thikness_color:Icon.color);
  fill_Rectangle(Icon.x+5,Icon.y+5,150-10,50-10,40,Icon.Background);
  fill_Rectangle(Icon.x+5,(Icon.y+value+5),((val<15)?(0):(150-value-10)),50-10,40,Icon.color);
  Tone_Icon({Icon.x+12,Icon.y+130,(val<20)?Icon.color:Icon.Background,(val<20)?Icon.Background:Icon.color},(val==0)?true:false);
}
void SEDHOM_Icons::Video_Icon(Icon_t Icon)
{
   fill_Rectangle(Icon.x,Icon.y,35,50,8,Icon.color);
   Equilateral_Triangle_Right(Icon.x+24,Icon.y+17,20,Fill_shape,Icon.Background);
}
void SEDHOM_Icons::Block_Icon(Icon_t Icon,bool open_or_closed)
{
  if(!open_or_closed)
  {
    fill_Rectangle(Icon.x+21,Icon.y-15,30,20,10,Icon.color);
     fill_Rectangle(Icon.x+21+2,Icon.y-15+2,30-4,20-4,10,Icon.Background);
     fill_Rectangle(Icon.x+26,Icon.y,20,26,2,Icon.Background);
  }
  else
  {
     fill_Rectangle(Icon.x+3,Icon.y-15,30,20,10,Icon.color);
     fill_Rectangle(Icon.x+3+2,Icon.y-15+2,30-4,20-4,10,Icon.Background);
  }
  fill_Rectangle(Icon.x,Icon.y,20,26,2,Icon.color);
  fill_Circle(Icon.x+12,Icon.y+6,4,Icon.Background);
  fill_Rectangle(Icon.x+10,Icon.y+9,8,5,2,Icon.Background);
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

  fill_Rectangle(Icon.x,Icon.y+20,5,5,0,color_one);
  fill_Rectangle(Icon.x+10,Icon.y+15,10,5,0,color_two);
  fill_Rectangle(Icon.x+20,Icon.y+10,15,5,0,color_three);
  fill_Rectangle(Icon.x+30,Icon.y+5,20,5,0,color_four);
  fill_Rectangle(Icon.x+40,Icon.y,25,5,0,color_five);
}
void SEDHOM_Icons::Bell_Icon(Icon_t Icon,bool mute_or_not,bool filled_or_not)
{
   fill_Rectangle(Icon.x-3,Icon.y+20,5,30-4,4,Icon.color);
   fill_Rectangle(Icon.x-5,Icon.y+23,5,30,4,Icon.color);
   fill_Rectangle(Icon.x-7,Icon.y+26,5,30+4,4,Icon.color);
   fill_Rectangle(Icon.x,Icon.y,30,20,10,Icon.color);
   fill_Circle(Icon.x+10,Icon.y+32,5,Icon.color);
   if(!filled_or_not)
   {
      fill_Rectangle(Icon.x-3+2,Icon.y+20+2,5-1,30-4-4,4,Icon.Background);
      fill_Rectangle(Icon.x-5+2,Icon.y+23+2,5-1,30-4,4,Icon.Background);
      fill_Rectangle(Icon.x-7+2,Icon.y+26+2,5-4,30+4-4,4,Icon.Background);
      fill_Rectangle(Icon.x+2,Icon.y+2,30-4,20-4,10,Icon.Background);
   }
   if(mute_or_not)
   {
     draw_Line(Icon.x-10,Icon.y+3,Icon.x+35,Icon.y+28,Icon.Background);
     draw_Line(Icon.x-10,Icon.y+4,Icon.x+35,Icon.y+29,Icon.Background);
     draw_Line(Icon.x-10,Icon.y+5,Icon.x+35,Icon.y+30,Icon.color);
     draw_Line(Icon.x-10,Icon.y+6,Icon.x+35,Icon.y+31,Icon.color);
     draw_Line(Icon.x-10,Icon.y+7,Icon.x+35,Icon.y+32,Icon.Background);
     draw_Line(Icon.x-10,Icon.y+8,Icon.x+35,Icon.y+33,Icon.Background);
   }
}
void SEDHOM_Icons::Menu_Icon_1(Icon_t Icon) // : : :
{
  for(int j=0;j<3;j++)
  {
    for(int i=0;i<3;i++)
    {
     fill_Circle(Icon.x+(j*10),Icon.y+(i*10),3,Icon.color);
    }
  }
}
void SEDHOM_Icons::Menu_Icon_2(Icon_t Icon) // ...
{
 for(int i=0;i<3;i++)
  {
    fill_Circle(Icon.x+(i*10),Icon.y,3,Icon.color);
  }
}
void SEDHOM_Icons::Menu_Icon_3(Icon_t Icon) // :
{
 for(int i=0;i<3;i++)
  {
    fill_Circle(Icon.x,Icon.y+(i*10),3,Icon.color);
  }
}
void SEDHOM_Icons::Menu_Icon_4(Icon_t Icon) // : :
{
  for(int j=0;j<2;j++)
  {
    for(int i=0;i<2;i++)
    {
     fill_Circle(Icon.x+(j*20),Icon.y+(i*20),3,Icon.color);
    }
  }
}
void SEDHOM_Icons::Menu_Icon_5(Icon_t Icon) // =
{
  for(int j=0;j<3;j++)
  {
    Fill_Rectangle(Icon.x,Icon.y+(j*10),30,5,5,Icon.color);
  }
}
void SEDHOM_Icons::Moon_Icon(Icon_t Icon)
{
   fill_Circle(Icon.x, Icon.y,20,Icon.color);
   fill_Circle(Icon.x+10,Icon.y-10,20,Icon.Background);
}
void SEDHOM_Icons::Sun_Icon(Icon_t Icon)
{
  // master circle
   fill_Circle(Icon.x, Icon.y,15,Icon.color);
   // small circles
   fill_Circle(Icon.x-25,Icon.y,3,Icon.color);
   fill_Circle(Icon.x+25,Icon.y,3,Icon.color);
   fill_Circle(Icon.x,Icon.y-25,3,Icon.color);
   fill_Circle(Icon.x,Icon.y+25,3,Icon.color);
   fill_Circle(Icon.x+20,Icon.y+20,3,Icon.color);
   fill_Circle(Icon.x-20,Icon.y-20,3,Icon.color);
   fill_Circle(Icon.x+20,Icon.y-20,3,Icon.color);
   fill_Circle(Icon.x-20,Icon.y+20,3,Icon.color);
}
void SEDHOM_Icons::Check_Box_Icon(Icon_t Icon,bool status,Color_t check_color,Color_t checked_fill_color)
{
  fill_Rectangle(Icon.x,Icon.y,40,40,5,Icon.color);
  fill_Rectangle(Icon.x+3,Icon.y+3,40-6,40-6,5,status ? checked_fill_color : Icon.Background);
  if(status)
  {
      for(int i=-1; i<=3; i++) 
      {
          draw_Line(Icon.x+7, Icon.y+25+i, Icon.x+15, Icon.y+30+i, (i<=2 && i>=-1) ? check_color : Icon.Background);
      }
      for(int i=-3; i<=3; i++) 
      {
          draw_Line(Icon.x+15, Icon.y+30+i, Icon.x+30, Icon.y+10+i, (i<=2 && i>=-2) ? check_color : Icon.Background);
      }
  }

}
void SEDHOM_Icons::Radio_Button_Icon(Icon_t Icon,bool status,Color_t check_color)
{
  // border
   fill_Circle(Icon.x,Icon.y,15,Icon.color);
   fill_Circle(Icon.x,Icon.y,12,Icon.Background);
   // status
  if(status) fill_Circle(Icon.x,Icon.y,5,check_color);
}
void SEDHOM_Icons::Text_Feild_Icon( Icon_t Icon,Text_t text ,int lenght,int max_char)
{
   fill_Rectangle(Icon.x,Icon.y,40,lenght,20,Icon.color);
   fill_Rectangle(Icon.x+3,Icon.y+3,40-6,lenght-6,20,Icon.Background);
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
void SEDHOM_Icons::Warning_Icon( Icon_t Icon,Color_t txt_color,bool filled_or_not )
{
  Equilateral_Triangle_Up(Icon.x,Icon.y,40,filled_or_not,Icon.color);
  Text_cpp(Icon.x-6,Icon.y+5,BigFont,txt_color,"!");
}
void SEDHOM_Icons::Chandelier_Icon(Icon_t Icon)
{
   fill_Circle(Icon.x,Icon.y,20,Icon.color);
   fill_Circle(Icon.x,Icon.y,20-3,Icon.Background);
   fill_Rectangle(Icon.x-23,Icon.y,25,46,0,Icon.Background);
   fill_Circle(Icon.x,Icon.y+2,8,Icon.color);
   fill_Circle(Icon.x,Icon.y+2,5,Icon.Background);
   fill_Rectangle(Icon.x-10,Icon.y-10,10,20,0,Icon.Background);
   fill_Rectangle(Icon.x-21,Icon.y,3,43,0,Icon.color);
   fill_Rectangle(Icon.x-1,Icon.y-33,15,3,2,Icon.color);
}
void SEDHOM_Icons::Smart_TV_Icon(Icon_t Icon,Color_t WIFI_icon)
{
  fill_Rectangle(Icon.x,Icon.y,50,60,7,Icon.color);
  fill_Rectangle(Icon.x+3,Icon.y+3,50-6,60-6,7,Icon.Background);
  WIFI_Icon({Icon.x+30,Icon.y+33,WIFI_icon,Icon.Background},WIFI_Status_conected_level_4_full,WIFI_icon);
  fill_Rectangle(Icon.x+8,Icon.y+50-3,3,50-6,5,Icon.color);
  fill_Rectangle(Icon.x+22,Icon.y+50-3,10,15,0,Icon.color);
  fill_Rectangle(Icon.x+10,Icon.y+50-3+10,5,40,5,Icon.color);
}
void SEDHOM_Icons::Air_Conditioner_Icon(Icon_t Icon)
{
  Border_Rectangle(Icon,40,80,10,3);
  fill_Rectangle(Icon.x+50,Icon.y+8,5,20,5,Icon.color);
  Border_Rectangle({ .x = Icon.x +15 , .y = Icon.y +25 , .color = Icon.color , .Background = Icon.Background},20,50,10,3);
  fill_Rectangle(Icon.x+12,Icon.y+37,3,53,5,Icon.color);
  fill_Rectangle(Icon.x+12,Icon.y+40,8,55,5,Icon.Background);
}




//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/////////////////////////////////////////////////////////////////////////////
#endif // !SEDHOM_OS_ICONS_H_