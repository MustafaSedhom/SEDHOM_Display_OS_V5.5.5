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
        void Pixel(Pixel_t pixel);
        void Line(Line_t line);    
        void Rectangle(Rectangle_t rect);
        void Square(Square_t sqrt);  
        void Circle(Circle_t circle); 
        void Triangle(Triangle_t tri); 
        void Equilateral_Triangle(Triangle_special_t tri);
        void Right_Triangle(int x, int y, int h, int w,bool fill_or_draw, Color_t color);
        void Border_Rectangle(Icon_t Border_Rect,int h,int w,int Raduis,int Border_size);
        // custom image or font
        void Draw_Custom_int_shap(int x,int y,int h,int w,int color,int arr[]);
        void Draw_Custom_Char(int x,int y,int h,int w,int color,char arr[]);
        void Container(int x,int y,int h,int w,int raduis,Color_t color);
        void fill_rectangle_with_end(int x,int y,int h,int w,int end_volume,Color_t color,Color_t end_color);
        
};
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// define functions
// Basic shapes function  
void SEDHOM_Basic_Shapes::Pixel(Pixel_t pixel)
{
    Draw_Pixel(pixel.coordenate_Point.x,pixel.coordenate_Point.y,pixel.color);
}
void SEDHOM_Basic_Shapes::Line(Line_t line)
{
    Draw_Line(line.coordenate_Start_Point.x,line.coordenate_Start_Point.y,line.coordenate_End_Point.x,line.coordenate_End_Point.y,line.color);
}                                     
void SEDHOM_Basic_Shapes::Rectangle(Rectangle_t rect)
{
    switch (rect.Filled)
    {
    case Shape_Fill:
      Fill_Rectangle(rect.coordenate.x,rect.coordenate.y,rect.area.w,rect.area.h,rect.Raduis,rect.color);
      break;
    case Shape_Draw:
      Draw_Rectangle(rect.coordenate.x,rect.coordenate.y,rect.area.w,rect.area.h,rect.Raduis,rect.color);
      break;
    }

}    
void SEDHOM_Basic_Shapes::Square(Square_t sqrt)
{
  Rectangle({{sqrt.coordenate.x,sqrt.coordenate.y},{sqrt.length,sqrt.length},sqrt.Raduis,sqrt.Filled,sqrt.color});
}  
void SEDHOM_Basic_Shapes::Circle(Circle_t circle)
{
    switch (circle.Filled)
    {
    case Shape_Fill:
      Fill_Circle(circle.coordenate.x,circle.coordenate.y,circle.Raduis,circle.color);
      break;
    case Shape_Draw:
      Draw_Circle(circle.coordenate.x,circle.coordenate.y,circle.Raduis,circle.color);
      break;
    }
}      
void SEDHOM_Basic_Shapes::Triangle(Triangle_t tri)
{
    switch (tri.Filled)
    {
    case Shape_Fill:
      Fill_Triangle(tri.coordenate_Point_1.x,tri.coordenate_Point_1.y,tri.coordenate_Point_2.x,tri.coordenate_Point_2.y,tri.coordenate_Point_3.x,tri.coordenate_Point_3.y,tri.color);
      break;
    case Shape_Draw:
      Draw_Triangle(tri.coordenate_Point_1.x,tri.coordenate_Point_1.y,tri.coordenate_Point_2.x,tri.coordenate_Point_2.y,tri.coordenate_Point_3.x,tri.coordenate_Point_3.y,tri.color);
      break;
    }  
}    
void SEDHOM_Basic_Shapes::Right_Triangle(int x, int y, int h, int w,bool fill_or_draw, Color_t color)
{
    if(fill_or_draw) {Fill_Triangle(x, y, x, y + w, x + h, y + w, color);}
    else {Draw_Triangle(x, y, x, y + w, x + h, y + w, color);}
}
void SEDHOM_Basic_Shapes::Equilateral_Triangle(Triangle_special_t tri) 
{
  int x_0,y_0,x_1,y_1,x_2,y_2 ;
  float height  = tri.lenght * sqrt(3) / 2.0; ;

  switch (tri.Dir)
  {
    case Direction_Up:
      {
        x_0 = tri.coordinate.x;              
        y_0 = tri.coordinate.y - (2.0/3.0)*height;

        x_1 = tri.coordinate.x - tri.lenght/2;        
        y_1 = tri.coordinate.y + (1.0/3.0)*height;

        x_2 = tri.coordinate.x + tri.lenght/2;        
        y_2 = tri.coordinate.y + (1.0/3.0)*height;
      }
      break;
    case Direction_Down:
      {
        x_0 = tri.coordinate.x;               
        y_0 = tri.coordinate.y + (2.0/3.0)*height;  

        x_1 = tri.coordinate.x -  tri.lenght/2;        
        y_1 = tri.coordinate.y - (1.0/3.0)*height;  

        x_2 = tri.coordinate.x +  tri.lenght/2;        
        y_2 = tri.coordinate.y - (1.0/3.0)*height; 
      }
      break;
    case Direction_Right:
      {
        x_0 = tri.coordinate.x + (2.0/3.0)* tri.lenght; 
        y_0 = tri.coordinate.y;

        x_1 = tri.coordinate.x - (1.0/3.0)* tri.lenght; 
        y_1 = tri.coordinate.y - height/2;

        x_2 = tri.coordinate.x - (1.0/3.0)* tri.lenght; 
        y_2 = tri.coordinate.y + height/2;
      }
      break;
    case Direction_Left:
      {
        x_0 = tri.coordinate.x - (2.0/3.0)* tri.lenght; 
        y_0 = tri.coordinate.y;

        x_1 = tri.coordinate.x + (1.0/3.0)* tri.lenght; 
        y_1 = tri.coordinate.y - height/2;

        x_2 = tri.coordinate.x + (1.0/3.0)* tri.lenght;
        y_2 = tri.coordinate.y + height/2;        
      }
      break;
  }
  Triangle({{ x_0,  y_0},{  x_1,  y_1},{  x_2,  y_2},tri.filled, tri.color});
}
// Draw custom image or font
void SEDHOM_Basic_Shapes::Draw_Custom_Char(int x,int y,int h,int w,int color,char arr[])
{
  for(int i=0; i<h; i++) 
  {
    for(int j=0; j<w; j++) 
    {
      if(((arr[i]) >> (w-1-j)) & 0x01)
      {
        Pixel({x+j, y+i, color}); 
      }
    }
  }
}
void SEDHOM_Basic_Shapes::Draw_Custom_int_shap(int x,int y,int h,int w,int color,int arr[])
{
      for(int i=0; i<h; i++) 
  {
    for(int j=0; j<w; j++) 
    {
      if(((arr[i]) >> (w-1-j)) & 0x01)
      {
        Pixel({x+j, y+i, color}); 
      }
    }
  }
}
void SEDHOM_Basic_Shapes::Border_Rectangle(Icon_t Border_Rect,int h,int w,int Raduis,int Border_size)
{
  Rectangle({{Border_Rect.x,Border_Rect.y},{w,h},Raduis,Shape_Fill,Border_Rect.color});
  Rectangle({{Border_Rect.x+Border_size,Border_Rect.y+Border_size},{w-(2*Border_size),h-(2*Border_size)},Raduis,Shape_Fill,Border_Rect.Background});
}
void SEDHOM_Basic_Shapes::Container(int x,int y,int h,int w,int raduis,Color_t color)
{
    Rectangle({{x, y},{ h, w}, raduis,Shape_Fill, color});
}

void SEDHOM_Basic_Shapes::fill_rectangle_with_end(int x,int y,int h,int w,int end_volume,Color_t color,Color_t end_color)
{
    Rectangle({{x,y},{w,h},5,Shape_Fill,end_color});
    Rectangle({{x + end_volume,y + end_volume},{w - 2*end_volume,h - 2*end_volume},5,Shape_Fill,color});
}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#endif // !SEDHOM_BASIC_SHAPES_H_