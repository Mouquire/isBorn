#include "serial.h"

Serial_C::Serial_C() :
motorId(NULL), 
speed(0),
message("")
{}

void Serial_C::receive()
{
	char charRead = Serial.read();

	if(charRead != '/') {
		this->message += charRead;
	} else {
		if (this->message.indexOf("MAX") != -1) {
			Serial.println("message : " + this->message);
			int motorIdIndex = this->message.indexOf(' ') + 1;
			int speedIndex = this->message.lastIndexOf(' ') + 1;
			
			this->motorId = this->message.substring(motorIdIndex, speedIndex - 1).toInt();
			this->speed = this->message.substring(speedIndex).toInt();

			this->message = "";

			this->mapValues();
		}
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

void Serial_C::clean() {
	this->motorId = NULL;
	this->speed = 0;
}
