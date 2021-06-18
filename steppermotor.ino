#include <Stepper.h>
#include <SoftwareSerial.h> 

SoftwareSerial mySerial(2,3);
const int stepsPerRevolution = 64; 
Stepper myStepper(stepsPerRevolution, 11,9,10,8); 
int message;
void setup() {
   Serial.begin(9600); 
 mySerial.begin(9600);
  myStepper.setSpeed(300);
}
void loop() {

 myStepper.step(-2048);
  
}
