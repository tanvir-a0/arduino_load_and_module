#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

#include <DHT.h>
#define Type DHT11
int sensorPin = 8;
DHT Sensor(sensorPin,Type);
float humidity;
float tempC;
float tempF;

byte degree_sign[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup() {
  Serial.begin(9600);
  
  lcd.begin(16,2);
  lcd.createChar(0,degree_sign);
  
  Sensor.begin();
    
}

void loop() {

  humidity = Sensor.readHumidity();
  tempC = Sensor.readTemperature();
  tempF = Sensor.readTemperature(true);

  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(humidity);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(tempC);
  lcd.write((byte)0);
  lcd.print("C");
  
  
//  Serial.print("humidity = ");Serial.print(humidity);
//  Serial.print(" tempC = ");Serial.print(tempC);
//  Serial.print(" tempF = ");Serial.println(tempF);
  
  delay(1000);
  
  lcd.clear();
  
  
    
}
