/*
	base class to get the car working in object oriented programming
	For the 2019 Manditory Tech course
  
	Author: Phil Legge 12/11/18
  email: phil.legge@det.nsw.edu.au
*/

#include "CarBase.h"
#define trigPin A0
#define echoPin A1

//create variables one CarBase object and an integer value
 CarBase *myBase;
 int carDistance;

void setup(){
	myBase = new CarBase();
  Serial.begin(9600); // this is for the output to the terminal (comment out after testing)
}

void loop(){  
  carDistance = ultraSonicDistance(trigPin,echoPin);// first the distance is queried from the ultrasonic
  if (carDistance > 0){  //logical decision based on ultrasonic return larger than zero 
      if(carDistance < 20){ //logical decision based on ultrasonic return smaller than 20cm 
        Serial.print("ultra distance -> ");Serial.print(carDistance);Serial.println("cm. Get out of there you are too close!!");     
        myBase->driveForward(0,0);
        delay(1000); 
      }else{ //logical reaction based on ultrasonic return larger than 20 less than 3m 
        Serial.print("ultra distance -> ");Serial.print(carDistance);Serial.println("cm");
        myBase->driveForward(175,175); //you 
        delay(500);
      }
  }else {  //logical reaction based on ultrasonic return less than 0 (distance greater than 3m or reflected not returned?)
      Serial.println("nothing in front");
      myBase->driveForward(255,255);  //forward full speed
      delay(500);
      }    
}

/****************ultraSonic distance function*****************************/
  int ultraSonicDistance(int trig, int echo){
    // returns error code or value for use in logic conditions bsed on offset to object infront
    long duration; 
    int distance;
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trig, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trig, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration/2) / 29;
    if (distance >= 300 ){ // return -1 if bigger than 3m
      return -1;
    }
    else if(distance <= 0){ // returns 0 for error or zero results
      return 0;
    }
    else {
      return distance; // returns a value if test is between 0m and 3m
    }
    delay(100); 
  }
/***********************************************************************/
