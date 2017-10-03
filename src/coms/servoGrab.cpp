/*
 * ComProtocol.cpp
 *
 *  Created on: Sep 2, 2017
 *      Author: dpwivagg
 */

#include "servoGrab.h"

Servo servo1(PF_7, 30);

void servoGrab::event(float * buffer){

    // read values from the packet buffer
	servoState = buffer[0];

	servo1 = servoState;

	float currentPos = servo1.read();

	buffer[0] = currentPos;
}



