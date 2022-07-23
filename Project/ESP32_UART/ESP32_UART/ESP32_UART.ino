#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)           //error catching
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT; //declares the Bluetooth object

#define LED 32
#define BUTTON 14

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

  Serial.begin(115200);
  Serial1.begin(9600); // Arduino Communication
  SerialBT.begin("ESP32_Hooks_On_Mars");  //begins Bluetooth Serial connection
  Serial.println("Started successfully.");

  digitalWrite(LED, LOW);
}

char readIn;
int bright = 0;

void loop() {
  
  if (SerialBT.available()) //if there are bytes available in the buffer
    readIn = char(SerialBT.read()); //read in one and store it in readIn

  if (readIn == 'w') {
    Serial1.print('w');
    readIn = '\0';
  }

    if (readIn == 's') {
    Serial1.print('s');
    readIn = '\0';
  }

  if (readIn == 'a') {
    Serial1.print('a');
    readIn = '\0';
  }

    if (readIn == 'd') {
    Serial1.print('d');
    readIn = '\0';
  }

    if (readIn == '1') {
    Serial1.print('1');
    readIn = '\0';
  }

    if (readIn == '2') {
    Serial1.print('2');
    readIn = '\0';
  }

    if (readIn == '3') {
    Serial1.print('3');
    readIn = '\0';
  }

    if (readIn == '4') {
    Serial1.print('4');
    readIn = '\0';
  }

    if (readIn == '5') {
    Serial1.print('5');
    readIn = '\0';
  }

    if (readIn == '0') {
    Serial1.print('0');
    readIn = '\0';
  }

   delay(20);

    //SerialBT.println("ON!");

    //SerialBT.println("OFF!");

}
