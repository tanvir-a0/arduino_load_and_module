int clockPin = 9;
int latchPin = 11;
int dataPin = 12;

byte mydata = 0x00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin,HIGH);
  shiftOut ( dataPin, clockPin, LSBFIRST, mydata);
  digitalWrite(latchPin,LOW);
  delay(100);
  

}
