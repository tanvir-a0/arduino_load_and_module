int buzzPin = 12;
int dt1 = 1;//dt = delayTime
int dt2 = 2;
int j;


void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for ( j = 0 ; j < 100 ; j = j + 1 )
{
  digitalWrite(buzzPin,HIGH);
  delay(dt1);
  digitalWrite(buzzPin,LOW);
  delay(dt1);
}
for ( j = 0 ; j < 100 ; j = j + 1 )
{
  digitalWrite(buzzPin,HIGH);
  delay(dt2);
  digitalWrite(buzzPin,LOW);
  delay(dt2);
}

}
