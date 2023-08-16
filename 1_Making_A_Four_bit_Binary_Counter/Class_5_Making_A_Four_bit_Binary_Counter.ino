int bit0 = 10;
int bit1 = 9;
int bit2 = 6;
int bit3 = 5;
int delayTime = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(bit0,OUTPUT);
  pinMode(bit1,OUTPUT);
  pinMode(bit2,OUTPUT);
  pinMode(bit3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(bit0,LOW);
  digitalWrite(bit1,LOW);
  digitalWrite(bit2,LOW);
  digitalWrite(bit3,LOW);
  delay(delayTime);
  digitalWrite(bit0,LOW);
  digitalWrite(bit1,LOW);
  digitalWrite(bit2,LOW);
  digitalWrite(bit3,HIGH);
  delay(delayTime);
  digitalWrite(bit0,LOW);
  digitalWrite(bit1,LOW);
  digitalWrite(bit2,HIGH);
  digitalWrite(bit3,LOW);
  delay(delayTime);
  digitalWrite(bit0,LOW);
  digitalWrite(bit1,LOW);
  digitalWrite(bit2,HIGH);
  digitalWrite(bit3,HIGH);
  delay(delayTime);
  digitalWrite(bit0,LOW);
  digitalWrite(bit1,HIGH);
  digitalWrite(bit2,LOW);
  digitalWrite(bit3,LOW);
  delay(delayTime);
  digitalWrite(bit0,LOW);
  digitalWrite(bit1,HIGH);
  digitalWrite(bit2,LOW);
  digitalWrite(bit3,HIGH);
  delay(delayTime);
  digitalWrite(bit0,LOW);
  digitalWrite(bit1,HIGH);
  digitalWrite(bit2,HIGH);
  digitalWrite(bit3,LOW);
  delay(delayTime);
  digitalWrite(bit0,LOW);
  digitalWrite(bit1,HIGH);
  digitalWrite(bit2,HIGH);
  digitalWrite(bit3,HIGH);
  delay(delayTime);
  
  digitalWrite(bit0,HIGH);
  digitalWrite(bit1,LOW);
  digitalWrite(bit2,LOW);
  digitalWrite(bit3,LOW);
  delay(delayTime);
  digitalWrite(bit0,HIGH);
  digitalWrite(bit1,LOW);
  digitalWrite(bit2,LOW);
  digitalWrite(bit3,HIGH);
  delay(delayTime);
  digitalWrite(bit0,HIGH);
  digitalWrite(bit1,LOW);
  digitalWrite(bit2,HIGH);
  digitalWrite(bit3,LOW);
  delay(delayTime);
  digitalWrite(bit0,HIGH);
  digitalWrite(bit1,LOW);
  digitalWrite(bit2,HIGH);
  digitalWrite(bit3,HIGH);
  delay(delayTime);
  digitalWrite(bit0,HIGH);
  digitalWrite(bit1,HIGH);
  digitalWrite(bit2,LOW);
  digitalWrite(bit3,LOW);
  delay(delayTime);
  digitalWrite(bit0,HIGH);
  digitalWrite(bit1,HIGH);
  digitalWrite(bit2,LOW);
  digitalWrite(bit3,HIGH);
  delay(delayTime);
  digitalWrite(bit0,HIGH);
  digitalWrite(bit1,HIGH);
  digitalWrite(bit2,HIGH);
  digitalWrite(bit3,LOW);
  delay(delayTime);
  digitalWrite(bit0,HIGH);
  digitalWrite(bit1,HIGH);
  digitalWrite(bit2,HIGH);
  digitalWrite(bit3,HIGH);
  delay(delayTime);

  
} 
