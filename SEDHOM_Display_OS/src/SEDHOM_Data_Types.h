#ifndef SEDHOM_DATA_TYPES_H_ 
#define SEDHOM_DATA_TYPES_H_ 
//**********************************************************************************************************************

#define Night_Mode       BLACK
#define Dark_Mode        BLACK
#define Light_Mode       WHITE
#define Normal_Mode      WHITE

#define Vertical         0 
#define Horizontal       1

#define Circle           0
#define Rect             1
#define Rectangle       Rect

#define Fill_shape        1
#define Draw_shape        0

#define Show              1
#define Hide              0

#define yes               1
#define no                0

#define on               ON
#define off              OFF
#define byte_t         uint8_t
#define string_t       char*
#define word_t         char*

typedef uint16_t Color_t;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum 
{
  Rotate_0_Degree,
  Rotate_90_Degree,
  Rotate_180_Degree,
  Rotate_270_Degree
}ROTATION_STASTUS_t;

typedef enum 
{
    WIFI_Status_not_connected,
    WIFI_Status_no_internet,
    WIFI_Status_conected_level_1,
    WIFI_Status_conected_level_2_half,
    WIFI_Status_conected_level_3,
    WIFI_Status_conected_level_4_full
}WIFI_STATUS_t;

typedef enum 
{
    BLuetooth_Status_closed,
    BLuetooth_Status_open_and_not_connected,
    BLuetooth_Status_open_and_connected
}BLUETOOTH_STATUS_t;

typedef enum 
{
    OFF,
    ON
}SWITCH_STATUS_t;

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

///////////////////////////////////////////////////////////////////////////
// data type of Id icon
typedef struct 
{
    bool is_professser;
    string_t user_name;
    string_t universty;
    string_t department_1;
    string_t department_2;
    string_t Born;
    string_t number;
}User_ID_Data_t;
///////////////////////////////////////////////////////////////////////////
// data type of time icon
typedef struct 
{
    int hour;
    int minut;
    int sec;
    word_t time_name;
}Time_t;
///////////////////////////////////////////////////////////////////////////
// data type of all icon
typedef struct 
{
    int x;
    int y;
    Color_t color;
    Color_t Background;
}Icon_t;
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
}Shapes_t;
///////////////////////////////////////////////////////////////////////////
// data type of coordenate
typedef struct 
{
    int x;
    int y;
}Coordenate_t;
///////////////////////////////////////////////////////////////////////////
// data type of WiFi network Encytption type
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
} WIFI_Config_t;

//**********************************************************************************************************************
#endif /* SEDHOM_DATA_TYPES_H_ */