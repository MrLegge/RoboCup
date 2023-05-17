#ifndef ROBOTLASER_H
#define ROBOTLASER_H

	class RobotLaser{

		public:
			RobotLaser();
			void initialize();
			bool beamBroken();

		protected:
			int sensorValue;
			int sensorPin;
			int ledPin;
	};
#endif
