/*******************************************************************
*	This is the library of the base of your robot, you should not  
*	need to adapt any of this code unless you want to change the  
*	default constant values for the motor controller.
*
*	You should use this file to check the functions available  
*	for you to use in your setup and loop functions.
*	
*	Author: Phil Legge
*	Date: 7/8/18
*********************************************************************/

#ifndef CARBASE_H
#define CARBASE_H

#include <L298N.h>

	class BasicBotBase{
		public:
		  const int MAX_SPEED = 255; 
		  const int THREE_QUARTER_SPEED = 138; 
		  const int HALF_SPEED = 92; 
		  const int QUARTER_SPEED = 46;  
		  const int MIN_SPEED = 15; 
		  int rightSignal, rightIn1, rightIn2; 
		  int leftSignal, leftIn1, leftIn2; 
		  
		  BasicBotBase();
		  
		  void driveForward(unsigned short, unsigned short);
		  void driveBackward(unsigned short, unsigned short);
		  void rotateRight(unsigned short);
		  void rotateLeft(unsigned short);
		private:
			L298N *_motorRight;
			L298N *_motorLeft;
	};

#endif 
