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

List<double>^ Side::GetFunction(List<List<int>^>^ points)
{

	List<int>^ sub = points[this->Points[0]];
	int x1 = sub[0];
	int y1 = sub[1];
	int z1 = sub[2];

	sub = points[this->Points[1]];
	int x2 = sub[0];
	int y2 = sub[1];
	int z2 = sub[2];

	sub = points[this->Points[2]];
	int x3 = sub[0];
	int y3 = sub[1];
	int z3 = sub[2];

	double a = y1 * (z2 - z3) + y2 * (z3 - z1) + y3 * (z1 - z2);
	double b = z1 * (x2 - x3) + z2 * (x3 - x1) + z3 * (x1 - x2);
	double c = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

	double d = x1 * (y2 * z3 - y3 * z2) + x2 * (y3 * z1 - y1 * z3) + x3 * (y1*z2 - y2 * z1);

	List<double>^ result = gcnew List<double>;

	result->Add(a);
	result->Add(b);
	result->Add(c);
	result->Add(d);


	sub = points[this->Points[0]];
	int x11 = sub[0];
	int y11 = sub[1];
	int z11 = sub[2];

	sub = points[this->Points[1]];
	int x21 = sub[0];
	int y21 = sub[1];
	int z21 = sub[2];

	sub = points[this->Points[3]];
	int x31 = sub[0];
	int y31 = sub[1];
	int z31 = sub[2];

	double a1 = y11 * (z21 - z31) + y21 * (z31 - z11) + y31 * (z11 - z21);
	double b1 = z11 * (x21 - x31) + z21 * (x31 - x11) + z31 * (x11 - x21);
	double c1 = x11 * (y21 - y31) + x21 * (y31 - y11) + x31 * (y11 - y21);

	//double d1 = x11 * (y21 * z3 - y3 * z2) + x2 * (y3 * z1 - y1 * z3) + x3 * (y1*z2 - y2 * z1);

	List<double>^ result1 = gcnew List<double>;
	result1->Add(a1);
	result1->Add(b1);
	result1->Add(c1);
	
	return result;
}
