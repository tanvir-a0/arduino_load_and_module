int en1 = 3;
int in1 = 4;
int in2 = 2;

int mspeed = 0;

int butt1pin = 7;
int butt1value;
int butt2pin = 8;
int butt2value;

int butt_delay ;
int push_start;

int clockwist_start_value = 10;
int anticlockwist_start_value = -10;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(en1,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);

pinMode(butt1pin,INPUT);
pinMode(butt2pin,INPUT);
digitalWrite(butt1pin,HIGH);
digitalWrite(butt2pin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
butt1value = digitalRead(butt1pin);
butt2value = digitalRead(butt2pin);

butt_delay = 5;

if(butt1value == 0)
{
  mspeed =mspeed + 1;
  delay(butt_delay);
}

if(butt2value == 0)
{
  mspeed =mspeed - 1;
  delay(butt_delay); 
}

if(mspeed > 170){
  mspeed = 170;
}

if(mspeed < -170){
  mspeed = -170;
}

if((-5 <= mspeed) && (mspeed <= 5))
{
  analogWrite(en1,0);
  push_start = 0;
}

if(5 < mspeed)
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  if(push_start == 0)
  {
    analogWrite(en1,255);
    delay(50);
    push_start = push_start + 1;
  }
  analogWrite(en1,mspeed+85);
}

if(-5 > mspeed)
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  if(push_start == 0)
  {
    analogWrite(en1,255);
    delay(50);
    push_start = push_start + 1;
  }
  analogWrite(en1,(-1)*(mspeed-85));
}




Serial.print("butt1value = ");    Serial.print(butt1value);
Serial.print(" butt2value = ");   Serial.print(butt2value);
Serial.print(" mspeed = ");       Serial.print(mspeed);
Serial.print(" push_start = ");   Serial.print(push_start);
Serial.print(" butt_delay = ");   Serial.println(butt_delay);


}
