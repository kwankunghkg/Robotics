/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
//#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display NXP PCF8574T
//LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display NXP PCF8574AT (MH)

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5);
//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int x = millis()/1000;
//dfrobot lcd shield
void setup() {
  lcd.init();                      // initialize the lcd

  // Print a message to the LCD.
  lcd.backlight();
  //lcd.print("Hello, world!");

  // set up the LCD's number of columns and rows: 
  //lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("LCD1602 I2C-MH ");
  lcd.setCursor(2, 1); // LCD (column , row)
  lcd.print(":");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //*
  lcd.setCursor(4, 1); // LCD (column , row)
  lcd.print(x);
  if (x > 59)
  x = 0;
  //*/
  lcd.setCursor(0, 1); // LCD (column , row)
  lcd.print(millis()/100);
}
