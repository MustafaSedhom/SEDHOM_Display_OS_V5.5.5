//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Shapes_OS Shapes(OS);
SEDHOM_Text_OS Texts(OS);
// SEDHOM_Colors_OS colors(OS);
// SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
// SEDHOM_Effects_OS effect(OS);
// SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
// SEDHOM_Animations_OS Animates(OS);
//=======================================================================================
//=======================================================================================
void setup()
{
  OS.Init_OS(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  // Basic Shapes
  Shapes.Circle({{50,50},30,Shape_Fill,Color_Yellow});
  Shapes.Rectangle({{100,30},{100,50},20,Shape_Fill,Color_Blue});
  Shapes.Rectangle({{100,100},{100,50},0,Shape_Fill,Color_White});
  Shapes.Square({{220,30},60,10,Shape_Fill,Color_Green});
  Shapes.Triangle({{300,30},{360,70},{330,80},Shape_Fill,Color_Red});
  Shapes.Right_Triangle({400,30,Color_Cyan,OS.Mode()},{50,50},Shape_Fill);
  Shapes.Equilateral_Triangle({{50,130},50,Shape_Fill,Direction_Up,Color_Magenta});
  Shapes.Border_Rectangle({230,100,Color_Blue},{140,50},30,5);
  Shapes.Equilateral_Triangle({{420,115},50,Shape_Fill,Direction_Down,Color_Magenta});
  Shapes.Line({{30,170},{450,170},Color_Red});
  // Texts
  Texts.Text({40,200},FONT_FREESERIFBOLDITALIC_MEDIUM,Color_Magenta,"SEDHOM Company");
  Texts.Text({300,205},FONT_FREESERIFBOLDITALIC_MEDIUM,Color_White,"2222006");
  Texts.Text({40,240},FONT_FREESERIFBOLD_MEDIUM,Color_Green,"Eng.Mustafa Sedhom");
  Texts.Text({40,270},FONT_FREESERIFBOLD_MEDIUM,Color_Blue,"Embedded SW & HW Engineer");
  Texts.Text({40,300},FONT_FREESERIFBOLDITALIC_MEDIUM,Color_Yellow,"SEDHOM Display OS");
}
//=======================================================================================
void loop() 
{
}
//=======================================================================================



















