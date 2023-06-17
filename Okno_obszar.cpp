#include "Okno_obszar.h"

Okno_obszar::Okno_obszar ( Obraz* _obraz, int _pozycja_y, int _dlugosc, int _pozycja_x, int _szerokosc )
{
	czy_aktywne = 0;

	pozycja_y = _pozycja_y;
	dlugosc = _dlugosc;
	pozycja_x = _pozycja_x;
	szerokosc = _szerokosc;

	myszka_obecna = 0;
	myszka_weszla = 0;
	myszka_wyszla = 0;

	l_wcisniety = 0;
	l_klikniety = 0;
	p_wcisniety = 0;
	p_klikniety = 0;

	kursor_y = 0;
	kursor_x = 0;

	obraz = _obraz;
}

Okno_obszar::~Okno_obszar ()
{
	//
}

void Okno_obszar::zmien_obraz ( Obraz* _obraz )
{
	obraz = _obraz;
}