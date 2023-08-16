#include <Servo.h>
int servopin = 10;
float servoposition ;
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
  
  for(int servoposition = 0; servoposition <=180 ; servoposition = servoposition + 1)
  {
    myservo.write(servoposition);
    delay(analogRead(potpin));
    Serial.print(" servoposition = ");
  Serial.println(servoposition);
  }
  
}
