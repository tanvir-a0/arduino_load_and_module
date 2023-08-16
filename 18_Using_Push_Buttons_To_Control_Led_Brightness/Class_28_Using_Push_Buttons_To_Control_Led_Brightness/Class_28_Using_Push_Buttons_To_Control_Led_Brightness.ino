int buttonPin1 = 11;
int buttonPin2 = 12;
int ledPin = 6;
int buzzPin = 10;

int button1Value;
int button2Value;

int brightness=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1Value = digitalRead(buttonPin1);
  Serial.print("button1Value = ");
  Serial.print(button1Value);
  button2Value = digitalRead(buttonPin2);
  Serial.print(" button2Value = ");
  Serial.print(button2Value);

  if(button1Value == 1)
  {
    brightness = brightness + 1;
    if(brightness>255){
    brightness = 255;
    digitalWrite(buzzPin,HIGH);
    delay(100);
    digitalWrite(buzzPin,LOW);
    }
    analogWrite(ledPin,brightness);
    delay(10);
  }
  if(button2Value == 1)
  {
    brightness = brightness - 1;
    if(brightness<0){
    brightness = 0;
    digitalWrite(buzzPin,HIGH);
    delay(100);
    digitalWrite(buzzPin,LOW);
    }
    analogWrite(ledPin,brightness);
    delay(10);
  }

  Serial.print(" brightness = ");
  Serial.println(brightness);
  

}
