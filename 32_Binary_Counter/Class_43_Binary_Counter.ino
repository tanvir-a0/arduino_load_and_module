int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte leds1 = 0b10101010;
int dt = 1000;

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
shiftOut(dataPin,clockPin,LSBFIRST,leds1);
digitalWrite(latchPin,HIGH);
delay(dt);
leds1 = leds1 * 0b10;
Serial.println(leds1,BIN);
}
