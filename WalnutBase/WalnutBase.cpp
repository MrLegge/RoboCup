/*************************************************************
* This is the robot base control class which is designed for a 
* four wheel robot construction using two Pololu_DCMotor 
* controllers and and arduino Mega2560 
**************************************************************/
#include <DualVNH5019MotorShield.h>
#include "WalnutBase.h"

	WalnutBase::WalnutBase(void){
		motorsRight.init();
		motorsLeft.init();	
	}
	
	void WalnutBase::stopRobot(){		
		int inSpeed = 0;
		motorsRight.setM1Speed(inSpeed);
		motorsRight.setM2Speed(inSpeed);
		motorsLeft.setM1Speed(inSpeed);
		motorsLeft.setM2Speed(inSpeed);
	}
	  /************************************************************check motor directions**********************************************************************/
	void WalnutBase::moveRobotForward(int inSpeed){		
		motorsRight.setM1Speed(inSpeed);
		//motor 2 forward
		motorsRight.setM2Speed(inSpeed);
		//motor 3 forward
		motorsLeft.setM1Speed(inSpeed);
		//motor 4 forward
		motorsLeft.setM2Speed(inSpeed);		
	}
	
	void WalnutBase::moveRobotBackward(int inSpeed){
		//motor 1 backwards
		motorsRight.setM1Speed(inSpeed*-1);
		//motor 2 backwards
		motorsRight.setM2Speed(inSpeed*-1);
		//motor 3 backwards
		motorsLeft.setM1Speed(inSpeed*-1);
		//motor 4 backwards
		motorsLeft.setM2Speed(inSpeed*-1);	
	}
	
	void WalnutBase::moveRobotLeft(int inSpeed){
		 //motor 1 forward
		motorsRight.setM1Speed(inSpeed);
		//motor 2 backwards
		motorsRight.setM2Speed(inSpeed*-1);
		//motor 3 forward
		motorsLeft.setM1Speed(inSpeed);
		//motor 4 backwards
		motorsLeft.setM2Speed(inSpeed*-1);	
	}
	
	void WalnutBase::void moveRobotRight(int inSpeed){
		 //motor 1 backwards
		motorsRight.setM1Speed(inSpeed*-1);
		//motor 2 forward
		motorsRight.setM2Speed(inSpeed);
		//motor 3 backwards
		motorsLeft.setM1Speed(inSpeed*-1);
		//motor 4 forward
		motorsLeft.setM2Speed(inSpeed);	
	}
	
	void WalnutBase::rotateRobotRight(int inSpeed){
	   //motor 1 forward
		motorsRight.setM1Speed(inSpeed);
		//motor 2 forward
		motorsRight.setM2Speed(inSpeed);
		//motor 3 backwards
		motorsLeft.setM1Speed(inSpeed*-1);
		//motor 4 backwards
		motorsLeft.setM2Speed(inSpeed*-1);	
    }
	
	void WalnutBase::rotateRobotLeft(int inSpeed){
	  //motor 1 backwards
		motorsRight.setM1Speed(inSpeed*-1);
		//motor 2 backwards
		motorsRight.setM2Speed(inSpeed*-1);
		//motor 3 forward
		motorsLeft.setM1Speed(inSpeed);
		//motor 4 forward
		motorsLeft.setM2Speed(inSpeed);	
    }
