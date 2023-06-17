#pragma once

#include <chrono>

class Licznik
{
	public:

	Licznik ();
	~Licznik ();

	void zacznij_odliczanie ();
	void zakoncz_odliczanie ();
	void zmierz_milisekundy ();
	void ustal_nowy_poczatek ();

	std::chrono::time_point<std::chrono::high_resolution_clock> poczatek_odliczania;
	int zliczone_milisekundy;
	bool czy_odliczac;
};

