#include "Cube.h"

Cube::Cube(int size):My3DObject()
{
	init(size);
}

void Cube::init(int size)
{
	this->centerX = 500;
	this->centerY = 250;

	List<double>^ a = gcnew List<double>();
	a->Add(0);
	a->Add(0);
	a->Add(0);

	List<double>^ b = gcnew List<double>();
	b->Add(size);
	b->Add(0);
	b->Add(0);
	
	List<double>^ c = gcnew List<double>();
	c->Add(size);
	c->Add(0);
	c->Add(size);

	List<double>^ d = gcnew List<double>();
	d->Add(0);
	d->Add(0);
	d->Add(size);

	List<double>^ e = gcnew List<double>();
	e->Add(0);
	e->Add(size);
	e->Add(0);

	List<double>^ f = gcnew List<double>();
	f->Add(size);
	f->Add(size);
	f->Add(0);

	List<double>^ g = gcnew List<double>();
	g->Add(size);
	g->Add(size);
	g->Add(size);

	List<double>^ h = gcnew List<double>();
	h->Add(0);
	h->Add(size);
	h->Add(size);

	this->local_points->Add(a);//0
	this->local_points->Add(b);//1
	this->local_points->Add(c);//2
	this->local_points->Add(d);//3
	this->local_points->Add(e);//4
	this->local_points->Add(f);//5
	this->local_points->Add(g);//6
	this->local_points->Add(h);//7

	//низ

	this->sides->Add(gcnew Side(0, 1, 2, 3));
	//серединная
	this->sides->Add(gcnew Side(0, 4, 5, 1));
	this->sides->Add(gcnew Side(1, 2, 6, 5));
	this->sides->Add(gcnew Side(3, 7, 6, 2));
	this->sides->Add(gcnew Side(3, 7, 4, 0));
	//верх
	this->sides->Add(gcnew Side(4, 5, 6, 7));
}