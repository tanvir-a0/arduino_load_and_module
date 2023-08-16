#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

byte customChar0[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};
byte customChar1[]={
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
};
byte customChar2[]={
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0,customChar0);
  lcd.createChar(1,customChar1);
  lcd.createChar(2,customChar2);
  
}

void loop() { 
  lcd.setCursor(0,0);
  lcd.write((byte)0);  

  lcd.setCursor(1,0);
  lcd.write((byte)1);

  lcd.setCursor(2,0);
  lcd.write((byte)2);
  
  
}
