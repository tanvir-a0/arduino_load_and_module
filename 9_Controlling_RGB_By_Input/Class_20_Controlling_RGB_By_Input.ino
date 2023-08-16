int redPin   = 9 ;
int greenPin = 6 ;
int bluePin  = 5 ;

int redValue    ;
int greenValue  ;
int blueValue   ;

int delayTime = 10;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
digitalWrite(redPin,OUTPUT);
digitalWrite(greenPin,OUTPUT);
digitalWrite(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println("=>What is the value of Red(is a scale of 0 to 255)?");
  while(Serial.available() == 0)
  {
    }
  redValue = Serial.parseInt();

  Serial.println("=>What is the value of Green(is a scale of 0 to 255)?");
    while(Serial.available() == 0)
  {
    }
  greenValue = Serial.parseInt();
  
  Serial.println("=>What is the value of Blue(is a scale of 0 to 255)?");
  while(Serial.available() == 0)
  {
    }
  blueValue = Serial.parseInt();

  for(int i = 0 ; i < redValue ; i = i + 1 )
  {
    analogWrite(redPin,i);
    delay(delayTime);
  }
  for(int j = 0 ; j < greenValue ; j = j + 1 )
  {
    analogWrite(greenPin,j);
    delay(delayTime);
  }
  for(int k = 0 ; k < blueValue ; k = k + 1 )
  {
    analogWrite(bluePin,k);
    delay(delayTime);
  }

  Serial.println();
  Serial.println("Press 'a' then Enter to input again.");
  while(Serial.available()==0)
  {
    }
  String ifAgain = Serial.readString();
  if(ifAgain = "a"){
    analogWrite(redPin,0);
    analogWrite(bluePin,0);
    analogWrite(greenPin,0);
  }
  Serial.println("________________________________________________________");
  
  





  
}
