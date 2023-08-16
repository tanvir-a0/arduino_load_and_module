//https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/
//we can also find the slave in this code.



//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  //Send message to receiver
  char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  Serial.println("Sent");
  delay(1000);
}
