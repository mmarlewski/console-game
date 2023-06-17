#pragma once

#include "Tryb.h"

class Tryb_wybor;
class Tryb_ekwipunek;
class Tryb_ruch;
class Tryb_wybor_umiejetnosci;
class Tryb_umiejetnosc;

class Tablica_okien;
class Czas;
class Mapa;
class Umiejetnosc;
class Obiekt;
class Licznik;
class Obraz;
class Okno_obszar;
class Okno_napis;

class Tryb_umiejetnosc :public Tryb
{
	public:

	Tryb_umiejetnosc ();
	~Tryb_umiejetnosc ();

	void stworz_okna ();
	void zniszcz_okna ();
	void zacznij ();
	void petla ();
	void zakoncz ();

	Tryb_wybor_umiejetnosci* tryb_wybor_umiejetnosci;

	Tablica_okien* tablica_okien;
	Czas* czas;
	Mapa* mapa;

	Umiejetnosc* umiejetnosc;
	Obiekt* obiekt;
	Licznik* licznik_animacji;
	Obraz* obraz_braku_animacji;

	bool w_trakcie_animacji;
	int nr_obrazu_animacji;
	bool mapa_przesunieto_kursor;

	Okno_obszar* okno_mapa;
	Okno_obszar* okno_animacja;
	Okno_napis* okno_imie;
	Okno_napis* okno_tytul;
	Okno_napis* okno_wroc;
};