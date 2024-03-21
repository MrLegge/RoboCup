/*
  Ultrasonic.h class library to provide a distance reading
  
  Author: Phil Legge  22/3/24
  email: phil.legge@det.nsw.edu.au
*/

#ifndef ROBOTULTRASONICSENSOR_H
#define ROBOTULTRASONICSENSOR_H

#include <arduino.h>

class UltraSonicSensor{
	
	public:		
		UltraSonicSensor(uint8_t,uint8_t);	
		int getDistance();
		

	protected:
		uint8_t _trigPin;
		uint8_t _echoPin;
		long _duration;
		int _distance;
};
    
#endif
