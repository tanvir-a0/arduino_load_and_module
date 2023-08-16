int xpin = A1;
int ypin = A2;
int swpin = 2;

int xval;
int yval;
int swval;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(swpin,INPUT);
  digitalWrite(swpin,HIGH);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  
  xval = analogRead (xpin);
  Serial.print("xval = ");
  Serial.print(xval);
  yval = analogRead (ypin);
  Serial.print(" yval = ");
  Serial.print(yval);
  swval = digitalRead(swpin);
  Serial.print(" swval = ");
  Serial.println(swval);

}
