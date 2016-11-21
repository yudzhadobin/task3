#include "RotateByLine.h"



RotateByLine::RotateByLine():MyMatrix(4)
{
	set(0, 0, 1);

	set(1, 1, 1);
	set(2, 2, 1);
	set(3, 3, 1);

	set(3, 0, -5);
	set(3, 1, -5);
	set(3, 2, -5);
}
