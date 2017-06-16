#ifndef serial
#define serial

#include <Arduino.h>

#include "_init.h"

class Serial_C

{
	public: 
	void receive();
	Serial_C();
	int getSpeed();
	int getMotorId();
	void clean();
	
	private:
	int motorId;
	int speed;
	void mapValues();
};

#endif