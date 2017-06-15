#ifndef serial
#define serial

#include <Arduino.h>

#include "_init.h"


class Serial_C 

{

public: 
void receive();
Serial_C();

private:
int motorNumber;
int speed;
void mapValues();


}

#endif