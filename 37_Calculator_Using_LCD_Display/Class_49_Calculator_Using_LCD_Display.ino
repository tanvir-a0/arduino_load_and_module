#include <LiquidCrystal.h>
int rs = 7  ;
int en = 8  ;
int d4 = 9  ;
int d5 = 10 ;
int d6 = 11 ;
int d7 = 12 ;

float number1;
float number2;
String action;
float result;

LiquidCrystal lcd ( rs, en , d4 , d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("What is the ");
  lcd.setCursor(0,1);
  lcd.print("first number?");
  while(Serial.available() == 0){
  }
  number1 = Serial.parseFloat();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("What is the");
  lcd.setCursor(0,1);
  lcd.print("second number?");
  while(Serial.available() == 0){
  }
  number2 = Serial.parseFloat();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("+,-,*,/|What do ");
  lcd.setCursor(0,1);
  lcd.print("you want to do?");
  while(Serial.available() == 0){
  }
  action = Serial.readString();

  int if_action_right = 0;
  if(action == "+"){
    result = number1 + number2;
    if_action_right = if_action_right + 1;
  }
  if(action == "-"){
    result = number1 - number2;
    if_action_right = if_action_right + 1;
  }
  if(action == "*"){
    result = number1 * number2;
    if_action_right = if_action_right + 1;
  }
  if(action == "/"){
    result = number1 / number2;
    if_action_right = if_action_right + 1;
  }
  if( if_action_right == 0)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter correct");
    lcd.setCursor(0,1);
    lcd.print("action.");
    if_action_right = 0;
    lcd.print(" ");
    for(int i = 5 ; i >= 0 ; i = i - 1 )
    {
      
      lcd.print(i);
      delay(1000);
    }
    }

  if(if_action_right != 0)
  {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(number1);
  lcd.print(action);
  lcd.print(number2);
  lcd.print("=");
  lcd.print(result);
  lcd.setCursor(0,1);
  for(int i = 5 ; i >= 0 ; i = i - 1 ){
    lcd.print(i);
    delay(1000);
  }
  }

  Serial.print("number2 = ");Serial.print(number2);
  Serial.print(" number2 = ");Serial.print(number2);
  Serial.print(" result = ");Serial.println(result);
  

}
