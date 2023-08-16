#include <Servo.h>
Servo servo1;
Servo servo2;
int servo2pin = 10;
int servo1value;
int servo1pin = 11;
int servo2value;

int xpin = A1;
int ypin = A2;
int swpin = 2;

int xval ;
int yval  ;
int swval ; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin ( 9600 );
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(swpin,INPUT);
  digitalWrite(swpin,HIGH);
  pinMode(7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  xval=analogRead(xpin);
  yval=analogRead(ypin);
  swval=digitalRead(swpin);
  
  servo1value = ((xval-11.)/1009.)*180.;
  servo2value = ((yval-13.)/1002.)*180.;

  servo1.write(servo1value);
  servo2.write(servo2value);

  if(swval == 0){
    digitalWrite(7,LOW);
  }
  if(swval == 1){
    digitalWrite(7,HIGH);
  }
  

  Serial.print("xval = ");
  Serial.print(xval);
  Serial.print(" yval = ");
  Serial.print(yval);
  Serial.print(" swval = ");
  Serial.print(swval);
  Serial.print(" servo1value = ");
  Serial.print(servo1value);
  Serial.print(" servo2value = ");
  Serial.println(servo2value);

}
