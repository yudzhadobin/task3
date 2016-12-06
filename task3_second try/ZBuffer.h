#pragma once
#include "MyMatrix.h";
#include "My3DObject.h"

using namespace System::Drawing;
ref class ZBuffer
{
public:
	MyMatrix<int>^ zBuffer;
	MyMatrix<Color>^ scene;

public:
	ZBuffer(Bitmap^ bm);

	void Draw(My3DObject^ object);
};

