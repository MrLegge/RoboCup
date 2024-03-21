/*
  Ultrasonic.ino Demonstration of how to use the UltraSonicSensor object to get a distance
  AND how to make a pause without delay()
  
  Author: Phil Legge  22/3/24
  email: phil.legge@det.nsw.edu.au
*/

#include "UltraSonicSensor.h"

UltraSonicSensor *myUltraSensor;

unsigned long previousMillis = 0UL;
unsigned long interval = 1000UL;

void setup() {
	myUltraSensor = new UltraSonicSensor(A0, A1);
	Serial.begin(9600);
}

void loop() {	
	unsigned long currentMillis = millis();
	if(currentMillis - previousMillis > interval){
		/* The Arduino executes this code once every second
		*  (interval = 1000 (ms) = 1 second).
		*/

		//update the previousMillis value
		previousMillis = currentMillis;
	  
		Serial.println(myUltraSensor->getDistance());
	}
}