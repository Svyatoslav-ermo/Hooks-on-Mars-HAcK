// include the library code:
  #include <LiquidCrystal.h>
  
  const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
  int count;

  // (1)
  byte full[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
  // (2) 
  byte sparkling1[8] = { B11101, B11101, B11101, B11000, B11101, B11101, B11111, B11111 };
  // (3)
  byte sparkling2[8] = { B11111, B11101, B11000, B11101, B10111, B00011, B10111, B11111 };
  // (4)
  byte sparkling3[8] = { B11011, B11011, B10001, B00000, B10001, B11011, B11011, B11111 };
  // (5)
  byte sparkling4[8] = { B10111, B10111, B00011, B10111, B10111, B11101, B11000, B11101 };
  // (6)
  byte smile_left[8] = { B11100, B11100, B01100, B01100, B01100, B00110, B00111, B00011 };
  // (7)
  byte smile_ctr[8] = { B00000, B00000, B00000, B00000, B00000, B00000, B11111, B11111 };
  // (8)  
  byte smile_right[8] = { B00111, B00111, B00110, B00110, B00110, B01110, B11100, B11000 };  
  
 // CREATING 16X2 LCD
  void setup() {
    lcd.begin(16, 2);
    lcd.home();
    Serial.begin(9600);
  }
  
  void loop() {
    // first row
    lcd.createChar(1, full);
    lcd.setCursor(0,0);
    lcd.write(1);
    
    lcd.setCursor(1,0);
    lcd.write(1);
    
    lcd.setCursor(2,0);
    lcd.write(1);
    
    lcd.createChar(2, sparkling1);
    lcd.setCursor(3,0);
    lcd.write(2);
    
    lcd.createChar(3, sparkling2);
    lcd.setCursor(4,0);
    lcd.write(3);
    
    lcd.setCursor(11, 0);
    lcd.write(1);
   
    lcd.setCursor(12, 0);
    lcd.write(1);
    
    lcd.setCursor(13, 0);
    lcd.write(1);
    
    lcd.setCursor(14, 0);
    lcd.write(3);
    
    lcd.createChar(5, sparkling4);
    lcd.setCursor(15, 0);
    lcd.write(5);
    
    // second row
    lcd.setCursor(0,1);
    lcd.write(1);
   
    lcd.setCursor(1,1);
    lcd.write(1);
    
    lcd.setCursor(2,1);
    lcd.write(1);
    
    lcd.createChar(4, sparkling3);
    lcd.setCursor(3,1);
    lcd.write(4);
    
    lcd.setCursor(4,1);
    lcd.write(5);
    
    lcd.createChar(6, smile_left);
    lcd.setCursor(6, 1);
    lcd.write(6);
    
    lcd.createChar(7, smile_ctr);
    lcd.setCursor(7, 1);
    lcd.write(7);
    
    lcd.setCursor(8, 1);
    lcd.write(7);
    
    lcd.createChar(8, smile_right);
    lcd.setCursor(9, 1);
    lcd.write(8);
    
    lcd.setCursor(11, 1);
    lcd.write(1);
    
    lcd.setCursor(12, 1);
    lcd.write(1);
    
     lcd.setCursor(13, 1);
    lcd.write(1);
    
    lcd.setCursor(14, 1);
    lcd.write(2);
  
    lcd.setCursor(15, 1);
    lcd.write(3);
  
  delay(10000)
  ;}
