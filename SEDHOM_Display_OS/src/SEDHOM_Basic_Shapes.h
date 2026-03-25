#ifndef SEDHOM_BASIC_SHAPES_H_
#define SEDHOM_BASIC_SHAPES_H_
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Math.h"
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
class SEDHOM_Basic_Shapes
{
    private:
        
    public:
        // define Basic shapes
        void Pixel(Pixel_Data_t pixel);
        void Line(Line_Data_t line);    
        static void Rectangle(Rectangle_Data_t rect);
        void Square(Square_Data_t sqrt);  
        void Circle(Circle_Data_t circle); 
        void Triangle(Triangle_Data_t tri); 
        // shapes derivative
        void Arc(Circle_Data_t Arc,int arc_number);
        void Equilateral_Triangle(Triangle_special_Data_t tri);
        void Right_Triangle(Icon_Data_t Icon,Area_t area,Shape_filled_t filled);
        void Border_Rectangle(Icon_Data_t Border_Rect,Area_t area,int Radius,int Border_size);
        void Container(Rectangle_Data_t container);
        // SEDHOM Shapes
        void SEDHOM_Circle(Circle_Data_t circle);
        // custom image or font
        void Draw_Custom_int_shape(Icon_Data_t Icon,Area_t area,int arr[]);
        void Draw_Custom_Char(Icon_Data_t Icon,Area_t area,char arr[]);
        // 3D shapes
        void Cube(Coordinate_t coordinate,int size,int Degree_angle_View,Color_t color);
        
};
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// define functions
// Basic shapes function  
void SEDHOM_Basic_Shapes::Pixel(Pixel_Data_t pixel)
{
    Draw_Pixel(pixel.coordinate_Point.x,pixel.coordinate_Point.y,pixel.color);
}
void SEDHOM_Basic_Shapes::Line(Line_Data_t line)
{
    Draw_Line(line.coordinate_Start_Point.x,line.coordinate_Start_Point.y,line.coordinate_End_Point.x,line.coordinate_End_Point.y,line.color);
}                                     
void SEDHOM_Basic_Shapes::Rectangle(Rectangle_Data_t rect)
{
    switch (rect.Filled)
    {
    case Shape_Fill:
      Fill_Rectangle(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,rect.Radius,rect.color);
      break;
    case Shape_Draw:
      Draw_Rectangle(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,rect.Radius,rect.color);
      break;
    }

}    
void SEDHOM_Basic_Shapes::Square(Square_Data_t sqrt)
{
  Rectangle({{sqrt.coordinate.x,sqrt.coordinate.y},{sqrt.length,sqrt.length},sqrt.Radius,sqrt.Filled,sqrt.color});
}  
void SEDHOM_Basic_Shapes::Circle(Circle_Data_t circle)
{
    switch (circle.Filled)
    {
    case Shape_Fill:
      Fill_Circle(circle.coordinate.x,circle.coordinate.y,circle.Radius,circle.color);
      break;
    case Shape_Draw:
      Draw_Circle(circle.coordinate.x,circle.coordinate.y,circle.Radius,circle.color);
      break;
    }
}      
void SEDHOM_Basic_Shapes::Triangle(Triangle_Data_t tri)
{
    switch (tri.Filled)
    {
    case Shape_Fill:
      Fill_Triangle(tri.coordinate_Point_1.x,tri.coordinate_Point_1.y,tri.coordinate_Point_2.x,tri.coordinate_Point_2.y,tri.coordinate_Point_3.x,tri.coordinate_Point_3.y,tri.color);
      break;
    case Shape_Draw:
      Draw_Triangle(tri.coordinate_Point_1.x,tri.coordinate_Point_1.y,tri.coordinate_Point_2.x,tri.coordinate_Point_2.y,tri.coordinate_Point_3.x,tri.coordinate_Point_3.y,tri.color);
      break;
    }  
}    
void SEDHOM_Basic_Shapes::Right_Triangle(Icon_Data_t Icon,Area_t area,Shape_filled_t filled)
{
    Triangle({{Icon.coordinate.x,Icon.coordinate.y},{Icon.coordinate.x ,Icon.coordinate.y + area.h },{Icon.coordinate.x + area.w,Icon.coordinate.y + area.h },filled,Icon.color});
}
void SEDHOM_Basic_Shapes::Equilateral_Triangle(Triangle_special_Data_t tri) 
{
  int x_0,y_0,x_1,y_1,x_2,y_2 ;
  float height  = tri.length * sqrt(3) / 2.0; ;

  switch (tri.Dir)
  {
    case Direction_Up:
      {
        x_0 = tri.coordinate.x;              
        y_0 = tri.coordinate.y - (2.0/3.0)*height;

        x_1 = tri.coordinate.x - tri.length/2;        
        y_1 = tri.coordinate.y + (1.0/3.0)*height;

        x_2 = tri.coordinate.x + tri.length/2;        
        y_2 = tri.coordinate.y + (1.0/3.0)*height;
      }
      break;
    case Direction_Down:
      {
        x_0 = tri.coordinate.x;               
        y_0 = tri.coordinate.y + (2.0/3.0)*height;  

        x_1 = tri.coordinate.x -  tri.length/2;        
        y_1 = tri.coordinate.y - (1.0/3.0)*height;  

        x_2 = tri.coordinate.x +  tri.length/2;        
        y_2 = tri.coordinate.y - (1.0/3.0)*height; 
      }
      break;
    case Direction_Right:
      {
        x_0 = tri.coordinate.x + (2.0/3.0)* tri.length; 
        y_0 = tri.coordinate.y;

        x_1 = tri.coordinate.x - (1.0/3.0)* tri.length; 
        y_1 = tri.coordinate.y - height/2;

        x_2 = tri.coordinate.x - (1.0/3.0)* tri.length; 
        y_2 = tri.coordinate.y + height/2;
      }
      break;
    case Direction_Left:
      {
        x_0 = tri.coordinate.x - (2.0/3.0)* tri.length; 
        y_0 = tri.coordinate.y;

        x_1 = tri.coordinate.x + (1.0/3.0)* tri.length; 
        y_1 = tri.coordinate.y - height/2;

        x_2 = tri.coordinate.x + (1.0/3.0)* tri.length;
        y_2 = tri.coordinate.y + height/2;        
      }
      break;
  }
  Triangle({{ x_0,  y_0},{  x_1,  y_1},{  x_2,  y_2},tri.filled, tri.color});
}
void SEDHOM_Basic_Shapes::SEDHOM_Circle(Circle_Data_t circle)
{
    int x_point = 0;
    int y_point = circle.Radius;
    int d = 1 - circle.Radius;

    while (x_point <= y_point)
    {
      if (circle.Filled == Shape_Draw)
      {
        // drew
        Pixel({{circle.coordinate.x + x_point, circle.coordinate.y - y_point}, circle.color});
        Pixel({{circle.coordinate.x + y_point, circle.coordinate.y - x_point}, circle.color});
        Pixel({{circle.coordinate.x + x_point, circle.coordinate.y + y_point}, circle.color});
        Pixel({{circle.coordinate.x + y_point, circle.coordinate.y + x_point}, circle.color});
        Pixel({{circle.coordinate.x - x_point, circle.coordinate.y + y_point}, circle.color});
        Pixel({{circle.coordinate.x - y_point, circle.coordinate.y + x_point}, circle.color});
        Pixel({{circle.coordinate.x - x_point, circle.coordinate.y - y_point}, circle.color});
        Pixel({{circle.coordinate.x - y_point, circle.coordinate.y - x_point}, circle.color});
      }
      else if (circle.Filled == Shape_Fill)
      {
        // filled
        for(int i = circle.coordinate.x - x_point; i <= circle.coordinate.x + x_point; i++) 
        {
          Pixel({{i, circle.coordinate.y + y_point}, circle.color});
          Pixel({{i, circle.coordinate.y - y_point}, circle.color});
        }
        for(int i = circle.coordinate.x - y_point; i <= circle.coordinate.x + y_point; i++) 
        {
            Pixel({{i, circle.coordinate.y + x_point}, circle.color});
            Pixel({{i, circle.coordinate.y - x_point}, circle.color});
        }
      }
        if (d < 0)
        {
            d +=  (2 * x_point) + 3;
        }
        else
        {
            d += (2 * (x_point - y_point)) + 5;
            y_point--;
        }
        x_point++;
    }
}
void SEDHOM_Basic_Shapes::Arc(Circle_Data_t Arc, int arc_number)
{
    int x_point = 0;
    int y_point = Arc.Radius;
    int d = 1 - Arc.Radius;

    while (x_point <= y_point)
    {
        if (Arc.Filled == Shape_Draw)
        {
            switch (arc_number)
            {
                case 1: Pixel({{Arc.coordinate.x + x_point, Arc.coordinate.y - y_point}, Arc.color}); break;
                case 2: Pixel({{Arc.coordinate.x + y_point, Arc.coordinate.y - x_point}, Arc.color}); break;
                case 3: Pixel({{Arc.coordinate.x + x_point, Arc.coordinate.y + y_point}, Arc.color}); break;
                case 4: Pixel({{Arc.coordinate.x + y_point, Arc.coordinate.y + x_point}, Arc.color}); break;
                case 5: Pixel({{Arc.coordinate.x - x_point, Arc.coordinate.y + y_point}, Arc.color}); break;
                case 6: Pixel({{Arc.coordinate.x - y_point, Arc.coordinate.y + x_point}, Arc.color}); break;
                case 7: Pixel({{Arc.coordinate.x - x_point, Arc.coordinate.y - y_point}, Arc.color}); break;
                case 8: Pixel({{Arc.coordinate.x - y_point, Arc.coordinate.y - x_point}, Arc.color}); break;
                case 0: // كل الـ Octants
                    Pixel({{Arc.coordinate.x + x_point, Arc.coordinate.y - y_point}, Arc.color});
                    Pixel({{Arc.coordinate.x + y_point, Arc.coordinate.y - x_point}, Arc.color});
                    Pixel({{Arc.coordinate.x + x_point, Arc.coordinate.y + y_point}, Arc.color});
                    Pixel({{Arc.coordinate.x + y_point, Arc.coordinate.y + x_point}, Arc.color});
                    Pixel({{Arc.coordinate.x - x_point, Arc.coordinate.y + y_point}, Arc.color});
                    Pixel({{Arc.coordinate.x - y_point, Arc.coordinate.y + x_point}, Arc.color});
                    Pixel({{Arc.coordinate.x - x_point, Arc.coordinate.y - y_point}, Arc.color});
                    Pixel({{Arc.coordinate.x - y_point, Arc.coordinate.y - x_point}, Arc.color});
                    break;
            }
        }
        else if (Arc.Filled == Shape_Fill)
        {
        switch(arc_number)
        {
            case 1: // Octant 1
                for(int i = Arc.coordinate.x; i <= Arc.coordinate.x + x_point; i++)
                {
                    Pixel({{i, Arc.coordinate.y - y_point}, Arc.color});
                }
                break;

            case 2: // Octant 2
                for(int i = Arc.coordinate.x; i <= Arc.coordinate.x + y_point; i++)
                {
                    Pixel({{i, Arc.coordinate.y - x_point}, Arc.color});
                }
                break;

            case 3: // Octant 3
                for(int i = Arc.coordinate.x; i <= Arc.coordinate.x + x_point; i++)
                {
                    Pixel({{i, Arc.coordinate.y + y_point}, Arc.color});
                }
                break;

            case 4: // Octant 4
                for(int i = Arc.coordinate.x; i <= Arc.coordinate.x + y_point; i++)
                {
                    Pixel({{i, Arc.coordinate.y + x_point}, Arc.color});
                }
                break;

            case 5: // Octant 5
                for(int i = Arc.coordinate.x - x_point; i <= Arc.coordinate.x; i++)
                {
                    Pixel({{i, Arc.coordinate.y + y_point}, Arc.color});
                }
                break;

            case 6: // Octant 6
                for(int i = Arc.coordinate.x - y_point; i <= Arc.coordinate.x; i++)
                {
                    Pixel({{i, Arc.coordinate.y + x_point}, Arc.color});
                }
                break;

            case 7: // Octant 7
                for(int i = Arc.coordinate.x - x_point; i <= Arc.coordinate.x; i++)
                {
                    Pixel({{i, Arc.coordinate.y - y_point}, Arc.color});
                }
                break;

            case 8: // Octant 8
                for(int i = Arc.coordinate.x - y_point; i <= Arc.coordinate.x; i++)
                {
                    Pixel({{i, Arc.coordinate.y - x_point}, Arc.color});
                }
                break;

            case 0: 
                for(int i = Arc.coordinate.x - x_point; i <= Arc.coordinate.x + x_point; i++)
                {
                    Pixel({{i, Arc.coordinate.y + y_point}, Arc.color});
                    Pixel({{i, Arc.coordinate.y - y_point}, Arc.color});
                }
                for(int i = Arc.coordinate.x - y_point; i <= Arc.coordinate.x + y_point; i++)
                {
                    Pixel({{i, Arc.coordinate.y + x_point}, Arc.color});
                    Pixel({{i, Arc.coordinate.y - x_point}, Arc.color});
                }
                break;
        }
        }
        if (d < 0)
            d += (2 * x_point) + 3;
        else
        {
            d += 2 * (x_point - y_point) + 5;
            y_point--;
        }
        x_point++;
    }
}
// Draw custom image or font
void SEDHOM_Basic_Shapes::Draw_Custom_Char(Icon_Data_t Icon,Area_t area,char arr[])
{
  for(int i=0; i<area.w; i++) 
  {
    for(int j=0; j<area.h; j++) 
    {
      if(((arr[i]) >> (area.h-1-j)) & 0x01)
      {
        Pixel({{Icon.coordinate.x+j,Icon.coordinate.y+i}, Icon.color}); 
      }
    }
  }
}
void SEDHOM_Basic_Shapes::Draw_Custom_int_shape(Icon_Data_t Icon,Area_t area,int arr[])
{
  for(int i=0; i<area.w; i++) 
  {
    for(int j=0; j<area.h; j++) 
    {
      if(((arr[i]) >> (area.w-1-j)) & 0x01)
      {
        Pixel({{Icon.coordinate.x+j,Icon.coordinate.y+i}, Icon.color}); 
      }
    }
  }
}
void SEDHOM_Basic_Shapes::Border_Rectangle(Icon_Data_t Border_Rect,Area_t area,int Radius,int Border_size)
{
  Rectangle({{Border_Rect.coordinate.x,Border_Rect.coordinate.y},{area.w,area.h},Radius,Shape_Fill,Border_Rect.color});
  Rectangle({{Border_Rect.coordinate.x+Border_size,Border_Rect.coordinate.y+Border_size},{area.w-(2*Border_size),area.h-(2*Border_size)},Radius,Shape_Fill,Border_Rect.Background});
}
void SEDHOM_Basic_Shapes::Container(Rectangle_Data_t container)
{
    Rectangle(container);
}
void SEDHOM_Basic_Shapes::Cube(Coordinate_t coordinate,int size,int Degree_angle_View,Color_t color)
{
    int cube[8][3] = {
        {-size,-size,-size}, {size,-size,-size},
        {size,size,-size},   {-size,size,-size},
        {-size,-size,size},  {size,-size,size},
        {size,size,size},    {-size,size,size}
    };
    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };
    Coordinate_t projected[8];
    float rad = SEDHOM_Math::Degree_to_Radian(Degree_angle_View);
    for(int i = 0; i < 8; i++)
    {
        float x = cube[i][0];
        float y = cube[i][1];
        float z = cube[i][2];
        float rx = x * cos(rad) - z * sin(rad);
        float rz = x * sin(rad) + z * cos(rad);
        int distance = 200;
        int px = (rx * distance) / (rz + distance);
        int py = (y  * distance) / (rz + distance);
        projected[i].x = px + size + 20 + coordinate.x;
        projected[i].y = py + size + 10 + coordinate.y;
    }
    for(int i = 0; i < 12; i++)
    {
        Line({
            projected[edges[i][0]],
            projected[edges[i][1]],
            color
        });
    }
}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#endif // !SEDHOM_BASIC_SHAPES_H_