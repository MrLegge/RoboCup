#include "RobotCompass.h"

	RobotCompass::RobotCompass(void){
		Wire.begin();
		myCompass.SetDeclination(61, 43, 'E'); //set to local area  http://www.magnetic-declination.com/
		myCompass.SetSamplingMode(COMPASS_SINGLE); //CONTINUOUS
		//   Options are 088, 130 (default), 190, 250, 400, 470, 560, 810 'COMPASS_SCALE_XXX'
		myCompass.SetScale(COMPASS_SCALE_400);
		myCompass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);  
	}
    
	float RobotCompass::getHeading(){    
		heading = myCompass.GetHeadingDegrees();
		return heading;    
	}
