#include <SPI.h>  
#include <Pixy.h>
#include"RobotPixy.h"



RobotPixy::RobotPixy(void) {
  myPixy.init();
 }

void RobotPixy::getData(){  
  blocks = myPixy.getBlocks();  
 } 

int RobotPixy::getArea(int requiredSignature){
   getData();
   int temp =0;
	if (blocks){    
      for (int j=0; j<blocks; j++){
		if (myPixy.blocks[j].signature == requiredSignature){
      for (int i = 0;i<10;i++){		
			 temp = temp + myPixy.blocks[j].width*myPixy.blocks[j].height;
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

int RobotPixy::getX(int requiredSignature){
  getData();
	if (blocks){      
      for (int j=0; j<blocks; j++){ 
		if (myPixy.blocks[j].signature == requiredSignature)
			return myPixy.blocks[j].x;       
		}
		}else{
			return -1;
		}	
	}

bool RobotPixy::isInFront(int requiredSignature){
   getData();
	if (blocks){      
      for (int j=0; j<blocks; j++){  
		if(myPixy.blocks[j].x > 120 && myPixy.blocks[j].x < 180 && myPixy.blocks[j].signature == requiredSignature){
			return true;      
		}else{
			return false;
			}
	  }		
	}else {
		return -1;
	}
}



