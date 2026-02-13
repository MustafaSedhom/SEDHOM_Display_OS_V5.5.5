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
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Icons.label_Icon(380,150,50,30,5,"11",GREEN,BLUE,OS.Mode());
  Icons.slide_Icon(10,20,150,44,BLUE,MAGENTA,CYAN,GREEN,RED);
  // Icons.file_Icon(250,20,OS.Not_Mode(),OS.Mode(),BLUE,"py",OS.Mode());
  Icons.file_Icon(250,20,OS.Mode(),Yellow,OS.Not_Mode(),"py",OS.Mode());
  Icons.folder_Icon(360,220,CYAN);
  Icons.Divider_vertical(10,70,150,3,GREEN);
  Icons.Color_Icon(330,15);
  Icons.Time_Icon(420,50,YELLOW,OS.Mode());
  Icons.Date_Icon(320,100,GREEN,OS.Mode());
  Icons.ID_Card_Icon(20,100,OS.Mode(),OS.Not_Mode(),RED,CYAN,true,false,false,"Mustaf sedhom","Science","Mathemitic &","Copmuter scince","22/2/2006","+201144962908");
}
void loop() 
{
}
