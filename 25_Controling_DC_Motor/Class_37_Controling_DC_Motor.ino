int speedPin = 5;//en1
int directionpin1 = 4;//in1
int directionpin2 = 3; //in2
int motorspeed = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin,OUTPUT);
  pinMode(directionpin1,OUTPUT);
  pinMode(directionpin2,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Enter the speed of the motor (0 to 255)");
  while(Serial.available()==0){
  }
  motorspeed = Serial.parseInt();
  
  digitalWrite(directionpin1,LOW);
  digitalWrite(directionpin2,HIGH);
  
  analogWrite(speedPin,255);
  delay(100);
  analogWrite(speedPin,motorspeed);
  
  
  

}
