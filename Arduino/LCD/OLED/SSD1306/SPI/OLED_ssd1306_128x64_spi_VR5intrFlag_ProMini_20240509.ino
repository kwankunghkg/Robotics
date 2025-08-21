/* Arduino Nano ATMEGA328
      https://www.teachmemicro.com/arduino-nano-pinout-diagram/
*/
#include <Arduino.h>
//#define LED_BUILTIN 13

/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using SPI to communicate
4 or 5 pins are required to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//#define DEBUG_SERIAL
#define DEBUG_SERIAL_VR
//#define DEBUG_SERIAL_FLAKE

#define TIMER1_ENABLE
const int TIMER1_PRELOAD = (65535 - 10000);  // period ~6ms

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
// OLED 0.96" SSD1306 7-pin {GND, VCC, D0(CLK), D1(DATA), RESET, DC, CS}
#define OLED_MOSI     11  // 51 //  9 // D1 for 6 pin modules
#define OLED_CLK      13  // 52 // 10 // D0 for 6 pin modules
#define OLED_DC        9  // 53 // 6 // SS_ Slave Select (active LOW) // DC for 6 pin modules
#define OLED_RESET     7  // 8 // 49 // 8  // or system RESET // RES for 6 pin modules
#define OLED_CS        6  // 7 // 48 // 7  // not necessary for 6 pin modules
const int16_t LCDWIDTH = 128;
const int16_t LCDHEIGHT = 64;
static uint8_t lcd_orientation = 0;  // ssd1306 {0, 1, 2, 3}

#define VR5vcc  A7 // VCC
#define VR5     A6 // VR
#define VR1x  A2
#define VR1y  A1
#define VR1sw A0
#define VR2x  A5
#define VR2y  A4
#define VR2sw A3
#define VR1x_OFFSET 512 - 534
#define VR1y_OFFSET 512 - 513
#define VR2x_OFFSET 512 - 500
#define VR2y_OFFSET 512 - 451
#define VR_GAIN 2
int vr5  = 0;
int vr1x = 0;
int vr1y = 0;
int vr2x = 0;
int vr2y = 0;
bool vr1sw = false;
bool vr2sw = false;
bool sw_pressed = false;

#define FLAKES_NUM 5
#define SCROLL_NUM 3
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define DELAY_FLAKE 10
#define DELAY_BASE_1 200
#define DELAY_BASE_2 200
#define DELAY_BASE_3 400
#define DELAY_BASE_4 400
#define DELAY_ASIII 500
#define DELAY_SCROLL_1 200
#define DELAY_SCROLL_2 100
unsigned int delay_flake = DELAY_FLAKE;
unsigned int delay_1 = DELAY_BASE_1;
unsigned int delay_2 = DELAY_BASE_2;
unsigned int delay_3 = DELAY_BASE_3;
unsigned int delay_4 = DELAY_BASE_4;
unsigned int delay_ascii = DELAY_ASIII;
unsigned int delay_scroll_1 = DELAY_SCROLL_1;
unsigned int delay_scroll_2 = DELAY_SCROLL_2;

#define TEST_CASE_MAX 15
int test_case = 0;

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH 16
static const unsigned char PROGMEM logo16_glcd_bmp[] = { 
    B00000000, B11000000,
    B00000001, B11000000,
    B00000001, B11000000,
    B00000011, B11100000,
    B11110011, B11100000,
    B11111110, B11111000,
    B01111110, B11111111,
    B00110011, B10011111,
    B00011111, B11111100,
    B00001101, B01110000,
    B00011011, B10100000,
    B00111111, B11100000,
    B00111111, B11110000,
    B01111100, B11110000,
    B01110000, B01110000,
    B00000000, B00110000 };
/*
OLED 0.96" SSD1306
  GND：电源地
  VCC：3.3V或者5V供电
  D0：CLK时钟
  D1：MOSI数据
  RST：复位
  DC：数据/命令
  6-pin SSD1306 pinout : 1.GND 2.VCC 3.SCL 4.SDA 5.RESET 6.DC
  7-pin SSD1306 pinout : {GND, VCC, D0(SCL), D1(SDA), RESET, DC, CS}
*/
/* 
// If using software SPI (the default case):
#define OLED_MOSI  11 // 51 // 9
#define OLED_CLK   13 // 52 // 10
#define OLED_DC     9 // 53 // 11 // SS_ Slave Select (active LOW)
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
*/
// * Uncomment this block to use hardware SPI
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);  // ArduinoIDE 2.3.2
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_DC, OLED_RESET, OLED_CS); //
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS); //
// * /
#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


ISR(TIMER1_OVF_vect) {
  //TCNT1 = 40535; // Timer Preloading
  TCNT1 = TIMER1_PRELOAD;  // Timer Preloading
  // Handle The Timer Overflow Interrupt
  //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // toggle LED

  // vr_read();
  vr5   = analogRead(VR5);
  vr1x  = analogRead(VR1x);
  vr1y  = analogRead(VR1y);
  vr2x  = analogRead(VR2x);
  vr2y  = analogRead(VR2y);
  vr1sw = digitalRead(VR1sw);
  vr2sw = digitalRead(VR2sw);
}


void vr_update() {
  sw_pressed = !vr1sw | !vr2sw;

  float vr1x_n = map(vr1x + VR1x_OFFSET, 0, 1023, -100,  100);
  float vr1y_n = map(vr1y + VR1y_OFFSET, 0, 1023, -100,  100);
  float vr2x_n = map(vr2x + VR2x_OFFSET, 0, 1023, -100,  100);
  float vr2y_n = map(vr2y + VR2y_OFFSET, 0, 1023,  100, -100);
  float vr5_n  = map(vr5,                0, 1023, -100,  100);
  vr1x_n = vr5_n;

  float vr1x_o = 1.0;

  if (vr1x_n > 10) {
    vr1x_o = 1 + (VR_GAIN * vr1x_n / 100);
  } else {
    if (vr1x_n < -10) {
      vr1x_o = 1 - abs(vr1x_n) / 100;
      if (vr1x_o > 1.0 || vr1x_o < 0) {
        vr1x_o = 0;
      }
    } else {
      vr1x_o = 1.0;
    }
  }

  delay_flake = DELAY_FLAKE * vr1x_o;
  delay_1 = DELAY_BASE_1 * vr1x_o;
  delay_2 = DELAY_BASE_2 * vr1x_o;
  delay_3 = DELAY_BASE_3 * vr1x_o;
  delay_4 = DELAY_BASE_4 * vr1x_o;
  delay_ascii = DELAY_ASIII * vr1x_o;
  delay_scroll_1 = DELAY_SCROLL_1 * vr1x_o;
  delay_scroll_2 = DELAY_SCROLL_2 * vr1x_o;

#ifdef DEBUG_SERIAL_VR
  Serial.print("  5:");
  Serial.print(vr5);
  Serial.print("  1x_o:");
  Serial.print(vr1x_o);
  Serial.print("  d1:");
  Serial.print(delay_1);
  Serial.print("  1x:");
  Serial.print(vr1x);
  Serial.print("  1y:");
  Serial.print(vr1y);
  Serial.print("  2x:");
  Serial.print(vr2x);
  Serial.print("  2y:");
  Serial.print(vr2y);
  Serial.print("  1sw:");
  Serial.print(vr1sw);
  Serial.print("  2sw:");
  Serial.print(vr2sw);
  Serial.println();
#endif
}


void print_debug(int out_value) {
#ifdef DEBUG_SERIAL
  Serial.print("debug : ");
  Serial.println(out_value);
#endif
}


#define FONT_H 0

void displayVRvalue() {
  // text display tests
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(0, FONT_H * 0);
  display.print("1x:");
  display.print(vr1x);
  display.println("");
  //display.setCursor(0,FONT_H*1);
  display.print("1y:");
  display.print(vr1y);
  display.println("");

  //display.setCursor(0,FONT_H*2);
  display.print("2x:");
  display.print(vr2x);
  display.println("");
  //display.setCursor(0,FONT_H*3);
  display.print("2y:");
  display.print(vr2y);
  display.println("");

  //display.setCursor(0,FONT_H*4);
  display.print("1sw:");
  display.print(vr1sw ? 0 : 1);
  display.println("");
  //display.setCursor(0,FONT_H*5);
  display.print("2sw:");
  display.print(vr2sw ? 0 : 1);
  display.println("");

  display.display();
}


void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  uint8_t icons[FLAKES_NUM][3];

  // initialize
  for (uint8_t f = 0; f < FLAKES_NUM; f++) {
    icons[f][XPOS] = random(display.width());
    icons[f][YPOS] = 0;
    icons[f][DELTAY] = random(5) + 1;
#ifdef DEBUG_SERIAL_FLAKE
    Serial.print("x: ");
    Serial.print(icons[f][XPOS], DEC);
    Serial.print(" y: ");
    Serial.print(icons[f][YPOS], DEC);
    Serial.print(" dy: ");
    Serial.println(icons[f][DELTAY], DEC);
#endif
  }

  //while (1) {
  for (int j = 0; j < 100; j++) {
    // draw each icon
    for (uint8_t f = 0; f < FLAKES_NUM; f++) {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, WHITE);
    }
    display.display();
    vr_update(); delay(delay_flake);

    // then erase it + move it
    for (uint8_t f = 0; f < FLAKES_NUM; f++) {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, BLACK);
      // move it
      icons[f][YPOS] += icons[f][DELTAY];
      // if its gone, reinit
      if (icons[f][YPOS] > display.height()) {
        icons[f][XPOS] = random(display.width());
        icons[f][YPOS] = 0;
        icons[f][DELTAY] = random(5) + 1;
      }
    }
  }
}


void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  for (uint8_t i = 0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    if ((i > 0) && (i % 21 == 0))
      display.println();
  }
  display.display();
}


void testdrawcircle(void) {
  for (int16_t i = 0; i < display.height(); i += 2) {
    display.drawCircle(display.width() / 2, display.height() / 2, i, WHITE);
    display.display();
  }
}


void testdrawtriangle(void) {
  for (int16_t i = 0; i < min(display.width(), display.height()) / 2; i += 5) {
    display.drawTriangle(display.width() / 2, display.height() / 2 - i,
                         display.width() / 2 - i, display.height() / 2 + i,
                         display.width() / 2 + i, display.height() / 2 + i, WHITE);
    display.display();
  }
}


void testfilltriangle(void) {
  //uint8_t color = WHITE;
  uint16_t color = WHITE;
  for (int16_t i = min(display.width(), display.height()) / 2; i > 0; i -= 5) {
    display.fillTriangle(display.width() / 2, display.height() / 2 - i,
                         display.width() / 2 - i, display.height() / 2 + i,
                         display.width() / 2 + i, display.height() / 2 + i, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
}


void testdrawroundrect(void) {
  for (int16_t i = 0; i < display.height() / 2 - 2; i += 2) {
    display.drawRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i, display.height() / 4, WHITE);
    display.display();
  }
}


void testfillroundrect(void) {
  uint16_t color = WHITE;
  //int color = WHITE; // 1;
  for (int16_t i = 0; i < display.height() / 2 - 2; i += 2) {  // original
                                                               //for (int16_t i=0; i<display.height()/2-2; i+=2) {
                                                               //for (int16_t i=3; i<LCDHEIGHT/2-4; i+=2) { // debugging 20240504
    // alternate colors
    display.fillRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i, display.height() / 4, color);  // original
    //display.fillRoundRect(i, i, display.width()-2*i-12, display.height()-2*i, display.height()/4, color); // debugging
    //display.fillRoundRect(i, i, i, i, 64/4, color); // debugging 20240504
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
}


void testfillrect(void) {
  //uint8_t color = WHITE; // 1;
  uint16_t color = WHITE;  // 1;
  //for (int16_t i=3; i<display.height()/2-4; i+=2) { // debugging 20240504
  for (int16_t i = 0; i < display.height() / 2; i += 3) {  // original
    // alternate colors
    uint16_t w = display.width() - i * 2 - 10;
    uint16_t h = display.height() - i * 2;
    /*
    Serial.print("i:");     Serial.print(i); 
    Serial.print(" w:");    Serial.print(w);    
    Serial.print(" h:");    Serial.println(h);
    //print_debug(w);    //print_debug(h);
*/
    display.fillRect(i, i, display.width() - i * 2, display.height() - i * 2, color % 2);  // original
    //display.fillRect(i, i, display.width()-i*2-10, display.height()-i*2, color); // debugging
    //display.fillRect(i, i, w, h, color);
    //display.fillRect(i, i, i, h, color); // debugging 20240504
    display.display();
    //color++;
    if (color == WHITE) color = BLACK;
    else color = WHITE;
  }
}


void testdrawrect(void) {
  for (int16_t i = 0; i < display.height() / 2; i += 2) {
    display.drawRect(i, i, display.width() - 2 * i - 4, display.height() - 2 * i, WHITE);
    display.display();
  }
}


void testdrawline() {
  for (int16_t i = 0; i < display.width(); i += 4) {
    display.drawLine(0, 0, i, display.height() - 1, WHITE);
    display.display();
  }
  for (int16_t i = 0; i < display.height(); i += 4) {
    display.drawLine(0, 0, display.width() - 1, i, WHITE);
    display.display();
  }
  vr_update(); delay(delay_1);

  display.clearDisplay();
  for (int16_t i = 0; i < display.width(); i += 4) {
    display.drawLine(0, display.height() - 1, i, 0, WHITE);
    display.display();
  }
  for (int16_t i = display.height() - 1; i >= 0; i -= 4) {
    display.drawLine(0, display.height() - 1, display.width() - 1, i, WHITE);
    display.display();
  }
  vr_update(); delay(delay_1);

  display.clearDisplay();
  for (int16_t i = display.width() - 1; i >= 0; i -= 4) {
    display.drawLine(display.width() - 1, display.height() - 1, i, 0, WHITE);
    display.display();
  }
  for (int16_t i = display.height() - 1; i >= 0; i -= 4) {
    display.drawLine(display.width() - 1, display.height() - 1, 0, i, WHITE);
    display.display();
  }
  vr_update(); delay(delay_1);

  display.clearDisplay();
  for (int16_t i = 0; i < display.height(); i += 4) {
    display.drawLine(display.width() - 1, 0, 0, i, WHITE);
    display.display();
  }
  for (int16_t i = 0; i < display.width(); i += 4) {
    display.drawLine(display.width() - 1, 0, i, display.height() - 1, WHITE);
    display.display();
  }
  vr_update(); delay(delay_1);
}


void testscrolltext(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 20);
  display.clearDisplay();
  display.println("scroll");
  display.display();

  for (int i = 0; i < SCROLL_NUM; i++) {
    display.startscrollright(0x00, 0x3F);
    vr_update(); delay(delay_scroll_1);
    display.stopscroll();
    vr_update(); delay(delay_scroll_2);
    display.startscrollleft(0x00, 0x3F);
    vr_update(); delay(delay_scroll_1);
    display.stopscroll();
    vr_update(); delay(delay_scroll_2);
    display.startscrolldiagright(0x00, 0x27);
    vr_update(); delay(delay_scroll_1);
    display.startscrolldiagleft(0x00, 0x27);
    vr_update(); delay(delay_scroll_2);
    display.stopscroll();
  }
}


void testDrawText() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello, world!");
  display.setTextColor(BLACK, WHITE);  // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("0x");
  display.println(0xDEADBEEF, HEX);
  display.display();
}


void testDrawSinglePixel() {
  // draw a single pixel
  display.drawPixel(11, 17, WHITE);
  display.drawPixel(23, 29, WHITE);
  display.drawPixel(31, 37, WHITE);
  display.drawPixel(51, 57, WHITE);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  display.display();
}


void loop_display() {
  display.clearDisplay();  // Clear the buffer

  if (test_case > TEST_CASE_MAX) {
    test_case = 0;
    if (lcd_orientation++ > 3)
      lcd_orientation = 0;
    display.setRotation(lcd_orientation);  // SSD1306 library rotate display {0,1,2,3}
    display.display();
  }
  //print_debug(test_case);
  switch (test_case++) {
    case 11:
      testDrawSinglePixel();
      vr_update(); delay(delay_1);
      break;
    case 1:
      testdrawline();  // draw many lines
      vr_update(); delay(delay_2);
      break;
    case 2:
      testdrawrect();  // draw rectangles
      vr_update(); delay(delay_3);
      break;
    case 3:
      testfillrect();  // draw multiple rectangles
      vr_update(); delay(delay_3);
      break;
    case 4:
      testdrawroundrect();
      vr_update(); delay(delay_3);
      break;
    case 5:
      testfillroundrect();
      vr_update(); delay(delay_3);
      break;
    case 6:
      testdrawcircle();  // draw mulitple circles
      vr_update(); delay(delay_4);
      break;
    case 7:
      // draw a white circle, 10 pixel radius
      display.fillCircle(display.width() / 2, display.height() / 2, 10, WHITE);
      display.display();
      vr_update(); delay(delay_4);
      break;
    case 8:
      testdrawtriangle();
      vr_update(); delay(delay_4);
      break;
    case 9:
      testfilltriangle();
      vr_update(); delay(delay_4);
      break;
    case 10:
      testdrawchar();  // draw the first ~12 characters in the font
      vr_update(); delay(delay_ascii);
      break;
    case 0:
      testscrolltext();  // draw scrolling text
      vr_update(); delay(delay_2);
      break;
    case 12:
      testDrawText();  // text display tests
      vr_update(); delay(delay_ascii);
      break;
    case 13:
      // miniature bitmap display
      display.drawBitmap(30, 16, logo16_glcd_bmp, 16, 16, 1);
      display.display();
      vr_update(); delay(delay_ascii);
      break;
    case 14:
      display.invertDisplay(true);  // invert the display
      vr_update(); delay(delay_ascii);
      display.invertDisplay(false);
      vr_update(); delay(delay_ascii);
      break;
    case 15:
      // draw a bitmap icon and 'animate' movement
      testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);
      vr_update(); delay(delay_ascii);
    default:
      // default statements
      break;
  }
}


void LCD_init() {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  // init done
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  vr_update(); delay(delay_ascii*4);
}


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  LCD_init();
  // initialize digital pin 13 as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(VR1sw, INPUT_PULLUP);
  pinMode(VR2sw, INPUT_PULLUP);
  pinMode(VR5vcc, OUTPUT);
  digitalWrite(VR5vcc, HIGH);

#ifdef TIMER1_ENABLE
  TCCR1A = 0;              // Init Timer1A
  TCCR1B = 0;              // Init Timer1B
  TCCR1B |= B00000011;     // Prescaler = 64
  TCNT1 = TIMER1_PRELOAD;  // Timer Preloading // 40535
  TIMSK1 |= B00000001;     // Enable Timer Overflow Interrupt
#endif
}


void loop() {
  sw_pressed = false;
  vr_update();
  if (sw_pressed == true) {
    displayVRvalue();
    sw_pressed = false;
  } else {
    loop_display();
  }
}


// the loop function runs over and over again forever
void loop_test() {
  for (int i = 10; i < 500; i += 40) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(i);                         // wait for i milli-second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(i);                         // wait for i milli-second
    Serial.print("millis() : ");
    Serial.println(millis());
  }
}


