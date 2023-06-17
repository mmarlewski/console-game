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

class Tryb_wybor :public Tryb
{
	public:

	Tryb_wybor ();
	~Tryb_wybor ();

	void stworz_okna ();
	void zniszcz_okna ();
	void zacznij ();
	void petla ();
	void zakoncz ();

	void pokaz_info_obiektu ();
	void stworz_pasek_hp ();
	void stworz_pasek_ap ();
	void stworz_pasek_broni ();

	Tryb_ekwipunek* tryb_ekwipunek;
	Tryb_wybor_umiejetnosci* tryb_wybor_umiejetnosci;
	Tryb_ruch* tryb_ruch;

	Tablica_okien* tablica_okien;
	Mapa* mapa;
	Obiekt* obiekt;
	int* tura;

	bool mapa_kursor_stop;
	bool mapa_przesunieto_kursor;
	int y_obiekt;
	int x_obiekt;

	Okno_obszar* okno_mapa;
	Okno_napis* okno_imie;
	Okno_napis* okno_klasa;
	Okno_napis* okno_gracz;
	Okno_napis* okno_hp;
	Okno_napis* okno_hp_pasek;
	Okno_napis* okno_ap;
	Okno_napis* okno_ap_pasek;
	Okno_napis* okno_bron_nazwa;
	Okno_napis* okno_bron_pojemnosc;
	Okno_napis* okno_bron_pasek;
	Okno_napis* okno_amunicja_nazwa;
	Okno_napis* okno_amunicja_pojemnosc;
	Okno_napis* okno_zaladuj;
	Okno_napis* okno_rozladuj;
	Okno_napis* okno_zbroja_nazwa;
	Okno_napis* okno_umiejetnosci;
	Okno_napis* okno_ruch;
	Okno_napis* okno_tura;
	Okno_napis* okno_zakoncz_ture;

};