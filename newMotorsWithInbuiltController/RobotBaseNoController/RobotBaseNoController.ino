
#include "RobotBaseNoController.h"
#define trigPin A0
#define echoPin A1

RobotBaseNoController *myBase;
 
void setup() {
  // put your setup code here, to run once:
  myBase = new RobotBaseNoController();
  }

void loop() {
  // put your main code here, to run repeatedly:
    myBase->driveForward(0,0);
    delay(2000);
    myBase->driveBackward(0,0);
    delay(2000);
    myBase->rotateLeft(0);
    delay(2000);
    myBase->rotateRight(0);
    delay(2000);
}



