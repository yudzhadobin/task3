#include "Spring.h"


int circle = 720;
int coef = 20;
Spring::Spring(int step_graduses)
{
	init(step_graduses);
}

void Spring::init(int step_graduses)
{
	this->centerX = 500;
	this->centerY = 250;

	List<double>^ normal = gcnew List<double>;
	normal->Add(0);
	normal->Add(0);
	normal->Add(0);
	for (int i = 0; i < circle / step_graduses; i++)
	{
		int angle_thata = i * circle / step_graduses;
		double radian_thata = angle_thata * M_PI / 180;

		for (int j = 0; j < circle / step_graduses; j++)
		{
			int angle_ghama = j * circle / step_graduses;
			double radian_ghama = angle_ghama * M_PI / 180;

			List<double>^ point = gcnew List<double>;
			point->Add((R + r* Math::Cos(radian_thata)) * Math::Cos(radian_ghama)); //x

			point->Add((r * Math::Sin(radian_thata)) + coef * radian_ghama); //y
			point->Add((R + r* Math::Cos(radian_thata)) * Math::Sin(radian_ghama)); //z

			this->local_points->Add(point);
			this->normals->Add(normal);
		}

		if (i > 0) {
			for (int j = 0; j < circle / step_graduses - 1; j++) {
				int a = (i - 1) * circle / step_graduses + j;
				int b = a + 1;
				int c = i  * circle / step_graduses + j;
				int d = c + 1;

				this->sides->Add(gcnew Side(a, b, c));
				this->sides->Add(gcnew Side(c, d, b));

			}
		}
		
	
		
	}

	//считаем нормали к граням
	for (int j = 0; j < this->sides->Count; j++)
	{
		Side^ curSide = this->sides[j];

		List<double>^ a = gcnew List<double>(local_points[curSide->Points[0]]);
		List<double>^ b = gcnew List<double>(local_points[curSide->Points[1]]);
		List<double>^ c = gcnew List<double>(local_points[curSide->Points[2]]);

		List<double>^ ba = gcnew List<double>;
		ba->Add(b[0] - a[0]);
		ba->Add(b[1] - a[1]);
		ba->Add(b[2] - a[2]);

		List<double>^ ca = gcnew List<double>;
		ca->Add(c[0] - a[0]);
		ca->Add(c[1] - a[1]);
		ca->Add(c[2] - a[2]);
		
		List<double>^ vectorNormal = gcnew List<double>;
		vectorNormal->Add(ba[1] * ca[2] - ba[2] * ca[1]);
		vectorNormal->Add(ba[2] * ca[0] - ba[0] * ca[2]);
		vectorNormal->Add(ba[0] * ca[1] - ba[1] * ca[0]);
		int normalLength =Math::Sqrt(Math::Pow(vectorNormal[0], 2)+ Math::Pow(vectorNormal[1], 2) + Math::Pow(vectorNormal[2], 2));

		vectorNormal[0] /= normalLength;
		vectorNormal[1] /= normalLength;
		vectorNormal[2] /= normalLength;

		curSide->normal = vectorNormal;
	}
	//нормали в точках
	for (int i = 0; i < sides->Count; i++)
	{
		List<double>^ curNormal = gcnew List<double>(sides[i]->normal);
		List<int>^ pointsIndexes = sides[i]->Points;
		for (int j = 0; j < pointsIndexes->Count; j++)
		{
			List<double>^ pointNormal = normals[pointsIndexes[j]];
			pointNormal[0] += curNormal[0] / 4;
			pointNormal[1] += curNormal[1] / 4;
			pointNormal[2] += curNormal[2] / 4;
		}
	}
}
