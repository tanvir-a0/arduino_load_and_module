int buzzPin=11;
int buzzTime1=1;
int buzzTime2=10;
int buzzTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin,OUTPUT);
  pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buzzTime = (analogRead(A0)/10)*10;
  Serial.println(buzzTime);
  
  digitalWrite(buzzPin,HIGH);
  delayMicroseconds(buzzTime);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(buzzTime);

}
