/*______Import Libraries_______*/
//#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
//#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
//#include <SPFD5408_TouchScreen.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;       // hard-wired for UNO shields anyway.
#include <TouchScreen.h>
/*______End of Libraries_______*/

/*______Define LCD pins (I have asigned the default values)_______*/
//#define YP A1  // must be an analog pin, use "An" notation!
//#define XM A2  // must be an analog pin, use "An" notation!
//#define YM 7   // can be a digital pin
//#define XP 6   // can be a digital pin
uint8_t YP = A3;  // must be an analog pin, use "An" notation!
uint8_t XM = A2;  // must be an analog pin, use "An" notation!
uint8_t YM = 9;   // can be a digital pin
uint8_t XP = 8;   // can be a digital pin
uint8_t SwapXY = 0;

uint16_t TS_LEFT = 920;
uint16_t TS_RT   = 150;
uint16_t TS_TOP  = 940;
uint16_t TS_BOT  = 120;
char *name = "Unknown controller";

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
/*_______End of defanitions______*/

uint16_t identifier, oldcolor, currentcolor;
uint8_t  Orientation = 0;    //PORTRAIT

#define SWAP(a, b) {uint16_t tmp = a; a = b; b = tmp;}

/*______Assign names to colors and pressure_______*/
#define WHITE   0x0000 // Black  -> White
#define YELLOW  0x001F // Blue   -> Yellow
#define CYAN    0xF800 // Red    -> Cyan
#define PINK    0x07E0 // Green  -> Pink
#define RED     0x07FF // Cyan   -> Red
#define GREEN   0xF81F // Pink   -> Green 
#define BLUE    0xFFE0 // Yellow -> Blue
#define BLACK   0xFFFF // White  -> Black
#define MINPRESSURE 10
#define MAXPRESSURE 1000
/*_______Assigned______*/

/*____Calibrate TFT LCD_____*/
//#define TS_MINX 125
//#define TS_MINY 85
//#define TS_MAXX 965
//#define TS_MAXY 905
uint16_t TS_MINX = 125 ;
uint16_t TS_MINY =  85 ;
uint16_t TS_MAXX = 965 ;
uint16_t TS_MAXY = 905 ;
/*______End of Calibration______*/

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300); //300 is the sensitivity
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET); //Start communication with LCD

String symbol[4][4] = {
  { "7", "8", "9", "/" },
  { "4", "5", "6", "*" },
  { "1", "2", "3", "-" },
  { "C", "0", "=", "+" }
};
 int X,Y,Z;
 long Num1,Num2,Number;
 char action;
 boolean result = false;

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
}

void setup() {
  uint16_t tmp;
  Serial.begin(9600); //Use serial monitor for debugging
  tft.reset(); //Always reset at start
    identifier = tft.readID();
    //    if (identifier == 0) identifier = 0x9341;
    if (0) {
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
        TS_LEFT = 900; TS_RT = 230; TS_TOP = 940; TS_BOT = 180;
        SwapXY = 0;
    } else if (identifier == 0x9329) {
        name = "ILI9329";
        TS_LEFT = 143; TS_RT = 885; TS_TOP = 941; TS_BOT = 131;
        SwapXY = 1;
    } else if (identifier == 0x9341) {
        name = "ILI9341 BLUE";
        TS_LEFT = 920; TS_RT = 139; TS_TOP = 944; TS_BOT = 150;
        SwapXY = 0;
    } else if (identifier == 0) {
        name = "ILI9341 DealExtreme";
        TS_LEFT = 893; TS_RT = 145; TS_TOP = 930; TS_BOT = 135;
        SwapXY = 1;
    } else if (identifier == 0 || identifier == 0x9341) {
        name = "ILI9341";
        TS_LEFT = 128; TS_RT = 911; TS_TOP = 105; TS_BOT = 908;
        SwapXY = 1;
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
// name = "ILI9328";
// TS_LEFT = 900; TS_RT = 230; TS_TOP = 940; TS_BOT = 180;
// SwapXY = 0;
 TS_MINX = TS_LEFT ; // 
 TS_MAXX = TS_RT   ; // 
 TS_MINY = TS_BOT  ; // 
 TS_MAXY = TS_TOP  ; // 
//  TS_MINX = 125 ;
//  TS_MINY =  85 ;
//  TS_MAXX = 965 ;
//  TS_MAXY = 905 ;
//  TS_MINX = 125 ;
//  TS_MINY =  85 ;
//  TS_MAXX = 965 ;
//  TS_MAXY = 905 ;

  tft.begin(identifier); // My LCD uses LIL9328 Interface driver IC
//  tft.setRotation(2); // I just roated so that the power jack faces up - optional
  //tft.fillScreen(WHITE);
  tft.fillScreen(GREEN);
    show_Serial();
    tft.setRotation(Orientation);
//    tft.fillScreen(BLACK);
    show_tft();

  IntroScreen();
  
  draw_BoxNButtons(); 
}

void loop() {
//TSPoint p = waitTouch();
Point p = waitTouch();
X = p.x; Y = p.y; Z = p.z;
Serial.print("XYZ = "); 
Serial.print(X); 
Serial.print(","); 
Serial.print(Y); 
Serial.print(","); 
Serial.println(Z); 

DetectButtons();
if (result==true)
CalculateResult();
DisplayResult();   
  delay(300);
}

//TSPoint waitTouch() {
Point waitTouch() {
//  TSPoint p;
  Point p;
  do {
    p = ts.getPoint(); 
    //pinMode(XM, OUTPUT);
    //pinMode(YP, OUTPUT);
  } while((p.z < MINPRESSURE )|| (p.z > MAXPRESSURE));
//  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
//  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 240);;
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);;
  return p;
}

void DetectButtons()
{
  if (X<240/4*1 && X>240/4*0) //Detecting Buttons on Column 1
  {
    if (Y>0 && Y<85) //If cancel Button is pressed
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}
    
     if (Y>85 && Y<140) //If Button 1 is pressed
    {Serial.println ("Button 1"); 
    if (Number==0)
    Number=1;
    else if (Number>0)
    Number = (Number*10) + 1; //Pressed twice
    else
    Number = (Number*10) - 1; //Pressed twice
    }
    
     if (Y>140 && Y<192) //If Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else if (Number>0)
    Number = (Number*10) + 4; //Pressed twice
    else
    Number = (Number*10) - 4; //Pressed twice
    }
    
     if (Y>192 && Y<245) //If Button 7 is pressed
    {Serial.println ("Button 7");
    if (Number==0)
    Number=7;
    else if (Number>0)
    Number = (Number*10) + 7; //Pressed twice
    else
    Number = (Number*10) - 7; //Pressed twice
    } 
  }

    if (X<240/4*2 && X>240/4*1) //Detecting Buttons on Column 2
  {
    if (Y>0 && Y<85)
    {Serial.println ("Button 0"); //Button 0 is Pressed
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if (Y>85 && Y<140)
    {Serial.println ("Button 2"); 
     if (Number==0)
    Number=2;
    else if (Number>0)
    Number = (Number*10) + 2; //Pressed twice
    else
    Number = (Number*10) - 2; //Pressed twice
    }
    
     if (Y>140 && Y<192)
    {Serial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else if (Number>0)
    Number = (Number*10) + 5; //Pressed twice
    else
    Number = (Number*10) - 5; //Pressed twice
    }
    
     if (Y>192 && Y<245)
    {Serial.println ("Button 8"); 
     if (Number==0)
    Number=8;
    else if (Number>0)
    Number = (Number*10) + 8; //Pressed twice
    else
    Number = (Number*10) - 8; //Pressed twice
    }   
  }

    if (X<240/4*3 && X>240/4*2) //Detecting Buttons on Column 3
  {
    if (Y>0 && Y<85)
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result=true;
    }
    
     if (Y>85 && Y<140)
    {Serial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else if (Number>0)
    Number = (Number*10) + 3; //Pressed twice
    else
    Number = (Number*10) - 3; //Pressed twice
    }
    
     if (Y>140 && Y<192)
    {Serial.println ("Button 6"); 
    if (Number==0)
    Number=6;
    else if (Number>0)
    Number = (Number*10) + 6; //Pressed twice
    else
    Number = (Number*10) - 6; //Pressed twice
    }
    
     if (Y>192 && Y<245)
    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else if (Number>0)
    Number = (Number*10) + 9; //Pressed twice
    else
    Number = (Number*10) - 9; //Pressed twice
    }   
  }

      if (X<240/4*4 && X>240/4*3) //Detecting Buttons on Column 3
  {
    Num1 = Number;    
    Num2 = Num1;
    Number = 0;
    tft.setCursor(200, 20);
    tft.setTextColor(RED);
    if (Y>0 && Y<85)
    {action = 1; tft.println('+'); Serial.println("Addition"); }
     if (Y>85 && Y<140)
    {action = 2; tft.println('-'); Serial.println("Subtraction"); }
     if (Y>140 && Y<192)
    {action = 3; tft.println('*'); Serial.println("Multiplication"); }
     if (Y>192 && Y<245)
    {action = 4; tft.println('/'); Serial.println("Division"); }  

    delay(300);
  }  
}

void CalculateResult()
{
  if (action==1)
    Number = Num1+Num2;

  if (action==2)
    Number = Num1-Num2;

  if (action==3)
    Number = Num1*Num2;

  if (action==4)
    Number = Num1/Num2; 

  //Num1=Number;  
}

void DisplayResult()
{
    tft.fillRect(0, 0, 240, 80, CYAN);  //clear result box
    tft.setCursor(10, 20);
    tft.setTextSize(4);
    tft.setTextColor(BLACK);
    tft.println(Number); //update new value
    result=false;
}

void IntroScreen()
{
  tft.setCursor (55, 120);
  tft.setTextSize (3);
  tft.setTextColor(RED);
  tft.println("ARDUINO");
  tft.setCursor (30, 160);
  tft.println("CALCULATOR");
  tft.setCursor (30, 220);
  tft.setTextSize (2);
  tft.setTextColor(BLUE);
  tft.println("-Circut Digest");
  delay(1800);
}

void draw_BoxNButtons()
{
  //Draw the Result Box
  tft.fillRect(0, 0, 240, 80, CYAN);

 //Draw First Column
  tft.fillRect  (0,260,60,60,RED);
  tft.fillRect  (0,200,60,60,BLACK);
  tft.fillRect  (0,140,60,60,BLACK);
  tft.fillRect  (0,80,60,60,BLACK);

 //Draw Third Column  
  tft.fillRect  (120,260,60,60,GREEN);
  tft.fillRect  (120,200,60,60,BLACK);
  tft.fillRect  (120,140,60,60,BLACK);
  tft.fillRect  (120,80,60,60,BLACK);

  //Draw Secound & Fourth Column  
  for (int b=260; b>=80; b-=60)
 { tft.fillRect  (180,b,60,60,BLUE); 
   tft.fillRect  (60,b,60,60,BLACK);}

  //Draw Horizontal Lines
  for (int h=80; h<=320; h+=60)
  tft.drawFastHLine(0, h, 240, WHITE);

  //Draw Vertical Lines
  for (int v=0; v<=240; v+=60)
  tft.drawFastVLine(v, 80, 240, WHITE);

  //Display keypad lables 
  for (int j=0;j<4;j++) {
    for (int i=0;i<4;i++) {
      tft.setCursor(22 + (60*i), 100 + (60*j));
      tft.setTextSize(3);
      tft.setTextColor(WHITE);
      tft.println(symbol[j][i]);
    }
  }
}
