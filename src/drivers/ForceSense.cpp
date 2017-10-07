#include "ForceSense.h"


AnalogIn force1(PA_3);
AnalogIn force2(PC_0);
AnalogIn force3(PC_3);

ForceSense::ForceSense(){

	forceArray[0] = force1.read();
	forceArray[1] = force1.read();
	forceArray[2] = force1.read();
	forceArray[3] = force1.read();
	forceArray[4] = force1.read();
	forceArray[5] = force1.read();
	forceArray[6] = force2.read();
	forceArray[7] = force2.read();
	forceArray[8] = force2.read();
	forceArray[9] = force2.read();
	forceArray[10] = force2.read();
	forceArray[11] = force2.read();
	forceArray[12] = force3.read();
	forceArray[13] = force3.read();
	forceArray[14] = force3.read();
	forceArray[15] = force3.read();
	forceArray[16] = force3.read();
	forceArray[17] = force3.read();

}

float * ForceSense::readForce() {

	// First, update the array with current values
	forceArray[j] = force1;
	forceArray[j+6] = force2;
	forceArray[j+12] = force3;
	j++;
	if(j>5) j = 0;

	// Now, compute averages and store them

	returnValues[0] = (forceArray[0] + forceArray[1] +
				forceArray[2] + forceArray[3] + forceArray[4] + forceArray[5]) / 6;
	returnValues[1] = (forceArray[6] + forceArray[7] +
				forceArray[8] + forceArray[9] + forceArray[10] + forceArray[11]) / 6;
	returnValues[2] = (forceArray[12] + forceArray[13] +
				forceArray[14] + forceArray[15] + forceArray[16] + forceArray[17]) / 6;

	// Convert the values to a digital 12-bit value
	returnValues[0] = returnValues[0] * 4095;
	returnValues[1] = returnValues[1] * 4095;
	returnValues[2] = returnValues[2] * 4095;

	// Convert those 12-bit values to an applied load in Newtons
	returnValues[0] = (returnValues[0]- 1960) / 178.5;
	returnValues[1] = (returnValues[1]- 2016) / 178.5;
	returnValues[2] = (returnValues[2]- 1860) / 178.5;


	// Let's return a pointer to this array so we can access
	// all the values at once

	return &returnValues[0];

}
