#ifndef SEDHOM_DISPLAY_OS_H_
#define SEDHOM_DISPLAY_OS_H_
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "SEDHOM_Display_Settings.h"
// include data types file to make easy to change data types
#include "SEDHOM_Data_Types.h"
// include icons file to draw icon and widgets
#include "SEDHOM_Icons.h"
// include widgets file to draw widgets
#include "SEDHOM_Widgets.h"
// include touch file
#include "SEDHOM_Display_Touch.h"
// include Time lib to calc time we OS run
#include "SEDHOM_Time.h"
// include Data structure file to use Stack and Queue in my projects
#include "SEDHOM_Data_Structure.h"
// include pages Handling file to handle user pages
#include "SEDHOM_Handlig_pages.h"
// include windows file to use sedhom_default_windows
#include "SEDHOM_Windows.h"
// include Page file to use sedhom_default_pages
#include "SEDHOM_pages.h"
// include colors file to use colors in your projects
#include "SEDHOM_Colors.h"
// include fonts file to use fonts in your projects
#include "SEDHOM_Display_Fonts.h"
// include Animation file to use actions in your projects
#include "SEDHOM_Animations.h"
// include math file to use math equations in your projects
#include "SEDHOM_Math.h"
// include rotation file to use rotate methods in your projects
#include "SEDHOM_Rotations.h"
// include controls file to use Buttons in your projects
#include "SEDHOM_Controls.h"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define API_SEDHOM_Name()           "SEDHOM"
#define API_SEDHOM_OS_Name()        "SEDHOM OS"
#define API_SEDHOM_OS_Version()     "5.5.5"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class SEDHOM_Display_OS : private SEDHOM_GUI_Core
{
  private:
  // SEDHOM_Icons Icon;
  Color_t OS_Mode;
  // my name is Mustafa SEDHOM i wrote this lib to make easy way to use TFT Display in embedded projects
  public:
    /// define all functions
    void Init_OS(ROTATION_STATUS_t Rotate = Rotate_90_Degree,Color_t Mode = Night_Mode);
    void Restart_OS();
    void Set_Device_Mode(Color_t Mode = Night_Mode);
    static int Screen_Height();
    static int Screen_Width();
    Color_t Mode();
    Color_t Not_Mode();
    void Fill_Screen(Color_t color = Night_Mode);
    String CPU_Type_OS();
    String CPU_Details_OS();
    String Mather_Board_Type_OS();
    String Mather_Board_Details_OS();
    String SEDHOM_OS_Version();
    String SEDHOM_OS_Name();
    // define all variables
    Color_t Night_mode = Night_Mode ;
    Color_t Light_mode = Light_Mode ;
    ROTATION_STATUS_t Rotate_0 = Rotate_0_Degree;
    ROTATION_STATUS_t Rotate_90 = Rotate_90_Degree;
    ROTATION_STATUS_t Rotate_180 = Rotate_180_Degree;
    ROTATION_STATUS_t Rotate_270 = Rotate_270_Degree;
};
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// define all functions
void SEDHOM_Display_OS::Init_OS(ROTATION_STATUS_t Rotate,Color_t Mode)
{
  API_Init_Screen();
  API_Set_Rotation(Rotate);
  OS_Mode = Mode;
  Set_Device_Mode(Mode);
  SEDHOM_Text::__Text_init_OS();
}
void SEDHOM_Display_OS::Restart_OS()
{
  Init_OS();
}
void SEDHOM_Display_OS::Set_Device_Mode(Color_t Mode)
{
  OS_Mode = Mode;
  Fill_Screen(OS_Mode);
}
int SEDHOM_Display_OS::Screen_Height()
{
    return API_Screen_height();
}
int SEDHOM_Display_OS::Screen_Width()
{
    return API_Screen_width();
}
Color_t SEDHOM_Display_OS::Mode()
{
  return OS_Mode;
}
Color_t SEDHOM_Display_OS::Not_Mode()
{
  if(OS_Mode == Color_Black) return Color_White;
  else return Color_Black;

}
void SEDHOM_Display_OS::Fill_Screen(Color_t color)
{
  fillScreen(color);
}
String SEDHOM_Display_OS::SEDHOM_OS_Name()
{
  return String(API_SEDHOM_OS_Name()) ;
}
String SEDHOM_Display_OS::SEDHOM_OS_Version()
{
  return String(API_SEDHOM_OS_Version()) ;
}
String SEDHOM_Display_OS::CPU_Type_OS()
{
  return String(API_MCU_Type_Name()) ;
}
String SEDHOM_Display_OS::CPU_Details_OS()
{
  return String(API_MCU_Type_Details()) ;
}
String SEDHOM_Display_OS::Mather_Board_Type_OS()
{
  return String(API_Board_Type_Name()) ;
}
String SEDHOM_Display_OS::Mather_Board_Details_OS()
{
  return String(API_Board_Type_Details()) ;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#endif /*SEDHOM_DISPLAY_OS_H_*/