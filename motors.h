
#ifndef motors
#define motors

#include <Arduino.h>

#include "_init.h"
#include "serial.h"

typedef struct Motor_ 

{
	const int FORWARD_PIN;
	const int BACKWARD_PIN;
	int speed;

	Motor_(int forwardPin, int backwardPin) : //contructeur du typedef
		FORWARD_PIN(forwardPin),
		BACKWARD_PIN(backwardPin),
		speed(0)
	{}
};

class Motors_C {
	public:
		Motors_C();
		void init();
		void move(Serial_C& serial);

	private:
		Motor_ motor[10] = //Motor_ est un type de variable définis avec un structure dans le typedef 

		{
			Motor_(MOTOR0_FORWARD_PIN, MOTOR0_BACKWARD_PIN),
			Motor_(MOTOR1_FORWARD_PIN, MOTOR1_BACKWARD_PIN),
			Motor_(MOTOR2_FORWARD_PIN, MOTOR2_BACKWARD_PIN),
			Motor_(MOTOR3_FORWARD_PIN, MOTOR3_BACKWARD_PIN),
			Motor_(MOTOR4_FORWARD_PIN, MOTOR4_BACKWARD_PIN),
			Motor_(MOTOR5_FORWARD_PIN, MOTOR5_BACKWARD_PIN),
			Motor_(MOTOR6_FORWARD_PIN, MOTOR6_BACKWARD_PIN),
			Motor_(MOTOR7_FORWARD_PIN, MOTOR7_BACKWARD_PIN),
			Motor_(MOTOR8_FORWARD_PIN, MOTOR8_BACKWARD_PIN),
			Motor_(MOTOR9_FORWARD_PIN, MOTOR9_BACKWARD_PIN)
		};
		int motorIdToUpdate;
		void updateDirectionAndSpeed(Serial_C message);
		void triggerMotion();
};

#endif