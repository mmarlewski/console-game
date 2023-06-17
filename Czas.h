#pragma once

#include <vector>

class Licznik;

class Czas
{
	public:

	Czas ();
	~Czas ();

	void zaktualizuj_liczniki ();
	void dodaj_licznik ( Licznik* _licznik );
	void usun_licznik ( Licznik* _licznik );

	std::vector<Licznik*> tablica_licznikow;
};

