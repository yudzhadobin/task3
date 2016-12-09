#pragma once

using namespace System;
using namespace System::Collections::Generic;
ref class Side
{
public:
	property List<int>^ Points;
	property List<double>^ normal;

	bool isVisible = true;
public:
	Side();

	Side(... array<int>^ points);


	List<double>^ GetFunction(List<List<int>^>^ points);
};


