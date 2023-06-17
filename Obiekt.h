#pragma once

#include <string>
#include <vector>

class Tablica_umiejetnosci;
class Umiejetnosc;
class Przedmiot;
class Bron;
class Bron_biala;
class Bron_dystansowa;
class Bron_miotana;
class Amunicja;
class Zbroja;

class Obiekt
{
	public:

	Obiekt ();
	~Obiekt ();

	virtual void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci ) = 0;
	void przyjmij_obrazenia ( int _obrazenia );

	std::string klasa;
	std::string imie;
	int gracz;
	int wysokosc;
	wchar_t symbol;
	int pozycja_y, pozycja_x;

	std::vector<Przedmiot*> ekwipunek;
	std::vector<Umiejetnosc*> umiejetnosci;

	Amunicja* amunicja;
	Bron* bron;
	Bron_biala* bron_biala;
	Bron_dystansowa* bron_dystansowa;
	Bron_miotana* bron_miotana;
	Zbroja* zbroja;

	bool czy_hp;
	int hp_teraz;
	int hp_max;

	bool czy_ap;
	int ap_teraz;
	int ap_max;

	bool czy_ekw;
	int ekw_max;

	bool czy_umiej;
};

