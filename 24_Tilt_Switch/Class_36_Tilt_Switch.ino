int tiltswpin = 6;
int tiltswvalue ;

int redPin = 5;
int greenPin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(tiltswpin,INPUT);
  digitalWrite(tiltswpin,HIGH);
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltswvalue = digitalRead(tiltswpin);

  Serial.print("tiltswvalue = ");
  Serial.print(tiltswvalue);

  if(tiltswvalue == 1)
  {
    Serial.println(" Tilted ");
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
  }
  if(tiltswvalue == 0)
  {
    Serial.println(" Straight ");
    digitalWrite(greenPin,LOW);
    digitalWrite(redPin,HIGH);
  }
}
