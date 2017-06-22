
#include "motors.h"


Motors_C::Motors_C() :
	motorIdToUpdate(NULL)
{}


void Motors_C::init() {
	pinMode (MOTOR0_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR1_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR2_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR3_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR4_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR5_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR6_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR7_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR8_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR9_FORWARD_PIN, OUTPUT);
	pinMode (MOTOR0_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR1_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR2_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR3_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR4_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR5_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR6_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR7_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR8_BACKWARD_PIN, OUTPUT);
	pinMode (MOTOR9_BACKWARD_PIN, OUTPUT);
}


void Motors_C::move(Serial_C& serial_) {
	this->updateSpeed(serial_);
	this->triggerMotion();
}


void Motors_C::updateSpeed(Serial_C serial_) {
	int id = serial_.getMotorId();

	if(id != NULL) {
		this->motorIdToUpdate = id;
		this->motor[id].speed = serial_.getSpeed();
		serial_.clean();

		if(this->motor[id].speed <= 60) {
			this->motor[id].isSlow = true;
			this->motor[id].pulseDuration = map(abs(this->motor[id].speed), 0, 60, 2, 10); //pulse duration calculation
		} else if (this->motor[id].speed > 60) {
			this->motor[id].isSlow = false;
		}
	}
}


void Motors_C::triggerMotion() {
	int id = this->motorIdToUpdate;


	// IF SPEED IS LOW
	for(int i = 0; i < MOTOR_NUMBER; i++) {
		if(!this->motor[i].pulsed) {
			if(this->motor[i].isSlow && millis() - this->motor[i].cacheTime > this->motor[i].pulseDuration) {
				if(this->motor[i].speed > 0) {
					digitalWrite(this->motor[i].FORWARD_PIN, HIGH);
					digitalWrite(this->motor[i].BACKWARD_PIN, LOW);
				} else if (this->motor[i].speed < 0) {
					digitalWrite(this->motor[i].FORWARD_PIN, LOW);
					digitalWrite(this->motor[i].BACKWARD_PIN, HIGH);
				}

				this->motor[i].pulsed = true;
				this->motor[i].cacheTime = millis();
			}
		} else {
			if(this->motor[i].isSlow && millis() - this->motor[i].cacheTime > 20 - this->motor[i].pulseDuration) {
				if(this->motor[i].speed > 0) {
					digitalWrite(this->motor[i].FORWARD_PIN, LOW);
				} else if (this->motor[i].speed < 0) {
					digitalWrite(this->motor[i].BACKWARD_PIN, LOW);
				}

				this->motor[i].pulsed = false;
				this->motor[i].cacheTime = millis();
			}
		}
	}

	// IF SPEED IS NORMAL
	if(id != NULL && !this->motor[id].isSlow) {
		if(this->motor[id].speed > 0) {
			analogWrite(this->motor[id].FORWARD_PIN, this->motor[id].speed); // Vas chercher dans la structure motor (rappel motor[id] est le nom du type Motor_)
			analogWrite(this->motor[id].BACKWARD_PIN, 0);
		} else if (this->motor[id].speed < 0) {
			analogWrite(this->motor[id].FORWARD_PIN, 0);
			analogWrite(this->motor[id].BACKWARD_PIN, -this->motor[id].speed);
		}

		this->motorIdToUpdate = NULL;
	}

	// IF SPEED IS NULL
	if(id != NULL && this->motor[id].speed == 0) {
		digitalWrite(this->motor[id].FORWARD_PIN, 0);
		digitalWrite(this->motor[id].BACKWARD_PIN, 0);
	}
}
