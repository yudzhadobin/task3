#include "RotateX.h"



RotateX::RotateX(int angle) :MyMatrix(4)
{

	double radian = angle * M_PI / 180;

	set(0, 0, 1);

	set(1, 1, Math::Cos(radian));
	set(1, 2, Math::Sin(radian));
	set(2, 1, -Math::Sin(radian));
	set(2, 2, Math::Cos(radian));

	set(3, 3, 1);
}
