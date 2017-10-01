/*
 * ComProtocol.h
 *
 *  Created on: Sep 2, 2017
 *      Author: dpwivagg
 */

#ifndef  Pid_server2
#define Pid_server2
#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>        // std::abs

class ComProtocol: public PacketEventAbstract{
private:
  PIDBowler* * myPidObjects;
   int myPumberOfPidChannels;
//   AnalogOut dacout(PA_5);
public:
  // Packet ID needs to be set
  ComProtocol (PIDBowler* * pidObjects, int numberOfPidChannels )
   : PacketEventAbstract( 38){
    myPidObjects=pidObjects;
    myPumberOfPidChannels=numberOfPidChannels;
  }
  //User function to be called when a packet comes in
  // Buffer contains data from the packet coming in at the start of the function
  // User data is written into the buffer to send it back
  void event(float * buffer);
};


#endif /* end of include guard: Pid_server */
