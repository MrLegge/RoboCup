/*
  LineSensor.cpp class library to provide line sensing
  
  Author: Kyla Bradford y11  12/11/22
  Adapted: Phil Legge  6/8/23
  email: phil.legge@det.nsw.edu.au
*/

#include"LineSensor.h"
#include <arduino.h>

LineSensor::LineSensor(){
 _signalPin = 2;
 _lineFlag = false;
 pinMode(_signalPin, INPUT);
}
LineSensor::LineSensor(int signalPin){
  _signalPin = signalPin;
 _lineFlag = false;
 pinMode(signalPin, INPUT);
}

bool LineSensor::onLine(){
    if(digitalRead(_signalPin)){
      _lineFlag = false;
    }else {
      _lineFlag = true;
      }
    return _lineFlag;    
  }
