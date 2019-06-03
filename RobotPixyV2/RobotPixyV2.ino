 #include"RobotPixyV2.h"
 #include <Arduino.h>
 
 RobotPixyV2 *pixy;

void setup() {
    pixy = new RobotPixyV2();
	Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
	pixy->lightsOn();
	Serial.print("this is the x value:  ");Serial.println(pixy->getX());
	delay(500);
	Serial.print("this is the y value:  ");Serial.println(pixy->getY());
	delay(500);
	Serial.print("this will display if in front:  ");Serial.println(pixy->isInFront());
	delay(500);
	Serial.print("this is the area value:  ");Serial.println(pixy->getArea());
	delay(500);
	pixy->lightsOff();
	delay(1000);
	
}


