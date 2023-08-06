#ifndef ROBOTACCELEROMETER_H
#define ROBOTACCELEROMETER_H
#define ACCELX A1
#define ACCELY A2
#define ACCELZ A3

#include "Arduino.h"
	class RobotAccelerometer{

		public:
			RobotAccelerometer();
			int getAccelX();
			int getAccelY();
			int getAccelZ();
      
			

		protected:
			int _accelerometerX;
			int _accelerometerY;
			int _accelerometerZ;

	};
#endif
