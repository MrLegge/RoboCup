#include "RobotIRSeeker.h"

	void RobotIRSeeker::Initialize(){
		Wire.begin();
		Wire.beginTransmission(RobotIRSeeker::Address);
		Wire.write(0x00);
		Wire.endTransmission();
		while(Wire.available() > 0)
			Wire.read();
	}

	boolean RobotIRSeeker::Test(){
		Wire.beginTransmission(RobotIRSeeker::Address);
		Wire.write(0x08);
		Wire.endTransmission();
		Wire.requestFrom(RobotIRSeeker::Address, 16);
		char Manufacturer_Model[16];
		while(Wire.available() < 16);
		for(byte i=0; i < 16; i++){
			Manufacturer_Model[i] = Wire.read();
		}
		while(Wire.available() > 0)
			Wire.read();
		return strncmp(Manufacturer_Model, "HiTechncNewIRDir", 16)==0;
	}

	void RobotIRSeeker::ReadValues(byte OffsetAddress, byte* buffer){
		Wire.beginTransmission(RobotIRSeeker::Address);
		Wire.write(OffsetAddress);
		Wire.endTransmission();
		Wire.requestFrom(RobotIRSeeker::Address, 6);
		while(Wire.available() < 6);
		for(byte i = 0; i < 6; i++){
			buffer[i] = Wire.read();
		}
		while(Wire.available() > 0)
			Wire.read();
	}

	void RobotIRSeeker::ReadACRaw(byte* buffer){
		ReadValues(0x49, buffer);
	}

	void RobotIRSeeker::ReadDCRaw(byte* buffer){
		ReadValues(0x42, buffer);
	}

	InfraredResult RobotIRSeeker::PopulateValues(byte* buffer){
		InfraredResult Data;
		Data.Direction = buffer[0];
		if(buffer[0] != 0){
			if(buffer[0] % 2 == 0){
				Data.Strength = (buffer[buffer[0] / 2] + buffer[buffer[0] / 2 + 1]) / 2;
			}else{
				Data.Strength = buffer[buffer[0] / 2 + 1];
			}
		}else{
			Data.Strength = 0;
		}
		return Data;
	}

	InfraredResult RobotIRSeeker::ReadAC(){
		byte buffer[6];
		ReadACRaw(buffer);
		return PopulateValues(buffer);
	}

InfraredResult RobotIRSeeker::ReadDC(){
	byte buffer[6];
	ReadDCRaw(buffer);
	return PopulateValues(buffer);
	}

	int RobotIRSeeker::DirectionAngle(byte Direction){
		return Direction * 30 - 150;
	}

	/*void setup(){
		Serial.begin(9600);
		Serial.println("HiTechnic IRSeeker V2");
		Serial.println();
		Serial.println();
		Serial.println("Dir\tAngle\tStrength");
		Serial.println();
		RobotIRSeeker::Initialize();
	}

	void loop(){   
		InfraredResult InfraredBall = RobotIRSeeker::ReadAC();
		Serial.print(InfraredBall.Direction);
		Serial.print("\t");
		Serial.print(DirectionAngle(InfraredBall.Direction));
		Serial.print("\t");
		Serial.print(InfraredBall.Strength);
		Serial.println();
		delay(100); //optional
	}*/
