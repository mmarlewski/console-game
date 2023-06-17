#include "Obraz.h"

#include "Znak.h"

Obraz::Obraz ()
{
	//
}

Obraz::Obraz ( int _dlugosc, int _szerokosc )
{
	dlugosc = _dlugosc;
	szerokosc = _szerokosc;

	obraz = new Znak * [dlugosc];

	for ( int i = 0; i < dlugosc; i++ )
	{
		obraz[i] = new Znak [szerokosc];
	}
}

Obraz::~Obraz ()
{
	for ( int i = 0; i < dlugosc; i++ )
	{
		delete[] obraz[i];
	}

	delete[] obraz;
}