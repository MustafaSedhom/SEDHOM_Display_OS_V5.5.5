#ifndef SEDHOM_EFFECTS_H_
#define SEDHOM_EFFECTS_H_
//EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
#include "SEDHOM_Basic_Shapes.h"
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Colors.h"
//EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
class SEDHOM_Effects
{
    private:
       SEDHOM_Basic_Shapes Shape;
       SEDHOM_Colors Colors ;
    public:
        // effects 
        Color_t Blur(Icon_Data_t Icon,Area_t area,int r,int Blur_value,Shapes_type_t shape = Shape_Rectangle);
        Color_t Color_Blur(Icon_Data_t Icon,Area_t area,int r,int Blur_value,Shapes_type_t shape = Shape_Rectangle);
        Color_t Shadow_effect(Icon_Data_t shadow = {} , Shapes_type_t shape = Shape_Rectangle, int shadow_size = 5 , int shadow_h = 120 , int shadow_w = 200 ,int shadow_Radius = 20 , Position_t pos = Position_Right_and_Bottom, Color_t Shadow_color = Color_DarkGrey);
};
//EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
// Effects
Color_t SEDHOM_Effects::Blur(Icon_Data_t Icon,Area_t area,int r,int Blur_value,Shapes_type_t shape)
{
  Color_t color_value = map(Blur_value,Icon.color?20:0,Icon.color?0:20,0,255);

  Color_t color = Colors.set_Color({color_value,color_value,color_value});
  if(shape == Shape_Rectangle)
  {
    Shape.Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{area.w,area.h},r,Shape_Fill,color});
  }
  else if(shape == Shape_Circle)
  {
    Shape.Circle({{Icon.coordinate.x,Icon.coordinate.y},r,Shape_Fill,color});
  }
  return color;
}
Color_t SEDHOM_Effects::Color_Blur(Icon_Data_t Icon,Area_t area,int r,int Blur_value,Shapes_type_t shape)
{
  if(shape == Shape_Rectangle)
  {
    Shape.Rectangle({{Icon.coordinate.x,Icon.coordinate.y},{area.w,area.h},r,Shape_Fill,Icon.color});
  }
  else if(shape == Shape_Circle)
  {
    Shape.Circle({{Icon.coordinate.x,Icon.coordinate.y},r,Shape_Fill,Icon.color});
  }
  return Icon.color;
}
Color_t SEDHOM_Effects::Shadow_effect(Icon_Data_t shadow, Shapes_type_t shape , int shadow_size  , int shadow_h , int shadow_w ,int shadow_Radius , Position_t pos  , Color_t Shadow_color )
{
    int x = shadow.coordinate.x;
    int y = shadow.coordinate.y;
    int h = shadow_h;
    int w = shadow_w;

   switch (pos)
    {
    case Position_Center:
        break;

    case Position_Top:
        y -= shadow_size;
        break;

    case Position_Bottom:
        y += shadow_size;
        break;

    case Position_Right:
        x += shadow_size;
        break;

    case Position_Left:
        x -= shadow_size;
        break;

    case Position_Top_Left:
        x -= shadow_size;
        y -= shadow_size;
        break;

    case Position_Top_Right:
        x += shadow_size;
        y -= shadow_size;
        break;

    case Position_Bottom_Left:
        x -= shadow_size;
        y += shadow_size;
        break;

    case Position_Bottom_Right:
        x += shadow_size;
        y += shadow_size;
        break;

    case Position_Right_and_Left:
        x -= shadow_size;
        w += shadow_size * 2;
        break;

    case Position_Right_and_Top:
        x += shadow_size;
        y -= shadow_size;
        break;

    case Position_Right_and_Bottom:
        x += shadow_size;
        y += shadow_size;
        break;

    case Position_Left_and_Top:
        x -= shadow_size;
        y -= shadow_size;
        break;

    case Position_Left_and_Bottom:
        x -= shadow_size;
        y += shadow_size;
        break;

    case Position_Top_and_Bottom:
        y -= shadow_size;
        h += shadow_size * 2;
        break;

    case Position_All:
        x -= shadow_size;
        y -= shadow_size;
        h += shadow_size * 2;
        w += shadow_size * 2;
        break;
    }
    if (shape == Shape_Circle)
    {
      Shape.Circle({{x , y }, shadow_Radius,Shape_Fill, Shadow_color});
    }
    else
    {
      Shape.Rectangle({{x, y},{ w, h}, shadow_Radius,Shape_Fill, Shadow_color});
    }
    return Shadow_color;
}
//EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
#endif // !SEDHOM_EFFECTS_H_