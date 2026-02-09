#ifndef SEDHOM_DISPLAY_FONTS_H_
#define SEDHOM_DISPLAY_FONTS_H_
//=========================== Defualt fonts font Family ========================
// #include "SEDHOM_7_seg_font.h"
#include "SEDHOM_Defualt_fonts.h"
//=========================== FreeSans Family ===========================
#include <Fonts/FreeSans9pt7b.h>    
#include <Fonts/FreeSans12pt7b.h>   
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSans24pt7b.h>   
//=========================== FreeSansBold Family =======================
#include <Fonts/FreeSansBold9pt7b.h>    
#include <Fonts/FreeSansBold12pt7b.h>   
#include <Fonts/FreeSansBold18pt7b.h>   
#include <Fonts/FreeSansBold24pt7b.h>   
//=========================== FreeSansOblique Family ===================
#include <Fonts/FreeSansOblique9pt7b.h>    
#include <Fonts/FreeSansOblique12pt7b.h>   
#include <Fonts/FreeSansOblique18pt7b.h>   
#include <Fonts/FreeSansOblique24pt7b.h>   
//=========================== FreeSerif Family =========================
#include <Fonts/FreeSerif9pt7b.h>    
#include <Fonts/FreeSerif12pt7b.h>   
#include <Fonts/FreeSerif18pt7b.h>   
#include <Fonts/FreeSerif24pt7b.h>   
//=========================== FreeSerifBold Family =====================
#include <Fonts/FreeSerifBold9pt7b.h>    
#include <Fonts/FreeSerifBold12pt7b.h>   
#include <Fonts/FreeSerifBold18pt7b.h>   
#include <Fonts/FreeSerifBold24pt7b.h>   
//=========================== FreeSerifItalic Family ===================
#include <Fonts/FreeSerifItalic9pt7b.h>    
#include <Fonts/FreeSerifItalic12pt7b.h>   
#include <Fonts/FreeSerifItalic18pt7b.h>   
#include <Fonts/FreeSerifItalic24pt7b.h>   
//=========================== FreeSerifBoldItalic Family ==============
#include <Fonts/FreeSerifBoldItalic9pt7b.h>    
#include <Fonts/FreeSerifBoldItalic12pt7b.h>   
#include <Fonts/FreeSerifBoldItalic18pt7b.h>   
#include <Fonts/FreeSerifBoldItalic24pt7b.h>   
//=========================== FreeMono Family =========================
#include <Fonts/FreeMono9pt7b.h>    
#include <Fonts/FreeMono12pt7b.h>   
#include <Fonts/FreeMono18pt7b.h>   
#include <Fonts/FreeMono24pt7b.h>   
//=========================== FreeMonoBold Family =====================
#include <Fonts/FreeMonoBold9pt7b.h>    
#include <Fonts/FreeMonoBold12pt7b.h>   
#include <Fonts/FreeMonoBold18pt7b.h>   
#include <Fonts/FreeMonoBold24pt7b.h>  
//=========================== FreeMonoOblique Family ==================
#include <Fonts/FreeMonoOblique9pt7b.h>    
#include <Fonts/FreeMonoOblique12pt7b.h>   
#include <Fonts/FreeMonoOblique18pt7b.h>   
#include <Fonts/FreeMonoOblique24pt7b.h>   
//=========================== FreeMonoBoldOblique Family =============
#include <Fonts/FreeMonoBoldOblique9pt7b.h>    
#include <Fonts/FreeMonoBoldOblique12pt7b.h>   
#include <Fonts/FreeMonoBoldOblique18pt7b.h>   
#include <Fonts/FreeMonoBoldOblique24pt7b.h>   
//=========================== define all shotcut fonts =================
// Dufualt small and Big Font
#define SmallFont                 &FreeSmallFont
#define BigFont                   &FreeBigFont
#define FONT_SMALL                &FreeSmallFont
#define FONT_BIG                  &FreeBigFont
// SebenSegment
#define FONT_SEVENSEGMENT         &FreeSevenSegNumFont
// FreeSans
#define FONT_FREESANS_SMALL       &FreeSans9pt7b
#define FONT_FREESANS_MEDIUM      &FreeSans12pt7b
#define FONT_FREESANS_BIG         &FreeSans18pt7b
#define FONT_FREESANS_VERYBIG     &FreeSans24pt7b
// FreeSansBold
#define FONT_FREESANSBOLD_SMALL       &FreeSansBold9pt7b
#define FONT_FREESANSBOLD_MEDIUM      &FreeSansBold12pt7b
#define FONT_FREESANSBOLD_BIG         &FreeSansBold18pt7b
#define FONT_FREESANSBOLD_VERYBIG     &FreeSansBold24pt7b
// FreeSansOblique
#define FONT_FREESANSOBLIQUE_SMALL       &FreeSansOblique9pt7b
#define FONT_FREESANSOBLIQUE_MEDIUM      &FreeSansOblique12pt7b
#define FONT_FREESANSOBLIQUE_BIG         &FreeSansOblique18pt7b
#define FONT_FREESANSOBLIQUE_VERYBIG     &FreeSansOblique24pt7b
// FreeSerif
#define FONT_FREESERIF_SMALL       &FreeSerif9pt7b
#define FONT_FREESERIF_MEDIUM      &FreeSerif12pt7b
#define FONT_FREESERIF_BIG         &FreeSerif18pt7b
#define FONT_FREESERIF_VERYBIG     &FreeSerif24pt7b
// FreeSerifBold
#define FONT_FREESERIFBOLD_SMALL       &FreeSerifBold9pt7b
#define FONT_FREESERIFBOLD_MEDIUM      &FreeSerifBold12pt7b
#define FONT_FREESERIFBOLD_BIG         &FreeSerifBold18pt7b
#define FONT_FREESERIFBOLD_VERYBIG     &FreeSerifBold24pt7b
// FreeSerifItalic
#define FONT_FREESERIFITALIC_SMALL       &FreeSerifItalic9pt7b
#define FONT_FREESERIFITALIC_MEDIUM      &FreeSerifItalic12pt7b
#define FONT_FREESERIFITALIC_BIG         &FreeSerifItalic18pt7b
#define FONT_FREESERIFITALIC_VERYBIG     &FreeSerifItalic24pt7b
// FreeSerifBoldItalic
#define FONT_FREESERIFBOLDITALIC_SMALL       &FreeSerifBoldItalic9pt7b
#define FONT_FREESERIFBOLDITALIC_MEDIUM      &FreeSerifBoldItalic12pt7b
#define FONT_FREESERIFBOLDITALIC_BIG         &FreeSerifBoldItalic18pt7b
#define FONT_FREESERIFBOLDITALIC_VERYBIG     &FreeSerifBoldItalic24pt7b
// FreeMono
#define FONT_FREEMONO_SMALL       &FreeMono9pt7b
#define FONT_FREEMONO_MEDIUM      &FreeMono12pt7b
#define FONT_FREEMONO_BIG         &FreeMono18pt7b
#define FONT_FREEMONO_VERYBIG     &FreeMono24pt7b
// FreeMonoBold
#define FONT_FREEMONOBOLD_SMALL       &FreeMonoBold9pt7b
#define FONT_FREEMONOBOLD_MEDIUM      &FreeMonoBold12pt7b
#define FONT_FREEMONOBOLD_BIG         &FreeMonoBold18pt7b
#define FONT_FREEMONOBOLD_VERYBIG     &FreeMonoBold24pt7b
// FreeMonoOblique
#define FONT_FREEMONOOBLIQUE_SMALL       &FreeMonoOblique9pt7b
#define FONT_FREEMONOOBLIQUE_MEDIUM      &FreeMonoOblique12pt7b
#define FONT_FREEMONOOBLIQUE_BIG         &FreeMonoOblique18pt7b
#define FONT_FREEMONOOBLIQUE_VERYBIG     &FreeMonoOblique24pt7b
// FreeMonoBoldOblique
#define FONT_FREEMONOBOLDOBLIQUE_SMALL       &FreeMonoBoldOblique9pt7b
#define FONT_FREEMONOBOLDOBLIQUE_MEDIUM      &FreeMonoBoldOblique12pt7b
#define FONT_FREEMONOBOLDOBLIQUE_BIG         &FreeMonoBoldOblique18pt7b
#define FONT_FREEMONOBOLDOBLIQUE_VERYBIG     &FreeMonoBoldOblique24pt7b
//=======================================================================================
#endif /* SEDHOM_DISPLAY_FONTS_H_ */
