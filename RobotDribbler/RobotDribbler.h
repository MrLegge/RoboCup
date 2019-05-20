#ifndef ROBOTDRIBBLER_H
#define ROBOTDRIBBLER_H

#include <L298N.h>

	class RobotDribbler{
		
		public:
			
			void dribble();
			void kick();
			void waitForBall();
      RobotDribbler();
     
		private:
			int rightSignal, rightIn1, rightIn2; 
			int leftSignal, leftIn1, leftIn2; 
			L298N *motorRight;
			L298N *motorLeft;
	};

#endif
