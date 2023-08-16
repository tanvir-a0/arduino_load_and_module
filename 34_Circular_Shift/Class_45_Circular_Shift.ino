int latchPin = 11;
int clockPin = 9;
int dataPin = 12;


byte data = 0b11101111;

void setup(){
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,data);
  digitalWrite(latchPin,HIGH);
  
  Serial.println(data,BIN);

  data = data * 0b10 + data / 0b10000000 ;
  delay(10);
}
