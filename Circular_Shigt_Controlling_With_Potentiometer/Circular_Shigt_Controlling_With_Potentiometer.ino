int latchPin = 8;
int clockPin = 6;
int dataPin = 13;
int dt ; 
int potPin = A0;


byte data = 0b11101111;

void setup(){
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,data);
  digitalWrite(latchPin,HIGH);
  
  Serial.print(data,BIN);
  Serial.print("   ");
  Serial.println(dt,DEC);
  dt = analogRead(potPin);

  data = data * 0b10 + data / 0b10000000 ;
  delay(dt);
}
