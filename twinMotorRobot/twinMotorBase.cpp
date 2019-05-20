/*************************************************************
* This is the robot base control class which is designed for a 
* four wheel robot construction using two Pololu_DCMotor 
* controllers and and arduino Mega2560 
**************************************************************/
#include <L298N.h>
#include "TwinMotorBase.h"

	TwinMotorBase::TwinMotorBase(void){
    motorsRight = new DualVNH5019MotorShield();
    motorsLeft = new DualVNH5019MotorShield(sigPinM1a,sigPinM1b,pwmM1,sigPinM1c,analogM1,sigPinM2a,sigPinM2b,pwmM2,sigPinM2c,analogM2);
		motorsRight->init();
		motorsLeft->init();	
	}
	
	void TwinMotorBase::stopRobot(){		
		int inSpeed = 0;
		motorsRight->setM1Speed(inSpeed);
		motorsRight->setM2Speed(inSpeed);
		motorsLeft->setM1Speed(inSpeed);
		motorsLeft->setM2Speed(inSpeed);
	}
	  /************************************************************check motor directions**********************************************************************/
	void TwinMotorBase::moveRobotForward(int inSpeed){		
		motorsRight->setM1Speed(inSpeed);
		//motor 2 forward
		motorsRight->setM2Speed(inSpeed);
		//motor 3 forward
		motorsLeft->setM1Speed(inSpeed);
		//motor 4 forward
		motorsLeft->setM2Speed(inSpeed);		
	}
	
	void TwinMotorBase::moveRobotBackward(int inSpeed){
		//motor 1 backwards
		motorsRight->setM1Speed(inSpeed*-1);
		//motor 2 backwards
		motorsRight->setM2Speed(inSpeed*-1);
		//motor 3 backwards
		motorsLeft->setM1Speed(inSpeed*-1);
		//motor 4 backwards
		motorsLeft->setM2Speed(inSpeed*-1);	
	}
	
	void TwinMotorBase::moveRobotLeft(int inSpeed){
		 //motor 1 forward
		motorsRight->setM1Speed(inSpeed);
		//motor 2 backwards
		motorsRight->setM2Speed(inSpeed*-1);
		//motor 3 forward
		motorsLeft->setM1Speed(inSpeed*-1);
		//motor 4 backwards
		motorsLeft->setM2Speed(inSpeed);	
	}
	
	void TwinMotorBase:: moveRobotRight(int inSpeed){
		 //motor 1 backwards
		motorsRight->setM1Speed(inSpeed*-1);
		//motor 2 forward
		motorsRight->setM2Speed(inSpeed);
		//motor 3 backwards
		motorsLeft->setM1Speed(inSpeed);
		//motor 4 forward
		motorsLeft->setM2Speed(inSpeed*-1);	
	}
	
	void TwinMotorBase::rotateRobotRight(int inSpeed){
	   //motor 1 forward
		motorsRight->setM1Speed(inSpeed*-1);
		//motor 2 forward
		motorsRight->setM2Speed(inSpeed*-1);
		//motor 3 backwards
		motorsLeft->setM1Speed(inSpeed);
		//motor 4 backwards
		motorsLeft->setM2Speed(inSpeed);	
    }
	
	void TwinMotorBase::rotateRobotLeft(int inSpeed){
	  //motor 1 backwards
		motorsRight->setM1Speed(inSpeed);
		//motor 2 backwards
		motorsRight->setM2Speed(inSpeed);
		//motor 3 forward
		motorsLeft->setM1Speed(inSpeed*-1);
		//motor 4 forward
		motorsLeft->setM2Speed(inSpeed*-1);	
    }
