#include "My3DObject.h"
#include "Side.h"


My3DObject::My3DObject()
{
	local_points = gcnew List<List<int>^>();
	sides = gcnew List<Side^>;
}

MyMatrix<double>^ My3DObject::ToMatrix()
{
	MyMatrix<double>^ result = gcnew MyMatrix<double>(4,8);
	for (int i = 0; i < this->local_points->Count; i++)
	{
		List<int>^ sub = local_points[i];
		result->set(i, 0, sub[0]);
		result->set(i, 1, sub[1]);
		result->set(i, 2, sub[2]);
		result->set(i, 3, 1);
	}
	return result;
}

void My3DObject::Draw(MyMatrix<double>^ points, List<Side^>^ sides, Bitmap ^ bitmap)
{
	Graphics^ gr = Graphics::FromImage(bitmap);


	for (int i = 0; i < sides->Count; i++)
	{
		Side^ side = sides[i];

		for (int j = 0; j < side->Points->Count - 1; j++)
		{
			List<double>^ point1 = points->GetRaw(side->Points[j]);
			List<double>^ point2 = points->GetRaw(side->Points[j + 1]);
			int x1 = centerX + point1[0]; // point1[3];
			int y1 = centerY + point1[1]; // point1[3];

			int x2 = centerX + point2[0]; // point2[3];
			int y2 = centerY + point2[1]; // point2[3];
			
			gr->DrawLine(Pens::Red, x1, y1, x2, y2);
		}

		List<double>^ point1 = points->GetRaw(side->Points[3]);
		List<double>^ point2 = points->GetRaw(side->Points[0]);
		int x1 = centerX + point1[0]; /// point1[3];
		int y1 = centerY + point1[1]; // point1[3];

		int x2 = centerX + point2[0]; // point2[3];
		int y2 = centerY + point2[1]; // point2[3];

		gr->DrawLine(Pens::Red, x1, y1, x2, y2);
	}
}

