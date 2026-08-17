#ifndef SEDHOM_MATH_H_
#define SEDHOM_MATH_H_
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#include "SEDHOM_Data_Types.h"
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
class SEDHOM_Math
{
private:
    Area_t Screen_Dimensions;
public:
    SEDHOM_Math();
    SEDHOM_Math(Area_t Screen_Area);
    ~SEDHOM_Math();
    // functions
    static float Degree_to_Radian(float Degree);
    static float Radian_to_Degree(float Radian);
    static Coordinate_t Rotation_Equation(Coordinate_t old_Point ,float Degree_angle);
    int Convert_Coordinates_to_Center_X_Point(int x);
    int Convert_Coordinates_to_Center_Y_Point(int y);
    Coordinate_t Convert_Coordinates_to_Center(Coordinate_t new_point);
};

SEDHOM_Math::SEDHOM_Math()
{
}
SEDHOM_Math::SEDHOM_Math(Area_t Screen_Area)
{
   Screen_Dimensions = Screen_Area;
}
SEDHOM_Math::~SEDHOM_Math()
{
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
float SEDHOM_Math::Degree_to_Radian(float Degree)
{
    return Degree * 3.14159265359 / 180.0;
}
float SEDHOM_Math::Radian_to_Degree(float Radian)
{
     return Radian * 180.0 / 3.14159265359;
}
Coordinate_t SEDHOM_Math::Rotation_Equation(Coordinate_t old_Point ,float Degree_angle)
{
    float rad_angle = Degree_to_Radian(Degree_angle);
    Coordinate_t return_coordinate_Rotate;
    return_coordinate_Rotate.x = old_Point.x * cos(rad_angle) - old_Point.y * sin(rad_angle);
    return_coordinate_Rotate.y = old_Point.x * sin(rad_angle) + old_Point.y * cos(rad_angle);
    return return_coordinate_Rotate;
}
int SEDHOM_Math::Convert_Coordinates_to_Center_X_Point(int x)
{
    return x + (Screen_Dimensions.w / 2);
}
int SEDHOM_Math::Convert_Coordinates_to_Center_Y_Point(int y)
{
    return (Screen_Dimensions.h / 2) - y;
}
Coordinate_t SEDHOM_Math::Convert_Coordinates_to_Center(Coordinate_t new_point)
{
  Coordinate_t old_coordinate ;
  old_coordinate.x = Convert_Coordinates_to_Center_X_Point(new_point.x);
  old_coordinate.y = Convert_Coordinates_to_Center_Y_Point(new_point.y);
   return old_coordinate;
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#endif // !SEDHOM_MATH_H_