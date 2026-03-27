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
Button_Data_t my_Button(
    false, // init_state
    Shape_Circle,  // shape_type
    {},  // rectangle off
    {},  // rectangle on
    {{100,100},30,Shape_Fill,Color_Red},   // circle off
    {{100,100},30,Shape_Fill,Color_Blue}   // circle on
);
Button btn(my_Button);
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
    btn.Single_Press([](){
    Icons.Rectangle({{20,20},{30,30},10,Shape_Fill,(!my_Button.state) ? Color_Green : Color_DarkGrey}); 
    my_Button.state = !my_Button.state; 
    }).Update(my_Button);
}
//======================================================================================= 
