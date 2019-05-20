#include "RobotDribbler.h"

RobotDribbler *dribbler;

void setup(){
	dribbler = new RobotDribbler();
}

void loop(){
	dribbler->dribble();
  delay(3000);
  dribbler->kick();
  delay(500);
  dribbler->waitForBall();
  delay(2000);
}
