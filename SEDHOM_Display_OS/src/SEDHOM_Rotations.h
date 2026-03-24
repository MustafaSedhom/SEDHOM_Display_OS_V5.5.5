#ifndef SEDHOM_ROTATIONS_H_
#define SEDHOM_ROTATIONS_H_
//////////////////////////////////////////////////////////////////////////////////////////////////
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Math.h"
#include "SEDHOM_Basic_Shapes.h"
//////////////////////////////////////////////////////////////////////////////////////////////////
class SEDHOM_Rotations
{
private:
   SEDHOM_Basic_Shapes Shapes;
public:
    SEDHOM_Rotations();
    ~SEDHOM_Rotations();
    Coordinate_t Rotate_coordinates(Coordinate_t Basic_coordinate,Coordinate_t center,float Degree_angle);
    void Rotated_Rect(Rectangle_Data_t Rect,float Degree_angle);
};

SEDHOM_Rotations::SEDHOM_Rotations()
{
}

SEDHOM_Rotations::~SEDHOM_Rotations()
{
}

//////////////////////////////////////////////////////////////////////////////////////////////////
Coordinate_t SEDHOM_Rotations::Rotate_coordinates(Coordinate_t Basic_coordinate,Coordinate_t center,float Degree_angle)
{
    Coordinate_t return_coordinate_Rotate;
    Coordinate_t new_center = {
        Basic_coordinate.x - center.x ,
        Basic_coordinate.y - center.y ,
    };
    return_coordinate_Rotate = SEDHOM_Math::Rotation_Equation(new_center,Degree_angle);

    return_coordinate_Rotate.x += center.x;
    return_coordinate_Rotate.y += center.y;

    return return_coordinate_Rotate;
}
void SEDHOM_Rotations::Rotated_Rect(Rectangle_Data_t Rect,float Degree_angle) 
{
    Coordinate_t center;
    Coordinate_t p1,p2,p3,p4;
    
    center.x = Rect.coordinate.x + Rect.area.w / 2;
    center.y = Rect.coordinate.y + Rect.area.h / 2;

    p1 = Rotate_coordinates(Rect.coordinate,center,Degree_angle);
    p2 = Rotate_coordinates({Rect.coordinate.x + Rect.area.w,Rect.coordinate.y},center,Degree_angle);
    p3 = Rotate_coordinates({Rect.coordinate.x + Rect.area.w,Rect.coordinate.y + Rect.area.h},center,Degree_angle);
    p4 = Rotate_coordinates({Rect.coordinate.x,Rect.coordinate.y + Rect.area.h},center,Degree_angle);

    if(Rect.Filled == Shape_Draw)
    {
      Shapes.Line({p1,p2, Rect.color});
      Shapes.Line({p2,p3, Rect.color});
      Shapes.Line({p3,p4, Rect.color});
      Shapes.Line({p4,p1, Rect.color});

    }
    else
    {
      Shapes.Triangle({p1,p2,p3,Shape_Fill,Rect.color});
      Shapes.Triangle({p1,p3,p4,Shape_Fill,Rect.color});
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
#endif // !SEDHOM_ROTATIONS_H_