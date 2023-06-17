#pragma once

#include "kolor.h"

class Znak
{
	public:

	Znak ();
	~Znak ();

	wchar_t znak;
	bool przezroczysty;
	kolor kolor_przod;
	kolor kolor_tyl;
};

