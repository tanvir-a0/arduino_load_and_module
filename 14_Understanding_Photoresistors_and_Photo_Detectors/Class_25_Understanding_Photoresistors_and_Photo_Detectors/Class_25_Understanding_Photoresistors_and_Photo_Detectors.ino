int inputPin = A1;
int inputValue ;
int redPin = 5;
int greenPin = 6;

float v2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(inputPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  inputValue = analogRead(inputPin);
  
  Serial.print("inputValue = ");
  Serial.print(inputValue);
  Serial.println("  ");

  if(inputValue < 200)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
  else
  {
     digitalWrite(greenPin,HIGH);
     digitalWrite(redPin,LOW);
  }
  

 
}
