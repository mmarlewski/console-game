#pragma once

#include <Windows.h>
#include <vector>

class Konsola;
class Okno;
class Okno_napis;
class Okno_obszar;
class Obraz;

class Tablica_okien
{
	public:

	Tablica_okien ( int _dlugosc_wspolnego_obrazu, int _szerokosc_wspolnego_obrazu );
	~Tablica_okien ();

	void zaktualizuj_okna ();
	void ustal_wspolny_obraz ();
	void dodaj_okno ( Okno* _okno );
	void usun_okno ( Okno* _okno );

	Konsola* konsola;

	std::vector<Okno*> tablica_okien;

	Obraz* wspolny_obraz_okien;

	int dlugosc_wspolnego_obrazu;
	int szerokosc_wspolnego_obrazu;
};

