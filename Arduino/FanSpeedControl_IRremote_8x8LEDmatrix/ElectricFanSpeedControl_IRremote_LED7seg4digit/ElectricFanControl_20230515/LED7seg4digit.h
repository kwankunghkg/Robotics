/*
How to Control a 4-digit 7-segment LED Display with an Arduino
  http://www.learningaboutelectronics.com/Articles/4-digit-7-segment-LED-circuit-with-an-arduino.php

Showing number 0-9 on a Common Anode 7-segment LED display
  
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
*/

/*
#define LED_ON   LOW
#define LED_OFF  HIGH
#define DIGIT_  0b0000000
#define DIGIT_0 0b1111110
#define DIGIT_1 0b0110000
#define DIGIT_2 0b1100010
#define DIGIT_3 0b0000110
#define DIGIT_4 0b0000000
#define DIGIT_5 0b0000000
#define DIGIT_6 0b0000000
#define DIGIT_7 0b0000000
#define DIGIT_8 0b0000000
#define DIGIT_9 0b0000000
#define DIGIT_A 0b0000000
#define DIGIT_B 0b0000000
#define DIGIT_C 0b0000000
#define DIGIT_D 0b0000000
#define DIGIT_E 0b0000000
#define DIGIT_F 0b0000000
*/

// #include <Arduino.h>
// const int sensorPin= 0;//The analog sensor is connected to analog pin 0 of the arduino

//ABCDEFG,dp
const int numeral[18]= {
B11111100, //0
B01100000, //1
B11011010, //2
B11110010, //3
B01100110, //4
B10110110, //5
B10111110, //6
B11100000, //7
B11111110, //8
B11110110, //9
B11101110, //A
B00111110, //b
B00011010, //c
B01111010, //d
B10011110, //E
B10001110, //F
B00000001, //dp
B00000000  //
};

#define pinA  3
#define pinB  7
#define pinC  10
#define pinD  12
#define pinE  13
#define pinF  4
#define pinG  9
#define pinO  11
#define D1    2
#define D2    5
#define D3    6
#define D4    8
#define LED_ON   LOW
#define LED_OFF  HIGH
//pins for decimal point and each segment
//dp, G, F, E, D, C, B, A
//const int segmentPins[]= { 4, 7, 8, 6, 5, 3, 2, 9};
const int segmentPins[]= {pinO, pinG, pinF, pinE, pinD, pinC, pinB, pinA};
const int numberofDigits=4;
//const int digitPins[numberofDigits] = {10,11,12,13}; //digits 1, 2, 3, 4
const int digitPins[numberofDigits] = {D1,D2,D3,D4}; //digits 1, 2, 3, 4
int marquee_digit_position = 0;
unsigned long marquee_time_now  = 0;
unsigned long marquee_time_last = 0;
unsigned long showDigit_time_now  = 0;
unsigned long showDigit_on_time_last = 0;
unsigned long showDigit_off_time_last = 0;
bool showDigit_status = 0;
#ifdef TIME_SCALE_micro
#define LED7seg_TIME_SCALE   TIME_SCALE // micros();
#endif
#ifdef TIME_SCALE_milli
#define LED7seg_TIME_SCALE   1 // * 0.7      // millis();
#endif
#define marquee_interval         15*LED7seg_TIME_SCALE // micro-second
// #define showDigit_interval    200*LED7seg_TIME_SCALE // micro-second
// #define showDigit_on_interval     0*LED7seg_TIME_SCALE // micro-second
// #define showDigit_off_interval   400*LED7seg_TIME_SCALE // micro-second
#define LED_ON_interval          1*LED7seg_TIME_SCALE // new=ForLoop  // old=milli-second

void LED7seg4digit_clear() {
  for (int segment= 0; segment < 8; segment++) {
    digitalWrite(segmentPins[segment], LOW);
  }
  for (int digit= numberofDigits-1; digit >=0; digit--) {
    digitalWrite(digitPins[digit], LOW);
  }
}

//Displays given number on a 7-segment display at the given digit position
void showDigit (int number, int digit) {
#ifdef TIME_SCALE_micro
  showDigit_time_now = micros()/TIME_SCALE; // millis();
#endif
#ifdef TIME_SCALE_milli
  showDigit_time_now = millis(); // millis();
#endif
  LED7seg4digit_clear();
  // if (showDigit_time_now - showDigit_on_time_last > showDigit_interval) {
  //   showDigit_on_time_last = showDigit_time_now;
  //   //digitalWrite(digitPins[digit], LOW);
  //   digitalWrite(digitPins[digit], HIGH);
  // }
  // digitalWrite(digitPins[digit], LOW);
  // showDigit_off_time_last = showDigit_time_now;
  for (int segment= 0; segment < 8; segment++) {
    boolean isBitSet= bitRead(numeral[number], segment);
    isBitSet= ! isBitSet; //remove this line if common cathode display
    digitalWrite(segmentPins[segment], isBitSet);
  }
  digitalWrite(digitPins[digit], HIGH); 
  delay(LED_ON_interval);
  digitalWrite(digitPins[digit], LOW); 
  //unsigned long dummy=0;
  //for(unsigned long count=0; count<(LED_ON_interval); count++) {dummy++;}
  // if ((showDigit_time_now-showDigit_off_time_last > showDigit_on_interval+showDigit_off_interval) && showDigit_status==1) {
  //   showDigit_off_time_last = showDigit_time_now;
  //   digitalWrite(digitPins[digit], LOW);
  //   showDigit_status=0;
  // }
  // if ((showDigit_time_now-showDigit_on_time_last  > showDigit_on_interval+showDigit_off_interval) && showDigit_status==0) {
  //   showDigit_on_time_last = showDigit_time_now; // +marquee_interval*(numberofDigits);
  //   digitalWrite(digitPins[digit], HIGH); 
  //   showDigit_status=1;
  // }
}

void showNumber (int number) {
  if (number == 0)
    showDigit (0, numberofDigits-1); //display 0 in the rightmost digit
  else {
    for (int digit= numberofDigits-1; digit >=0; digit--) {
      if (number > 0) {
        showDigit(number % 10, digit);
        number= number/10;
        }
      }
    }
}

void LED7seg4digit_setup() {
  //set segment and DP pins to output
  for (int i=0; i < 8; i++)
    pinMode(segmentPins[i], OUTPUT); 
  //set the digit pins to output
  for (int i=0; i < numberofDigits; i++)
    pinMode(digitPins[i], OUTPUT);
}

void LED7seg4digit_loop(int value) {
  // int value=analogRead(sensorPin);
  for (int value=0; value<=9999; value++) { 
    showNumber(value);
    //delay(10);
  }
}

void marquee_LED7seg4digit(int value) {
  //unsigned long dummy=0;
  //for(unsigned long count=0; count<(LED_ON_interval); count++) {dummy++;}
#ifdef TIME_SCALE_micro
  marquee_time_now = micros()/TIME_SCALE; // millis();
#endif
#ifdef TIME_SCALE_milli
  marquee_time_now = millis(); // millis();
#endif
  if (marquee_time_now - marquee_time_last > marquee_interval) {
    marquee_time_last = marquee_time_now;
    if (++marquee_digit_position > numberofDigits) {
       marquee_digit_position=0;
    }
    //LED7seg4digit_clear();
    showDigit(value, marquee_digit_position);
  };
}

void marqueeDot_LED7seg4digit() {
  //unsigned long dummy=0;
  //for(unsigned long count=0; count<(LED_ON_interval); count++) {dummy++;}
#ifdef TIME_SCALE_micro
  marquee_time_now = micros()/TIME_SCALE; // millis();
#endif
#ifdef TIME_SCALE_milli
  marquee_time_now = millis(); // millis();
#endif
  if (marquee_time_now - marquee_time_last > marquee_interval) {
    marquee_time_last = marquee_time_now;
    if (++marquee_digit_position > numberofDigits) {
       marquee_digit_position=0;
    }
    showDigit(16, marquee_digit_position);
  };
}
