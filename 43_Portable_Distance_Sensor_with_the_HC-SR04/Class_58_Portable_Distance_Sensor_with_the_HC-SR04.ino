#include <LiquidCrystal.h>
int rs = 4 ;
int en = 7 ;
int d4 = 8 ;
int d5 = 9 ;
int d6 = 10 ;
int d7 = 11 ;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int trigpin = 3;
int echopin = 5;
int traveltime;
float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);

  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);

  traveltime = pulseIn(echopin,HIGH);
  distance = 0.0187909164 * traveltime;

  Serial.print("traveltime = ");
  Serial.print(traveltime);
  Serial.print(" distance = ");
  Serial.print(distance);
  Serial.println("");

  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("cm");
  lcd.setCursor(0,1);
  lcd.print(distance*0.393700787); 
  lcd.print("inches");
  

}
