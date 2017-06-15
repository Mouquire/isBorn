#include "serial.h"

Serial_C::Serial_C() :
motorNumber(NULL), 
speed(0),
direction(FORWARDS)
{}

void Serial_C::updateMessage ()

{
	String message = Serial.readStringUntil('\n');


	this->motorNumber = message.substring(0, directionIndex - 1).toInt();
	String directionMessage = message.substring(directionIndex, speedIndex - 1).trim();
	this->speed = message.substring(speedIndex).toInt();


	if(directionMessage == "F")
	
	{ 
		this->direction = FORWARDS;
 
	}


	else if(directionMessage == "B")
	
	{ 
		this->direction = BACKWARDS;
 
	}
}

