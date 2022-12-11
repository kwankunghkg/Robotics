/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
#if defined(ARDUINO_ARCH_MBED_RP2040) 
#warning __WARNING_DEFINED_RP2040__ARDUINO_ARCH_MBED_RP2040
#endif
#if defined(ARDUINO_ARCH_RP2040)
#warning __WARNING_DEFINED_RP2040__ARDUINO_ARCH_RP2040
#endif

#define BLINK_COUNT    4
#define DELAY_MS       100
#define GPIO_0         0
#define GPIO_1         1
#define GPIO_16        16
#define LED_0          GPIO_0
#define LED_1          GPIO_16

int counter_1   = 0;
int counter_old = 0;

void toggleLED(int pinLED) {
  //int LEDstate = digitalRead(pinLED);
  digitalWrite(pinLED, !digitalRead(pinLED));   
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_0,       OUTPUT);
  pinMode(LED_1,       OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_0,       LOW );   // turn the LED off by making the voltage LOW
  digitalWrite(LED_1,       LOW );   // turn the LED off by making the voltage LOW
}

void setup1() {
  //pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(GPIO_1, blink, FALLING);
  Serial.begin(115200);
  Serial.println("counter_1");
}

// the loop function runs over and over again forever
void loop() {
  for (int i=0; i<BLINK_COUNT; i++) {
    for (int j=0; j<BLINK_COUNT; j++) {
      for (int k=0; k<BLINK_COUNT; k++) {
        toggleLED(LED_BUILTIN);
        delay(DELAY_MS);
      }
      toggleLED(LED_1);
    }
    toggleLED(LED_0);
  }
}

void loop1() {
  if (counter_1 != counter_old) {
    Serial.print("intr_cnt=");
    Serial.print(counter_1);
    counter_old = counter_1;
    //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Toggle LED on pin 13
    Serial.print("  RP2040.temp=");
    Serial.println(analogReadTemp());
  }
}

void blink() {
  counter_1++;
}
