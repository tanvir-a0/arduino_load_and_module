int inputPin = A1;
int inputValue;
int buzzPin = 10;
int delayTime;
int buzzValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin,INPUT);
  pinMode(buzzPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:  
  inputValue = analogRead ( inputPin ) ;
  Serial.print("inputValue = ");
  Serial.print(inputValue);

  
  buzzValue = (inputValue/100);
  Serial.print(" buzzValue = ");
  Serial.print(buzzValue);

  
  delayTime = (9./470.)*(inputValue-150.)+1.;
  Serial.print(" delayTime = ");
  Serial.println(delayTime);

  analogWrite(buzzPin,60);
  delay(delayTime);
  analogWrite(buzzPin,55);
  delay(delayTime);
 

}
