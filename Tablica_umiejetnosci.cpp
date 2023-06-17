#include "Tablica_umiejetnosci.h"

Tablica_umiejetnosci::Tablica_umiejetnosci ()
{
	dzgniecie_mieczem = new Dzgniecie_mieczem ();
	zamach_mieczem = new Zamach_mieczem ();
	dzgniecie_wlocznia = new Dzgniecie_wlocznia ();
	przebicie_wlocznia = new Przebicie_wlocznia ();
	blyskawica = new Blyskawica ();
	kula_ognia = new Kula_ognia ();
}

Tablica_umiejetnosci::~Tablica_umiejetnosci ()
{
	delete dzgniecie_mieczem;
	delete zamach_mieczem;
	delete dzgniecie_wlocznia;
	delete przebicie_wlocznia;
	delete blyskawica;
	delete kula_ognia;
}