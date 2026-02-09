//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
SEDHOM_Display_OS OS;
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Dark_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  OS.Icon.fill_Rectangle(200,250,50,90,10,RED);
  OS.Icon.TEXT(120,20,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"SEDHOM Display OS V4.4.4");
  OS.Icon.TEXT(100,220,FONT_FREESERIFBOLDITALIC_MEDIUM,CYAN,"Eng.Mustafa Sedhom");
  OS.Icon.fill_Circle(50,250,30,MAGENTA);
  OS.Icon.Container(150,70,70,70,0,BLUE);
  OS.Icon.fill_Triangle(50,50,50,100,100,20,GREEN);
  OS.Icon.fill_Right_Triangle(400,200,40,50,YELLOW);
  OS.Icon.draw_Line(100,230,320,230,WHITE);
}

void loop() 
{
}
