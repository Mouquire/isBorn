
#include "motors.h"

Motors_C::Motors_C() :
	motorIdToUpdate(NULL)
{}

void Motors_C::init() {
	// Pour Victoire et Hina : Initialiser les moteurs avec pinMode
}

void Motors_C::move(Serial_& message) {
	this->updateDirectionAndSpeed(message);
	this->triggerMotion();
}

void Motors_C::updateDirectionAndSpeed(Serial_ message) {
	int id = message.getMotorId();

	if(id != NULL)
		this->motorIdToUpdate = id;
		this->motor[id].speed = message.getSpeed();
		message.clean();
	}


void Motors_C::triggerMotion() {
	int id = this->motorIdToUpdate;

	if(id != NULL) {
		if(this->motor[id].speed > 0) {
			analogWrite(this->motor[id].FORWARD_PIN, this->motor[id].speed);
			analogWrite(this->motor[id].BACKWARD_PIN, 0);
		} else if (this->motor[id].speed < 0) {
			analogWrite(this->motor[id].FORWARD_PIN, 0);
			analogWrite(this->motor[id].BACKWARD_PIN, -this->motor[id].speed);
		} else {
			analogWrite(this->motor[id].FORWARD_PIN, 0);
			analogWrite(this->motor[id].BACKWARD_PIN, 0);
		}

		this->motorIdToUpdate = NULL;
	}
}
