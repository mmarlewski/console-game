#pragma once

#include "kolor.h"

class Znak;

class Obraz
{
	public:

	Obraz ();
	Obraz ( int _dlugosc, int _szerokosc );
	~Obraz ();

	int dlugosc;
	int szerokosc;

	Znak** obraz;
};