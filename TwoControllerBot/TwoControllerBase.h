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

#ifndef TWOCONTROLLERBASE_H
#define TWOCONTROLLERBASE_H

#include <L298N.h>

	class TwoControllerBase{
		public:
			const int MAX_SPEED = 255; 
			const int THREE_QUARTER_SPEED = 138; 
			const int HALF_SPEED = 92; 
			const int QUARTER_SPEED = 46;  
			const int MIN_SPEED = 15; 
			int rightFrontSignal, rightFrontIn1, rightFrontIn2, rightRearSignal, rightRearIn1, rightRearIn2; 
			int leftFrontSignal, leftFrontIn1, leftFrontIn2, leftRearSignal, leftRearIn1, leftRearIn2; 

			TwoControllerBase();

			void driveForward(unsigned short);
			void driveBackward(unsigned short);
			void driveRight(unsigned short);
			void driveLeft(unsigned short);
			void rotateRight(unsigned short);
			void rotateLeft(unsigned short);
		private:
			L298N *_motorFrontRight;
			L298N *_motorFrontLeft;
			L298N *_motorRearRight;
			L298N *_motorRearLeft;
	};

#endif 
