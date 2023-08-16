int dataPin = 12; 
int clockPin = 9;
int latchPin = 11;

byte data = 0b10101111;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(data,BIN);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,data);
  digitalWrite(latchPin,HIGH);
  delay(1000);

  data = 0b11111111 - data;
  
  

}
