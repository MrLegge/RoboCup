#include "RobotAccelerometer.h"
#include <Arduino.h>

	RobotAccelerometer::RobotAccelerometer(){
		_accelerometerX = 0;
		_accelerometerY = 0;
		_accelerometerZ = 0;
	}
	
	int RobotAccelerometer::getAccelX(){
		_accelerometerX = analogRead(ACCELX);
		return _accelerometerX;
	}
	
	int RobotAccelerometer::getAccelY(){
		_accelerometerY = analogRead(ACCELY);
		return _accelerometerY;	
	}
	
	int RobotAccelerometer::getAccelZ(){
		_accelerometerZ = analogRead(ACCELZ);
		return _accelerometerZ;
	}
