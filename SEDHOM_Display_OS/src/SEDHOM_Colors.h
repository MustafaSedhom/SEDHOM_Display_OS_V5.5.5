//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#pragma once
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#include "SEDHOM_Display_Settings.h"
#include "SEDHOM_Data_Types.h"
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
typedef uint16_t Color_t ;
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define BLACK       0x0000      /*   0,   0,   0 */
#define NAVY        0x000F      /*   0,   0, 128 */
#define DARKGREEN   0x03E0      /*   0, 128,   0 */
#define DARKCYAN    0x03EF      /*   0, 128, 128 */
#define MAROON      0x7800      /* 128,   0,   0 */
#define PURPLE      0x780F      /* 128,   0, 128 */
#define OLIVE       0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY   0xC618      /* 192, 192, 192 */
#define DARKGREY    0x7BEF      /* 128, 128, 128 */
#define BLUE        0x001F      /*   0,   0, 255 */
#define GREEN       0x07E0      /*   0, 255,   0 */
#define CYAN        0x07FF      /*   0, 255, 255 */
#define RED         0xF800      /* 255,   0,   0 */
#define MAGENTA     0xF81F      /* 255,   0, 255 */
#define YELLOW      0xFFE0      /* 255, 255,   0 */
#define WHITE       0xFFFF      /* 255, 255, 255 */
#define ORANGE      0xFDA0      /* 255, 180,   0 */
#define GREENYELLOW 0xB7E0      /* 180, 255,   0 */
#define PINK        0xFC9F      /* 255, 192, 203 */
#define very_dark_grey 0x2104   /*  33,  33,  33 */
/////////////////////////////end colors//////////////////////////////
#define black       BLACK    
#define navy        NAVY    
#define darkgary    DARKGREY   
#define darkcyan    DARKCYAN  
#define maroon      MAROON     
#define purple      PURPLE    
#define olive       OLIVE    
#define lightgrey   LIGHTGREY  
#define darkgrey    DARKGREY   
#define blue        BLUE       
#define green       GREEN 
#define cyan        CYAN      
#define red         RED       
#define magenta     MAGENTA   
#define yellow      YELLOW    
#define white       WHITE     
#define orange       ORANGE      
#define greenyellow GREENYELLOW 
#define pink        PINK 
/////////////////////////////end colors//////////////////////////////
#define Black       BLACK    
#define Navy        NAVY    
#define DarkGary    DARKGREY 
#define DarkCyan    DARKCYAN  
#define Maroon      MAROON     
#define Purple      PURPLE    
#define Olive       OLIVE    
#define LightGrey   LIGHTGREY  
#define DarkGrey    DARKGREY   
#define Blue        BLUE       
#define Green       GREEN 
#define Cyan        CYAN      
#define Red         RED       
#define Magenta     MAGENTA   
#define Yellow      YELLOW    
#define White       WHITE     
#define Orange       ORANGE      
#define GreenYellow GREENYELLOW 
#define Pink        PINK 
/////////////////////////////end colors//////////////////////////////
#define Color_Black       BLACK    
#define Color_Navy        NAVY     
#define Color_DarkCyan    DARKCYAN  
#define Color_Maroon      MAROON     
#define Color_Purple      PURPLE    
#define Color_Olive       OLIVE    
#define Color_LightGrey   LIGHTGREY  
#define Color_DarkGrey    DARKGREY   
#define Color_Blue        BLUE       
#define Color_Green       GREEN 
#define Color_Cyan        CYAN      
#define Color_Red         RED       
#define Color_Magenta     MAGENTA   
#define Color_Yellow      YELLOW    
#define Color_White       WHITE     
#define Color_Orange       ORANGE      
#define Color_GreenYellow GREENYELLOW 
#define Color_Pink        PINK 
#define Color_Very_DarkGrey   very_dark_grey
/////////////////////////////end colors//////////////////////////////
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
class SEDHOM_Colors
{
    private:

    public:
        // colors
        Color_t Set_Color(Color_RGB_t color);
        Color_t Set_Color(uint16_t Hex_code); 
        Color_t Set_Color(String Hex_Html_color_code);
        Color_t RGB_to_Gray(Color_RGB_t RGB_color);
};
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
// colors
Color_t SEDHOM_Colors::Set_Color(Color_RGB_t RGB_color)
{
    uint16_t rgb565 = ((RGB_color.R & 0xF8) << 8) |
                  ((RGB_color.G & 0xFC) << 3) |
                  (RGB_color.B >> 3);

   return(rgb565);
}
Color_t SEDHOM_Colors::Set_Color(uint16_t RGB565_Hex_code)
{
    return RGB565_Hex_code;
}
Color_t SEDHOM_Colors::Set_Color(String Html_Hex_color_code)
{
    // Remove '#'
    if (Html_Hex_color_code.charAt(0) == '#')
    {
        Html_Hex_color_code.remove(0, 1);
    }

    // Validate HEX length
    if (Html_Hex_color_code.length() != 6)
    {
        return 0x0000; // Black
    }

    // Convert HEX string to RGB888
    uint32_t RGB888 = strtoul(
        Html_Hex_color_code.c_str(),
        NULL,
        16
    );

    // Extract RGB components
    uint8_t R = (RGB888 >> 16) & 0xFF;
    uint8_t G = (RGB888 >> 8)  & 0xFF;
    uint8_t B = RGB888 & 0xFF;

    // Convert RGB888 -> RGB565
    uint16_t RGB565 =
        ((R & 0xF8) << 8) |
        ((G & 0xFC) << 3) |
        (B >> 3);

    return (Color_t)RGB565;
}
Color_t SEDHOM_Colors::RGB_to_Gray(Color_RGB_t RGB_color)
{
    uint8_t gray = (uint8_t)(((uint32_t)RGB_color.R * 77 + (uint32_t)RGB_color.G * 150 + (uint32_t)RGB_color.B * 29 + 128) >> 8);
    uint16_t r5 = (gray >> 3) & 0x1F; 
    uint16_t g6 = (gray >> 2) & 0x3F; 
    uint16_t b5 = (gray >> 3) & 0x1F;
    return (Color_t)((r5 << 11) | (g6 << 5) | b5);
}
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}