#ifndef force_sensing
#define force_sensing
#include "../main.h"
#include "../../mbed-os/drivers/AnalogIn.h"

class ForceSense{
private:

	float forceArray[12];
	float returnValues[3];

	int j = 0;

public:
	ForceSense();

	float * readForce();
};

#endif
