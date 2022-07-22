#define LED1 13
#define LED2 12
#define LED3 8

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}

void loop() {
  digitalWrite(LED1,HIGH);
  delay(100);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  delay(100);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  delay(100);
  digitalWrite(LED3, LOW);

}
