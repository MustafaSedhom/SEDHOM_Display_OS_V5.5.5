#ifndef SEDHOM_BASIC_SHAPES_H_
#define SEDHOM_BASIC_SHAPES_H_
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Data_Types.h"
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
class SEDHOM_Basic_Shapes
{
    private:
        
    public:
        // define Basic shapes
        void Pixel(Pixel_Data_t pixel);
        void Line(Line_Data_t line);    
        void Rectangle(Rectangle_Data_t rect);
        void Square(Square_Data_t sqrt);  
        void Circle(Circle_Data_t circle); 
        void Triangle(Triangle_Data_t tri); 
        void Equilateral_Triangle(Triangle_special_Data_t tri);
        void Right_Triangle(Icon_Data_t Icon,Area_t area,Shape_filled_t filled);
        void Border_Rectangle(Icon_Data_t Border_Rect,Area_t area,int Radius,int Border_size);
        void Container(Rectangle_Data_t container);
        // custom image or font
        void Draw_Custom_int_shape(Icon_Data_t Icon,Area_t area,int arr[]);
        void Draw_Custom_Char(Icon_Data_t Icon,Area_t area,char arr[]);
        
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
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#endif // !SEDHOM_BASIC_SHAPES_H_