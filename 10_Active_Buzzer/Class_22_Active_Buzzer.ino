int myNumber; 
int buzzPin = 12; 
int potValue;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);

  Serial.println(potValue);
  
  if(potValue > 1000 )
  {
    digitalWrite(buzzPin,HIGH);
  }
  else{
    digitalWrite(buzzPin,LOW);
  }
  
}
