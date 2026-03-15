#ifndef SEDHOM_Text_H_
#define SEDHOM_Text_H_
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Display_Fonts.h"
#include "SEDHOM_Arabic_Font.h"
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Colors.h"
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
class SEDHOM_Text
{
    private:
    
    public:
        // Text
        static void Text_C(Coordinate_t coordinate,const GFXfont* font,Color_t color,string_t txt);
        void Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,String str);
        void Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,float value);
        void Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,int value);
        void Text(Coordinate_t coordinate,Text_Data_t str);
        void Text_OverFlow(Coordinate_t coordinate,const GFXfont* font,Color_t color,String txt,int number_overFlow=10,string_t overFlow_chars="...");
};
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
// Text_C
void SEDHOM_Text::Text_C(Coordinate_t coordinate,const GFXfont* font,Color_t color,string_t txt) 
{
    Text_Driver(coordinate.x,coordinate.y,font,color,txt);
}
void SEDHOM_Text::Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,String str) 
{
    Text_Driver(coordinate.x,coordinate.y,font,color,str);
}
void SEDHOM_Text::Text(Coordinate_t coordinate,Text_Data_t str)
{
    Text_Driver(coordinate.x,coordinate.y,str.txt_font,str.txt_color,str.txt);
}
void SEDHOM_Text::Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,float value)
{
    Text_Driver(coordinate.x,coordinate.y,font,color,String(value));
}
void SEDHOM_Text::Text(Coordinate_t coordinate,const GFXfont* font,Color_t color,int value)
{
    Text_Driver(coordinate.x,coordinate.y,font,color,String(value));
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