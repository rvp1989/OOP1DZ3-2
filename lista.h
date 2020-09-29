#pragma once
#include<iostream>
#include<string>

using namespace std;




template<typename T>
class Lista
{
	struct Elem
	{
		T pod;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr)
		{
			pod = p;
			sled = s;
		}
	};
	Elem* prvi, * posl;
	mutable Elem* tek, * pret;
	void kopiraj(const Lista& lst);
	void premsti(Lista& lst)
	{
		prvi = lst.prvi;
		posl = lst.posl;
		lst.prvi = lst.posl = nullptr;
	}
public:
	Lista()
	{
		prvi = posl = tek = pret = nullptr;
	}
	Lista(const Lista& lst)
	{
		kopiraj(lst);
	}
	Lista(Lista&& lst)
	{
		premsti(lst);
	}
	~Lista()
	{
		isprazni();
	}
	Lista& operator=(const Lista& lst)
	{
		if (this != &lst)
		{
			isprazni();
			kopiraj(lst);
		}
		return *this;
	}
	Lista& operator=(Lista&& lst)
	{
		if (this != &lst)
		{
			isprazni();
			premsti(lst);
		}
		return *this;
	}
	Lista& dodaj(const T& t)
	{
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		return *this;
	}
	Lista& naPrvi()
	{
		tek = prvi;
		pret = nullptr;
		return *this;
	}
	const Lista& naPrvi() const
	{
		tek = prvi;
		pret = nullptr;
		return *this;
	}
	Lista& naSled()
	{
		pret = tek;
		if (tek)
			tek = tek->sled;
		return *this;
	}
	const Lista& naSled() const
	{
		pret = tek;
		if (tek)
			tek = tek->sled;
		return *this;
	}

	bool imaTek()const
	{
		return tek != nullptr;
	}

	T& dohvTek()
	{
		if (!tek)
			throw Gnematek();
		return tek->pod;
	}

	const T& dohvTek() const
	{
		if (!tek)
			throw Gnematek();
		return tek->pod;
	}

	Lista& izbaciTek()
	{
		if (!tek)
			throw Gnematek();
		Elem* stari = tek;
		tek = tek->sled;
		(!pret ? prvi : pret->sled) = tek;
		if (!tek)
			posl = pret;
		delete stari;
		return *this;
	}
	Lista& isprazni();

	template<typename T>
	friend ostream& operator<<(ostream& it, const Lista<T>& lst)
	{
		for (lst.tek = lst.prvi;lst.tek;lst.tek = lst.tek->sled)
			it << lst.tek->pod << endl;
	}

};

template<typename T>
void Lista<T>::kopiraj(const Lista& lst)
{
	prvi = posl = tek = pret = nullptr;
	for (Elem* pok = lst.prvi;pok;pok = pok->sled)
	{
		Elem* novi = new Elem(pok->pod);
		posl = (!prvi ? prvi : posl->sled) = novi;
		if (pok == lst.tek)
			tek = novi;
		if (pok == lst.pret)
			pret = novi;
	}
}

template<typename T>
Lista<T>& Lista<T>::isprazni()
{
	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = pret = nullptr;
	return *this;
}