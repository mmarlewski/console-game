#include "Umiejetnosc.h"

#include "Obraz.h"
#include "Mapa.h"

Umiejetnosc::Umiejetnosc ()
{
	nazwa = "";
	koszt = 0;
	mapa = nullptr;
	obiekt = nullptr;
	y_obiekt = 0;
	x_obiekt = 0;
	y_cel = 0;
	x_cel = 0;
}

Umiejetnosc::~Umiejetnosc ()
{
	for ( int i = 0; i < obrazy_animacji.size (); i++ )
	{
		delete obrazy_animacji[i];
	}
}

void Umiejetnosc::wyczysc_animacje ()
{
	for ( int i = 0; i < obrazy_animacji.size (); i++ )
	{
		delete obrazy_animacji[i];
	}

	obrazy_animacji.clear ();
}