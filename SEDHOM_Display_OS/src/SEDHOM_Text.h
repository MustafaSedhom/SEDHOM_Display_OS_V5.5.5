#ifndef SEDHOM_Text_H_
#define SEDHOM_Text_H_
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Display_Fonts.h"
#include "SEDHOM_Arabic_Font.h"
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Colors.h"
#include "SEDHOM_GUI_Core.h"
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
// class SEDHOM_Text : private virtual SEDHOM_GUI_Core
class SEDHOM_Text : private virtual SEDHOM_GUI_Core
{
    private:
    
    public:
        // Text
        void static __Text_init_OS();
        void Text_C(Coordinate_t coordinate,const GFXfont* font,Color_t color,const char* txt);
        void Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,String str);
        void Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,float value);
        void Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,int value);
        void Text(Coordinate_t coordinate,Text_Data_t str);
        void Text_OverFlow(Coordinate_t coordinate,const GFXfont* font,Color_t color,String txt,int number_overFlow=10,string_t overFlow_chars="...");
};
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
// Text_C
void SEDHOM_Text::Text_C(Coordinate_t coordinate, const GFXfont* font, Color_t color, const char* txt) 
{
    if (txt == nullptr) return;
    setCursor(coordinate.x, coordinate.y);
    setTextColor(color);
    Adafruit_GFX::setFont(font);
    setTextWrap(false);
    uint16_t len = strlen(txt);
    for (uint16_t i = 0; i < len; i++) 
    {
        write(txt[i]);
    }
}

void SEDHOM_Text::Text(Coordinate_t coordinate, const GFXfont* font, Color_t color, String str) 
{
    setCursor(coordinate.x, coordinate.y);
    setTextColor(color);
    Adafruit_GFX::setFont(font);
    setTextWrap(false);
    for (uint16_t i = 0; i < str.length(); i++) 
    {
        write(str[i]);
    }
}
void SEDHOM_Text::__Text_init_OS()
{
    SEDHOM_Text Text; 
    Text.Text({0,0}, FONT_BIG, Color_Black, " ");
}
void SEDHOM_Text::Text(Coordinate_t coordinate, Text_Data_t str)
{
    setCursor(coordinate.x, coordinate.y);
    Adafruit_GFX::setFont(str.txt_font);
    setTextColor(str.txt_color);
    setTextWrap(false);
    String txt_obj = String(str.txt);
    for (uint16_t i = 0; i < txt_obj.length(); i++) 
    {
        write(txt_obj[i]);
    }
}

void SEDHOM_Text::Text(Coordinate_t coordinate, const GFXfont* font, Color_t color, float value)
{
    String str = String(value, 2);
    Text(coordinate, font, color, str);
}

void SEDHOM_Text::Text(Coordinate_t coordinate, const GFXfont* font, Color_t color, int value)
{
    String str = String(value);
    Text(coordinate, font, color, str);
}
void SEDHOM_Text::Text_OverFlow(Coordinate_t coordinate,const GFXfont* font,Color_t color,String txt,int number_overFlow,string_t overFlow_chars)
{
    String all_name;
    String part;
    if( txt.length() > number_overFlow)
    {
        if(number_overFlow >=3)
        {
             part = txt.substring(0,number_overFlow);
        }
        all_name = part + overFlow_chars ;
    }
    else
    {
        all_name = txt;
    }
    Text(coordinate,font,color,all_name);
}
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
#endif // !SEDHOM_Text_C_H_