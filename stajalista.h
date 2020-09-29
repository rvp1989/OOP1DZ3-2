#pragma once
#include<iostream>
#include<string>
#include"greske.h"

using namespace std;

class Stajaliste
{
	int oznaka;
	string naziv;
	int zona;
public:
	Stajaliste(int o, string n, int z)
	{
		oznaka = o;
		naziv = n;
		zona = z;
	}
	virtual int dohvOznaku()const { return oznaka; }
	virtual string dohvNaziv()const { return naziv; }
	virtual int dohvZonu()const { return zona; }
	friend bool operator==(const Stajaliste& s1, const Stajaliste& s2)
	{
		return s1.oznaka == s2.oznaka;
	}
	friend ostream& operator<<(ostream& it, const Stajaliste& s)
	{
		return it << "[" << s.zona << "]" << "#" << s.oznaka << "-" << s.naziv;
	}
};
