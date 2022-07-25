#include <ESP32Servo.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)           //error catching
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

Servo myservoLeft;
Servo myservoRight;
// Create Servo objects for the arms
int servoPinLeft = 13; // Define Servo pins
int servoPinRight = 12;
int servoAngle = 10; // Set Servo angle
BluetoothSerial SerialBT; //declares the Bluetooth object

void setup() {
  myservoLeft.attach(servoPinLeft, 500, 2400); // attach servo to the two arms.
  myservoLeft.write(servoAngle);
  myservoRight.attach(servoPinRight, 500, 2400);
  myservoRight.write(servoAngle);
  
  Serial.begin(115200); // Serial monitor
  Serial1.begin(9600); // Arduino Communication
  SerialBT.begin("ESP32_Hooks_On_Mars");  //begins Bluetooth Serial connection
  Serial.println("Started successfully.");

}



int servoInc = 10; // Increments to change servo angle

char readIn; // Define Bluetooth char variable

void loop() 
{
  if (SerialBT.available()) //if there are bytes available in the buffer
    readIn = char(SerialBT.read()); //read in one and store it in readIn

  //Several "If" statements are for reading characters from computer and printing on serial monitor. 
  
  if (readIn == 'w') 
  {
    Serial1.print('w');
    readIn = '\0';
  }

  if (readIn == 's') 
  {
    Serial1.print('s');
    readIn = '\0';
  }

  if (readIn == 'a') 
  {
    Serial1.print('a');
    readIn = '\0';
  }

  if (readIn == 'd') 
  {
      Serial1.print('d');
      readIn = '\0';
  }
  
  if (readIn == 'z') 
  {
      Serial1.print('z');
      readIn = '\0';
  }
  if (readIn == 'x') 
  {
      Serial1.print('x');
      readIn = '\0';
  }
  if (readIn == 'm')
  {
      Serial1.print('m');
      readIn = '\0';
  }
  Serial.println(readIn);
    if (readIn == 'o' && servoAngle < 180) 
    { // if input is o and servo angle is less than 180 degrees
      servoAngle += servoInc; // Increment angle
      myservoLeft.write(servoAngle); // Write new angle to servo
      Serial.println("Inside increment angle");
      readIn = '\0';
    }
    if (readIn == 'p' && servoAngle > 10) 
    { // else if input is p and servo angle is more than 10 degrees
      servoAngle -= servoInc; // Decrement angle
      myservoLeft.write(servoAngle); // Write new angle to servo
      Serial.println("Inside increment angle");
      readIn = '\0';
    }
    if (readIn == 'k' && servoAngle < 180) 
    { // else if input is k and servo angle is less than 180 degrees
      servoAngle += servoInc; // Decrement angle
      myservoRight.write(servoAngle); // Write new angle to servo
      Serial.println("Inside increment angle");
      readIn = '\0';
    }
    if (readIn == 'l' && servoAngle > 10) 
    { // else if input is l and servo angle is more than 10 degrees
      servoAngle -= servoInc; // Decrement angle

      myservoRight.write(servoAngle); // Write new angle to servo
      Serial.println("Inside increment angle");
      readIn = '\0';
    }
    
   delay(20);
