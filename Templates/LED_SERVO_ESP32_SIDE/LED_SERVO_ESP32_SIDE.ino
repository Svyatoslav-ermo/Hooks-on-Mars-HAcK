void setup() {
  Serial1.begin(9600);
}

void loop() {
  Serial1.print('l');
  delay(4000);
  Serial1.print('s');
  delay(4000);
}
