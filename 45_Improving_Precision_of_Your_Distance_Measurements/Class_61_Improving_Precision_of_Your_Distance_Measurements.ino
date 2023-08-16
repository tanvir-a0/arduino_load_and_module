#include <LiquidCrystal.h>
int rs = 4 ;
int en = 7 ;
int d4 = 8 ;
int d5 = 9 ;
int d6 = 10 ;
int d7 = 11 ;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int trig_pin = 3;
int echo_pin = 5;
int travel_time;
float distance;

int button_pin = 12;
int button_value;

int wait_time = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);

  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(button_pin,INPUT);
  digitalWrite(button_pin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  float avg_distance_s_by_travel_time_s = 0.017968;
  int if_tested = 0;
  
  Serial.println("Do you want to adjust the sensor?");
  Serial.println("Press 'yes' to go to adjust mode.");
  Serial.println("Press 'no' to go to regular mode.");
  while(Serial.available() == 0)
  {
  }
  String mode = Serial.readString();
  
  if(mode == "yes")
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Processing......");
    Serial.println("How many value do you wanna calculate?");
    while(Serial.available() == 0)
    {
    }
    int number_of_value = Serial.parseInt();
  
    int distance_s[number_of_value];
    int travel_time_s[number_of_value];
    float distance_s_by_travel_time_s[number_of_value];
  
    for(int i = 0 ; i < number_of_value ; i = i + 1)
    {
      Serial.print("Type distance[");
      Serial.print(i);
      Serial.println("] (in cm) and press enter");
      while(Serial.available() == 0)
      {
      }
      distance_s[i] = Serial.parseInt();
      
      digitalWrite(trig_pin,LOW);
      delayMicroseconds(10);
      digitalWrite(trig_pin,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig_pin,LOW);
      delayMicroseconds(10);

      travel_time_s[i] = pulseIn(echo_pin,HIGH);
      
      distance_s_by_travel_time_s[i] = (float)distance_s[i] / (float)travel_time_s[i];

      Serial.print("travel_time_s[");
      Serial.print(i);
      Serial.print("] = ");
      Serial.print(travel_time_s[i]);
      Serial.print("milisec");
      Serial.print(" distance_s[");
      Serial.print(i);
      Serial.print("] = ");
      Serial.print(distance_s[i]);
      Serial.print("cm");
      Serial.print(" distance_s_by_travel_time_s[");
      Serial.print(i);
      Serial.print("] = ");
      Serial.print(distance_s_by_travel_time_s[i],6);
      Serial.println("cm/milisec");
      Serial.println("");
    
    }

    float net_distance_s_by_travel_time_s = 0;

    for(int j = 0 ; j < number_of_value ; j = j + 1)
    {
      net_distance_s_by_travel_time_s = net_distance_s_by_travel_time_s + distance_s_by_travel_time_s[j];
    }

    Serial.println("");
    Serial.print("net_distance_s_by_travel_time_s = ");
    Serial.print(net_distance_s_by_travel_time_s,6);
    Serial.println("cm/milisec");

    avg_distance_s_by_travel_time_s = net_distance_s_by_travel_time_s / number_of_value;
    Serial.print("avg_distance_s_by_travel_time_s = ");
    Serial.print(avg_distance_s_by_travel_time_s,6);
    Serial.println("cm/milisec");
    if_tested = 1 ;
  }

  lcd.clear();
  
  while((if_tested == 1)||(mode != "yes") )
  {
    button_value = digitalRead(button_pin);
    while(button_value == 1)
    {
      
      lcd.setCursor(0,0);
      lcd.print("Place the target");
      lcd.setCursor(0,1);
      lcd.print("Press the button");
      Serial.println("");
      Serial.println("Place the target and press the button.");
      button_value = digitalRead(button_pin);
    }
    lcd.clear();
    while(button_value == 0)
    {
      digitalWrite(trig_pin,LOW);
      delayMicroseconds(10);
      digitalWrite(trig_pin,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig_pin,LOW);
      delayMicroseconds(10);

      travel_time = pulseIn(echo_pin,HIGH);
      distance = avg_distance_s_by_travel_time_s * travel_time;

      Serial.println("");
      Serial.print("travel_time = ");
      Serial.print(travel_time);
      Serial.print(" distance = ");
      Serial.print(distance);
      Serial.print(" button_value = ");
      Serial.print(button_value);
      Serial.println("");

      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Distance:");
      lcd.print(distance);
      lcd.print("cm");
      lcd.setCursor(0,1);
      lcd.print(distance*0.393700787); 
      lcd.print("inches");

      for(int i = wait_time ; i >= 0 ; i = i - 1)
      {
        delay(1000);
        lcd.print(i);
      }
    
      button_value = digitalRead(button_pin);
    }
  }
    lcd.clear();
  
  
  
}
