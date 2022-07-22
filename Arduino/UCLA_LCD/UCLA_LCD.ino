  // include the library code:
  #include <LiquidCrystal.h>
  
  const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
  int count;
  
  byte heart[8] = { B00000,B01010,B11111,B11111,B11111,B01110,B00100,B00000};
  byte letterA[8] = { B01110, B11111, B11011, B11011, B11111, B11011, B11011, B11011};
  byte letterU[8] = {
    B11011,
    B11011,
    B11011,
    B11011,
    B11011,
    B11111,
    B11111,
    B01110
  };

  byte letterC[] = {
  B01110,
  B11011,
  B11000,
  B11000,
  B11000,
  B11000,
  B11001,
  B01110
};
  
  
  void setup() {
    lcd.begin(16, 2);
    lcd.home();
    Serial.begin(9600);
  }
  
  void loop() {
    //lcd.clear();
    lcd.createChar(1, heart);
    lcd.setCursor(6,0);
    lcd.write(1);

    lcd.createChar(2, letterU);
    lcd.setCursor(7, 0);
    lcd.write(2);

    lcd.createChar(3, letterC);
    lcd.setCursor(8, 0);
    lcd.write(3);
  
    lcd.createChar(5, letterA);
    lcd.setCursor(10,0);
    lcd.write(5);
    
    lcd.setCursor(11,0);
    lcd.write(1);
  

  }
