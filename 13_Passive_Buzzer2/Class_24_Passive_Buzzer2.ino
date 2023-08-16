 int buzzPin = 10;
 int buzzValue;
 int potPin = A0;
 int potValue;
 
 
 
 
 
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin,OUTPUT);
  pinMode(potPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  Serial.print("potValue = ");
  Serial.print(potValue);

  buzzValue =((10000.-9.7165*potValue)/100);
  Serial.print(" buzzValue = ");
  Serial.println(buzzValue*100);

  analogWrite(buzzPin,buzzValue);

}
