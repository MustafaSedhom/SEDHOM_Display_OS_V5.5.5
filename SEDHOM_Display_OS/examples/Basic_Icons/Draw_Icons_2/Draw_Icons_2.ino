//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
SEDHOM_Display_OS  OS;
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Dark_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  OS.Icon.label_Icon(380,150,50,30,5,"11",GREEN,BLUE,OS.Mode());
  OS.Icon.slide_Icon(10,20,150,44,BLUE,MAGENTA,CYAN,GREEN,RED);
  // OS.Icon.file_Icon(250,20,OS.Not_Mode(),OS.Mode(),BLUE,"py",OS.Mode());
  OS.Icon.file_Icon(250,20,OS.Mode(),Yellow,OS.Not_Mode(),"py",OS.Mode());
  OS.Icon.folder_Icon(360,220,CYAN);
  OS.Icon.Divider_vertical(10,70,150,3,GREEN);
  OS.Icon.Color_Icon(330,15);
  OS.Icon.Time_Icon(420,50,YELLOW,OS.Mode());
  OS.Icon.Date_Icon(320,100,GREEN,OS.Mode());
  OS.Icon.ID_Card_Icon(20,100,OS.Mode(),OS.Not_Mode(),RED,CYAN,true,false,false,"Mustaf sedhom","Science","Mathemitic &","Copmuter scince","22/2/2006","+201144962908");
}
void loop() 
{
}
