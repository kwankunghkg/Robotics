// the regular Adafruit "TouchScreen.h" library only works on AVRs

// different mcufriend shields have Touchscreen on different pins
// and rotation.
// Run the UTouch_calibr_kbv sketch for calibration of your shield

#include <Adafruit_GFX.h>      // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
Adafruit_TFTLCD tft(A3, A2, A1, A0, A4);
//#include <MCUFRIEND_kbv.h>     // modified LCD TFT 2.4" // Hardware-specific library
//MCUFRIEND_kbv tft;             // hard-wired for UNO shields anyway.
//#include <TouchScreen.h>            // 20180408
#include <Adafruit_TouchScreen.h>     // 20220410

#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif

// These are the pins for some typical shields!
// S6D0154: YP=A1, XM=A2, YM=7, XP=6
// ST7783 : YP=A2, XM=A1, YM=6, XP=7
// ILI9320: YP=A2, XM=A3, YM=8, XP=9
// ILI9325: YP=A1, XM=A2, YM=7, XP=6
// ILI9325BG: YP=A2, XM=A1, YM=6, XP=7
// ILI9328: YP=A3, XM=A2, YM=9, XP=8      test OK 20180408
// ILI9341: YP=A2, XM=A1, YM=7, XP=6
// ILI9341: Y1=A1, X1=A2, Y2=7, X2=6      test OK 20220410
// ILI9488: YP=A1, XM=A2, YM=7, XP=6
// R65109V: YP=A2, XM=A1, YM=6, XP=7

// most mcufriend shields use these pins and Portrait mode:
uint8_t YP = A3; // A1;  // must be an analog pin, use "An" notation!
uint8_t XM = A2; // A2;  // must be an analog pin, use "An" notation!
uint8_t YM =  9; //  7;  // can be a digital pin
uint8_t XP =  8; //  6;  // can be a digital pin
uint8_t SwapXY = 0;

uint16_t TS_LEFT = 870; // 920;
uint16_t TS_RT   = 230; // 150;
uint16_t TS_TOP  = 950; // 940;
uint16_t TS_BOT  = 155; // 120;
char *name = "Unknown controller";

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;      // Adafruit_TouchScreen library 20220410
//Point tp;        // Touch Screen library function renamed from TSPoint to Point 20180408

#define MINPRESSURE 20
#define MAXPRESSURE 1000

#define SWAP(a, b) {uint16_t tmp = a; a = b; b = tmp;}

int16_t BOXSIZE;
int16_t PENRADIUS = 3;
uint16_t identifier, oldcolor, currentcolor;
uint8_t Orientation = 3;    // PORTRAIT=0/2   Landscape=1/3
bool Orientation_updated=true;
unsigned long last_millis ; // timeout
int timeout_interval = 3000;

// Assign human-readable names to some common 16-bit color values:
/*
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
*/
// Assign human-readable names to some common 16-bit color values:
#define BLACK       0x0000
#define BLUE        0x001F
//int32_t BLUE = tft.color565(50, 50, 255);
#define BRIGHTBLUE  tft.color565(50, 50, 255);
#define DARKBLUE    0x0010
#define VIOLET      0x8888
#define RED         0xF800
#define GREEN       0x07E0
#define CYAN        0x07FF
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define WHITE       0xFFFF
#define GREY        tft.color565(64, 64, 64);
#define GOLD        0xFEA0
#define BROWN       0xA145
#define SILVER      0xC618
#define LIME        0x07E0
#define ORANGE      0xFD20
#define ORANGERED   0xFA20

void show_Serial(void)
{
    Serial.print(F("Found "));
    Serial.print(name);
    Serial.println(F(" LCD driver"));
    Serial.print(F("ID=0x"));
    Serial.println(identifier, HEX);
    Serial.println("Screen is " + String(tft.width()) + "x" + String(tft.height()));
    Serial.println("Calibration is: ");
    Serial.println("LEFT = " + String(TS_LEFT) + " RT  = " + String(TS_RT));
    Serial.println("TOP  = " + String(TS_TOP)  + " BOT = " + String(TS_BOT));
    Serial.print("Wiring is: ");
    Serial.println(SwapXY ? "SWAPXY" : "PORTRAIT");
    Serial.println("YP=" + String(YP)  + " XM=" + String(XM));
    Serial.println("YM=" + String(YM)  + " XP=" + String(XP));
}

void show_tft(void)
{
    tft.setCursor(2, 2);
    tft.setTextSize(2);
    tft.print(F("Found "));
    tft.print(name);
    tft.println(F(" LCD"));
    tft.setTextSize(1);
    tft.print(F("ID=0x"));
    tft.println(identifier, HEX);
    tft.println("Screen is " + String(tft.width()) + "x" + String(tft.height()));
    tft.println("Calibration is: ");
    tft.println("LEFT = " + String(TS_LEFT) + " RT  = " + String(TS_RT));
    tft.println("TOP  = " + String(TS_TOP)  + " BOT = " + String(TS_BOT));
    tft.println("Orientation=" + String(Orientation));
    tft.print("\nWiring is: ");
    if (SwapXY) {
        tft.setTextColor(CYAN);
        tft.setTextSize(2);
    }
    tft.println(SwapXY ? "SWAPXY" : "PORTRAIT");
    tft.println("YP=" + String(YP)  + "  XM=" + String(XM));
    tft.println("YM=" + String(YM)  + "   XP=" + String(XP));
    tft.setTextSize(2);
    tft.setTextColor(RED);
    tft.setCursor((tft.width() - 48) / 2, (tft.height() * 2) / 4);
    tft.print("EXIT");
    tft.setTextColor(YELLOW, BLACK);
    tft.setCursor(0, (tft.height() * 6) / 8);
    tft.print("Touch screen for LOC");
    timeout_update();
    while (true) {
        tp = ts.getPoint();
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        ////pinMode(XP, OUTPUT);
        ////pinMode(YM, OUTPUT);
        if (timeout_check()==true) {
          screenSaver();
          Orientation_updated=true;
          break;
        }
        if (tp.z < MINPRESSURE || tp.z > MAXPRESSURE) { // no touch ?
          continue;
        } else {
          timeout_update();
        }
        if (tp.x > 450 && tp.x < 570  && tp.y > 450 && tp.y < 570) break; // touched EXIT
        tft.setCursor(0, (tft.height() * 3) / 4);
        tft.print("tp.x=" + String(tp.x) + " tp.y=" + String(tp.y) + "   ");
    }
}

void prepare_tft() {
uint16_t tmp;
    Orientation_updated=false;
    tft.reset();
    identifier = tft.readID();
    Serial.print("TFT.id = 0x");
    Serial.println(identifier, HEX);
    // if (identifier == 0) { identifier = 0x9341; }
    if (identifier == 0) {
        name = "ILI9341 DealExtreme";
        //TS_LEFT = 893; TS_RT = 145; TS_TOP = 930; TS_BOT = 135;
        //TS_LEFT = 150; TS_RT = 910; TS_TOP = 960; TS_BOT = 130;
        SwapXY = 1;
        if (Orientation%2 ==0) {
          TS_LEFT = 910; TS_RT = 150; TS_TOP = 130; TS_BOT = 960; // working 20220410
        } else {
          TS_LEFT = 150; TS_RT = 910; TS_TOP = 960; TS_BOT = 130; // working 20220410
        }
    } else if (identifier == 0x0154) {
        name = "S6D0154";
        TS_LEFT = 914; TS_RT = 181; TS_TOP = 957; TS_BOT = 208;
    } else if (identifier == 0x5408) {  //thanks gazialankus
        name = "SPFD5408";
        TS_LEFT = 150; TS_RT = 960; TS_TOP = 155; TS_BOT = 925;
        SwapXY = 1;
    } else if (identifier == 0x7783) {
        name = "ST7781";
        TS_LEFT = 865; TS_RT = 155; TS_TOP = 942; TS_BOT = 153;
        SwapXY = 1;
    } else if (identifier == 0x7789) {
        name = "ST7789V";
        YP = A2; XM = A1; YM = 7; XP = 6;
        TS_LEFT = 906; TS_RT = 169; TS_TOP = 161; TS_BOT = 919;
    } else if (identifier == 0x9320) {
        name = "ILI9320";
        YP = A3; XM = A2; YM = 9; XP = 8;
        TS_LEFT = 902; TS_RT = 137; TS_TOP = 941; TS_BOT = 134;
    } else if (identifier == 0x9325) {
        name = "ILI9325";
        TS_LEFT = 900; TS_RT = 103; TS_TOP = 96; TS_BOT = 904;
    } else if (identifier == 0x9325) {
        name = "ILI9325 Green Dog";
        TS_LEFT = 900; TS_RT = 130; TS_TOP = 940; TS_BOT = 130;
    } else if (identifier == 0x9327) {
        name = "ILI9327";
        TS_LEFT = 899; TS_RT = 135; TS_TOP = 935; TS_BOT = 79;
        SwapXY = 1;
    } else if (identifier == 0x9328) {
        name = "ILI9328";
        SwapXY = 0;
        if (Orientation%2 ==0) {
          TS_LEFT = 800; TS_RT = 310; TS_TOP = 950; TS_BOT = 210; // working 20220412
        } else {
          TS_LEFT = 310; TS_RT = 800; TS_TOP = 210; TS_BOT = 950; // working 20220412
        }
    } else if (identifier == 0x9329) {
        name = "ILI9329";
        TS_LEFT = 143; TS_RT = 885; TS_TOP = 941; TS_BOT = 131;
        SwapXY = 1;
    } else if (identifier == 0x9341) {
        name = "ILI9341 BLUE";
        //TS_LEFT = 920; TS_RT = 139; TS_TOP = 944; TS_BOT = 150;
        SwapXY = 1;
        if (Orientation%2 ==0) {
          TS_LEFT = 910; TS_RT = 150; TS_TOP = 130; TS_BOT = 960; // working 20220410
        } else {
          TS_LEFT = 150; TS_RT = 910; TS_TOP = 960; TS_BOT = 130; // working 20220410
        }
 // } else if (identifier == 0) {
 //     name = "ILI9341 DealExtreme";
 //     //TS_LEFT = 893; TS_RT = 145; TS_TOP = 930; TS_BOT = 135;
 //     //TS_LEFT = 150; TS_RT = 910; TS_TOP = 960; TS_BOT = 130;
 //     SwapXY = 1;
 //     if (Orientation%2 ==0) {
 //       TS_LEFT = 910; TS_RT = 150; TS_TOP = 130; TS_BOT = 960; // working 20220410
 //     } else {
 //       TS_LEFT = 150; TS_RT = 910; TS_TOP = 960; TS_BOT = 130; // working 20220410
 //     }
//  } else if (identifier == 0 || identifier == 0x9341) {
//      name = "ILI9341";
//      TS_LEFT = 128; TS_RT = 911; TS_TOP = 105; TS_BOT = 908;
//      SwapXY = 1;
    } else if (identifier == 0x9486) {
        name = "ILI9486";
        TS_LEFT = 904; TS_RT = 170; TS_TOP = 950; TS_BOT = 158;
    } else if (identifier == 0x9488) {
        name = "ILI9488";
        TS_LEFT = 904; TS_RT = 170; TS_TOP = 950; TS_BOT = 158;
    } else if (identifier == 0xB509) {
        name = "R61509V";
        TS_LEFT = 889; TS_RT = 149; TS_TOP = 106; TS_BOT = 975;
        SwapXY = 1;
    } else {
        name = "unknown";
    }
    switch (Orientation) {      // adjust for different aspects
        case 0:   break;        //no change,  calibrated for PORTRAIT
        case 1:   tmp = TS_LEFT, TS_LEFT = TS_BOT, TS_BOT = TS_RT, TS_RT = TS_TOP, TS_TOP = tmp;  break;
        case 2:   SWAP(TS_LEFT, TS_RT);  SWAP(TS_TOP, TS_BOT); break;
        case 3:   tmp = TS_LEFT, TS_LEFT = TS_TOP, TS_TOP = TS_RT, TS_RT = TS_BOT, TS_BOT = tmp;  break;
    }

    ts = TouchScreen(XP, YP, XM, YM, 300);     //call the constructor AGAIN with new values.
    if (identifier != 0x0) {
      tft.begin(identifier); // work for 0x9328 20220412
    } else {
      tft.begin(0x9341);  // if it is not work try for 9325 ,9328,7575,8347,8357
    }
    show_Serial();
    tft.setRotation(Orientation);
    tft.fillScreen(BLACK);
    show_tft();
}

void sketchboard_init() {
    BOXSIZE = tft.width() / 6;
    tft.fillScreen(BLACK);
    tft.fillRect(BOXSIZE*0, 0, BOXSIZE, BOXSIZE, RED);
    tft.fillRect(BOXSIZE*1, 0, BOXSIZE, BOXSIZE, YELLOW);
    tft.fillRect(BOXSIZE*2, 0, BOXSIZE, BOXSIZE, GREEN);
    tft.fillRect(BOXSIZE*3, 0, BOXSIZE, BOXSIZE, CYAN);
    tft.fillRect(BOXSIZE*4, 0, BOXSIZE, BOXSIZE, BLUE);
    tft.fillRect(BOXSIZE*5, 0, BOXSIZE, BOXSIZE, MAGENTA);
    tft.drawRect(0+4, 0+4, BOXSIZE-8, BOXSIZE-8, WHITE);
    currentcolor = RED;
}

void sketchboard() {
  uint16_t xpos, ypos;  //screen coordinates

  sketchboard_init();
  timeout_update();
  while (true) {
      tp = ts.getPoint();   //tp.x, tp.y are ADC values
      // if sharing pins, you'll need to fix the directions of the touchscreen pins
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      // we have some minimum pressure we consider 'valid'
      // pressure of 0 means no pressing!
    
      if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
          timeout_update(); // last_millis = millis(); // update timeout counter
          // is controller wired for Landscape ? or are we oriented in Landscape?
          if (SwapXY != (Orientation & 1)) SWAP(tp.x, tp.y);
          // scale from 0->1023 to tft.width  i.e. left = 0, rt = width
          // most mcufriend have touch (with icons) that extends below the TFT
          // screens without icons need to reserve a space for "erase"
          // scale the ADC values from ts.getPoint() to screen values e.g. 0-239
          xpos = map(tp.x, TS_LEFT, TS_RT, 0, tft.width());
          ypos = map(tp.y, TS_TOP, TS_BOT, 0, tft.height());
    
          // are we in top color box area ?
          if (ypos < BOXSIZE) {               //draw white border on selected color box
              oldcolor = currentcolor;
    
              if (xpos < BOXSIZE) {
                  currentcolor = RED;
                  tft.drawRect(BOXSIZE*0+4, 0+4, BOXSIZE-8, BOXSIZE-8, BLACK);
              } else if (xpos < BOXSIZE * 2) {
                  currentcolor = YELLOW;
                  tft.drawRect(BOXSIZE*1+4, 0+4, BOXSIZE-8, BOXSIZE-8, BLACK);
              } else if (xpos < BOXSIZE * 3) {
                  currentcolor = GREEN;
                  tft.drawRect(BOXSIZE*2+4, 0+4, BOXSIZE-8, BOXSIZE-8, BLACK);
              } else if (xpos < BOXSIZE * 4) {
                  currentcolor = CYAN;
                  tft.drawRect(BOXSIZE*3+4, 0+4, BOXSIZE-8, BOXSIZE-8, BLACK);
              } else if (xpos < BOXSIZE * 5) {
                  currentcolor = BLUE;
                  tft.drawRect(BOXSIZE*4+4, 0+4, BOXSIZE-8, BOXSIZE-8, BLACK);
              } else if (xpos < BOXSIZE * 6) {
                  currentcolor = MAGENTA;
                  tft.drawRect(BOXSIZE*5+4, 0+4, BOXSIZE-8, BOXSIZE-8, BLACK);
              }
    
              if (oldcolor != currentcolor) { //rub out the previous white border
                  if (oldcolor == RED    ) tft.fillRect(BOXSIZE*0, 0, BOXSIZE, BOXSIZE, RED    );
                  if (oldcolor == YELLOW ) tft.fillRect(BOXSIZE*1, 0, BOXSIZE, BOXSIZE, YELLOW );
                  if (oldcolor == GREEN  ) tft.fillRect(BOXSIZE*2, 0, BOXSIZE, BOXSIZE, GREEN  );
                  if (oldcolor == CYAN   ) tft.fillRect(BOXSIZE*3, 0, BOXSIZE, BOXSIZE, CYAN   );
                  if (oldcolor == BLUE   ) tft.fillRect(BOXSIZE*4, 0, BOXSIZE, BOXSIZE, BLUE   );
                  if (oldcolor == MAGENTA) tft.fillRect(BOXSIZE*5, 0, BOXSIZE, BOXSIZE, MAGENTA);
              }
          }
          // are we in drawing area ?
          if (((ypos - PENRADIUS) > BOXSIZE) && ((ypos + PENRADIUS) < tft.height())) {
              tft.fillCircle(xpos, ypos, PENRADIUS, currentcolor);
          }
          // are we in erase area ?
          if (ypos > tft.height() - 10) {
              // press the bottom of the screen to erase
              tft.fillRect(0, BOXSIZE, tft.width(), tft.height() - BOXSIZE, BLACK);
              if (Orientation++ >= 3) Orientation=0;
              Orientation_updated=true;
              break;
          }
      }
      if (timeout_check()==true) {
        screenSaver();
        break;
      }
  }
}

void screenSaver()
{
  TSPoint p = ts.getPoint();     // Read touchscreen
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  tft.fillScreen(BLACK);
  tft.setCursor(30, 100);
  tft.print("");
  tft.setCursor(10, 150);
  tft.print("Screen Saving");
  tft.setCursor(50, 200);
  tft.print("");
  delay(1000);
  //tft.fillScreen(BLACK);

  bool loop_flag = true;
  while (loop_flag)
  {
    for (int i = 0; i < 100; i++)
    {
      int color = tft.color565(random(255), random(255), random(255));
      int x      = random(320); 
      int y      = random(320);
      int x2     = random(240); 
      int y2     = random(320);
      int x3     = random(300); 
      int y3     = random(200);
      int radius = random(20);
      int shape  = random(10);
      switch (shape) {
          case 0 :
              tft.drawCircle(x, y, radius, color);
            break;
          case 1 :
              tft.fillCircle(x, y, radius, color);
            break;
          case 2 :
              tft.drawRect(x, y, x2, y2, color);
            break;
          case 3 :
              tft.drawLine(x, y, x2, y2, color);
            break;
          case 4 :
              tft.drawRoundRect(x, y, x2, y2, radius, color);
            break;
          case 5 :
              tft.drawCircle(x, y, radius, color);
            break;
          case 6 :
              tft.drawTriangle(x, y, x2, y2, x3, y3, color);
            break;
          case 7 :
              tft.drawTriangle(x, y, x2, y2, x3, y3, color);
            break;
          case 8 :
              tft.drawLine(x, y, x2, y2, color);
            break;
          case 9 :
              tft.drawLine(x, y, x2, y2, color);
            break;
          default:
            // default statements
            break;
      }
      tp = ts.getPoint();     // Read touchscreen
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) { // touched & break
        loop_flag=false;
        break;
      }
      delay(100);
    }
  tft.fillScreen(BLACK);
  }
  timeout_update(); // last_millis = millis(); // update timeout counter
} 

bool timeout_check() {
  // check timeout go screenSaver mode
  if ((millis() - last_millis) > timeout_interval) {
    return true;
  } else {
    return false;
  }
}

void timeout_update() {
  last_millis = millis(); // update timeout counter
}

void setup(void)
{
  Serial.begin(115200);
  timeout_update(); // last_millis = millis(); // update timeout counter
  //digitalWrite(LED_BUILTIN, HIGH);
  //digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  if (Orientation_updated) {
    prepare_tft();
  } else {
    sketchboard();
  }
}
