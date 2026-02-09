#ifndef SEDHOM_DISPLAY_QRCODES_H_
#define SEDHOM_DISPLAY_QRCODES_H_
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SEDHOM_Display_Settings.h"

 init_Qr_code();

#define SEDHOM_QRCode(x,y,size,Background,ForeGround,version,content)  \
                        SEDHOM_QRCode_Settings(Background,ForeGround,size,version);SEDHOM_QRCode_write(x,y,content);

#define SEDHOM_QRCode_write(x,y,content)        qrcode.draw(content,x,y);

#define SEDHOM_QRCode_Settings(Background_Color,ForeGround,size,version) \
    qrcode.setScale(size).setColors(Background_Color, ForeGround).setRotation(QRCodeRotation::R0); \
    qrcode.getGenerator().setErrorCorrectionLevel(/*QRCodeECCLevel::High*/ QRCodeECCLevel::Low).setVersion(version); 
    // from 1 to 20  // background, foreground // 0°, 90°, 180°, or 270° // force specific version
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /*SEDHOM_DISPLAY_QRCODES_H_*/