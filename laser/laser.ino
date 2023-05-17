#include "RobotLaser.h"
RobotLaser *myLaser;

void setup() {
myLaser = new RobotLaser();
myLaser->initialize();
Serial.begin(9600);
}

void loop() {
	if (myLaser->beamBroken())
		Serial.println("get out of my light!");
	else
		Serial.println("that's better!");
}
