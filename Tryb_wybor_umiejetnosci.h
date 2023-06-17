#pragma once
 
#include "Tryb.h"

class Tryb_wybor;
class Tryb_ekwipunek;
class Tryb_ruch;
class Tryb_wybor_umiejetnosci;
class Tryb_umiejetnosc;

class Tablica_okien;
class Tablica_umiejetnosci;
class Mapa;
class Obiekt;
class Okno_obszar;
class Okno_napis;

class Tryb_wybor_umiejetnosci :public Tryb
{
	public:

	Tryb_wybor_umiejetnosci ();
	~Tryb_wybor_umiejetnosci ();

	void stworz_okna ();
	void zniszcz_okna ();
	void zacznij ();
	void petla ();
	void zakoncz ();

	void pokaz_umiejetnosc ();

	Tryb_wybor* tryb_wybor;
	Tryb_umiejetnosc* tryb_umiejetnosc;

	Tablica_umiejetnosci* tablica_umiejetnosci;
	Tablica_okien* tablica_okien;
	Mapa* mapa;
	Obiekt* obiekt;

	int nr_umiejetnosci;
	int y_obiekt;
	int x_obiekt;

	Okno_obszar* okno_mapa;
	Okno_napis* okno_imie;
	Okno_napis* okno_tytul;
	Okno_napis* okno_wroc;
	Okno_napis* okno_nazwa;
	Okno_napis* okno_koszt;
	Okno_napis* okno_wybierz;
	Okno_napis* okno_lewa_strzalka;
	Okno_napis* okno_nr_umiejetnosci;
	Okno_napis* okno_prawa_strzalka;
};