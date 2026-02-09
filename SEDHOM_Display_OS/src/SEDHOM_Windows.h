#ifndef SEDHOM_WINDOWS_H_
#define SEDHOM_WINDOWS_H_
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include "SEDHOM_Icons_And_Widgets.h"
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
    //#########################################################################################################################################
              // keyboard varbiles
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
                word_t fourth_line_speciial  [10] = { " " ," "," ","<",">","?"," "," "," "," "}; 
                bool caps_or_not = true;
                bool special_char_or_not = false;
                Color_t Full_KeyBoard_window_color;
                // variables for windows handling
                char full_key_board_text[50] = "";
                int index_char_in_text = 0;
                void refresh_full_key_board_text(bool var_or_not = 0,string_t str = "")
                {
                  Icon.fill_Rectangle(85,8,50,380,20,Icon.Not_Mode());
                  Icon.fill_Rectangle(85+3,8+3,50-6,380-6,20,Icon.Mode());
                  // text input
                  Icon.TEXT(92,40,FONT_BIG,Full_KeyBoard_window_color,var_or_not ? str : full_key_board_text);
                }
      public:
                String Full_KeyBoard_window_user_input_TXT = "";
                //drawing window functions 
                void Full_Key_Board_Window(Color_t color,bool caps_or_not=true,bool special_char_or_not=false);
                // handling touch functions for windows
                bool Handling_Touch_Full_Key_Board_Window();
                /////////////////////////////////////////////////////////////
    void set_windows_mode(Color_t mode)
    {
      Icon.Set_Mode(mode);
    }
    //#########################################################################################################################################

    //#########################################################################################################################################
};
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// define all functions for drawing windows
void SEDHOM_Windows::Full_Key_Board_Window(Color_t color,bool caps_or_not=true,bool special_char_or_not=false)
{
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // special_char_or_not = true;
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // settings of window
  #define max_char_in_line      10
  #define char_color            Icon.Not_Mode()
  #define first_line_special    first_line_capital    
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  Full_KeyBoard_window_color = color;
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //Draw back arrow and text feild
  Icon.Back_Arrow_Icon(20,30,RED,Icon.Not_Mode());
  if(index_char_in_text == 0)
  {
    Icon.fill_Rectangle(85,8,50,380,20,Icon.Not_Mode());
    Icon.fill_Rectangle(85+3,8+3,50-6,380-6,20,Icon.Mode());
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // draw rectangle of char
  for(int i=0;i < max_char_in_line;i++)
  {
    Icon.fill_Rectangle(11+(46*i),70,40,40,5,color); Icon.TEXT(11+(46*i)+10,70+27,FONT_BIG,char_color,special_char_or_not ? first_line_special[i] : (caps_or_not ? first_line_capital[i] : first_line_small[i]));
    Icon.fill_Rectangle(11+(46*i),116,40,40,5,color); Icon.TEXT(11+(46*i)+10,116+27,FONT_BIG,char_color,special_char_or_not ? Second_line_special[i] : (caps_or_not ? Second_line_capital[i] : Second_line_small[i]));
    if(i==9)break;
    Icon.fill_Rectangle(11+(46*i),162,40,40,5,color); Icon.TEXT(11+(46*i)+10,162+27,FONT_BIG,char_color,special_char_or_not ? third_line_special[i] : (caps_or_not ? third_line_capital[i] : third_line_small[i]));
    Icon.fill_Rectangle(11+(46*i),208,40,40,5,color); Icon.TEXT(11+(46*i)+10,208+27,FONT_BIG,char_color,special_char_or_not ? fourth_line_speciial[i] : (caps_or_not ? fourth_line_capital[i] : fourth_line_small[i]));
    if(special_char_or_not) { if(i==1||i==2||i==6||i==7) { Icon.fill_Rectangle(11+(46*i),208,40,40,5,Icon.Mode()); } }
  }
  // draw special buttons
      // caps button
      Icon.fill_Rectangle(11,208,60,40,5,color);
      Icon.fill_Rectangle(11,255,40,85,5,color);
      Icon.TEXT(22,280,FONT_BIG,char_color,"Caps");
      // draw special char button
      Icon.fill_Rectangle(104,255,40,85,5,color);
      Icon.TEXT(130,280,FONT_BIG,char_color,"$?");
      // draw space button
      Icon.fill_Rectangle(195,255,40,130,5,color);
      Icon.TEXT(220,280,FONT_BIG,char_color,"Space");
      // draw Done button
      Icon.fill_Rectangle(332,255,40,130,5,color);
      Icon.TEXT(365,280,FONT_BIG,char_color,"Done");
      // return button
      Icon.fill_Rectangle(424,163,52,39,5,color);
      Icon.fill_Rectangle(378,209,40,85,5,color);
      Icon.TEXT(400,235,FONT_BIG,char_color,"<--");
}

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// define handling touch of function
bool SEDHOM_Windows::Handling_Touch_Full_Key_Board_Window()
{
  if(Touch.Is_Presssed())
  {
    if(index_char_in_text > 22)
    {
      index_char_in_text = 0;
      refresh_full_key_board_text(true,"");
    }

    for (int i = 0; i < 10; i++)
    {
      if(Touch.onTap(11,208,60,40)||Touch.onTap(11,255,80,40)) // caps lock
      {
        caps_or_not = !caps_or_not;
        Full_Key_Board_Window(Full_KeyBoard_window_color,caps_or_not,special_char_or_not);

      }
      if(Touch.onTap(104,255,85,40)) // special char
      {
        special_char_or_not = !special_char_or_not;
        Full_Key_Board_Window(Full_KeyBoard_window_color,caps_or_not,special_char_or_not);
      }
      if(Touch.onTap(195,255,135,40)) // space
      {
        full_key_board_text[index_char_in_text++] = ' ';
        //Draw back arrow and text feild
        refresh_full_key_board_text();
      }
      if(Touch.onTap(332,255,135,40)) // done
      {
        Full_KeyBoard_window_user_input_TXT = String(full_key_board_text);
        return true;
      }
      if (Touch.onTap(424,163,39,52) || Touch.onTap(378,209,85,40)) // return button
      {
        if(index_char_in_text > 0)
        {
          full_key_board_text[--index_char_in_text] = '\0';
          //Draw back arrow and text feild
         refresh_full_key_board_text();
        }
      }  
      if (Touch.onTap(20,30,30,30)) // back arrow
      {
        return false;
      }
      ///////////////////////////////////////////////////////////////////////////
      if(Touch.onTap(11+(46*i),70,40,40))
      {
        full_key_board_text[index_char_in_text++] = special_char_or_not ? first_line_capital[i][0] : (caps_or_not ? first_line_capital[i][0] : first_line_small[i][0]);
        //Draw back arrow and text feild
        refresh_full_key_board_text();
      }
      else if(Touch.onTap(11+(46*i),116,40,40))
      {
        full_key_board_text[index_char_in_text++] = special_char_or_not ? Second_line_special[i][0] : (caps_or_not ? Second_line_capital[i][0] : Second_line_small[i][0]);
        //Draw back arrow and text feild
        refresh_full_key_board_text();
      }
      else if(Touch.onTap(11+(46*i),162,40,30))
      {
        if(i == 9) break;
        full_key_board_text[index_char_in_text++] = special_char_or_not ? third_line_special[i][0] : (caps_or_not ? third_line_capital[i][0] : third_line_small[i][0]);
        //Draw back arrow and text feild
         refresh_full_key_board_text();
      }
      else if(Touch.onTap(11+(46*i),208,40,30))
      {
        if(i == 0||i==8||i==9) { break; }
        if(special_char_or_not && (i==1||i==2||i==6||i==7)) { break; }
        full_key_board_text[index_char_in_text++] = special_char_or_not ? fourth_line_speciial[i][0] : (caps_or_not ? fourth_line_capital[i][0] : fourth_line_small[i][0]);
        //Draw back arrow and text feild
        refresh_full_key_board_text();
      }
    }
    return false;
  }
}



//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#endif // !SEDHOM_WINDOWS_H_