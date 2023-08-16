#include "DHT.h"
#define Type DHT11
int sensePin = 2 ;
DHT HT(sensePin,Type);

float  humidity;
float tempc;
float tempf;
int setTime = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(setTime);

}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempc = HT.readTemperature();
  tempf = HT.readTemperature(true);
  
  Serial.print("humidity = ");Serial.print(humidity);
  Serial.print(" tempc = ");Serial.print(tempc);
  Serial.print(" tempf = ");Serial.println(tempf);

}
