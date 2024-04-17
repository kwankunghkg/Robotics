//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// https://www.nxp.com/documents/data_sheet/PCF8574.pdf

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display NXP PCF8574T
// LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display NXP PCF8574AT (MH)

int PWMoutPin1  =  5;   // 3, 5, 6, 9, 10, 11 / 490 Hz (pins 5 and 6: 980 Hz) 
int PWMoutPin2  = 11;   // 3, 5, 6, 9, 10, 11 / 490 Hz (pins 5 and 6: 980 Hz) 
int analogInPin = A0;   // potentiometer connected to analog pin 
int pot = 0;            // variable to store the analog read value
int pwm = 0;            // variable 
int pwm_duty = 0;       // variable 
char display_string[16] = ""; //  Buffer for 16 character width

byte pwmOut = 3 ;       // Atmega328p OC2B=D3
  
void setup()
{
  Serial.begin(115200);            // open the serial port 
  lcd.init();                      // initialize the lcd

  // Print a message to the LCD.
  lcd.backlight();
  // lcd.print("Hello, world!");

  pinMode(LED_BUILTIN, OUTPUT);  // sets the pin as output

  pinMode(pwmOut, OUTPUT);
  OCR2A = 62;     // defines the frequency 51 = 38.4 KHz, 54 = 36.2 KHz, 58 = 34 KHz, 62 = 32 KHz
  OCR2B = 26;     // defines the duty cycle - Half the OCR2A value for 50%
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);   // COM2B1 (output to OC2B) ; WGMode 7 Fast PWM (part 1)
  TCCR2B = _BV(WGM22)  | _BV(CS21);                 // prescalere x8 ;  WGMode 7 Fast PWM (part 1)
}

void loop()
{
  pot = analogRead(analogInPin);  // read the input pin
  Serial.println(pot);
  pwm = (pot / 4);
  // PWM analogWrite relation between timers and PWM outputs :
  //   timer0 = Pins 5, 6
  //   timer1 = Pins 9, 10
  //   timer2 = Pins 11, 3
  //analogWrite(LED_BUILTIN, pwm); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(PWMoutPin1,  pwm); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  //analogWrite(PWMoutPin2,  pwm); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255

  pwm_duty = map(pot, 0, 1023, 0, 62); // map(value, fromLow, fromHigh, toLow, toHigh)
  OCR2B = pwm_duty;                    // defines the duty cycle - Half the OCR2A value for 50%

  // set the cursor to column 0, line 0
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("TIME : ");
  lcd.print(millis()/1000);
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print("VR/PWM ");
  // lcd.print(pot, DEC); // not working
  // sprintf(display_string,"%2d %2d %4.2f %7.3e",v1,v2,v3,v4);
  sprintf(display_string,"%3d/%2d  ", pot, pwm_duty);
  lcd.print( display_string );
}
