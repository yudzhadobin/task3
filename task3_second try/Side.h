#pragma once

using namespace System;
using namespace System::Collections::Generic;
ref class Side
{
public:
	property List<int>^ Points;

public:
	Side();

	Side(... array<int>^ points);
};


