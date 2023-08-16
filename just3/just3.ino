int buttonpin = 9 ;
int buttonvalue ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonpin,INPUT);
  digitalWrite(buttonpin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
buttonvalue = digitalRead(buttonpin);
Serial.println(buttonvalue);
delay(100);
}
