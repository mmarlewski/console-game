#pragma once

#include <Windows.h>
#include <iostream>

class Pole;
class Punkt;
class Odcinek;
class Okrag;
class Obraz;

class Mapa
{
	public:

	Mapa ( int _dlugosc_mapy, int _szerokosc_mapy );
	~Mapa ();

	void przesun_kursor_na_srodek ();
	Pole* zwroc_pole_pod_kursorem ();
	Pole* zwroc_pole ( int _y, int _x );
	void ustal_odleglosci ( int _y_start, int _x_start );

	void wyczysc_obraz_mapy ();
	void wyczysc_oznaczenie_wybor ();
	void wyczysc_oznaczenie_efekt ();

	void dolacz_obiekty_do_obrazu_mapy ();
	void dolacz_oznaczenie_wybor_do_obrazu_mapy ();
	void dolacz_oznaczenie_efekt_do_obrazu_mapy ();
	void dolacz_kursor_do_obrazu_mapy ();

	void wyznacz_punkt ( Punkt* _punkt, int _wsp_y, int _wsp_x );
	void wyznacz_odcinek ( Odcinek* _odcinek, int _pocz_y, int _pocz_x, int _kon_y, int _kon_x );
	void wyznacz_okrag ( Okrag* _okrag, int _srodek_y, int _srodek_x, int _promien );

	Pole** mapa;

	Obraz* obraz_mapy;

	int dlugosc_mapy;
	int szerokosc_mapy;

	int kursor_y, kursor_x;
};

