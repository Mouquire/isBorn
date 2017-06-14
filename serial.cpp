
// void loop()
// {

// if (Serial.available() > 0)

// 	String message = Serial.read();

// 	int directionIndex = message.indexOf(' ') + 1;
// 	int speedIndex = message.lastIndexOf(' ') + 1;

// 	int motorNumber = message.substring(0, directionIndex - 1).toInt();
// 	String direction = message.substring(directionIndex, speedIndex - 1).trim();
// 	String speed = message.substring(speedIndex).toInt();

	



// 	this->ip = cache.substring(ipIndex, routeIndex - 1);
// 	this->ip.trim();
// 	this->route = cache.substring(routeIndex, valueIndex);
// 	this->route.trim();
// 	this->value = cache.substring(valueIndex).toInt();

// 	// some little debug never hurt
// 	Serial.print("OSC ");
// 	Serial.print(this->ip);
// 	Serial.print(" ");
// 	Serial.print(this->route);
// 	Serial.print(" ");
// 	Serial.println(this->value);
// }