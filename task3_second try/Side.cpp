#include "Side.h"



Side::Side()
{
	Points = gcnew List<int>;
}


Side::Side(... array<int>^ points):Side()
{
	for (int i = 0; i < points->Length; i++)
	{
		this->Points->Add(points[i]);
	}
}