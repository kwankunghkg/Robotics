#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TEST_ENABLE  
//#define SERIAL_MONITOR_OFF
#define PWM32k_ENABLE  
#define TIMER1_ENABLE  
#define LCD_I2C_ENABLE  
#define PWMoutPin0_ENABLE
//#define PWMoutPin1_ENABLE
//#define PWMoutPin2_ENABLE

// PWM analogWrite relation between timers and PWM outputs :
//   timer0 = Pins 5, 6
//   timer1 = Pins 9, 10
//   timer2 = Pins 11, 3
const int PWMoutPin0  =  5; // 3, 5, 6, 9, 10, 11 / 490 Hz (pins 5 and 6: 980 Hz) 
const int PWMoutPin1  = 10; // 3, 5, 6, 9, 10, 11 / 490 Hz (pins 5 and 6: 980 Hz) 
const int PWMoutPin2  = 11; // 3, 5, 6, 9, 10, 11 / 490 Hz (pins 5 and 6: 980 Hz) 
const int pwmOut      =  3; // Atmega328p OC2B=D3
const int ROT_ENC_CLK =  2; // 2; // rotary encoder CLocK 
const int ROT_ENC_DT  =  8; // 3; // rotary encoder DirecTion 
const int ROT_ENC_SW  =  9; // 4; // rotary encoder SWitch 
const int LED_intr    = 12; // 

const int DEBOUNCE_MS    =  5; // 5;
const int TIMER1_PRELOAD = (65535-1000); // period ~6ms

int analogInPin = A0; // potentiometer connected to analog pin 
int pot         = 0; // variable to store the analog read value
int pot_test    = 0; // variable to store the analog read value
int lastVR      = 0; // variable to store the analog read value
int lastVR_test = 0; // variable to store the analog read value
int pwm         = 0; // variable 
int pwm_duty    = 0; // variable 
char display_string[16] = ""; //  Buffer for 16 character width
const int VR_THRESHOLD =  2;

volatile boolean rotarEncTriggered = false;
volatile boolean newEncCLK         = false;
volatile boolean newEncDT          = false;
volatile boolean EncCLK            = false;
volatile boolean EncDT             = false;
volatile boolean EncSampled        = false;
volatile int     virtualPosition   = 0; // Updated by the ISR (Interrupt Service Routine)
//static   int     virtualPosition   = 0; 
static   int     lastPosition      = 0; 
static   unsigned long    interruptTime     = 0;
static   unsigned long    lastInterruptTime = 0;
static   unsigned long    lastLoopTime      = 0;
static   boolean          pressed           = true;
static   boolean          LED_state         = false;
static   boolean          LED_intr_state    = false;

#ifdef LCD_I2C_ENABLE
// https://www.nxp.com/documents/data_sheet/PCF8574.pdf
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display NXP PCF8574T
// LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display NXP PCF8574AT (MH)
#endif

/*
 *   Reconfiguration of the microcontroller’s timers may result in 
 *   inaccurate millis() readings. The "Arduino AVR Boards" and 
 *   "Arduino megaAVR Boards" cores use Timer0 to generate millis(). 
 * 
 *   What timer does USB serial monitor use? 
 */

/*
 *  Arduino Timer Interrupts Tutorial & Examples
 *    https://deepbluembedded.com/arduino-timer-interrupts/
 *
 */

ISR(TIMER1_OVF_vect) {
  //TCNT1 = 40535; // Timer Preloading
  TCNT1 = TIMER1_PRELOAD; // Timer Preloading
  // Handle The Timer Overflow Interrupt
  //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  LED_toggle();
  if ( rotarEncTriggered == true) {
    rotarEncUpdate();
  }
}

void rotarEncISR ()  {
  rotarEncTriggered = true;
  LED_intr_on();
}

void rotarEncUpdate() {
  //LED_intr_on();
  //LED_on();
  LED_toggle();
  interruptTime = millis();

  if ( EncSampled == false ) {
    EncCLK = digitalRead(ROT_ENC_CLK) ;
    EncDT  = digitalRead(ROT_ENC_DT) ;
    EncSampled = true;
    //LED_on();                         // 
    //LED_intr_off();
  }

  // If interrupts come faster than 5ms, assume it's a bounce and ignore
  if (interruptTime - lastInterruptTime > DEBOUNCE_MS) {
    newEncCLK = digitalRead(ROT_ENC_CLK) ;
    newEncDT  = digitalRead(ROT_ENC_DT) ;
    //LED_off();                        //
    if ( newEncDT!=EncCLK && newEncDT==EncDT ) {
      virtualPosition++ ;    
      }
    if ( newEncDT!=EncCLK && newEncDT!=EncDT ) {
      //virtualPosition-- ;    
      }
    if ( newEncDT==EncCLK && newEncDT==EncDT ) {
      virtualPosition-- ;
      }
    if ( newEncDT==EncCLK && newEncDT!=EncDT ) {
      virtualPosition-- ;
      }
    // Keep track of when we were here last (no more than every 5ms)
    lastInterruptTime = interruptTime;
    rotarEncTriggered = false;
    EncSampled = false;
    LED_intr_off();
    //LED_off();
  }
}

void LED_toggle() {
  LED_state = !LED_state;
  digitalWrite(LED_BUILTIN, LED_state);
}

void LED_on() {
  LED_state = true;
  digitalWrite(LED_BUILTIN, LED_state);
}

void LED_off() {
  LED_state = false;
  digitalWrite(LED_BUILTIN, LED_state);
}

void LED_intr_toggle() {
  LED_intr_state = !LED_intr_state;
  digitalWrite(LED_intr, LED_intr_state);
}

void LED_intr_on() {
  LED_intr_state = true;
  digitalWrite(LED_intr, LED_intr_state);
}

void LED_intr_off() {
  LED_intr_state = false;
  digitalWrite(LED_intr, LED_intr_state);
}


void setup() {
#ifdef LCD_I2C_ENABLE
  delay(100);
  lcd.init();                      // initialize the lcd
  delay(100);
  lcd.backlight();
  delay(100);
  //lcd.clear();                     // 
  // Print a message to the LCD.
  lcd.print("Hello, world!");
  delay(1000);
#endif

#ifdef SERIAL_MONITOR_OFF
#else
  Serial.begin(115200);            // open the serial port 
  //Serial.begin(9600);            // lower bit rate more serious problem in interrupt/timer 
  delay(1000);
#endif  

  pinMode(LED_BUILTIN, OUTPUT);  // sets the pin as output
  pinMode(LED_intr,    OUTPUT);  // sets the pin as output
  pinMode(pwmOut,      OUTPUT);
  pinMode(PWMoutPin0,  OUTPUT);
  pinMode(PWMoutPin1,  OUTPUT);
  pinMode(PWMoutPin2,  OUTPUT);

#ifdef PWM32k_ENABLE  
  OCR2A = 62;     // defines the frequency 51 = 38.4 KHz, 54 = 36.2 KHz, 58 = 34 KHz, 62 = 32 KHz
  OCR2B = 26;     // defines the duty cycle - Half the OCR2A value for 50%
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);   // COM2B1 (output to OC2B) ; WGMode 7 Fast PWM (part 1)
  TCCR2B = _BV(WGM22)  | _BV(CS21);                 // prescalere x8 ;  WGMode 7 Fast PWM (part 1)
#endif

#ifdef TIMER1_ENABLE  
  TCCR1A = 0;           // Init Timer1A
  TCCR1B = 0;           // Init Timer1B
  TCCR1B |= B00000011;  // Prescaler = 64
  TCNT1 = TIMER1_PRELOAD; // Timer Preloading // 40535
  TIMSK1 |= B00000001;  // Enable Timer Overflow Interrupt
#endif

  // Rotary pulses are INPUTs
  pinMode(ROT_ENC_CLK, INPUT); // KY-040 Rotary Encoder
  pinMode(ROT_ENC_DT,  INPUT);
  //pinMode(ROT_ENC_SW,  INPUT);
  pinMode(ROT_ENC_SW,  INPUT_PULLUP);
  delay(100);

/*
    https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  Four constants are predefined as valid values:
    LOW to trigger the interrupt whenever the pin is low,
    CHANGE to trigger the interrupt whenever the pin changes value
    RISING to trigger when the pin goes from low to high,
    FALLING for when the pin goes from high to low.
  The Due, Zero and MKR1000 boards allow also:
    HIGH to trigger the interrupt whenever the pin is high.
*/
  // Attach the routine to service the interrupts
  //attachInterrupt(digitalPinToInterrupt(ROT_ENC_CLK), rotarEncUpdate_intrPinLOW, LOW);  
  attachInterrupt(digitalPinToInterrupt(ROT_ENC_CLK), rotarEncISR, CHANGE);  
  //attachInterrupt(digitalPinToInterrupt(ROT_ENC_CLK), rotarEncUpdate, CHANGE);  
  //attachInterrupt(digitalPinToInterrupt(ROT_ENC_CLK), rotarEncISR, RISING);  
  //attachInterrupt(digitalPinToInterrupt(ROT_ENC_CLK), rotarEncISR, FALLING);  
}

void loop()
{
  //LED_toggle();                         // monitor loop period 
/*
  if (rotarEncTriggered == true) {
    rotarEncUpdate();
  }
*/ 
#ifdef TEST_ENABLE  
  if (pressed == true) {
    pot = analogRead(analogInPin);  // read the input pin
    pot_test = pot;
  } else {
    if ( lastLoopTime - millis() > 100) { // testing
      pot_test+=virtualPosition; // self test 
      if (pot_test >= 1024) pot_test=0;
      if (pot_test <     0) pot_test=1023;
      lastLoopTime  = millis();           
    }
  }
#else
#endif
  pot = analogRead(analogInPin);  // read the input pin
  if ( abs(pot - lastVR) > VR_THRESHOLD ||  abs(pot_test - lastVR_test) > VR_THRESHOLD) {
#ifdef SERIAL_MONITOR_OFF
#else
    Serial.print("VR=");
    Serial.print(pot);
    Serial.print("  VRt=");
    Serial.print(pot_test);
    Serial.print("  POS=");
    Serial.println(virtualPosition);
#endif
    lastVR = pot;
    lastVR_test = pot_test;
  }
#ifdef TEST_ENABLE  
  pwm = (pot_test / 4);
#else
  pwm = (pot / 4);
#endif
  // PWM analogWrite relation between timers and PWM outputs :
  //   timer0 = Pins 5, 6
  //   timer1 = Pins 9, 10
  //   timer2 = Pins 11, 3
  //analogWrite(LED_BUILTIN, pwm); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
#ifdef PWMoutPin0_ENABLE
  analogWrite(PWMoutPin0,  pwm); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
#endif
#ifdef PWMoutPin1_ENABLE
  analogWrite(PWMoutPin1,  pwm); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
#endif
#ifdef PWMoutPin2_ENABLE
  analogWrite(PWMoutPin2,  pwm); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
#endif
#ifdef TEST_ENABLE  
  pwm_duty = map(pot_test, 0, 1023, 0, 62); // map(value, fromLow, fromHigh, toLow, toHigh)
#else
  pwm_duty = map(pot, 0, 1023, 0, 62); // map(value, fromLow, fromHigh, toLow, toHigh)
#endif
#ifdef PWM32k_ENABLE  
  OCR2B = pwm_duty;                    // defines the duty cycle - Half the OCR2A value for 50%
#endif
#ifdef LCD_I2C_ENABLE
  //lcd.clear();                     // 
  // set the cursor to column 0, line 0
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("T:");
  lcd.print(millis()/1000);
  lcd.print(" K:");
  sprintf(display_string,"%d      ", virtualPosition);
  lcd.print( display_string );
  lcd.setCursor(15, 0); // (column, line)
  if (pressed == true) {
    lcd.print("P");
  } else {
    lcd.print(" ");
  }

  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  //lcd.print("VR:");
  sprintf(display_string,"VR%4d", pot);
  lcd.print( display_string );
  // lcd.print(pot, DEC); // not working
  // sprintf(display_string,"%2d %2d %4.2f %7.3e",v1,v2,v3,v4);
#ifdef TEST_ENABLE  
  sprintf(display_string,"PWM%4d/%2d  ", pot_test, pwm_duty);
#else
  sprintf(display_string,"PWM%4d/%2d  ", pot, pwm_duty);
#endif
  lcd.print( display_string );
#endif
  if (virtualPosition != lastPosition) {
#ifdef SERIAL_MONITOR_OFF
#else
    Serial.print(virtualPosition);
    Serial.print(" ");
#endif
    if ( virtualPosition > lastPosition) {
#ifdef SERIAL_MONITOR_OFF
#else
      Serial.println("+");
#endif
    } else {
#ifdef SERIAL_MONITOR_OFF
#else
      Serial.println("-");
#endif
    }
    lastPosition = virtualPosition;
  }
  if (digitalRead(ROT_ENC_SW) == LOW && pressed == false) {
    pressed = true;
#ifdef SERIAL_MONITOR_OFF
#else
    Serial.println("SW = PRESS");
#endif
  }
  if (digitalRead(ROT_ENC_SW) == HIGH && pressed == true) {
    pressed = false;
#ifdef SERIAL_MONITOR_OFF
#else
    Serial.println("SW = release");
#endif
  }
}


