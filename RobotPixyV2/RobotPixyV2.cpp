#include"RobotPixyV2.h"



RobotPixyV2::RobotPixyV2(void) {
  myPixy.init();
 }

void RobotPixyV2::getData(){  
  blocks = myPixy.ccc.getBlocks();  
 } 

int RobotPixyV2::getArea(int requiredSignature){
   getData();
   int temp =0;
	if (blocks){    
      for (int j=0; j<blocks; j++){
		if (myPixy.ccc.blocks[j].signature == requiredSignature){
      for (int i = 0;i<10;i++){		
			 temp = temp + myPixy.ccc.blocks[j].width*myPixy.ccc.blocks[j].height;
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

int RobotPixyV2::getX(int requiredSignature){
  getData();
	if (blocks){      
      for (int j=0; j<blocks; j++){ 
		if (myPixy.ccc.blocks[j].signature == requiredSignature)
			return myPixy.ccc.blocks[j].x;       
		}
		}else{
			return -1;
		}	
	}
	
int RobotPixyV2::getY(int requiredSignature){
  getData();
	if (blocks){      
      for (int j=0; j<blocks; j++){ 
		if (myPixy.ccc.blocks[j].signature == requiredSignature)
			return myPixy.ccc.blocks[j].y;       
		}
		}else{
			return -1;
		}	
	}

bool RobotPixyV2::isInFront(int requiredSignature){
   getData();
	if (blocks){      
      for (int j=0; j<blocks; j++){  
		if(myPixy.ccc.blocks[j].x > 135 && myPixy.ccc.blocks[j].x < 180 && myPixy.ccc.blocks[j].signature == requiredSignature){
			return true;      
		}else{
			return false;
			}
	  }		
	}else {
		return -1;
	}
}

void RobotPixyV2::lightsOn(){
	myPixy.setLamp(true,true);	
}
void RobotPixyV2::lightsOff(){
	myPixy.setLamp(false,false);	
}
