#include <LiquidCrystal.h>

int rs=12;
int en=11;
int d4=5;
int d5 =4;
int d6=3;
int d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int pot_pin = A0;
int pot_value ;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:

  pot_value = analogRead(pot_pin);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("pot_value=");
  lcd.print(pot_value);
  delay(100);
  
  
  

}
