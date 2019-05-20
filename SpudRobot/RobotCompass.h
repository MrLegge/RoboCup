#ifndef ROBOTCOMPASS_H
#define ROBOTCOMPASS_H

#include <Wire.h>
#include "robotLibrary\HMC5883L_Simple.h"

	class RobotCompass{

		public:
			float getHeading();
			HMC5883L_Simple myCompass;
      
			RobotCompass();

		protected:
			float heading;

	};
#endif
