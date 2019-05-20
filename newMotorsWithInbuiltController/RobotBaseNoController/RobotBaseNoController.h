#ifndef RobotBaseNoController_H
#define RobotBaseNoController_H


class RobotBaseNoController{
	public:
		const int MAX_SPEED = 255; 
		const int THREE_QUARTER_SPEED = 138; 
		const int HALF_SPEED = 92; 
		const int QUARTER_SPEED = 46;  
		const int MIN_SPEED = 15; 
		
		RobotBaseNoController();
		
		void driveForward(unsigned short rightWheel, unsigned short leftWheel);
		void driveBackward(unsigned short rightWheel, unsigned short leftWheel);
		void rotateRight(unsigned short turnSpeed);
		void rotateLeft(unsigned short turnSpeed);
		void stopMotors();
		
	private:
		int i, rightPWM, leftPWM, rightDirectionPin, leftDirectionPin, rightSignalPin, leftSignalPin;
		unsigned long time;
		bool flag; 
	
};

#endif 
