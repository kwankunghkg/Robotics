/*
 * Electric Fan Control 20220831
*/
// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!
//
// Adafruit Motor/Stepper/Servo Shield for Arduino kit - v1.2
//
// https://www.arduino.cc/en/uploads/Main/arduino-duemilanove-schematic.pdf
// https://cdn-learn.adafruit.com/assets/assets/000/009/769/original/mshieldv1-schem.png
// https://www.adafruit.com/product/81
// https://learn.adafruit.com/adafruit-motor-shield/faq
/*
What pins are not used on the motor shield ?
All 6 analog input pins are available. They can also be used as digital pins (pins #14 thru 19)
Digital pin 2, and 13 are not used.
The following pins are in use only if the DC/Stepper noted is in use:
Digital pin 11: DC Motor #1 / Stepper #1 (activation/speed control)
Digital pin  3: DC Motor #2 / Stepper #1 (activation/speed control)
Digital pin  5: DC Motor #3 / Stepper #2 (activation/speed control)
Digital pin  6: DC Motor #4 / Stepper #2 (activation/speed control)
The following pins are in use if any DC/steppers are used
Digital pin 4, 7, 8 and 12 are used to drive the DC/Stepper motors via the 74HC595 serial-to-parallel latch
The following pins are used only if that particular servo is in use:
Digital pin 10: Servo #1 control
Digital pin  9: Servo #2 control
*/

#include <IRremote.h>
#include "IRtx_code.h"
int RECV_PIN = A3; // TSOP1838 pinout sphere face (LEFT most) OUTput / GND (middle) / VCC (RIGHT most)
IRrecv irrecv(RECV_PIN);
decode_results results;

char text[] = "a";
#include "LEDMatrixDriver.h"

#define TIME_SCALE 1000
#define RELAY_ON_ 10  // active LOW Relay // Adafruit Motor Shield pin 10 Servo #1 control
#define SPEED_MIN 0
#define SPEED_MAX 9
#define SPEED_DEFAULT 3

int time_on;
int time_off;
int fan_speed     = 0;
int fan_speed_new = SPEED_DEFAULT;
bool relay_state = false;
unsigned long time_now       = 0;
unsigned long time_relay_on  = 0;
unsigned long time_relay_off = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_ON_,   OUTPUT);
  LEDMatrix_setup();
  relay_on();
  //delay(1000*15);
  text[0] = fan_speed+48;
  //text[1] = text[0] ;
}

void relay_on() {
  time_relay_on = millis();
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on   (HIGH is the voltage level)  
  digitalWrite(RELAY_ON_,   LOW);    // turn the active LOW RELAY on 
  relay_state = true;
  Serial.print("time ");
  Serial.print(time_relay_on/TIME_SCALE);
  Serial.print(" / ON ");
  print_speed();
}

void relay_off() {
  time_relay_off = millis();
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(RELAY_ON_,   HIGH);   // turn the active LOW RELAY off 
  relay_state = false;
  Serial.print("time ");
  Serial.print(time_relay_off/TIME_SCALE);
  Serial.print(" / OFF");
  print_speed();
}

void serial_check() {
  time_now = millis();
  while (Serial.available() != 0) {     // skip waiting for data available
    String ser_str = Serial.readString();  //read until timeout
    ser_str.trim();                        // remove any \r \n whitespace at the end of the String
    fan_speed_new = ser_str.toInt();
    Serial.print("time : ");
    Serial.print(time_now);
    Serial.print(" serial string : ");
    Serial.print(ser_str);
    Serial.print(" -> ");
    Serial.print(fan_speed_new);
  }
}

void fan_speed_update() {
  if (fan_speed_new != fan_speed) {
    fan_speed = fan_speed_new;
    text[0] = fan_speed+48;
    //text[1] = text[0] ;
    switch (fan_speed) {
      case 0:
        time_on  = 0;  time_off = 1;
        break;
      case 1:
        time_on  = 4.5*TIME_SCALE;  time_off = 4.5*TIME_SCALE;
        break;
      case 2:
        time_on  = 5.5*TIME_SCALE;  time_off = 4.5*TIME_SCALE;
        break;
      case 3:
        time_on  = 6.5*TIME_SCALE;  time_off = 4.5*TIME_SCALE;
        break;
      case 4:
        time_on  = 7*TIME_SCALE;  time_off = 4*TIME_SCALE;
        break;
      case 5:
        time_on  = 8*TIME_SCALE;  time_off = 3*TIME_SCALE;
        break;
      case 6:
        time_on  = 10*TIME_SCALE;  time_off = 3*TIME_SCALE;
        break;
      case 7:
        time_on  = 1;  time_off = 0;
        break;
      case 8:
        time_on  = 1;  time_off = 0;
        break;
      case 9:
        time_on  = 1;  time_off = 0;
        break;
      default:
        // if nothing else matches, do the default
        // default is optional
        break;
    }
    print_speed();
  }
}

void print_speed() {
    Serial.print(" / fan_speed "); 
    Serial.print(fan_speed);
    Serial.print(" on "); 
    Serial.print(float(time_on)/float(TIME_SCALE), 1);
    Serial.print(" off "); 
    Serial.println(float(time_off)/float(TIME_SCALE), 1);
}

void ir_check() {
  if (irrecv.decode(&results) ) {
    if (results.value != 0xffffffff){
      Serial.print("IR.recv=0x");
      Serial.println(results.value, HEX);
      // set the cursor to column 0, line 1
      // (note: line 1 is the second row, since counting begins with 0):
      //lcd.setCursor(0, 1);
      //lcd.print(" ");
      //if (++cursor_position>1) { cursor_position=0; }
      //lcd.setCursor(cursor_position, 1);
      //lcd.print(results.value, HEX);
      //lcd.print(" ");
      switch (results.value) {
        case IRTX_VOL_MINUS:
          if (--fan_speed_new<SPEED_MIN) fan_speed_new=SPEED_MIN;
          break;
        case IRTX_VOL_PLUS:
          if (++fan_speed_new>SPEED_MAX) fan_speed_new=SPEED_MAX;
          break;
        case IRTX_EQ:
          fan_speed_new=SPEED_MIN;
          break;
        case IRTX_TRACK_PREV:
          if (--fan_speed_new<SPEED_MIN) fan_speed_new=SPEED_MIN;
          break;
        case IRTX_TRACK_NEXT:
          if (++fan_speed_new>SPEED_MAX) fan_speed_new=SPEED_MAX;
          break;
        case IRTX_CH:
          fan_speed_new=0;
          break;
        case IRTX_CH_MINUS:
          fan_speed_new=0;
          break;
        case IRTX_CH_PLUS:
          fan_speed_new=0;
          break;
        case IRTX_NUM_0:
          fan_speed_new=0;
          break;
        case IRTX_NUM_1:
          fan_speed_new=1;
          break;
        case IRTX_NUM_2:
          fan_speed_new=2;
          break;
        case IRTX_NUM_3:
          fan_speed_new=3;
          break;
        case IRTX_NUM_4:
          fan_speed_new=4;
          break;
        case IRTX_NUM_5:
          fan_speed_new=5;
          break;
        case IRTX_NUM_6:
          fan_speed_new=6;
          break;
        case IRTX_NUM_7:
          fan_speed_new=7;
          break;
        case IRTX_NUM_8:
          fan_speed_new=8;
          break;
        case IRTX_NUM_9:
          fan_speed_new=9;
          break;
        case IRTX_NUM_100:
          fan_speed_new=SPEED_MAX;
          break;
        case IRTX_NUM_200:
          fan_speed_new=SPEED_MAX;
          break;
        default:
          break;
      }
    }
    irrecv.resume(); // Receive the next value
  }
}

void relay_switch() {
  time_now = millis();
  if (time_on !=0 ) {
    if ( relay_state == false && (time_now - time_relay_off) > time_off ) {
      relay_on();
    }
  }
  if (time_off !=0 ) {
    if ( relay_state == true  && (time_now - time_relay_on ) > time_on  ) {
      relay_off();
    }
  }
}

// the loop function runs over and over again forever
void loop() {
  ir_check();
  serial_check();
  fan_speed_update();
  relay_switch();
  LEDMatrix_loop();
}
