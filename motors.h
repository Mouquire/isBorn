
#ifndef motors
#define motors

#include <Arduino.h>

#include "_init.h"
#include "serial.h"

typedef struct Motor_S {
	const int FORWARD_PIN;
	const int BACKWARD_PIN;
	int speed = 0;
	bool direction = FORWARDS;
	int lastSpeed = 0;
	bool lastDirection = FORWARDS;
	int liner = 0;

	Motors_S(int forwardPin, int backwardPin) :
		FORWARD_PIN(forwardPin),
		BACKWARD_PIN(backwardPin)
	{};
};

class Motors_C {
	public:
		Motors_C();
		void init();
		void move(Serial_C& Serial_);

	private:
		Motor_S motor[10] = {
			Motor_S(MOTOR0_FORWARD_PIN, MOTOR0_BACKWARD_PIN),
			Motor_S(MOTOR1_FORWARD_PIN, MOTOR1_BACKWARD_PIN),
			Motor_S(MOTOR2_FORWARD_PIN, MOTOR2_BACKWARD_PIN),
			Motor_S(MOTOR3_FORWARD_PIN, MOTOR3_BACKWARD_PIN),
			Motor_S(MOTOR4_FORWARD_PIN, MOTOR4_BACKWARD_PIN),
			Motor_S(MOTOR5_FORWARD_PIN, MOTOR5_BACKWARD_PIN),
			Motor_S(MOTOR6_FORWARD_PIN, MOTOR6_BACKWARD_PIN),
			Motor_S(MOTOR7_FORWARD_PIN, MOTOR7_BACKWARD_PIN),
			Motor_S(MOTOR8_FORWARD_PIN, MOTOR8_BACKWARD_PIN),
			Motor_S(MOTOR9_FORWARD_PIN, MOTOR9_BACKWARD_PIN)
		};
};

#endif