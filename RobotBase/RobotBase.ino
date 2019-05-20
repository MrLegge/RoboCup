/*************************************************************
* this is the robot base control class which is designed for a 
* four wheel robot construction using an Adafruit_DCMotor controller
* and and arduino Uno 
**************************************************************/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

    const int MAX_SPEED = 255;
    const int THREE_QUARTER_SPEED = 190;
    const int HALF_SPEED = 127;
    const int QUARTER_SPEED = 90;
    const int MIN_SPEED = 30;

    Adafruit_MotorShield AFMS; 
    Adafruit_DCMotor *myMotorM1;
    Adafruit_DCMotor *myMotorM2;
    Adafruit_DCMotor *myMotorM3;
    Adafruit_DCMotor *myMotorM4;

void setup(){
    AFMS = Adafruit_MotorShield();
    AFMS.begin();
    myMotorM1 = AFMS.getMotor(1);     
    myMotorM2 = AFMS.getMotor(2);
    myMotorM3 = AFMS.getMotor(3);      
    myMotorM4 = AFMS.getMotor(4); 
  }
void loop(){
   moveRobotForward(MAX_SPEED);
   //stopRobotAfter(1500);
  }



  void  stopRobotAfter(int time){
		delay(time);
		myMotorM1->setSpeed(0); 
		myMotorM2->setSpeed(0); 
		myMotorM3->setSpeed(0); 
		myMotorM4->setSpeed(0);   
  }
	void moveRobotForward(int inSpeed){
  	  myMotorM1->setSpeed(inSpeed); 
  	  myMotorM1->run(FORWARD);
  	  myMotorM2->setSpeed(inSpeed); 
  	  myMotorM2->run(FORWARD);
  	  myMotorM3->setSpeed(inSpeed); 
  	  myMotorM3->run(FORWARD);
  	  myMotorM4->setSpeed(inSpeed); 
  	  myMotorM4->run(FORWARD);
	  }
	void moveRobotBackward(int inSpeed){
  	  myMotorM1->setSpeed(inSpeed); 
  	  myMotorM1->run(BACKWARD);
  	  myMotorM2->setSpeed(inSpeed); 
  	  myMotorM2->run(BACKWARD);
  	  myMotorM3->setSpeed(inSpeed); 
  	  myMotorM3->run(BACKWARD);
  	  myMotorM4->setSpeed(inSpeed); 
  	  myMotorM4->run(BACKWARD);
	  }
	 void moveRobotLeft(int inSpeed){
  	  myMotorM1->setSpeed(inSpeed); 
  	  myMotorM1->run(FORWARD);
  	  myMotorM2->setSpeed(inSpeed); 
  	  myMotorM2->run(BACKWARD);
  	  myMotorM3->setSpeed(inSpeed); 
  	  myMotorM3->run(FORWARD);
  	  myMotorM4->setSpeed(inSpeed); 
  	  myMotorM4->run(BACKWARD);
	  }
	 void moveRobotRight(int inSpeed){
  	  myMotorM1->setSpeed(inSpeed); 
  	  myMotorM1->run(BACKWARD);
  	  myMotorM2->setSpeed(inSpeed); 
  	  myMotorM2->run(FORWARD);
  	  myMotorM3->setSpeed(inSpeed); 
  	  myMotorM3->run(BACKWARD);
  	  myMotorM4->setSpeed(inSpeed); 
  	  myMotorM4->run(FORWARD);
	  }
   void rotateRobotRight(int inSpeed){
      myMotorM1->setSpeed(inSpeed); 
      myMotorM1->run(FORWARD);
      myMotorM2->setSpeed(inSpeed); 
      myMotorM2->run(FORWARD);
      myMotorM3->setSpeed(inSpeed); 
      myMotorM3->run(BACKWARD);
      myMotorM4->setSpeed(inSpeed); 
      myMotorM4->run(BACKWARD);
    }
  void rotateRobotLeft(int inSpeed){
      myMotorM1->setSpeed(inSpeed); 
      myMotorM1->run(BACKWARD);
      myMotorM2->setSpeed(inSpeed); 
      myMotorM2->run(BACKWARD);
      myMotorM3->setSpeed(inSpeed); 
      myMotorM3->run(FORWARD);
      myMotorM4->setSpeed(inSpeed); 
      myMotorM4->run(FORWARD);
    }
 

