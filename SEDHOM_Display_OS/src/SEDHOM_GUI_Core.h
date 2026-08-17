//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#pragma once 
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include "SEDHOM_Display_Settings.h"
#include "Imports/Adafruit_GFX_Library/Adafruit_GFX.h"
#include "Imports/QRCodeGFX/src/QRCodeGFX.h"
#include "Imports/BarcodeGFX/src/BarcodeGFX.h"
#include "Imports/U8g2_for_Adafruit_GFX/src/U8g2_for_Adafruit_GFX.h"
#include "Imports/U8g2_for_Adafruit_GFX/src/u8g2_fonts.h"
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

class SEDHOM_GUI_Core : public Adafruit_GFX
{
private:

public:
    // Constructor
    SEDHOM_GUI_Core(int16_t w = API_Screen_width(), int16_t h = API_Screen_height()) 
    : Adafruit_GFX(w, h) {
    }
    // Required Pure Virtual Function
    void drawPixel(int16_t x, int16_t y, uint16_t color) override {
        API_Draw_Pixel(x, y, color);
    }

    // High-Performance Hardware Acceleration Overrides
    void startWrite(void) override {
        API_Start_Write();
    }

    void endWrite(void) override {
        API_End_Write();
    }

    void writePixel(int16_t x, int16_t y, uint16_t color) override {
        API_Write_Pixel(x, y, color);
    }

    void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override {
        API_Write_Fast_VLine(x, y, h, color);
    }

    void writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override {
        API_Write_Fast_HLine(x, y, w, color);
    }

    void writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override {
        API_Write_Fill_Rect(x, y, w, h, color);
    }

    void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override {
        API_Draw_Fast_VLine(x, y, h, color);
    }

    void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override {
        API_Draw_Fast_HLine(x, y, w, color);
    }

    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override {
        API_Fill_Rect(x, y, w, h, color);
    }

    void fillScreen(uint16_t color) override {
        API_Fill_Screen(color);
    }

    void setRotation(uint8_t r) override {
        Adafruit_GFX::setRotation(r);
        API_Set_Rotation(r);
    }

    void invertDisplay(bool i) override {
        API_Invert_Display(i);
    }
    // =========================================================================
    // QR Code Functions (Takes Coordinates and Text)
    // =========================================================================
    void drawQRCode(int16_t x, int16_t y, const char* text, uint8_t scale = 3, uint16_t bg = 0xFFFF , uint16_t fg = 0x0000 ) {
        QRCodeGFX qrcode(*this); 
        static uint8_t qrcodeBuffer[175];
        static uint8_t tempBuffer[175];
        qrcode.getGenerator().setBuffers(qrcodeBuffer, tempBuffer, sizeof(qrcodeBuffer));
        qrcode.setScale(scale).setColors(bg, fg);
        qrcode.draw(text, x, y);
    }
    void drawBarcode(int16_t x,int16_t y,const char* codeText, uint16_t height,BarcodeType type,uint8_t scale,bool showDigits, uint16_t bg, uint16_t fg) {
        BarcodeGFX barcode(*this);
        barcode.setShowDigits(showDigits).setScale(scale).setColors(bg, fg);
       barcode.draw(codeText, x, y, height, type);
    }
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<