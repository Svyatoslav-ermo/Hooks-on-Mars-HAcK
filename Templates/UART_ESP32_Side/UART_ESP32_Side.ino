void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
  while (!Serial2) {
    ;
  }
}

void loop() {
  if(Serial2.available()){
    Serial.println("Message Received: ");
    Serial.println(Serial2.readString());
  }

}
