#include "My3DPoint.h"



My3DPoint::My3DPoint()
{
	local_points = gcnew List<List<int>^>^ ();
	sides = gcnew List<Side^>;
}
