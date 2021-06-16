
#include <SoftwareSerial.h>    
#include <Stepper.h>
#include <dht.h>

SoftwareSerial BT(2,3);
const int stepsPerRevolution = 64; 
Stepper myStepper(stepsPerRevolution, 11,9,10,8); 
dht DHT;
#define DHT11_PIN A1
unsigned long previousMillis = 0;

char a = BT.read();



void setup() 
{
Serial.begin(9600);        
myStepper.setSpeed(300);
BT.begin(9600);
}
void loop(){


}

void automode(){
  
 
  
   int chk = DHT.read11(DHT11_PIN);
   int temperature = DHT.temperature;
    int AnalogValue;
    AnalogValue = analogRead(A0);
   
   
    if(temperature>25&&AnalogValue>600){
      myStepper.step(-2048);
      
      
    }else if(temperature>25&&AnalogValue<600){
     myStepper.step(2048); 
     
    }else if (temperature<25&&AnalogValue>600){
    myStepper.step(2048);
   
    }else if (temperature<25&&AnalogValue<600){
  myStepper.step(-2048);
    
    }
    return;}

void voicemode(){
  unsigned long currentMillis = millis();
  if(BT.available()){
char a = BT.read();


  if (a=='1'){
 
     previousMillis = currentMillis;
    automode();
    
  }
  if (a=='2'){
       previousMillis = currentMillis;
  
    myStepper.step(2048);
   
    
    
    
  }  
  if (a=='3'){
   previousMillis = currentMillis;
  
    myStepper.step(-2048);
    
     
  } 

 
  }

     if (currentMillis - previousMillis >=20000){
    previousMillis = currentMillis;
    
    automode();
    return;
 }
}
  
   

    
      
  
      

 
