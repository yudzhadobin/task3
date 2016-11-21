#include "RotateZ.h"



RotateZ::RotateZ(int angle):MyMatrix(4)
{

	double radian = angle * M_PI / 180;

	set(0, 0, Math::Cos(radian));
	set(0, 1, Math::Sin(radian));

	set(1, 0, -Math::Sin(radian));
	set(1, 1, Math::Cos(radian));

	set(2, 2, 1);

	set(3, 3, 1);

}
