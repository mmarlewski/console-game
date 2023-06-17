#pragma once

#include <Windows.h>
#include <string>

class Obraz;

class Konsola
{
	public:

	Konsola ( int _dlugosc_konsoli, int _szerokosc_konsoli );
	~Konsola ();

	void zaktualizuj_konsole ();
	void zmien_tytul_konsoli ( std::string _tytul );
	void pobierz_dane_myszki ();
	bool zwroc_czy_esc ();

	int dlugosc_konsoli;
	int szerokosc_konsoli;

	int myszka_y;
	int myszka_x;

	bool myszka_l;
	bool myszka_p;

	CHAR_INFO* bufor;

	Obraz* obraz;

	HANDLE screen_buffer;
	HANDLE input_buffer;

	SMALL_RECT wymiary;

	DWORD stary_stan_konsoli;
	DWORD nowy_stan_konsoli;
};

