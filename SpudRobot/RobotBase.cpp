/*************************************************************
* this is the robot base control class which is designed for a 
* four wheel robot construction using an Adafruit_DCMotor controller
* and and arduino Uno 
**************************************************************/
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "RobotBase.h"

	RobotBase::RobotBase(void) { 
		AFMS = Adafruit_MotorShield();
		AFMS.begin();
		myMotorM1 = AFMS.getMotor(1);     
		myMotorM2 = AFMS.getMotor(2);
		myMotorM3 = AFMS.getMotor(3);      
		myMotorM4 = AFMS.getMotor(4);	
	} 
	void  RobotBase::stopRobotAfter(int time){
  		delay(time);
  		myMotorM1->run(RELEASE); 
  		myMotorM2->run(RELEASE); 
  		myMotorM3->run(RELEASE); 
  		myMotorM4->run(RELEASE);   
	}
	void RobotBase::moveRobotForward(int inSpeed){   
		myMotorM1->setSpeed(inSpeed); 
		myMotorM1->run(BACKWARD);
		myMotorM2->setSpeed(inSpeed); 
		myMotorM2->run(FORWARD);
		myMotorM3->setSpeed(inSpeed); 
		myMotorM3->run(FORWARD);
		myMotorM4->setSpeed(inSpeed); 
		myMotorM4->run(BACKWARD);
	}
	void RobotBase::moveRobotBackward(int inSpeed){
		myMotorM1->setSpeed(inSpeed); 
		myMotorM1->run(FORWARD);
		myMotorM2->setSpeed(inSpeed); 
		myMotorM2->run(BACKWARD);
		myMotorM3->setSpeed(inSpeed); 
		myMotorM3->run(BACKWARD);
		myMotorM4->setSpeed(inSpeed); 
		myMotorM4->run(FORWARD);
	}
	 void RobotBase::moveRobotRight(int inSpeed){
		myMotorM1->setSpeed(inSpeed); 
		myMotorM1->run(FORWARD);
		myMotorM2->setSpeed(inSpeed); 
		myMotorM2->run(FORWARD);
		myMotorM3->setSpeed(inSpeed); 
		myMotorM3->run(BACKWARD);
		myMotorM4->setSpeed(inSpeed); 
		myMotorM4->run(BACKWARD);
	}
	void RobotBase::moveRobotLeft(int inSpeed){
		myMotorM1->setSpeed(inSpeed); 
		myMotorM1->run(BACKWARD);
		myMotorM2->setSpeed(inSpeed); 
		myMotorM2->run(BACKWARD);
		myMotorM3->setSpeed(inSpeed); 
		myMotorM3->run(FORWARD);
		myMotorM4->setSpeed(inSpeed); 
		myMotorM4->run(FORWARD);
	}
	void RobotBase::rotateRobotRight(int inSpeed){
		myMotorM1->setSpeed(inSpeed); 
		myMotorM1->run(FORWARD);
		myMotorM2->setSpeed(inSpeed); 
		myMotorM2->run(FORWARD);
		myMotorM3->setSpeed(inSpeed); 
		myMotorM3->run(FORWARD);
		myMotorM4->setSpeed(inSpeed); 
		myMotorM4->run(FORWARD);
	}
	void RobotBase::rotateRobotLeft(int inSpeed){
		myMotorM1->setSpeed(inSpeed); 
		myMotorM1->run(BACKWARD);
		myMotorM2->setSpeed(inSpeed); 
		myMotorM2->run(BACKWARD);
		myMotorM3->setSpeed(inSpeed); 
		myMotorM3->run(BACKWARD);
		myMotorM4->setSpeed(inSpeed); 
		myMotorM4->run(BACKWARD);
	}
 


