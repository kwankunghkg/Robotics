// 
// PolyU Electronic & Information Engineering
// 2013.08.21
//

// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int analog_pin = 2;  // analog pin used to connect the potentiometer

/*
 * HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: cnobile $
 * $Date: 2011-09-17 02:43:12 -0400 (Sat, 17 Sep 2011) $
 * $Revision: 29 $
 * ----------------------------------
 */

#include <Ultrasonic.h>

//#define TRIGGER_PIN   9  // pin  9 => S1 of AdaFruit Motor Shield
//#define ECHO_PIN     10  // pin 10 => S2 of AdaFruit Motor Shield
//#define TRIGGER_PIN   1  // pin 1 of AdaFruit Motor Shield
//#define ECHO_PIN      2  // pin 2 of AdaFruit Motor Shield
#define TRIGGER_PIN   A0  // pin A0 of AdaFruit Motor Shield
#define ECHO_PIN      A1  // pin A1 of AdaFruit Motor Shield

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);


float range_check(void) 
{
  long      sonic_range_microsec;
  float     sonic_range_distance_cm;
 
  sonic_range_microsec = ultrasonic.timing();
  sonic_range_distance_cm = ultrasonic.convert(sonic_range_microsec, Ultrasonic::CM);

  Serial.print("distance CM : ");
  Serial.println(sonic_range_distance_cm);
  
  return(sonic_range_distance_cm);
}

void motion_response(int servo_position, float sonic_range_distance_cm)
{
float hit_range_front   = 15;
float clear_range_front = 25;
float hit_range_edge    = 15;
float clear_range_edge  = 15;
//float good_range        =  1;
  
if (sonic_range_distance_cm != 0) {   // check sonar working 
switch (servo_position) {
case 0 ... 30 : 
  if (sonic_range_distance_cm > hit_range_edge) 
    {
    motor1.run(FORWARD); // left  motor
    motor2.run(FORWARD); // right motor
    //delay(100);
    }
  else  
    {
    Serial.println("!!! HIT  Right !!!");
    do 
      {
      motor1.run(RELEASE); // left  motor
      motor2.run(FORWARD); // right motor
      delay(100);
      sonic_range_distance_cm = range_check();
      }
    while (sonic_range_distance_cm < clear_range_edge) ; 
    }
    break;

case 70 ... 110 : 
  if (sonic_range_distance_cm > hit_range_front) 
    {
    motor1.run(FORWARD); // left  motor
    motor2.run(FORWARD); // right motor
    //delay(100);
    }
  else  
    {
    Serial.println("!!! HIT !!!");
    motor1.run(RELEASE ); // left motor
    motor2.run(RELEASE ); // right motor
    delay(500);
    do 
      {
      motor1.run(BACKWARD); // left motor
      motor2.run(RELEASE ); // right motor
      delay(100);
      sonic_range_distance_cm = range_check();
      }
    while (sonic_range_distance_cm < clear_range_front) ; 
    motor1.run(RELEASE ); // left motor
    motor2.run(RELEASE ); // right motor
    delay(500);
    }
    break;

case 150 ... 179 : 
  if (sonic_range_distance_cm > hit_range_edge) 
    {
    motor1.run(FORWARD); // left  motor
    motor2.run(FORWARD); // right motor
    //delay(100);
    }
  else  
    {
    Serial.println("!!! HIT  Left !!!");
    do 
      {
      motor1.run(FORWARD); // left  motor
      motor2.run(RELEASE); // right motor
      delay(100);
      sonic_range_distance_cm = range_check();
      }
    while (sonic_range_distance_cm < clear_range_edge) ; 
    }
    break;
    
    default :
    break;
}    

} // if
else { // below good_range => ultrasonic sensor error
  do 
    {
    Serial.println("!!! Range ERROR !!!");
    motor1.run(RELEASE ); // left motor
    motor2.run(RELEASE ); // right motor
    delay(100);
    sonic_range_distance_cm = range_check();
    }
  while (sonic_range_distance_cm = 0) ; 
  Serial.println("!!! Range OK !!!");
  } // else

  //return(void);
}


// servo motor control 
// 
// 

#include <Servo.h> 

Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 

int servo_position_1  = 90;     // variable to store the servo position 
int servo_position_2  = 90;     // variable to store the servo position 
int servo_center_offset_1 = -7;  // variable to store the servo center position offset
int servo_center_offset_2 = -7;  // variable to store the servo center position offset
int servo_range_1 = 80;          // servo position range
int servo_step    =  5;          // servo position jump step
int servo_position_delay = 20;

void print_servo_position(int servo_position_1, int servo_position_2) {
  Serial.print("pos = ");           // use serial monitor (console) for debugging    
  Serial.print(servo_position_1); 
  //Serial.print("    trim = ");                  // use servo 2 as center trimming
  //Serial.print(servo_position_2);               // use servo 2 as center trimming
  //Serial.print("    servo_center_offset = ");   // use servo 2 as center trimming
  //Serial.print(servo_position_2-90);            // use servo 2 as center trimming
  Serial.print("    ");
}


void setup() {
  Serial.begin(115200);           // set up Serial library at xxxx bps

  // turn on motor
  motor1.setSpeed(150);
  motor2.setSpeed(150);
 
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  
  myservo1.attach( 9);  // attaches the servo on pin  9 to the servo object, pin  9 => S1 of AdaFruit Motor Shield
  myservo2.attach(10);  // attaches the servo on pin  5 to the servo object, pin 10 => S2 of AdaFruit Motor Shield 
  myservo1.write(90);   // tell servo to go to center position
  myservo2.write(90);   // tell servo to go to center position
  delay(500);
}

void loop() {
  uint8_t   i;
  int       analog_in;    // variable to read the value from the analog pin 
  long      sonic_range_microsec;
  float     sonic_range_distance_cm;

   
  // scan left (servo_position > 90degree)
  for(servo_position_1 = (90+servo_center_offset_1); servo_position_1 < (90+servo_center_offset_1+servo_range_1); servo_position_1 += servo_step)  // goes from 0 degrees to 180 degrees 
  {                                      // in steps of 1 degree 
  myservo1.write(servo_position_1);                // tell servo to go to position in variable 'pos' 
  delay(servo_position_delay);
  }

  print_servo_position(servo_position_1, servo_position_2);

  sonic_range_distance_cm = range_check();
  motion_response(servo_position_1, sonic_range_distance_cm);
  
  for(servo_position_1 = (90+servo_center_offset_1+servo_range_1); servo_position_1 > (90+servo_center_offset_1); servo_position_1 -= servo_step)  // goes from 0 degrees to 180 degrees 
  {                                      // in steps of 1 degree 
  myservo1.write(servo_position_1);                // tell servo to go to position in variable 'pos' 
  delay(servo_position_delay);
  }

  print_servo_position(servo_position_1, servo_position_2);

  sonic_range_distance_cm = range_check();
  motion_response(servo_position_1, sonic_range_distance_cm);
  
  //delay (2000);
  //servo_position_1 = 90+servo_center_offset_1 ;
  //myservo1.write(servo_position_1);                // tell servo to go to position in variable 'pos'   delay (1000);
  //delay (2000);
  
  for(servo_position_1 = (90+servo_center_offset_1); servo_position_1 > (90+servo_center_offset_1-servo_range_1); servo_position_1 -= servo_step)  // goes from 0 degrees to 180 degrees 
  {                                      // in steps of 1 degree 
  myservo1.write(servo_position_1);                // tell servo to go to position in variable 'pos' 
  delay(servo_position_delay);
  }

  print_servo_position(servo_position_1, servo_position_2);
  
  sonic_range_distance_cm = range_check();
  motion_response(servo_position_1, sonic_range_distance_cm);
  
  for(servo_position_1 = (90+servo_center_offset_1-servo_range_1); servo_position_1 < (90+servo_center_offset_1); servo_position_1 += servo_step)  // goes from 0 degrees to 180 degrees 
  {                                      // in steps of 1 degree 
  myservo1.write(servo_position_1);                // tell servo to go to position in variable 'pos' 
  delay(servo_position_delay);
  }
  
  print_servo_position(servo_position_1, servo_position_2);

  sonic_range_distance_cm = range_check();
  motion_response(servo_position_1, sonic_range_distance_cm);
  
  // use servo 2 as center trimming
  //
  //analog_in  = analogRead(analog_pin);  // reads the value of the potentiometer (value between 0 and 1023) 
  //servo_position_2 = map(analog_in, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 degree and 180 degree) 
  //myservo2.write(servo_position_2);  // tell servo to go to position

}
