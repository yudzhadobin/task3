#include "Projector.h"

double multy(List<double>^ first, List<double>^ second) {
	double result = 0;
	for (int i = 0; i < first->Count; i++)
	{
		result += first[i] * second[i];
	}
	return result;
}


Projector::Projector()
{
}

MyMatrix<double>^ Projector::Multiple(MyMatrix<double>^ first, MyMatrix<double>^ second) {
	MyMatrix<double>^ result = gcnew MyMatrix<double>(second->Width, first->Length);
	for (int i = 0; i < result->Length; i++) {
		for (int j = 0; j < result->Width; j++)
		{
			List<double>^ a = first->GetRaw(i);
			List<double>^ b = second->GetColumn(j);
			result->set(i, j, (int)multy(a, b));
		}
	}
	return result;
}