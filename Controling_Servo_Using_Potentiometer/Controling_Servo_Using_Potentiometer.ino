#include <Servo.h>
int servopin = 11;
int servoposition ;
Servo myservo;

int potpin = A0;
int potvalue;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potpin,INPUT);
  myservo.attach(servopin);
  pinMode(potpin , INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  potvalue = analogRead(potpin);

  servoposition = (((potvalue - 2.)/1017.)*180.);


  myservo.write(servoposition);

  Serial.print("potvalue = ");
  Serial.print(potvalue);
  Serial.print(" servoposition = ");
  Serial.println(servoposition);

  
}
