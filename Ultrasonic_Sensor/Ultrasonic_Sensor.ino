int trigpin = 2;
int echopin = 3;
float duration;
float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration = pulseIn(echopin,HIGH);

  distance = duration * 0.0356234 / 2.;

  /*
  Serial.print("duration = "); //Serial.print();
  Serial.print(duration);
  Serial.print(" microseconds ");
  Serial.print("distance = "); //Serial.print();
  Serial.print(distance);
  Serial.println(" cm");*/
  Serial.print(distance);
  
}
