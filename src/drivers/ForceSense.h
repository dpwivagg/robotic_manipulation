#ifndef ForceSense
#define ForceSense
#include "../main.h"

class ForceSense{
private:

	AnalogIn force1(LOAD_1);
	AnalogIn force2(LOAD_2);
	AnalogIn force3(LOAD_3);

	float forceArray[12];
	float returnValues[3];

	int j = 0;

public:
	ForceSense();

	float * readForce();
};

#endif
