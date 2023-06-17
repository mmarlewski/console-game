#pragma once

#include <Windows.h>
#include <string>

class Obraz;

class Okno
{
	public:

	Okno ();
	virtual ~Okno ();

	void zaktualizuj ( bool _myszka, bool _myszka_l, bool _myszka_p );
	void aktywuj ();
	void deaktywuj ();

	Obraz* obraz;

	bool czy_aktywne;

	int pozycja_y;
	int dlugosc;    // V //
	int pozycja_x;
	int szerokosc;  // > //

	bool myszka_obecna;
	bool myszka_weszla;
	bool myszka_wyszla;

	bool l_wcisniety;
	bool l_klikniety;
	bool p_wcisniety;
	bool p_klikniety;

	int kursor_y;
	int kursor_x;
};

