/*
  Ultrasonic.cpp class library to provide a distance reading
  
  Author: Phil Legge  22/3/24
  email: phil.legge@det.nsw.edu.au
*/

#include "UltraSonicSensor.h"
#include <arduino.h>

UltraSonicSensor::UltraSonicSensor(uint8_t trig,uint8_t echo){
	_trigPin = trig;
	_echoPin = echo;
	pinMode(_trigPin, OUTPUT);
  	pinMode(_echoPin, INPUT);
	
}

int UltraSonicSensor::getDistance(){
	digitalWrite(_trigPin, LOW); 
    	delayMicroseconds(2); 
    	digitalWrite(_trigPin, HIGH);
    	delayMicroseconds(10); 
    	digitalWrite(_trigPin, LOW);
    	_duration = pulseIn(_echoPin, HIGH);
   	 _distance = (_duration/2) / 29;
    if (_distance >= 300 ){ // return -1 if bigger than 3m
     	 return -1;
    }
    else if(_distance <= 0){ // returns 0 for error or zero results
      	return 0;
    }
    else {
      	return _distance; // returns a value if test is between 0m and 3m
    }
}
