float y_sin;
float y_cos;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  for(float x = 0 ; x <= 360 ; x = x + 1)
  {
    y_sin = sin(x*(3.1416/180));//input of sin() and cos() has to be in radian;
    y_cos = cos(x*(3.1416/180));

    Serial.print(-1);
    Serial.print(",");
    Serial.print(0);
    Serial.print(",");
    Serial.print(1);
    Serial.print(",");
    Serial.print(y_sin);
    Serial.print(",");
    Serial.println(y_cos);
    delay(10);
  }

}
