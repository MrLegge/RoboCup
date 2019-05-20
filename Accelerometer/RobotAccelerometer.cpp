#include "RobotAccelerometer.h"
#include <Arduino.h>

	RobotAccelerometer::RobotAccelerometer(){
		AccelerometerX = 0;
		AccelerometerY = 0;
		AccelerometerZ = 0;
	}
	
	int RobotAccelerometer::getAccelX(){
		AccelerometerX = analogRead(ACCELX);
		return AccelerometerX;
	}
	
	int RobotAccelerometer::getAccelY(){
		AccelerometerY = analogRead(ACCELY);
		return AccelerometerY;	
	}
	
	int RobotAccelerometer::getAccelZ(){
		AccelerometerZ = analogRead(ACCELZ);
		return AccelerometerZ;
	}