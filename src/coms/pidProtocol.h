/*
 * pidProtocol.h
 *
 *  Created on: Sep 12, 2017
 *      Author: dpwivagg
 */

#ifndef  Pid_server3
#define Pid_server3
#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"\
//#include "AnalogOut.h"
#include <cmath>        // std::abs

class pidProtocol: public PacketEventAbstract{
private:
  PIDBowler* * myPidObjects;
   int myPumberOfPidChannels;
public:
  // Packet ID needs to be set
  pidProtocol (PIDBowler* * pidObjects, int numberOfPidChannels )
   : PacketEventAbstract( 39){
    myPidObjects=pidObjects;
    myPumberOfPidChannels=numberOfPidChannels;
  }
  //User function to be called when a packet comes in
  // Buffer contains data from the packet coming in at the start of the function
  // User data is written into the buffer to send it back
  void event(float * buffer);
};


#endif /* end of include guard: Pid_server */
