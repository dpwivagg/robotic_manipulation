/*
 * ComProtocol.h
 *
 *  Created on: Sep 2, 2017
 *      Author: dpwivagg
 */

#ifndef  servoGrab_1
#define servoGrab_1
#include <PacketEvent.h>
#include <PID_Bowler.h>
#include "AS5050.h"
#include "mbed.h"
#include "Servo.h"

class servoGrab: public PacketEventAbstract{
private:
	float servoState;
public:
  // Packet ID needs to be set
  servoGrab():PacketEventAbstract(48){}
  //User function to be called when a packet comes in
  // Buffer contains data from the packet coming in at the start of the function
  // User data is written into the buffer to send it back
  void event(float * buffer);
};


#endif /* end of include guard: Pid_server */
