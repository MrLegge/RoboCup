#ifndef ROBOTBASE_H
#define ROBOTBASE_H

#include <Wire.h>
#include <Adafruit_MotorShield.h>

	class RobotBase{
  
		public:
			const int MAX_SPEED = 255; 
			const int THREE_QUARTER_SPEED = 138; 
			const int HALF_SPEED = 92; 
			const int QUARTER_SPEED = 46;  
			const int MIN_SPEED = 31; 
			Adafruit_MotorShield AFMS; 
     
			RobotBase();
			
			void moveRobotForward(int inSpeed);
			void moveRobotBackward(int inSpeed);
			void moveRobotLeft(int inSpeed);
			void moveRobotRight(int inSpeed);
			void rotateRobotRight(int inSpeed);
			void rotateRobotLeft(int inSpeed);
			void stopRobotAfter(int time);

	protected:      
			Adafruit_DCMotor *myMotorM1;
			Adafruit_DCMotor *myMotorM2;
			Adafruit_DCMotor *myMotorM3;
			Adafruit_DCMotor *myMotorM4;

			
	};
#endif

