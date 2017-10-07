#ifndef force_sensing
#define force_sensing
#include "../../mbed-os/drivers/AnalogIn.h"
#include "AS5050.h"
#include "mbed.h"

class ForceSense{
private:

	float forceArray[18];
	float returnValues[3];

	int j = 0;

public:
	ForceSense();

	float * readForce();
};

#endif
