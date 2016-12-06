#include "Tore.h"
#include "torus.h"

using namespace System;
Tore::Tore():My3DObject()
{
	init();
}

void Tore::init()
{
	this->centerX = 500;
	this->centerY = 300;

	List<double>^ point;
	List<double>^ normal;
	for (int i = 0; i < vcount; i++)
	{
		point = gcnew List<double>;
		normal = gcnew List<double>;
		for (int j = 0; j < 3; j++)
		{
			point->Add(vertices[i][0][j]);
			normal->Add(vertices[i][2][j]);
		}
		normals->Add(normal);
		local_points->Add(point);
	}

	array<int>^ arr;
	for (int i = 0; i < icount; i++)
	{
		if (i == 0) {
			arr = gcnew array<int>(3);
			arr[i] = indices[i];
		}
		else {
			if (i % 3 == 0) {
				sides->Add(gcnew Side(arr));
				arr = gcnew array<int>(3);
				arr[0] = indices[i];
			}
			else {
				arr[i % 3] = indices[i];
			}
		}
	}
}
