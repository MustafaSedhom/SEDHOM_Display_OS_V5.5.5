#ifndef SEDHOM_WINDOWS_H_
#define SEDHOM_WINDOWS_H_
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include "SEDHOM_Icons.h"
#include "SEDHOM_Widgets.h"
#include "SEDHOM_Display_Touch.h"
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
class SEDHOM_Windows
{
  private:
    // make object to use icons functions
    SEDHOM_Icons Icon;
    // make object to use touch functions
    SEDHOM_Touch Touch;
    // variables for windows handling

    //#########################################################################################################################################
    // keyboard variables
      // array of capital litters
      word_t first_line_capital    [10] = { "!","@","#","$","%","^","&","*","(",")" };
      word_t Second_line_capital   [10] = { "Q","W","E","R","T","Y","U","I","O","P" };
      word_t third_line_capital    [10] = { "A","S","D","F","G","H","J","K","L", " " };
      word_t fourth_line_capital   [10] = { " ","Z","X","C","V","B","N","M", " ", " " };
      // array of small litters
      word_t first_line_small      [10] = { "0","1","2","3","4","5","6","7","8","9" };
      word_t Second_line_small     [10] = { "q","w","e","r","t","y","u","i","o","p" };
      word_t third_line_small      [10] = { "a","s","d","f","g","h","j","k","l", " " };
      word_t fourth_line_small     [10] = { " ","z","x","c","v","b","n","m", " ", " " };
      // array of special character
      word_t Second_line_special   [10] = { "`","~","-","_","=","+","[","]","{","}" };
      word_t third_line_special    [10] = { "\\","|",":",";","\"","\"",",",".","/"  };
      word_t fourth_line_special  [10] = { " " ," "," ","<",">","?"," "," "," "," "}; 
      bool caps_or_not = true;
      bool special_char_or_not = false;
      Color_t Full_KeyBoard_window_color = GREEN;
      Color_t Full_KeyBoard_Text_feild_color = RED;
      Color_t Color_Background_full_keyboard = BLACK;
      Color_t Color_not_Background_full_keyboard = White;
      Color_t Color_char_full_keyboard = Cyan;
      // variables for windows handling
      char full_key_board_Text[50] = "";
      int index_char_in_Text = 0;
      void refresh_full_key_board_Text(bool var_or_not = 0,string_t str = "")
      {
        Icon.Rectangle({{85,8},{50,380},20,Shape_Fill,Color_not_Background_full_keyboard});
        Icon.Rectangle({{85+3,8+3},{50-6,380-6},20,Shape_Fill,Color_Background_full_keyboard});
        // Text input
        Icon.Text_C({92,40},FONT_BIG,Full_KeyBoard_Text_feild_color,var_or_not ? str : full_key_board_Text);
      }
    public:
      void set_windows_mode(Color_t mode = Color_Black);
      String Full_KeyBoard_window_user_input_TXT = "";
      //drawing window functions 
      void Full_Key_Board_Window(Color_t color = Color_Blue,Color_t Background = Color_Black,Color_t char_color = WHITE,Color_t Text_feild_color = -1,bool caps_or_not=true,bool special_char_or_not=false);
      // handling touch functions for windows
      bool Handling_Touch_Full_Key_Board_Window();
    //#########################################################################################################################################
};
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// define all functions for drawing windows
void SEDHOM_Windows::set_windows_mode(Color_t mode = Color_Black)
{
  Icon.Set_Mode(mode);
}
void SEDHOM_Windows::Full_Key_Board_Window(Color_t color,Color_t Background,Color_t char_color ,Color_t Text_feild_color ,bool caps_or_not,bool special_char_or_not)
{
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // special_char_or_not = true;
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // settings of window
  #define max_char_in_line      10
  #define first_line_special    first_line_capital    
  if(Text_feild_color == -1) Text_feild_color = color;
  if(Background == BLACK) Color_not_Background_full_keyboard = WHITE;
  else Color_not_Background_full_keyboard = BLACK;
  Color_Background_full_keyboard = Background;
  Full_KeyBoard_Text_feild_color = Text_feild_color;
  Color_char_full_keyboard = char_color;
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  Full_KeyBoard_window_color = color;
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //Draw back arrow and Text feild
  Icon.Arrow_Icon({20,30,RED,Color_not_Background_full_keyboard},Direction_Right,(Background == Color_Black) ? Color_White : Color_Black);
  if(index_char_in_Text == 0)
  {
    Icon.Rectangle({{85,8},{380,50},20,Shape_Fill,Color_not_Background_full_keyboard});
    Icon.Rectangle({{85+3,8+3},{380-6,50-6},20,Shape_Fill,Background});
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // draw rectangle of char
  for(int i=0;i < max_char_in_line;i++)
  {
    Icon.Rectangle({{11+(46*i),70},{40,40},5,Shape_Fill,color}); Icon.Text_C({11+(46*i)+10,70+27},FONT_BIG,char_color,special_char_or_not ? first_line_special[i] : (caps_or_not ? first_line_capital[i] : first_line_small[i]));
    Icon.Rectangle({{11+(46*i),116},{40,40},5,Shape_Fill,color}); Icon.Text_C({11+(46*i)+10,116+27},FONT_BIG,char_color,special_char_or_not ? Second_line_special[i] : (caps_or_not ? Second_line_capital[i] : Second_line_small[i]));
    if(i==9)break;
    Icon.Rectangle({{11+(46*i),162},{40,40},5,Shape_Fill,color}); Icon.Text_C({11+(46*i)+10,162+27},FONT_BIG,char_color,special_char_or_not ? third_line_special[i] : (caps_or_not ? third_line_capital[i] : third_line_small[i]));
    Icon.Rectangle({{11+(46*i),208},{40,40},5,Shape_Fill,color}); Icon.Text_C({11+(46*i)+10,208+27},FONT_BIG,char_color,special_char_or_not ? fourth_line_special[i] : (caps_or_not ? fourth_line_capital[i] : fourth_line_small[i]));
    if(special_char_or_not) { if(i==1||i==2||i==6||i==7) { Icon.Rectangle({{11+(46*i),208},{40,40},5,Shape_Fill,Background}); } }
  }
  // draw special buttons
      // caps button
      Icon.Rectangle({{11,208},{40,60},5,Shape_Fill,color});
      Icon.Rectangle({{11,255},{85,40},5,Shape_Fill,color});
      Icon.Text_C({22,280},FONT_BIG,char_color,"Caps");
      // draw special char button
      Icon.Rectangle({{104,255},{85,40},5,Shape_Fill,color});
      Icon.Text_C({130,280},FONT_BIG,char_color,"$?");
      // draw space button
      Icon.Rectangle({{195,255},{130,40},5,Shape_Fill,color});
      Icon.Text_C({220,280},FONT_BIG,char_color,"Space");
      // draw Done button
      Icon.Rectangle({{332,255},{130,40},5,Shape_Fill,color});
      Icon.Text_C({365,280},FONT_BIG,char_color,"Done");
      // return button
      Icon.Rectangle({{424,163},{39,52},5,Shape_Fill,color});
      Icon.Rectangle({{378,209},{85,40},5,Shape_Fill,color});
      Icon.Text_C({400,235},FONT_BIG,char_color,"<--");
}

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// define handling touch of function
bool SEDHOM_Windows::Handling_Touch_Full_Key_Board_Window()
{
  // if(Touch.Is_Pressed())
  // {
  //   if(index_char_in_Text > 22)
  //   {
  //     index_char_in_Text = 0;
  //     refresh_full_key_board_Text(true,"");
  //   }

  //   for (int i = 0; i < 10; i++)
  //   {
  //     if(Touch.onTap({{11,208},{60,40}})||Touch.onTap({{11,255},{80,40}})) // caps lock
  //     {
  //       caps_or_not = !caps_or_not;
  //       Full_Key_Board_Window(Full_KeyBoard_window_color,Color_Background_full_keyboard,Color_char_full_keyboard,Full_KeyBoard_Text_feild_color,caps_or_not,special_char_or_not);

  //     }
  //     if(Touch.onTap({{104,255},{85,40}})) // special char
  //     {
  //       special_char_or_not = !special_char_or_not;
  //       Full_Key_Board_Window(Full_KeyBoard_window_color,Color_Background_full_keyboard,Color_char_full_keyboard,Full_KeyBoard_Text_feild_color,caps_or_not,special_char_or_not);
  //     }
  //     if(Touch.onTap({{195,255},{135,40}})) // space
  //     {
  //       full_key_board_Text[index_char_in_Text++] = ' ';
  //       //Draw back arrow and Text feild
  //       refresh_full_key_board_Text();
  //     }
  //     if(Touch.onTap({{332,255},{135,40}})) // done
  //     {
  //       Full_KeyBoard_window_user_input_TXT = String(full_key_board_Text);
  //       return true;
  //     }
  //     if (Touch.onTap({{424,163},{39,52}}) || Touch.onTap({{378,209},{85,40}})) // return button
  //     {
  //       if(index_char_in_Text > 0)
  //       {
  //         full_key_board_Text[--index_char_in_Text] = '\0';
  //         //Draw back arrow and Text feild
  //        refresh_full_key_board_Text();
  //       }
  //     }  
  //     if (Touch.onTap({{20,30},{30,30}})) // back arrow
  //     {
  //       return false;
  //     }
  //     ///////////////////////////////////////////////////////////////////////////
  //     if(Touch.onTap({{11+(46*i),70},{40,40}}))
  //     {
  //       full_key_board_Text[index_char_in_Text++] = special_char_or_not ? first_line_capital[i][0] : (caps_or_not ? first_line_capital[i][0] : first_line_small[i][0]);
  //       //Draw back arrow and Text_feild
  //       refresh_full_key_board_Text();
  //     }
  //     else if(Touch.onTap({{11+(46*i),116},{40,40}}))
  //     {
  //       full_key_board_Text[index_char_in_Text++] = special_char_or_not ? Second_line_special[i][0] : (caps_or_not ? Second_line_capital[i][0] : Second_line_small[i][0]);
  //       //Draw back arrow and Text feild
  //       refresh_full_key_board_Text();
  //     }
  //     else if(Touch.onTap({{11+(46*i),162},{40,30}}))
  //     {
  //       if(i == 9) break;
  //       full_key_board_Text[index_char_in_Text++] = special_char_or_not ? third_line_special[i][0] : (caps_or_not ? third_line_capital[i][0] : third_line_small[i][0]);
  //       //Draw back arrow and Text feild
  //        refresh_full_key_board_Text();
  //     }
  //     else if(Touch.onTap({{11+(46*i),208},{40,30}}))
  //     {
  //       if(i == 0||i==8||i==9) { break; }
  //       if(special_char_or_not && (i==1||i==2||i==6||i==7)) { break; }
  //       full_key_board_Text[index_char_in_Text++] = special_char_or_not ? fourth_line_special[i][0] : (caps_or_not ? fourth_line_capital[i][0] : fourth_line_small[i][0]);
  //       //Draw back arrow and Text feild
  //       refresh_full_key_board_Text();
  //     }
  //   }
  //   return false;
  // }
}



//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif // !SEDHOM_WINDOWS_H_