#include "serial.h"

Serial_C::Serial_C() :
motorId(NULL), 
speed(0)
{}



void Serial_C::receive()

{
	String message = Serial.readStringUntil('\n');

	if (message.indexOf("MAX") != -1) 

	{
		int motorIdIndex = message.index0f(' ') + 1;
		int speedIndex = message.lastIndexOf(' ') + 1;
		
		this->motorId = message.substring(motorIdIndex, speedIndex - 1).toInt();
		this->speed = message.substring(speedIndex).toInt();

		this->mapValues();
	}
}

void Serial_C::mapValues()

{
	if( this->speed < -100 )
	{ 
		this->speed = -100;
	}

	else if(this->speed > 100)
	{ 
		this->speed = 100;
	}

	this->speed = map(this->speed, -100, -255, 100, 255);

	if( this->motorId < 0 )
	{ 
		this->motorId = 0;
	}

	else if(this->motorId > 9)
	{ 
		this->motorId = 9 ;
	}
}

int Serial_C::getSpeed()

{
	return this->speed;
}


int Serial_C::getMotorId()

{
	return this->motorId;
}
