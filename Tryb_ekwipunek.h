#pragma once

#include "Tryb.h"

#include "kolor.h"

class Tryb_wybor;
class Tryb_ekwipunek;
class Tryb_ruch;
class Tryb_wybor_umiejetnosci;
class Tryb_umiejetnosc;

class Tablica_okien;
class Mapa;
class Obiekt;
class Przedmiot;
class Okno_obszar;
class Okno_napis;

class Tryb_ekwipunek :public Tryb
{
	public:

	Tryb_ekwipunek ();
	~Tryb_ekwipunek ();

	void stworz_okna ();
	void zniszcz_okna ();
	void zacznij ();
	void petla ();
	void zakoncz ();

	void pokaz_czesc_ekwipunku ();

	Tryb_wybor* tryb_wybor;

	Tablica_okien* tablica_okien;
	Mapa* mapa;
	Obiekt* obiekt;

	std::vector< Przedmiot* > przedmioty;
	std::string rodzaj_przedmiotow;
	int nr_czesci;
	int max_czesci;

	int wartosc_1;
	kolor kolor_wartosc_1;
	int wartosc_2;
	kolor kolor_wartosc_2;

	Okno_obszar* okno_mapa;
	Okno_napis* okno_imie;
	Okno_napis* okno_tytul;
	Okno_napis* okno_wroc;
	Okno_napis* okno_nazwa[5];
	Okno_napis* okno_wartosc_1[5];
	Okno_napis* okno_wartosc_2[5];
	Okno_napis* okno_lewa_strzalka;
	Okno_napis* okno_nr_czesci;
	Okno_napis* okno_prawa_strzalka;
};