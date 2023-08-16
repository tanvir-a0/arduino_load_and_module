int latchPin = 11;
int clockPin = 9;
int dataPin = 12;


byte data = 0b00010111;

void setup(){
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,data);
  digitalWrite(latchPin,HIGH);
  
  Serial.println(data,BIN);
  
  delay(1000);
}
