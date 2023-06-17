#pragma once

#include "Umiejetnosci.h"

class Tablica_umiejetnosci
{
	public:

	Tablica_umiejetnosci ();
	~Tablica_umiejetnosci ();

	Dzgniecie_mieczem* dzgniecie_mieczem;
	Zamach_mieczem* zamach_mieczem;
	Dzgniecie_wlocznia* dzgniecie_wlocznia;
	Przebicie_wlocznia* przebicie_wlocznia;
	Blyskawica* blyskawica;
	Kula_ognia* kula_ognia;
};

