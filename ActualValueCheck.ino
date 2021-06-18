#include <TimeLib.h>

#include <dht.h>

dht DHT;

#define DHT11_PIN A1

void setup(){
 
  Serial.begin(9600);
}

void loop(){

  unsigned int AnalogValue;
  AnalogValue = analogRead(A0);
  Serial.println(AnalogValue);
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  
  
  delay(5000);
}
