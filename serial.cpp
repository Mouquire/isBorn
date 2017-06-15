#include "serial.h"

Serial_C::Serial_C() :
motorNumber(NULL), 
speed(0)
{}



void Serial_C::receive()

{
	String message = Serial.readStringUntil('\n');

	if (message.indexOf("MAX") != -1) 

	{
		int motorNumberIndex = message.index0f(' ') + 1;
		int speedIndex = message.lastIndexOf(' ') + 1;
		
		this->motorNumber = message.substring(motorNumberIndex, speedIndex - 1).toInt();
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

	if( this->motorNumber < 0 )
	{ 
		this->motorNumber = 0;
	}

	else if(this->motorNumber > 9)
	{ 
		this->motorNumber = 9 ;
	}
}


