/*
  LineSensor.cpp class library to provide line sensing
  
  Author: Kyla Bradford y11  12/11/22
  Adapted: Phil Legge  6/8/23
  email: phil.legge@det.nsw.edu.au
*/

#include"LineSensor.h"
#include <arduino.h>

LineSensor::LineSensor(){
 signalPin = 2;
 lineFlag = false;
 pinMode(signalPin, INPUT);
}
LineSensor::LineSensor(int signalPin){
 lineFlag = false;
 pinMode(signalPin, INPUT);
}

bool LineSensor::onLine(){
    if(digitalRead(signalPin)){
      lineFlag = false;
    }else {
      lineFlag = true;
      }
    return lineFlag;    
  }
