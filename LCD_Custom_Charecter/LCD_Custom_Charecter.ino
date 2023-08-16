#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

byte customChar1[] = {
  B01000,
  B01100,
  B01110,
  B11111,
  B11111,
  B01110,
  B01100,
  B01000
};

byte customChar2[] = {
  B00010,
  B00110,
  B01110,
  B11111,
  B11111,
  B01110,
  B00110,
  B00010
};

void setup() {
  lcd.begin(16, 2);
}

void loop() { 
  for ( int i = 0 ; i < 16 ; i = i+1)
  {
  lcd.createChar(0, customChar1);
  lcd.setCursor(i, 0);
  lcd.write((byte)0);
  delay(25);
  lcd.clear();
  }
  for ( int i = 15 ; i >=0 ; i = i-1)
  {
  lcd.createChar(0, customChar2);
  lcd.setCursor(i, 1);
  lcd.write((byte)0);
  delay(25);
  lcd.clear();
  }
  
  }
