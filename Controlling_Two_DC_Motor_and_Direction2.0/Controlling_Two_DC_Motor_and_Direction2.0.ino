//Joystick module;
int x_pin = A0;
int y_pin = A1;
int x_value;
int y_value;
int sw_pin = 4;
int sw_value;

//Motor pin
int en12 = 3 ;
int in1 = 2 ;
int en34 = 5 ;
int in3 = 7 ;

//Motor value
int xspeed;
int yspeed;
int x1speed;
int x2speed;
float speed_ratio = 0.5;
int kick_start;


void setup() {
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
      x1speed = 0;
      x2speed = 0;
      analogWrite(en12,x1speed);
      analogWrite(en34,x2speed);
    }
    if(90<xspeed)
    {
      digitalWrite(in1,HIGH);
      digitalWrite(in3,HIGH);
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
}
