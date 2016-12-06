#include "ZBuffer.h"

ZBuffer::ZBuffer(Bitmap^ bm)
{
	scene = bm;
	zBuffer = gcnew MyMatrix<int>(bm->Size.Width, bm->Size.Height, -10000000);
}

void ZBuffer::setPicture(System::Windows::Forms::PictureBox ^ picture)
{
	this->picture = picture;
}

void ZBuffer::setBitmap(Bitmap ^ bm)
{
	this->scene = bm;
}

void swap(List<int>^ a, List<int>^b) {
	int sub;
	for (int i = 0; i < a->Count; i++)
	{
		sub = b[i];
		b[i] = a[i];
		a[i] = sub;
	}

}

//https://habrahabr.ru/post/248179/
void ZBuffer::restereize(List<List<int>^>^ points, My3DObject^ obj, Side^ side) {
	List<int>^ a = gcnew List<int>(points[0]);
	List<int>^ b = gcnew List<int>(points[1]);
	List<int>^ c = gcnew List<int>(points[2]);
	if (a[1] > b[1]) {
		swap(a, b);
	}
	if (a[1] > c[1]) {
		swap(a, c);
	}
	if (b[1] > c[1]) {
		swap(b, c);
	}

	int totalHeight = c[1] - a[1];

	for (int i = 0; i < totalHeight; i++) {
		bool secondHalf = (i > (b[1] - a[1])) || (b[1] == a[1]);
		int segmentHeight = secondHalf ? c[1] - b[1] : b[1] - a[1];

		double alpha = (double)i / totalHeight;
		double beta = (double)(i - (secondHalf ? b[1] - a[1] : 0)) / segmentHeight;
		List<int>^ A = gcnew List<int>(a);
		for (int i = 0; i < A->Count; i++)
		{
			A[i] += (c[i] - a[i]) * alpha  + 0.5;
		}
		
		List<int>^ B = secondHalf ? gcnew List<int>(b) : gcnew List<int>(a);
		for (int i = 0; i < B->Count; i++)
		{
			B[i] += (secondHalf ? (c[i] - b[i]) * beta : (b[i] - a[i]) * beta) + 0.5;
		}
		
		if (A[0] > B[0]) {
			swap(A, B);
		}

		for (int j = A[0]; j <= B[0]; j++)
		{
		

			double phi = B[0] == A[0] ? 1 : (double)(j - A[0]) / (double)(B[0] - A[0]);
			
			List<int>^ point = gcnew List<int>(A);
		
			for (size_t i = 0; i < point->Count; i++)
			{
				point[i] += ((B[i] - A[i]) * phi + 0.5);
			}
			point[0] += obj->centerX;
			point[1] += obj->centerY;

			if (point[0] < zBuffer->Length && point[1] < zBuffer->Width) {
				if (zBuffer->get(point[0], point[1]) < point[2]) {
					zBuffer->set(point[0], point[1], point[2]);

					double coef = obj->calculateIntensity(side);
					int R = Color::Red.R * coef;
					int G = Color::Red.G * coef;
					int B = Color::Red.B * coef;
					scene->SetPixel(point[0], point[1], Color::FromArgb(255, R, G, B));
				}
			}
		}
	}
}

void ZBuffer::Draw(My3DObject^ object)
{
	for (int i = 0; i < object->sides->Count; i++)
	{
		
		Side^ curSide = object->sides[i];

		List<List<int>^>^ curPoints = gcnew List<List<int>^>;
		for (int j = 0; j < curSide->Points->Count; j++)
		{
			curPoints->Add(object->global_points[curSide->Points[j]]);
		}		
		restereize(curPoints, object, curSide);
	}
	zBuffer = gcnew MyMatrix<int>(scene->Size.Height, scene->Size.Width, -10000000);
}

