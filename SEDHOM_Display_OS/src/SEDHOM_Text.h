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
        // Text_C
        void Text_C(Coordenate_t coordinate,const GFXfont* font,Color_t color,string_t txt);
        void Text(Coordenate_t coordinate,const GFXfont* font,Color_t color,String str);
};
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
// Text_C
void SEDHOM_Text::Text_C(Coordenate_t coordinate,const GFXfont* font,Color_t color,string_t txt) 
{
    Text_Driver(coordinate.x,coordinate.y,font,color,txt);
}
void SEDHOM_Text::Text(Coordenate_t coordinate,const GFXfont* font,Color_t color,String str) 
{
    Text_Driver(coordinate.x,coordinate.y,font,color,str);
}
//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
#endif // !SEDHOM_Text_C_H_