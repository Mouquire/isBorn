#ifndef serial
#define serial

#include <Arduino.h>

#include "_init.h"


class Serial_C 

{

public: 
void updateMessage();
Serial_C ();

private:
int motorNumber;
int speed;

}

#endif