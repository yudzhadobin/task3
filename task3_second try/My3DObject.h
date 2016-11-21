#pragma once
#include "MyMatrix.h"
#include "Side.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

ref class My3DObject
{
public:
	int centerX;
	int centerY;
	List<List<int>^>^ local_points;
	List<Side^>^ sides;
public:
	My3DObject();

	MyMatrix<double>^ ToMatrix();

	void Draw(MyMatrix<double>^ points, List<Side^>^ sides, Bitmap^ bitmap);
};

