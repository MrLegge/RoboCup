#include "RobotLaser.h"



RobotLaser::RobotLaser(void){
	sensorValue = 0; // sets initial value to zero so as to not pollute 
	sensorPin = A0; //this is the analogue pin value change to suit chosen pin
	ledPin = 13;  // this is the digital pin and power supply for the laser 
	pinMode(ledPin, OUTPUT);
	pinMode(sensorPin, INPUT);
	}
    
	//turn on the laser
	void RobotLaser::Initialize(){    
		digitalWrite(ledPin, HIGH);
	}
	
	// return true if beam is broken false if it's on the sensor
	bool RobotLaser::beamBroken(){ 
		sensorValue = analogRead(sensorPin);
		if (sensorValue < 850){
			return true;
		}else{
			return false;
		}
	}
