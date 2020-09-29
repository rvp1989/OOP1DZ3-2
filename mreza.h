#pragma once
#include<iostream>
#include<string>
#include"greske.h"
#include"grLinije.h"
#include"stajalista.h"
#include"lista.h"
using namespace std;

class Mreza :public GradskaLinija
{
	Lista<GradskaLinija*>linije;
public:
	Mreza(string o) :GradskaLinija(o) {}
	Mreza& operator+=(GradskaLinija& gl)
	{
		linije.dodaj(&gl);
		return *this;
	}
protected:
	void pisi(ostream& it)const override
	{
		GradskaLinija::pisi(it);
	}
};