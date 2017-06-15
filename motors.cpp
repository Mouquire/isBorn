
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

// this->scaleSpeed(); // Pour Hina et Victoire : Écrire la fonction scaleSpeed qui empèche les valeurs de déborder (moteur 0 < 9 ; vitesse 0 < 100 ; direction F || B)
// // /!\, à mettre dans serial.cpp

// void Serial_C::scaleSpeed() {
// 	if(this->motorId != NULL) {
// 		if(this->speed < -100) {
// 			this->speed = -100;
// 		} else if (this->speed > 100) {
// 			this->speed = 100;
// 		}

// 		if(this->speed < 0) {
// 			int sign = -1;
// 		} else {
// 			int sign = 1;
// 		}

// 		this->speed = map(abs(this->speed), 0, 100, MIN_SPEED, MAX_SPEED) * sign;
// 	}
// }
