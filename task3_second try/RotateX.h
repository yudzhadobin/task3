#pragma once
#include "MyMatrix.h"

using namespace System;
ref class RotateX :
	public MyMatrix<double>
{
public:
	RotateX(int angle);
};

