#include "ForceSense.h"

ForceSense::ForceSense(){
	forceArray[0] = force1;
	forceArray[1] = force1;
	forceArray[2] = force1;
	forceArray[3] = force1;
	forceArray[4] = force2;
	forceArray[5] = force2;
	forceArray[6] = force2;
	forceArray[7] = force2;
	forceArray[8] = force3;
	forceArray[9] = force3;
	forceArray[10] = force3;
	forceArray[11] = force3;
}

float * ForceSense::readForce(int sensor) {

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

	double *returnForces = &returnValues;

	return returnForces;

}
