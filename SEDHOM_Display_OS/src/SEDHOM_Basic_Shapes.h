#ifndef SEDHOM_BASIC_SHAPES_H_
#define SEDHOM_BASIC_SHAPES_H_
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Data_Types.h"
#include "SEDHOM_Math.h"
#include "SEDHOM_GUI_Core.h"
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
class SEDHOM_Basic_Shapes : private virtual SEDHOM_GUI_Core
{
    private:
        
    public:
        //
        SEDHOM_Basic_Shapes(){}
        // define Basic shapes
        void Pixel(Pixel_Data_t pixel);
        void Line(Line_Data_t line);    
        void Rectangle(Rectangle_Data_t rect);
        void Rotated_Rectangle(Rectangle_Data_t rect,int angle);
        void Square(Square_Data_t sqrt);  
        void Circle(Circle_Data_t circle); 
        void Triangle(Triangle_Data_t tri); 
        void Pie(Pie_Data_t pie);
        void Ellipse(Ellipse_Data_t ellipse);
        // shapes derivative
        void Equilateral_Triangle(Triangle_special_Data_t tri);
        void Right_Triangle(Icon_Data_t Icon,Area_t area,Shape_filled_t filled);
        void Border_Rectangle(Icon_Data_t Border_Rect,Area_t area,int Radius,int Border_size);
        void Container(Rectangle_Data_t container);
        void Image_Single_Color(Image_Data_t image);
        void Image_RGB(Image_RGB_Data_t image);
        // 3D shapes
        void Cube(Coordinate_t coordinate,int size,int Degree_angle_View,Color_t color);
        // QR Code
        void QRCode(QRCode_Data_t qr);
        void BarCode(BarCode_Data_t qr);
        
};
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
// define functions
// Basic shapes function  
void SEDHOM_Basic_Shapes::Pixel(Pixel_Data_t pixel)
{
    // Draw_Pixel(pixel.coordinate_Point.x,pixel.coordinate_Point.y,pixel.color);
    drawPixel(pixel.coordinate_Point.x,pixel.coordinate_Point.y,pixel.color);
}
void SEDHOM_Basic_Shapes::Line(Line_Data_t line)
{
    // Draw_Line(line.coordinate_Start_Point.x,line.coordinate_Start_Point.y,line.coordinate_End_Point.x,line.coordinate_End_Point.y,line.color);
    drawLine(line.coordinate_Start_Point.x,line.coordinate_Start_Point.y,line.coordinate_End_Point.x,line.coordinate_End_Point.y,line.color);
}                                     
void SEDHOM_Basic_Shapes::Rectangle(Rectangle_Data_t rect)
{
    switch (rect.Filled)
    {
    case Shape_Fill:
    //   Fill_Rectangle(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,rect.Radius,rect.color);
      fillRoundRect(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,rect.Radius,rect.color);
      break;
      case Shape_Draw:
    //   Draw_Rectangle(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,rect.Radius,rect.color);
      drawRoundRect(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,rect.Radius,rect.color);
      break;
    }

}    
void SEDHOM_Basic_Shapes::Rotated_Rectangle(Rectangle_Data_t rect,int angle)
{
    switch (rect.Filled)
    {
    case Shape_Fill:
    //   Fill_Rotated_Rect(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,angle,rect.color);
      fillRotatedRect(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,angle,rect.color);
      break;
    case Shape_Draw:
    //   Draw_Rotated_Rect(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,angle,rect.color);
      drawRotatedRect(rect.coordinate.x,rect.coordinate.y,rect.area.w,rect.area.h,angle,rect.color);
      break;
    }
}
void SEDHOM_Basic_Shapes::Image_Single_Color(Image_Data_t image)
{
    // Draw_Image_one_color(image.coordinate.x,image.coordinate.y,image.image,image.area.w,image.area.h,image.color);
    drawBitmap(image.coordinate.x,image.coordinate.y,image.image,image.area.w,image.area.h,image.color);
}
void SEDHOM_Basic_Shapes::Image_RGB(Image_RGB_Data_t image)
{
    // Draw_Image_RGB(image.coordinate.x,image.coordinate.y,image.image,image.area.w,image.area.h);
    drawRGBBitmap(image.coordinate.x,image.coordinate.y,image.image,image.area.w,image.area.h);
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
    //   Fill_Circle(circle.coordinate.x,circle.coordinate.y,circle.Radius,circle.color);
      fillCircle(circle.coordinate.x,circle.coordinate.y,circle.Radius,circle.color);
      break;
    case Shape_Draw:
      drawCircle(circle.coordinate.x,circle.coordinate.y,circle.Radius,circle.color);
      break;
    }
}      
void SEDHOM_Basic_Shapes::Triangle(Triangle_Data_t tri)
{
    switch (tri.Filled)
    {
    case Shape_Fill:
    //   Fill_Triangle(tri.coordinate_Point_1.x,tri.coordinate_Point_1.y,tri.coordinate_Point_2.x,tri.coordinate_Point_2.y,tri.coordinate_Point_3.x,tri.coordinate_Point_3.y,tri.color);
      fillTriangle(tri.coordinate_Point_1.x,tri.coordinate_Point_1.y,tri.coordinate_Point_2.x,tri.coordinate_Point_2.y,tri.coordinate_Point_3.x,tri.coordinate_Point_3.y,tri.color);
      break;
    case Shape_Draw:
    //   Draw_Triangle(tri.coordinate_Point_1.x,tri.coordinate_Point_1.y,tri.coordinate_Point_2.x,tri.coordinate_Point_2.y,tri.coordinate_Point_3.x,tri.coordinate_Point_3.y,tri.color);
      drawTriangle(tri.coordinate_Point_1.x,tri.coordinate_Point_1.y,tri.coordinate_Point_2.x,tri.coordinate_Point_2.y,tri.coordinate_Point_3.x,tri.coordinate_Point_3.y,tri.color);
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
  float height  = tri.length * sqrt(3) / 2.0 ; 

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
void SEDHOM_Basic_Shapes::Pie(Pie_Data_t pie)
{
    if (pie.Radius <= 0) return;
    int16_t x0 = pie.coordinate.x;
    int16_t y0 = pie.coordinate.y;
    int16_t r = pie.Radius;
    uint8_t corners = (pie.corners == 0) ? 0x0F : pie.corners;
    switch (pie.Filled)
    {
    case Shape_Fill:
        fillCircleHelper(x0, y0, r, corners, 0, pie.color);
        break;
    case Shape_Draw:
        drawCircleHelper(x0, y0, r, corners, pie.color);
        break;
    }
}
void SEDHOM_Basic_Shapes::Ellipse(Ellipse_Data_t ellipse)
{
    switch (ellipse.Filled)
    {
    case Shape_Fill:
        fillEllipse(ellipse.coordinate.x,ellipse.coordinate.y,ellipse.Radius.w,ellipse.Radius.h,ellipse.color);
        break;
        case Shape_Draw:
        drawEllipse(ellipse.coordinate.x,ellipse.coordinate.y,ellipse.Radius.w,ellipse.Radius.h,ellipse.color);
        break;
    }
}
void SEDHOM_Basic_Shapes::QRCode(QRCode_Data_t qr)
{
  drawQRCode(qr.coordinate.x,qr.coordinate.y,qr.content.c_str(),qr.scale,qr.Background_color,qr.foreground_color);
}
void SEDHOM_Basic_Shapes::BarCode(BarCode_Data_t bar)
{
  BarcodeType type_barcode = BarcodeType::Unknown;
  switch (bar.type)
  {
  case Barcode_Type_Unknown:
    type_barcode = BarcodeType::Unknown;
    break;
  case Barcode_Type_EAN13:
    type_barcode = BarcodeType::EAN13;
    break;
  case Barcode_Type_EAN8:
    type_barcode = BarcodeType::EAN8;
    break;
  case Barcode_Type_UPCA:
    type_barcode = BarcodeType::UPCA;
    break;
  case Barcode_Type_UPCE:
    type_barcode = BarcodeType::UPCE;
    break;
  
  default:
      type_barcode = BarcodeType::Unknown;
    break;
  }
  drawBarcode(bar.coordinate.x,bar.coordinate.y,bar.content.c_str(),bar.height,type_barcode,bar.scale,bar.show_digit,bar.Background_color,bar.foreground_color);
}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#endif // !SEDHOM_BASIC_SHAPES_H_