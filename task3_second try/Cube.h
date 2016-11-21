#pragma once
#include "My3DObject.h"
#include "Side.h"

ref class Cube :
	public My3DObject
{
public:
	Cube(int size);

private:
	void init(int size);
};

