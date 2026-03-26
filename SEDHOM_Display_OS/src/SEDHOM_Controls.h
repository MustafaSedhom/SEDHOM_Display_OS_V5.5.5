#ifndef SEDHOM_CONTROLE_H_
#define SEDHOM_CONTROLE_H_
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Icons.h"
#include "SEDHOM_Time.h"
#include "SEDHOM_Display_Touch.h"
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
class SEDHOM_Controls
{
private:
    SEDHOM_Icons Icon;
    SEDHOM_Touch Touch;
    SEDHOM_Time Time;
public:
    SEDHOM_Controls();
    ~SEDHOM_Controls();

    // Button
    template<typename Function>
    void Button_Control(bool* state,Rectangle_Data_t Button_shape_off,Rectangle_Data_t Button_shape_on,Function onTap,int Time_between_clicks_ms = 250);
    template<typename Function>
    void Button_Control(bool* state,Circle_Data_t Button_shape_off,Circle_Data_t Button_shape_on,Function onTap,int Time_between_clicks_ms = 250);
};
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
SEDHOM_Controls::SEDHOM_Controls()
{
}
SEDHOM_Controls::~SEDHOM_Controls()
{
}
template<typename Function>
void SEDHOM_Controls::Button_Control(bool* state,Rectangle_Data_t Button_shape_off,Rectangle_Data_t Button_shape_on,Function onTap,int Time_between_clicks_ms )
{
    static unsigned long lastPressTime = 0;    
    unsigned long currentTime = Time.Calc_time_ms();     
    Rectangle_Data_t activeShape = *state ? Button_shape_on : Button_shape_off;
    Icon.Rectangle(activeShape);
    bool pressed = Touch.onTap({activeShape.coordinate, activeShape.area});      
    if (pressed && (currentTime - lastPressTime > Time_between_clicks_ms))
    {
        onTap();                  
        lastPressTime = currentTime; 
    }
}
template<typename Function>
void SEDHOM_Controls::Button_Control(bool* state,Circle_Data_t Button_shape_off,Circle_Data_t Button_shape_on,Function onTap,int Time_between_clicks_ms )
{
    static unsigned long lastPressTime = 0;    
    unsigned long currentTime = Time.Calc_time_ms();     
    Circle_Data_t activeShape = *state ? Button_shape_on : Button_shape_off;
    Icon.Circle(activeShape);
    bool pressed = Touch.onTap({{activeShape.coordinate.x - activeShape.Radius,activeShape.coordinate.y - activeShape.Radius},{activeShape.Radius*2,activeShape.Radius*2}});      
    if (pressed && (currentTime - lastPressTime > Time_between_clicks_ms))
    {
        onTap();                       
        lastPressTime = currentTime; 
    }
}
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
#endif // !SEDHOM_CONTROLE_H_