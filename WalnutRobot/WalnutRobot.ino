//#include <L298N.h>
#include "WalnutBase.h"
#include "RobotPixy.h"

	RobotPixy *pixy;
	WalnutBase *base;
  int ball, goal, ownGoal;
	
	//float goalHeading;
	//boolean motorRunning; 
	//int currentSpeed;
	//float heading;
	

	void setup(){
    ball = 1;
    goal = 2;
    ownGoal =3;
    //currentSpeed = 0;
    //motorRunning = true;
    base = new WalnutBase();
   // base->AFMS.begin();
    //compass = new RobotCompass();
    //goalHeading = compass->getHeading();
   // irseeker = new RobotIRSeeker();
   // irseeker->Initialize();
   // dribbler = new RobotDribbler();
	pixy = new RobotPixy();
    Serial.begin(9600);
  }

/****************ultraSonic sampling call*****************************
	int ultraSonicDistance(int trigPin, int echoPin){
		long duration, distance;
		pinMode(trigPin, OUTPUT);
		pinMode(echoPin, INPUT);
		digitalWrite(trigPin, LOW); 
		delayMicroseconds(2); 
		digitalWrite(trigPin, HIGH);
		delayMicroseconds(10); 
		digitalWrite(trigPin, LOW);
		duration = pulseIn(echoPin, HIGH);
		distance = (duration/2) / 29.1;
		if (distance >= 300 || distance <= 0){
			return 0;
		}
		else {
			return distance;
		}
		delay(100);	
	}
/***********************************************************************/

	void loop(){
    
	//	heading = compass->getHeading();
	//	ball = irseeker->ReadAC();
	//	Serial.println("ball created");
	//	irStrength = ball.Strength;
	//	Serial.print(irStrength);Serial.println("  ir strength");
	//	irDirection = ball.Direction;
	//	Serial.print(irDirection);Serial.println("  ir direction");
	//	Serial.print(heading);Serial.println("  heading");
		/*usDistance1 = ultraSonicDistance(7, 6);
		Serial.print(usDistance1);Serial.println("  distance with Ultrasonic 1");
		usDistance2 = ultraSonicDistance(9, 8);
		Serial.print(usDistance2);Serial.println("  distance with Ultrasonic 2");
		usDistance3 = ultraSonicDistance(11, 10);
		Serial.print(usDistance3);Serial.println("  distance with Ultrasonic 3");
		delay(2000);*/
     // if (motorRunning){
    //delay(5000);
   base->moveRobotBackward(base->MAX_SPEED);
  //  delay(500);
   // base->moveRobotRight(base->HALF_SPEED);
   // delay(500);
  //  base->moveRobotBackward(base->THREE_QUARTER_SPEED);
   // delay(500);
   // base->moveRobotLeft(base->HALF_SPEED);
  //  delay(500);
  //  base->rotateRobotRight(base->HALF_SPEED);
  //  delay(500);
 //   base->rotateRobotLeft(base->HALF_SPEED);
   // delay(500);
  // motorRunning = false;
   // }
    
	//	if (heading>100){
	//		motorRunning = false;
	//	}
  
	//	if(motorRunning){
	//		if(currentSpeed<base->MAX_SPEED){
	//			currentSpeed += 15; 
	//			Serial.print("adding "); Serial.println(currentSpeed);
	//		}
	//		base->rotateRobotRight(currentSpeed);
	//		Serial.println("Power motor ");     
			// motorRunning = false;
	//	}
 //  Serial.println("dribbler running");
  // dribbler->dribble();
	//	base->moveRobotForward(base->MAX_SPEED);
		//base->moveRobotBackward(base->MAX_SPEED);
		//base->moveRobotRight(base->HALF_SPEED);
		//base->moveRobotLeft(base->MAX_SPEED);
		//base->rotateRobotRight(base->MAX_SPEED);
 //   delay(1000);
 //   base->stopRobotAfter(100);
		//base->rotateRobotLeft(base->QUARTER_SPEED);
		// heading = compass->getHeading();
	//	Serial.print("Heading ");Serial.println(heading);
		//base->stopRobotAfter(100);


		Serial.print("this is the x value:  ");Serial.println(pixy->getX(ball));
		Serial.print("this will display if in front:  ");Serial.println(pixy->isInFront(ball));
		Serial.print("this is the area value:  ");Serial.println(pixy->getArea(ball));
	}

