#include "Okno_napis.h"

#include "Obraz.h"
#include "Znak.h"

Okno_napis::Okno_napis ( int _pozycja_y, int _pozycja_x, int _szerokosc )
{
	czy_aktywne = 0;

	pozycja_y = _pozycja_y;
	dlugosc = 1;
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

	obraz = new Obraz ( 1, szerokosc );

	for ( int i = 0; i < dlugosc; i++ )
	{
		for ( int j = 0; j < szerokosc; j++ )
		{
			obraz->obraz[i][j].przezroczysty = false;
		}
	}
}

Okno_napis::~Okno_napis ()
{
	delete obraz;
}

void Okno_napis::zmien_napis ( std::string _napis )
{
	for ( int i = 0; i < szerokosc && i < _napis.length (); i++ )
	{
		obraz->obraz[0][i].znak = _napis[i];
	}

	for ( int i = _napis.length (); i < szerokosc; i++ )
	{
		obraz->obraz[0][i].znak = L' ';
	}
}

void Okno_napis::zmien_kolor ( kolor _kolor_tyl, kolor _kolor_przod )
{
	for ( int i = 0; i < szerokosc; i++ )
	{
		obraz->obraz[0][i].kolor_przod = _kolor_przod;
		obraz->obraz[0][i].kolor_tyl = _kolor_tyl;
	}
}