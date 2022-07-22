#include <Servo.h>
#define POT A0

Servo myservo;
int servoPin = 3;

int ADC_Max = 1024;
int val;
int angle;

void setup() {
  myservo.attach(servoPin, 500, 2400);

  Serial.begin(115200);
}

void loop() {
  val = analogRead(POT);
  
  angle = map(val, 0, ADC_Max, 10,180);
  Serial.println(angle);
  myservo.write(angle);
  delay(50);

}
