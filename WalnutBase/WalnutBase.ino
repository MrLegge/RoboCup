/*************************************************************
* this is the robot base control class which is designed for a 
* four wheel robot construction using two Pololu_DCMotor 
* controllers and and arduino Mega2560 
**************************************************************/

#include <DualVNH5019MotorShield.h>

    const int WALNUT_MAX_SPEED = 400;
    const int WALNUT_THREE_QUARTER_SPEED = 300;
    const int WALNUT_HALF_SPEED = 200;
    const int WALNUT_QUARTER_SPEED = 100;
    const int WALNUT_MIN_SPEED = 1;

    DualVNH5019MotorShield motorsRight; //signalPinM1 2, 4, 6 PWM_M1 9 AnalogPinM1 A0 || signalPinM2 7, 8, 12 PWM_M2 10 AnalogPinM2 A1
	// the second shield needs the wires conected to the same pins as the first but use the following pins into the Mega2560
	DualVNH5019MotorShield motorsLeft(24,26,45,22,A8,25,27,46,23,A9);//signalPinM1 24,26,22 PWM_M1 45 AnalogPinM1 A8 || signalPinM2 25,27,23 PWM_M2 46 AnalogPinM2 A9


void setup(){
    motorsRight.init();
	motorsLeft.init();	
  }
  
void loop(){
    moveRobotForward(WALNUT_HALF_SPEED);
   //stopRobot();
  }

  void  stopRobot(){		
		int inSpeed = 0;
		motorsRight.setM1Speed(inSpeed);
		motorsRight.setM2Speed(inSpeed);
		motorsLeft.setM1Speed(inSpeed);
		motorsLeft.setM2Speed(inSpeed);
  }
   /*********************check motor directions*******************/
  //motor 1 forward
	void moveRobotForward(int inSpeed){		
		motorsRight.setM1Speed(inSpeed);
		//motor 2 forward
		motorsRight.setM2Speed(inSpeed);
		//motor 3 forward
		motorsLeft.setM1Speed(inSpeed);
		//motor 4 forward
		motorsLeft.setM2Speed(inSpeed);		
	  }
	void moveRobotBackward(int inSpeed){
		//motor 1 backwards
		motorsRight.setM1Speed(inSpeed*-1);
		//motor 2 backwards
		motorsRight.setM2Speed(inSpeed*-1);
		//motor 3 backwards
		motorsLeft.setM1Speed(inSpeed*-1);
		//motor 4 backwards
		motorsLeft.setM2Speed(inSpeed*-1);	
	  }
	 void moveRobotLeft(int inSpeed){
		 //motor 1 forward
		motorsRight.setM1Speed(inSpeed);
		//motor 2 backwards
		motorsRight.setM2Speed(inSpeed*-1);
		//motor 3 forward
		motorsLeft.setM1Speed(inSpeed);
		//motor 4 backwards
		motorsLeft.setM2Speed(inSpeed*-1);	
	  }
	 void moveRobotRight(int inSpeed){
		 //motor 1 backwards
		motorsRight.setM1Speed(inSpeed*-1);
		//motor 2 forward
		motorsRight.setM2Speed(inSpeed);
		//motor 3 backwards
		motorsLeft.setM1Speed(inSpeed*-1);
		//motor 4 forward
		motorsLeft.setM2Speed(inSpeed);	
	  }
   void rotateRobotRight(int inSpeed){
	   //motor 1 forward
		motorsRight.setM1Speed(inSpeed);
		//motor 2 forward
		motorsRight.setM2Speed(inSpeed);
		//motor 3 backwards
		motorsLeft.setM1Speed(inSpeed*-1);
		//motor 4 backwards
		motorsLeft.setM2Speed(inSpeed*-1);	
    }
  void rotateRobotLeft(int inSpeed){
	  //motor 1 backwards
		motorsRight.setM1Speed(inSpeed*-1);
		//motor 2 backwards
		motorsRight.setM2Speed(inSpeed*-1);
		//motor 3 forward
		motorsLeft.setM1Speed(inSpeed);
		//motor 4 forward
		motorsLeft.setM2Speed(inSpeed);	
    }
