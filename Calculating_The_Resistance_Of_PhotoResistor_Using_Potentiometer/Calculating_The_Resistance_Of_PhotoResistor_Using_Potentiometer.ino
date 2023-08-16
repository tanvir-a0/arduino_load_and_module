int redPin = 5;
int inputPin = A0;
int potValue ;
float R2_; 
float Rph;
float R2 = 4516.12;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(inputPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  
  potValue = analogRead(inputPin);

  R2_ = (10000./1023.)*potValue;
  Rph = 1/(1/R2_-1/R2);

  Serial.print("potValue = ");
  Serial.print(potValue);
  Serial.print(" R2 = 4516.12");
  Serial.print(" R2' = ");
  Serial.print(R2_);
  Serial.print(" Rph = ");
  Serial.println(Rph);

 
}
