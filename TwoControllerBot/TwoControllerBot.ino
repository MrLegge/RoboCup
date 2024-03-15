#include "TwoControllerBase.h"
/*******************************************************
 * These comands all need to go into the loop function
 * Values you can use in setting the motor values:
 * 
 *   myBase->MAX_SPEED = 255; 
 *   myBase->THREE_QUARTER_SPEED = 138; 
 *   myBase->HALF_SPEED = 92; 
 *   myBase->QUARTER_SPEED = 46;  
 *   myBase->MIN_SPEED = 15; 
 *   eg. myBase->driveForward(myBase->MAX_SPEED, myBase->MAX_SPEED);
 * 
 * Functions you can call to make the Robot drive: 
 * 
 *   driveForward(rightWheelValue, leftWheelValue);
 *   driveBackward(rightWheelValue, leftWheelValue);
 *   rotateRight(turnSpeed);
 *   rotateLeft(turnSpeed);
 *   eg. myBase->rotateRight(myBase->HALF_SPEED);
 ******************************************************/

//#include "RobotPixy.h"

/*******************************************************
 * These comands all need to go into the loop function
 * Functions you can call to get data from the PixyCam:
 * 
 *    isInFront(ball);  
 *      this function is a boolean so returns true or false
 *      and can be used like: 
 *    if(myPixy->isInFront(ball){
 *      some code
 *    }else{
 *      some other code
 *    }
 *    
 *    getX(goal);
 *      this function returns a number relating to the x 
 *      position of the object and can be used like: 
 *    
 *    if(myPixy->getX(goal) < 120){
 *      rotateLeft(myBase->HALF_SPEED);
 *    }
 *    or
 *    if(myPixy->getX(goal) < 120 && !isInFront(goal)){
 *      rotateLeft(myBase->HALF_SPEED);
 *    }else {
 *      rotateRight(myBase->HALF_SPEED);
 *    }
 *    
 *    getArea(ownGoal);
 *      this function returns the area of the object chosen  
 *      and can be used like this:
 *      
 *     if(myPixy->getArea(ownGoal)> 2000){
 *        some code to save the ball because you are close to your own goal
 *     }
 *    
 * *****************************************************/
 
TwoControllerBase *myBase;
//RobotPixy *myPixy;
int ball, goal, ownGoal;

void setup(){
	// the code you write in here runs once at the very start of the program
	myBase = new TwoControllerBase();
	//myPixy = new RobotPixy();
	ball = 1;
	goal = 2;
	ownGoal = 3;
  }

  void loop(){
    // all the code you write in here will run over and over 50 times per second
	
    myBase->driveForward(myBase->MAX_SPEED);
    
  }
