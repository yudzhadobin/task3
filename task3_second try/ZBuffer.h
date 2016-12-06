#pragma once

#include "MyMatrix.h";
#include "My3DObject.h"

using namespace System;
using namespace System::Drawing;

ref class ZBuffer
{
public:
	MyMatrix<int>^ zBuffer;
	Bitmap^ scene;
	System::Windows::Forms::PictureBox^ picture;
public:
	ZBuffer(Bitmap^ bm);
	
	void setPicture(System::Windows::Forms::PictureBox^ picture);
	void setBitmap(Bitmap^ bm);
	void Draw(My3DObject^ object);

	void restereize(List<List<int>^>^ points, My3DObject^ obj, Side^ side);
};

