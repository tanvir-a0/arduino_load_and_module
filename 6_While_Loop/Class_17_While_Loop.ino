int potPin = A0;
int potValue;
int redPin = 5;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potPin,INPUT);
  pinMode(redPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  potValue=analogRead(potPin);
  Serial.println(potValue);

  while(potValue>1000)
  {
    potValue=analogRead(potPin);
    digitalWrite(redPin, HIGH);
    Serial.println(potValue);
  }
  digitalWrite(redPin,LOW);

}
