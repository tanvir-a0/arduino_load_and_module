#include <Servo.h>
int servoPin=9;
int servoPosition =  0 ; //0 in degree;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("What is the angle for sarvo? ");
  while(Serial.available() == 0)
  {
    
  }
  servoPosition = Serial.parseInt();
  myServo.write(servoPosition);

}
