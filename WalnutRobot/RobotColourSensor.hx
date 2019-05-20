#ifndef ROBOTCOLOURSENSOR_H
#define ROBOTCOLOURSENSOR_H

#include <Adafruit_TCS34725.h>
#include <Wire.h>

  class RobotColourSensor{
    
    public:

      Adafruit_TCS34725 robotColoursSensor;
      RobotColourSensor();
     // isRed();
      
    private:
      boolean isRed, isGreen, isBlue;
      uint16_t clear, red, green, blue;
      void getData();
    };

#endif
