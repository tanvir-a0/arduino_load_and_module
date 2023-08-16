int trigPin = 3;
int echoPin = 5;
int pingTravelTime;
float distance;

#include <LiquidCrystal.h>
int rs = 4;
int en = 7;
int d4 = 8;
int d5 = 9;
int d6 = 10;
int d7 = 11;
LiquidCrystal lcd ( rs, en , d4 , d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lcd.begin(16,2);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  pingTravelTime = pulseIn(echoPin,HIGH);//int Microseconds

  distance = 0.0187909164 * pingTravelTime;
  
  Serial.print("pingTravelTime = ");
  Serial.print(pingTravelTime);
  Serial.print(" distance = ");
  Serial.println(distance);

  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("cm");
  lcd.setCursor(0,1);
  lcd.print(distance*0.0328084);
  lcd.print("feet");
   lcd.print(distance*0.393701);
  lcd.print("Inch");
  delay(1000);
  lcd.clear();

}



 
