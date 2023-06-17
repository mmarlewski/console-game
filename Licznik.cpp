#include "Licznik.h"

Licznik::Licznik ()
{
	zliczone_milisekundy = 0;
	czy_odliczac = false;
}

Licznik::~Licznik ()
{
	//
}

void Licznik::zacznij_odliczanie ()
{
	czy_odliczac = true;

	poczatek_odliczania = std::chrono::high_resolution_clock::now ();
}

void Licznik::zakoncz_odliczanie ()
{
	czy_odliczac = false;
}

void Licznik::zmierz_milisekundy ()
{
	zliczone_milisekundy = std::chrono::duration_cast< std::chrono::milliseconds > ( std::chrono::high_resolution_clock::now () - poczatek_odliczania ).count ();
}

void Licznik::ustal_nowy_poczatek ()
{
	poczatek_odliczania = std::chrono::high_resolution_clock::now ();
}