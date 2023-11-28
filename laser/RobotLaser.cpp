#include "RobotLaser.h"
#include <Arduino.h>


RobotLaser::RobotLaser(void){
	_sensorValue = 0;
	_sensorPin = A0;
	_ledPin = 13;
	pinMode(_ledPin, OUTPUT);
	}
    
	void RobotLaser::initialize(){    
		digitalWrite(_ledPin, HIGH);
	}
	bool RobotLaser::beamBroken(){
		_sensorValue = analogRead(_sensorPin);
		if (_sensorValue < 850){
			return true;
		}else{
			return false;
		}
	}
