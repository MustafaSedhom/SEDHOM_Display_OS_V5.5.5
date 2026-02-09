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
#define Color_t        uint16_t
#define string_t       char*
#define word_t         char*
#define SEDHOM_Display_OS_t    SEDHOM_Display_OS
#define SEDHOM_Icons_t         SEDHOM_Icons
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum Rotate
{
  Rotate_0_Degree,
  Rotate_90_Degree,
  Rotate_180_Degree,
  Rotate_270_Degree
}ROTATION_STASTUS_t;

typedef enum WIFI_Status
{
    WIFI_Status_not_connected,
    WIFI_Status_no_internet,
    WIFI_Status_conected_level_1,
    WIFI_Status_conected_level_2_half,
    WIFI_Status_conected_level_3,
    WIFI_Status_conected_level_4_full
}WIFI_STATUS_t;

typedef enum Bluetooth_Status
{
    BLuetooth_Status_closed,
    BLuetooth_Status_open_and_not_connected,
    BLuetooth_Status_open_and_connected
}BLUETOOTH_STATUS_t;

typedef enum Switch
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
//**********************************************************************************************************************
#endif /* SEDHOM_DATA_TYPES_H_ */