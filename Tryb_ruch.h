#pragma once

#include "Tryb.h"

class Tryb_wybor;
class Tryb_ekwipunek;
class Tryb_ruch;
class Tryb_wybor_umiejetnosci;
class Tryb_umiejetnosc;

class Tablica_okien;
class Mapa;
class Obiekt;
class Okno_obszar;
class Okno_napis;

class Tryb_ruch :public Tryb
{
	public:

	Tryb_ruch ();
	~Tryb_ruch ();

	void stworz_okna ();
	void zniszcz_okna ();
	void zacznij ();
	void petla ();
	void zakoncz ();

	Tryb_wybor* tryb_wybor;

	Tablica_okien* tablica_okien;
	Mapa* mapa;
	Obiekt* obiekt;

	bool mapa_przesunieto_kursor;

	Okno_obszar* okno_mapa;
	Okno_napis* okno_imie;
	Okno_napis* okno_tytul;
	Okno_napis* okno_wroc;
	Okno_napis* okno_odleglosc;
	Okno_napis* okno_liczba;
};