
#include "_init.h"
#include "motors.h"
#include "serial.h"

Serial_C serial_;
Motors_C motors_;

void setup() {
	Serial.begin(115200);

	motors_.init();
}

void loop() {
	motors_.move();
}

void serialEvent() {
	serial_.receive();
}