#include <Stepper.h>
int StepsPerRevolution = 2048;
int motSpeed = 10;
Stepper myStepper(StepsPerRevolution, 8 , 10 , 9 , 11 );
int steps = 2048;

int delayTime = 500;

int buttonPin = 6;
int motorDir = 1;
int buttonValueNew ;
int buttonValueOld = 1;



void setup() {  // put your setup code here, to run once:
 
Serial.begin(9600);
myStepper.setSpeed(motSpeed);

pinMode (buttonPin,INPUT);
digitalWrite(buttonPin,HIGH);
}

void loop() {  // put your main code here, to run repeatedly:
  
buttonValueNew = digitalRead(buttonPin);

if((buttonValueNew == 0) && (buttonValueOld == 1))
{
  motorDir = (-1)*motorDir;
}
myStepper.step(motorDir*5);

buttonValueOld = buttonValueNew;

Serial.print("steps = ");
Serial.print(motorDir);
Serial.print(" buttonValueNew = ");
Serial.print(buttonValueNew); 
Serial.print(" buttonValueOld = ");
Serial.println(buttonValueOld); 


}
