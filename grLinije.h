#pragma once
#include<iostream>
#include<string>
#include"greske.h"
#include"grLinije.h"
#include"stajalista.h"
#include"lista.h"
using namespace std;
class GradskaLinija
{
	string oznaka;
	Lista<Stajaliste*>stajalista;
public:
	GradskaLinija(string o) : oznaka(o) {}
	virtual string dohvhOznaku()const { return oznaka; }
	Lista listaStajalista()const { return Lista<Stajaliste*> stajalista; }

	int operator&(GradskaLinija& gl1)
	{
		Lista<Stajaliste*>lista1 = gl1.stajalista;
		int counter = 0;
		stajalista.naPrvi();
		while (stajalista.imaTek())
		{
			Stajaliste prvo = stajalista.
		}
	}

protected:
	virtual void pisi(ostream& it)const
	{
		it << oznaka << endl;

	}
	friend ostream& operator<<(ostream& it, const GradskaLinija& g)
	{
		g.pisi(it);
		return it;
	}


};