//=======================================================================================
// include OS lib from SEDHOM company
#include <SEDHOM_Display_OS.h>
// object from library
SEDHOM_Display_OS OS;
// var for touch
int last_x,last_y; 
void SEDHOM_Draw_Full_Calculator();
void print_on_calc(String op,bool refresh = no ,bool is_result = no,String result = "error");
void setup()
{
  OS.Init_Screen(Rotate_90_Degree,Night_Mode);
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  SEDHOM_Draw_Full_Calculator();
  print_on_calc("3*5",yes,yes,calc_exp("3*5"));
  ///////////////////////////////////////////////////////////////////////////////////////////////////
}
void loop() 
{
   if(OS.Touch.Is_Presssed())
   {
      int x = OS.Touch.get_X_point();
      int y = OS.Touch.get_Y_point();
      if(x != last_x || y != last_y)
      {
        ////////////////////////
        ////////////////////////
        last_x = x;
        last_y = y;
      }
   }
   OS.Time.Stop_Display(100); // micro seconds
}

String calc_exp(String op)
{
  int op_index = -1;
  char oper;
  for (int i = 0; i < op.length(); i++)
  {
    if (op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/')
    {
      op_index = i;
      oper = op[i];
      break;
    }
  }

  if (op_index == -1) return "error";

  float num1 = op.substring(0, op_index).toFloat();
  float num2 = op.substring(op_index + 1).toFloat();

  float result = 0;

  switch (oper)
  {
    case '+': result = num1 + num2; break;
    case '-': result = num1 - num2; break;
    case '*': result = num1 * num2; break;
    case '/':
      if (num2 != 0)
        result = num1 / num2;
      else
      {
       return "error";
        return;
      }
      break;
  }
  return String(result);
}

void print_on_calc(String op,bool refresh,bool is_result,String result)
{
  if(refresh)
  {
    OS.Icon.Container(10,20,460,50,20,Cyan);
    OS.Icon.Container(10+3,20+3,460-6,50-6,20,OS.Mode());
  }
  OS.Icon.Text_cpp(25,52,FONT_BIG,RED,is_result ? (op + " = " + result) : (op));
}

void SEDHOM_Draw_Full_Calculator()
{
  #define color_calc      orange
  #define numbers_color   Blue
  #define sines_color     magenta
  #define Basic_op        RED
  #define equal_color     RED
  String col_1[] = { "sin","cos","tan","sinh","cosh","tanh","asin","acos" };
  String col_2[] = { "7","8","9","/","(",")","log","ln" };
  String col_3[] = { "4","5","6","*","^2","!","R","|x|" };
  String col_4[] = { "1","2","3","-","~","&","|","^" };
  String col_5[] = { "0",".","PI","+","e","C","<-","=" };
  OS.Fill_Screen(OS.Mode());
  OS.Icon.Text_cpp(15,10,FONT_BIG,OS.Not_Mode(),"SEDHOM Scientific Calculator");
  // textfeild for input calc and ouput result
  // OS.Icon.Container(10,20,460,50,20,Cyan);
  // OS.Icon.Container(10+3,20+3,460-6,50-6,20,OS.Mode());
  print_on_calc("",yes);

  for(int i=0;i<8;i++)
  {
    OS.Icon.Container(4+(i*60),80,53,40,5,sines_color);OS.Icon.Text_cpp(15+(i*60),105,FONT_SMALL,OS.Not_Mode(),col_1[i]);
    OS.Icon.Container(4+(i*60),130,53,40,5,(i<3)?numbers_color:(i==3)?Basic_op:color_calc);OS.Icon.Text_cpp(20+(i*60),155,(i>=6)?FONT_SMALL:FONT_BIG,OS.Not_Mode(),col_2[i]);
    OS.Icon.Container(4+(i*60),180,53,40,5,(i<3)?numbers_color:(i==3)?Basic_op:color_calc);OS.Icon.Text_cpp((i==7)?8+(i*60):20+(i*60),205,FONT_BIG,OS.Not_Mode(),col_3[i]);
    OS.Icon.Container(4+(i*60),230,53,40,5,(i<3)?numbers_color:(i==3)?Basic_op:color_calc);OS.Icon.Text_cpp(20+(i*60),255,FONT_BIG,OS.Not_Mode(),col_4[i]);
    OS.Icon.Container(4+(i*60),280,53,40,5,(i<3)?numbers_color:(i==3)?Basic_op:(i==7)?equal_color:color_calc);OS.Icon.Text_cpp(20+(i*60),305,FONT_BIG,OS.Not_Mode(),col_5[i]);    
  }
}









