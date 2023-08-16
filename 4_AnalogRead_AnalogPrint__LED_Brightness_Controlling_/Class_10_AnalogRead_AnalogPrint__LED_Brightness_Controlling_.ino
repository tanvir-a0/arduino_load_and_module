int redPin = 5;
int inputPin = A0;
int inputValue ;
int brightness;
float v2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(inputPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  inputValue = analogRead(inputPin);
  v2 = (5./1023.)*inputValue;
  Serial.print("inputValue = ");
  Serial.print(inputValue);
  Serial.print(" v2 = ");
  Serial.print(v2);

  brightness = (255./1023.)*inputValue;
  Serial.print(" brightness = ");
  Serial.println(brightness);

  analogWrite(redPin,brightness);
}
