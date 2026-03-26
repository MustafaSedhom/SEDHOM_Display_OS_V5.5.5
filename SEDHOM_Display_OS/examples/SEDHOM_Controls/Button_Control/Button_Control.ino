//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
//=======================================================================================
// object from library
SEDHOM_Display_OS OS;
// SEDHOM_Math_OS Math(OS);
SEDHOM_Icon_OS Icons(OS);
// SEDHOM_Widgets_OS Widgets(OS);
// SEDHOM_Windows_OS Windows(OS);
// SEDHOM_Pages_OS Pages(OS);
// SEDHOM_Handling_Pages_OS Handling_pages(OS);
// SEDHOM_Data_Structure_OS Handling_Data(OS);
// SEDHOM_Touch_OS Touch(OS);
// SEDHOM_Time_OS Time(OS);
// SEDHOM_Communications_OS Call(OS);
// SEDHOM_Animations_OS Animates(OS);
SEDHOM_Control_OS Control(OS);
//=======================================================================================
Rectangle_Data_t rect_off_1 = {{100,100},{50,50},10,Shape_Fill,Color_Red};
Rectangle_Data_t rect_on_1  = {{100,100},{50,50},10,Shape_Fill,Color_Green};
Rectangle_Data_t rect_off_2 = {{300,100},{50,50},10,Shape_Fill,Color_Red};
Rectangle_Data_t rect_on_2  = {{300,100},{50,50},10,Shape_Fill,Color_Green};
Circle_Data_t circ_off_1 = {{130,200},30,Shape_Fill,Color_Red};
Circle_Data_t circ_on_1  = {{130,200},30,Shape_Fill,Color_Blue};
Circle_Data_t circ_off_2 = {{330,200},30,Shape_Fill,Color_Red};
Circle_Data_t circ_on_2  = {{330,200},30,Shape_Fill,Color_Blue};

bool s1 = false;
bool s2 = false;
bool s3 = false;
bool s4 = false;
//======================================================================================= 
void setup()
{
  ///////////////////////////////////////////////////////////////////////////////////////
  OS.Init_OS(OS.Rotate_90,OS.Night_mode);
  // OS.Set_Device_Mode(Light_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////
}
//======================================================================================= 
void loop() 
{
  Control.Button_Control(&s1,rect_off_1,rect_on_1,[](){
    Icons.Rectangle({{10,10},{10,10},3,Shape_Fill,((!s1)?Color_Green:Color_DarkGrey)}); 
    s1 = !s1;
  });
  Control.Button_Control(&s2,rect_off_2,rect_on_2,[](){
    Icons.Rectangle({{50,10},{10,10},3,Shape_Fill,((!s2)?Color_Green:Color_DarkGrey)}); 
    s2 = !s2;
  });
  Control.Button_Control(&s3,circ_off_1,circ_on_1,[](){
    Icons.Rectangle({{100,10},{10,10},3,Shape_Fill,((!s3)?Color_Green:Color_DarkGrey)}); 
    s3 = !s3;
  });
  Control.Button_Control(&s4,circ_off_2,circ_on_2,[](){
    Icons.Rectangle({{150,10},{10,10},3,Shape_Fill,((!s4)?Color_Green:Color_DarkGrey)}); 
    s4 = !s4;
  });
}
//======================================================================================= 





