int analoginputpin = A0;
int analoginputvalue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(analoginputpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analoginputvalue = analogRead(analoginputpin);
  Serial.print("analoginputvalue = ");
  Serial.println(analoginputvalue * 100);

}
