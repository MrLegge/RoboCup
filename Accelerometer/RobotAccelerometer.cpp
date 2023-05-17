#include "RobotAccelerometer.h"
#include <Arduino.h>

	RobotAccelerometer::RobotAccelerometer(){
		accelerometerX = 0;
		accelerometerY = 0;
		accelerometerZ = 0;
	}
	
	int RobotAccelerometer::getAccelX(){
		accelerometerX = analogRead(ACCELX);
		return accelerometerX;
	}
	
	int RobotAccelerometer::getAccelY(){
		accelerometerY = analogRead(ACCELY);
		return accelerometerY;	
	}
	
	int RobotAccelerometer::getAccelZ(){
		accelerometerZ = analogRead(ACCELZ);
		return accelerometerZ;
	}
