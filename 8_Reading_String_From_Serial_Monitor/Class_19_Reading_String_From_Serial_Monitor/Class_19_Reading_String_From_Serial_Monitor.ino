int redPin    = 5;
int yellowPin = 6;
int greenPin  = 9;
int bluePin   = 10;

String inputString;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redPin,OUTPUT);
pinMode(yellowPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println("What color do you want?");

int if_spelling_right=0;

while(Serial.available()==0)
{
  }
inputString = Serial.readString();

if((inputString == "Red")||(inputString == "RED")||(inputString == "red"))
{
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
  digitalWrite(yellowPin,LOW);
  if_spelling_right=if_spelling_right+1;
}
if((inputString == "green")||(inputString == "Green")||(inputString == "GREEN"))
{
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,HIGH);
  digitalWrite(bluePin,LOW);
  digitalWrite(yellowPin,LOW);
  if_spelling_right=if_spelling_right+1;
  
}
if((inputString == "BLUE")||(inputString == "Blue")||(inputString == "blue"))
{
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,HIGH);
  digitalWrite(yellowPin,LOW);
  if_spelling_right=if_spelling_right+1;
}
if((inputString == "Yellow")||(inputString == "yellow")||(inputString == "YELLOW"))
{
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
  digitalWrite(yellowPin,HIGH);
  if_spelling_right=if_spelling_right+1;
}
Serial.println();
if(if_spelling_right == 0)
{
  Serial.println("Make sure you choosed the right color and your spelling is right.");
  Serial.println("_________________________________________________________________");
}



}
