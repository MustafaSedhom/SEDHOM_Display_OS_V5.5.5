//===============================================================================================================================
#pragma once
//===============================================================================================================================
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Time.h"
//===============================================================================================================================
class SEDHOM_Touch
{
  private:
      SEDHOM_Time Time;
      int pixel_x=0;
      int pixel_y=0;
      int pixel_z=0;
      bool Touch_getXY();
  public:
      bool Is_Pressed();
      Coordinate_t get_Point_Touched();
      int get_X_point();
      int get_Y_point();
      int get_Z_point();

      bool onTap(Touch_Data_t pressed_space);
      void onTap(Touch_Data_t pressed_space,void (*Do_Function)());

      bool Single_Pressed(Touch_Data_t pressed_space);
      bool Double_Pressed(Touch_State_t &state,Touch_Data_t pressed_space , int Time_ms_between_clicks = 1000);
      bool Long_Pressed(Touch_State_t &state,Touch_Data_t pressed_space, int Time_ms_long_time = 800);

      bool Single_Pressed_Circle(Coordinate_t pressed_center,int Radius);
      bool Double_Pressed_Circle(Touch_State_t &state,Coordinate_t pressed_center,int Radius,int Time_ms_between_clicks = 1000);
      bool Long_Pressed_Circle(Touch_State_t &state,Coordinate_t pressed_center,int Radius,int Time_ms_between_clicks = 800);
};
//===============================================================================================================================
//===============================================================================================================================
bool SEDHOM_Touch::Touch_getXY() 
{
  API_Touch_Point_Driver_Class_Name Point = API_Get_Touch_Point();

  API_Set_Touch_Pins_Setting();
  
  bool pressed = (Point.z > API_Touch_Pressure_Min() && Point.z < API_Touch_Pressure_Max());
  if (pressed) {
    pixel_x = map(Point.y, API_Touch_X_Raw_Left_Edge(), API_Touch_X_Raw_Right_Edge(), 0, API_Screen_height());
    pixel_y = map(Point.x, API_Touch_Y_Raw_Top_Edge(), API_Touch_Y_Raw_Bottom_Edge(), 0, API_Screen_width());
    pixel_z = Point.z;
  }
  return pressed;
}
//===============================================================================================================================
bool SEDHOM_Touch::Is_Pressed()
{
    return Touch_getXY();
}
//===============================================================================================================================
int SEDHOM_Touch::get_X_point() { return pixel_x; }
//===============================================================================================================================
int SEDHOM_Touch::get_Y_point() { return pixel_y; }
//===============================================================================================================================
int SEDHOM_Touch::get_Z_point() { return pixel_z; }
//===============================================================================================================================
Coordinate_t SEDHOM_Touch::get_Point_Touched() 
{
    return {pixel_x, pixel_y};
}
//===============================================================================================================================
bool SEDHOM_Touch::onTap(Touch_Data_t pressed_space)
{
  static unsigned long lastTapTime = 0;
  unsigned long now = Time.Now_Time();

  if (now - lastTapTime < 100)     
      return false;

  if (!Touch_getXY()) return false;   // ✅ نداء واحد بس

  lastTapTime = now; 
  return ((pixel_x >= pressed_space.coordinate.x && pixel_x <= (pressed_space.coordinate.x + pressed_space.area.w)) 
        && (pixel_y >= pressed_space.coordinate.y && pixel_y <= (pressed_space.coordinate.y + pressed_space.area.h)));
}
//===============================================================================================================================
bool SEDHOM_Touch::Single_Pressed_Circle(Coordinate_t pressed_center,int Radius)
{
  return onTap({{pressed_center.x-Radius,pressed_center.y-Radius},{Radius*2,Radius*2}}); // ✅ return
}
//===============================================================================================================================
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
//===============================================================================================================================
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
//===============================================================================================================================
void SEDHOM_Touch::onTap(Touch_Data_t pressed_space,void (*Do_Function)())
{
  if(onTap(pressed_space))
  {
    Do_Function();
  }
}
//===============================================================================================================================
bool SEDHOM_Touch::Single_Pressed(Touch_Data_t pressed_space)
{
  return onTap(pressed_space);
}
//===============================================================================================================================
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
//===============================================================================================================================
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
//===============================================================================================================================