/*
 * ComProtocol.cpp
 *
 *  Created on: Sep 2, 2017
 *      Author: dpwivagg
 */

#include "pidProtocol.h"


void pidProtocol::event(float * buffer){
	//printf("\nPid Server Event");
	for(int i=0; i<myPumberOfPidChannels;i++){
		// read values from the packet buffer
		float kpIn = buffer[(i*3)+0];
		float kiIn = buffer[(i*3)+1];
		float kdIn = buffer[(i*3)+2];

		//perform state update

		__disable_irq();    // Disable Interrupts
		myPidObjects[i]->setPIDConstants(kpIn, kiIn, kdIn);
		__enable_irq();

	}
	uint8_t * buff = (uint8_t *)buffer;
	for(int i=4; i<60;i++){
		buff[i]=0;
	}
	//printf("\nPid Server Event");ComProtocol
	for(int i=0; i<myPumberOfPidChannels;i++){
		// write upstream packets
		buffer[(i*3)+0] = 0xFFFF;
		buffer[(i*3)+1] = 0xFFFF;
		buffer[(i*3)+2] = 0xFFFF;
	}

	// for(int i=0; i<15;i++){
	//
	//   buffer[i]=i+0.01;
	//
	// }
}



