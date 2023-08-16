int inputpin = A0;
int inputvalue;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  inputvalue = analogRead(inputpin);
  Serial.print("modulevalue = ");
  Serial.println(inputvalue);
  delay(100);
}
