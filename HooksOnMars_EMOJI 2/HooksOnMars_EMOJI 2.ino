// include the library code:
  #include <LiquidCrystal.h>
  
// ASSIGNING PINS
  const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  

  int count;

// ALL SELECTED 16X2
  // (1)
  byte full[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
// SPARKLES
  // (2)
  byte tear1[8] = { B11111, B11111, B11101, B11101, B11000, B11101, B10101, B10111 };
  // (3)
  byte tear2[8] = { B10111, B10111, B00011, B10111, B10110, B11110, B11100, B11100 }; 
// TEARS
  // (4)
  byte tear3[8] = { B10111, B10111, B00011, B00011, B00001, B00001, B00000, B00000 };
  // (5)
  byte tear4[8] = { B00011, B10111, B10111, B11111, B11101, B11000, B11101, B11101 };
  // (6)
  byte tear5[8] = { B11100, B11100, B00100, B00110, B11111, B11011, B10001, B11011 };
  // (7)
  byte tear6[8] = { B00000, B00000, B00000, B00001, B00011, B11111, B11111, B11111 };
// LIPS
  // (8)  
  byte lips[8] = { B00000, B00000, B11111, B11111, B11111, B11111, B00000, B00000 };
  
//CREATING 16X3 LCD
  void setup() {
    lcd.begin(16, 2);
    lcd.home();
    Serial.begin(9600);
  }
  

  void loop() {
   // lcd.createChar -- defining character with the number
   // only have to use lcd.write after defining the character with lcd.createChar
   
    // first row
    lcd.createChar(1, full);
    lcd.setCursor(0,0);
    lcd.write(1);
    
    lcd.createChar(2, tear1);
    lcd.setCursor(1,0);
    lcd.write(2);
    
    lcd.createChar(3, tear2);
    lcd.setCursor(2,0);
    lcd.write(3);
    
    lcd.createChar(4, tear3);
    lcd.setCursor(3,0);
    lcd.write(4);
    
    lcd.setCursor(4,0);
    lcd.write(1);
    
    lcd.setCursor(11,0);
    lcd.write(1);
    
    lcd.setCursor(12,0);
    lcd.write(2);
    
    lcd.setCursor(13,0);
    lcd.write(3);
    
    lcd.setCursor(14,0);
    lcd.write(4);
    
    lcd.setCursor(15,0);
    lcd.write(1);
  
    //second row
    lcd.setCursor(0,1);
    lcd.write(1);
    
    lcd.createChar(5, tear4);
    lcd.setCursor(1,1);
    lcd.write(5);
    
    lcd.createChar(6, tear5);
    lcd.setCursor(2,1);
    lcd.write(6);
    
    lcd.createChar(7, tear6);
    lcd.setCursor(3,1);
    lcd.write(7);
    
    lcd.setCursor(4,1);
    lcd.write(1);
    
    lcd.createChar(8, lips);
    lcd.setCursor(6,1);
    lcd.write(8);
    
    lcd.setCursor(7,1);
    lcd.write(8);
    
    lcd.setCursor(8,1);
    lcd.write(8);
    
    lcd.setCursor(9,1);
    lcd.write(8);
    
    lcd.setCursor(11,1);
    lcd.write(1);
    
    lcd.setCursor(12,1);
    lcd.write(5);
    
    lcd.setCursor(13,1);
    lcd.write(6);
    
    lcd.setCursor(14,1);
    lcd.write(7);
    
    lcd.setCursor(15,1);
    lcd.write(1);
    
  delay(10000)
  ;}
