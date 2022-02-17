#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)    //Checks is there any data in buffer 
  {
    Serial.read();  //Read serial data byte and send back to serial monitor
  }


}