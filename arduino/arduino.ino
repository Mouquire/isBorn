
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
	if (Serial.available()) {
		serial_.receive();
	}

	motors_.move(serial_);
}