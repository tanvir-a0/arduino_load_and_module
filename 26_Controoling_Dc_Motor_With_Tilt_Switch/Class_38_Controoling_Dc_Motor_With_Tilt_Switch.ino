int speedPin = 5;
int speedValue;
int dirPin1 = 4;
int dirPin2 = 2;
int tiltSwPin = 12;
int tiltSwValue ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dirPin1,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  pinMode(speedPin,OUTPUT);
  pinMode(tiltSwPin,INPUT);
  digitalWrite(tiltSwPin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly://Serial.print("");

  tiltSwValue = digitalRead(tiltSwPin);
  Serial.println(tiltSwValue);

  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW);

  speedValue = 150;
  int if_motor_started = 0;
  
  if(tiltSwValue == 0)
  {
    if(if_motor_started == 0)
    {
       analogWrite(speedPin,255);
       delay(100);
       if_motor_started = 1;
    }
    while((if_motor_started == 1)&&(tiltSwValue == 0))
    {
       analogWrite(speedPin,speedValue);
       tiltSwValue = digitalRead(tiltSwPin);
       //Serial.print("a");
    }
  }
  if(tiltSwValue == 1)
  {
    analogWrite(speedPin,0);
    delay(100);
    analogWrite(speedPin,0);
    //Serial.print("s");
  }
  
  
   

}

  
