#define VR A0
#define LED1 4
#define LED2 2
#define LED3 7
#define LED4 8

void setup() {
  Serial.begin(115200);
  pinMode(VR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

}

void loop() {
  int sensorValue = analogRead(VR);
  float voltage = sensorValue * (5/ 1024.0);
  Serial.println(voltage);
  if (voltage >= 1)
  {
    digitalWrite(LED1,HIGH);
  }
  else
  {
    digitalWrite(LED1,LOW);
  }

  if (voltage >= 2)
  {
    digitalWrite(LED2,HIGH);
  }
  else
  {
    digitalWrite(LED2,LOW);
  }
  if (voltage >= 3)
  {
    digitalWrite(LED3,HIGH);
  }
  else
  {
    digitalWrite(LED3,LOW);
  }
  if (voltage >= 4)
  {
    digitalWrite(LED4,HIGH);
  }
  else
  {
    digitalWrite(LED4,LOW);
  }

}
