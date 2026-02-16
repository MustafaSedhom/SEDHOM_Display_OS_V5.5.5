#ifndef SEDHOM_TEXT_H_
#define SEDHOM_TEXT_H_
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
        void TEXT(int x,int y,const GFXfont* font,Color_t color,string_t txt);
        void Text_cpp(int x,int y,const GFXfont* font,Color_t color,String txt);
};
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
// Text
void SEDHOM_Text::TEXT(int x,int y,const GFXfont* font,Color_t color,string_t txt) 
{
    Text(x,y,font,color,txt);
}
void SEDHOM_Text::Text_cpp(int x,int y,const GFXfont* font,Color_t color,String txt) 
{
    Text(x,y,font,color,txt);
}
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
#endif // !SEDHOM_TEXT_H_