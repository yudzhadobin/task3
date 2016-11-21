#pragma once
#include "MyMatrix.h"
using namespace System::Collections::Generic;

ref class Projector
{
public:
	Projector();

	MyMatrix<double>^ Multiple(MyMatrix<double>^ first, MyMatrix<double>^ second);

};

