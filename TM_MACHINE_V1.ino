

// ============================================================                                                            
// TM_MACHINE_COCKTAIL_V1.2                          
// ============================================================
// Auteur:       Oscar Janossy
// Dernière modification : 31.12.2019                                     
// ============================================================ 
// Descripton:  
// Ce programme permet de faire fonctionner la machine à cocktail sur un Arduino Mega.
// Le programme est basé sur la librairie facilitant la création de menus 
// de Nils Feldkämper "LCDMenuLIB" publiée en OpenSource 3.0 à l'adresse : https://github.com/Jomelo/LCDMenuLib/tree/v2.3.5

// ============================================================ 


  // include libs
  #include <Wire.h>                 //https://www.arduino.cc/en/reference/wire
  #include <LiquidCrystal_I2C.h>    //https://bitbucket.org/fmalpartida/new-liquidcrystal/src/integration/
  #include <LCDMenuLib.h>           //https://github.com/Jomelo/LCDMenuLib/tree/v2.3.5
  #include <HX711.h>                //https://github.com/bogde/HX711
  #include <Adafruit_NeoPixel.h>    //https://github.com/adafruit/Adafruit_NeoPixel
  #include <NewPing.h>              //https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
  
  // lib config
  #define _LCDML_DISP_cfg_button_press_time          200    // button press time in ms
  #define _LCDML_DISP_cfg_initscreen_time            60000  // enable initscreen time
  #define _LCDML_DISP_cfg_scrollbar                  1      // enable a scrollbar
  #define _LCDML_DISP_cfg_cursor                     0x7E   // cursor Symbol 

// ********************************************************************* 
// LCDML TYPE SELECT
// *********************************************************************
  // settings for lcd 
  #define _LCDML_DISP_cols             20
  #define _LCDML_DISP_rows             4  

  // lcd object
  //LiquidCrystal_I2C lcd(0x27);  // Set the LCD I2C address
  //LiquidCrystal_I2C lcd(0x27, BACKLIGHT_PIN, POSITIVE);  // Set the LCD I2C address
  LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

  
  
  const uint8_t scroll_bar[5][8] = {
    {B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001}, // scrollbar top
    {B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001}, // scroll state 1 
    {B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001}, // scroll state 2
    {B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001}, // scroll state 3
    {B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111}  // scrollbar bottom
  }; 



// *********************************************************************
// LCDML MENU/DISP
// *********************************************************************
  // create menu
  // menu element count - last element id
  // this value must be the same as the last menu element
  #define _LCDML_DISP_cnt    58
  
  // LCDML_root        => layer 0 
  // LCDML_root_X      => layer 1 
  // LCDML_root_X_X    => layer 2 
  // LCDML_root_X_X_X  => layer 3 
  // LCDML_root_... 	 => layer ... 
  
  // LCDMenuLib_add(id, group, prev_layer_element, new_element_num, lang_char_array, callback_function)
  LCDML_DISP_init(_LCDML_DISP_cnt);
  LCDML_DISP_add      (0  , _LCDML_G1  , LCDML_root        , 1  , "IBA Cocktails"        , LCDML_FUNC);
  LCDML_DISP_add      (1  , _LCDML_G1  , LCDML_root_1      , 1  , "BACARDI"              , LCDML_FUNC_BACARDI);
  LCDML_DISP_add      (2  , _LCDML_G1  , LCDML_root_1      , 2  , "BETWEEN THE SHEETS"   , LCDML_FUNC_BETWEEN_THE_SHEETS);
  LCDML_DISP_add      (3  , _LCDML_G1  , LCDML_root_1      , 3  , "COSMOPOLITAN"         , LCDML_FUNC_COSMOPOLITAN);
  LCDML_DISP_add      (4  , _LCDML_G1  , LCDML_root_1      , 4  , "CUBA LIBRE"           , LCDML_FUNC_CUBA_LIBRE);
  LCDML_DISP_add      (5  , _LCDML_G1  , LCDML_root_1      , 5  , "KAMIKAZE"             , LCDML_FUNC_KAMIKAZE);
  LCDML_DISP_add      (6  , _LCDML_G1  , LCDML_root_1      , 6  , "LEMON DROP MARTINI"   , LCDML_FUNC_LEMON_DROP_MARTINI);
  LCDML_DISP_add      (7  , _LCDML_G1  , LCDML_root_1      , 7  , "LONG ISLAND TEA "     , LCDML_FUNC_LONG_ISLAND_TEA);
  LCDML_DISP_add      (8  , _LCDML_G1  , LCDML_root_1      , 8  , "MARGARITA"            , LCDML_FUNC_MARGARITA);
  LCDML_DISP_add      (9  , _LCDML_G1  , LCDML_root_1      , 9  , "PARADISE"             , LCDML_FUNC_PARADISE);
  LCDML_DISP_add      (10 , _LCDML_G1  , LCDML_root_1      , 10 , "SCREWDRIVER"          , LCDML_FUNC_SCREWDRIVER);
  LCDML_DISP_add      (11 , _LCDML_G1  , LCDML_root_1      , 11 , "SEX ON THE BEACH"     , LCDML_FUNC_SEX_ON_THE_BEACH);
  LCDML_DISP_add      (12 , _LCDML_G1  , LCDML_root_1      , 12 , "SIDECAR"              , LCDML_FUNC_SIDECAR);  
  LCDML_DISP_add      (13 , _LCDML_G1  , LCDML_root_1      , 13 , "TEQUILA SUNRISE"      , FUNC_TEQUILA_SUNRISE);  
  LCDML_DISP_add      (14 , _LCDML_G1  , LCDML_root_1      , 14 , "WHITE LADY"           , LCDML_FUNC_WHITE_LADY);
  LCDML_DISP_add      (15 , _LCDML_G1  , LCDML_root        , 2  , "Cocktails"            , LCDML_FUNC);
  LCDML_DISP_add      (16 , _LCDML_G1  , LCDML_root_2      , 1  , "AMBER COOLER"         , LCDML_FUNC_AMBER_COOLER);
  LCDML_DISP_add      (17 , _LCDML_G1  , LCDML_root_2      , 2  , "ALELLUIA"             , LCDML_FUNC_ALELLUIA);
  LCDML_DISP_add      (18 , _LCDML_G1  , LCDML_root_2      , 3  , "APRICOT"              , LCDML_FUNC_APRICOT);
  LCDML_DISP_add      (19 , _LCDML_G1  , LCDML_root_2      , 4  , "BELLE OF ST MARY'S"   , LCDML_FUNC_BELLES);
  LCDML_DISP_add      (20 , _LCDML_G1  , LCDML_root_2      , 5  , "BLUE ARROW"           , LCDML_FUNC_BLUE_ARROW);
  LCDML_DISP_add      (21 , _LCDML_G1  , LCDML_root_2      , 6  , "BLUE LADY"            , LCDML_FUNC_BLUE_LADY);
  LCDML_DISP_add      (22 , _LCDML_G1  , LCDML_root_2      , 7  , "BLUE LAGOON"          , LCDML_FUNC_BLUE_LAGOON);    
  LCDML_DISP_add      (23 , _LCDML_G1  , LCDML_root_2      , 8  , "BLUE MARGARITA"       , LCDML_FUNC_BLUE_MARGARITA);
  LCDML_DISP_add      (24 , _LCDML_G1  , LCDML_root_2      , 9  , "BOSTON SIDECAR"       , LCDML_FUNC_BOSTON_SIDECAR);
  LCDML_DISP_add      (25 , _LCDML_G1  , LCDML_root_2      , 10 , "CAPE CODDER"          , LCDML_FUNC_CAPE_CODDER);
  LCDML_DISP_add      (26 , _LCDML_G1  , LCDML_root_2      , 11 , "EXPLORER"             , LCDML_FUNC_EXPLORER);
  LCDML_DISP_add      (27 , _LCDML_G1  , LCDML_root_2      , 12 , "ICE BEAR"             , LCDML_FUNC_ICE_BEAR);
  LCDML_DISP_add      (28 , _LCDML_G1  , LCDML_root_2      , 13 , "INK MARTINI"          , LCDML_FUNC_INK_MARTINI);
  LCDML_DISP_add      (29 , _LCDML_G1  , LCDML_root_2      , 14 , "JUICY"                , LCDML_FUNC_JUICY);
  LCDML_DISP_add      (30 , _LCDML_G1  , LCDML_root_2      , 15 , "GIMLET"               , LCDML_FUNC_GIMLET);
  LCDML_DISP_add      (31 , _LCDML_G1  , LCDML_root_2      , 16 , "LADY LYSSNA"          , LCDML_FUNC_LADY_LYSSNA);
  LCDML_DISP_add      (32 , _LCDML_G1  , LCDML_root_2      , 17 , "ORANGE MARGARITA"     , LCDML_FUNC_ORANGE_MARGARITA);
  LCDML_DISP_add      (33 , _LCDML_G1  , LCDML_root_2      , 18 , "TOJO"                 , LCDML_FUNC_TOJO);
  LCDML_DISP_add      (34 , _LCDML_G1  , LCDML_root_2      , 19 , "WOO WOO"              , LCDML_FUNC_WOOWOO);
  LCDML_DISP_add      (35 , _LCDML_G1  , LCDML_root        , 3  , "Sans Alcool"          , LCDML_FUNC);
  LCDML_DISP_add      (36 , _LCDML_G1  , LCDML_root_3      , 1  , "Coca-Cola"            , LCDML_FUNC_COKE);
  LCDML_DISP_add      (37 , _LCDML_G1  , LCDML_root_3      , 2  , "Jus de Cranberry"     , LCDML_FUNC_CRANBERRY );
  LCDML_DISP_add      (38 , _LCDML_G1  , LCDML_root_3      , 3  , "Jus d'orange"         , LCDML_FUNC_ORANGE );  
  LCDML_DISP_add      (39 , _LCDML_G1  , LCDML_root_3      , 4  , "Sprite"               , LCDML_FUNC_SPRITE );
  LCDML_DISP_add      (40 , _LCDML_G1  , LCDML_root_3      , 5  , "Keep Sober"           , LCDML_FUNC_KEEP_SOBER);
  LCDML_DISP_add      (41 , _LCDML_G1  , LCDML_root_3      , 6  , "Arabian Sunrise"      , LCDML_FUNC_ARABIAN_SUN);
  LCDML_DISP_add      (57 , _LCDML_G1  , LCDML_root_3      , 7  , "Jus de citron"        , LCDML_FUNC_LIME);
  LCDML_DISP_add      (58 , _LCDML_G1  , LCDML_root_3      , 8  , "Sirop grenadine"      , LCDML_FUNC_GRENADINE); 
  LCDML_DISP_add      (42 , _LCDML_G1  , LCDML_root        , 4  , "Shots"                , LCDML_FUNC);
  LCDML_DISP_add      (43 , _LCDML_G1  , LCDML_root_4      , 1  , "Vodka"                , LCDML_FUNC_VODKA);
  LCDML_DISP_add      (44 , _LCDML_G1  , LCDML_root_4      , 2  , "Curacao bleu"         , LCDML_FUNC_CURACAO);
  LCDML_DISP_add      (45 , _LCDML_G1  , LCDML_root_4      , 3  , "Gin"                  , LCDML_FUNC_GIN);
  LCDML_DISP_add      (46 , _LCDML_G1  , LCDML_root_4      , 4  , "Rhum blanc"           , LCDML_FUNC_RHUMBLANC);
  LCDML_DISP_add      (47 , _LCDML_G1  , LCDML_root_4      , 5  , "Tequila"              , LCDML_FUNC_TEQUILA);
  LCDML_DISP_add      (48 , _LCDML_G1  , LCDML_root_4      , 6  , "Cointreau"            , LCDML_FUNC_COINTREAU);
  LCDML_DISP_add      (49 , _LCDML_G1  , LCDML_root_4      , 7  , "Liqueur de peche"     , LCDML_FUNC_PECHE);
  LCDML_DISP_add      (50 , _LCDML_G1  , LCDML_root_4      , 8  , "Abricot brandy"       , LCDML_FUNC_BRANDY);
  LCDML_DISP_add      (51 , _LCDML_G1  , LCDML_root_4      , 9  , "Stop and Go Naked"    , LCDML_FUNC_STOP_AND_GO_NAKED);
  LCDML_DISP_add      (52 , _LCDML_G1  , LCDML_root        , 5  , "Balance"              , LCDML_FUNC_BALANCE);
  LCDML_DISP_add      (53 , _LCDML_G1  , LCDML_root        , 6  , "Nettoyage"            , LCDML_FUNC);
  LCDML_DISP_add      (54 , _LCDML_G1  , LCDML_root_6      , 1  , "RECUPERATION"         , LCDML_FUNC_CLEAN_RECUP);
  LCDML_DISP_add      (55 , _LCDML_G1  , LCDML_root_6      , 2  , "NETTOYAGE A EAU"      , LCDML_FUNC_CLEAN_EAU);
  LCDML_DISP_add      (56 , _LCDML_G7  , LCDML_root        , 7  , "initscreen"           , LCDML_FUNC_initscreen);

  LCDML_DISP_createMenu(_LCDML_DISP_cnt);



// ********************************************************************* 
// LCDML BACKEND (core of the menu)
// ********************************************************************* 
  // define backend function  
  #define _LCDML_BACK_cnt    2  // last backend function id
  
  LCDML_BACK_init(_LCDML_BACK_cnt);
  LCDML_BACK_new_timebased_dynamic (0  , ( 20UL )         , _LCDML_start  , LCDML_BACKEND_control);
  LCDML_BACK_new_timebased_dynamic (1  , ( 1000UL )       , _LCDML_stop   , LCDML_BACKEND_menu);
  LCDML_BACK_new_timebased_dynamic (2  , ( 20UL )       , _LCDML_start   , LCDML_BACKEND_RAINBOW);

  LCDML_BACK_create();

// ********************************************************************* 
// SCALE (setup)
// *********************************************************************

  #define calibration_factor 835 //This value is obtained using the SparkFun_HX711_Calibration sketch

  #define DOUT  3
  #define CLK  4
  
  const int poid_minimal =5;
  
// ********************************************************************* 
// Ultrasonic sensor (setup)
// https://www.makerguides.com/hc-sr04-arduino-tutorial/
// *********************************************************************

    #define trigPin  5
    #define echoPin  6
    #define MAX_DISTANCE 350 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
    
    NewPing sonar(trigPin, echoPin, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
    
    float duration, distance;
    const int distance_verre =20; //DISTANCE DE DETECTION DU VERRE
    
// ********************************************************************* 
// TIMER NETTOYAGE
// *********************************************************************

  unsigned long previousMillis = 0;        // will store last time LED was updated
  const long interval = 1000;              // interval at which to blink (milliseconds)
  signed short nombre =30;

// ********************************************************************* 
// PUMPS (setup)
// *********************************************************************

  #define PUMP1_IN1   49        //control pin for first motor   //  vodka
  #define PUMP1_IN2   48        //control pin for first motor
  #define PUMP2_IN1   28       //control pin for second motor   //  Gin
  #define PUMP2_IN2   29       //control pin for second motor
  #define PUMP3_IN1   27       //control pin for third motor    //  Curacao
  #define PUMP3_IN2   26       //control pin for third motor
  #define PUMP4_IN1   45       //control pin for fourth motor   //  Cointreau
  #define PUMP4_IN2   44       //control pin for fourth motor
  #define PUMP5_IN1   30       //control pin for fifth motor    //  Rhum blanc
  #define PUMP5_IN2   31       //control pin for fifth motor
  #define PUMP6_IN1   47       //control pin for sixth motor    //  Tequila
  #define PUMP6_IN2   46       //control pin for sixth motor
  #define PUMP7_IN1   42       //control pin for 7th motor      //  Coca-Cola
  #define PUMP7_IN2   43       //control pin for 7th motor
  #define PUMP8_IN1   51       //control pin for 8th motor      //  Jus de Cramberry
  #define PUMP8_IN2   50       //control pin for 8th motor
  #define PUMP9_IN1   36       //control pin for 9th motor      //  Jus d'orange
  #define PUMP9_IN2   37       //control pin for 9th motor
  #define PUMP10_IN1  24       //control pin for 10th motor     //  Sprite
  #define PUMP10_IN2  25       //control pin for 10th motor
  #define PUMP11_IN1  32       //control pin for 11th motor     //  Sirop Grenadine
  #define PUMP11_IN2  33       //control pin for 11th motor
  #define PUMP12_IN1  34       //control pin for 12th motor     //  Jus de citron
  #define PUMP12_IN2  35       //control pin for 12th motor
  #define PUMP13_IN1  41       //control pin for 13th motor     //  Liqueur de pêche
  #define PUMP13_IN2  40       //control pin for 13th motor
  #define PUMP14_IN1  38       //control pin for 14th motor     //  Liqueur d'abricot
  #define PUMP14_IN2  39       //control pin for 14th motor



// ********************************************************************* 
// NEOPIXEL 
//https://learn.adafruit.com/multi-tasking-the-arduino-part-3/put-it-all-together-dot-dot-dot
// *********************************************************************
   #define PIN_PIXEL 12   // input pin Neopixel is attached to

   #define NUMPIXELS      65 // number of neopixels in strip    
    

   int delayval = 50; // timing delay in milliseconds

   int redColor   = 0;
   int greenColor = 0;
   int blueColor  = 0;


  // Pattern types supported:
enum  pattern { NONE, RAINBOW_CYCLE, CLEARSTRIP, THEATER_CHASE };
// Patern directions supported:
enum  direction { FORWARD, REVERSE };

// NeoPattern Class - derived from the Adafruit_NeoPixel class
class NeoPatterns : public Adafruit_NeoPixel
{
    public:

    // Member Variables:  
    pattern  ActivePattern;  // which pattern is running
    direction Direction;     // direction to run the pattern
    
    unsigned long Interval;   // milliseconds between updates
    unsigned long lastUpdate; // last update of position
    
    uint32_t Color1, Color2;  // What colors are in use
    uint16_t TotalSteps;  // total number of steps in the pattern
    uint16_t Index;  // current step within the pattern
    
    void (*OnComplete)();  // Callback on completion of pattern
    
    // Constructor - calls base-class constructor to initialize strip
    NeoPatterns(uint16_t pixels, uint8_t pin, uint8_t type, void (*callback)())
    :Adafruit_NeoPixel(pixels, pin, type)
    {
        OnComplete = callback;
    }
    
    // Update the pattern
    void Update()
    {
        if((millis() - lastUpdate) > Interval) // time to update
        {
            lastUpdate = millis();
            switch(ActivePattern)
            {
                case RAINBOW_CYCLE:
                    RainbowCycleUpdate();
                    break;
                case CLEARSTRIP:
                    clearstripUpdate();
                    break;
                case THEATER_CHASE:
                    TheaterChaseUpdate();
                    break;
                default:
                    break;
            }
        }
    }
  
    // Increment the Index and reset at the end
    void Increment()
    {
        if (Direction == FORWARD)
        {
           Index++;
           if (Index >= TotalSteps)
            {
                Index = 0;
                if (OnComplete != NULL)
                {
                    OnComplete(); // call the comlpetion callback
                }
            }
        }
        else // Direction == REVERSE
        {
            --Index;
            if (Index <= 0)
            {
                Index = TotalSteps-1;
                if (OnComplete != NULL)
                {
                    OnComplete(); // call the comlpetion callback
                }
            }
        }
    }
    
    // Reverse pattern direction
    void Reverse()
    {
        if (Direction == FORWARD)
        {
            Direction = REVERSE;
            Index = TotalSteps-1;
        }
        else
        {
            Direction = FORWARD;
            Index = 0;
        }
    }
    
    // Initialize for a RainbowCycle
    void RainbowCycle(uint8_t interval, direction dir = FORWARD)
    {
        ActivePattern = RAINBOW_CYCLE;
        Interval = interval;
        TotalSteps = 255;
        Index = 0;
        Direction = dir;
    }
    
    // Update the Rainbow Cycle Pattern
    void RainbowCycleUpdate()
    {
        for(int i=0; i< numPixels(); i++)
        {
            setPixelColor(i, Wheel(((i * 256 / numPixels()) + Index) & 255));
        }
        show();
        Increment();
    }


    // Initialize for a RainbowCycle
    void clearstrip(uint8_t interval, direction dir = FORWARD)
    {
        ActivePattern = CLEARSTRIP;
        Interval = interval;
        TotalSteps = 255;
        Index = 0;
        Direction = dir;
    }
    
    // Update the Rainbow Cycle Pattern
    void clearstripUpdate()
    {
        for(int i=0; i< numPixels(); i++)
        {
            setPixelColor(i, 0,0,0);
        }
        show();
        Increment();
    }
     // Initialize for a Theater Chase
    void TheaterChase(uint32_t color1, uint32_t color2, uint8_t interval, direction dir = FORWARD)
    {
        ActivePattern = THEATER_CHASE;
        Interval = interval;
        TotalSteps = numPixels();
        Color1 = color1;
        Color2 = color2;
        Index = 0;
        Direction = dir;
   }
    
    // Update the Theater Chase Pattern
    void TheaterChaseUpdate()
    {
        for(int i=0; i< numPixels(); i++)
        {
            if ((i + Index) % 3 == 0)
            {
                setPixelColor(i, Color1);
            }
            else
            {
                setPixelColor(i, Color2);
            }
        }
        show();
        Increment();
    }

   
   
    // Calculate 50% dimmed version of a color (used by ScannerUpdate)
    uint32_t DimColor(uint32_t color)
    {
        // Shift R, G and B components one bit to the right
        uint32_t dimColor = Color(Red(color) >> 1, Green(color) >> 1, Blue(color) >> 1);
        return dimColor;
    }

    // Set all pixels to a color (synchronously)
    void ColorSet(uint32_t color)
    {
        for (int i = 0; i < numPixels(); i++)
        {
            setPixelColor(i, color);
        }
        show();
    }

    // Returns the Red component of a 32-bit color
    uint8_t Red(uint32_t color)
    {
        return (color >> 16) & 0xFF;
    }

    // Returns the Green component of a 32-bit color
    uint8_t Green(uint32_t color)
    {
        return (color >> 8) & 0xFF;
    }

    // Returns the Blue component of a 32-bit color
    uint8_t Blue(uint32_t color)
    {
        return color & 0xFF;
    }
    
    // Input a value 0 to 255 to get a color value.
    // The colours are a transition r - g - b - back to r.
    uint32_t Wheel(byte WheelPos)
    {
        WheelPos = 255 - WheelPos;
        if(WheelPos < 85)
        {
            return Color(255 - WheelPos * 3, 0, WheelPos * 3);
        }
        else if(WheelPos < 170)
        {
            WheelPos -= 85;
            return Color(0, WheelPos * 3, 255 - WheelPos * 3);
        }
        else
        {
            WheelPos -= 170;
            return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
        }
    }
};


void pixelsComplete();


// Define some NeoPatterns for the two rings and the stick
//  as well as some completion routines

NeoPatterns pixels(100, 12, NEO_GRB + NEO_KHZ800, &pixelsComplete);
// Pixels Completion Callback
void pixelsComplete()
{
    
        pixels.RainbowCycle(random(0,10));
    }

  

// ********************************************************************* 
// MASSES VOLUMIQUES 
// *********************************************************************
   //ALCOOLS
    const float rho_vodka = 0.95;
    const float rho_gin = 0.95;
    const float rho_curacao = 1.11;
    const float rho_cointreau = 1.09;
    const float rho_rhum_blanc = 0.95;
    const float rho_tequila = 0.95;
    const float rho_liqueur_peche = 1.09;
    const float rho_liqueur_brandy = 1.09;

   //SOFTS
    const float rho_cola = 1.04;
    const float rho_cranberry = 1;
    const float rho_orange = 1.04;
    const float rho_sprite = 1.02;
    const float rho_grenadine = 1.18;
    const float rho_lime = 1;
    
// ********************************************************************* 
// AUTRES 
// *********************************************************************   
      
   int volume;     
   
   const int involontaire = 1000; // temps nécessaire pour éviter une action par inadvertance
   int total_cocktail =0; // nombres de cocktails fait
   
// *********************************************************************
// SETUP
// *********************************************************************
  
  
  void setup()
  { 
  
    
      
    //PUMPS PINMODE
      pinMode(PUMP1_IN1, OUTPUT);    
      pinMode(PUMP1_IN2, OUTPUT);
      pinMode(PUMP2_IN1, OUTPUT);    
      pinMode(PUMP2_IN2, OUTPUT);
      pinMode(PUMP3_IN1, OUTPUT);    
      pinMode(PUMP3_IN2, OUTPUT);
      pinMode(PUMP4_IN1, OUTPUT);    
      pinMode(PUMP4_IN2, OUTPUT);
      pinMode(PUMP5_IN1, OUTPUT);    
      pinMode(PUMP5_IN2, OUTPUT);
      pinMode(PUMP6_IN1, OUTPUT);    
      pinMode(PUMP6_IN2, OUTPUT);
      pinMode(PUMP7_IN1, OUTPUT);    
      pinMode(PUMP7_IN2, OUTPUT);
      pinMode(PUMP8_IN1, OUTPUT);    
      pinMode(PUMP8_IN2, OUTPUT);
      pinMode(PUMP9_IN1, OUTPUT);    
      pinMode(PUMP9_IN2, OUTPUT);
      pinMode(PUMP10_IN1, OUTPUT);    
      pinMode(PUMP10_IN2, OUTPUT);
      pinMode(PUMP11_IN1, OUTPUT);    
      pinMode(PUMP11_IN2, OUTPUT);
      pinMode(PUMP12_IN1, OUTPUT);    
      pinMode(PUMP12_IN2, OUTPUT);
      pinMode(PUMP13_IN1, OUTPUT);    
      pinMode(PUMP13_IN2, OUTPUT);
      pinMode(PUMP14_IN1, OUTPUT);    
      pinMode(PUMP14_IN2, OUTPUT);
      
    // LCD Begin
      lcd.begin(_LCDML_DISP_cols,_LCDML_DISP_rows);
      
    // Initialize the NeoPixel library.
       pixels.begin();
       pixels.setBrightness(60); // 1/4 brightness
       pixels.clear();
       pixels.show();
       
   
       
    //INIT SCREEN
      lcd.setCursor(0, 0);
      lcd.print("COCKTAIL MACHINE");
      lcd.setCursor(0, 1);
      lcd.print("V: 1.2");;
      delay(1000);   
    
    
    // serial init;    
       Serial.begin(9600);                // start serial    
       Serial.println("DEBUT DU PROGRAMME"); // debut du programme
    
    //SCALE BEGIN
    //detection=digitalRead(capteur); // on lit la broche capteur
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;
      
     // la sortie OUT du capteur est active sur niveau bas
      while (distance<distance_verre) { // objet détecté = distance inférieure a la longueur de la plateforme
       
      duration = sonar.ping();
      distance = (duration / 2) * 0.0343;

       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("Enlever le verre");

       setColorred();
       
       Serial.println("ERREUR");
       delay(100);
       pixels.clear();
       pixels.show();
       delay(100);
       
      }
    delay(500); 
    
    scale.begin(DOUT, CLK);
    scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
    scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  
    lcd.clear();
    lcd.home ();                   // go home
    lcd.clear();       
    // set special chars for scrollbar
    lcd.createChar(0, (uint8_t*)scroll_bar[0]);
    lcd.createChar(1, (uint8_t*)scroll_bar[1]);
    lcd.createChar(2, (uint8_t*)scroll_bar[2]);
    lcd.createChar(3, (uint8_t*)scroll_bar[3]);
    lcd.createChar(4, (uint8_t*)scroll_bar[4]);
    lcd.setCursor(0,0);
    lcd.print(F("booting"));
  
    // Enable all items with _LCDML_G1
    LCDML_DISP_groupEnable(_LCDML_G1); // enable group 1
    
    // Enable menu rollover if needed
    LCDML.enRollover();
  
    // LCDMenu Setup
    LCDML_setup(_LCDML_BACK_cnt);


    

  }

// *********************************************************************
// LOOP
// *********************************************************************
  void loop()
  { 
    // example for init screen   
    if((millis() - g_lcdml_initscreen) >= _LCDML_DISP_cfg_initscreen_time) {
      g_lcdml_initscreen = millis(); // reset init screen time
      LCDML_DISP_jumpToFunc(LCDML_FUNC_initscreen); // jump to initscreen     
    }      
    
    // this function must called here, do not delete it
    LCDML_run(_LCDML_priority); 
  }




// *********************************************************************
// check some errors 
// *********************************************************************
# if(_LCDML_DISP_rows > _LCDML_DISP_cfg_max_rows)
# error change value of _LCDML_DISP_cfg_max_rows in LCDMenuLib.h
# endif
# if(_LCDML_DISP_cols > _LCDML_DISP_cfg_max_string_length)
# error change value of _LCDML_DISP_cfg_max_string_length in LCDMenuLib.h
# endif
