int x_endvalue = 10;
int x_startvalue = -10;
float y;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int x = x_startvalue ; x <= x_endvalue ; x = x + 1)
  {
    //y = x * x ; // parabola
    //y = x + 10 ; //straight line

    y = sqrt(100 - pow(x,2));//circle
    float neg_y = (-1)*sqrt(100 - pow(x,2));
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.println(neg_y);
    Serial.print(",");
    delay(10);
    
  }

}
