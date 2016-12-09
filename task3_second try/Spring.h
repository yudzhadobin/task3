#pragma once
#include "My3DObject.h"

using namespace System;

ref class Spring :
	public My3DObject
{


private:
	int R = 100;
	int r = 50;

public:
	Spring(int step_graduses);

private:
	void init(int step_graduses);


};

