void setup() {
  Serial.begin(9600);
  while(!Serial) {
    ;
  }
}

char uart_receive;

void loop() {
  if (Serial.available()){
    uart_receive = char(Serial.read());
    Serial.print(uart_receive);
    
  }

  delay(2000);
}
