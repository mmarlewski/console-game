#pragma once

#include "Okno.h"

class Okno_obszar:public Okno
{
	public:

	Okno_obszar ( Obraz* _obraz, int _pozycja_y, int _dlugosc, int _pozycja_x, int _szerokosc );
	~Okno_obszar ();

	void zmien_obraz ( Obraz* _obraz );
};

