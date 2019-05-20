#include "Arduino.h"
#include "RobotAccelerometer.h"

RobotAccelerometer *myAccelerometer;

void setup() {
  myAccelerometer = new RobotAccelerometer();
 Serial.begin(9600);
}
void loop() {
 Serial.print("X " );
 Serial.print(myAccelerometer->getAccelX());
 Serial.print(" Y " );
 Serial.print(myAccelerometer->getAccelY());
 Serial.print(" Z " );
 Serial.print(myAccelerometer->getAccelZ());
 Serial.println();
 delay(1000);
}
