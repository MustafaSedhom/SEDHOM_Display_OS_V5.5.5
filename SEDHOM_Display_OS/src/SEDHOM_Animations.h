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

        void Change_Text_Color(Coordinate_t co, GFXfont* Font,int Animation_time, String txt);
        void Scrolling_Text(Icon_t Icon,GFXfont* Font,int time_ms,String txt ,Coordinate_t min_max);
};
//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
void Text_Animator::Change_Text_Color(Coordinate_t co, GFXfont* Font,int Animation_time, String txt)
{
    interval = Animation_time ;
    unsigned long time_now = Time.Calc_time_ms();

    if (time_now - lastTime > Animation_time)
    {
        Icon.Text(co, Font, (Color_t)random(0xFFFF), txt);
        lastTime = time_now;
    }
}
void Text_Animator::Scrolling_Text(Icon_t myIcon,GFXfont* Font,int time_ms,String txt ,Coordinate_t min_max)
{
  static Coordinate_t co = min_max ;
  static unsigned long t = 0;
  static int i = 0;
  static int dir = 1;   
  static int last_i = 0;

  unsigned long now = Time.Calc_time_ms();

  if (now - t > time_ms)
  {
      Icon.Text({myIcon.coordinate.x + last_i, myIcon.coordinate.y}, Font, myIcon.Background, txt);
      Icon.Text({myIcon.coordinate.x + i, myIcon.coordinate.y},Font,myIcon.color , txt);
      last_i = i;
      t = now;

      i += dir;

      if (i > co.y || i < co.x)
          dir = -dir;  
  }
}
//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG

//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
class SEDHOM_Animations : public Text_Animator //, public Shapes_Animations
{
    private:
      
    public:
    // void Text_change_color(Coordinate_t co,GFXfont* Font,int time_ms,String txt);
};

//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
// void SEDHOM_Animations::Text_change_color(Coordinate_t co,GFXfont* Font,int time_ms,String txt)
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