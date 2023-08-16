/*
 * This Code Doesn't Work
 * 
 * 
 * 
 */
int ledPin = 6;
int ledState = 0;

int buttonPin = 12;
int buttonRead ;
int buttonNew;
int buttonOld;

int delayTime = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonNew = digitalRead(buttonPin);
  Serial.println(buttonNew);

  if((buttonOld == 0) && (buttonNew == 1))
  {
    if(ledState == 0)
    {
      digitalWrite(ledPin,HIGH);
      ledState = 1;
    }
    if(ledState == 1)
    {
      digitalWrite(ledPin,LOW);
      ledState = 0;
    }
  }
  buttonOld = buttonNew;
  delay(delayTime);

}
