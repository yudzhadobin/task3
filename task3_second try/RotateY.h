#pragma once
#include "MyMatrix.h"

using namespace System;

ref class RotateY :
	public MyMatrix<double>
{
public:
	RotateY(int angle);
};

