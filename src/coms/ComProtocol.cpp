/*
 * ComProtocol.cpp
 *
 *  Created on: Sep 2, 2017
 *      Author: dpwivagg
 */

#include "ComProtocol.h"

static float lastPosition[3] = {0,0,0};

// An array that contains the normal error for each link
// i.e., how much to subtract from encoder value to reach "Home" position
static float homingArray[3] = {-225,-42,773};


void ComProtocol::event(float * buffer){
  //printf("\nPid Server Event");
  bool skipLink = false;
  for(int i=0; i<myPumberOfPidChannels;i++){

    float position = myPidObjects[i]->GetPIDPosition();

    // read values from the packet buffer
    float setpoint        = buffer[(i*3)+0];
    setpoint = setpoint + homingArray[i];
    float velocityTarget  = buffer[(i*3)+1];
    float forceTarget     = buffer[(i*3)+2];

    //perform state update
    float timeOfMotion=0;
    if(velocityTarget>0)
     timeOfMotion=(std::abs(setpoint-position)/velocityTarget)*1000;// convert from Tics per second to miliseconds

	bool newUpdate = !myPidObjects[i]->bound(setpoint,
      myPidObjects[i]->state.interpolate.set,
      0.01,
     0.01);
    // printf("\n  data index %i position = %f setpoint = %f target = %f update = %i time = %f",
    // i,
    // position,
    // setpoint,
    // myPidObjects[i]->state.SetPoint,
    // newUpdate,
    // timeOfMotion
    // );

    if(newUpdate){

      __disable_irq();    // Disable Interrupts
      myPidObjects[i]->SetPIDEnabled( true);
      myPidObjects[i]->SetPIDTimed(setpoint, timeOfMotion);// go to setpoint in timeBetweenPrints ms, linear interpolation
      __enable_irq();
      // printf("\n Index %i Interpolation Set = %f ,  Start = %f , setTime = %f , startTime = %f",
      // i,
      // myPidObjects[i]->state.interpolate.set,
      // myPidObjects[i]->state.interpolate.start,
      // myPidObjects[i]->state.interpolate.setTime,
      // myPidObjects[i]->state.interpolate.startTime
      // );
   }else{
    //  printf("\r\nPacket write ignored, index %i to %f is already %f",i,setpoint,myPidObjects[i]->state.interpolate.set);
     skipLink=true;
   }
  //  if(skipLink){
  //    for (int i=0;i<15;i++){
  //      printf("\r\nPacket write ignored, value %i to %f ",i,buffer[i]);
  //    }
   //}
  }
  uint8_t * buff = (uint8_t *)buffer;
  for(int i=4; i<60;i++){
    buff[i]=0;
  }
  // Update the force sensor readings
  float *readings = sensors.readForce();
  //printf("\nPid Server Event");ComProtocol
  for(int i=0; i<myPumberOfPidChannels;i++){

    float position = myPidObjects[i]->GetPIDPosition();
    position = position - homingArray[i];
    float velocity = (position - lastPosition[i]) * 400;
    float torque = readings[i];
    // write upstream packets
    buffer[(i*3)+0] = position;
    buffer[(i*3)+1] = velocity;
    buffer[(i*3)+2] = torque;

    if(myPidObjects[i]->isPIDArrivedAtSetpoint(20))
    	buffer[9+i] = 1;
    else buffer[9+i] = 0;

    lastPosition[i] = position;
  }

  // for(int i=0; i<15;i++){
  //
  //   buffer[i]=i+0.01;
  //
  // }
}



