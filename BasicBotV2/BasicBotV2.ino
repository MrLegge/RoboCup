#include "BasicBotBase.h"
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
 #include <Pixy2.h>
/*******************************************************
* to use the pixy V2 you will need call the functions 
* below and use the myPixy stuff eg:
* 
********************************************************/
 

 
BasicBotBase *myBase;
Pixy2 myPixy;
int ball, goal, ownGoal;
uint16_t blocks;

void setup(){
	// the code you write in here runs once at the very start of the program
	myBase = new BasicBotBase();
  myPixy.init();
	ball = 1;
	goal = 2;
	ownGoal = 3;
  Serial.begin(9600);
  }

  void loop(){
    // all the code you write in here will run over and over 50 times per second
	
    myBase->driveForward(myBase->MAX_SPEED, myBase->MAX_SPEED);

    //the code following this is just test code to sample the output from the pixy V2
    lightsOn();
    Serial.print("this is the x value:  ");Serial.println(getX(1));
    delay(500);
    Serial.print("this is the y value:  ");Serial.println(getY(1));
    delay(500);
    Serial.print("this will display if in front:  ");Serial.println(isInFront(1));
    delay(500);
    Serial.print("this is the area value:  ");Serial.println(getArea(1));
    delay(500);
    lightsOff();
    delay(1000);
  }

int getX(int requiredSignature){
  getData();
  if (myPixy.ccc.numBlocks){      
      for (int j=0; j<myPixy.ccc.numBlocks; j++){ 
    if (myPixy.ccc.blocks[j].m_signature == requiredSignature)
      return myPixy.ccc.blocks[j].m_x;       
    }
    }else{
      return -1;
    } 
  }
  
int getY(int requiredSignature){
  getData();
  if (myPixy.ccc.numBlocks){      
      for (int j=0; j<myPixy.ccc.numBlocks; j++){ 
    if (myPixy.ccc.blocks[j].m_signature == requiredSignature)
      return myPixy.ccc.blocks[j].m_y;       
    }
    }else{
      return -1;
    } 
  }

bool isInFront(int requiredSignature){
   getData();
  if (myPixy.ccc.numBlocks){      
      for (int j=0; j<myPixy.ccc.numBlocks; j++){  
    if(myPixy.ccc.blocks[j].m_x > 120 && myPixy.ccc.blocks[j].m_x < 180 && myPixy.ccc.blocks[j].m_signature == requiredSignature){
      return true;      
    }else{
      return false;
      }
    }   
  }else {
    return -1;
  }
}

void lightsOn(){
  myPixy.setLamp(true,true);  
}
void lightsOff(){
  myPixy.setLamp(false,false);  
}

int getArea(int requiredSignature){
   getData();
   int temp =0;
  if (myPixy.ccc.numBlocks){    
      for (int j=0; j<myPixy.ccc.numBlocks; j++){
    if (myPixy.ccc.blocks[j].m_signature == requiredSignature){
      for (int i = 0;i<10;i++){   
       temp = temp + myPixy.ccc.blocks[j].m_width*myPixy.ccc.blocks[j].m_height;
      }
      if (temp<0){
        temp=temp*-1;
        }
      return temp/10;
    }
    else
      return 0;
    }
  }else{
      return -1;
    } 
}
  void getData(){  
  blocks = myPixy.ccc.getBlocks();  
 } 
