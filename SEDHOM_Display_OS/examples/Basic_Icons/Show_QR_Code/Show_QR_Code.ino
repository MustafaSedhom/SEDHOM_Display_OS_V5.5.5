//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
SEDHOM_Display_OS OS;

void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Dark_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  OS.Icon.QRCode_Icon(5,5,5,Yellow,BLUE,5,"https://drive.google.com/drive/folders/16Hg8dgcBH3FalRkK8SDBWj2221bd8Fue?usp=sharing");
}
void loop() 
{
}
