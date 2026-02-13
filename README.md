
# ***SEDHOM Display OS***  
![Version](https://img.shields.io/badge/Version-5.5.5-green) &emsp;
![Platform](https://img.shields.io/badge/Platform-Arduino_IDE-blue) &emsp;
![Language](https://img.shields.io/badge/Language-C++-yellow)

# <img src="images/SEDHOM.jpg" width="30" style="border-radius:40%;"> ***SEDHOM Company***

by ***Eng.Mustafa Sedhom*** Embedded Software and Hardware Engineer

<img src="images/SEDHOM.jpg" width="600" style="border-radius:30%; border:2px solid #00000;">

#
## **about library**

### I draw all icons and widgets and pages by using circles & rectangles and triangles only i dont use any images or bitmap images this way make this library take small size .
### you can use this lib in 
- ### <img src="https://cdn.simpleicons.org/arduino" width="30"/>&emsp; Arduino IDE 
- ### <img src="https://cdn.simpleicons.org/platformio" width="30"/>&emsp; Platform IO

is new version of my Library you can use any tft display and you can install it in arduino ide , platform io or you are embeeded engineer .
you can see most project i made with this library and arduino uno and tft 3.5 inch sheild as apicture and videos look this link in my Google Drive : &ensp; [images and videos link ](https://drive.google.com/drive/folders/16Hg8dgcBH3FalRkK8SDBWj2221bd8Fue?usp=sharing)



#
## **about this version**
- **last version :** &emsp; ![last version](https://img.shields.io/badge/Version-4.4.4-red)
- adding some widgets and icons .
- adding effect like BLUR effect .
- handling all file for this lib and make it for begineers to use it .
- in SEDHOM_Display_OS.h class that has 4 var .
#
## **why I made this lib ?**
- this lib i use it for drawing some icons in ant tft i use it with arduino uno and nano and mega and esp32 .
- this lib doing any thing about this tft touch display with any mcu like sd card read file touch draw any thing in this tft display .
- GUI simple for control GPIO and smart thing .
- simple use for beginner to use elcronics .
#
## **what this lib do ?**
- draw some icons and wedigts and handling touch and read file from sd card .
- handling pages it's you make it .
- drawing pages i make it for any thing .
- you can make Beuatiful GUI for any machine and smart homes .
#
## **about Writer this Library**

***Eng.Mustafa Sedhom*** ( Embedded Software and Haedware Engineer ) 

  Gmail : **elmohandes24680@gmail.com**

  linkedIn : **[Mustafa Sedhom](https://www.linkedin.com/in/mustafa-sedhom-bb2551322)**

  WhatsApp : **+201144962908**
#
## **properites of Library**
- OS
    ```cpp
    void Init_Screen(ROTATION_STASTUS_t Rotate,Color_t Mode = Night_Mode);
    void Set_Device_Mode(Color_t Mode = Night_Mode);
    int Screen_Height();
    int Screen_Width();
    Color_t Mode();
    Color_t Not_Mode();
    void Fill_Screen(Color_t color);
    int Convert_Coordenates_to_Center_X_Point(int x);
    int Convert_Coordenates_to_Center_Y_Point(int y);
    Coordenate_t Convert_Coordenates_to_Center(Coordenate_t new_point);
    Color_t Night_mode = Night_Mode ;
    Color_t Light_mode = Light_Mode ;
    ROTATION_STASTUS_t Rotate_0 = Rotate_0_Degree;
    ROTATION_STASTUS_t Rotate_90 = Rotate_90_Degree;
    ROTATION_STASTUS_t Rotate_180 = Rotate_180_Degree;
    ROTATION_STASTUS_t Rotate_270 = Rotate_270_Degree;

    ```
- Data Structure
    ```cpp
    Stack<Data Type> stack ;
    Queue<Data Type> queue ;
    LinkedList<Data Type> linkedlist ;

    ```
- Icons 
    ```Cpp
        // to set and handling mode
        uint16_t Not_Mode();
        uint16_t Mode();
        void Set_Mode(Color_t Mode);
        // colors
        Color_t set_Color(int r,int g,int b);
        Color_t Set_Hex_Color(uint16_t Hex_code); 
        // define Basic shapes
        void draw_Pixel(int x,int y,Color_t color);
        void draw_Line(int x0,int y0,int x1,int y1,Color_t color);    
        void fill_Rectangle(int x,int y,int w,int h,int r,Color_t color);    
        void draw_Rectangle(int x,int y,int w,int h,int r,Color_t color);  
        void fill_Circle(int x,int y,int r,Color_t color); 
        void draw_Circle(int x,int y,int r,Color_t color);
        void fill_Triangle(int x0,int y0,int x1,int y1,int x2,int y2,Color_t color); 
        void draw_Triangle(int x0,int y0,int x1,int y1,int x2,int y2,Color_t color);

        void Right_Triangle(int x, int y, int h, int w,bool fill_or_draw, Color_t color);
        void Equilateral_Triangle_Up(int x, int y, int h,bool fill_or_draw, Color_t color);
        void Equilateral_Triangle_Down(int x, int y, int h,bool fill_or_draw, Color_t color); 
        void Equilateral_Triangle_Right(int x, int y, int h,bool fill_or_draw, Color_t color); 
        void Equilateral_Triangle_Left(int x, int y, int h,bool fill_or_draw, Color_t color); 

        void TEXT(int x,int y,const GFXfont* font,Color_t color,string_t txt);
        void Text_cpp(int x,int y,const GFXfont* font,Color_t color,String txt);
        void Container(int x,int y,int h,int w,int raduis,Color_t color);
        void Border_Rectangle(Icon_t Border_Rect,int h,int w,int Raduis,int Border_size);
        void fill_rectangle_with_end(int x,int y,int h,int w,int end_volume,Color_t color,Color_t end_color);
        void Draw_Custom_int_shap(int x,int y,int h,int w,int color,int arr[]);
        void Draw_Custom_Char(int x,int y,int h,int w,int color,char arr[]);
        // effects 
        Color_t Blur(int x,int y,int h,int w,int r,int Blur_value,Color_t mode,bool circle_or_rectangle = 1);
        Color_t Color_Blur(int x,int y,int h,int w,int r,Color_t color,Color_t mode,bool circle_or_rectangle = 1,void (*shadow)(Icon_t shadow_icon, int shadow_h,int shadow_w,int shadow_r,Color_t shadow_color) = nullptr);
        Color_t Shadow_effect(Icon_t shadow , Shapes_t shape = Shape_Rectangle, int shadow_size = 5 , int shadow_h = 120 , int shadow_w = 200 ,int shadow_Raduis = 20 , Position_t pos = Position_Right_and_Bottom, Color_t Shadow_color = Color_DarkGrey);
        // Draw SEDhOM Icons
        void WIFI_Icon(int x,int y,WIFI_STATUS_t state,Color_t color_on,Color_t color_off,Color_t Background);
        void Battary_Icon(int x,int y,int range,Color_t color,Color_t txt_color,Color_t Background,bool low_charge_red_color);
        void Home_Icon(int x,int y,Color_t color,Color_t Background);
        void Setting_Icon(int x,int y,Color_t color,Color_t Background);
        void Add_Icon(int x,int y,Color_t color,Color_t Background=0);
        void SD_Card_Icon(int x,int y,Color_t Background=0);
        void Control_Icon(int x,int y,Color_t color,Color_t Background);
        void Sensor_Icon(int x,int y,Color_t color,Color_t Background=0);
        void Power_off_Icon(int x,int y,Color_t color,Color_t Background);
        void Bluetooth_Icon(int x , int y ,BLUETOOTH_STATUS_t connect_status,Color_t color,Color_t Background);
        void Button_Icon(int x,int y,Color_t Background=0,bool print_on_and_off = 0);
        void Display_Time_Icon(int x,int y,Time_t time,Color_t color,Color_t Background=0);
        void Terminal_Icon(int x,int y,Color_t Background=0);
        void About_Icon(int x,int y ,Color_t color,Color_t Background);
        void Display_Date_Icon(int x,int y,Color_t color,Color_t text_color,int year,word_t month_name,int Day,word_t week_day_name,Color_t Background);
        void UP_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void DOWN_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void LEFT_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void RIGHT_Aroow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void Back_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void After_Arrow_Icon(int x,int y, Color_t color,Color_t end_color,Color_t Background=0);
        void Color_Icon(int x,int y,Color_t Background=0);
        void Time_Icon(int x,int y,Color_t color,Color_t Background);
        void Date_Icon(int x,int y,Color_t color,Color_t Background);
        void Switch_Icon(int x,int y,Color_t color_on,Color_t color_off,Color_t thumb_color,Color_t txt_color,bool state,Color_t Background=0);
        void label_Icon(int x,int y,int h,int w,int end,word_t string_in_label,Color_t color_str_in_label,Color_t color,Color_t Background);
        void slide_Icon(int x,int y,int h,byte_t range ,Color_t color_active,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color,Color_t Background=0);
        void file_Icon(int x,int y,Color_t color,Color_t end_color,Color_t file_extend_color,word_t file_extend,Color_t Background);
        void folder_Icon(int x,int y,Color_t folder_color,Color_t Background=0);
        void Divider_vertical(int x,int y,int length , int thikness,Color_t color);
        void Divider_Horezontal(int x,int y,int length , int thikness,Color_t color);
        void ID_Card_Icon(int x,int y,Color_t color,Color_t main_font_color,Color_t font_color,Color_t image_background,bool default_image,bool eye,bool prof,char* name,char* unversity,char* department_1,char* department_2,char* Born,char* number,Color_t Background=0);
        void Joy_Stick_Icon(int x,int y,int thumb_x,int thumb_y,int size,int thumb_size,Color_t color,Color_t OutLine,Color_t thumb,Color_t in ,Color_t Background=0);
        void Temperature_Meter_Icon(int x,int y,int value,bool show_val_dashes,Color_t color,Color_t Outline,Color_t Background);
        void Tone_Icon(int x,int y,bool is_muted_or_not,Color_t color,Color_t Background);
        void Sound_value_Icon(int x,int y,int value,Color_t color,Color_t thikness_color,Color_t Background,bool thikness_or_not=0);
        void Video_Icon(int x,int y,Color_t color,Color_t Background);
        void Block_Icon(int x,int y,bool open_or_closed,Color_t color,Color_t Background);
        void Signal_Icon(int x,int y,SIGNAL_STATUS_t state,Color_t color_on,Color_t color_off,Color_t Background);
        void Bell_Icon(int x,int y,bool mute_or_not,bool filled_or_not,Color_t color,Color_t Background);
        void Menu_Icon_1(int x,int y,Color_t color ,Color_t Background); // : : :
        void Menu_Icon_2(int x,int y,Color_t color ,Color_t Background); // ...
        void Menu_Icon_3(int x,int y,Color_t color ,Color_t Background); // :
        void Menu_Icon_4(int x,int y,Color_t color ,Color_t Background); // : :
        void Menu_Icon_5(int x,int y,Color_t color ,Color_t Background); // = 
        void Moon_Icon(int x,int y,Color_t color,Color_t Background);
        void Sun_Icon(int x,int y,Color_t color,Color_t Background);
        void Check_Box_Icon(int x,int y,bool status,Color_t border_color,Color_t check_color,Color_t checked_fill_color,Color_t Background);
        void Radio_Button_Icon(int x,int y,bool status,Color_t border_color,Color_t check_color,Color_t Background);
        void Text_Feild_Icon(int x,int y,int lenght,int max_char,Color_t Border_color,Color_t Text_color, GFXfont* font,Color_t Background , String str);
        void Warning_Icon(int x,int y,Color_t color,Color_t txt_color,Color_t Background,bool filled_or_not = Fill_shape);
        void Chandelier_Icon(int x,int y,Color_t color,Color_t Background);
        void Smart_TV_Icon(Icon_t icon,Color_t WIFI_icon);
        void Air_Conditioner_Icon(Icon_t Icon);

    ```
- Fonts 
    ```cpp
    // Dufualt small and Big Font
     SmallFont                 
     BigFont                   
     FONT_SMALL                
     FONT_BIG                  
    // SevenSegment
     FONT_SEVENSEGMENT         
    // FreeSans
     FONT_FREESANS_SMALL       
     FONT_FREESANS_MEDIUM      
     FONT_FREESANS_BIG         
     FONT_FREESANS_VERYBIG     
    // FreeSansBold
     FONT_FREESANSBOLD_SMALL       
     FONT_FREESANSBOLD_MEDIUM      
     FONT_FREESANSBOLD_BIG         
     FONT_FREESANSBOLD_VERYBIG     
    // FreeSansOblique
     FONT_FREESANSOBLIQUE_SMALL       
     FONT_FREESANSOBLIQUE_MEDIUM      
     FONT_FREESANSOBLIQUE_BIG         
     FONT_FREESANSOBLIQUE_VERYBIG     
    // FreeSerif
     FONT_FREESERIF_SMALL       
     FONT_FREESERIF_MEDIUM      
     FONT_FREESERIF_BIG         
     FONT_FREESERIF_VERYBIG     
    // FreeSerifBold
     FONT_FREESERIFBOLD_SMALL       
     FONT_FREESERIFBOLD_MEDIUM      
     FONT_FREESERIFBOLD_BIG         
     FONT_FREESERIFBOLD_VERYBIG     
    // FreeSerifItalic
     FONT_FREESERIFITALIC_SMALL       
     FONT_FREESERIFITALIC_MEDIUM      
     FONT_FREESERIFITALIC_BIG         
     FONT_FREESERIFITALIC_VERYBIG     
    // FreeSerifBoldItalic
     FONT_FREESERIFBOLDITALIC_SMALL       
     FONT_FREESERIFBOLDITALIC_MEDIUM      
     FONT_FREESERIFBOLDITALIC_BIG         
     FONT_FREESERIFBOLDITALIC_VERYBIG     
    // FreeMono
     FONT_FREEMONO_SMALL       
     FONT_FREEMONO_MEDIUM      
     FONT_FREEMONO_BIG         
     FONT_FREEMONO_VERYBIG     
    // FreeMonoBold
     FONT_FREEMONOBOLD_SMALL       
     FONT_FREEMONOBOLD_MEDIUM      
     FONT_FREEMONOBOLD_BIG         
     FONT_FREEMONOBOLD_VERYBIG     
    // FreeMonoOblique
     FONT_FREEMONOOBLIQUE_SMALL       
     FONT_FREEMONOOBLIQUE_MEDIUM      
     FONT_FREEMONOOBLIQUE_BIG         
     FONT_FREEMONOOBLIQUE_VERYBIG     
    // FreeMonoBoldOblique
     FONT_FREEMONOBOLDOBLIQUE_SMALL       
     FONT_FREEMONOBOLDOBLIQUE_MEDIUM      
     FONT_FREEMONOBOLDOBLIQUE_BIG         
     FONT_FREEMONOBOLDOBLIQUE_VERYBIG     

    ```
- Widgets
    ```cpp
        void set_widgets_mode(Color_t mode);
        void APP_Bar_Widget(bool show_back_arrow,WIFI_STATUS_t WIFI_state,BLUETOOTH_STATUS_t Bluetooth_state,int Battary_Value,Time_t time,Color_t Wifi_on,Color_t Wifi_off,Color_t BLE_color,Color_t Battary_color,Color_t Time_color,Color_t Reverse_color,Color_t Background);
        void Big_frame_widget(Color_t color,Color_t Background);
        void ERROR_Massage_Widget(String masseage,Color_t Background,Color_t color=MAGENTA,Color_t color_txt=WHITE,Color_t ERROR_Massage_color = RED,Color_t title_Massage_color = BLUE,String title="ERROR",bool filled_or_not = Fill_shape,int x = 100,int y = 70,int w = 160,int h = 240,int max_lines_of_masseage_error =5,int max_char_in_one_line = 20);

    ```
- Windows
    ```cpp
     void set_windows_mode(Color_t mode);
      String Full_KeyBoard_window_user_input_TXT = "";
      //drawing window functions 
      void Full_Key_Board_Window(Color_t color,Color_t Background,Color_t char_color = WHITE,Color_t text_feild_color = -1,bool caps_or_not=true,bool special_char_or_not=false);
      bool Handling_Touch_Full_Key_Board_Window();

    ```
- Touch
    ``` Cpp
      bool Is_Presssed();
      int get_X_point();
      int get_Y_point();
      int get_Z_point();
      bool onTap(int x, int y, int w, int h);
      void onTap(int x, int y, int w, int h,void (*Do_Function)());
    ```
- SD_Card <- handling all function to dealing betwwen sdcard and mcu
    - read() , write() , ... like sd lib do exactly .
- Handle pages
    ```cpp
      // input SEDHOM_Handling_pages_paramters instead of void (*pages_array[])(void), int size
      void Handle_all_pages(void (*pages_array[])(void), int size);
      void goto_page(int number);
      void push_page();
      void pop_page();
    ```
- Time
    ```cpp
    void Stop_Display(int time);
    void Wait(int time);
    unsigned long Calc_time_ms();
    unsigned long Calc_time_us();

    ```
- Colors
    ```cpp
     Color_Black           
     Color_Navy            
     Color_DarkGary       
     Color_DarkCyan      
     Color_Maroon           
     Color_Purple          
     Color_Olive           
     Color_LightGrey     
     Color_DarkGrey       
     Color_Blue               
     Color_Green        
     Color_Cyan              
     Color_Red                
     Color_Magenta        
     Color_Yellow          
     Color_White            
     Color_Orange             
     Color_GreenYellow  
     Color_Pink         

    ```
- SEDHOM Data Types
    ```cpp
    string_t                // char *
    word_t                  // char *
    byte_t                  // uint8_t
    Color_t                 // uint16_t
    ROTATION_STASTUS_t      // enum
    WIFI_STATUS_t           // enum
    BLUETOOTH_STATUS_t      // enum
    SWITCH_STATUS_t         // enum
    SIGNAL_STATUS_t         // enum
    User_ID_Data_t          // struct
    Time_t                  // struct
    Icon_t                  // struct
    Position_t              // enum
    Shapes_t                // enum
    Coordenate_t            // struct
    WIFI_Encryption_Type_t  // enum
    WIFI_Config_t           // struct
    ```
#
## if you want install it in arduino ide 
1. download this folder in your pc
2. put this folder in (~/Documentos/Arduino/libraries) between your arduino libraries .
3. you should install some library becuose this lib is a top layer of drivers 
    - MCUFreind_kbv  <- or choose any driver do you want and adding some setting in SEDHOM_Display_Settings.h file .
    - Adarfruit Touch <- this lib for touch you can use it and edit all setting touch in SEDHOM_Display_Settings.h file .
    - Adafruit GFX <- for drawing basic shapes .
    - QRCodeGFX <- for drawing QRCode icon .
    - SD <- for use sd card and load images and fonts in tft screen .
    - SPI <- this lib embbedded in arduino ide .
4. open arduino ide or restart arduino ide and open (file -> Examples -> SEDHOM_Display_OS -> ... ) choose any project and added any thing you want and use lib .
5. you can open new project and put in top first thing this line #include<SEDHOM_Display_OS.h> and next line SEDHOM_Display_OS   OS; and in setup OS.Init_Screen(Rotate_90_Degree,Night_Mode); and use OS. and show all proertes in this lib and see last pargraf in this to show all prpertes .
#
## else if you want install it in platform io -->

1. download this folder in your pc
2. create platform project .
3. put this folder in (lib folder) between your libraries .
4. you should add some library because this lib is a top layer of drivers input all library in lib folder for you project next SEDHOM_Display_OS folder
    - MCUFreind_kbv  <- or choose any driver do you want and adding some setting in SEDHOM_Display_Settings.h file .
    - Adarfruit Touch <- this lib for touch you can use it and edit all setting touch in SEDHOM_Display_Settings.h file .
    - Adafruit GFX <- for drawing basic shapes .
    - SD <- for use sd card and load images and fonts in tft screen .
    - SPI <- this lib for communication protocal betwwen MCU and SD card .
5. open (SEDHOM_Display_OS ->example-> ... ) choose any project and added any thing you want and use lib .
6. you can open new project and put in top first thing this line #include<SEDHOM_Display_OS.h> and next line SEDHOM_Display_OS   OS; and in setup OS.Init_Screen(Rotate_90_Degree,Night_Mode); and use OS. and show all propirtes in this lib and see last pargraf in this to show all prpertes .
#
## else if you Embedded Engineer and want use this library -->

- put this folder betwwen your project and adding this line #include<SEDHOM_Display_OS.h> and next line SEDHOM_Display_OS   OS; and in main before while loop OS.Init_Screen(Rotate_90_Degree,Night_Mode); and you can OS. to show all properites and in SEDHOM_Display_Setting.h all folders i use it and function yhis file is control all my library all files for drawing and gandling touch only .
#
