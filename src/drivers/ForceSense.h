#ifndef ForceSense
#define ForceSense
#include "../main.h"

class ForceSense {
private:

	AnalogIn force1(LOAD_1);
	AnalogIn force2(LOAD_2);
	AnalogIn force3(LOAD_3);

public:
	ForceSense(){

	}

	float readForce(int sensor);
};

#endif
