#pragma once

#include "Okno.h"
#include "kolor.h"

class Okno_napis:public Okno
{
	public:

	Okno_napis ( int _pozycja_y, int _pozycja_x, int _szerokosc );
	~Okno_napis ();

	void zmien_napis ( std::string _napis );
	void zmien_kolor ( kolor _kolor_tyl, kolor _kolor_przod );
};

