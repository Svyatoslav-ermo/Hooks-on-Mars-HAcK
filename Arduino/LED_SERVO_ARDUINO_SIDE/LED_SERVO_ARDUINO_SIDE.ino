#include <Servo.h>
#define LED 5

Servo myservo;
int servoPin = 3;
char uart_receive;

void setup() {
  myservo.attach(servoPin, 500, 2400);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);

  while(!Serial) {
    ;
  }
}

void loop() {
  if (Serial.available()){
    uart_receive = char(Serial.read());
    if (uart_receive == 'l'){
      digitalWrite(LED, HIGH);
      delay(2000);
      digitalWrite(LED, LOW);
    }
    else if (uart_receive == 's'){
      myservo.write(180);
      delay(2000);
      myservo.write(10);
    }
  }

  delay(2000);
}
