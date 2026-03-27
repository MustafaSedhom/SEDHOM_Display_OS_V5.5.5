#ifndef SEDHOM_CONTROLE_H_
#define SEDHOM_CONTROLE_H_
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Icons.h"
#include "SEDHOM_Time.h"
#include "SEDHOM_Display_Touch.h"
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
class Button : private SEDHOM_Icons , private SEDHOM_Touch , private SEDHOM_Time
{
    private:
        Button_Data_t button;
    public:
        Button(Button_Data_t& button) : button(button){}
        ~Button(){}
        // function for Draw it
        Button& Draw();
        Button& Update(Button_Data_t new_button);
        template<typename Function>
        Button& Single_Press(Function To_Do);
        template<typename Function>
        Button& Double_Press(Function To_Do);
        template<typename Function>
        Button& Long_Press(Function To_Do);
};
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
Button& Button::Draw()
{
    if(button.shape == Shape_Circle)
    {
        Circle(button.state ? button.circle_shape_on : button.circle_shape_off);
    }
    else
    {
        Rectangle(button.state ? button.rectangle_shape_on : button.rectangle_shape_off);
    }
    return *this;
}
//=======================================================================================
Button& Button::Update(Button_Data_t new_button) 
{
    button = new_button;
    Draw();
}
template<typename Function>
Button& Button::Single_Press(Function To_Do)
{
    if(button.shape == Shape_Circle)
    {
        Circle_Data_t activeShape = button.state ? button.circle_shape_on : button.circle_shape_off;
        if(Single_Pressed({{activeShape.coordinate.x - activeShape.Radius,
                            activeShape.coordinate.y - activeShape.Radius},
                        {activeShape.Radius*2 , activeShape.Radius*2}}))
        {
            To_Do();
        }
    }
    else
    {
        Rectangle_Data_t activeShape = button.state ? button.rectangle_shape_on : button.rectangle_shape_off;
        if(Single_Pressed({activeShape.coordinate, activeShape.area}))
        {
            To_Do();
        }
    }
    return *this;
}
template<typename Function>
Button& Button::Double_Press(Function To_Do)
{ 
    if(button.shape == Shape_Circle)
    {
        Circle_Data_t activeShape = button.state ? button.circle_shape_on : button.circle_shape_off;
        if(Double_Pressed(button.touch_state,
                            {{activeShape.coordinate.x - activeShape.Radius,
                            activeShape.coordinate.y - activeShape.Radius},
                            {activeShape.Radius*2 , activeShape.Radius*2}},
                            button.doublePressTime))
        {
            To_Do();
        }
    }
    else
    {
        Rectangle_Data_t activeShape = button.state ? button.rectangle_shape_on : button.rectangle_shape_off;
        if(Double_Pressed(button.touch_state,{activeShape.coordinate, activeShape.area},button.doublePressTime))
        {
            To_Do();
        }
    }
    return *this;
}
template<typename Function>
Button& Button::Long_Press(Function To_Do)
{
    if(button.shape == Shape_Circle)
    {
        Circle_Data_t activeShape = button.state ? button.circle_shape_on : button.circle_shape_off;
        if(Long_Pressed(button.touch_state,
                        {{activeShape.coordinate.x - activeShape.Radius,
                            activeShape.coordinate.y - activeShape.Radius},
                            {activeShape.Radius*2 , activeShape.Radius*2}},
                        button.longPressTime))
        {
            To_Do();
        }
    }
    else
    {
        Rectangle_Data_t activeShape = button.state ? button.rectangle_shape_on : button.rectangle_shape_off;
        if(Long_Pressed(button.touch_state,
                        {activeShape.coordinate, activeShape.area},
                        button.longPressTime))
        {
            To_Do();
        }
    }
    return *this;
}
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
class SEDHOM_Controls
{
private:

public:
    SEDHOM_Controls(){}
    ~SEDHOM_Controls(){}

};
//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ

//QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
#endif // !SEDHOM_CONTROLE_H_