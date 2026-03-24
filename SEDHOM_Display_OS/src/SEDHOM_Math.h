#ifndef SEDHOM_MATH_H_
#define SEDHOM_MATH_H_
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#include "SEDHOM_Data_Types.h"
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
class SEDHOM_Math
{
private:
    /* data */
public:
    SEDHOM_Math(/* args */);
    ~SEDHOM_Math();
    // functions
    static float Degree_to_Radian(float Degree);
    static float Radian_to_Degree(float Radian);
    static Coordinate_t Rotation_Equation(Coordinate_t old_Point ,float Degree_angle);
};

SEDHOM_Math::SEDHOM_Math(/* args */)
{
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
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#endif // !SEDHOM_MATH_H_