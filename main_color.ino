//heading
#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>
#include <ezButton.h>

#define cs   15   
#define dc   26  
#define rst   4   

#define S0 12 
#define S1 13 
#define S2 27 
#define S3 14 
#define sensorOut 32 


// Color definitions
#define  SPRING_GREEN  0x7D2D
#define MEDIUM_SPRING_GREEN 0x8D4D
#define DARK_SEA_GREEN  0x9593
#define PALE_GREEN  0x95D4
#define LIGHT_GREEN 0x8DB3
#define PEACH_PUFF  0xAE1C
#define NAVAJO_WHITE  0xA61C
#define MOCCASIN  0xAE3C
#define ROSY_BROWN  0xA496
#define TAN 0x9D79
#define DARK_SLATE_GRAY 0x630A
#define LIGHT_SEA_GREEN 0xAD06
#define MEDIUM_SEA_GREEN  0x74EC
#define MEDIUM_AQUA_MARINE  0xA58F
#define SEA_GREEN 0x744A
#define PAPAYA_WHIP 0xC67B
#define OLD_LACE  0xD69B
#define LINEN 0xD69B
#define LAVENDER_BLUSH  0xDE9B
#define MISTY_ROSE  0xCE5B
#define GREEN_YELLOW  0x6595
#define CHARTREUSE  0x6552
#define LAWN_GREEN  0x6532
#define OLIVE_DRAB  0x6470
#define DARK_OLIVE_GREEN  0x63CE
#define SADDLE_BROWN  0x6B72
#define LIGHT_YELLOW  0xCEDB
#define LIGHT_GOLDER_ROD_YELLOW 0xC6BB
#define LEMON_CHIFFON 0xBEBB
#define CORN_SILK 0xCEBB
#define LIME_GREEN  0x6CED
#define LIME  0x6CCD
#define FOREST_GREEN  0x6C4D
#define GREEN 0x6C0C
#define DARK_GREEN  0x0B8C
#define BURLY_WOOD  0x9559
#define SANDY_BROWN 0x7CBA
#define PERU  0x6C18
#define CHOCOLATE 0x6BD8
#define SIENNA  0x6B74
#define CRIMSON 0x7377
#define FIREBRICK 0x7374
#define BROWN 0x7353
#define DARK_RED  0x6B52
#define MAROON  0x6B52
#define DARK_MAGENTA  0x8AF1
#define MEDIUM_PURPLE 0xC430
#define MEDIUM_SLATE_BLUE 0xC42E
#define SLATE_BLUE  0xBBCC
#define DARK_SLATE_BLUE 0xA349
#define LIGHT_CORAL 0x8439
#define INDIAN_RED  0x7B77
#define CORAL 0x6C3A
#define TOMATO  0x6BDA
#define RED 0x7379
#define THISTLE 0xD5B8
#define PURPLE  0x82F0
#define MEDIUM_ORCHID 0xB394
#define DARK_ORCHID 0xAB30
#define DARK_VIOLET 0xA310
#define DARK_ORANGE 0x647B
#define ORANGE_RED  0x6B9A
#define LIGHT_SALMON  0x84BB
#define SALMON  0x7C3A
#define DARK_SALMON 0x8C9A
#define MEDIUM_VIOLET_RED 0x82F5
#define ORCHID  0xBBF7
#define FUCHSIA 0xA2F8
#define VIOLET  0xC478
#define PLUM  0xCCF8
#define PALE_GOLDEN_ROD 0xA63A
#define GOLDEN_ROD  0x64BA
#define DARK_GOLDEN_ROD 0x6C37
#define GOLD  0x5D7C
#define ORANGE  0x64DB
#define PINK  0xB59B
#define LIGHT_PINK  0xAD5A
#define HOT_PINK  0x9419
#define DEEP_PINK 0x8339
#define PALE_VIOLET_RED 0x93F8
#define YELLOW_GREEN  0x5D74
#define YELLOW  0x5DFD
#define OLIVE 0x6C32
#define KHAKI 0x8DFB
#define DARK_KHAKI  0x8557
#define WHEAT 0xAE1B
#define BLANCHED_ALMOND 0xBE5B
#define BISQUE  0xBE3B
#define BEIGE 0xCE9A
#define ANTIQUE_WHITE 0xC67B
#define DEEP_SKY_BLUE 0xD528
#define CORN_FLOWER_BLUE  0xD52D
#define STEEL_BLUE  0xBC48
#define CADET_BLUE  0xA4CD
#define POWDER_BLUE 0xD635
#define DIM_GRAY  0x7B8E
#define BLACK 0x39E8
#define SNOW  0xDEBB
#define AZURE 0xDEDA
#define IVORY 0xDEDB
#define MIDNIGHT_BLUE 0x9349
#define LIGHT_SKY_BLUE  0xE610
#define SKY_BLUE  0xDE11
#define LIGHT_BLUE  0xD634
#define DODGER_BLUE 0x1CCA
#define GAINSBORO 0xD638
#define LIGHT_GREY  0xCE38
#define SILVER  0xC5D8
#define DARK_GREY 0xB534
#define GREY  0x9430
#define ROYAL_BLUE  0xC449
#define BLUE  0xB387
#define MEDIUM_BLUE 0xA368
#define DARK_BLUE 0x9B49
#define NAVY  0x9349
#define INDIGO  0x9B2C
#define BLUE_VIOLET 0xB36F
#define WHITE 0xDEDA
#define WHITE_SMOKE 0xDEBA
#define LIGHT_CYAN  0xDEB8
#define CYAN  0xD5AA
#define AQUA  0xD5AA
#define DARK_CYAN 0xA4A0
#define TEAL  0x9C80
#define LIGHT_STEEL_BLUE  0xDDF4
#define LIGHT_SLATE_GRAY  0xA46F
#define SLATE_GRAY  0x9C2F
#define MINT_CREAM  0xDEDA
#define SEA_SHELL 0xD6BB
#define AQUA_MARINE 0xBDF1
#define PALE_TURQUOISE  0xD655
#define MEDIUM_TURQUOISE  0xC58C
#define TURQUOISE 0xBD8D
#define DARK_TURQUOISE  0xC568
#define HONEYDEW  0xD6BA
#define GHOST_WHITE 0xE6BA
#define ALICE_BLUE  0xDEBA
#define FLORAL_WHITE  0xDEBB
#define LAVENDER  0xDE78

// Definisi pin CS, DC dan Reset pada TFT
Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);

int button_current_state = HIGH;
byte redfrequency = 0;
byte bluefrequency = 0;
byte greenfrequency = 0;

byte R = 0;
byte G = 0;
byte B = 0;

int last_state = 1;
int current_state = 1;
