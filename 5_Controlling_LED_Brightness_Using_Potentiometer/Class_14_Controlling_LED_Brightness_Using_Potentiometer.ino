int inputPin = A0;
int ledPin = 5;

int potValue;
int ledBrightness;
 

void setup() {
  // put your setup code here, to run once:
  pinMode ( ledPin , OUTPUT);
  pinMode ( inputPin , INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
potValue = analogRead(inputPin);
ledBrightness = (255./1023.)*potValue;

Serial.print("potValue = ");
Serial.print(potValue);
Serial.print(" ledBrightness = ");
Serial.println(ledBrightness);

analogWrite(ledPin,ledBrightness);
}
