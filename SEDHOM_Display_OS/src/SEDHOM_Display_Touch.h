#ifndef SEDHOM_DISPLAY_TOUCH_H_
#define SEDHOM_DISPLAY_TOUCH_H_
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "SEDHOM_Display_Settings.h"
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class SEDHOM_Touch
{
  private:
      // variables
      int pixel_x=0;
      int pixel_y=0;
      int pixel_z=0;
      // function private
      bool Touch_getXY();
  public:
      bool Is_Pressed();
      int get_X_point();
      int get_Y_point();
      int get_Z_point();
      bool onTap(Touch_Data_t pressed_space);
      void onTap(Touch_Data_t pressed_space,void (*Do_Function)());

};

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool SEDHOM_Touch::Touch_getXY() 
{
  TSPoint p = ts.getPoint();

  set_pins_for_touch();

  bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
  if (pressed) {
    pixel_x = map(p.y, TS_LEFT, TS_RT, 0, 480);
    pixel_y = map(p.x, TS_TOP, TS_BOT, 0, 320);
    pixel_z = p.z;
  }
  return pressed;
}
bool SEDHOM_Touch::Is_Pressed()
{
    return Touch_getXY();
}
int SEDHOM_Touch::get_X_point()
{
    Touch_getXY();
    return pixel_x; 
}
int SEDHOM_Touch::get_Y_point()
{
    Touch_getXY();
    return pixel_y; 
}
int SEDHOM_Touch::get_Z_point()
{
    Touch_getXY();
    return pixel_z; 
}
bool SEDHOM_Touch::onTap(Touch_Data_t pressed_space)
{
  if (!Touch_getXY()) return false;
  return ((pixel_x >= pressed_space.coordinate.x && pixel_x <= (pressed_space.coordinate.x + pressed_space.area.w)) 
        && (pixel_y >= pressed_space.coordinate.y && pixel_y <= (pressed_space.coordinate.y + pressed_space.area.h)));
}
void SEDHOM_Touch::onTap(Touch_Data_t pressed_space,void (*Do_Function)())
{
  if(onTap(pressed_space))
  {
    Do_Function();
  }
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif /*SEDHOM_DISPLAY_TOUCH_H_*/
