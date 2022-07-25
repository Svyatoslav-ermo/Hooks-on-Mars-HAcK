#include <ESP32Servo.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)           //error catching
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

Servo myservoLeft;
Servo myservoRight;
// Create Servo object
int servoPinLeft = 13; // Define Servo pin
int servoPinRight = 12;
int servoAngle = 10; // Set Servo angle
BluetoothSerial SerialBT; //declares the Bluetooth object

void setup() {
  myservoLeft.attach(servoPinLeft, 500, 2400); // attach servo
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
    if (readIn == 'p' && servoAngle > 10) { // else if input is o and servo angle is less than 180 degrees
      servoAngle -= servoInc; // Decrement angle
      myservoLeft.write(servoAngle); // Write new angle to servo
      Serial.println("Inside increment angle");
      readIn = '\0';
     // myservoLeft.write(100); 
    }
    if (readIn == 'k' && servoAngle < 180) { // else if input is o and servo angle is less than 180 degrees
      servoAngle += servoInc; // Decrement angle
      myservoRight.write(servoAngle); // Write new angle to servo
      Serial.println("Inside increment angle");
      readIn = '\0';
    }
    if (readIn == 'l' && servoAngle > 10) { // else if input is o and servo angle is less than 180 degrees
      servoAngle -= servoInc; // Decrement angle
      myservoRight.write(servoAngle); // Write new angle to servo
      Serial.println("Inside increment angle");
      readIn = '\0';
    }
    
//    if (readIn == '1') {
//    Serial1.print('1');
//    readIn = '\0';
//  }
//
//    if (readIn == '2') {
//    Serial1.print('2');
//    readIn = '\0';
//  }
//
//    if (readIn == '3') {
//    Serial1.print('3');
//    readIn = '\0';
//  }
//
//    if (readIn == '4') {
//    Serial1.print('4');
//    readIn = '\0';
//  }
//
//    if (readIn == '5') {
//    Serial1.print('5');
//    readIn = '\0';
//  }
//
//    if (readIn == '0') {
//    Serial1.print('0');
//    readIn = '\0';
//  }

   delay(20);

    //SerialBT.println("ON!");

    //SerialBT.println("OFF!");

}
