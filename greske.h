#pragma once
#include<iostream>
#include<string>

using namespace std;

class Gnematek {};
inline ostream& operator<<(ostream& it, const Gnematek&)
{
	return it << "***GRESKA:NEMA TEKUCEG ELEMENTA***";
}