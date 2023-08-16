int blinkNumber;
int blinkDelay;
int ledPin = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("How many times do you want to blink?");

  while(Serial.available()==0)
  {
    
  }
  blinkNumber = Serial.parseInt();

  Serial.println("What is the delay time?");

  while(Serial.available()==0)
  {
    
  }
  blinkDelay = Serial.parseInt();

  for(int i = 0 ; i < blinkNumber ; i = i + 1)
  {
    digitalWrite(ledPin,HIGH);
    delay(blinkDelay);
    digitalWrite(ledPin,LOW);
    delay(blinkDelay);
  }
}
