#pragma once
#include "MyMatrix.h"
#include "Side.h"
#include "Projector.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

ref class My3DObject
{
public:
	int centerX;
	int centerY;
	List<List<double>^>^ local_points;
	List<List<double>^>^ normals;
	List<List<double>^>^ global_normals;

	List<List<int>^>^ global_points;
	List<Side^>^ sides;

private:
	const double diffuseReflectionCoef = 0.5;
	const int lightIntensity = 1;
	int light_x = 100;
	int light_y = 100;
	int light_z = 100;



public:
	My3DObject();

	MyMatrix<double>^ ToMatrix();

	void Draw(List<Side^>^ sides, Bitmap^ bitmap, MyMatrix<double>^ proectMatrix);

	MyMatrix<double>^ GetObjectMatrix();

	List<int>^ GetMedianPoint();

	void MoveToGlobal(MyMatrix<double>^ rotateX, MyMatrix<double>^ rotateY, MyMatrix<double>^ rotateZ, int x, int y, int z);
	void MoveToGlobal();
	MyMatrix<double>^ ToMatrixGlobalPoints();

private:
	double calculateIntensity(Side^ side);
};

