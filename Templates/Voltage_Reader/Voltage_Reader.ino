#define VR A0

void setup() {
  Serial.begin(115200);
  pinMode(VR, INPUT);

}

void loop() {
  int sensorValue = analogRead(VR);
  float voltage = sensorValue * (5/ 1024.0);
  Serial.println(voltage);
  delay(1000);
  

}
