#include "Umiejetnosci.h"

#include "Mapa.h"
#include "Pole.h"
#include "Obiekt.h"
#include "Obraz.h"
#include "Znak.h"
#include "Punkt.h"
#include "Odcinek.h"
#include "Okrag.h"
#include "Przedmiot.h"

Dzgniecie_mieczem::Dzgniecie_mieczem ()
{
	nazwa = "dzgniecie mieczem";
	koszt = 1;

	okrag = new Okrag ();
}

Dzgniecie_mieczem::~Dzgniecie_mieczem ()
{
	delete okrag;
}

void Dzgniecie_mieczem::ustal_oznaczenie_wybor ()
{
	mapa->wyznacz_okrag ( okrag, y_obiekt, x_obiekt, 1 );

	for ( int i = 0; i < okrag->dlugosc; i++ )
	{
		if ( okrag->zbior_punktow[i].wsp_b )
		{
			mapa->zwroc_pole ( okrag->zbior_punktow[i].wsp_y, okrag->zbior_punktow[i].wsp_x )->oznaczenie_wybor = true;
		}
	}
}

void Dzgniecie_mieczem::ustal_oznaczenie_efekt ()
{
	// nic
}

void Dzgniecie_mieczem::wykonaj_umiejetnosc ()
{
	if ( mapa->zwroc_pole ( y_cel, x_cel )->obiekt != nullptr )
	{
		mapa->zwroc_pole ( y_cel, x_cel )->obiekt->przyjmij_obrazenia ( obiekt->bron_biala->obrazenia );
	}
}

void Dzgniecie_mieczem::ustal_animacje ()
{
	Obraz* obraz = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );

	obraz->obraz[y_cel][x_cel].przezroczysty = false;
	obraz->obraz[y_cel][x_cel].znak = L'X';

	obrazy_animacji.push_back ( obraz );
}