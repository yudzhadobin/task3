#pragma once
#include "My3DObject.h"
ref class Garlic :
	public My3DObject
{
public:
	int R = 100;
	int step_graduses = 30;
	int graduses = 360;
	Garlic();

private:
	void init();


};

