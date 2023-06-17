#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>

#include "kolor.h"

class Tryb
{
	public:

	Tryb ();
	virtual ~Tryb ();

	virtual void stworz_okna () = 0;
	virtual void zniszcz_okna () = 0;
	virtual void zacznij () = 0;
	virtual void petla () = 0;
	virtual void zakoncz () = 0;

	bool czy_tryb_ma_trwac;
	std::string nastepny_tryb;
};