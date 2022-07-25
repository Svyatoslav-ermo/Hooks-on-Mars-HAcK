// include the library code:
  #include <LiquidCrystal.h>

// ASSIGNING PINS 
  const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
  int count;

// EYES - WEARING GLASSES!
  // (1) eyes 1/6 (LEFT - UPPER)
  byte eyes1[8] = { B01111, B10000, B10000, B00000, B11111, B10000, B10111, B10111 };
  // (2) eyes 2/6 (MID - UPPER)
  byte eyes2[8] = { B11111, B00000, B00000, B00000, B11111, B00000, B11111, B11111 };
  // (3) eyes 3/6 (RIGHT - UPPER)
  byte eyes3[8] = { B11110, B00001, B00001, B00000, B11111, B00001, B11101, B11101 };
  // (4) eyes 4/6 (LEFT - LOWER)
  byte eyes4[8] = { B10111, B10111, B10111, B10111, B10111, B10111, B10000, B11111 };
  // (5) eyes 5/6 (MID - LOWER)
  byte eyes5[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B00000, B11111 };
  // (6) eyes 6/6 (RIGHT - LOWER)
  byte eyes6[8] = { B11101, B11101, B11101, B11101, B11101, B11101, B00001, B11111 };
  // (7) Glasses BRIDGE
  byte glasses[8] = { B00000, B00000, B00000, B00000, B00000, B11111, B11111, B11111 };
//sparkling
  // (8) sparkling
  byte spark[8] = { B00000, B00100, B00100, B01110, B11111, B01110, B00100, B00100 };
  
// CREATING 16X2 LCD
  void setup() {
    lcd.begin(16, 2);
    lcd.home();
    Serial.begin(9600);
  }
  
  void loop() {
  // lcd.createChar -- defining character with the number
  // only have to use lcd.write after defining the character with lcd.createChar
    
    // first row
    lcd.createChar(1, eyes1);
    lcd.setCursor(0,0);
    lcd.write(1);
    
    lcd.createChar(2, eyes2);
    lcd.setCursor(1,0);
    lcd.write(2);
    
    lcd.setCursor(2,0);
    lcd.write(2);
    
    lcd.setCursor(3,0);
    lcd.write(2);
    
    lcd.setCursor(4,0);
    lcd.write(2);
    
    lcd.createChar(3, eyes3);
    lcd.setCursor(5,0);
    lcd.write(3);
    
    lcd.createChar(7, glasses);
    lcd.setCursor(6,0);
    lcd.write(7);
    
    lcd.setCursor(7,0);
    lcd.write(7);
    
    lcd.setCursor(8,0);
    lcd.write(7);
    
    lcd.setCursor(9,0);
    lcd.write(1);
    
    lcd.setCursor(10,0);
    lcd.write(2);
    
    lcd.setCursor(11,0);
    lcd.write(2);
    
    lcd.setCursor(12,0);
    lcd.write(2);
    
    lcd.setCursor(13,0);
    lcd.write(2);
    
    lcd.setCursor(14,0);
    lcd.write(3);
    
    lcd.createChar(8, spark);
    lcd.setCursor(15,0);
    lcd.write(8);
    
    // second row
    
    lcd.createChar(4, eyes4);
    lcd.setCursor(0,1);
    lcd.write(4);
    
    lcd.createChar(5, eyes5);
    lcd.setCursor(1,1);
    lcd.write(5);
    
    lcd.setCursor(2,1);
    lcd.write(5);
    
    lcd.setCursor(3,1);
    lcd.write(5);
    
    lcd.setCursor(4,1);
    lcd.write(5);
    
    lcd.createChar(6, eyes6);
    lcd.setCursor(5,1);
    lcd.write(6);
    
    lcd.setCursor(9,1);
    lcd.write(4);
    
    lcd.setCursor(10,1);
    lcd.write(5);
    
    lcd.setCursor(11,1);
    lcd.write(5);
    
    lcd.setCursor(12,1);
    lcd.write(5);
    
    lcd.setCursor(13,1);
    lcd.write(5);
    
    lcd.setCursor(14,1);
    lcd.write(6);
    
  delay(10000)
  ;}
