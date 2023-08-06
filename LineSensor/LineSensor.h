/*
  LineSensor.h class library to provide line sensing
  
  Author: Kyla Bradford y11  12/11/22
  Adapted: Phil Legge  6/8/23
  email: phil.legge@det.nsw.edu.au
*/

#ifndef ROBOTLINESENSOR_H
#define ROBOTLINESENSOR_H


#include <arduino.h>
       class LineSensor{

          public:
	LineSensor();
	LineSensor(int);
            
            bool onLine();
          //  bool reverse();

          protected:
            bool _lineFlag;
            int _signalPin;
           
      };
    
#endif
