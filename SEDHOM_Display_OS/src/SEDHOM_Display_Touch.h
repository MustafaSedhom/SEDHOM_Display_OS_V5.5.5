#ifndef SEDHOM_DISPLAY_TOUCH_H_
#define SEDHOM_DISPLAY_TOUCH_H_
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Time.h"
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class SEDHOM_Touch
{
  private:
      // variables
      SEDHOM_Time Time;
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
      bool onTap_Circle(Coordinate_t pressed_center,int Radius);
      void onTap(Touch_Data_t pressed_space,void (*Do_Function)());
      bool Single_Pressed(Touch_Data_t pressed_space);
      bool Double_Pressed(Touch_State_t &state,Touch_Data_t pressed_space , int Time_ms_between_clicks = 1000);
      bool Long_Pressed(Touch_State_t &state,Touch_Data_t pressed_space, int Time_ms_long_time = 800);
      bool Single_Pressed_Circle(Coordinate_t pressed_center,int Radius);
      bool Double_Pressed_Circle(Touch_State_t &state,Coordinate_t pressed_center,int Radius,int Time_ms_between_clicks = 1000);
      bool Long_Pressed_Circle(Touch_State_t &state,Coordinate_t pressed_center,int Radius,int Time_ms_between_clicks = 800);
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
  static unsigned long lastTapTime = 0;
  unsigned long now = Time.Now_Time();

  if (now - lastTapTime < 100)     
      return false;

  if (!Touch_getXY()) return false;

  lastTapTime = now; 
  if (!Touch_getXY()) return false;
  return ((pixel_x >= pressed_space.coordinate.x && pixel_x <= (pressed_space.coordinate.x + pressed_space.area.w)) 
        && (pixel_y >= pressed_space.coordinate.y && pixel_y <= (pressed_space.coordinate.y + pressed_space.area.h)));
}
bool SEDHOM_Touch::Single_Pressed_Circle(Coordinate_t pressed_center,int Radius)
{
  onTap({{pressed_center.x-Radius,pressed_center.y-Radius},{Radius*2,Radius*2}});
}
bool SEDHOM_Touch::Double_Pressed_Circle(Touch_State_t &state,Coordinate_t pressed_center,int Radius,int Time_ms_between_clicks)
{
    unsigned long currentTime = Time.Now_Time();

    if (Single_Pressed_Circle(pressed_center,Radius))
    {
        if (state.waitingDouble &&
            (currentTime - state.lastTapTime <= Time_ms_between_clicks))
        {
            state.waitingDouble = false;
            return true;
        }
        else
        {
            state.waitingDouble = true;
            state.lastTapTime = currentTime;
        }
    }
    if (state.waitingDouble &&
        (currentTime - state.lastTapTime > Time_ms_between_clicks))
    {
        state.waitingDouble = false;
    }

    return false;
}
bool SEDHOM_Touch::Long_Pressed_Circle(Touch_State_t &state,Coordinate_t pressed_center,int Radius, int Time_ms_long_time)
{
    unsigned long currentTime = Time.Now_Time();

    if (Single_Pressed_Circle(pressed_center,Radius))
    {
        if (!state.isPressing)
        {
            state.isPressing = true;
            state.startTime = currentTime;
            state.longTriggered = false;
        }

        if (!state.longTriggered && (currentTime - state.startTime >= Time_ms_long_time))
        {
            state.longTriggered = true;
            return true;
        }
    }
    else
    {
        state.isPressing = false;
        state.longTriggered = false;
    }

    return false;
}
//!
void SEDHOM_Touch::onTap(Touch_Data_t pressed_space,void (*Do_Function)())
{
  if(onTap(pressed_space))
  {
    Do_Function();
  }
}
bool SEDHOM_Touch::Single_Pressed(Touch_Data_t pressed_space)
{
  return onTap(pressed_space);
}
bool SEDHOM_Touch::Double_Pressed(Touch_State_t &state,Touch_Data_t pressed_space,int Time_ms_between_clicks)
{
    unsigned long currentTime = Time.Now_Time();

    if (onTap(pressed_space))
    {
        if (state.waitingDouble &&
            (currentTime - state.lastTapTime <= Time_ms_between_clicks))
        {
            state.waitingDouble = false;
            return true;
        }
        else
        {
            state.waitingDouble = true;
            state.lastTapTime = currentTime;
        }
    }
    if (state.waitingDouble &&
        (currentTime - state.lastTapTime > Time_ms_between_clicks))
    {
        state.waitingDouble = false;
    }

    return false;
}
bool SEDHOM_Touch::Long_Pressed(Touch_State_t &state,Touch_Data_t pressed_space, int Time_ms_long_time)
{
    unsigned long currentTime = Time.Now_Time();

    if (onTap(pressed_space))
    {
        if (!state.isPressing)
        {
            state.isPressing = true;
            state.startTime = currentTime;
            state.longTriggered = false;
        }

        if (!state.longTriggered && (currentTime - state.startTime >= Time_ms_long_time))
        {
            state.longTriggered = true;
            return true;
        }
    }
    else
    {
        state.isPressing = false;
        state.longTriggered = false;
    }

    return false;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#endif /*SEDHOM_DISPLAY_TOUCH_H_*/
