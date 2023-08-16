int potpin = A0;
int potvalue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(potpin));

}
