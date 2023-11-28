#ifndef ROBOTLASER_H
#define ROBOTLASER_H

	class RobotLaser{

		public:
			RobotLaser();
			void initialize();
			bool beamBroken();

		protected:
			int _sensorValue;
			int _sensorPin;
			int _ledPin;
	};
#endif
