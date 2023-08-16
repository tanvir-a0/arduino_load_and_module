#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

byte start_of_bar[] = {B11111,B10000,B10000,B10000,B10000,B10000,B10000,B11111};
byte middle_of_bar[] = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111};
byte end_of_bar[] = {B11111,B00001,B00001,B00001,B00001,B00001,B00001,B11111};
byte loading_sign[] = {B11100,B11110,B01111,B00111,B00111,B01111,B11110,B11100};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.createChar(0,start_of_bar);
  lcd.createChar(1,middle_of_bar);
  lcd.createChar(2,end_of_bar);
  lcd.createChar(3,loading_sign);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.write((byte)0);
  for(int i = 1; i < 15; i=i+1)
  {
    lcd.setCursor(i,0);
    lcd.write((byte)1);
  }
  lcd.setCursor(15,0);
  lcd.write((byte)2);

  for(int i = 0 ; i < 16 ; i = i + 1)
  {
    lcd.setCursor(i,0);
    lcd.write((byte)3);
    delay(50);
    lcd.setCursor(i,0);
    if(i==0){
      lcd.write((byte)0);
    }
    lcd.write((byte)1);
  }

}
