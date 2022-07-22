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
  SerialBT.begin("ESP32");  //begins Bluetooth Serial connection
  Serial.println("Started successfully.");

  digitalWrite(LED, LOW);
}

char readIn;
int bright = 0;
int brightStep = 1;
int oldBright = 255;

void loop() {
  
  if (SerialBT.available()) //if there are bytes available in the buffer
    readIn = char(SerialBT.read()); //read in one and store it in readIn

  if (readIn == 'l') {
    Serial1.print('l');
    readIn = '\0';
  }

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

    if (readIn == 'u') {
    Serial1.print('u');
    readIn = '\0';
  }

    if (readIn == 'j') {
    Serial1.print('j');
    readIn = '\0';
  }
  
  
  else if (readIn == 'l') {
    if (bright > 0) {
      oldBright = bright;
      bright = 0;
      analogWrite(LED, bright);
      readIn = '\0';
    }
    else {
      bright = oldBright;
      analogWrite(LED, bright);
      readIn = '\0';
    }
  }

else if (readIn == 'w') {
    if (bright > 0) {
      oldBright = bright;
      bright = 0;
      analogWrite(LED, bright);
      readIn = '\0';
    }
    else {
      bright = oldBright;
      analogWrite(LED, bright);
      readIn = '\0';
    }
  }

  else if (readIn == 's') {
    if (bright > 0) {
      oldBright = bright;
      bright = 0;
      analogWrite(LED, bright);
      readIn = '\0';
    }
    else {
      bright = oldBright;
      analogWrite(LED, bright);
      readIn = '\0';
    }
  }

else if (readIn == 'a') {
    if (bright > 0) {
      oldBright = bright;
      bright = 0;
      analogWrite(LED, bright);
      readIn = '\0';
    }
    else {
      bright = oldBright;
      analogWrite(LED, bright);
      readIn = '\0';
    }
  }

else if (readIn == 'd') {
    if (bright > 0) {
      oldBright = bright;
      bright = 0;
      analogWrite(LED, bright);
      readIn = '\0';
    }
    else {
      bright = oldBright;
      analogWrite(LED, bright);
      readIn = '\0';
    }
  }

else if (readIn == 'u') {
    if (bright > 0) {
      oldBright = bright;
      bright = 0;
      analogWrite(LED, bright);
      readIn = '\0';
    }
    else {
      bright = oldBright;
      analogWrite(LED, bright);
      readIn = '\0';
    }
  }

else if (readIn == 'j') {
    if (bright > 0) {
      oldBright = bright;
      bright = 0;
      analogWrite(LED, bright);
      readIn = '\0';
    }
    else {
      bright = oldBright;
      analogWrite(LED, bright);
      readIn = '\0';
    }
  }


  if(digitalRead(BUTTON) == HIGH)
    SerialBT.println("ON!");
  else
    SerialBT.println("OFF!");
  delay(20);
}
