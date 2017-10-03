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

	if(servoState = 100) {
		servo1.write(1);
		// servo open
	}
	else if(servoState = 75) {
		servo1.write(1.75);
		// servo close
	}

	buffer[0] = 0;
}



