/*************************************************************
* This is the robot base control class which is designed for a 
* four wheel robot construction using two Pololu_DCMotor 
* controllers and and arduino Mega2560 
**************************************************************/

#ifndef WALNUTBASE_H
#define WALNUTBASE_H

#include <DualVNH5019MotorShield.h>

	class WalnutBase{
		public:
			const int WALNUT_MAX_SPEED = 400;
			const int WALNUT_THREE_QUARTER_SPEED = 300;
			const int WALNUT_HALF_SPEED = 200;
			const int WALNUT_QUARTER_SPEED = 100;
			const int WALNUT_MIN_SPEED = 1;
			
			DualVNH5019MotorShield motorsRight; 
			/*	signalPinM1 2, 4, 6 
				PWM_M1 9 
				AnalogPinM1 A0 
				signalPinM2 7, 8, 12 
				PWM_M2 10 
				AnalogPinM2 A1 
				*/
			// the second shield needs the wires conected to the same pins as the first but use the following pins into the Mega2560
			DualVNH5019MotorShield motorsLeft(24,26,45,22,A8,25,27,46,23,A9);
			/*	signalPinM1 24,26,22 
				PWM_M1 45 
				AnalogPinM1 A8 
				signalPinM2 25,27,23 
				PWM_M2 46 
				AnalogPinM2 A9 
				*/
				
			// functions
			void  stopRobot();
			void moveRobotForward(int inSpeed);
			void moveRobotBackward(int inSpeed);
			void moveRobotLeft(int inSpeed);
			void moveRobotRight(int inSpeed);
			void rotateRobotRight(int inSpeed);
			void rotateRobotLeft(int inSpeed);
		protected:
		
	};

#endif