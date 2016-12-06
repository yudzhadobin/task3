#pragma once
#define M_PI           3.14159265358979323846 
using namespace System;
using namespace System::Collections::Generic;

template<typename T>
ref class MyMatrix
{

	List<List<T>^>^ matrix;
public: 
	property int Length;
	property int Width;
public:

	static MyMatrix^ FromArray(List<List<T>^>^ list) {
		MyMatrix<T>^ result = gcnew MyMatrix<T>();
		result->Length = list->Count;
		result->Width = list[0]->Count;
		List<T>^ sub;
		for (int i = 0; i < list->Count; i++)
		{
			sub = gcnew List<T>(list[i]);
			sub->Add(1);
			result->matrix->Add(sub);
		}
		return result;
	}

	MyMatrix()
	{
		matrix = gcnew List<List<T>^>();
	}

	MyMatrix(int size) :MyMatrix()
	{
		Length = size;
		Width = size;

		for (int i = 0; i < size; i++)
		{
			matrix->Add(gcnew List<T>);
			for (int j = 0; j < size; j++)
			{
				matrix[i]->Add(0);
			}
		}
	}

	MyMatrix(int width, int length) :MyMatrix()
	{
		Length = length;
		Width = width;

		for (int i = 0; i < length; i++)
		{
			matrix->Add(gcnew List<T>);
			for (int j = 0; j < width; j++)
			{
				matrix[i]->Add(T());
			}
		}
	}

	MyMatrix(int width, int length, T value) :MyMatrix()
	{
		Length = length;
		Width = width;

		for (int i = 0; i < length; i++)
		{
			matrix->Add(gcnew List<T>);
			for (int j = 0; j < width; j++)
			{
				matrix[i]->Add(value);
			}
		}
	}

	void set(int i, int j, T value)
	{
		List<T>^ v = matrix[i];
		v[j] = value;

	}

	T get(int i, int j)
	{
		List<T>^ v = matrix[i];
		return v[j];
	}

	List<T>^ GetRaw(int index)
	{
		return matrix[index];
	}

	List<T>^ GetColumn(int index) {
		List<T>^ result = gcnew List<T>();

		for (int i = 0; i < Length; i++)
		{
			List<T>^ sub = matrix[i];
			result->Add(sub[index]);
		}
		return result;
	}

	void plus(int column, int change) {
		for (int i = 0; i < Length; i++)
		{
			List<T>^ sub = matrix[i];
			sub[column] += change;
		}
	}

	virtual String^ ToString() override
	{
		String^ result = "";

		for (int i = 0; i < matrix->Count; i++)
		{
			for (int j = 0; j < matrix[i]->Count; j++)
			{
				List<T>^ sub = matrix[i];
				result += sub[j] + " \t";
			}
			result += "\n";
		}
		return result;
	}
	
	void clear(T value) {
		for (int i = 0; i < Length; i++)
		{
			List<int>^ sub = matrix[i];
			for (int j = 0; i < Width; i++)
			{
				sub[j] = value;
			}
		}
	}
};


