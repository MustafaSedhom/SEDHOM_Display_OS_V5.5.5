#ifndef SEDHOM_ANIMATIONS_H_
#define SEDHOM_ANIMATIONS_H_
//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
#include "SEDHOM_Icons.h"
#include "SEDHOM_Display_Touch.h"
#include "SEDHOM_Effects.h"
#include "SEDHOM_Time.h"
//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
class Text_Animator 
{
    private:
        unsigned long lastTime = 0;
        int interval;
    protected:
        SEDHOM_Time Time;
        SEDHOM_Icons Icon;

    public:
        Text_Animator(){}
        Text_Animator(int t) 
        {
            interval = t;
        }

        void Change_Text_Color(Coordenate_t co, GFXfont* Font,int Animation_time, String txt);

};
//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
void Text_Animator::Change_Text_Color(Coordenate_t co, GFXfont* Font,int Animation_time, String txt)
{
    interval = Animation_time ;
    unsigned long time_now = Time.Calc_time_ms();

    if (time_now - lastTime > Animation_time)
    {
        Icon.Text(co, Font, (Color_t)random(0xFFFF), txt);
        lastTime = time_now;
    }
}
//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
class SEDHOM_Animations : public Text_Animator
{
    private:
      
    public:
    // void Text_change_color(Coordenate_t co,GFXfont* Font,int time_ms,String txt);
};

//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
// void SEDHOM_Animations::Text_change_color(Coordenate_t co,GFXfont* Font,int time_ms,String txt)
// {
//   static unsigned long t_change = 0;
//    if( Time.Calc_time_ms() - t_change > time_ms)
//    {
//       Icon.Text(co,Font,random(0x0000, 0xFFFF),txt);
//       t_change = Time.Calc_time_ms();
//    }
// }
//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG


//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
#endif // !SEDHOM_ANIMATIONS_H_