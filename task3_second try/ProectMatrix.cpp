#include "ProectMatrix.h"



ProectMatrix::ProectMatrix():MyMatrix(4,4)
{
	set(0, 0, 1);
	set(1, 1, 1);
	set(3, 3, 1);

	set(2, 3, 1);
}
