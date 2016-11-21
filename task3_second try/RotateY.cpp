#include "RotateY.h"



RotateY::RotateY(int angle):MyMatrix(4)
{
	double radian = angle * M_PI / 180;
	
	set(0, 0, Math::Cos(radian));
	set(2, 0, Math::Sin(radian));
	set(1, 1, 1);
	set(0, 2, -Math::Sin(radian));
	set(2, 2, Math::Cos(radian));
	set(3, 3, 1);

	int j = 5;
}
