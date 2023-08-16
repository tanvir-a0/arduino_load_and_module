#include <LiquidCrystal.h>

int rs = 4  ;
int en = 7  ;
int d4 = 8  ;
int d5 = 9 ;
int d6 = 10 ;
int d7 = 11 ;

LiquidCrystal lcd ( rs, en , d4 , d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); // lcd.begin(column, row)

  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Watch me count:");
 for ( int i = 980 ;  ; i = i + 1 )
 {
  lcd.setCursor(0,1);
  lcd.print(i);
  delay(5);
 }
 lcd.clear();
 
 
}
