
#ifndef motors
#define motors

#include <Arduino.h>

#include "_init.h"
#include "serial.h"

typedef struct Motor {
	const int FORWARD_PIN;
	const int BACKWARD_PIN;
	int speed;
	bool direction;
	int lastSpeed;
	bool lastDirection;
	int liner;

	Motor(char forwardPin, char backwardPin) :
		FORWARD_PIN(forwardPin),
		BACKWARD_PIN(backwardPin),
		speed(0),
		direction(FORWARDS),
		lastSpeed(0),
		lastDirection(FORWARDS),
		liner(0)
	{}
};

class Motors_C {
	public:
		void init();
		void move(Serial_C& Serial_);

	private:
		Motor motor[10] = {
			Motor(MOTOR0_FORWARD_PIN, MOTOR0_BACKWARD_PIN),
			Motor(MOTOR1_FORWARD_PIN, MOTOR1_BACKWARD_PIN),
			Motor(MOTOR2_FORWARD_PIN, MOTOR2_BACKWARD_PIN),
			Motor(MOTOR3_FORWARD_PIN, MOTOR3_BACKWARD_PIN),
			Motor(MOTOR4_FORWARD_PIN, MOTOR4_BACKWARD_PIN),
			Motor(MOTOR5_FORWARD_PIN, MOTOR5_BACKWARD_PIN),
			Motor(MOTOR6_FORWARD_PIN, MOTOR6_BACKWARD_PIN),
			Motor(MOTOR7_FORWARD_PIN, MOTOR7_BACKWARD_PIN),
			Motor(MOTOR8_FORWARD_PIN, MOTOR8_BACKWARD_PIN),
			Motor(MOTOR9_FORWARD_PIN, MOTOR9_BACKWARD_PIN)
		};
};

#endif