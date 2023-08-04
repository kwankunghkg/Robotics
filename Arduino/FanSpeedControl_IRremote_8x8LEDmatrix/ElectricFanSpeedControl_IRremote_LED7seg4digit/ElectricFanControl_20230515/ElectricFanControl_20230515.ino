/*
 * Electric Fan Control 20230519 // 20220831
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

#define TIME_SCALE_milli                  // new=micros() ; old=millis()
//#define TIME_SCALE_micro                  // new=micros() ; old=millis()
#define TIME_SCALE    800                 // new=micros() ; old=millis()
#define TIME_SCALE_1 (TIME_SCALE * 0.75)  // long
#define TIME_SCALE_2 (TIME_SCALE_1 /  2)  // medium
#define TIME_SCALE_3 (TIME_SCALE_1 /  5)  // short
#define PIN_LED    A1
#define PIN_RELAY  A2 // 10 // active LOW Relay // Adafruit Motor Shield pin 10 Servo #1 control
#define RELAY_ON   HIGH  // active high opto-coupler
#define RELAY_OFF  LOW
#define SPEED_MIN 0
#define SPEED_MAX 9
#define SPEED_DEFAULT 5
#define DEBUG_SERIAL
#define DEBUG_SERIAL_VERBOSE

#define RECV_PIN    A3   // TSOP1838 pinout sphere face (LEFT most) OUTput / GND (middle) / VCC (RIGHT most)
#define IR_USE_TIMER1

// https://github.com/Arduino-IRremote/Arduino-IRremote
//   https://www.instructables.com/Arduino-Infrared-Remote-tutorial/
// lib_deps = z3t0/IRremote@2.8.0 // Ken Shirriff
#include "IRremote.h"    
#include "IRtx_code.h"
#include "LED7seg4digit.h"
IRrecv irrecv(RECV_PIN);
decode_results ir_results;
/*
struct decode_results {
    decode_type_t decode_type;  ///< UNKNOWN, NEC, SONY, RC5, ...
    uint16_t address;           ///< Used by Panasonic & Sharp6 NEC_standard [16-bits]
    uint32_t value;             ///< Decoded value / command [max 32-bits]
    uint16_t bits;              ///< Number of bits in decoded value
    uint16_t magnitude;         ///< Used by MagiQuest [16-bits]
    bool isRepeat;              ///< True if repeat of value is detected
    // next 3 values are copies of irparams values - see IRremoteint.h
    uint16_t *rawbuf;           ///< Raw intervals in 50uS ticks
    uint16_t rawlen;            ///< Number of records in rawbuf
    bool overflow;              ///< true if IR raw code too long
  }
*/
uint32_t ir_new=0;
uint32_t ir_old=0;

//char text[] = "a";
//#include "LEDMatrixDriver.h"

int fan_speed     = 0;
int fan_speed_new = SPEED_DEFAULT;
bool relay_state = false;
unsigned long time_on        = 0;
unsigned long time_off       = 0;
unsigned long time_now       = 0;
unsigned long time_relay_on  = 0;
unsigned long time_relay_off = 0;

void print_speed() {
#ifdef DEBUG_SERIAL // _VERBOSE
    Serial.print(" / fan_speed "); 
    Serial.print(fan_speed);
    Serial.print(" on "); 
    Serial.print(float(time_on)/float(TIME_SCALE_1), 1);
    Serial.print(" off "); 
    Serial.println(float(time_off)/float(TIME_SCALE_1), 1);
#endif
}

void relay_on() {
#ifdef TIME_SCALE_micro
  time_relay_on = micros()/TIME_SCALE; // millis();
#endif
#ifdef TIME_SCALE_milli
  time_relay_on = millis(); // millis();
#endif
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on   (HIGH is the voltage level)  
  digitalWrite(PIN_LED, RELAY_ON);     // turn the LED on 
  digitalWrite(PIN_RELAY, RELAY_ON);    
  relay_state = true;
#ifdef DEBUG_SERIAL
  Serial.print("time ");
  Serial.print(time_relay_on/TIME_SCALE_1);
  Serial.print(" / ON ");
#endif
  print_speed();
}

void relay_off() {
#ifdef TIME_SCALE_micro
  time_relay_off = micros()/TIME_SCALE; // millis();
#endif
#ifdef TIME_SCALE_milli
  time_relay_off = millis(); // millis();
#endif
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(PIN_LED, RELAY_OFF);    // turn the LED off 
  digitalWrite(PIN_RELAY, RELAY_OFF);   
  relay_state = false;
#ifdef DEBUG_SERIAL
  Serial.print("time ");
  Serial.print(time_relay_off/TIME_SCALE_1);
  Serial.print(" / OFF");
#endif
  print_speed();
}

void relay_switch() {
#ifdef TIME_SCALE_micro
  time_now = micros()/TIME_SCALE; // millis();
#endif
#ifdef TIME_SCALE_milli
  time_now = millis(); // millis();
#endif
  if (time_on !=0 ) {
    if ( relay_state == false && (time_now - time_relay_off) > (time_off) ) {
      relay_on();
    }
  }
  if (time_off !=0 ) {
    if ( relay_state == true  && (time_now - time_relay_on ) > (time_on) ) {
      relay_off();
    }
  }
}

void serial_check() {
#ifdef TIME_SCALE_micro
  time_now = micros()/TIME_SCALE; // millis();
#endif
#ifdef TIME_SCALE_milli
  time_now = millis(); // millis();
#endif
  while (Serial.available() != 0) {     // skip waiting for data available
    String ser_str = Serial.readString();  //read until timeout
    ser_str.trim();                        // remove any \r \n whitespace at the end of the String
    fan_speed_new = ser_str.toInt();
#ifdef DEBUG_SERIAL
    Serial.print("time : ");
    Serial.print(time_now);
    Serial.print(" serial string : ");
    Serial.print(ser_str);
    Serial.print(" -> ");
    Serial.print(fan_speed_new);
#endif
  }
}

void fan_speed_update() {
  if (fan_speed_new != fan_speed) {
    //for(int idx=0; idx<5; idx++) marqueeDot_LED7seg4digit();
    fan_speed = fan_speed_new;
    //text[0] = fan_speed+48; // pass text to LEDMatrix_loop();
    //text[1] = text[0] ;
    switch (fan_speed) {
      case 0:
        time_on  = 0;  time_off = 1;
        break;
      case 1:
        time_on  = 2*TIME_SCALE_1;  time_off = 4*TIME_SCALE_1;
        break;
      case 2:
        time_on  = 3*TIME_SCALE_1;  time_off = 4*TIME_SCALE_1;
        break;
      case 3:
        time_on  = 4.5*TIME_SCALE_1;  time_off = 4.5*TIME_SCALE_1;
        break;
      case 4:
        time_on  = 5.5*TIME_SCALE_1;  time_off = 4.5*TIME_SCALE_1;
        break;
      case 5:
        time_on  = 6.5*TIME_SCALE_1;  time_off = 4.5*TIME_SCALE_1;
        break;
      case 6:
        time_on  = 7*TIME_SCALE_1;  time_off = 4*TIME_SCALE_1;
        break;
      case 7:
        time_on  = 8*TIME_SCALE_1;  time_off = 3*TIME_SCALE_1;
        break;
      case 8:
        time_on  = 10*TIME_SCALE_1;  time_off = 3*TIME_SCALE_1;
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

void fan_speed_get() {
    switch (ir_results.value) {
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

void ir_check_old() {
  if (irrecv.decode(&ir_results) ) {
    if (ir_results.value != 0xffffffff){
#ifdef DEBUG_SERIAL_VERBOSE
      Serial.print("IR.recv=0x");
      Serial.println(ir_results.value, HEX);
#endif
      // set the cursor to column 0, line 1
      // (note: line 1 is the second row, since counting begins with 0):
      //lcd.setCursor(0, 1);
      //lcd.print(" ");
      //if (++cursor_position>1) { cursor_position=0; }
      //lcd.setCursor(cursor_position, 1);
      //lcd.print(results.value, HEX);
      //lcd.print(" ");
    fan_speed_get();
    }
    irrecv.resume(); // Receive the next value
  }
}

void ir_check_new() {
  if (irrecv.available()) {
    irrecv.decode(&ir_results); 
    //Serial.print("IR.res=");
    //irrecv.printResultShort(&Serial);
    ir_new = ir_results.value;
  //if (irrecv.decode(&ir_results)) {
  //if (ir_new) {
#ifdef DEBUG_SERIAL_VERBOSE
      Serial.print("\tIR.new=0x");
      Serial.println(ir_new, HEX);
      //Serial.print(" IR.old=0x");
      //Serial.println(ir_old, HEX);
#endif    
    //if (ir_results.value != 0xffffffff) 
    //if (ir_results.value != 0xffffffff && ir_results.value != 0) 
    //if (ir_results.value != 0xffffffff && ir_new != ir_old) 
    //if (ir_results.value != 0xffffffff && ir_results.value != 0 && ir_new != ir_old) 
    if (ir_new != 0xffffffff && ir_new != 0) 
    //if (ir_new != 0xffffffff && ir_new != 0 && ir_new != ir_old) 
      {
#ifdef DEBUG_SERIAL_VERBOSE
/*
struct decode_results {
    decode_type_t decode_type;  ///< UNKNOWN, NEC, SONY, RC5, ...
    uint16_t address;           ///< Used by Panasonic & Sharp6 NEC_standard [16-bits]
    uint32_t value;             ///< Decoded value / command [max 32-bits]
    uint16_t bits;              ///< Number of bits in decoded value
    uint16_t magnitude;         ///< Used by MagiQuest [16-bits]
    bool isRepeat;              ///< True if repeat of value is detected
    // next 3 values are copies of irparams values - see IRremoteint.h
    uint16_t *rawbuf;           ///< Raw intervals in 50uS ticks
    uint16_t rawlen;            ///< Number of records in rawbuf
    bool overflow;              ///< true if IR raw code too long
  }
*/
//*
      Serial.print("\t\t\t\t\tIR.addr=0x");
      Serial.print(ir_results.address, HEX);
      Serial.print(" IR.value=0x");
      Serial.print(ir_results.value, HEX);
      Serial.print(" IR.bits=0x");
      Serial.print(ir_results.bits, HEX);
// * /
#endif
      ir_old = ir_new;
      //for(int idx=0; idx<10; idx++) marqueeDot_LED7seg4digit();
      // set the cursor to column 0, line 1
      // (note: line 1 is the second row, since counting begins with 0):
      //lcd.setCursor(0, 1);
      //lcd.print(" ");
      //if (++cursor_position>1) { cursor_position=0; }
      //lcd.setCursor(cursor_position, 1);
      //lcd.print(results.value, HEX);
      //lcd.print(" ");
      fan_speed_get();
      }
    //ir_results.value=0;
    irrecv.resume(); // Receive the next value
#ifdef DEBUG_SERIAL_VERBOSE
    Serial.println(" IR.resume");
#endif    
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  //Serial.begin(9600);
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_LED,   OUTPUT);
  pinMode(PIN_RELAY, OUTPUT);
  //LEDMatrix_setup();
  LED7seg4digit_setup();
  relay_on();
  //delay(1000*15);
  //text[0] = fan_speed+48;
  //text[1] = text[0] ;
}

// the loop function runs over and over again forever
void loop() {
  //ir_check_old();
  ir_check_new();
  serial_check();
  fan_speed_update();
  relay_switch();
  //LEDMatrix_loop();
  marquee_LED7seg4digit(fan_speed);
}
