#pragma once

#include <Windows.h>

class Obiekt;

class Pole
{ 
	public:

	Pole ();
	~Pole ();

	Obiekt* obiekt;
	int odleglosc;
	bool oznaczenie_wybor;
	bool oznaczenie_efekt;
};

