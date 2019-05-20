#include "RobotLaser.h"
#include <Arduino.h>


RobotLaser::RobotLaser(void){
	sensorValue = 0;
	sensorPin = A0;
	ledPin = 13;
	pinMode(ledPin, OUTPUT);
	}
    
	void RobotLaser::Initialize(){    
		digitalWrite(ledPin, HIGH);
	}
	bool RobotLaser::beamBroken(){
		sensorValue = analogRead(sensorPin);
		if (sensorValue < 850){
			return true;
		}else{
			return false;
		}
	}
