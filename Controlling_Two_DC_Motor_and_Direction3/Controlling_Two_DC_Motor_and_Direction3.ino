//LCD module
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7


//Joystick module;
int x_pin = A0;
int y_pin = A1;
int x_value;
int y_value;
int sw_pin = 7;
int sw_value;

//Motor pin
int en12  ;
int in1  ;
int en34  ;
int in3  ;

//Motor value
int xspeed;
int yspeed;
int x1speed;
int x2speed;
float speed_ratio = 0.5;
int kick_start;
bool in1val;
bool in3val;

byte forward_sign[]={
  B00100,
  B01110,
  B11111,
  B00100,
  B01110,
  B11111,
  B00000,
  B00000
};

byte backward_sign[]={
  B00000,
  B00000,
  B11111,
  B01110,
  B00100,
  B11111,
  B01110,
  B00100
};

byte stop_sign[]={
  B00100,
  B01110,
  B11011,
  B10001,
  B11011,
  B01110,
  B00100,
  B00000
};

void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,forward_sign);
  lcd.createChar(1,backward_sign);
  lcd.createChar(2,stop_sign);
  
  Serial.begin(9600);

  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(sw_pin, INPUT);
  digitalWrite(sw_pin, HIGH);

  pinMode(en12, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(en34, OUTPUT);
  pinMode(in3, OUTPUT);



}

void loop() {
  

  x_value = analogRead(x_pin);
  y_value = analogRead(y_pin);
  sw_value = digitalRead(sw_pin);

  xspeed = (((float)x_value ) / (-1023.)) * 510 + 255;
  yspeed = (((float)y_value ) / (-1023.)) * 510 + 255;
  
  if(( -90 <= yspeed ) && ( yspeed <= 90))
  {
    if((-90<=xspeed)&&(xspeed<=90))
    {
      kick_start = 0;
      digitalWrite(in1,HIGH);
      digitalWrite(in3,HIGH);
      in1val = HIGH;
      in3val = HIGH;
      x1speed = 0;
      x2speed = 0;
      analogWrite(en12,x1speed);
      analogWrite(en34,x2speed);
    }
    if(90<xspeed)
    {
      digitalWrite(in1,HIGH);
      digitalWrite(in3,HIGH);
      in1val = HIGH;
      in3val = HIGH;
      if(kick_start == 0)
      {
        kick_start = kick_start + 1;
        Serial.println("Kickstarted.");
        analogWrite(en12,255);
        delay(50);
        analogWrite(en34,255);
        delay(50);
      }
      x1speed = xspeed;
      x2speed = xspeed;
      analogWrite(en12,x1speed);
      analogWrite(en34,x2speed);
    }
    if(xspeed<-90)
    {
      digitalWrite(in1,LOW);
      digitalWrite(in3,LOW);
      in1val = LOW;
      in3val = LOW;
      if(kick_start == 0)
      {
        kick_start = kick_start + 1;
        Serial.println("Kickstarted.");
        analogWrite(en12,255);
        delay(50);
        analogWrite(en34,255);
        delay(50);
      }
      x1speed = -xspeed;
      x2speed = -xspeed;
      analogWrite(en12,x1speed);
      analogWrite(en34,x2speed);
    }
  }
  if(yspeed<-90)
  {
    if((-90<=xspeed)&&(xspeed<=90))
    { 
      digitalWrite(in1,HIGH); 
      digitalWrite(in3,HIGH); 
      in1val = HIGH;
      in3val = HIGH;
      if(kick_start == 0)
      {
        kick_start = kick_start + 1;
        Serial.println("Kickstarted.");
        analogWrite(en12,255);
        delay(50);
        analogWrite(en34,255);
        delay(50);
      }
      x1speed = 0; 
      x2speed = -yspeed; 
      analogWrite(en12,x1speed); 
      analogWrite(en34,x2speed); 
    }
    if(90<xspeed)
    {
      digitalWrite(in1,HIGH); 
      digitalWrite(in3,HIGH); 
      in1val = HIGH;
      in3val = HIGH;
      if(kick_start == 0)
      {
        kick_start = kick_start + 1;
        Serial.println("Kickstarted.");
        analogWrite(en12,255);
        delay(50);
        analogWrite(en34,255);
        delay(50);
      }
      x1speed = xspeed - speed_ratio * ( - yspeed ) ; 
      if(x1speed<0){x1speed=0;}if(x2speed<0){x2speed=0;}
      x2speed = xspeed; 
      analogWrite(en12,x1speed); 
      analogWrite(en34,x2speed); 
    }
    if(xspeed<-90)
    {
      digitalWrite(in1,LOW); 
      digitalWrite(in3,LOW); 
      in1val = LOW;
      in3val = LOW;
      if(kick_start == 0)
      {
        kick_start = kick_start + 1;
        Serial.println("Kickstarted.");
        analogWrite(en12,255);
        delay(50);
        analogWrite(en34,255);
        delay(50);
      }
      x1speed = -xspeed - speed_ratio * ( - yspeed); 
      if(x1speed<0){x1speed=0;}if(x2speed<0){x2speed=0;}
      x2speed = -xspeed; 
      analogWrite(en12,x1speed); 
      analogWrite(en34,x2speed); 
    }
  }
  if(90<yspeed)
  {
    if((-90<=xspeed)&&(xspeed<=90))
    {
      digitalWrite(in1,HIGH); 
      digitalWrite(in3,HIGH); 
      in1val = HIGH;
      in3val = HIGH;
      if(kick_start == 0)
      {
        kick_start = kick_start + 1;
        Serial.println("Kickstarted.");
        analogWrite(en12,255);
        delay(50);
        analogWrite(en34,255);
        delay(50);
      }
      x1speed = yspeed; 
      x2speed = 0; 
      analogWrite(en12,x1speed); 
      analogWrite(en34,x2speed); 
    }
    if(90<xspeed)
    {
      digitalWrite(in1,HIGH); 
      digitalWrite(in3,HIGH); 
      in1val = HIGH;
      in3val = HIGH;
      if(kick_start == 0)
      {
        kick_start = kick_start + 1;
        Serial.println("Kickstarted.");
        analogWrite(en12,255);
        delay(50);
        analogWrite(en34,255);
        delay(50);
      }
      x1speed = xspeed; 
      x2speed = xspeed - speed_ratio * yspeed; 
      if(x1speed<0){x1speed=0;}if(x2speed<0){x2speed=0;}
      analogWrite(en12,x1speed); 
      analogWrite(en34,x2speed); 
    }
    if(xspeed<-90)
    {
      digitalWrite(in1,LOW); 
      digitalWrite(in3,LOW); 
      in1val = LOW;
      in3val = LOW;
      
      if(kick_start == 0)
      {
        kick_start = kick_start + 1;
        Serial.println("Kickstarted.");
        analogWrite(en12,255);
        delay(50);
        analogWrite(en34,255);
        delay(50);
      }
      x1speed = -xspeed; 
      x2speed = -xspeed - speed_ratio * yspeed; 
      if(x1speed<0){x1speed=0;}if(x2speed<0){x2speed=0;}
      analogWrite(en12,x1speed); 
      analogWrite(en34,x2speed); 
    }
  }

  
  
  //Serial.print(" ");Serial.print();
  Serial.print(" xspeed: ");Serial.print(xspeed);
  Serial.print(" yspeed: ");Serial.print(yspeed);
  Serial.print(" x1speed: ");Serial.print(x1speed);
  Serial.print(" x2speed: ");Serial.print(x2speed);
  Serial.print(" kick_start: ");Serial.print(kick_start);
  Serial.print(" sw_value: ");Serial.print(sw_value);
  Serial.println("");

  lcd.setCursor(0,0);
  lcd.print("x1speed:");
  lcd.print(x1speed);
  lcd.setCursor(11,0);
  
  if(x1speed == 0)
  {
    lcd.write((byte)2);
  }
  else{
  if(in1val == HIGH)
  {
    lcd.write((byte)0);
  }
  if(in1val == LOW)
  {
    lcd.write((byte)1);
  }
  }
  
  lcd.setCursor(0,1);
  lcd.print("x2speed:");
  lcd.print(x2speed);
  lcd.setCursor(11,1);
  if(x2speed == 0)
  {
    lcd.write((byte)2);
  }
  else{
  if(in3val == HIGH)
  {
    lcd.write((byte)0);
  }
  if(in3val == LOW)
  {
    lcd.write((byte)1);
  }
  }
  delay(100);
  lcd.clear();
  
  
}
