#include <LiquidCrystal.h>
int rs = 4;
int en = 7;
int d4 = 8;
int d5 = 9;
int d6 = 10;
int d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  
  Sensor.begin();
}

void loop() {

  
}
