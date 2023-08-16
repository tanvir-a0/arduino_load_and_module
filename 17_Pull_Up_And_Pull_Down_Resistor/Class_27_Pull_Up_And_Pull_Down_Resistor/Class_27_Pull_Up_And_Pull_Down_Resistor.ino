int ledPin = 6;
int buttonPin = 12;
int  buttonRead;
int ledState = 0;
int buttonNew;
int buttonOld=0;
int delayTime = 100;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
}
void loop() {
 buttonNew= digitalRead(buttonPin);

 if ((buttonOld == 1) && (buttonNew == 0))
 {
  if(ledState == 0)
  {
    digitalWrite(ledPin,HIGH);
    ledState = ledState + 1;
  }
  if(ledState == 1)
  {
    digitalWrite(ledPin,LOW);
    ledState = ledState - 1;
  }
 }

 buttonOld = buttonNew;
 delayTime = 100;

 
 
 
  


 
}
