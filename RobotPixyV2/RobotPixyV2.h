#ifndef ROBOTPIXYV2_H
#define ROBOTPIXYV2_H
 
#include <Pixy2.h>
#include <stdint.h>


	class RobotPixyV2{
		
		public:
			Pixy2 myPixy;
			
			int getArea(int);
			bool isInFront(int);
			int getX(int);
			int getY(int);
			void lightsOn(void); 
			void lightsOff(void);
			RobotPixyV2();
			
		private:
			uint16_t blocks;
		
			void getData(void);

	};
#endif
