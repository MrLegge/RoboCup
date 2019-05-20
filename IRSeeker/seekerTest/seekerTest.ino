#include "RobotIRSeeker.h"

void setup(){
  
  Serial.begin(9600);
  Serial.println("HiTechnic IRSeeker V2");
  Serial.println();
  Serial.println();
  Serial.println("Dir\tAngle\tStrength");
  Serial.println();
  InfraredSeeker::Initialize();
  
  }

void loop(){
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  Serial.print(InfraredBall.Direction);
  Serial.print("\t");
  Serial.print(InfraredSeeker::DirectionAngle(InfraredBall.Direction));
  Serial.print("\t");
  Serial.print(InfraredBall.Strength);
  Serial.println();
  delay(100); //optional
  }
