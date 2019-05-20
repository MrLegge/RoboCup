/*************************************************************
* This is the robot base control class which is designed for a 
* four wheel robot construction using two Pololu_DCMotor 
* controllers and and arduino Mega2560 
**************************************************************/

#ifndef TWINMOTORBASE_H
#define TWINMOTORBASE_H

#include <DualVNH5019MotorShield.h>

	class TwinMotorBase{
		public:
			const int MAX_SPEED = 400;
			const int THREE_QUARTER_SPEED = 300;
			const int HALF_SPEED = 200;
			const int QUARTER_SPEED = 100;
			const int MIN_SPEED = 1;
			
			L298N *motorRight;
			/*	signalPinM1 2, 4, 6 
				PWM_M1 9 
				AnalogPinM1 A0 
				signalPinM2 7, 8, 12 
				PWM_M2 10 
				AnalogPinM2 A1 
				*/
			L298N *motorLeft; 			
			
      //  will need to test this for uno
			/*	signalPinM1 24,26,22  //
				PWM_M1 45 
				AnalogPinM1 A8 
				signalPinM2 25,27,23 
				PWM_M2 46 
				AnalogPinM2 A9 
				*/
				
			// functions
			void stopRobot();
			void moveRobotForward(int);
			void moveRobotBackward(int);
			void moveRobotLeft(int);
			void moveRobotRight(int);
			void rotateRobotRight(int);
			void rotateRobotLeft(int);
      TwinMotorBase();
      //DualVNH5019MotorShield motorsLeft(24,26,45,22,A8,25,27,46,23,A9);
		protected:
		  uint8_t sigPinM1a = 24;
		  uint8_t sigPinM1b = 26;
		  uint8_t sigPinM1c = 22;
		  uint8_t pwmM1 = 45;
		  uint8_t analogM1 = A8;
		  uint8_t sigPinM2a = 25;
		  uint8_t sigPinM2b = 27;
		  uint8_t sigPinM2c = 23;
		  uint8_t pwmM2 = 46;
		  uint8_t analogM2 = A9;
	};

#endif
