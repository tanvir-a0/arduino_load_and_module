
int button1pin = 9;
int button1value ;
int button2pin = 10;
int button2value;
int output1pin = 5;
int output2pin = 6;

int inputledpin1 = 11;
int inputledpin2 = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button1pin,INPUT);
  digitalWrite(button1pin,HIGH);
  pinMode(button2pin,INPUT);
  digitalWrite(button2pin,HIGH);

  pinMode(inputledpin1,OUTPUT);
  pinMode(inputledpin2,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(button1pin) == 0)
  {button1value = 1;}
  if(digitalRead(button1pin) == 1)
  {button1value = 0;}
  if(digitalRead(button2pin) == 0)
  {button2value = 1;}
  if(digitalRead(button2pin) == 1)
  {button2value = 0;}

  digitalWrite(inputledpin1,button1value);
  digitalWrite(output1pin,button1value);
  digitalWrite(inputledpin2,button2value);
  digitalWrite(output2pin,button2value);
  

  Serial.print("button1value = ");
  Serial.print(button1value);
  Serial.print(" button2value = ");
  Serial.println(button2value);

  delay(100);

}
