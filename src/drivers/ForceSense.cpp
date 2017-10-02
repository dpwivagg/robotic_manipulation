#include "ForceSense.h"

AnalogIn force1(PA_3);
AnalogIn force2(PC_0);
AnalogIn force3(PC_3);

ForceSense::ForceSense(){

	forceArray[0] = force1.read();
	forceArray[1] = force1.read();
	forceArray[2] = force1.read();
	forceArray[3] = force1.read();
	forceArray[4] = force2.read();
	forceArray[5] = force2.read();
	forceArray[6] = force2.read();
	forceArray[7] = force2.read();
	forceArray[8] = force3.read();
	forceArray[9] = force3.read();
	forceArray[10] = force3.read();
	forceArray[11] = force3.read();

}

float * ForceSense::readForce() {

	// First, update the array with current values
	forceArray[j] = force1;
	forceArray[j+4] = force2;
	forceArray[j+8] = force3;
	j++;
	if(j>3) j = 0;

	// Now, compute averages and store them

	returnValues[0] = (forceArray[0] + forceArray[1] +
				forceArray[2] + forceArray[3]) / 4;
	returnValues[1] = (forceArray[4] + forceArray[5] +
				forceArray[6] + forceArray[7]) / 4;
	returnValues[2] = (forceArray[8] + forceArray[9] +
				forceArray[10] + forceArray[11]) / 4;

	// Let's return a pointer to this array so we can access
	// all the values at once

	return &returnValues[0];

}
