int motorSpeedpin = 3; 
int motorSpeedvalue;
int motorDir1pin = 4;
int motorDir2pin = 2;

int xpin = A0;
int xvalue;
int ypin = A1;
int yvalue;
int swpin = 12;
int swvalue;

int push_motor_to_start;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(motorSpeedpin,OUTPUT);
  pinMode(motorDir1pin,OUTPUT);
  pinMode(motorDir2pin,OUTPUT);
  
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(swpin,INPUT);
  digitalWrite(swpin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("");
  xvalue = analogRead(xpin);
  yvalue = analogRead(ypin);
  swvalue = digitalRead(swpin);
  
  
  
  if((xvalue>=500)&&(xvalue<=530))
  {
    motorSpeedvalue = 0;
    digitalWrite(motorDir1pin,HIGH);
    digitalWrite(motorDir2pin,LOW);
    analogWrite(motorSpeedpin,0);
    push_motor_to_start = 0;
    
  }
  if((xvalue>=0)&&(xvalue<500))
  {
    motorSpeedvalue = (xvalue/(-500.))*255.+255.;
    digitalWrite(motorDir1pin,HIGH);
    digitalWrite(motorDir2pin,LOW);
    if(push_motor_to_start == 0)
    {
      analogWrite(motorSpeedpin,255);
      delay(50);
      push_motor_to_start = push_motor_to_start+1;
    }
    analogWrite(motorSpeedpin,motorSpeedvalue);
  }
  if((xvalue>530)&&(xvalue<=1023))
  {
    motorSpeedvalue = ((xvalue-530.)/493.)*255;
    digitalWrite(motorDir1pin,LOW);
    digitalWrite(motorDir2pin,HIGH);
    if(push_motor_to_start == 0)
    {
      analogWrite(motorSpeedpin,255);
      delay(50);
      push_motor_to_start = push_motor_to_start+1;
    }
    analogWrite(motorSpeedpin,motorSpeedvalue);
  }
  
  Serial.print("xvalue = ");              Serial.print(xvalue);
  Serial.print(" yvalue = ");             Serial.print(yvalue);
  Serial.print(" swvalue = ");            Serial.print(swvalue);
  Serial.print(" motorSpeedvalue = ");    Serial.print(motorSpeedvalue);
  Serial.print(" push_motor_to_start = ");Serial.println(push_motor_to_start);
  delay(1);
  


  
}
