#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Galaz {
public:

	Galaz()
	{

	}

	double Dlugosc(double dlugosc = 0)
	{
		if (dlugosc == 0)
		{
			return dlug;
		}
		else
		{
			dlug = dlugosc;
		}
	}

	size_t Lisc(size_t liczba_lisci = 0)
	{
		if (liczba_lisci = 0)
		{
			return lisc;
		}
		else
		{
			lisc = liczba_lisci;
		}
	}

private:
	double dlug = 0.;
	size_t lisc = 0;
};




class Drzewo {
public:

	Drzewo(const char* nazwa, double wysokosc)
	{
		name = nazwa;
		height = wysokosc;
	}

	~Drzewo()
	{
		galaz.clear();
	}

	const char* Nazwa(const char* nazwa = nullptr)
	{
		if (nazwa == nullptr)
		{
			const char* nazwa_drzewa_rzut = name.c_str();
			return nazwa_drzewa_rzut;
		}
		else
		{
			name = nazwa;
		}
	}

	double Wysokosc(double wysokosc = 0)
	{
		if (wysokosc == 0)
		{
			return height;
		}
		else
		{
			height = wysokosc;
		}
	}

	void Galaz_f(Galaz* galaz_n)
	{
		if (galaz_n != NULL)
		{
			galaz.push_back(galaz_n);
		}

	}

	Galaz* Galaz_f(size_t ilosc = 0)
	{
		if (ilosc > galaz.size())
			return nullptr;
		else if (galaz.size() == 0)
			return nullptr;
		else
		{
			return galaz[ilosc];
		}
	}

	const size_t Galaz_f()
	{
		size_t ilosc = galaz.size();
		return ilosc;
	}


private:
	string name;
	double height;
	vector<Galaz*> galaz; // pamietac o skasowaniu obiektow
};


int main() {
	Drzewo d1("brzoza", 20);
	Drzewo d2("sekwoja", 100); 
	d1.Galaz_f(new Galaz); // dodaje pierwsza galaz
	d1.Galaz_f(new Galaz); // dodaje kolejna galaz
	Galaz* g1 = d1.Ga1az_f(0); // pobieram pierwsza galaz
	g1->Dlugosc(5); // ustawiam dlugosc galezi
	g1->Lisc(100); // ustawiam liczbe lisci
	Galaz* g2 = d2.Ga1az_f(1); // pobieram druga galaz
	g2->Dlugosc(3); // ustawiam dlugosc galezi
	g2->Lisc(70); // ustawiam liczbe lisci

	cout << d1.Nazwa() << " ma galezi: " << d1.Galaz_f() << endl;
	cout << d2.Nazwa() << " ma galezi: " << d2.Galaz_f() << endl;

}