#include "My3DObject.h"
#include "Side.h"


My3DObject::My3DObject()
{
	local_points = gcnew List<List<double>^>();
	normals = gcnew List<List<double>^>();
	global_normals = gcnew List<List<double>^>();
	global_points = gcnew List<List<int>^>();
	sides = gcnew List<Side^>;
}

MyMatrix<double>^ My3DObject::ToMatrix()
{
	MyMatrix<double>^ result = gcnew MyMatrix<double>(4,local_points->Count);
	for (int i = 0; i < this->local_points->Count; i++)
	{
		List<double>^ sub = local_points[i];
		result->set(i, 0, sub[0]);
		result->set(i, 1, sub[1]);
		result->set(i, 2, sub[2]);
		result->set(i, 3, 1);
	}
	return result;
}

List<int>^ My3DObject::GetMedianPoint()
{
	int x = 0;
	int y = 0;
	int z = 0;

	for (size_t i = 0; i < global_points->Count; i++)
	{
		List<int>^ point = global_points[i];

		x += point[0];
		y += point[1];
		z += point[2];
	}

	x /= global_points->Count;
	y /= global_points->Count;
	z /= global_points->Count;

	List<int>^ result = gcnew List<int>;
	result->Add(x);
	result->Add(y);
	result->Add(z);
	return result;
}

void My3DObject::MoveToGlobal(MyMatrix<double>^ rotateX, MyMatrix<double>^ rotateY, MyMatrix<double>^ rotateZ, int x, int y, int z)
{
	MyMatrix<double>^ result = this->ToMatrix();
	MyMatrix<double>^ normalsMatrix = MyMatrix<double>::FromArray(normals);
	result->plus(0, x);
	result->plus(1, y);
	result->plus(2, z);

	Projector^ projector = gcnew Projector;

	if (rotateX != nullptr) {
		result = projector->Multiple(result, rotateX);
		normalsMatrix = projector->Multiple(result, rotateX);
	}
	if (rotateY != nullptr) {
		result = projector->Multiple(result, rotateY);
		normalsMatrix = projector->Multiple(normalsMatrix, rotateY);
	}
	if (rotateZ != nullptr) {
		result = projector->Multiple(result, rotateZ);
		normalsMatrix = projector->Multiple(normalsMatrix, rotateZ);
	}

	global_points->Clear();
	global_normals->Clear();
	for (size_t i = 0; i < result->Length; i++)
	{
		List<double>^ sub = result->GetRaw(i);
		List<double>^ sub2 = normalsMatrix->GetRaw(i);
		List<int>^ global_point = gcnew List<int>;
		List<double>^ global_normal= gcnew List<double>;
		for (int j = 0; j < sub->Count; j++)
		{
			global_point->Add((int)sub[j]);
		}

		for (int j = 0; j < sub2->Count-1; j++)
		{
			global_normal->Add(sub2[j]);
		}

		global_normals->Add(global_normal);
		global_points->Add(global_point);
	}

}


void My3DObject::MoveToGlobal()
{
	MoveToGlobal(nullptr, nullptr, nullptr, 0, 0, 0);
}

MyMatrix<double>^ My3DObject::ToMatrixGlobalPoints()
{

	MyMatrix<double>^ result = gcnew MyMatrix<double>(4, global_points->Count);
	for (int i = 0; i < this->global_points->Count; i++)
	{
		List<int>^ sub = global_points[i];
		result->set(i, 0, sub[0]);
		result->set(i, 1, sub[1]);
		result->set(i, 2, sub[2]);
		result->set(i, 3, 1);
	}
	return result;
}

double My3DObject::calculateIntensity(Side ^ side)
{
	List<List<double>^>^ curNormals = gcnew List<List<double>^>;
	
	double x = 0;
	double y = 0;
	double z = 0;

	for (int i = 0; i < side->Points->Count; i++)
	{
		List<double>^ curNormal = global_normals[side->Points[i]];
		x += curNormal[0];
		y += curNormal[1];
		z += curNormal[2];
	}
	x /= 3;
	y /= 3;
	z /= 3;

	double cos = (x * light_x + y * light_y + z * light_z) / (Math::Sqrt(Math::Pow(x, 2) + Math::Pow(y, 2) + Math::Pow(z, 2)) * Math::Sqrt(Math::Pow(light_x, 2) + Math::Pow(light_y, 2) + Math::Pow(light_z, 2)));
	cos = Math::Abs(cos);
	return lightIntensity * diffuseReflectionCoef * cos;
}

void My3DObject::Draw(List<Side^>^ sides, Bitmap ^ bitmap, MyMatrix<double>^ proectMatrix)
{
	Graphics^ gr = Graphics::FromImage(bitmap);

	MyMatrix<double>^ global = ToMatrixGlobalPoints();
	Projector^ projector = gcnew Projector;

	global = projector->Multiple(global, proectMatrix);

	for (int i = 0; i < sides->Count; i++)
	{
		Side^ side = sides[i];
		if (side->isVisible) {
			for (int j = 0; j < side->Points->Count - 2; j++)
			{
				List<double>^ point1 = global->GetRaw(side->Points[j]);
				List<double>^ point2 = global->GetRaw(side->Points[j + 1]);
				List<double>^ point3 = global->GetRaw(side->Points[j + 2]);
				int x1 = centerX + point1[0]; // point1[3];
				int y1 = centerY + point1[1]; // point1[3];
				
				int x2 = centerX + point2[0]; // point2[3];
				int y2 = centerY + point2[1]; // point2[3];

				int x3 = centerX + point3[0]; // point2[3];
				int y3 = centerY + point3[1]; // point2[3];

				Point a = *gcnew Point(x1, y1);
				Point b = *gcnew Point(x2, y2);
				Point c = *gcnew Point(x3, y3);
				array<Point>^ polygon = { a, b, c };

				double coef = calculateIntensity(side);
				int R = Color::Red.R * coef;
				int G = Color::Red.G * coef;
				int B = Color::Red.B * coef;

				SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(255, R, G, B));

				gr->FillPolygon(brush, polygon);

			//	gr->DrawPolygon(Pens::Black, polygon);
			}
		}
	}
}

MyMatrix<double>^ My3DObject::GetObjectMatrix()
{
	List<int>^ medianPoint = GetMedianPoint();	
	MyMatrix<double>^ functionsMatrix = gcnew MyMatrix<double>(4,sides->Count);
	List<List<int>^>^ points = gcnew List<List<int>^>;

	for (int i = 0; i < global_points->Count; i++)
	{
		List<int>^ sub = global_points[i];
		List<int>^ point = gcnew List<int>;
		point->Add(sub[0] + centerX);
		point->Add(sub[1] + centerY);
		point->Add(sub[2]);
		points->Add(point);
	}
	for (int i = 0; i < sides->Count; i++)
	{	
		List<double>^ function = sides[i]->GetFunction(points);
		for (int j = 0; j < function->Count; j++)
		{
			functionsMatrix->set(i, j, function[j]);
		}
	}

	for (int i = 0; i < functionsMatrix->Length; i++)
	{
		List<double> ^ function = functionsMatrix->GetRaw(i);
		double sum = 0;

		for (int i = 0; i < function->Count - 1; i++)
		{
			sum += function[i] * medianPoint[i];
		}

		if (sum < 0) {
			for (size_t j = 0; j < function->Count; j++)
			{
				functionsMatrix->set(i, j, -function[j]);
			}
		} 
	}

	List<int>^ infinity = gcnew List<int>;
	infinity->Add(centerX);
	infinity->Add(centerY);
	infinity->Add(100000000);
	
	for (int i = 0; i < functionsMatrix->Length; i++)
	{
		List<double>^ function = functionsMatrix->GetRaw(i);
		int sum = 0;
		for (int j = 0; j < infinity->Count; j++)
		{
			sum += function[j] * infinity[j];
		}

		if (sum < 0) {
			sides[i]->isVisible = false;
		}
		else
		{
			sides[i]->isVisible = true;
		}
	}
	return nullptr;
}

