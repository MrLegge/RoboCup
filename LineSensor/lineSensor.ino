/*
 LineSensor.ino - Demonstration of how to use the LineSensor
  
  Author: Phil Legge 12/11/18
  email: phil.legge@det.nsw.edu.au
*/

#include "LineSensor.h"

LineSensor *mySensor;

void setup() {
   mySensor = new LineSensor();
  //mySensor = new LineSensor(2);
  Serial.begin(9600);
}

void loop() {

  if(mySensor->onLine()){
    delay(10);
    Serial.println("On the line"); 
    delay(1000);
  }else{
    Serial.println("Not on a line"); 
    delay(1000);
  }
  
}
