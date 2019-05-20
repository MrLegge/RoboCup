/*******************************************
* Motor wire layout: 
*	Pos 1 - power (red)
*	Pos 2 - signal pin (green)
*	Pos 3 - direction pin (yellow)
*	Pos 4 - GND (black)
*	Pos 5 - PWM control (blue)
*
********************************************/

#include "RobotBaseNoController.h"
#include <Arduino.h>


RobotBaseNoController::RobotBaseNoController(){
	i = 0;
	rightPWM = 9;
	rightDirectionPin = 10;
	rightSignalPin = 11;
	leftPWM = 3;
	leftDirectionPin = 5;
	leftSignalPin = 6;
	time = 0;
	flag = HIGH; 
	pinMode(rightPWM,OUTPUT);
	pinMode(rightDirectionPin,OUTPUT);
	pinMode(rightSignalPin,OUTPUT);
	pinMode(leftPWM,OUTPUT);
	pinMode(leftDirectionPin,OUTPUT);
	pinMode(leftSignalPin,OUTPUT);
	}

void RobotBaseNoController::driveForward(unsigned short rightWheel, unsigned short leftWheel){ 
  if((rightWheel>=0 && rightWheel <= 255)&&(leftWheel>=0 && leftWheel <= 255) ){
		digitalWrite(rightDirectionPin,LOW);    
		digitalWrite(rightSignalPin,HIGH);
		analogWrite(rightPWM,rightWheel);
		digitalWrite(leftDirectionPin,HIGH);    
		digitalWrite(leftSignalPin,LOW);
		analogWrite(leftPWM,leftWheel);
		}
}
  void RobotBaseNoController::driveBackward(unsigned short rightWheel, unsigned short leftWheel){
    if((rightWheel>=0 && rightWheel <= 255)&&(leftWheel>=0 && leftWheel <= 255) ){
		digitalWrite(rightDirectionPin,HIGH);  
		digitalWrite(rightSignalPin,LOW);
		analogWrite(rightPWM,rightWheel);
		digitalWrite(leftDirectionPin,LOW);    
		digitalWrite(leftSignalPin,HIGH);
		analogWrite(leftPWM,leftWheel);
      }
  }
  void RobotBaseNoController::stopMotors(){
		digitalWrite(rightDirectionPin,LOW);
		digitalWrite(rightSignalPin,LOW); 
		digitalWrite(leftDirectionPin,LOW);
		digitalWrite(leftSignalPin,LOW);
  }
  void RobotBaseNoController::rotateRight(unsigned short turnSpeed){
    if(turnSpeed>=0 && turnSpeed <= 255){
		digitalWrite(rightDirectionPin,HIGH);    
		digitalWrite(rightSignalPin,LOW);
		analogWrite(rightPWM,turnSpeed);
		digitalWrite(leftDirectionPin,HIGH);    
		digitalWrite(leftSignalPin,LOW);
		analogWrite(leftPWM,turnSpeed);
    }
  }
  void RobotBaseNoController::rotateLeft(unsigned short turnSpeed){
    if(turnSpeed>=0 && turnSpeed <= 255){
		digitalWrite(rightDirectionPin,LOW);    
		digitalWrite(rightSignalPin,HIGH);
		analogWrite(rightPWM,turnSpeed);
		digitalWrite(leftDirectionPin,HIGH);    
		digitalWrite(leftSignalPin,LOW);
		analogWrite(leftPWM,turnSpeed);
     }
  }
