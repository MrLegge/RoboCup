#ifndef ROBOTPIXY_H
#define ROBOTPIXY_H

#include <SPI.h>  
#include <Pixy.h>

	class RobotPixy{
		
		public:
			Pixy myPixy;
			uint16_t blocks;

			void getData();
			int getArea(int);
			bool isInFront(int);
			int getX(int);

      
			RobotPixy();

	};
#endif
