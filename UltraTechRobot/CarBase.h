/*
  base class library to get the car working in object oriented programming
  For the 2019 Manditory Tech course
  
  Author: Phil Legge 12/11/18
  email: phil.legge@det.nsw.edu.au
*/

#ifndef CARBASE_H
#define CARBASE_H

#include <L298N.h>

	class CarBase{
		public:
		  const int MAX_SPEED = 255; 
		  const int THREE_QUARTER_SPEED = 138; 
		  const int HALF_SPEED = 92; 
		  const int QUARTER_SPEED = 46;  
		  const int MIN_SPEED = 15; 
		  int rightSignal, rightIn1, rightIn2; 
		  int leftSignal, leftIn1, leftIn2; 
		  
		  CarBase();
		  
		  void driveForward(unsigned short rightWheel, unsigned short leftWheel);
		  void driveBackward(unsigned short rightWheel, unsigned short leftWheel);
		  void rotateRight(unsigned short turnSpeed);
		  void rotateLeft(unsigned short turnSpeed);
		private:
			L298N *motorRight;
			L298N *motorLeft;
	};

#endif 
