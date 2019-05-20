#include "RobotDribbler.h"

RobotDribbler::RobotDribbler(){
		rightSignal = 5;
		leftSignal = 10;
		rightIn1 = 6;
		rightIn2 = 7; 
		leftIn1 = 8;
		leftIn2 = 9;
		pinMode(rightSignal, OUTPUT);
		pinMode(rightIn1, OUTPUT);
		pinMode(rightIn2, OUTPUT);		
		pinMode(leftIn1, OUTPUT);
		pinMode(leftIn2, OUTPUT);
		pinMode(leftSignal, OUTPUT);
		motorRight = new L298N(rightSignal,rightIn1,rightIn2);
		motorLeft = new L298N(leftSignal,leftIn1,leftIn2);	
	}
 
void RobotDribbler::dribble(){    
		motorRight->setSpeed(85);    
    motorLeft->setSpeed(85);  
    motorRight->backward();
    motorLeft->forward();  
	}
	
void RobotDribbler::kick(){    
		motorRight->setSpeed(85);
    motorLeft->setSpeed(85);    
    motorRight->forward();
    motorLeft->backward();
	}
	
void RobotDribbler::waitForBall(){
	  motorRight->setSpeed(0);
    motorLeft->setSpeed(0);
    motorRight->forward();
    motorLeft->forward();
}
