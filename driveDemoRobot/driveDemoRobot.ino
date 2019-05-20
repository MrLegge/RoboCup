/*
	base class to get the car working in object oriented programming
	For the 2019 Manditory Tech course

	Author: Phil Legge 26/03/19
	email: phil.legge@det.nsw.edu.au
*/

#include "CarBase.h"

//create variables one CarBase object and a boolean value for selection
	CarBase *myBase;
	bool flag;
	
	void setup(){   // sets up once as the program starts
		myBase = new CarBase();
		flag = true;
	}

	void loop(){ // loops continuously 50 times a second

		if (flag){
			myBase->driveForward(255,255);
			delay(1000);
			flag = false;
		}else{
      myBase->driveForward(0,0);
    }
	}

