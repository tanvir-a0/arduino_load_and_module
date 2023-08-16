int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte leds = 0b11111111;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(clockPin,OUTPUT);
 pinMode(dataPin,OUTPUT);
 pinMode(latchPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,leds);
digitalWrite(latchPin,HIGH);

leds = leds*0b10;

delay(dt);



}
