#define POT A0

#define LED_1 3
#define LED_2 5
#define LED_3 6
#define LED_4 9

int ADC_Max = 1024;
int val;
float voltage;

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  pinMode(POT, INPUT);

  Serial.begin(115200);

}

void loop() {
  val = analogRead(POT);
  voltage = val * (5/ ADC_Max);
  Serial.println(voltage);

  if (voltage > 0)
    digitalWrite(LED_1, HIGH);
  else
    digitalWrite(LED_1, LOW);
  if (voltage >= 1.25)
    digitalWrite(LED_2, HIGH);
  else
    digitalWrite(LED_2, LOW);
  if (voltage >= 2.5)
    digitalWrite(LED_3, HIGH);
  else
    digitalWrite(LED_3, LOW);
  if (voltage >= 3.75)
    digitalWrite(LED_4, HIGH);
  else
    digitalWrite(LED_4, LOW);
  

}
