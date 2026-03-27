#ifndef SEDHOM_DISPLAY_OS_H_
#define SEDHOM_DISPLAY_OS_H_
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// include data types file to make easy to change data types
#include "SEDHOM_Data_Types.h"
// include icons file to draw icon and widgets
#include "SEDHOM_Icons.h"
// include widgets file to draw widgets
#include "SEDHOM_Widgets.h"
// include touch file
#include "SEDHOM_Display_Touch.h"
// include SD Lib
#include "SEDHOM_SD_Card.h"
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
// include arabic fonts file to use arabic fonts in your projects
#include "SEDHOM_Arabic_Font.h"
// include communications file to use communication protocols in your projects
#include "SEDHOM_Comminucations.h"
// include Animation file to use actions in your projects
#include "SEDHOM_Animations.h"
// include math file to use math equations in your projects
#include "SEDHOM_Math.h"
// include rotation file to use rotate methods in your projects
#include "SEDHOM_Rotations.h"
// include controls file to use Buttons in your projects
#include "SEDHOM_Controls.h"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class SEDHOM_Display_OS
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
    // define all variables
    Color_t Night_mode = Night_Mode ;
    Color_t Light_mode = Light_Mode ;
    ROTATION_STATUS_t Rotate_0 = Rotate_0_Degree;
    ROTATION_STATUS_t Rotate_90 = Rotate_90_Degree;
    ROTATION_STATUS_t Rotate_180 = Rotate_180_Degree;
    ROTATION_STATUS_t Rotate_270 = Rotate_270_Degree;
};
class SEDHOM_Shapes_OS : public SEDHOM_Basic_Shapes
{
  public:
    SEDHOM_Shapes_OS(SEDHOM_Display_OS & OS)
    {
    }

};
class SEDHOM_Text_OS : public SEDHOM_Text
{
  public:
    SEDHOM_Text_OS(SEDHOM_Display_OS & OS)
    {
    }

};
class SEDHOM_Colors_OS : public SEDHOM_Colors
{
  public:
    SEDHOM_Colors_OS(SEDHOM_Display_OS & OS)
    {
    }

};
class SEDHOM_Effects_OS : public SEDHOM_Effects
{
  public:
    SEDHOM_Effects_OS(SEDHOM_Display_OS & OS)
    {
    }

};
class SEDHOM_Icon_OS : public SEDHOM_Icons
{
private:
  
public:
  SEDHOM_Icon_OS(SEDHOM_Display_OS & OS)
  {
    SEDHOM_Icons::Set_Mode(OS.Mode());
  }
};
class SEDHOM_Windows_OS : public SEDHOM_Windows
{
private:
public:
  SEDHOM_Windows_OS(SEDHOM_Display_OS & OS)
  {
   SEDHOM_Windows::set_windows_mode(OS.Mode());
  }

};
class SEDHOM_Pages_OS : public SEDHOM_Pages
{
  private:
  public:
    SEDHOM_Pages_OS(SEDHOM_Display_OS & OS)
    {
      SEDHOM_Pages::set_Pages_mode(OS.Mode());
    }
};
class SEDHOM_Communications_OS : public SEDHOM_Communications_UART
{
private:
public:
  SEDHOM_Communications_OS(SEDHOM_Display_OS & OS)
  {

  }
};
class SEDHOM_Time_OS : public SEDHOM_Time
{
private:
public:
  SEDHOM_Time_OS(SEDHOM_Display_OS & OS)
  {
    // Time.set_time_mode(OS.Mode());
  }
};
class SEDHOM_Data_Structure_OS : public Stack<int>, public Queue<int>, public LinkedList<int>
{
private:
public:
  SEDHOM_Data_Structure_OS(SEDHOM_Display_OS & OS)
  {
    // Stack.set_stack_mode(OS.Mode());
    // Queue.set_queue_mode(OS.Mode());
  }
  // Stack<int> Stack;
  // Queue<int> Queue;
  // LinkedList<int> LinkedList;
};
class SEDHOM_Touch_OS : public SEDHOM_Touch
{
private:
public:
  SEDHOM_Touch_OS(SEDHOM_Display_OS & OS)
  {
    // Touch.set_touch_mode(OS.Mode());
  }
};
class SEDHOM_SD_Card_OS : public SEDHOM_SD_Card
{
private:
public:
  SEDHOM_SD_Card_OS(SEDHOM_Display_OS & OS)
  {
    // SD_Card.set_sd_card_mode(OS.Mode());
  }
};
class SEDHOM_Handling_Pages_OS : public SEDHOM_Handling_Pages
{
private:
public:
  SEDHOM_Handling_Pages_OS(SEDHOM_Display_OS & OS)
  {
    // Handle_page.set_handling_pages_mode(OS.Mode());
  }
};
class SEDHOM_Widgets_OS : public SEDHOM_Widgets
{
  private:
  public:
    SEDHOM_Widgets_OS(SEDHOM_Display_OS & OS)
    {
      SEDHOM_Widgets::set_widgets_mode(OS.Mode());
    }
};
class SEDHOM_Animations_OS : public SEDHOM_Animations
{
  private:
  public:
  SEDHOM_Animations_OS(SEDHOM_Display_OS & OS)
  {
    // SEDHOM_Animations::set_widgets_mode(OS.Mode());
  }

};
class SEDHOM_Math_OS : public SEDHOM_Math
{
public:
  SEDHOM_Math_OS()
  : SEDHOM_Math({SEDHOM_Display_OS::Screen_Width(), SEDHOM_Display_OS::Screen_Height()})
  {
  }

  SEDHOM_Math_OS(SEDHOM_Display_OS & OS)
  : SEDHOM_Math({SEDHOM_Display_OS::Screen_Width(), SEDHOM_Display_OS::Screen_Height()})
  {
  }
};
class SEDHOM_Rotation_OS : public SEDHOM_Rotations
{
private:
public:
  SEDHOM_Rotation_OS()
  {

  }
  SEDHOM_Rotation_OS(SEDHOM_Display_OS & OS)
  {

  }
};
class SEDHOM_Control_OS : public SEDHOM_Controls , public Button
{
private:
  /* data */
public:
  SEDHOM_Control_OS(SEDHOM_Display_OS & OS)
  {

  }
};




























//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// define all functions
void SEDHOM_Display_OS::Init_OS(ROTATION_STATUS_t Rotate,Color_t Mode)
{
  init_Screen(Rotate);
  OS_Mode = Mode;
  Set_Device_Mode(Mode);
  SEDHOM_Icon_OS::Text_C({0,0},FONT_BIG,0," ");
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
    return Screen_height ;
}
int SEDHOM_Display_OS::Screen_Width()
{
    return Screen_width;
}
Color_t SEDHOM_Display_OS::Mode()
{
  return OS_Mode;
}
Color_t SEDHOM_Display_OS::Not_Mode()
{
  if(OS_Mode == BLACK) return WHITE;
  else return BLACK;

}
void SEDHOM_Display_OS::Fill_Screen(Color_t color)
{
  SEDHOM_Basic_Shapes::Rectangle({
      {0,0},
      {Screen_Height(),Screen_Width()},
      0,
      Shape_Fill,
      color
  });
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#endif /*SEDHOM_DISPLAY_OS_H_*/