#ifndef SEDHOM_DATA_TYPES_H_ 
#define SEDHOM_DATA_TYPES_H_ 
//**********************************************************************************************************************
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Dynamic_Data_Type.h"
//**********************************************************************************************************************

#define Night_Mode       BLACK
#define Dark_Mode        BLACK
#define Light_Mode       WHITE
#define Normal_Mode      WHITE

#define yes               1
#define no                0
#define ON                1
#define OFF               0
#define on               ON
#define off              OFF

#define string_t       char*
#define word_t         char*

#define lambda_none         [](){}
#define lambda_func_none    [](){}
#define lambda()            []()
// #define ()=>{}              []()

#define Image_t        static const unsigned char PROGMEM

typedef unsigned char  byte_t;   
typedef uint16_t Color_t;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// make Data type of Data Types names and value put it
class Dynamic : public SEDHOM_Dynamic_Data_Type
{
    public:
        using SEDHOM_Dynamic_Data_Type::operator=;
        // Constructors
        Dynamic() {}
        Dynamic(int value) { *this = value; }
        Dynamic(float value) { *this = value; }
        Dynamic(double value) { *this = value; }
        Dynamic(bool value) { *this = value; }
        Dynamic(char value) { *this = value; }
        Dynamic(const char* value) { *this = value; }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum 
{
    Rotate_0_Degree,
    Rotate_90_Degree,
    Rotate_180_Degree,
    Rotate_270_Degree
}ROTATION_STATUS_t;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum 
{
    WIFI_Status_not_connected,
    WIFI_Status_no_internet,
    WIFI_Status_connected_level_1,
    WIFI_Status_connected_level_2_half,
    WIFI_Status_connected_level_3,
    WIFI_Status_connected_level_4_full
}WIFI_STATUS_t;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum 
{
    BLuetooth_Status_closed,
    BLuetooth_Status_open_and_not_connected,
    BLuetooth_Status_open_and_connected
}BLUETOOTH_STATUS_t;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum 
{
    SWITCH_State_OFF,
    SWITCH_State_ON,
}SWITCH_STATUS_t;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum 
{
    Signal_Status_Off,
    Signal_Status_No_Signal,
    Signal_Status_Signal_level_1,
    Signal_Status_Signal_level_2,
    Signal_Status_Signal_level_3,
    Signal_Status_Signal_level_4,
    Signal_Status_Signal_level_5_full,
}SIGNAL_STATUS_t;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// data type of Id icon
typedef struct 
{
    bool is_professor;
    string_t user_name;
    string_t university;
    string_t department_1;
    string_t department_2;
    string_t Born;
    string_t number;
    Color_t image_background;
    bool default_image;
    bool eye;

}User_ID_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of time icon
typedef struct Time_Data_t
{
    int hour;
    int minute;
    int sec;
    word_t time_name;
    bool operator==(const Time_Data_t& other) const
    {
        return (hour == other.hour) &&
               (minute == other.minute) &&
               (sec == other.sec) &&
               (time_name == other.time_name);
    }
    bool operator!=(const Time_Data_t& other) const
    {
        return !(*this == other);
    }
} Time_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of coordinate
typedef struct 
{
    int x;
    int y;
}Coordinate_t;
///////////////////////////////////////////////////////////////////////////
// data type of all icon
typedef struct 
{
    Coordinate_t coordinate;
    Color_t color;
    Color_t Background;
}Icon_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of positions
typedef enum 
{
    Position_Center,
    Position_Top,
    Position_Bottom,
    Position_Right,
    Position_Left,
    Position_Top_Left,
    Position_Top_Right,
    Position_Bottom_Left,
    Position_Bottom_Right,
    Position_Right_and_Left,
    Position_Right_and_Top,
    Position_Right_and_Bottom,
    Position_Left_and_Top,
    Position_Left_and_Bottom,
    Position_Top_and_Bottom,
    Position_All,
}Position_t;
///////////////////////////////////////////////////////////////////////////
// data type of Shapes
typedef enum 
{
    Shape_Circle,
    Shape_Rectangle,
    Shape_Triangle,
    Shape_Line,
    Shape_Square,
}Shapes_type_t;
///////////////////////////////////////////////////////////////////////////
// data type of Days
typedef enum 
{
    Day_Saturday,
    Day_Sunday,
    Day_Monday,
    Day_Tuesday,
    Day_Wednesday,
    Day_Thursday,
    Day_Friday
}Days_t;
///////////////////////////////////////////////////////////////////////////
// data type of Hijri Months
typedef enum
{
    Hijri_Month_Muharram,
    Hijri_Month_Safar,
    Hijri_Month_Rabi_Al_Awwal,
    Hijri_Month_Rabi_Al_Thani,
    Hijri_Month_Jumada_Al_Awwal,
    Hijri_Month_Jumada_Al_Thani,
    Hijri_Month_Rajab,
    Hijri_Month_Shaaban,
    Hijri_Month_Ramadan,
    Hijri_Month_Shawwal,
    Hijri_Month_Dhul_Qadah,
    Hijri_Month_Dhul_Hijjah
}Hijri_Months_t;
///////////////////////////////////////////////////////////////////////////
// data type of Months
typedef enum 
{
    Month_January,
    Month_February,
    Month_March,
    Month_April,
    Month_May,
    Month_June,
    Month_July,
    Month_August,
    Month_September,
    Month_October,
    Month_November,
    Month_December
}Months_t;
///////////////////////////////////////////////////////////////////////////
// data type of WiFi network Encryption type
typedef enum
{
    WIFI_Encryption_OPEN,             // Open
    WIFI_Encryption_WEP,              // WEP
    WIFI_Encryption_WPA_PSK,          // WPA
    WIFI_Encryption_WPA2_PSK,         // WPA2
    WIFI_Encryption_WPA_WPA2_PSK,     // WPA+WPA2
    WIFI_Encryption_WPA2_ENTERPRISE,  // WPA2 Enterprise
    WIFI_Encryption_WPA3_PSK,         // WPA3
    WIFI_Encryption_WPA2_WPA3_PSK,    // WPA2+WPA3
}WIFI_Encryption_Type_t;
///////////////////////////////////////////////////////////////////////////
// data type of WiFi network configuration
typedef struct 
{
    String SSID;                   
    String Password;              
    int range;                    
    int RSSI;                     
    bool Secured;                  
    int channel;                  
    WIFI_Encryption_Type_t Encryption_Type; 
    WIFI_STATUS_t wifi_status;     
} WIFI_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of WiFi network configuration
typedef struct 
{
    String name;                                
    int range;                    
    WIFI_STATUS_t wifi_status;     
} WIFI_Data_Simple_t;
///////////////////////////////////////////////////////////////////////////
// data type of Date
typedef struct 
{
    int year;
    int month;
    int Day;
    String month_name;
    String week_day_name;     
} Date_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of string
typedef struct 
{
    GFXfont* txt_font;
    Color_t txt_color;
    String txt;
}Text_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of string
typedef struct 
{
    GFXfont* txt_font;
    Color_t txt_color;
    char* txt;
}Text_C_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of Area
typedef struct 
{
    int w;
    int h;
}Area_t;
///////////////////////////////////////////////////////////////////////////
// data type of RGB color
typedef struct 
{
    byte_t R;
    byte_t G;
    byte_t B;
}Color_RGB_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Shape_filled_t
typedef enum 
{
    Shape_Draw,
    Shape_Fill,
}Shape_filled_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Square_Data_t shape
typedef struct 
{
   Coordinate_t coordinate;
    int length;
    int Radius;
    Shape_filled_t Filled ;
    Color_t color;
}Square_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Rectangle_Data_t shape
typedef struct 
{
    Coordinate_t coordinate;
    Area_t area;
    int Radius;
    Shape_filled_t Filled ;
    Color_t color;
}Rectangle_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Circle_Data_t shape
typedef struct 
{
    Coordinate_t coordinate;
    int Radius;
    Shape_filled_t Filled ;
    Color_t color;
}Circle_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Triangle_Data_t shape
typedef struct 
{
    Coordinate_t coordinate_Point_1;
    Coordinate_t coordinate_Point_2;
    Coordinate_t coordinate_Point_3;
    Shape_filled_t Filled ;
    Color_t color;
}Triangle_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Line_Data_t shape
typedef struct 
{
    Coordinate_t coordinate_Start_Point;
    Coordinate_t coordinate_End_Point;
    Color_t color;
}Line_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Pixel_Data_t shape
typedef struct 
{
    Coordinate_t coordinate_Point;
    Color_t color;
}Pixel_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Visibility_t
typedef enum  
{
    Hide,
    Show,
}Visibility_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Direction_t
typedef enum  
{
    Direction_Up,
    Direction_Down,
    Direction_Right,
    Direction_Left,
}Direction_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Special_Triangle_Data_t
typedef struct  
{
    Coordinate_t coordinate ;
    int length ;
    Shape_filled_t filled ;
    Direction_t Dir ;
    Color_t color ;
}Triangle_special_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  touch point
typedef struct  
{
    Coordinate_t coordinate ;
    Area_t area;
}Touch_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Orientation
typedef enum
{
    HORIZONTAL,
    VERTICAL,
}Orientation_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Icon Size
typedef enum
{
    Size_1=1,
    Size_2=2,
    Size_3=3,
    Size_4=4,
    Size_5=5,
    Size_6=6,
    Size_7=7,
    Size_8=8,
}Icon_Size_t;
///////////////////////////////////////////////////////////////////////////
// data type of Image
typedef struct 
{
    Coordinate_t coordinate;
    Area_t area;
    Color_t color;
    const uint8_t *image;
}Image_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of Image
typedef struct 
{
    Coordinate_t coordinate;
    Area_t area;
    const uint16_t *image;
}Image_RGB_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of  touch state
typedef struct  
{
    unsigned long startTime = 0;
    unsigned long lastTapTime = 0;

    bool isPressing = false;
    bool longTriggered = false;
    bool waitingDouble = false;
}Touch_State_t;
///////////////////////////////////////////////////////////////////////////
// data type of  Button
struct Button_Data_t {
    bool state = false;
    Touch_State_t touch_state;
    Shapes_type_t shape;
    Rectangle_Data_t rectangle_shape_off;
    Rectangle_Data_t rectangle_shape_on;
    Circle_Data_t circle_shape_off;
    Circle_Data_t circle_shape_on;
    int longPressTime = 1000;
    int doublePressTime = 500;

    // Constructor
    Button_Data_t(
        bool button_state = false,
        Shapes_type_t shape_type = Shape_Rectangle,
        Rectangle_Data_t off_Rect = {{0,0},{0,0},0,Shape_Fill,0},
        Rectangle_Data_t on_Rect = {{0,0},{0,0},0,Shape_Fill,0},
        Circle_Data_t off_Circle = {{0,0},0,Shape_Fill,0},
        Circle_Data_t on_Circle = {{0,0},0,Shape_Fill,0},
        int long_Press = 1000,
        int double_Press = 500
    ) {
        state = button_state;
        shape = shape_type;
        rectangle_shape_off = off_Rect;
        rectangle_shape_on  = on_Rect;
        circle_shape_off    = off_Circle;
        circle_shape_on     = on_Circle;
        longPressTime       = long_Press;
        doublePressTime     = double_Press;
    }
};

//**********************************************************************************************************************
#endif /* SEDHOM_DATA_TYPES_H_ */