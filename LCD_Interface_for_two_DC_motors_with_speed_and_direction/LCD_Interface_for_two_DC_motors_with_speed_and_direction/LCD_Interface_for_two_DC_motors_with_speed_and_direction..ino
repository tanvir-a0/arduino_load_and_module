#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

int en12 = 0 ;// speed of x1 motor
bool in1 = LOW ;// direction of x1 motor
int en34 = 0 ;// speed of x2 motor
bool in3 = HIGH ;// direction of x2 motor

byte forward_sign[]={
  B00100,
  B01110,
  B11111,
  B00100,
  B01110,
  B11111,
  B00000,
  B00000
};

byte backward_sign[]={
  B00000,
  B00000,
  B11111,
  B01110,
  B00100,
  B11111,
  B01110,
  B00100
};

byte stop_sign[]={
  B00100,
  B01110,
  B11011,
  B10001,
  B11011,
  B01110,
  B00100,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.createChar(0,forward_sign);
  lcd.createChar(1,backward_sign);
  lcd.createChar(2,stop_sign);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  lcd.setCursor(0,0);
  lcd.print("x1:");
  lcd.print(en12);
  lcd.setCursor(7,0);
  
  if(en12 == 0)
  {
    lcd.write((byte)2);
  }
  else{
  if(in1 == HIGH)
  {
    lcd.write((byte)0);
  }
  if(in1 == LOW)
  {
    lcd.write((byte)1);
  }
  }
  
  lcd.setCursor(0,1);
  lcd.print("x2:");
  lcd.print(en34);
  lcd.setCursor(7,1);
  if(en34 == 0)
  {
    lcd.write((byte)2);
  }
  else{
  if(in3 == HIGH)
  {
    lcd.write((byte)0);
  }
  if(in3 == LOW)
  {
    lcd.write((byte)1);
  }
  }
  

  
}
