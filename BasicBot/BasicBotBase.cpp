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


#include "BasicBotBase.h"

  BasicBotBase::BasicBotBase(){
      // signal pins need to be pwm pins on the UNO board (~ near the number)
      rightSignal = 3;
      leftSignal = 6; 
      // these pins don't need to be pwm
      rightIn1 = 10;
      rightIn2 = 9;
      leftIn1 = 5;
      leftIn2 = 4;
      _motorRight = new L298N(rightSignal,rightIn1,rightIn2);
      _motorLeft = new L298N(leftSignal,leftIn1,leftIn2);
    }
  void BasicBotBase::driveForward(unsigned short rightWheel, unsigned short leftWheel){
      _motorRight->setSpeed(rightWheel);
      _motorLeft->setSpeed(leftWheel);
      _motorRight->backward();
      _motorLeft->forward();
    }
  void BasicBotBase::driveBackward(unsigned short rightWheel, unsigned short leftWheel){
      _motorRight->setSpeed(rightWheel);
      _motorLeft->setSpeed(leftWheel);
      _motorRight->forward();
      _motorLeft->backward();
    
    }
  void BasicBotBase::rotateRight(unsigned short turnSpeed){
      _motorRight->setSpeed(turnSpeed);
      _motorLeft->setSpeed(turnSpeed);
      _motorRight->backward();
      _motorLeft->backward();
    
    }
  void BasicBotBase::rotateLeft(unsigned short turnSpeed){
      _motorRight->setSpeed(turnSpeed);
      _motorLeft->setSpeed(turnSpeed);
      _motorRight->forward();
      _motorLeft->forward();
    
    }
