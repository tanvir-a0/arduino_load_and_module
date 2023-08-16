#include <Servo.h>
int servoPin=9;
int servoPosition =  0 ; //0 in degree;

int potresPin = A0;
int potresValue  ;
int prV;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7,HIGH);

  potresValue = analogRead(potresPin);
  Serial.print("potresValue = ");

  prV=potresValue/10;
  Serial.print(prV);
  
  servoPosition = (((prV-70.)/69.)*180.+180.);

  Serial.print(" servoPosition = ");
  Serial.println(servoPosition);


  myServo.write(servoPosition);
  delay(0);
  
  

}
