// include the library code:
#include <LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int count;

byte heart[8] = { B00000,B01010,B11111,B11111,B11111,B01110,B00100,B00000};
byte letterA[8] = { B01110, B11111, B11011, B11011, B11111, B11011, B11011, B11011};

void setup() {
  lcd.begin(16, 2);
  lcd.home();
  Serial.begin(9600);
}

void loop() {
  //lcd.clear();
  lcd.createChar(1, heart);
  lcd.setCursor(0,0);
  lcd.write(1);

  lcd.createChar(5, letterA);
  lcd.setCursor(7,1);
  lcd.write(5);
}
