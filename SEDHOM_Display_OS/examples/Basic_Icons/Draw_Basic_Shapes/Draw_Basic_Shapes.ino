//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
// SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Communications_OS Call(OS);
//=======================================================================================
//=======================================================================================
void setup()
{
  OS.Init_Screen(OS.Rotate_90,OS.Night_mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  Icons.fill_Rectangle(200,250,50,90,10,RED);
  Icons.Text_C(120,20,FONT_FREEMONOBOLD_MEDIUM,MAGENTA,"SEDHOM Display OS V5.5.5");
  Icons.Text_C(100,220,FONT_FREESERIFBOLDITALIC_MEDIUM,CYAN,"Eng.Mustafa Sedhom");
  Icons.fill_Circle(50,250,30,MAGENTA);
  Icons.Container(150,70,70,70,0,BLUE);
  Icons.fill_Triangle(50,50,50,100,100,20,GREEN);
  Icons.fill_Right_Triangle(400,200,40,50,YELLOW);
  Icons.draw_Line(100,230,320,230,WHITE);
}
void loop() 
{
}
