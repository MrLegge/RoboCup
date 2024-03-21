/*******************************************************************
*	This is the workings of the base of your robot, you should not  
*	need to adapt any of this code unless you want to change the  
*	pins for the motor controller.
*
*	You should use this file to check your pin location against the  
*	pin values.
*	
*	Author: Phil Legge
*	Date: 7/8/18
*********************************************************************/

#include "TwoControllerBase.h"

TwoControllerBase::TwoControllerBase(){
	// signal pins need to be pwm pins on the UNO board (~ near the number)
	rightFrontSignal = 13; //ENA F
	rightRearSignal = 11;  //ENA R
	leftFrontSignal = 12; //ENB F
	leftRearSignal = 10;  //ENB R
	// these pins don't need to be pwm
	rightFrontIn1 = 31;
	rightFrontIn2 = 33;
	leftFrontIn1 = 35;
	leftFrontIn2 = 37;
	rightRearIn1 = 22;
	rightRearIn2 = 24;
	leftRearIn1 = 26;
	leftRearIn2 = 28;
	_motorFrontRight = new L298N(rightFrontSignal,rightFrontIn1,rightFrontIn2);
	_motorFrontLeft = new L298N(leftFrontSignal,leftFrontIn1,leftFrontIn2);
	_motorRearRight = new L298N(rightRearSignal,rightRearIn1,rightRearIn2);
	_motorRearLeft = new L298N(leftRearSignal,leftRearIn1,leftRearIn2);
}

void TwoControllerBase::driveForward(unsigned short leftSpeed, unsigned short rightSpeed){
	_motorFrontRight->setSpeed(rightSpeed);
	_motorFrontLeft->setSpeed(leftSpeed);
	_motorRearRight->setSpeed(rightSpeed);
	_motorRearLeft->setSpeed(leftSpeed);
	_motorFrontRight->backward();
	_motorFrontLeft->forward();
	_motorRearRight->backward();
	_motorRearLeft->forward();
}

void TwoControllerBase::driveBackward(unsigned short leftSpeed, unsigned short rightSpeed){
	_motorFrontRight->setSpeed(rightSpeed);
	_motorFrontLeft->setSpeed(leftSpeed);
	_motorRearRight->setSpeed(rightSpeed);
	_motorRearLeft->setSpeed(leftSpeed);
	_motorFrontRight->forward();
	_motorFrontLeft->backward();
	_motorRearRight->forward();
	_motorRearLeft->backward();
}

void TwoControllerBase::driveRight(unsigned short frontSpeed, unsigned short backSpeed){
	_motorFrontRight->setSpeed(frontSpeed);
	_motorFrontLeft->setSpeed(frontSpeed);
	_motorRearRight->setSpeed(backSpeed);
	_motorRearLeft->setSpeed(backSpeed);
	_motorFrontRight->backward();
	_motorFrontLeft->forward();
	_motorRearRight->forward();
	_motorRearLeft->backward();
}

void TwoControllerBase::driveLeft(unsigned short frontSpeed, unsigned short backSpeed){
	_motorFrontRight->setSpeed(frontSpeed);
	_motorFrontLeft->setSpeed(frontSpeed);
	_motorRearRight->setSpeed(backSpeed);
	_motorRearLeft->setSpeed(backSpeed);
	_motorFrontRight->forward();
	_motorFrontLeft->backward();
	_motorRearRight->backward();
	_motorRearLeft->forward();	  
}

void TwoControllerBase::rotateRight(unsigned short turnSpeed){
	_motorFrontRight->setSpeed(turnSpeed);
	_motorFrontLeft->setSpeed(turnSpeed);
	_motorRearRight->setSpeed(turnSpeed);
	_motorRearLeft->setSpeed(turnSpeed);
	_motorFrontRight->forward();
	_motorFrontLeft->forward();
	_motorRearRight->forward();
	_motorRearLeft->forward();	
}

void TwoControllerBase::rotateLeft(unsigned short turnSpeed){
	_motorFrontRight->setSpeed(turnSpeed);
	_motorFrontLeft->setSpeed(turnSpeed);
	_motorRearRight->setSpeed(turnSpeed);
	_motorRearLeft->setSpeed(turnSpeed);
	_motorFrontRight->backward();
	_motorFrontLeft->backward();
	_motorRearRight->backward();
	_motorRearLeft->backward();
}
